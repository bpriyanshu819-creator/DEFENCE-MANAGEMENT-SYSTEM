#include <iostream>
#include "Navy.h"

using namespace std;

Navy::Navy(int s, int sh)
    : Force(s), ships(sh), weapons("Navy")
{
}

void Navy::navyMission()
{
    cout << "Navy Mission: Naval Operation" << endl;
    cout << "Navy Strength: " << strength << endl;
    cout << "Number of Ships: " << ships << endl;

    cout << "\nNavy Weapons:" << endl;
    weapons.displayWeapons();
}

void Navy::displayNavyWeapons()
{
    weapons.displayWeapons();
}

void Navy::updateNavyWeapon(string weaponName, int quantity)
{
    weapons.updateQuantity(weaponName, quantity);
}