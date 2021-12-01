import * as WasmModule from "./module_test1";

function test() {
  new WasmModule().then((wasmContext) => {
    console.log("wasm module loaded");
    console.log("lerp result: " + wasmContext.lerp(1, 2, 0.5));
  });
}

test();
