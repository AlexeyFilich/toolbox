# Usage

From `toolbox` repository include `simplefs/simplefs.hpp`
```cpp
#include "simplefs/simplefs.hpp"
```

List all files and directories in `path`:
```cpp
/*
 folder
 ├── folder
 │   └── fileinfolder.ext
 ├── image.jpg
 ├── main.exe 
 └── textfile.txt
*/

std::vector<std::string> out = simplefs::getFilesAndDirectories("folder");

for (auto & item: out)
    std::cout << item << "\n";

/*
 Will result in:

 .
 ..
 folder
 image.jpg
 main.exe 
 textfile.txt
*/
```
