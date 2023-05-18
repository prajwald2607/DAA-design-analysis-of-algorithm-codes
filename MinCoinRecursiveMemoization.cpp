#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
//Time Complexity: O(N*T)
int minCoin(vector<int> &arr,int ind,int T,vector<vector<int> > &dp)
{//Base-Case
	if(ind==0)
	{
		if(T%arr[0]==0)
		{
			return T/arr[0];
		}
		else{
			return 1e9;
		}
	}
	//Check Whether the given answer is already calculated or not
	//If yes then we need to return dp array
	if(dp[ind][T]!=-1)
	{
		return dp[ind][T];
	}
	int notTaken=0+minCoin(arr,ind-1,T,dp);
	int taken=1e9;
	
	if(arr[ind]<=T)
	{
		taken=1+minCoin(arr,ind,T-arr[ind],dp);
	}
	dp[ind][T]=min(notTaken,taken);
	return dp[ind][T];
}
int minElements(vector<int> &arr,int T)
{
	int n=arr.size();
	//Create a 2D Array of named DP with initialize -1;
	vector<vector<int> > dp(n,vector<int>(T+1,-1));
	int ans=minCoin(arr,n-1,T,dp);
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
	int n;
	cout<<"Enter the number of coins: "<<endl;
	cin>>n;
	vector<int> arr(n);
	cout<<"\nEnter the Coin Values in the array: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int T=49;
	cout<<"Target is: "<<T<<endl;
	cout<<"||The minimum number of coins required to form the target sum is: " <<minElements(arr,T)<<" ||";
}
/*
Ouput-1:
Enter the Coin Values in the array:
1
2
3
Target is: 7
||The minimum number of coins required to form the target sum is: 3 ||
Output-2:
Enter the number of coins:
9

Enter the Coin Values in the array:
1
2
5
10
20
50
100
500
1000
Target is: 49
||The minimum number of coins required to form the target sum is: 5 ||76
';l kj21v	c`f	125
*/
