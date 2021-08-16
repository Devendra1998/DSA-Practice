#include <bits/stdc++.h>
using namespace std;

int fibbo_DP(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}

int fibbo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a = fibbo(n - 1);
    int b = fibbo(n - 2);

    return a + b;
}

int fibbo_better(int n, int *ans)
{
    if (n <= 1)
    {
        ans[n] = n;
        return n;
    }
    if (ans[n - 1] == 0)
    {
        ans[n - 1] = fibbo_better(n - 1, ans);
    }
    if (ans[n - 2] == 0)
    {
        ans[n - 2] = fibbo_better(n - 2, ans);
    }
    ans[n] = ans[n - 1] + ans[n - 2];
    return ans[n];
}

int fibbo_better(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        ans[i] = 0;
    }
    return fibbo_better(n, ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << fibbo_DP(n);
}