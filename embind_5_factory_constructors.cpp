// emcc --bind -o embind_5_factory_constructors.js embind_5_factory_constructors.cpp
// open http://localhost:8080/embind_5_factory_constructors.html

#include <emscripten/bind.h>

class MyClass {
public:
    int someFunction() {
        return x;
    };
    int x;
};

//Factory function.
MyClass* makeMyClass() {
    MyClass* a = new MyClass();
    a -> x = 17;
    return a;
}

// Binding code
EMSCRIPTEN_BINDINGS(my_class_example) {
  emscripten::class_<MyClass>("MyClass")
    .constructor(&makeMyClass, emscripten::allow_raw_pointers())
    .function("someFunction", &MyClass::someFunction)
    ;
}
