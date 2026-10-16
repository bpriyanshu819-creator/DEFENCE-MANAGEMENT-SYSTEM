#ifndef ARMY_H
#define ARMY_H

#include "../Force/Force.h"
#include "../Weapon/Weapon.h"

class Army : public Force
{
private:
    int weaponStrength;
    Weapon weapons;

public:
    Army(int s, int ws);

    void armyMission();
    void displayArmyWeapons();
    void updateArmyWeapon(string weaponName, int quantity);
};

#endif