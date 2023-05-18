#include<iostream>
#include<string.h>
#include<climits>
// d is the number of characters in the input alphabet
#define d 256
using namespace std;
void rabinKarp(string text,string pattern,int q)
{
	//Intialise all the Variables
	int N=text.length();
	int M=pattern.length();
	int p=0;//hash value for pattern string
	int t=0;//hash value for text string
	int i,j;
	int h=1;
	// The value of h would be "pow(d, M-1)%q"
	for(int i=0;i<M-1;i++)
	{
		h=(h*d)%q;
	}
	//Calculate Hash Values of Pattern string as well as Text String
	for(int i=0;i<M;i++)
	{
		p=(d*p+pattern[i])%q;
		t=(d*t+text[i])%q;
	}
	// Slide the pattern over text one by one
	for(i=0;i<=N-M;i++)
	{
		// Check the hash values of current window of text and pattern. If the hash values match then only check for characters one by one
		if(p==t)
		{
			//Check for characters one by one 
			for(j=0;j<M;j++)
			{
				if(text[i+j]!=pattern[j])
				{
					break;
			    }
			}	
            // if p == t and pat[0...M-1] = txt[i, i+1,
            // ...i+M-1]
			if(j==M)
			{
				cout<<"The Pattern is found at index "<<i<<"th"<<endl;
			}
		}
		// Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
		if(i<N-M)
		{
			t=(d* (t - text[i] * h) + text[i+M])%q;
			// We might get negative value of t, converting
            // it to positive
			if(t<0)
			{
				t=(t+q);
			}
		}
	}
}
int main()
{
	string text,pattern;
	cout<<"Enter the String of Text is: "<<endl;
	getline(cin,text);
	cout<<"Enter the string of Pattern is: "<<endl;
	getline(cin,pattern);
	// we mod to avoid overflowing of value but we should
    // take as big q as possible to avoid the collison
	int q=INT_MAX;
	rabinKarp(text,pattern,q);
	return 0;
}
/*
Output-1:
Enter the String of Text is:
AABAACAADAABAABA
Enter the string of Pattern is:
AABA
The Pattern is found at index 0th
The Pattern is found at index 9th
The Pattern is found at index 12th
Output-2:
Enter the String of Text is:
2359023141526739921
Enter the string of Pattern is:
31415
The Pattern is found at index 6th

*/

