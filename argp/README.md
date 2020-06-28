# Usage

From `toolbox` repository include `argp/argp.hpp`
```cpp
#include "argp/argp.hpp"
```

Create a `argp::Options` object
```cpp
argp::Options options("Program name", "One line program description");
```

Add custom options using `options.addOption()` function
```cpp
int intVar = 5; // 5 is default value
float floatVar = 0.0f; // 0.0f is default value
bool boolVar = false; // false is default value
std::string stringVar = "Hello, world!"; // "Hello, world!" is default value

options.addOptions("short1", "long1", "Description", &intVar);
options.addOptions("short2", "long2", "Description", &floatVar);
options.addOptions("short3", "long3", "Description", &boolVar);
options.addOptions("short4", "long4", "Description", &stringVar);
```
Variables should be initialized. If parser fails finding argument for variable, value, specified during initialization will be used.

Note: only `int`, `float`, `bool`, and `std::string` are supported.

Pass `argc` and `argv` from `int main(int argc, char *argv[]) {`
```cpp
options.parse(argc, argv);
```

Now all arguments will be stored in corresponding variables. Boolean variables will be set to `false` if their flag was not set.

# TODO list

* Add help print function
