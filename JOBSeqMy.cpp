#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};
class Solution
{
public:
    bool static comparator(Job a, Job b)
    {
        if (a.profit > b.profit)
        {
            return true;
        }
        return false;
    }
    pair<int, int> JobSequencing(Job arr[], int n)
    {
        sort(arr, arr + n, comparator);
        int maxi = arr[0].dead;

        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, arr[i].dead);
        }

        int slot[maxi];

        for (int i = 0; i < maxi; i++)
        {
            slot[i] = -1;
        }
        int countJobs = 0;
        int totalProfit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = i;
                    countJobs++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        return make_pair(countJobs, totalProfit);
    }
};
int main()
{
    int n = 4;
    Job arr[n] = {{1, 2, 60},
                  {2, 1, 80},
                  {3, 1, 50},
                  {4, 2, 100}};

    Solution obj;
    pair<int, int> ans = obj.JobSequencing(arr, n);

    cout << "\nThe No.of jobs done are: " << ans.first << "\nTotal profit is:  " << ans.second << endl;

    return 0;
}
