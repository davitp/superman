#ifndef PLUGIN_H
#define PLUGIN_H

class Plugin {
public:
    // Initialize plugin
    void (*init) (void);

    // De-initialize plugin
    void (*destroy) (void);

    // Run plugin
    void (*run) (void);

    // Name of plugin's can_do
    const char* (*can_do) (void);

    // handle of plugin
    void* handle;
};
#endif // PLUGIN_H
