#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;


int knapsackfun(vector<int> wt,vector<int> val,int n,int W)
{
	//Create dp array
	vector<vector<int> > dp(n,vector<int>(W+1,0));
	//Base-Condition
	for(int i=wt[0];i<=W;i++)
	{
		dp[0][i]=val[0];
	}
	
	//Check whether answer is already calculated 
	//If yes then we need to return the value of dp array
	for(int ind=1;ind<n;ind++)
	{
		for(int cap=0;cap<=W;cap++){
			
			int notTaken=0+dp[ind-1][cap];
			int taken=INT_MIN;
			
			if(wt[ind]<=cap)
			{
			    taken=val[ind]+dp[ind-1][cap-wt[ind]];	
			}
			dp[ind][cap]=max(notTaken,taken);
		}
	}
	return dp[n-1][W];
}


int main()
{
	vector<int> wt;
	vector<int> val;
	int W=5;
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
	
	cout<<"The Maximum Value of items,thief can steal is: "<<knapsackfun(wt,val,n,W);
	return 0;
}
