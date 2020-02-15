// emcc --bind -o embind_15_vector.js embind_15_vector.cpp
// open http://localhost:8080/embind_15_vector.html

#include <emscripten/bind.h>
#include <string>
#include <vector>

using namespace emscripten;

std::vector<int> returnVectorData () {
  std::vector<int> v(10, 1); // 10 ints with value 1
  return v;
}

std::map<int, std::string> returnMapData () {
  std::map<int, std::string> m;
  m.insert(std::pair<int, std::string>(10, "This is a string."));
  return m;
}

EMSCRIPTEN_BINDINGS(module) {
  function("returnVectorData", &returnVectorData);
  function("returnMapData", &returnMapData);

  // register bindings for std::vector<int> and std::map<int, std::string>.
  register_vector<int>("vector<int>");
  register_map<int, std::string>("map<int, string>");
}
