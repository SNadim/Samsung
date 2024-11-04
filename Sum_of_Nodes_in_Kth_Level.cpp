#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int k;
    cin >> k >> s;
    int level = -1;
    int sum = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            level++;
        }
        else if(s[i] == ')')
        {
            level--;
        }
        else
        {
            if(level == k)
            {
                string num = "";
                while(s[i] != '(' && s[i] != ')')
                {
                    num+= s[i];
                    i++;
                }
                i--;
                sum += stoi(num);
            }
        }
    }
    cout << sum << '\n';
    return 0;
}
