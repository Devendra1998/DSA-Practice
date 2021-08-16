#include <bits/stdc++.h>
using namespace std;
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

    int m;
    cin >> m;
    int *arr = new int[m];
    string *arr1 = new string[m];

    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }

    unordered_map<string, int> name;
    vector<string> ans1;
    for (int i = 0; i < m; i++)
    {
        if (name.find(arr1[i]) == name.end())
        {
            ans1.push_back(arr1[i]);
            name[arr1[i]];
        }
    }

    for (int i = 0; i < ans1.size(); i++)
    {
        cout << ans1[i] << " ";
    }

    /*  for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int min = INT32_MAX;
    int max = INT32_MIN;
    int min_index = 0;
    int max_index = 0;
    for (int i = 0; i < m; i++)
    {
        if (min >= arr[i])
        {
            min = arr[i];
            min_index = i;
        }
        if (max < arr[i])
        {
            max = arr[i];
            max_index = i;
        }
    }
    int ans = 0;
    if (min_index >= max_index)
    {
        ans = abs(m - min_index - 1) + abs(0 - max_index);
    }
    else
    {
        ans = max_index + abs(m - min_index - 1) - 1;
    }
    cout << ans;
*/
    return 0;
}
