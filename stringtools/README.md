# Usage

From `toolbox` repository include `stringtools/stringtools.hpp`
```cpp
#include "stringtools/stringtools.hpp"
```

Returns `num` copies of `str`.
```c++
std::string multiply(std::string str, int num);
```

Returns position of first character of `instance`'s `substr` in `str`.
```c++
int findInstance(std::string str, std::string substr, int instance);
```

Replaces `instance`'s `what` in `str` with `with`.
```c++
std::string replaceInstance(std::string str, std::string what, std::string with, int instance);
```

Replaces all `what` in `str` with `with`.
```c++
std::string replaceAllInstances(std::string str, std::string what, std::string with);
```
