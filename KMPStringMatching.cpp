#include<iostream>
#include<string.h>
#include<vector>
#include<chrono>
using namespace std;
//Time Complexity is: O(m+n)
//m-->Pie Table
//n--> searching time
void computeLPS(string pattern,vector<int> &lps)
{
	int m=pattern.length();
	// length of the previous longest prefix suffix
	int len=0;
	// lps[0] is always 0
	lps[0]=0;
	// the loop calculates lps[i] for i = 1 to M-1
	int i=1;
	while(i<m)
	{
		if(pattern[i]==pattern[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			// (pattern[i] != pattern[len])
			// This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
			if(len!=0)
			{
				len=lps[len-1];
				// Also, note that we do not increment
                // i here
			}
			else
			{
				//len==0
				lps[i]=0;
				i++;
			}
		}
	}
}
void KMPsearch(string text,string pattern)
{
	int n=text.length();
	int m=pattern.length();
	//Create LPS table of pattern length size
	//Intiallized with all 0
	vector<int> lps(m,0);
	computeLPS(pattern,lps);
	int i=0,j=0;
	while(i<n)
	{
		if(text[i]==pattern[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<"\nThe Pattern "<<pattern<<" is Found at index "<<i-j<<"th"<<endl;
			j=lps[j-1];
		}
		//mismatch after j matches
		else if(i<n && text[i]!=pattern[j])
		{
			// Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	cout<<endl;
	cout<<"The LPS(Longest Prefix Table) Table or Pie Table is looks like: "<<endl;
	for(int k=0;k<lps.size();k++)
	{
		cout<<lps[k]<<" ";
	}
}
int main()
{
	string text,pattern;
	cout<<"||*****KMP Algorithm ******||"<<endl;
	cout<<"Enter the Text String: "<<endl;
	cin>>text;
	cout<<"Enter the Pattern String: "<<endl;
	cin>>pattern;
	auto start=std::chrono::steady_clock::now();
	KMPsearch(text,pattern);
	auto finish=std::chrono::steady_clock::now();
	
	float time=std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
	cout<<time<<endl;
	return 0;
}
/*
Output:
||*****KMP Algorithm ******||
Enter the Text String:
ababcabcabababd
Enter the Pattern String:
ababd

The Pattern ababd is Found at index 10th

The LPS(Longest Prefix Table) Table or Pie Table is looks like:
0 0 1 2 0
*/
