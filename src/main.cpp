#include <iostream>
#include <functionality.h>
#include <vector>
#include <string_extend.h>
using namespace std;

// currently extending "main" functionality
#define MAIN_FUNCTIONALITY "main"

int main(){
    // an instance of functionality
    Functionality mainFunc(MAIN_FUNCTIONALITY);

    // print usage info
    cout << "Usage: " << endl;
    cout << "Load Plugin: load *name* "<< endl;
    cout << "Use Plugin: use *name* " << endl;
    cout << "Unload Plugin: unload *name* " << endl;
    cout << "Show active Plugins: show " << endl;
    cout << "Exit: exit " << endl;

    cout << endl << endl;

    // buffer for commands
    string buffer;

    while(true){
        // read command from stdin
        cout << "input > ";
        getline(cin, buffer);

        // split commands and arguments
        vector<string> cmdarg = explode(buffer, ' ');

        // if no command just iterate
        if(cmdarg.size() < 1)
           continue;

        // if we have both command and argument
        else if(cmdarg.size() == 2){

            // handle "load" command
            if(cmdarg[0] == "load")
                mainFunc.Add(cmdarg[1]);

            // handle "use" command
            else if(cmdarg[0] == "use"){
                // get plugin
                const Plugin* toDo = mainFunc[cmdarg[1]];
                // if not null run plugin logic
                if(toDo != 0) 
                    toDo->run();
                // clear buffer
                cin.ignore();
            }

            // handle unload command
            else if(cmdarg[0] == "unload")
                mainFunc.Remove(cmdarg[1]);
        }

        // commands w/o argumenent
        else if(cmdarg.size() == 1){
            // handle show command
            if(cmdarg[0] == "show")
                mainFunc.Show();

            // handle exit command
            else if(cmdarg[0] == "exit")
                break;
        }
        // otherwise  - something is wrong
        else
            cout << "Wrong command!" << endl;

        cout << endl << endl;
    }

    return 0;
}
