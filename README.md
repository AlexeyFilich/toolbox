[![CodeFactor](https://www.codefactor.io/repository/github/alexeyfilich/toolbox/badge)](https://www.codefactor.io/repository/github/alexeyfilich/toolbox)

# Install
```
$ git submodule add https://github.com/AlexeyFilich/toolbox third-party/toolbox
```

# Path
For Visual Studio Code with C/C++ extension installed add `"${workspaceFolder}/third-party/toolbox/*"` to `C_Cpp.default.includePath`.
```json
"C_Cpp.default.includePath": [
    "${workspaceFolder}/third-party/toolbox/*"
]
```

# Libraries

* [AGRP](argp/README.md)
* [COLORTYPE](ColorType/README.md)
* [LOGGER](logger/README.md)
* [STRINGTOOLS](stringtools/README.md)
