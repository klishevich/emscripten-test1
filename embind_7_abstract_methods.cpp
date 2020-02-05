// Non-member-functions on the JavaScript prototype
// emcc --bind -o embind_7_abstract_methods.js embind_7_abstract_methods.cpp
// open http://localhost:8080/embind_7_abstract_methods.html

#include <emscripten/bind.h>

struct Interface {
    virtual void invoke(const std::string& str) = 0;
};

struct InterfaceWrapper : public emscripten::wrapper<Interface> {
    EMSCRIPTEN_WRAPPER(InterfaceWrapper);
    void invoke(const std::string& str) {
        return call<void>("invoke", str);
    }
};

EMSCRIPTEN_BINDINGS(interface) {
    emscripten::class_<Interface>("Interface")
        .function("invoke", &Interface::invoke, emscripten::pure_virtual())
        .allow_subclass<InterfaceWrapper>("InterfaceWrapper")
        ;
}
