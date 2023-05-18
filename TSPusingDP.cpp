#include<iostream>
#include<climits>
using namespace std;
int adjnancy_matrix[10][10];
int cost=0;
int visited[10];

int least(int c,int n)
{
	int nc=INT_MAX;
	int kmin,min=INT_MAX;
	
	for(int i=0;i<n;i++)
	{
		if((adjnancy_matrix[c][i]!=0) && (visited[i]==0))
		{
			if(adjnancy_matrix[c][i] + adjnancy_matrix[i][c] <min)
			{
				min=adjnancy_matrix[i][0]+adjnancy_matrix[c][i];
				kmin=adjnancy_matrix[c][i];
				nc=i;
			}
		}
	}
	if(min!=INT_MAX)
	{
		cost+=kmin;
	}
	return nc;
}

void minCost(int city,int n)
{
	int ncity,i;
	visited[city]=1;
	cout<<city+1<<"----->";
	ncity=least(city,n);
	//Base-case
	if(ncity==INT_MAX)
	{
		ncity=0;
		cout<<ncity+1;
		cost+=adjnancy_matrix[city][ncity];
		return;
	}
	//Baki Sab Recusion Sambhal Leega
	minCost(ncity,n);
}
int main()
{
	int n;
	cout<<"\nEnter the Number of Cities: "<<endl;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter the distances from the city"<<i+1<<endl;
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				adjnancy_matrix[i][j]=0;
			}
			else
			{
				cout<<"\tTo the city- "<<j+1<<":- ";
				cin>>adjnancy_matrix[i][j];
			}
		}
	}
	cout<<"\n\nThe Cost-Matrix is:\n\t";
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<i+1;
	}
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		cout<<"\t"<<i+1<<"  |";
		for(int j=0;j<n;j++)
		{
			cout<<"\t"<<adjnancy_matrix[i][j];
		}
		cout<<"\t|";
	}
	cout << "\n\nSolution:- ";
    cout << "\n\tPath for Salesman:- \n\t";
	minCost(0,n);
	cout<<"\n\b\tThe Minimum number of Cost is:- "<<cost<<endl;
	return 0;
	
}
/*
Output:

Enter the Number of Cities:
4

Enter the distances from the city1
        To the city- 2:- 16
        To the city- 3:- 11
        To the city- 4:- 6

Enter the distances from the city2
        To the city- 1:- 8
        To the city- 3:- 13
        To the city- 4:- 16

Enter the distances from the city3
        To the city- 1:- 4
        To the city- 2:- 7
        To the city- 4:- 9

Enter the distances from the city4
        To the city- 1:- 5
        To the city- 2:- 12
        To the city- 3:- 2


The Cost-Matrix is:
                1       2       3       4
        1  |    0       16      11      6       |
        2  |    8       0       13      16      |
        3  |    4       7       0       9       |
        4  |    5       12      2       0       |

Solution:-
        Path for Salesman:-
        1----->4----->3----->2----->1
        The Minimum number of Cost is:- 23

*/
