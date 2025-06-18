#ifndef PDA_H
#define PDA_H

#include "Automaton.h"
#include <stack>

class pda : public DasAutomat {
private:
    enum State { S0, S1, S2, S_INVALID };
    State currentState;
    std::stack<char> stack;
    State transition(char input);

public:
    pda();
    bool read(std::string& input) override;
    void reset() override;
};

#endif // PDA_H 