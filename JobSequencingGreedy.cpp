#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;
// A structure to represent a job

//Time Complexity: O(N2)
//Auxiliary Space: O(N)
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
class Solution
{
public:
    bool static comparison(Job a, Job b)
    {
        return (a.profit > b.profit);
    }
    // Function to find the maximum profit and the number of jobs done
    pair<int, int> JobScheduling(Job arr[], int n)
    {
    	//Step no.1: Sorting according to profit
        sort(arr, arr + n, comparison);
        //Step no.2: To find out maximum  deadline
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, arr[i].dead);
        }
        //Gantt Chart Sequence of Jobs
        int slot[maxi];
        vector<int> ans;
        //intialise with -1
        for (int i = 0; i <= maxi; i++)
            slot[i] = -1;

        int countJobs = 0, jobProfit = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    ans.push_back(arr[i].id);
                    break;
                }
            }
        }
        cout << "The Sequence of Jobs are: " << endl;
        for (int i=0;i<ans.size(); i++)
        {
            cout << "| " << ans[i] << " ";
        }
        cout << "|";
        return make_pair(countJobs, jobProfit);
    }
};
int main()
{
    int n;
    cout << "Enter the number of Jobs: ";
    cin >> n;
    Job arr[n];
    // Job arr[5] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};
    // create a object of class solution
    cout << "Enter the ID,Deadline and Profit of Job:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id;
        cin >> arr[i].dead;
        cin >> arr[i].profit;
    }
    Solution ob;
    // function call
    pair<int, int> ans = ob.JobScheduling(arr, n);
    cout << "\nThe No.of jobs done are: " << ans.first << "\nTotal profit is:  " << ans.second << endl;

    return 0;
}
/*
Output-1:
The No.of jobs done are: 3
Total profit is:  90
Output-2:
Enter the number of Jobs: 4
Enter the ID,Deadline and Profit of Job:
1 4 20
2 1 10
3 1 40
4 1 30
The Sequence of Jobs are:
| 3 | 1 |
The No.of jobs done are: 2
Total profit is:  60
Output-3:
Enter the number of Jobs: 4
Enter the ID,Deadline and Profit of Job:
1 2 60
2 1 80
3 1 50
4 2 100
The Sequence of Jobs are:
| 4 | 2 |
The No.of jobs done are: 2
Total profit is:  180

*/
