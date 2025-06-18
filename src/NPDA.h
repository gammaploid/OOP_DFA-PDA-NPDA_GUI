#ifndef NPDA_H
#define NPDA_H

#include "Automaton.h"
#include <stack>

class npda : public DasAutomat {
private:
    std::stack<char> stack;

public:
    npda();
    bool read(std::string& input) override;
    void reset() override;
};

#endif // NPDA_H 