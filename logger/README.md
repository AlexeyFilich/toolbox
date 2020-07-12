# Usage

From `toolbox` repository include `logger/logger.hpp`
```cpp
#include "logger/logger.hpp"
```

Print line to console in format [HH:MM:SS] str_a:
```cpp
logger::log("Hello, world!"); // Results in [10:47:02] Hello, world!
```

Print line to console in format [HH:MM:SS][str_a] str_b:
```cpp
logger::log("From main", "Hello, world!"); // Results in [10:47:02][From main] Hello, world!
```
