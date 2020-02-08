// Non-member-functions on the JavaScript prototype
// emcc --bind -o embind_8_virtual_methods.js embind_8_virtual_methods.cpp
// open http://localhost:8080/embind_8_virtual_methods.html

#include <emscripten/bind.h>

struct BaseStruct {
    virtual void invoke(const std::string& str) {
        // return 333;
    }
};

struct BaseStructWrapper : public emscripten::wrapper<BaseStruct> {
    EMSCRIPTEN_WRAPPER(BaseStructWrapper);
    void invoke(const std::string& str) {
        return call<void>("invoke", str);
    }
};

EMSCRIPTEN_BINDINGS(interface) {
    emscripten::class_<BaseStruct>("BaseStruct")
        .allow_subclass<BaseStructWrapper>("BaseStructWrapper")
        .function("invoke", emscripten::optional_override([](BaseStruct& self, const std::string& str) {
            return self.BaseStruct::invoke(str);
        }))
        ;
}
