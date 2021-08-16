#include <bits/stdc++.h>
using namespace std;
// #define int long long int
#define endl "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL); //fast I/O
// int mod = 1e9 + 7;
// int inf = 1e18;

int32_t main()
{
    fast
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> check;
        int i = 0;
        while (s[i] != '\0')
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                check.push(s[i]);
            }
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (s[i] == ')' && check.top() == '(')
                {
                    check.pop();
                }
                if (s[i] == '}' && check.top() == '{')
                {
                    check.pop();
                }
                if (s[i] == ']' && check.top() == '[')
                {
                    check.pop();
                }
            }
            i++;
        }
        if (check.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}