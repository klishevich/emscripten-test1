// test1.cpp

// Run
// emcc --bind -o test1.js test1.cpp
// open http://localhost:8080/test1/test1.html
// look into console

// BUILD AS A MODULE
// emcc --bind -s MODULARIZE=1 -o module_test1.js test1.cpp

#include <emscripten/bind.h>

using namespace emscripten;

float lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("lerp", &lerp);
}
