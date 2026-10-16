#include <iostream>
#include "JointOperation.h"

using namespace std;

void JointOperation::startJointOperation(Army &army,Navy &navy,AirForce &airforce)
{
    cout << "\n===== JOINT OPERATION =====" << endl;

    cout << "Army: Ground Support" << endl;
    cout << "Navy: Naval Support" << endl;
    cout << "AirForce: Air Support" << endl;

    int totalStrength =army.getStrength() +navy.getStrength() +airforce.getStrength();

    cout << "Combined Strength: "<< totalStrength << endl;
}