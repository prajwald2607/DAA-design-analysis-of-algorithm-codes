#include <iostream>
#include <algorithm>
using namespace std;
struct Item
{
    int value;
    int weight;
    double ratio;
};
bool cmp(Item a, Item b)
{
    return a.ratio > b.ratio;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    int cur_weight = 0;
    double final_value = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (cur_weight + arr[i].weight <= W)
        {
            cur_weight += arr[i].weight;
            final_value += arr[i].value;
        }
        else
        {
            int remain = W - cur_weight;
            final_value += arr[i].ratio * remain;
            break;
        }
    }
    return final_value;
}
int main()
{
    int W = 50; // maximum weight that the knapsack can hold
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        arr[i].ratio = (double)arr[i].value / (double)arr[i].weight;
    }
    double max_value = fractionalKnapsack(W, arr, n);
    cout << "Maximum value we can obtain = " << max_value << endl;

    return 0;
}
