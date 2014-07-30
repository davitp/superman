#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H
#include <map>
#include <iostream>
#include <string>
#include <dlfcn.h>
#include "plugin.h"
#include "colormod.h"
#define PLUGIN_PREFIX "./plugins/"
using namespace std;


class Functionality {
private:
    // name of functionality
    string functionality;

    // prepare storage for plugins
    map<string, Plugin*> plugins;

    // active plugins in current functionality
    size_t cnt;

    // color mods
    Color::Modifier red;
    Color::Modifier def;
    Color::Modifier blue;
    Color::Modifier green;
public:
    // constructor
    Functionality(string name)
        : functionality(name), cnt(0),
          red(Color::FG_RED), def(Color::FG_DEFAULT),
          blue(Color::FG_BLUE), green(Color::FG_GREEN){}

    ~Functionality() {
        // remove from memory all plugin structures
        map<string, Plugin*>::iterator it;
        for(it = plugins.begin(); it != plugins.end(); ++it){
            delete it->second;
        }
    }

    // add plugin to current functionality
    bool Add(string name){

        // if already loaded - OK
        if(plugins.find(name) != plugins.end()){
            ok_load();
            return true;
        }

        // prepare plugin
        Plugin* plugin = new Plugin();

        // open lib.
        string path = PLUGIN_PREFIX + functionality + "/" + name;
        plugin->handle = dlopen(path.c_str(), RTLD_LAZY);
        // error handle
        if (!plugin->handle) {
            err_load();
            delete plugin;
            return false;
         }

        // find function and map into our plugin structure
        plugin->init = (void (*)()) dlsym(plugin->handle, "init");
        plugin->destroy = (void (*)()) dlsym(plugin->handle, "destroy");
        plugin->can_do = (const char* (*)()) dlsym(plugin->handle, "can_do");
        plugin->run = (void (*)()) dlsym(plugin->handle, "run");

        // error is there
        if(dlerror() != 0){
            dlclose(plugin->handle);
            err_load();
            delete plugin;
            return false;
        }

        // add plugin to storage
        plugins[name] = plugin;
        // all is ok
        ok_load();
        cnt++;
        plugin->init();
        return true;
    }

    // get plugin to work
    const Plugin* operator[](string name){
        if(plugins.find(name) == plugins.end()){
            err_use();
            return 0;
        }
        return plugins[name];
    }

    // unload
    void Remove(string name){
        // if no plugin - OK
        if(plugins.find(name) == plugins.end()){
            ok_unload();
            return;
        }

        // get plugin
        Plugin* plug = plugins[name];
        // erase from storage
        plugins.erase(name);
        // call plugin destructor
        plug->destroy();
        // unload from memory
        dlclose(plug->handle);
        // delete plugin from memory
        delete plug;

        if(dlerror() == 0)
            ok_unload();
        else
            err_unload();

        // we have less plugins
        cnt--;
    }

    // show active modules
    void Show(){
        cout << "Active Plugins: " << cnt << endl;

        map<string, Plugin*>::iterator it;

        // find and print plugins
        for(it = plugins.begin(); it != plugins.end(); ++it){
            Plugin* plugin = it->second;
            // print list
            cout << blue << it->first << def
                 << " (" << plugin->can_do() << ")"
                 <<  endl;
        }

    }

private:
    // error message
    void err_load(){
        cerr << red << "ERROR: "
             << "Can not load plugin" << def << endl;
    }

    // success message
    void ok_load(){
        cerr << green << "OK: "
             << "Plugin loaded" << def << endl;
    }


    // error message unload
    void err_unload(){
        cerr << red << "ERROR: "
             << "Can not unload plugin" << def << endl;
    }

    // success message unload
    void ok_unload(){
        cerr << green << "OK: "
             << "Plugin unloaded" << def << endl;
    }

    // error message unload
    void err_use(){
        cerr << red << "ERROR: "
             << "No such loaded plugin" << def << endl;
    }
};

#endif // FUNCTIONALITY_H
