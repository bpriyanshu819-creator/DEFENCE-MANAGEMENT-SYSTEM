#include <iostream>
#include "BaseGraph.h"

using namespace std;

// -------------------- Constructor & Destructor --------------------

BaseGraph::BaseGraph()
{
    first = nullptr;
    countLocations = 0;
    loadSampleData();   // load the sample bases & roads
}

BaseGraph::~BaseGraph()
{
    Location* location = first;

    while (location != nullptr)
    {
        Road* road = location->head;

        while (road != nullptr)
        {
            Road* nextRoad = road->next;
            delete road;
            road = nextRoad;
        }

        Location* nextLocation = location->next;
        delete location;
        location = nextLocation;
    }
}

// -------------------- Helper Methods --------------------

Location* BaseGraph::findLocation(const string& name)
{
    Location* temp = first;

    while (temp != nullptr)
    {
        if (temp->name == name)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

bool BaseGraph::roadExists(Location* loc, const string& dest)
{
    if (loc == nullptr) return false;

    Road* r = loc->head;
    while (r != nullptr)
    {
        if (r->destination == dest)
            return true;
        r = r->next;
    }
    return false;
}

void BaseGraph::collectLocations()
{
    countLocations = 0;
    Location* temp = first;

    while (temp != nullptr && countLocations < MAX_LOCATIONS)
    {
        names[countLocations] = temp->name;
        countLocations++;
        temp = temp->next;
    }
}

int BaseGraph::getIndex(const string& name)
{
    for (int i = 0; i < countLocations; i++)
    {
        if (names[i] == name)
            return i;
    }
    return -1;
}

// -------------------- Public Methods --------------------

void BaseGraph::addLocation(const string& name)
{
    // Prevent duplicate locations
    if (findLocation(name) != nullptr)
        return;

    if (countLocations >= MAX_LOCATIONS)
    {
        cout << "Maximum number of locations reached.\n";
        return;
    }

    Location* newLocation = new Location;
    newLocation->name = name;
    newLocation->head = nullptr;
    newLocation->next = nullptr;

    if (first == nullptr)
    {
        first = newLocation;
    }
    else
    {
        Location* temp = first;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newLocation;
    }

    // Keep the names array up to date
    names[countLocations] = name;
    countLocations++;
}

void BaseGraph::addRoad(const string& a, const string& b, int distance)
{
    // Sanity checks
    if (a == b || distance < 0)
        return;

    Location* source = findLocation(a);
    Location* destination = findLocation(b);

    if (source == nullptr || destination == nullptr)
        return;

    // Prevent duplicate roads (both directions)
    if (roadExists(source, b) || roadExists(destination, a))
        return;

    // Road a → b
    Road* road1 = new Road;
    road1->destination = b;
    road1->distance = distance;
    road1->next = source->head;
    source->head = road1;

    // Road b → a (undirected)
    Road* road2 = new Road;
    road2->destination = a;
    road2->distance = distance;
    road2->next = destination->head;
    destination->head = road2;
}

void BaseGraph::loadSampleData()
{
    // Clear any existing data first (optional safety)
    // In this design we call it only once from the constructor.

    addLocation("Dehradun");
    addLocation("Delhi");
    addLocation("Chandigarh");
    addLocation("Lucknow");
    addLocation("Jaipur");

    addRoad("Dehradun", "Delhi", 250);
    addRoad("Dehradun", "Chandigarh", 170);
    addRoad("Delhi", "Jaipur", 280);
    addRoad("Delhi", "Lucknow", 550);
    addRoad("Chandigarh", "Jaipur", 500);
    addRoad("Jaipur", "Lucknow", 570);
}

// -------------------- DFS --------------------

void BaseGraph::DFS(const string& name)
{
    int index = getIndex(name);

    if (index == -1 || visited[index])
        return;

    visited[index] = true;
    cout << name << " ";

    Location* location = findLocation(name);
    if (location == nullptr) return;

    Road* road = location->head;
    while (road != nullptr)
    {
        if (!visited[getIndex(road->destination)])
            DFS(road->destination);
        road = road->next;
    }
}

void BaseGraph::displayDFS()
{
    collectLocations();

    for (int i = 0; i < countLocations; i++)
        visited[i] = false;

    cout << "\n===== RECURSIVE DFS TRAVERSAL =====\n";
    DFS("Dehradun");
    cout << endl;
}

// -------------------- Dijkstra (Shortest Route) --------------------

void BaseGraph::shortestRoute(const string& start, const string& destination)
{
    collectLocations();

    int source = getIndex(start);
    int target = getIndex(destination);

    if (source == -1 || target == -1)
    {
        cout << "\nInvalid base name.\n";
        cout << "Available bases: ";
        for (int i = 0; i < countLocations; i++)
        {
            cout << names[i];
            if (i < countLocations - 1) cout << ", ";
        }
        cout << endl;
        return;
    }

    int distance[MAX_LOCATIONS];
    int parent[MAX_LOCATIONS];
    bool used[MAX_LOCATIONS];

    for (int i = 0; i < countLocations; i++)
    {
        distance[i] = INT_MAX;
        parent[i] = -1;
        used[i] = false;
    }

    distance[source] = 0;

    // Dijkstra
    for (int i = 0; i < countLocations; i++)
    {
        int current = -1;

        for (int j = 0; j < countLocations; j++)
        {
            if (!used[j] && (current == -1 || distance[j] < distance[current]))
            {
                current = j;
            }
        }

        if (current == -1 || distance[current] == INT_MAX)
            break;

        used[current] = true;

        Location* location = findLocation(names[current]);
        if (location == nullptr) continue;

        Road* road = location->head;
        while (road != nullptr)
        {
            int nextIndex = getIndex(road->destination);

            if (nextIndex != -1 &&
                distance[current] <= INT_MAX - road->distance &&
                distance[current] + road->distance < distance[nextIndex])
            {
                distance[nextIndex] = distance[current] + road->distance;
                parent[nextIndex] = current;
            }
            road = road->next;
        }
    }

    if (distance[target] == INT_MAX)
    {
        cout << "\nNo route exists between these bases.\n";
        return;
    }

    // Reconstruct path
    int path[MAX_LOCATIONS];
    int pathSize = 0;
    int current = target;

    while (current != -1 && pathSize < MAX_LOCATIONS)
    {
        path[pathSize++] = current;
        current = parent[current];
    }

    cout << "\n===== SHORTEST ROUTE =====\n";
    for (int i = pathSize - 1; i >= 0; i--)
    {
        cout << names[path[i]];
        if (i > 0) cout << " -> ";
    }
    cout << "\nTotal distance: " << distance[target] << " km\n";
}
