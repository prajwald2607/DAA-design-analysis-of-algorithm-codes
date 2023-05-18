#include <iostream>
#include <vector>
using namespace std;

// Return a pair containing the minimum and maximum elements of the subarray arr[low..high]
pair<int, int> MinMaxArray(int arr[], int low, int high)
{
    // If the subarray contains only one element
    if (high - low == 0)
    {
        // Return that element as both min and max
        return make_pair(arr[low], arr[high]);
    }
    // If the subarray contains two elements
    else if (high - low == 1)
    {
        // Return the smaller element as min and the larger element as max
        if (arr[low] < arr[high])
        {
            return make_pair(arr[low], arr[high]);
        }
        else
        {
            return make_pair(arr[high], arr[low]);
        }
    }
    else
    {
        int mid = low + (high - low) / 2;
        int min, max;

        // Recursively find the min and max of the left subarray
        pair<int, int> minmax1 = MinMaxArray(arr, low, mid);
        int min1 = minmax1.first;
        int max1 = minmax1.second;

        // Recursively find the min and max of the right subarray
        pair<int, int> minmax2 = MinMaxArray(arr, mid + 1, high);
        int min2 = minmax2.first;
        int max2 = minmax2.second;

        // Find the overall min and max of the subarray
        if (min1 < min2)
        {
            min = min1;
        }
        else
        {
            min = min2;
        }
        if (max1 > max2)
        {
            max = max1;
        }
        else
        {
            max = max2;
        }
        return make_pair(min, max);
    }
}

int main()
{
    int arr[] = {2, 37, 89, 12, 45};
    int low = 0;
    int high = sizeof(arr) / sizeof(arr[0]) - 1;
    pair<int, int> ans = MinMaxArray(arr, low, high);
    cout << "\nThe Minimum Element in the Array is: " << ans.first << "\nThe Maximum Element in the Array is: " << ans.second << endl;
}
/*
Output:
The Minimum Element in the Array is: 2
The Maximum Element in the Array is: 89
*/

