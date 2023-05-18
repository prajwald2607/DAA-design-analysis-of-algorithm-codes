#include <iostream>
#include <vector>
using namespace std;

bool is_safe (vector < int >&queens, int row, int col)
{
  for (int i = 0; i < row; i++)
    {
      if (queens[i] == col || queens[i] - col == i
	  - row || queens[i] - col == row - i)
	{
	  return false;
	}
    }
  return true;
}

void solve (int N, vector < int >&queens, int row, int &count)
{
  if (row == N)
    {
      count++;
      cout << "Solution " << count << ":" << endl;
      cout << endl;
      for (int i = 0; i < N; i++)
	{
	  for (int j = 0; j < N; j++)
	    {
	      cout << (queens[i] == j ? "Q " : "* ");
	    }
	  cout << endl;
	}
      cout << endl;
    }
  else
    {
        for (int col = 0; col < N; col++)
        {
            if (is_safe (queens, row, col))
	        {
	            queens[row] = col;
	            solve (N, queens, row + 1, count);
	        }
	    }
    }
}

int main ()
{
  int n;
  cout << "Enter the size of chessboard (N * N) : ";
  cin >> n;
  vector < int >queens (n, 0);
  int count = 0;
  solve (n, queens, 0, count);
  cout << "Total solutions: " << count << endl;
  return 0;
}
//O(N!)
