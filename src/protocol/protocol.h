// an interface of plugin
// that have to be implemented
// to get this work

#ifndef PROTOCOL_H
#define PROTOCOL_H
extern "C" {
    // constructor
    void init(void);
    // destructor
    void destroy(void);
    // logic of plugin
    void run(void);
    // description of plugin
    const char* can_do(void);
}
#endif // PROTOCOL_H
