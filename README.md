# WASM demo

A simple WASM demo.

### Setup

```
# Get the emsdk repo
git clone https://github.com/emscripten-core/emsdk.git

# Enter that directory
cd emsdk

# Download and install the latest SDK tools.
./emsdk install latest

# Make the "latest" SDK "active" for the current user. (writes .emscripten file)
./emsdk activate latest --permanent

```

Add `<path-to-emscripten>/emsdk/upstream/emscripten` to PATH.

Configure and build using CMake as normal.
