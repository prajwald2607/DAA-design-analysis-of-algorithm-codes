#include <iostream>
#include <vector>
using namespace std;
// Time Complexity:O(V)
// Space Complexity : O(1)
void minmCoinChange(int coin[],int n,int V)
{
	vector<int> answer;
	for(int i=n-1;i>=0;i--)
	{
		while(V>=coin[i])
		{
			V=V-coin[i];
			answer.push_back(coin[i]);
		}
	}
	cout<<"Minimum number of coins are required are: "<<answer.size()<<endl;
	cout<<"Coin required are: "<<endl;
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";
	}
}
int main()
{
	int n;
	cout<<"Enter the number of coins that you want: "<<endl;
	cin>>n;
	int coin[n];
	cout<<"Enter the Coin Values that you want: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	int V;
	cout<<"Enter the Amount: "<<endl;
	cin>>V;
	minmCoinChange(coin,n,V);
}
/*
Output:
Enter the number of coins that you want:
9
Enter the Coin Values that you want:
1
2
5
10
20
50
100
500
1000
Enter the Amount:
49
Minimum number of coins are required are: 5
Coin required are:
20 20 5 2 2
*/
