# Quick start

Argp is a simple C++ option parser library.

There are two ways to give options:
    -short
    -short argument
    --long
    --long argument

# Basics

From `toolbox` repository:
```cpp
#include <argp/argp.hpp>
```

Create a `argp::Options` instance.

```cpp
argp::Options options("Program name", "Program description (one line)");
```

Then use `addOptions`.

```cpp
int intVar = 0;
float floatVar = 0.0f;
bool boolVar = false;
std::string stringVar = "";

options.addOptions("short1", "long1", "Description", &intVar);
options.addOptions("short2", "long2", "Description", &floatVar);
options.addOptions("short3", "long3", "Description", &boolVar);
options.addOptions("short4", "long4", "Description", &stringVar);
```
Variables should be initialized. If parser fails finding argument for variable, value, specified during initialization will be used.

Options are declared with a short and a long option. A description must be provided. Last argument is pointer to variable, where argument will be written

Please note: only `int`, `float`, `bool`, and `std::string` are supported.

To parse the command line do:

```cpp
options.parse(argc, argv);
```

Now all arguments will be stored in corresponding variables. Boolean variables will be set to `false` if their flag was not set.

# Linking

This is a header only library.

# TODO list

* Add help print function