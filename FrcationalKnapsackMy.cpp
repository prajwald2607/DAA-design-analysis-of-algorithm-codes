#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item
{
    double value;
    double weight;
};
class Solution
{
public:
    bool static comparator(Item a, Item b)
    {
        double r1 = double(a.value) / double(a.weight);
        double r2 = double(b.value) / double(b.weight);
        if (r1 > r2)
        {
            return true;
        }
        return false;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comparator);
        int currWeight = 0;
        double finalAns = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (currWeight + arr[i].weight <= W)
            {
                currWeight = currWeight + arr[i].weight;
                finalAns = finalAns + arr[i].value;
            }
            else
            {
                int remainWeight = W - currWeight;
                finalAns += (arr[i].value / double(arr[i].weight)) * double(remainWeight);
                break;
            }
        }
        return finalAns;
    }
};
int main()
{
    int n = 5;
    int W = 10;
    Item arr[5] = {{10, 3}, {15, 3}, {10, 2}, {12, 5}, {8, 1}};
    Solution obj;
    double ans = obj.fractionalKnapsack(W, arr, n);
    cout << "The Maximum Profit achieved from the given Knapsack: " << setprecision(2) << fixed << ans << endl;
    return 0;
}