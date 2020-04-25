#pragma once
#define ARGP_H
#ifdef ARGP_H

#include <string>
#include <vector>

namespace argp {

void separateArguments(std::string arg, std::string * short_arg, std::string * long_arg) {
    *short_arg = "";
    *long_arg = "";
    bool sw = true;
    for (int i = 0; i < arg.size(); i++) {
        if (arg[i] == ',') {
            sw = false;
            continue;
        }
        if (sw)
            *short_arg += arg[i];
        else
            *long_arg += arg[i];
        std::cout << *short_arg << ":" << *long_arg << "\n";
    }
}

enum Types : unsigned int {
    INT = 0,
    FLOAT = 1,
    BOOL = 2,
    STRING = 3
};

struct Opt {
    int         * int_;
    float       * float_;
    bool        * bool_;
    std::string * string_;
    argp::Types type;
    Opt(int * i, float * f, bool * b, std::string * s, argp::Types type) : int_(i), float_(f), bool_(b), string_(s), type(type) {}
};

class Options {
    public:
        Options(std::string prog_name, std::string prog_desc);
        ~Options();
        void addOption(std::string arg, std::string desc, int * ptr);
        void addOption(std::string arg, std::string desc, float * ptr);
        void addOption(std::string arg, std::string desc, bool * ptr);
        void addOption(std::string arg, std::string desc, std::string * ptr);
        void parse(int argc, char *argv[]);

    private:
        std::string prog_name;
        std::string prog_desc;
        std::vector<Opt> value_storage;
        std::vector<std::string> short_arg;
        std::vector<std::string> long_arg;
        std::vector<std::string> descriptions;
};

Options::Options(std::string prog_name, std::string prog_desc) {
    this->prog_name = prog_name;
    this->prog_desc = prog_desc;
}

Options::~Options() {
}

void Options::addOption(std::string arg, std::string desc, int * ptr) {
    std::string short_arg = "", long_arg = "";
    argp::separateArguments(arg, &short_arg, &long_arg);
    this->short_arg.push_back(short_arg);
    this->long_arg.push_back(long_arg);
    this->descriptions.push_back(desc);
    this->value_storage.emplace_back(ptr, nullptr, nullptr, nullptr, argp::Types::INT);
}

void Options::addOption(std::string arg, std::string desc, float * ptr) {
    std::string short_arg = "", long_arg = "";
    argp::separateArguments(arg, &short_arg, &long_arg);
    this->short_arg.push_back(short_arg);
    this->long_arg.push_back(long_arg);
    this->descriptions.push_back(desc);
    this->value_storage.emplace_back(nullptr, ptr, nullptr, nullptr, argp::Types::FLOAT);
}

void Options::addOption(std::string arg, std::string desc, bool * ptr) {
    std::string short_arg = "", long_arg = "";
    argp::separateArguments(arg, &short_arg, &long_arg);
    this->short_arg.push_back(short_arg);
    this->long_arg.push_back(long_arg);
    this->descriptions.push_back(desc);
    this->value_storage.emplace_back(nullptr, nullptr, ptr, nullptr, argp::Types::BOOL);
}

void Options::addOption(std::string arg, std::string desc, std::string * ptr) {
    std::string short_arg = "", long_arg = "";
    argp::separateArguments(arg, &short_arg, &long_arg);
    this->short_arg.push_back(short_arg);
    this->long_arg.push_back(long_arg);
    this->descriptions.push_back(desc);
    this->value_storage.emplace_back(nullptr, nullptr, nullptr, ptr, argp::Types::STRING);
}

void Options::parse(int argc, char *argv[]) {
    
}

} // namespace argp

#endif