#include <bits/stdc++.h>
using namespace std;

int minStep(int n)
{
    if (n == 1)
    {
        return 0;
    }
    int x = minStep(n - 1);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = minStep(n / 2);
    }
    if (n % 3 == 0)
    {
        z = minStep(n / 3);
    }
    return min(x, min(y, z)) + 1;
}

int minStepBetter(int n, int *ans)
{
    if (n == 1)
    {
        ans[0] = 0;
        return 0;
    }
    if (ans[n - 1] == -1)
    {
        ans[n - 1] = minStepBetter(n - 1, ans);
    }
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        if (ans[n / 2] == -1)
        {
            ans[n / 2] = minStepBetter(n / 2, ans);
        }
        y = ans[n / 2];
    }
    if (n % 3 == 0)
    {
        if (ans[n / 3] == -1)
        {
            ans[n / 3] = minStepBetter(n / 3, ans);
        }
        z = ans[n / 3];
    }
    return min(ans[n - 1], min(y, z)) + 1;
}

int minStepBetter(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return minStepBetter(n, ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << minStepBetter(n);
    return 0;
}