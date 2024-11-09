#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int minDis = 1e9;

int calculateDist(vector<int> &plot, vector<int> &fisherman)
{
    int dis = 0;
    for(int i = 0; i < plot.size(); i++)
    {
        if(plot[i] != -1)
        {
            dis = dis + abs(fisherman[plot[i]] - i)+1;
        }
    }
    
    return dis;
}

void f(int x, vector<int> &fisherman, vector<int> &plot)
{
    if(x >= fisherman.size())
    {
        int cal = calculateDist(plot, fisherman);
        minDis = min(cal, minDis);
        return;
    }
    
    for(int i = 0; i < plot.size(); i++)
    {
        if(plot[i] == -1)
        {
            plot[i] = x;
            f(x+1, fisherman, plot);
            plot[i] = -1;
        }
    }
}

int main()
{
    int n, a;
    cin >> n;
    vector<int> plot(n, -1);
    vector<int> gate(3);
    for(int i = 0; i < 3; i++)
    {
        cin >> a;
        gate[i] = a-1;
    }
    vector<int> fisherman;
    for(int i = 0; i < 3; i++)
    {
        cin >> a;
        for(int j = 0; j < a; j++)
        {
            fisherman.push_back(gate[i]);
        }
    }
    f(0, fisherman, plot);
    cout << minDis << '\n';
    return 0;
}
