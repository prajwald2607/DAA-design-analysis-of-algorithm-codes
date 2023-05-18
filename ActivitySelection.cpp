#include <bits/stdc++.h>
using namespace std;

struct meeting
{
    int start;
    int end;
    int pos;
};

class Solution
{
public:
    bool static comparator(struct meeting m1, struct meeting m2)
    {
        if (m1.end < m2.end)
            return true;
        //Overlapping condition
        else if (m1.end > m2.end)
            return false;
        // if both meetings have same end time then depends on position
        else if (m1.pos < m2.pos)
            return true;
        return false;
    }
    void maxMeetings(int s[], int e[], int n)
    {
        struct meeting meet[n];
        // Time -Complexity is O(n)
        for (int i = 0; i < n; i++)
        {
            meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i+1;
        }
        // Time-Complexity is O(nlog(n))
        sort(meet, meet + n, comparator);

        vector<int> answer;
        int count = 0;
        int limit = meet[0].end;
        answer.push_back(meet[0].pos);
        count = 1;
        // Time-Complexity is O(n)
        for (int i = 1; i < n; i++)
        {
            if (meet[i].start > limit)
            {
                count++;
                limit = meet[i].end;
                answer.push_back(meet[i].pos);
            }
        }
        // Time -Complexity is O(n)
        cout << "The order in which the meetings will be performed is " << endl;
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\nThe Total Number of Meeting are: " << count << endl;
    }
    // Total Time-Complexity:O(n) +O(n log n) + O(n) ~O(n log n)
    // Space Complexity : O(n)
};
int main()
{
    Solution obj;
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};
//    int n = 10;
//    int start[] = {1,2,3,4,7,8,9,9,11,12};
//    int end[] = {3,5,4,7,10,9,11,13,12,14};
    obj.maxMeetings(start, end, n);
    return 0;
}
/*
Output-1:
The order in which the meetings will be performed is
1 2 4 5
The Total Number of Meeting are: 4
*/
