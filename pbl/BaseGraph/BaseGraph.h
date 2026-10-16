#ifndef BASEGRAPH_H
#define BASEGRAPH_H

#include <string>
#include <climits>

struct Road {
    std::string destination;
    int distance;
    Road* next;
};

struct Location {
    std::string name;
    Road* head;          // adjacency list
    Location* next;      // next location in the list of bases
};

class BaseGraph {
private:
    Location* first;
    int countLocations;
    static const int MAX_LOCATIONS = 100;
    std::string names[MAX_LOCATIONS];
    bool visited[MAX_LOCATIONS];

    Location* findLocation(const std::string& name);
    int getIndex(const std::string& name);
    void collectLocations();
    void DFS(const std::string& name);
    bool roadExists(Location* loc, const std::string& dest);

public:
    BaseGraph();
    ~BaseGraph();

    void addLocation(const std::string& name);
    void addRoad(const std::string& a, const std::string& b, int distance);
    void loadSampleData();          // separated from constructor
    void displayDFS();
    void shortestRoute(const std::string& start, const std::string& destination);
};

#endif
