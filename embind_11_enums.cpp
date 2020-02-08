// emcc --bind -o embind_11_enums.js embind_11_enums.cpp
// open http://localhost:8080/embind_11_enums.html

#include <emscripten/bind.h>

enum OldStyle {
    OLD_STYLE_ONE,
    OLD_STYLE_TWO
};

enum class NewStyle {
    ONE,
    TWO
};

EMSCRIPTEN_BINDINGS(my_enum_example) {
    emscripten::enum_<OldStyle>("OldStyle")
        .value("ONE", OLD_STYLE_ONE)
        .value("TWO", OLD_STYLE_TWO)
        ;
    emscripten::enum_<NewStyle>("NewStyle")
        .value("ONE", NewStyle::ONE)
        .value("TWO", NewStyle::TWO)
        ;
}
