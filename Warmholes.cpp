#include <iostream>
using namespace std;
#define inf 1e9
struct node{
  int x, wt;  
};

node q[100];
int front = 0;
int back = 0;

bool empty()
{
    return front == back;
}

void push(node nums)
{
    q[back++] = nums;
}

node pop()
{
    return q[front++];
}

int dijksta(int graph[101][101], int n)
{
    int dist[2*n+2];
    for(int i = 0 ; i < 2*n+2; i++)
    {
        dist[i] = inf;
    }
    push({0,0});
    
    while(!empty())
    {
        node curr = pop();
        int node = curr.x;
        int wt = curr.wt;
        for(int i = 0; i < 2*n+2; i++)
        {
            int adjwt = graph[i][node];
            
            if(wt+adjwt < dist[i])
            {
                dist[i] = wt+adjwt;
                push({i, dist[i]});
            }
        }
    }
    
    return dist[1];
}


int main() {
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        int graph[101][101];
        for(int i = 0; i < 2*n+2; i++)
        {
            for(int j = 0; j < 2*n+2; j++)
            {
                graph[i][j] = -1;
            }
        }

        int x[2*n+2], y[2*n+2];
        
        for(int i = 0; i < 2; i++)
        {
            cin >> x[i] >> y[i];
        }
        
        for(int i = 2; i < 2*n+2; i+=2)
        {
            int cost;
            cin >> x[i] >> y[i] >> x[i+1] >> y[i+1] >> cost;
            graph[i][i+1] = cost;
            graph[i+1][i] = cost;
        }
        
        for(int i = 0; i < 2*n+2; i++)
        {
            for(int j = 0; j < 2*n+2; j++)
            {
                if(graph[i][j] != -1) continue;
                graph[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            }
        }
        
        cout << dijksta(graph, n);
        
    }
    return 0;
}

