#ifndef NAVY_H
#define NAVY_H

#include "../Force/Force.h"
#include "../Weapon/Weapon.h"

class Navy : public Force
{
private:
    int ships;
    Weapon weapons;

public:
    Navy(int s, int sh);

    void navyMission();
    void displayNavyWeapons();
    void updateNavyWeapon(string weaponName, int quantity);
};

#endif