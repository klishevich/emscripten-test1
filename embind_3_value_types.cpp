// emcc --bind -o embind_3_value_types.js embind_3_value_types.cpp
// open http://localhost:8080/embind_quick_example.html

#include <emscripten/bind.h>

struct Point2f {
    float x;
    float y;
};

struct PersonRecord {
    std::string name;
    int age;
};

PersonRecord findPersonAtLocation(Point2f point) {
    int age = (int)point.x;
    PersonRecord person = { "Michael", age };
    return person;
};

EMSCRIPTEN_BINDINGS(my_value_example) {
    emscripten::value_array<Point2f>("Point2f")
        .element(&Point2f::x)
        .element(&Point2f::y)
        ;

    emscripten::value_object<PersonRecord>("PersonRecord")
        .field("name", &PersonRecord::name)
        .field("age", &PersonRecord::age)
        ;

    emscripten::function("findPersonAtLocation", &findPersonAtLocation);
}