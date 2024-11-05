#include <bits/stdc++.h>

using namespace std;

vector<int> drawPath(int start, int end, unordered_map<int, int> &parent)
{
    int current = start;
    vector<int> path = {start};
    
    while(current != end)
    {
        current = parent[current];
        path.push_back(current);
    }
    sort(path.begin(), path.end());
    return path;
}

bool checkCycleDFS(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &dfsVis, unordered_map<int, int> &parent, vector<int> &cyclePath)
{
    vis[node] = true;
    dfsVis[node] = true;
    
    for(auto i : adjList[node])
    {
        if(!vis[i])
        {
            parent[i] = node;
            bool cycle = checkCycleDFS(i, vis, adjList, dfsVis, parent, cyclePath);
            if(cycle) {
                return true;
            }

        }
        else if(dfsVis[i]) {
            cyclePath = drawPath(node, i, parent);
            return true;
        }
    }
    dfsVis[node] = false;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
    }
    unordered_map<int, bool> vis;
    unordered_map<int, bool> dfsVis;
    
    vector<int> ans;
    for(int i = 1; i <= n; i++)
    {
        unordered_map<int, int> parent;
        if(!vis[i])
        {
            vector<int> cyclePath;
            bool cycle = checkCycleDFS(i, vis, adjList, dfsVis, parent, cyclePath);
            if(cycle)
            {
               ans = cyclePath;
               break;
            }
        }
    }
    
    for(auto i : ans) cout << i << " ";
    cout << "\n";
    
    return 0;
}
