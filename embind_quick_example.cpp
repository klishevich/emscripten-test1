// quick_example.cpp

// Run
// emcc --bind -o embind_quick_example.js embind_quick_example.cpp
// open http://localhost:8080/embind_quick_example.html
// look into console

#include <emscripten/bind.h>

using namespace emscripten;

float lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("lerp", &lerp);
}
