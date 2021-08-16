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

    std::stack<int> st;
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int q;
        scanf("%d", &q);

        switch (q)
        {
        case 1:
            scanf("%d", &x);

            if (st.empty())
            {
                st.push(x);
            }
            else
            {
                st.push(max(x, st.top()));
            }
            break;

        case 2:
            if (!st.empty())
            {
                st.pop();
            }
            break;

        case 3:
            printf("%d\n", st.top());
            break;

        default:
            break;
        }
    }

    return 0;
}