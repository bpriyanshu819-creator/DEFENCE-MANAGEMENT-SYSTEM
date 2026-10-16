#include <iostream>
#include "AirForce.h"

using namespace std;

AirForce::AirForce(int s, int a)
    : Force(s), aircraft(a), weapons("AirForce")
{
}

void AirForce::airforceMission()
{
    cout << "AirForce Mission: Air Operation" << endl;
    cout << "AirForce Strength: " << strength << endl;
    cout << "Number of Aircraft: " << aircraft << endl;

    cout << "\nAirForce Weapons:" << endl;
    weapons.displayWeapons();
}

void AirForce::displayAirForceWeapons()
{
    weapons.displayWeapons();
}

void AirForce::updateAirForceWeapon(string weaponName, int quantity)
{
    weapons.updateQuantity(weaponName, quantity);
}