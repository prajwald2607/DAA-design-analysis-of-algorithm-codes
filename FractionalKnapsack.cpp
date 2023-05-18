#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
//Time-Complexity:O(NlogN)
struct Item
{
    int value;
    int weight;
};
class Solution
{
public:
    bool static comp(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    // function to return fractionalweights
    double fractionalKnapsack(int W, Item arr[], int n)
    {
    	//O(nlog(n))
        sort(arr, arr + n, comp);

        int curWeight = 0;
        double finalvalue = 0.0;
        //o(n)
        for (int i = 0; i < n; i++)
        {

            if (curWeight + arr[i].weight <= W)
            {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            else
            {
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                break;
            }
        }

        return finalvalue;
    }
};
int main()
{
//    int n = 3, weightoftheknapsack = 50;
//    Item arr[3] = {{100, 20}, {60, 10}, {120, 30}};
//    int n = 5, weightoftheknapsack = 10;
//    Item arr[5] = {{10, 3}, {15, 3}, {10, 2}, {12, 5}, {8, 1}};
    //first is value or profit
    //second is weight
    int n = 3, weightoftheknapsack = 20;
    Item arr[3] = {{25, 18}, {24, 15}, {15, 10}};
    Solution obj;
    double ans = obj.fractionalKnapsack(weightoftheknapsack, arr, n);
    cout << "The Maximum value in the Knapsack is " << setprecision(2) << fixed << ans;
    return 0;
}
/*
Output-1:
The Maximum value in the Knapsack is 240.00
Output-2:
The Maximum value in the Knapsack is 45.40
Output-3:
The Maximum value in the Knapsack is 31.50
*/
