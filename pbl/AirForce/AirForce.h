#ifndef AIRFORCE_H
#define AIRFORCE_H

#include "../Force/Force.h"
#include "../Weapon/Weapon.h"

class AirForce : public Force
{
private:
    int aircraft;
    Weapon weapons;

public:
    AirForce(int s, int a);

    void airforceMission();
    void displayAirForceWeapons();
    void updateAirForceWeapon(string weaponName, int quantity);
};

#endif