#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

int maxcrossingsum(int arr[], int low, int mid, int high)
{
    int sum = 0;

    int left_sum = INT_MIN;
    for (int i = mid; i >= low; i--)
    {
        sum = sum + arr[i];

        if (sum > left_sum)
        {
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= high; i++) // fixed for loop bounds
    {
        sum = sum + arr[i];

        if (sum > right_sum)
        {
            right_sum = sum;
        }
    }

    return max(left_sum + right_sum, max(left_sum, right_sum)); // fixed max function arguments
}

int maxsubarraysum(int arr[], int low, int high)
{
    if (low == high)
        return arr[high];
    int mid = low + (high - low) / 2; // fixed mid calculation

    return max(maxsubarraysum(arr, low, mid),
               max(maxsubarraysum(arr, mid + 1, high), // fixed max function arguments
                   maxcrossingsum(arr, low, mid, high)));
}

int main()
{

    int arr[5] = {2, 3, 4, 5, 6};
    //    int arr[9]={-2, 1, -3, 4, -1, 2, 1, -5, 4};
    //    int arr[9]={-5, -3, -2, -1, 1,1,2,4,4};

    int max_sum = maxsubarraysum(arr, 0, 4);
    cout << "Max Sum: " << max_sum;
    return 0;
}
/*
Output:
Max Sum: 20
*/
