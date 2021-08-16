#include <iostream>
using namespace std;
#include "Fraction.cpp"

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

    Fraction f1(10, 3);
    Fraction f2(5, 2);

   (f1+=f2)+=f2;
   f1.print();
   f2.print();

/*
    Fraction f3=f1++;
    f1.print();
    f3.print();


    f1.print();
    Fraction f3=++(++(++f1));
    f1.print();
    f3.print();


    f1.print();
    Fraction f3 = ++f1;
    f1.print();
    f3.print();

    
    Fraction f3 = f1 + f2;
    f1.print();
    f2.print();
    f3.print();

    Fraction f4=f1 * f2;
    f4.print();*/

    return 0;
}
