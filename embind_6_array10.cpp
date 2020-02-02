// Non-member-functions on the JavaScript prototype
// emcc --bind -o embind_6_array10.js embind_6_array10.cpp
// open http://localhost:8080/embind_6_array10.html

#include <emscripten/bind.h>

struct Array10 {
    int& get(size_t index) {
        return data[index];
    }
    int data[10];
};

//Factory function.
Array10 makeArray10() {
    Array10 ar;
    ar.data[0] = 0;
    ar.data[1] = 1;
    ar.data[2] = 20;
    return ar;
}

emscripten::val Array10_get(Array10& arr, size_t index) {
    if (index < 10) {
        return emscripten::val(arr.get(index));
    } else {
        return emscripten::val::undefined();
    }
}

EMSCRIPTEN_BINDINGS(non_member_functions) {
    emscripten::class_<Array10>("Array10")
        .constructor(&makeArray10, emscripten::allow_raw_pointers())
        .function("get", &Array10_get)
        ;
}