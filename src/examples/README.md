HOW TO TEST IT
==================

First of all we have to compile plugins as shared libs (.so) 

copy example file and protocol.h into same directory and do in terminal

```bash
g++ -shared -fPIC example.cpp -o plug
```

Then copy "plug" file into "plugins/main" folder and run "./superman"
