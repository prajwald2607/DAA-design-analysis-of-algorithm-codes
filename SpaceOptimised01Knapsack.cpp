#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int n, int W){

    vector<int> prev(W+1,0);

    //Base Condition

    for(int i=wt[0]; i<=W; i++){
        prev[i] = val[0];
    }

    for(int ind =1; ind<n; ind++){
        for(int cap=W; cap>=0; cap--){

            int notTaken = 0 + prev[cap];

            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + prev[cap - wt[ind]];

            prev[cap] = max(notTaken, taken);
        }
    }

    return prev[W];
}

int main() {

    vector<int> wt;
	vector<int> val;
	int W=8;
	int n=4;
	int x;
	int y;
	cout<<"Enter the Weight Values: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		wt.push_back(x);
	}
	cout<<"Enter the Values in the array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>y;
		val.push_back(y);
	}
	
    cout << "The Maximum value of items, thief can steal is " << knapsack(wt, val, n, W) << endl;
    return 0;
}
/*Output:
Enter the Weight Values:
1
2
3
Enter the Values in the array:
10
15
40
The Maximum value of items, thief can steal is 65
Output-2:
Enter the Weight Values:
2
3
4
5
Enter the Values in the array:
1
2
5
6
The Maximum value of items, thief can steal is 8
*/

