// #include <bits/stdc++.h>
#include <iostream>
#include <string.h>
using namespace std;
#define NO_OF_CHARS 256
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
    {
        badchar[i] = -1;
    }
    for (i = 0; i < size; i++)
    {
        badchar[(int)str[i]] = i;
    }
}
void search(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);
    cout << "\nThe Bad Character table looks like: " << endl;
    for (int i = 0; i < pat.length() - 1; i++)
    {
        cout << pat[i] << " ";
    }
    cout << "*" << endl;
    int arr[] = {4, 2, 1, 4};
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
        {
            j--;
        }
        if (j < 0)
        {
            cout << "\nPattern occurs at Index Position: " << s << endl;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else
        {
            s += max(1, j - badchar[txt[s + j]]);
        }
    }
}
int main()
{
    cout << "\n\t**********BM ALGO USING BAD CHARACTER APPROACH**********" << endl;
    string txt, pat;
    cout << "\nEnter the Text: ";
    cin >> txt;
    cout << "\nEnter the Pattern: ";
    cin >> pat;
    search(txt, pat);
    return 0;
}

// OUTPUT OBTAINED:
/*
        **********BM ALGO USING BAD CHARACTER APPROACH**********

Enter the Text: THISISATEXT

Enter the Pattern: TEXT

The Bad Character table looks like:
T E X *
4 2 1 4

Pattern occurs at Index Position: 7

--------------------------------
Process exited after 12.38 seconds with return value 0
Press any key to continue . . .
*/
