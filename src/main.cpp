#include <iostream>
#include <limits> // Required for std::numeric_limits -- for empty string in npda
#include "Automaton.h"  
#include "DFA.h"        
#include "PDA.h"        
#include "NPDA.h"       
#include "UI.h"

void run(DasAutomat& automat, std::string& name, std::string& language_desc)  {  
    
    std::string input;  
                       
    char again = 'y';

    std::cout << PINK_BG;  // pink background

    while (again == 'y' || again == 'Y') {
        UI::print_ascii_art();
        UI::printWelcome(name, language_desc);
        
        std::getline(std::cin, input);
        
        automat.reset();  
        UI::printProcessing();

         
        if (automat.read(input))  {  
            UI::printSuccess(name, input);
        } else {
            UI::printFail(name,  input);
        }

        std::cout << std::endl << "Try another? (y/n):   ";
        std::cin >> again;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume the rest of the line
        std::cout << std::endl;
    }

    std::cout << "Thanks for playing with the machines! 👋" <<  std::endl; 
    std::cout << RESET; // reset color
}

int main() {

    int choice;
    
    dfa dfaMachine;      
    pda pdaMachine;   
    npda npdaMachine;
    
    std::cout << PINK_BG;
    std::cout << "Welcome to the machine. " << std::endl;
    std::cout << "Pick your machine:" << std::endl;
    std::cout << "1. DFA (finds exactly one '1')" << std::endl;
    std::cout << "2. PDA (checks 0^n 1^n+1 pattern) " << std::endl;
    std::cout << "3. NPDA (palindrome checker)" << std::endl;
    std::cout << "Choice (1-3): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume the rest of the line
    std::cout << RESET;

    // polymorphism  
    // Each case calls run() 
    switch (choice) {
        case 1: {
            std::string name = "DFA";
            std::string lang_desc = "•Enter a binary string that has only one occurence of '1' |  Example: 1, 01, 00010, etc:";
            run(dfaMachine, name, lang_desc);
            break;
        }
        case 2: {
            std::string name = "PDA";
            std::string lang_desc = "•Enter a binary string of the language {0^n 1^n+1}  |  Example: 1, 011, 00111, etc. :";
            run(pdaMachine, name, lang_desc);
            break;
        }
        case 3: {
            std::string name = "NPDA";
            std::string lang_desc = "•Enter a string of palindrome of any two charchters | Example: 1, 010, 110011110011, abba,  empty string";
            run(npdaMachine, name, lang_desc);
            break;
        }
        default:
            std::cout << "Invalid choice! Run the program again." << std::endl;
            return 1;
    }

    return 0;
} 