#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f(int i, int j, vector<vector<int>> arr, bool bomb)
{
    if(j < 0 || j == 5 || i < 0 || (arr[i][j] == 2 && bomb)) return 0;
    if(arr[i][j] == 2)
    {
        for(int x = i; x >=0 && x > i - 5; x--)
        {
            for(int y = 0; y < 5; y++)
            {
                if(arr[x][y] == 2) arr[x][y] = 0;
            }
        }
        bomb = true;
    }
    
    int coin = arr[i][j];
    int totCoin = 0;
    totCoin = max(f(i-1, j, arr, bomb)+coin, f(i-1, j+1, arr, bomb)+coin);
    
    totCoin = max(totCoin, f(i-1, j-1, arr, bomb)+coin);
    
    return totCoin;
}

int main() {
    int t, n, x = 1;        
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(5));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                cin >> arr[i][j];
            }
        }
        int totCoins = f(n-1, 2, arr, false);
        totCoins = max(totCoins, f(n-1, 1, arr, false));
        totCoins = max(totCoins, f(n-1, 3, arr, false));
        cout << "#" << x << " " << totCoins << '\n';
        x++;
    }
    
    return 0;
}
