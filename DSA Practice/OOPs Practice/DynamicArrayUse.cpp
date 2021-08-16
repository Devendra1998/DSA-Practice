#include <iostream>
using namespace std;
#include "DynamicArray.cpp"

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

    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();

    DynamicArray d2(d1); //Copy constructor

    DynamicArray d3;
    d3 = d1;
    d1.add(0, 100);

    d2.print();
    d3.print();

    return 0;
}