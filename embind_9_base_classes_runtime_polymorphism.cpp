// emcc --bind -o embind_9_base_classes_runtime_polymorphism.js embind_9_base_classes_runtime_polymorphism.cpp
// open http://localhost:8080/embind_9_base_classes_runtime_polymorphism.html

#include <emscripten/bind.h>

class BaseClass {
    // the virtual makes BaseClass and DerivedClass polymorphic
    // virtual ~Base() {}
    public:
    // If using virtual keyword result is 4, othewise 1
    int virtual test() {
        return 1;
    }
};

class DerivedClass : public BaseClass {
    public:
    int test() {
        return 4;
    }
};

BaseClass* getDerivedInstance() {
    return new DerivedClass;
}

EMSCRIPTEN_BINDINGS(automatic_downcasting) {
    emscripten::class_<BaseClass>("BaseClass")
        .function("test", &BaseClass::test);
    emscripten::class_<DerivedClass, emscripten::base<BaseClass>>("DerivedClass");
    emscripten::function("getDerivedInstance", &getDerivedInstance, emscripten::allow_raw_pointers());
}
