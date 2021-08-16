#include <iostream>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

class Time
{

public:
    int hours;
    int minutes;
    int day;
    int month;
    int year;

    int set(int a, int b, int c, int d, int e)
    {
        if (a >= 0 && a <= 24)
        {
            this->hours = a;
        }
        else
        {
            return -1;
        }
        if (b >= 0 && b <= 60)
        {
            this->minutes = b;
        }
        else
        {
            return -1;
        }

        if (c >= 0 && c <= 31)
        {
            this->day = c;
        }
        else
        {
            return -1;
        }

        if (d >= 0 && d <= 12)
        {
            this->month = d;
        }
        else
        {
            return -1;
        }

        if (e >= 0 && e <= 9999)
        {
            this->year = e;
        }
        else
        {
            return -1;
        }
    }

    void get()
    {
        cout << "Date:" << this->day << " day - " << this->month << " month - " << this->year << " Year" << endl;
        cout << "Time:" << this->hours << " hours " << this->minutes << " mins " << endl;
        cout << "Total mins:" << this->hours * 60 + this->minutes;
    }
};

int main()
{
    fast
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Time t;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int check = t.set(a, b, c, d, e);

    if (check == -1)
    {
        cout << "Invalid";
    }
    else
    {
        t.get();
    }

    return 0;
}