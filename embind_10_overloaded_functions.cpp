// emcc --bind -o embind_10_overloaded_functions.js embind_10_overloaded_functions.cpp
// open http://localhost:8080/embind_10_overloaded_functions.html

#include <emscripten/bind.h>

struct HasOverloadedMethods {
    int foo() {
        return 1;
    }

    int foo(int i) {
        return i;
    }

    int foo(float f) {
        return (int)f + 1;
    }
};

EMSCRIPTEN_BINDINGS(overloads) {
    emscripten::class_<HasOverloadedMethods>("HasOverloadedMethods")
        .constructor()
        .function("foo", emscripten::select_overload<int()>(&HasOverloadedMethods::foo))
        // .function("foo_int", emscripten::select_overload<int(int)>(&HasOverloadedMethods::foo))
        // .function("foo_float", emscripten::select_overload<int(float)>(&HasOverloadedMethods::foo))
        .function("foo", emscripten::select_overload<int(int)>(&HasOverloadedMethods::foo))
        .function("foo", emscripten::select_overload<int(float)>(&HasOverloadedMethods::foo))
        ;
}
