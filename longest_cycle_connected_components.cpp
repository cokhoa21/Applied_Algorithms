#include<bits/stdc++.h>
#include<vector>
#include<map>
#include<set>
#include<queue>

using namespace std;
#define MAX 1e5
struct Point {
    string id;
    int x, y;
}

struct Segment {
    string id, point1, point2;
}

map<string, Point> points;
map<string, Segment> segments;
map<string, vector<string>> adjcencyList;

void addPoint(string id, int x, int y) {
    points[id] = {id, x, y};
}

void addSegment(string id, string point1, string point2) {
    segments[id] = {id, point1, point2};
    adjcencyList[point1].push_back(point2);
    adjcencyList[point2].push_back(point1);
}

void dfs(string currentPoint, set<string>& visited) {
    visited.insert(currentPoint);

    for(string neighbor : adjcencyList[currentPoint]) {
        if(visited.find(neighbor) == visited.end()) {
            dfs(neighbor, visited);
        }
    }
}

int getNumberPoints() {
    return points.size();
}

int getNumberSegments() {
    return segments.size();
}

int getConnectedComponents() {
    set<string> visited;
    int cnt = 0;
    for(Point point : points) {
        if(visited.find(point.id) == visited.end()) {
            dfs(point.id, visited);
            cnt ++;
        }
    }
    return cnt;
}

int getLongestCycleFrom(string startPoint) {
    map<string, int> distance;
    queue<string> q;

    q.push(startPoint);
    distance[startPoint] = 0;

    while (!q.empty()) {
        string currentPoint = q.front();
        q.pop();

        for (const auto& neighbor : adjacencyList[currentPoint]) {
            if (distance.find(neighbor) == distance.end()) {
                q.push(neighbor);
                distance[neighbor] = distance[currentPoint] + 1;
            }
        }
    }

    int maxDistance = 0;
    for (const auto& d : distance) {
        maxDistance = max(maxDistance, d.second);
    }

    // A cycle has n edges and n+1 vertices, so return (maxDistance + 1) / 2
    return maxDistance + 1;
}


void input() {
    string pointID;
    int x, y;
    while(cin >> pointID && pointID != "#") {
        cin >> x >> y;
        addPoint(pointID, x, y);
    }

    string segmentId, point1, point2;
    while (cin >> segmentId && segmentId != "#")
    {
        cin >> point1 >> point2;
        addSegment(segmentId, point1, point2);
    }

    string query;
    while (cin >> query && query != "###") {
        if (query == "?number_points") {
            cout << getNumberPoints() << endl;
        } else if (query == "?number_segments") {
            cout << getNumberSegments() << endl;
        } else if (query == "?connected_components") {
            cout << getConnectedComponents() << endl;
        } else if (query.substr(0, 19) == "?longest_cycle_from") {
            string startPoint = query.substr(20);
            cin >> startPoint;
            cout << getLongestCycleFrom(startPoint) << endl;
        }
    }
}

int main() {
    input();
    return 0;
}