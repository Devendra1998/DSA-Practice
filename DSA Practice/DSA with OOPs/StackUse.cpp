#include <bits/stdc++.h>
using namespace std;
#include "stack.cpp"

#define int long long int
#define endl "\n"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL); //fast I/O
int mod = 1e9 + 7;
int inf = 1e18;

int32_t main()
{
    fast
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    StackUsingArray<char> s;
    s.Push(100);
    s.Push(101);
    s.Push(102);
    s.Push(103);
    s.Push(104);

    cout << s.top() << endl;

    cout << s.Pop() << endl;
    cout << s.Pop() << endl;
    cout << s.Pop() << endl;

    cout << s.size() << endl;

    cout << s.isEmpty() << endl;

    return 0;
}
