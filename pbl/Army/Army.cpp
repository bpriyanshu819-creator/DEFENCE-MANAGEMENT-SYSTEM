#include <iostream>
#include "Army.h"

using namespace std;

Army::Army(int s, int ws) : Force(s), weaponStrength(ws), weapons("Army")
{
}

void Army::armyMission()
{
    cout << "Army Mission: Ground Operation" << endl;
    cout << "Army Strength: " << strength << endl;
    cout << "Weapon Strength: " << weaponStrength << endl;

    cout << "\nArmy Weapons:" << endl;
    weapons.displayWeapons();
}

void Army::displayArmyWeapons()
{
    weapons.displayWeapons();
}

void Army::updateArmyWeapon(string weaponName, int quantity)
{
    weapons.updateQuantity(weaponName, quantity);
}