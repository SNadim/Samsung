#include<bits/stdc++.h>
using namespace std;

int maxCount = 0;

bool allOne(int row, vector<vector<int>> &board)
{
    int one = 0;
    for(int col = 0; col < board[row].size(); col++)
    {
        if(board[row][col] == 0) return false; 
    }
    return true;
}

void toggle(int col, vector<vector<int>> &board)
{
    for(int i = 0; i < board.size(); i++)
    {
        board[i][col] = board[i][col] == 1 ? 0 : 1;
    }
}

int numberOfRow(vector<vector<int>> &board)
{
    int count = 0;
    for(int i = 0; i < board.size(); i++)
    {
        count += allOne(i, board);
    }
    
    return count;
}

void comb(int n, int x, int k, vector<vector<int>> &board)
{
    if(x == k)
    {
        int count = numberOfRow(board);
        maxCount = max(count, maxCount);
        return;
    }
    if( n < board[0].size())
    {
        x++;
        toggle(n, board);
        comb(n, x, k, board);
        x--;
        toggle(n, board);
        comb(n+1, x, k, board);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> board(n, vector<int>(m));
    
    for(int i = 0; i < n; i++)
    {
       for(int j = 0; j < m; j++)
       {
           cin >> board[i][j];
       }
    }
    comb(0, 0, k, board);
    cout << maxCount << '\n';
    return 0;
}

