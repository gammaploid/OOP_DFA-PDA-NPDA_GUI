#include "DFA.h"
#include <iostream>

dfa::dfa() : currentState(S0) {}

void dfa::reset() {
    currentState = S0;
}

dfa::State dfa::transition(State state, char input) {


    switch (state) {
        case S0:
            if (input == '0') return S1;
            else if (input == '1') return S2;
            else return S0;
        case S1:
            if (input == '0') return S1;
            else if (input == '1') return S2;
            else return S1;
        case S2:
            if (input == '0') return S2;
            else return S3;
        case S3: 
             return S3;
    }
    return state;
}


bool dfa::read(std::string& input) {
    for (char c : input) {
        std::cout << "-Read: " << c << " | current state : → 'S" << currentState << "'" << std::endl;
        currentState = transition(currentState, c);
    }
    std::cout << "-End of string | final state : → 'S" << currentState << "'" << std::endl;
    return currentState == S2;
} 