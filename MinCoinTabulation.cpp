#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;


int minCoin(vector<int> &arr,int T)
{
	int n=arr.size();
	//Create a 2D Array of named DP with initialize -1;
	vector<vector<int> > dp(n,vector<int>(T+1,0));
	
	//Base-Case
	for(int i=0;i<=T;i++)
	{
		if(i%arr[0]==0)
		{
			dp[0][i]=i/arr[0];
		}
		else
		{
			dp[0][i]=1e9;
		}
	}
	for(int ind=1;ind<n;ind++)
	{
		for(int target=0;target<=T;target++)
		{
			int notTaken=0+dp[ind-1][target];
		    int taken=1e9;	
		    if(arr[ind]<=target)
		    {
			    taken=1+dp[ind][target-arr[ind]];
		    }
		    dp[ind][target]=min(notTaken,taken);
	    }
	}
	int ans=dp[n-1][T];
	if(ans>=1e9)
	{
		return -1;
	}
	else
	{
		return ans;
	}
}
int main()
{
	vector<int> arr;
	int n=3;
	int x;
	cout<<"\nEnter the Coin Values in the array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		arr.push_back(x);
	}
	int T=7;
	cout<<"Target is: "<<T<<endl;
	cout<<"||The minimum number of coins required to form the target sum is: " <<minCoin(arr,T)<<" ||";
}
/*
Output-1:
Enter the Coin Values in the array:
1
2
3
Target is: 7
||The minimum number of coins required to form the target sum is: 3 ||
*/
