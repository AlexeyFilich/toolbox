#pragma once
#define LOGGER_H
#ifdef LOGGER_H

/* C++ */
#include <ctime>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
/* End */

namespace logger {
    inline std::string get_time() {
        time_t _time = std::time(nullptr);
        tm time = *std::localtime(std::addressof(_time));
        std::string output = "";
        (time.tm_hour <= 9) ? (output += "0" + std::to_string(time.tm_hour) + ":") : (output += std::to_string(time.tm_hour) + ":");
        (time.tm_min <= 9) ? (output += "0" + std::to_string(time.tm_min) + ":") : (output += std::to_string(time.tm_min) + ":");
        (time.tm_sec <= 9) ? (output += "0" + std::to_string(time.tm_sec)) : (output += std::to_string(time.tm_sec));
        return output;
    }

    inline void log(std::string str_a) {
        std::cout << "[" << logger::get_time() << "] " << str_a << "\n";
    }

    inline void log(std::string str_a, std::string str_b) {
        std::cout << "[" << logger::get_time() << "][" << str_a << "] " << str_b << "\n";
    }
} // namespace logger

#endif
