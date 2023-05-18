#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Time-Complexity:O(nlogn)
int minmCabs(vector<int> start,vector <int> end,int n)
{
	int cabs_needed=1;
	int result=1;
	//Two Pointer Approach
	int i=1;//first train will always arrived at platform 1 thats why not taken 0(index)
	int j=0;//departure time will start from start i.e 0th index
	//Step no.1
	//Sort start array
	sort(start.begin(),start.end());
	//Sort end array
	sort(end.begin(),end.end());
	
	while(i<n && j<n)
	{
		if(start[i]<=end[j])
		{
			cabs_needed++;
			i++;
		}
		else if(start[i]>=end[j])
		{
		   cabs_needed--;
		   j++;	
		}
		if(cabs_needed>result)
		{
			//Main Logic We store minimum value of result
			result=cabs_needed;
		}
	}
	return result;
}
int main()
{
	int n;
	cout<<"Enter the  number of persons: "<<endl;
	cin>>n;
	
	vector<int> start(n);
	vector<int> end(n);
	cout<<"Enter the  Start Time of Persons: "<<endl;
	for(int i=0;i<start.size();i++)
	{
		cin>>start[i];
	}
	cout<<"Enter the  End Time of Persons: "<<endl;
	for(int i=0;i<end.size();i++)
	{
		cin>>end[i];
	}
	//Print the Arrays
	cout<<"\nThe Start Time of Persons: "<<endl;
	for(int i=0;i<start.size();i++)
	{
		cout<<start[i]<<" ";
	}
	cout<<"\nThe  End Time of Persons: "<<endl;
	for(int i=0;i<end.size();i++)
	{
		cout<<end[i]<<" ";
	}
	
	int result=minmCabs(start,end,n);
	cout<<"\n Minimum Number of Cabs required are: "<<result<<endl;
	return 0;
}
/*
Output:
Enter the  number of persons:
6
Enter the  Start Time of Persons:
900
945
955
1100
1500
1800
Enter the  End Time of Persons:
920
1200
1130
1150
1900
2000

The Start Time of Persons:
900 945 955 1100 1500 1800
The  End Time of Persons:
920 1200 1130 1150 1900 2000
 Minimum Number of Cabs required are: 3
*/
