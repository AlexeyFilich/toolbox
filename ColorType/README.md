# Usage

From `toolbox` repository include `ColorType/ColorType.hpp`
```cpp
#include "ColorType/ColorType.hpp"
```

Optional: set default escape string (default `\033`)
```cpp
colortype::setEscapeString(std::string escape);
```

Optional: set default color mode (default `BIT_8`)
```cpp
colortype::setColorMode(colortype::Mode mode);
```

Set foreground color:
```cpp
// With default color mode
colortype::setForegroundColor(colortype::Colors::WHITE);
// Or overwriting it
colortype::setForegroundColor(0xFFFFFF, colortype::Mode::BIT_24);
// Resetting
colortype::resetForegroundColor();
// is the same thing as
colortype::setForegroundColor(colortype::Colors::DEFAULT_COLOR);
```

There are equivalent functions for setting background color.

Enable or disable underline and reverse video
```cpp
void enableUnderline();
void disableUnderline();
void enableReverseVideo();
void disableReverseVideo();
```

Finally, formatted string
```cpp
std::string getFormattedString(std::string string, bool clearAttributes); // If clearAttributes is set, colortype::ESC::escape + "[0m" will be added to the end of the string.
```

Or ignoring setting up colors
```cpp
std::string getFormattedString(std::string str, int fgclr, int bgclr, bool underline, bool reverseVideo, bool clearAttributes);
```

And setting up color mode
```cpp
std::string getFormattedString(std::string str, int fgclr, int bgclr, colortype::Mode mode, bool underline, bool reverseVideo, bool clearAttributes);
```
