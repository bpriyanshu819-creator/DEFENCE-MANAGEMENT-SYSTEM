
#include <iostream>
#include <string>
#include <limits>
#include <climits>

#include "Army/Army.h"
#include "Navy/Navy.h"
#include "AirForce/AirForce.h"
#include "JointOperation/JointOperation.h"
#include "MissionScheduler/MissionScheduler.h"
#include "BaseGraph/BaseGraph.h"

using namespace std;

int main()
{
    Army army(100, 80);
    Navy navy(90, 20);
    AirForce airforce(70, 30);

    JointOperation joint;
    MissionScheduler scheduler;
    BaseGraph graph;

    int choice;

    do
    {
        cout << "\n====================================================\n";
        cout << "     INTEGRATED DEFENCE OPERATION MANAGEMENT SYSTEM\n";
        cout << "====================================================\n";

        cout << "1. Army Mission\n";
        cout << "2. Navy Mission\n";
        cout << "3. AirForce Mission\n";
        cout << "4. Display Force Strength\n";
        cout << "5. Joint Operation\n";
        cout << "6. Display Army Weapons\n";
        cout << "7. Display Navy Weapons\n";
        cout << "8. Display AirForce Weapons\n";
        cout << "9. Update Army Weapon\n";
        cout << "10. Update Navy Weapon\n";
        cout << "11. Update AirForce Weapon\n";
        cout << "12. Submit Mission Request\n";
        cout << "13. Execute Next Mission\n";
        cout << "14. Display Mission Execution Sequence\n";
        cout << "15. Traverse Bases using Recursive DFS\n";
        cout << "16. Find Shortest Route using Dijkstra\n";
        cout << "17. Find Nearest Base\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            cout << "\n===== ARMY MISSION =====\n";
            army.armyMission();
            break;

        case 2:
            cout << "\n===== NAVY MISSION =====\n";
            navy.navyMission();
            break;

        case 3:
            cout << "\n===== AIR FORCE MISSION =====\n";
            airforce.airforceMission();
            break;

        case 4:
            cout << "\n===== FORCE STRENGTH =====\n";
            cout << "Army Strength: " << army.getStrength() << endl;
            cout << "Navy Strength: " << navy.getStrength() << endl;
            cout << "AirForce Strength: " << airforce.getStrength() << endl;
            break;

        case 5:
            joint.startJointOperation(army, navy, airforce);
            break;

        case 6:
            cout << "\n===== ARMY WEAPONS =====\n";
            army.displayArmyWeapons();
            break;

        case 7:
            cout << "\n===== NAVY WEAPONS =====\n";
            navy.displayNavyWeapons();
            break;

        case 8:
            cout << "\n===== AIR FORCE WEAPONS =====\n";
            airforce.displayAirForceWeapons();
            break;

        case 9:
        {
            string weaponName;
            int quantity;

            cout << "Enter Army weapon name: ";
            cin >> weaponName;
            cout << "Enter new quantity: ";

            if (!(cin >> quantity))
            {
                cout << "Quantity must be a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            if (quantity < 0)
                cout << "Quantity cannot be negative.\n";
            else
                army.updateArmyWeapon(weaponName, quantity);

            break;
        }

        case 10:
        {
            string weaponName;
            int quantity;

            cout << "Enter Navy weapon name: ";
            cin >> weaponName;
            cout << "Enter new quantity: ";

            if (!(cin >> quantity))
            {
                cout << "Quantity must be a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            if (quantity < 0)
                cout << "Quantity cannot be negative.\n";
            else
                navy.updateNavyWeapon(weaponName, quantity);

            break;
        }

        case 11:
        {
            string weaponName;
            int quantity;

            cout << "Enter AirForce weapon name: ";
            cin >> weaponName;
            cout << "Enter new quantity: ";

            if (!(cin >> quantity))
            {
                cout << "Quantity must be a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            if (quantity < 0)
                cout << "Quantity cannot be negative.\n";
            else
                airforce.updateAirForceWeapon(weaponName, quantity);

            break;
        }

        case 12:
            scheduler.requestMission();
            break;

        case 13:
            scheduler.executeNextMission();
            break;

        case 14:
            scheduler.displaySequence();
            break;

        case 15:
            graph.displayDFS();
            break;

        case 16:
        {
            string start;
            string destination;

            cout << "\nAvailable bases:\n";
            cout << "Dehradun, Delhi, Chandigarh, Lucknow, Jaipur\n";

            cout << "Enter starting base: ";
            getline(cin, start);

            cout << "Enter destination base: ";
            getline(cin, destination);

            graph.shortestRoute(start, destination);
            break;
        }

        case 17:
        {
            string bases[5] = {
                "Dehradun", "Delhi", "Chandigarh",
                "Lucknow", "Jaipur"
            };

            int roads[5][5] = {
                {0, 250, 170,   0,   0},
                {250, 0,   0, 550, 280},
                {170, 0,   0,   0, 500},
                {0, 550,   0,   0, 570},
                {0, 280, 500, 570,   0}
            };

            string currentBase;

            cout << "\n===== FIND NEAREST BASE =====\n";
            cout << "Available bases:\n";
            cout << "Dehradun, Delhi, Chandigarh, Lucknow, Jaipur\n";
            cout << "Enter your current base: ";
            getline(cin, currentBase);

            int source = -1;

            for (int i = 0; i < 5; i++)
            {
                if (bases[i] == currentBase)
                {
                    source = i;
                    break;
                }
            }

            if (source == -1)
            {
                cout << "Invalid base name.\n";
                break;
            }

            int distance[5];
            bool visited[5] = {false};

            for (int i = 0; i < 5; i++)
                distance[i] = INT_MAX;

            distance[source] = 0;

            // Dijkstra's algorithm
            for (int i = 0; i < 5; i++)
            {
                int current = -1;

                for (int j = 0; j < 5; j++)
                {
                    if (!visited[j] &&
                        (current == -1 ||
                         distance[j] < distance[current]))
                    {
                        current = j;
                    }
                }

                if (current == -1 ||
                    distance[current] == INT_MAX)
                    break;

                visited[current] = true;

                for (int j = 0; j < 5; j++)
                {
                    if (roads[current][j] > 0 &&
                        distance[current] != INT_MAX &&
                        distance[current] + roads[current][j]
                            < distance[j])
                    {
                        distance[j] =
                            distance[current] + roads[current][j];
                    }
                }
            }

            int nearest = -1;
            int minimumDistance = INT_MAX;

            for (int i = 0; i < 5; i++)
            {
                if (i != source && distance[i] < minimumDistance)
                {
                    minimumDistance = distance[i];
                    nearest = i;
                }
            }

            if (nearest != -1)
            {
                cout << "\nNearest base: " << bases[nearest] << endl;
                cout << "Shortest distance: "
                     << minimumDistance << " km\n";

                cout << "\nShortest route:\n";
                graph.shortestRoute(currentBase, bases[nearest]);
            }
            else
            {
                cout << "No reachable base found.\n";
            }

            break;
        }

        case 0:
            cout << "\nExiting the system...\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
