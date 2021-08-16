#include <bits/stdc++.h>
using namespace std;

// h>0
int balanceBTs(int h)
{
    if (h <= 1)
    {
        return 1;
    }
    int mod = (int)pow(10, 9) + 7;
    int x = balanceBTs(h - 1);
    int y = balanceBTs(h - 2);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);
    int ans = (temp1 + temp2) % mod;

    // int ans = (x%mod * x%mod)%mod + (2 * x%mod * y%mod)%mod;
    return ans % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    cout << balanceBTs(n);
    return 0;
}