#ifndef JOINTOPERATION_H
#define JOINTOPERATION_H

#include "../Army/Army.h"
#include "../Navy/Navy.h"
#include "../AirForce/AirForce.h"

class JointOperation
{
public:
    void startJointOperation(Army &army, Navy &navy, AirForce &airforce);
};

#endif