#include "PDA.h"
#include <iostream>

pda::pda() : currentState(S0) {}

void pda::reset() {
    currentState = S0;
    while (!stack.empty()) {
        stack.pop();
    }
}

pda::State pda::transition(char input) {
    char top = stack.empty() ? '$' : stack.top();

    switch (currentState) {
        case S0:
            if (input == '0') {
                stack.push('0');
                return S0;
            } else if (input == '1' && top == '0') {
                stack.pop();
                return S1;
            } else if (input == '1' && top == '$') {
                return S2;
            }
            break;
        case S1:
            if (input == '1' && top == '0') {
                stack.pop();
                return S1;
            } else if (input == '1' && top == '$') {
                return S2;
            }
            break;
        case S2:
            return S_INVALID;

        case S_INVALID:
            return S_INVALID;
    }
    return S_INVALID; // Invalid transition
}

bool pda::read(std::string& input) {
    for ( char c : input) {
        std::cout << "-Read: " << c << " | current state: → 'S" << currentState << "' | Stack Top: " << (stack.empty() ? '$' : stack.top()) << std::endl;
        currentState = transition(c);
        if (currentState == S_INVALID) {
            break;
        }
    }
    std::cout << "-End of string | final state: → 'S" << currentState << "' | Stack Top: " << (stack.empty() ? '$' : stack.top()) << std::endl;
    return currentState == S2 && stack.empty();
} 