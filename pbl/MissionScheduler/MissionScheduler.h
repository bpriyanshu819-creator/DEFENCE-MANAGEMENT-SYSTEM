#ifndef MISSION_SCHEDULER_H
#define MISSION_SCHEDULER_H

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

struct MissionRequest
{
    int requestID;
    string forceName;
    string missionName;
    int priority;
};

struct CompareMission
{
    bool operator()(const MissionRequest& a,
                    const MissionRequest& b)
    {
        if (a.priority == b.priority)
            return a.requestID > b.requestID;

        return a.priority < b.priority;
    }
};

class MissionScheduler
{
private:
    priority_queue<MissionRequest,
                   vector<MissionRequest>,
                   CompareMission> pendingMissions;

    int nextID;

public:
    MissionScheduler();

    void requestMission();
    void displaySequence();
    void executeNextMission();
};

#endif