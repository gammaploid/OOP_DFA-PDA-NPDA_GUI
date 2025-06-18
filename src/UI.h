#ifndef UI_H
#define UI_H

#include <string>

// ANSI color codes
#define PINK_BG "\033[48;5;218m"
#define RESET "\033[0m"

namespace UI {
    void print_ascii_art();
    void printSuccess(std::string& automat_name, std::string& input);
    void printFail(std::string& automat_name, std::string& input);
    void printWelcome(std::string& automat_name, std::string& language_desc);
    void printProcessing();
}

#endif // UI_H 