#pragma once
#define STRINGTOOLS_H
#ifdef STRINGTOOLS_H

/* C++ */
#include <iostream>
#include <regex>
#include <string>
#include <vector>
/* END */

namespace stringtools {

std::string multiply(std::string str, int num) {
    std::string temp = "";
    for (int i = 0; i < num; i++)
        temp += str;
    return temp;
}

int findInstance(std::string str, std::string substr, int instance) {
    int pos = str.find(substr);
    int i;
    for (i = 0; i < instance && pos != std::string::npos; i++)
        pos = str.find(substr, pos + 1);
    if (i == instance)
        return pos;
    else
        return -1;
}

std::string replaceInstance(std::string str, std::string what, std::string with, int instance) {
    int pos = stringtools::findInstance(str, what, instance);
    if (pos == -1)
        return str;
    else
        return str.substr(0, pos) + with + str.substr(pos + what.size(), str.size());
}

std::string replaceAllInstances(std::string str, std::string what, std::string with) {
    while(stringtools::findInstance(str, what, 0) != -1)
        str = stringtools::replaceInstance(str, what, with, 0);
    return str;
}

} // namespace stringtools

#endif
