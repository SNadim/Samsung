#include<iostream>
#include<math.h>
using namespace std;
int n, sourceX = 0, sourceY = 0, destinationX = 100, destinationY = 100, shortestRoute;
int X[10], Y[10], visited[100];

int getDistance(int x1, int y1, int x2, int y2)
{
    int x = x1-x2;
    int y = y1-y2;
    int result = abs(x) + abs(y);
    return result;
}

void explore(int current, int cost, int nodeLeft)
{
    if(nodeLeft <= 1)
    {
        if(cost + getDistance(X[current], Y[current], destinationX, destinationY) < shortestRoute)
        {
            shortestRoute = cost + getDistance(X[current], Y[current], destinationX, destinationY);
        }
        return;
    }
    
    visited[current] = 1;
    
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            explore(i, cost + getDistance(X[current], Y[current], X[i], Y[i]), nodeLeft - 1);
        }
    }
    visited[current] = 0;
}

int main()
{
    
    for(int i = 1; i <= 10; i++)
    {
        cin >> n;
        cin >> sourceX >> sourceY >> destinationX >> destinationY;
        
        for(int j = 0; j < n; j++)
        {
            cin >> X[j] >> Y[j];
            visited[j] = 0;
        }
        
        shortestRoute = 1000000;
        for(int j = 0; j < n; j++)
        {
            explore(j, getDistance(X[j], Y[j], sourceX, sourceY), n);
        }
        cout << "# " << i << " " << shortestRoute << '\n';
    }
    return 0;
}
