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

    // vector<int> *vp=new vector<int>();
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;


    return 0;
}