#include "Weapon.h"

Weapon::Weapon(string forceType)
{
    if (forceType == "Army")
    {
        weapons.push_back({"Guns", 50});
        weapons.push_back({"Missile", 10});
        weapons.push_back({"Tank", 5});
    }
    else if (forceType == "Navy")
    {
        weapons.push_back({"Submarine", 8});
        weapons.push_back({"Ships", 20});
        weapons.push_back({"Torpedo", 15});
    }
    else if (forceType == "AirForce")
    {
        weapons.push_back({"Aircraft", 12});
        weapons.push_back({"Drones", 20});
        weapons.push_back({"Helicopter", 6});
    }

    sortByQuantity();
}

void Weapon::sortByQuantity()
{
    sort(weapons.begin(), weapons.end(),[](const pair<string, int>& a, const pair<string, int>& b)
    {
        return a.second > b.second;
    });
}

void Weapon::displayWeapons()
{
    cout << "=================== Weapons ===================" << endl;
    cout << "Weapon Type\t\tQuantity" << endl;
    for (auto &weapon : weapons)
    {
        cout << weapon.first << "\t\t" << weapon.second << endl;
    }
}

void Weapon::updateQuantity(string weaponName, int quantity)
{
    for (auto &weapon : weapons)
    {
        if (weapon.first == weaponName)
        {
            weapon.second = quantity;
            cout << "Quantity updated successfully." << endl;
            return;
        }
    }

    cout << "Weapon not found." << endl;
}