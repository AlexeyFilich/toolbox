#pragma once
#define COLORTYPER_H
#ifdef COLORTYPER_H

/* C++ */
#include <iostream>
#include <string>
/* END */

namespace colortype {

enum Mode : unsigned int {
    BIT_8 = 0,
    BIT_24 = 1
};

enum Colors : int {
    DEFAULT_COLOR = -1,
    BLACK = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    MAGENTA = 5,
    CYAN = 6,
    WHITE = 7,
    BRIGHT_BLACK = 8,
    BRIGHT_RED = 9,
    BRIGHT_GREEN = 10,
    BRIGHT_YELLOW = 11,
    BRIGHT_BLUE = 12,
    BRIGHT_MAGENTA = 13,
    BRIGHT_CYAN = 14,
    BRIGHT_WHITE = 15
};

namespace ESC {
    colortype::Mode mode = colortype::BIT_8;
    std::string escape = "\033";
    std::string foreground_color = "";
    std::string background_color = "";
    bool underline = false;
    bool reverseVideo = false;
} // namespace ESC

void setEscapeString(std::string escape) {
    colortype::ESC::escape = escape;
}

void setColorMode(colortype::Mode mode) {
    colortype::ESC::mode = mode;
}

void setForegroundColor(int clr, colortype::Mode mode) {
    if (clr == colortype::Colors::DEFAULT_COLOR) {
        colortype::ESC::foreground_color = "39";
        return;
    }
    switch (mode) {
        case colortype::Mode::BIT_8:
            colortype::ESC::foreground_color = "38;05;" + std::to_string(clr);
            break;
        case colortype::Mode::BIT_24:
            colortype::ESC::foreground_color = "38;02;" + std::to_string(((clr >> 16) & 0xFF)) + ";" + std::to_string(((clr >> 8) & 0xFF)) + ";" + std::to_string(((clr) & 0xFF));
            break;
        default:
            break;
    }
}

void setForegroundColor(int clr) {
    colortype::setForegroundColor(clr, colortype::ESC::mode);
}

void resetForegroundColor() {
    colortype::ESC::foreground_color = "39";
}

void setBackgroundColor(int clr, colortype::Mode mode) {
    if (clr == colortype::Colors::DEFAULT_COLOR) {
        colortype::ESC::background_color = "49";
        return;
    }
    switch (mode) {
        case colortype::Mode::BIT_8:
            colortype::ESC::background_color = "48;05;" + std::to_string(clr);
            break;
        case colortype::Mode::BIT_24:
            colortype::ESC::background_color = "48;02;" + std::to_string(((clr >> 16) & 0xFF)) + ";" + std::to_string(((clr >> 8) & 0xFF)) + ";" + std::to_string(((clr) & 0xFF));
            break;
        default:
            break;
    }
}

void setBackgroundColor(int clr) {
    colortype::setBackgroundColor(clr, colortype::ESC::mode);
}

void resetBackgroundColor() {
    colortype::ESC::foreground_color = "49";
}

void enableUnderline() {
    colortype::ESC::underline = true;
}

void disableUnderline() {
    colortype::ESC::underline = false;
}

void enableReverseVideo() {
    colortype::ESC::reverseVideo = true;
}

void disableReverseVideo() {
    colortype::ESC::reverseVideo = false;
}

std::string getEscapeString(std::string esc, std::string fgclr, std::string bgclr, bool underline, bool reverseVideo) {
    std::string temp = esc + "[" + fgclr + ";" + bgclr;
    if (underline)
        temp += ";04";
    else
        temp += ";24";
    if (reverseVideo)
        temp += ";07";
    else
        temp += ";27";
    return temp + "m";
}

std::string getFormattedString(std::string str, bool clearAttributes = false) {
    if (clearAttributes)
        return colortype::getEscapeString(colortype::ESC::escape,
                                          colortype::ESC::foreground_color,
                                          colortype::ESC::background_color,
                                          colortype::ESC::underline,
                                          colortype::ESC::reverseVideo)
                                          + str + colortype::ESC::escape + "[0m";
    return colortype::getEscapeString(colortype::ESC::escape,
                                      colortype::ESC::foreground_color,
                                      colortype::ESC::background_color,
                                      colortype::ESC::underline,
                                      colortype::ESC::reverseVideo)
                                      + str;
}

std::string getFormattedString(std::string str, int fgclr, int bgclr, colortype::Mode mode, bool underline = false, bool reverseVideo = false, bool clearAttributes = false) {
    std::string bgclrs = "";
    switch (mode) {
        case colortype::Mode::BIT_8:
            bgclrs = "48;05;" + std::to_string(bgclr);
            break;
        case colortype::Mode::BIT_24:
            bgclrs = "48;02;" + std::to_string(((bgclr >> 16) & 0xFF)) + ";" + std::to_string(((bgclr >> 8) & 0xFF)) + ";" + std::to_string(((bgclr) & 0xFF));
            break;
        default:
            break;
    }
    if (bgclr == colortype::Colors::DEFAULT_COLOR) {
        bgclrs = "49";
    }
    std::string fgclrs = "";
    switch (mode) {
        case colortype::Mode::BIT_8:
            fgclrs = "38;05;" + std::to_string(fgclr);
            break;
        case colortype::Mode::BIT_24:
            fgclrs = "38;02;" + std::to_string(((fgclr >> 16) & 0xFF)) + ";" + std::to_string(((fgclr >> 8) & 0xFF)) + ";" + std::to_string(((fgclr) & 0xFF));
            break;
        default:
            break;
    }
    if (fgclr == colortype::Colors::DEFAULT_COLOR) {
        fgclrs = "39";
    }

    if (clearAttributes)
        return colortype::getEscapeString(colortype::ESC::escape,
                                          fgclrs,
                                          bgclrs,
                                          underline,
                                          reverseVideo)
                                          + str + colortype::ESC::escape + "[0m";
    return colortype::getEscapeString(colortype::ESC::escape,
                                      fgclrs,
                                      bgclrs,
                                      underline,
                                      reverseVideo)
                                      + str;
}

std::string getFormattedString(std::string str, int fgclr, int bgclr, bool underline = false, bool reverseVideo = false, bool clearAttributes = false) {
    return colortype::getFormattedString(str, fgclr, bgclr, colortype::ESC::mode, underline, reverseVideo, clearAttributes);
}

std::string raw(std::string input) {
    std::string output = "";
    for (const char c: input) {
        switch (c) {
            case '\0': output += "\\0"; break;
            case '\a': output += "\\a"; break;
            case '\b': output += "\\b"; break;
            case '\e': output += "\\e"; break;
            case '\f': output += "\\f"; break;
            case '\n': output += "\\n"; break;
            case '\r': output += "\\r"; break;
            case '\t': output += "\\t"; break;
            case '\v': output += "\\v"; break;
            case '\?': output += "\\?"; break;

            case '\'': output += "\\\'"; break;
            case '\"': output += "\\\""; break;
            case '\\': output += "\\\\"; break;

            default: output += c; break;
        }
    }
    return output;
}

} // namespace colortype

#endif
