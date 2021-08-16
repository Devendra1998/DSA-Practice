#include <bits/stdc++.h>
using namespace std;

int knapsack(int *weight, int *values, int n, int maxWeight)
{
    if (n == 0 || maxWeight == 0)
    {
        return 0;
    }

    if (weight[0] > maxWeight)
    {
        return knapsack(weight + 1, values + 1, n - 1, maxWeight);
    }

    // reccursion
    int x = knapsack(weight + 1, values + 1, n - 1, maxWeight - weight[0]) + values[0];
    int y = knapsack(weight + 1, values + 1, n - 1, maxWeight);

    return max(x, y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int weight[] = {5, 1, 8, 9, 2};
    int values[] = {4, 10, 2, 3, 1};
    int maxWeight = 15;
    cout << knapsack(weight, values, 5, maxWeight) << endl;
    return 0;
}