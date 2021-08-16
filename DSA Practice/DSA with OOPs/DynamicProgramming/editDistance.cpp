#include <bits/stdc++.h>
using namespace std;

int editDistance_DP(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        ans[i] = new int[n + 1];
    }

    for (int j = 0; j <= n; j++)
    {
        ans[0][j] = j;
    }

    for (int i = 0; i <= m; i++)
    {
        ans[m][0] = i;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                ans[i][j] = ans[i - 1][j - 1];
            }
            else
            {
                ans[i][j] = min(ans[i - 1][j], min(ans[i][j - 1], ans[i - 1][j - 1])) + 1;
            }
        }
    }
    return ans[m][n];
}

int editDistance_Better(string s, string t, int **ans)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());
    }

    int m = s.size();
    int n = t.size();
    if (ans[m][n] != -1)
    {
        return ans[m][n];
    }

    if (s[0] == t[0])
    {
        ans[m][n] = editDistance_Better(s.substr(1), t.substr(1), ans);
    }
    else
    {
        ans[m - 1][n] = editDistance_Better(s.substr(1), t, ans);
        ans[m][n - 1] = editDistance_Better(s, t.substr(1), ans);
        ans[m - 1][n - 1] = editDistance_Better(s.substr(1), t.substr(1), ans);

        ans[m][n] = 1 + min(ans[m - 1][n], min(ans[m][n - 1], ans[m - 1][n - 1]));
    }
    return ans[m][n];
}

int editDistance_Better(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **ans = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        ans[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            ans[i][j] = -1;
        }
    }
    return editDistance_Better(s, t, ans);
}

int editDistance(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return max(s.size(), t.size());
    }
    int ans = 0;
    if (s[0] == t[0])
    {
        return editDistance(s.substr(1), t.substr(1));
    }
    else
    {
        // Insert
        int x = editDistance(s.substr(1), t) + 1;
        // Delete
        int y = editDistance(s, t.substr(1)) + 1;
        // Update
        int z = editDistance(s.substr(1), t.substr(1)) + 1;

        ans = min(x, min(y, z));
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s, t;
    cin >> s >> t;
    cout << editDistance_DP(s, t) << endl;
    cout << editDistance_Better(s, t) << endl;
    cout << editDistance(s, t) << endl;
    return 0;
}