#include "Force.h"

Force::Force(int s)
{
    strength = s;
}

int Force::getStrength()
{
    return strength;
}

void Force::setStrength(int s)
{
    strength = s;
}