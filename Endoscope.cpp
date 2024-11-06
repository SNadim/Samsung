#include<bits/stdc++.h>
using namespace std;
int N,M,X,Y,L;
int mp[55][55], visited[55][55];

struct node{
    int x, y, l;
};

bool valid(int x, int y)
{
    return (x < N && x >= 0 && y < M && y >= 0);
}
bool left(int x, int y)
{
    return (mp[x][y] == 1 || mp[x][y] == 3 || mp[x][y] == 6 || mp[x][y] == 7);
}

bool right(int x, int y)
{
    return (mp[x][y] == 1 || mp[x][y] == 3 || mp[x][y] == 4 || mp[x][y] == 5);
}
bool up(int x, int y)
{
    return (mp[x][y] == 1 || mp[x][y] == 2 || mp[x][y] == 4 || mp[x][y] == 7);
}
bool down(int x, int y)
{
    return (mp[x][y] == 1 || mp[x][y] == 2 || mp[x][y] == 5 || mp[x][y] == 6);
}
int solve(int x, int y, int l)
{
    int ans = 0;
    visited[x][y] = 1;
    queue<node> q;
    q.push({x, y, l});
    while(!q.empty())
    {
        node front = q.front();
        q.pop();
        int x = front.x;
        int y = front.y;
        int l = front.l;
        if(l == 0) continue;
        ans++;
        if(valid(x, y-1) && left(x, y) && right(x, y-1) && !visited[x][y-1])
        {
            q.push({x, y-1, l-1});
            visited[x][y-1] = 1;
        }
        if(valid(x, y+1) && right(x, y) && left(x, y+1) && !visited[x][y+1])
        {
            q.push({x, y+1, l-1});
            visited[x][y+1] = 1;
        }
        if(valid(x-1, y) && up(x, y) && down(x-1, y) && !visited[x-1][y])
        {
            q.push({x-1, y, l-1});
            visited[x-1][y] = 1;
        }
        if(valid(x+1, y) && down(x, y) && up(x+1, y) && !visited[x+1][y])
        {
            q.push({x+1, y, l-1});
            visited[x+1][y] = 1;
        }
    }
    
    return ans;
}
int main()
{
    int t;cin >> t;
    while(t--)
    {
        cin >> N >> M >> X >> Y >> L;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                cin >> mp[i][j];
                visited[i][j] = 0;
            }
        }
        if(mp[X][Y] > 0)
            {
                cout << solve(X, Y, L) << '\n';
            }
            else cout << 0 << '\n';
    }
}
