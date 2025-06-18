#ifndef DFA_H
#define DFA_H

#include "Automaton.h"

class dfa : public DasAutomat {
private:
    enum State { S0, S1, S2, S3 };
    State currentState;
    State transition(State state, char input);

public:
    dfa();
    bool read(std::string& input) override;
    void reset() override;
};

#endif // DFA_H 