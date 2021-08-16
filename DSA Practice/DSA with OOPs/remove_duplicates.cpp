#include <bits/stdc++.h>
using namespace std;

vector<int> remove_duplicate(int *a, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(a[i]) > 0)
        {
            continue;
        }
        seen[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}

int main()
{
    int arr[]={1,1,2,3,2,2,3,3,4,2,1,4,6,6,5,3,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    vector<int> output=remove_duplicate(arr,size);
    for (int i = 0; i <output.size(); i++)
    {
        cout<<output[i]<<endl;
    }
    
    return 0;
}