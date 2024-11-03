#include <bits/stdc++.h>

using namespace std;

bool isVisitedAll(vector<int> &vis)
{
    for(auto i : vis) if(i == 0) return false;
    
    return true;
}

int tsp(int n, vector<vector<int>> &M, vector<int> &vis)
{
    if(isVisitedAll(vis)) return M[n][0];
    int minCost = INT_MAX;
    for(int i = 1; i < M.size(); i++)
    {
        if(!vis[i] && i != n)
        {
            vis[i] = 1;
            minCost = min(minCost, tsp(i, M, vis)+M[n][i]);
            vis[i] = 0;
        }
    }
    return minCost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        vector<int> vis(n,0);
        vis[0] = 1;
        cout << tsp(0, M, vis) << '\n';
    }
    return 0;
    
}

