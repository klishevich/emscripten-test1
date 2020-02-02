// emcc -s WASM=1 -s ONLY_MY_CODE=1 -s EXPORTED_FUNCTIONS="['_add']" -o node_example.js *.c node_example.c

int add(int a, int b) {
  return a + b;
}
