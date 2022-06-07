
#include <string>
#include <utility>
#include <iostream>
#include <emscripten/bind.h>

using namespace emscripten;

float lerp(float a, float b, float t) {
    return (1 - t) * a + t * b;
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("lerp", &lerp);
}

class MyClass {
public:
    MyClass(int x, std::string y)
            : x(x), y(std::move(y)) {}

    void incrementX() {
        ++x;
    }

    int getX() const { return x; }

    void setX(int x_) { x = x_; }

    std::string getString() {
        return y;
    }

    void greet(const std::string &name) {
        std::cout << "Hei, " << name << "!" <<  std::endl;
    }

private:
    int x;
    std::string y;
};

// Binding code
EMSCRIPTEN_BINDINGS(my_class_example) {
    class_<MyClass>("MyClass")
            .constructor<int, std::string>()
            .function("incrementX", &MyClass::incrementX)
            .property("x", &MyClass::getX, &MyClass::setX)
            .function("getString", &MyClass::getString)
            .function("greet", &MyClass::greet);
}