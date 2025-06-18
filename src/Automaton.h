#ifndef DASAUTOMAT_H
#define DASAUTOMAT_H

#include <string>

class DasAutomat {
public:
    virtual ~DasAutomat() {}
    virtual bool read(std::string& input) = 0;
    virtual void reset() = 0;
};

#endif // DASAUTOMAT_H 