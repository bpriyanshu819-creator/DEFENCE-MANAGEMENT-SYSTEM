#include "MissionScheduler.h"

using namespace std;

MissionScheduler::MissionScheduler()
{
    nextID = 1;
}

void MissionScheduler::requestMission()
{
    MissionRequest m;
    m.requestID = nextID;

    cout << "\n===== SELECT FORCE =====\n";
    cout << "1. Army\n";
    cout << "2. Navy\n";
    cout << "3. Air Force\n";
    cout << "Enter choice: ";

    int forceChoice;
    cin >> forceChoice;

    switch (forceChoice)
    {
        case 1:
            m.forceName = "Army";
            break;

        case 2:
            m.forceName = "Navy";
            break;

        case 3:
            m.forceName = "Air Force";
            break;

        default:
            cout << "Invalid force selection.\n";
            return;
    }

    cout << "\n===== SELECT MISSION =====\n";
    cout << "1. Emergency Rescue / Evacuation - Priority 5\n";
    cout << "2. Urgent Medical Support - Priority 4\n";
    cout << "3. Essential Logistics - Priority 3\n";
    cout << "4. Routine Patrol / Transport - Priority 2\n";
    cout << "5. Training / Maintenance - Priority 1\n";
    cout << "Enter mission choice: ";

    int typeChoice;
    cin >> typeChoice;

    switch (typeChoice)
    {
        case 1:
            m.missionName = "Emergency Rescue / Evacuation";
            m.priority = 5;
            break;

        case 2:
            m.missionName = "Urgent Medical Support";
            m.priority = 4;
            break;

        case 3:
            m.missionName = "Essential Logistics";
            m.priority = 3;
            break;

        case 4:
            m.missionName = "Routine Patrol / Transport";
            m.priority = 2;
            break;

        case 5:
            m.missionName = "Training / Maintenance";
            m.priority = 1;
            break;

        default:
            cout << "Invalid mission choice.\n";
            return;
    }

    pendingMissions.push(m);
    nextID++;

    cout << "\nMission submitted successfully!\n";
    cout << "Request ID: " << m.requestID << endl;
    cout << "Force: " << m.forceName << endl;
    cout << "Mission: " << m.missionName << endl;
    cout << "Priority: " << m.priority << endl;
}

void MissionScheduler::displaySequence()
{
    if (pendingMissions.empty())
    {
        cout << "\nNo pending missions.\n";
        return;
    }

    priority_queue<MissionRequest,
                   vector<MissionRequest>,
                   CompareMission> temp = pendingMissions;

    cout << "\n===== MISSION EXECUTION SEQUENCE =====\n";

    int position = 1;

    while (!temp.empty())
    {
        MissionRequest m = temp.top();

        cout << "\nExecution Position: " << position << endl;
        cout << "Request ID: " << m.requestID << endl;
        cout << "Force: " << m.forceName << endl;
        cout << "Mission: " << m.missionName << endl;
        cout << "Priority: " << m.priority << endl;

        temp.pop();
        position++;
    }
}

void MissionScheduler::executeNextMission()
{
    if (pendingMissions.empty())
    {
        cout << "\nNo pending missions to execute.\n";
        return;
    }

    MissionRequest m = pendingMissions.top();

    cout << "\n===== EXECUTING NEXT MISSION =====\n";
    cout << "Request ID: " << m.requestID << endl;
    cout << "Force: " << m.forceName << endl;
    cout << "Mission: " << m.missionName << endl;
    cout << "Priority: " << m.priority << endl;

    pendingMissions.pop();

    cout << "\nMission marked as executed.\n";
}