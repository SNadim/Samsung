#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n,m;
int mat[11][51];
int vis[11], ans[11], minSum = 99999;
int top = -1, stack[11], answerSize = -1;

void dfs(int current)
{
    if(vis[current] && top != -1)
    {
        int i, sum = stack[top];
        for(i = top-1; i >=0 && stack[i] != current; i--)
        {
            sum+=stack[i];
        }
        
        if(i != -1 && sum < minSum)
        {
            minSum = sum;
            answerSize = -1;
            ans[++answerSize] = stack[top];
            for(i = top-1; i >=0 && stack[i] != current; i--)
            {
                ans[++answerSize] = stack[i];
            }
            
        }
        return;
    }
    else
    {
        vis[current] = 1;
        for(int i = 1; i <=n;i++)
        {
            if(mat[current][i] == 1)
            {
                stack[++top] = i;
                dfs(i);
                top--;
            }
        }
        vis[current] = 0;
    }
}

int main() {
    cin >> n >> m;
    
    memset(mat, 0, sizeof(mat));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        mat[a][b] = 1;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            stack[++top] = i;
            dfs(i);
            top--;
        }
    }
    sort(ans, ans+answerSize+1);
    for(int i = 0; i <= answerSize; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}

