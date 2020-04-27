#pragma once
#define ARGP_H
#ifdef ARGP_H

#include <iostream>
#include <string>
#include <vector>

namespace argp {

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
        void addOption(std::string short_arg, std::string long_arg, std::string desc, int * ptr);
        void addOption(std::string short_arg, std::string long_arg, std::string desc, float * ptr);
        void addOption(std::string short_arg, std::string long_arg, std::string desc, bool * ptr);
        void addOption(std::string short_arg, std::string long_arg, std::string desc, std::string * ptr);
        void parse(int argc, char *argv[]);

    private:
        std::string prog_name;
        std::string prog_desc;
        std::vector<Opt *> value_storage;
        std::vector<std::string> short_arg;
        std::vector<std::string> long_arg;
        std::vector<std::string> descriptions;
        int total = 0;
};

Options::Options(std::string prog_name, std::string prog_desc) {
    this->prog_name = prog_name;
    this->prog_desc = prog_desc;
}

Options::~Options() {
}

void Options::addOption(std::string short_arg, std::string long_arg, std::string desc, int * ptr) {
    this->short_arg.push_back("-" + short_arg);
    this->long_arg.push_back("--" + long_arg);
    this->descriptions.push_back(desc);
    this->value_storage.emplace_back(new argp::Opt(ptr, nullptr, nullptr, nullptr, argp::Types::INT));
    this->total++;
}

void Options::addOption(std::string short_arg, std::string long_arg, std::string desc, float * ptr) {
    this->short_arg.push_back("-" + short_arg);
    this->long_arg.push_back("--" + long_arg);
    this->descriptions.push_back(desc);
    this->value_storage.emplace_back(new argp::Opt(nullptr, ptr, nullptr, nullptr, argp::Types::FLOAT));
    this->total++;
}

void Options::addOption(std::string short_arg, std::string long_arg, std::string desc, bool * ptr) {
    this->short_arg.push_back("-" + short_arg);
    this->long_arg.push_back("--" + long_arg);
    this->descriptions.push_back(desc);
    this->value_storage.emplace_back(new argp::Opt(nullptr, nullptr, ptr, nullptr, argp::Types::BOOL));
    *this->value_storage[this->total]->bool_ = false;
    this->total++;
}

void Options::addOption(std::string short_arg, std::string long_arg, std::string desc, std::string * ptr) {
    this->short_arg.push_back("-" + short_arg);
    this->long_arg.push_back("--" + long_arg);
    this->descriptions.push_back(desc);
    this->value_storage.emplace_back(new argp::Opt(nullptr, nullptr, nullptr, ptr, argp::Types::STRING));
    this->total++;
}

void Options::parse(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        for (int i = 0; i < this->value_storage.size(); i++) {
            if (this->value_storage[i] == nullptr)
                continue;
            if ((this->short_arg[i] == std::string(argv[arg])) || (this->long_arg[i] == std::string(argv[arg]))) {
                bool avaliable = false;
                std::string var = "";
                if (arg + 1 != argc) {
                    avaliable = true;
                    var = argv[arg + 1];
                }
                switch (this->value_storage[i]->type) {
                    case argp::Types::INT:
                        if (avaliable) {
                            try {
                            	int conv = std::stoi(var);
                            	*this->value_storage[i]->int_ = conv;
                            }
                            catch (std::invalid_argument const &e) {
                            	std::cout << "[argp] Bad input" << "\n";
                            }
                            catch (std::out_of_range const &e) {
                            	std::cout << "[argp] Overflow" << "\n";
                            }
                        }
                        delete this->value_storage[i];
                        this->value_storage[i] = nullptr;
                        break;
                    case argp::Types::FLOAT:
                        if (avaliable) {
                            try {
                            	float conv = std::stof(var);
                            	*this->value_storage[i]->float_ = conv;
                            }
                            catch (std::invalid_argument const &e) {
                            	std::cout << "[argp] Bad input" << "\n";
                            }
                            catch (std::out_of_range const &e) {
                            	std::cout << "[argp] Overflow" << "\n";
                            }
                        }
                        delete this->value_storage[i];
                        this->value_storage[i] = nullptr;
                        break;
                    case argp::Types::BOOL:
                        *this->value_storage[i]->bool_ = true;
                        delete this->value_storage[i];
                        this->value_storage[i] = nullptr;
                        break;
                    case argp::Types::STRING:
                        if (avaliable) {
                            *this->value_storage[i]->string_ = var;
                        }
                        delete this->value_storage[i];
                        this->value_storage[i] = nullptr;
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

} // namespace argp

#endif