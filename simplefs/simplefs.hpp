#pragma once
#define SIMPLEFS_H
#ifdef SIMPLEFS_H

/* C++ */
#include <dirent.h>
#include <iostream>
#include <string>
#include <vector>
/* End */

namespace simplefs {

inline std::vector<std::string> getFilesAndDirectories(std::string path) {
    struct dirent *entry;
    DIR *dir = opendir(path.data());
    std::vector<std::string> temp;
    while ((entry = readdir(dir)) != NULL) {
        temp.push_back(entry->d_name);
    }
    closedir(dir);
    return temp;
}

} // namespace simplefs


#endif
