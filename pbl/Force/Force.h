#ifndef FORCE_H
#define FORCE_H

class Force
{
protected:
    int strength;

public:
    Force(int s);

    int getStrength();
    void setStrength(int s);
};

#endif