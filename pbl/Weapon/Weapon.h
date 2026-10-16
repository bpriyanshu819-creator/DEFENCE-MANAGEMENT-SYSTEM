#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Weapon
{
private:
    vector<pair<string, int>> weapons;
    void sortByQuantity();

public:
    Weapon(string forceType);

    void displayWeapons();
    void updateQuantity(string weaponName, int quantity);
};

#endif