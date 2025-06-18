#include "UI.h"
#include <iostream>

void UI::print_ascii_art() {
    std::cout << "                              \\\\\\\\" << std::endl;
    std::cout << "                            \\\\\\\\\\\\\\\\" << std::endl;
    std::cout << "                          \\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;
    std::cout << "  -----------,-|           |C>   // )\\\\|\\" << std::endl;
    std::cout << "           ,','|          /    || ,'/////|\\" << std::endl;
    std::cout << "---------,','  |         (,    ||   /////" << std::endl;
    std::cout << "         ||    |          \\\\  ||||//''''|\\" << std::endl;
    std::cout << "         ||    |           |||||||     _|" << std::endl;
    std::cout << "         ||    |______      `````\\____/ \\" << std::endl;
    std::cout << "         ||    |     ,|         _/_____/ \\" << std::endl;
    std::cout << "         ||  ,'    ,' |        /          |" << std::endl;
    std::cout << "         ||,'    ,'   |       |         \\  |" << std::endl;
    std::cout << "_________|/    ,'     |      /           | |" << std::endl;
    std::cout << "_____________,'      ,',_____|      |    | |" << std::endl;
    std::cout << "             |     ,','      |      |    | |" << std::endl;
    std::cout << "             |   ,','    ____|_____/    /  |" << std::endl;
    std::cout << "             | ,','  __/ |             /   |" << std::endl;
    std::cout << "_____________|','   ///_/-------------/   |" << std::endl;
    std::cout << "              |===========,'" << std::endl << std::endl;
}

void UI::printWelcome(std::string& automat_name, std::string& language_desc) {
    std::cout << "============================================" << std::endl;
    std::cout << "Welcome to the machine. You have entered a " << automat_name << " machine." << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << language_desc << std::endl << std::endl << std::endl;
}

void UI::printSuccess(std::string& automat_name, std::string& input) {
    std::cout << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "Final state for string: " << input << " → ACCEPTED! ✓" << std::endl;
    if (automat_name == "DFA") { 
        std::cout << "Perfect! Exactly one '1' found!  🎯" << std::endl;
     } else if (automat_name == "PDA") {
        std::cout << "Excellent! It matches the 0^n 1^n+1 pattern!" << std::endl;
    } else if (automat_name == "NPDA") {
        std::cout << "Sweet! That's a palindrome! 🔄 "  << std::endl;
    }
    std::cout << "============================================" << std::endl;
    std::cout << std::endl << std::endl << "	(｡◕‿‿◕｡) happy machine!" << std::endl  << std::endl;
}

void UI::printFail(std::string& automat_name, std::string& input)  {
    std::cout << std::endl;
    std::cout << "********************************************" << std::endl;
    std::cout << "Final state for string:" << input << " → REJECTED " << std::endl;
    if (automat_name == "DFA") {
        std::cout << "Our hard working DFA couldn't compute." <<" More than one [1] or no [1's] yet" << std::endl;
    } else if (automat_name == "PDA") {
        std::cout << "Our hard working PDA couldn't compute." <<" It's NOT in the language {0^n 1^n+1}" << std::endl;
    } else if  (automat_name == "NPDA") {
        std::cout << "Our hard working NPDA couldn't compute." <<" It's NOT a palindrome." << std::endl;
    }
    std::cout << "********************************************" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
    std::cout << " _________        .---'''''      '''''---." << std::endl;
    std::cout << ":______.-':      :  .--------------.  :            " << std::endl;
    std::cout << "| ______  |      | :                : |            " << std::endl;
    std::cout << "|:______B:|      | |  Little Error: | |            " << std::endl;
    std::cout << "|:______B:|      | |  ୧༼ಠ益ಠ༽︻╦╤─  | |            " << std::endl;
    std::cout << "|:______B:|      | |                | |            " << std::endl;
    std::cout << "|         |      | |  " << automat_name << " doesn't " << " | |            " << std::endl;
    std::cout << "|:_____:  |      | |   like your   | |            " << std::endl;
    std::cout << "|    ==   |      : :    string!     : :            " << std::endl;
    std::cout << "|       O |      :  '--------------'  :            " << std::endl;
    std::cout << "|       o |      :'---...______...---'              " << std::endl;
    std::cout << "|       o |-._.-i___/'             \\._             " << std::endl;
    std::cout << "'-.____o_|   '-.   '-...______...-'  `-._         " << std::endl;
    std::cout << ":_________:      `.____________________   `-.___.-." << std::endl;
    std::cout << "                 .'.eeeeeeeeeeeeeeeeee.'.      :___:" << std::endl;
    std::cout << "    fsc        .'.eeeeeeeeeeeeeeeeeeeeee.'.        " << std::endl;
    std::cout << "              :____________________________:" << std::endl;
}


void UI::printProcessing() {
    std::cout << std::endl << "PROCESSING STRING..." << std::endl;
    std::cout << "-------------------------------------------" << std::endl << std::endl;
} 