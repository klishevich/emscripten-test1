# Simple Example how to load wasm module build with Emscripten

## Build Emscripten 

* install Emscripten
* `cd src`
* `emcc --bind -s MODULARIZE=1 -s ENVIRONMENT=web -o module_test1.js test1.cpp`

## Running the Example

* `npm install`
* `npm start` 
* Open https://localhost:8080
* Open browser console
* You will find this message in the browser console "lerp result: 1.5" where the result is calculated with WASM.
