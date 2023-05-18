// #include <bits/stdc++.h>
#include <iostream>
#include <string.h>
using namespace std;

void preprocess_strong_suffix(int *shift, int *bpos, string pat, int m)
{
    int i = m, j = m + 1;
    bpos[i] = j;

    while (i > 0)
    {
        while (j <= m && pat[i - 1] != pat[j - 1])
        {
            if (shift[j] == 0)
            {
                shift[j] = j - i;
            }

            j = bpos[j];
        }
        i--;
        j--;
        bpos[i] = j;
    }
}

void preprocess_case2(int *shift, int *bpos, string pat, int m)
{
    int i, j;
    j = bpos[0];
    for (i = 0; i <= m; i++)
    {
        if (shift[i] == 0)
        {
            shift[i] = j;
        }

        if (i == j)
        {
            j = bpos[j];
        }
    }
}

void search(string text, string pat)
{
    int s = 0, j;
    int m = pat.length();
    int n = text.length();

    int bpos[m + 1], shift[m + 1];

    for (int i = 0; i < m + 1; i++)
    {
        shift[i] = 0;
    }

    preprocess_strong_suffix(shift, bpos, pat, m);
    preprocess_case2(shift, bpos, pat, m);

    while (s <= n - m)
    {

        j = m - 1;

        while (j >= 0 && pat[j] == text[s + j])
        {
            j--;
        }

        if (j < 0)
        {
            cout << "\nPattern occurs at index: " << s;
            s += shift[0];
        }
        else
        {
            s += shift[j + 1];
        }
    }
}

int main()
{
    string text, pat;
    cout << "\nEnter Text: ";
    cin >> text;

    cout << "\nEnter pattern: ";
    cin >> pat;

    cout << "\nUsing case 1 shifting is performed from index 3 to 10\n";
    search(text, pat);
    return 0;
}
/*
Output:
Enter Text: AABAACAADAABAABA

Enter pattern: AABA

Using case 1 shifting is performed from index 3 to 10

Pattern occurs at index: 0
Pattern occurs at index: 9
Pattern occurs at index: 12
*/