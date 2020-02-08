// emcc --bind -o embind_12_constants.js embind_12_constants.cpp
// open http://localhost:8080/embind_12_constants.html

#include <emscripten/bind.h>

#define SOME_CONSTANT 10

EMSCRIPTEN_BINDINGS(my_constant_example) {
    emscripten::constant("SOME_CONSTANT", SOME_CONSTANT);
}
