#include <iostream>
#include <fstream>
using namespace std;

void Permute(string a, int left, int right)
{
    if (left == right)
    {
        cout << a << "\n";
    }
    else
    {
        for (int i = left; i <= right; i++)
        {
            swap(a[left], a[i]);

            Permute(a, left + 1, right);

            swap(a[left], a[i]);
        }
    }
}

int main()
{
    ifstream myFile;
    myFile.open("input.csv");
    while (myFile.good())
    {
        string line;
        getline(myFile, line, ',');
        Permute(line, 0, line.size() - 1);
    }

    return 0;
}