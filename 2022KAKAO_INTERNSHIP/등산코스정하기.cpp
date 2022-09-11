#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;
using pii = pair<int, int>;

map<int, int>   gateMap;
map<int, int>   summitMap;

int bfs(int n, int startNode, int endNode, vector<pii> graph[]) {
    vector<int> visited(n + 1, INT_MAX);
    queue<pii>  q; // node, minIntensity
    int minIntensity;
    
    minIntensity = INT_MAX;
    q.push({ startNode, 0 });
    visited[startNode] = 1;
    while (!q.empty()) {
        int currentNode = q.front().first;
        int currentIntensity = q.front().second;
        q.pop();
        
        if (currentNode == endNode) {
            minIntensity = minIntensity > currentIntensity ? currentIntensity : minIntensity;
            continue ;
        }
        for (pii nextInfo: graph[currentNode]) {
            int nextNode = nextInfo.first;
            int nextIntensity = nextInfo.second;
            if (nextIntensity < currentIntensity) {
                nextIntensity = currentIntensity;
            }
            // gate는 2개 이상 x
            if (nextNode != endNode && gateMap.find(nextNode) != gateMap.end()) continue;
            // summit도 2개 이상 x
            if (nextNode != endNode && summitMap.find(nextNode) != summitMap.end()) continue;
            
            // 더 작은 intensity만 가게
            if (visited[nextNode] > nextIntensity) {
                visited[nextNode] = nextIntensity;
                q.push({ nextNode, nextIntensity });    
            }
        }
    }
    return (minIntensity);
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    int minCost;
    int minSummit;
    vector<pii> graph[50001];
    
    minSummit = -1;
    minCost = 500000000;
    for (vector<int> path: paths) {
        graph[path[0]].push_back({ path[1], path[2] });
        graph[path[1]].push_back({ path[0], path[2] });
    }
    for (int summit: summits) {
        gateMap.insert({ summit, 1 });
    }
    for (int gate: gates) {
        summitMap.insert({ gate, 1 });
    }
    for (int gate: gates) {
        for (int summit: summits) {
            int cost = bfs(n, gate, summit, graph);
            if (cost < minCost) {
                minCost = cost;
                minSummit = summit;
            }
        }
    }
    return { minSummit, minCost };
}