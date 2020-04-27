# Install
```
$ git submodule add https://github.com/AlexeyFilich/toolbox third-party/toolbox
```
# Path
For Visual Studio Code with C/C++ extension installed add `"${workspaceFolder}/third-party/toolbox/*"` to `C_Cpp.default.includePath`.
```json
"C_Cpp.default.includePath": [
    "${workspaceFolder}/third-party/ColorType/include/*",
    "${workspaceFolder}/third-party/toolbox/*"
]
```

# Libraries

* [argp - C++ option parser library](argp/README.md)
