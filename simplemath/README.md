# Usage

From `toolbox` repository include `simplemath/simplemath.hpp`
```cpp
#include "simplemath/simplemath.hpp"
```

Keep `value` in range from `min` to `max`:
```c++
simplemath::constrain(15, 10, 20); // Output: 15
simplemath::constrain(5, 10, 20); // Output: 10
simplemath::constrain(25, 10, 20); // Output: 20
```

Keep `value` in periodic range from `min` to `max`:
```c++
simplemath::wraprange(90, 0, 360); // Output: 90
simplemath::wraprange(-90, 0, 360); // Output: 270
simplemath::wraprange(450, 0, 360); // Output: 90
```

Convert `value` that fits range from `from_start` to `from_end` to value that will fit range from `to_start` to `to_end`:
```c++
simplemath::convert(5, 0, 10, 50, 100); // Output: 75
```
