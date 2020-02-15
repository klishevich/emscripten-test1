// emcc --bind -o embind_13_memory_views.js embind_13_memory_views.cpp
// open http://localhost:8080/embind_13_memory_views.html

#include <emscripten/bind.h>

using namespace emscripten;

size_t bufferLength = 786434;
unsigned char *byteBuffer = new unsigned char [bufferLength];

val getBytes() {
    return val(typed_memory_view(bufferLength, byteBuffer));
}

EMSCRIPTEN_BINDINGS(memory_view_example) {
    function("getBytes", &getBytes);
}
