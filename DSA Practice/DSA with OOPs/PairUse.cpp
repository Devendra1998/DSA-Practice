#include <bits/stdc++.h>
using namespace std;
#include "Pair.cpp"

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

    Pair<Pair<int, int>, int> P2;
    P2.sety(10);
    Pair<int, int> P4;
    P4.setx(15);
    P4.sety(20);
    P2.setx(P4);

    cout << P2.getx().getx() << " " << P2.getx().gety() << "    " << P2.gety() << endl;

    /*   Pair<int,double> P1;
    Pair<double,int> P2;

    P1.setx(10);
    P1.sety(20.33);

    cout << P1.getx() << " " << P1.gety() << endl;

    P2.setx(100.34);
    P2.sety(36);

    cout << P2.getx() << " " << P2.gety() << endl;
*/
    return 0;
}