// emcc --bind -o embind_4_allow_raw_pointers.js embind_4_allow_raw_pointers.cpp
// open http://localhost:8080/embind_4_allow_raw_pointers.html

#include <emscripten/bind.h>

class C {
public:
    C() {
        x = 10;
    }

    int x;
};

C* passThrough(C* ptr) { return ptr; }

EMSCRIPTEN_BINDINGS(raw_pointers) {
    emscripten::class_<C>("C")
        .constructor()
        .property("x", &C::x);
    emscripten::function("passThrough", &passThrough, emscripten::allow_raw_pointers());
}
