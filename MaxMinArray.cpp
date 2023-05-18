#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
vector<int> minMax(vector<int> &arr, int l, int r)
{
    if (r == l)
    {
        if (arr[l] < arr[r])
            return {arr[l], arr[r]};
        else
            return {arr[r], arr[l]};
    }
    else
    {
        int mid = l + (r - l) / 2, min1, min2, max1, max2, min, max;
        vector<int> minmax1, minmax2;
        minmax1 = minMax(arr, l, mid);
        minmax2 = minMax(arr, mid + 1, r);
        min1 = minmax1[0];
        max1 = minmax1[1];
        min2 = minmax2[0];
        max2 = minmax2[1];
        if (min1 < min2)
            min = min1;
        else
            min = min2;
        if (max1 > max2)
            max = max1;
        else
            max = max2;
        return {min, max};
    }
}
int main()
{
    // vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 7};
    vector<int> arr = {2, 3, 4, 5, 6, 23};
    vector<int> minmax = minMax(arr, 0, arr.size() - 1);
    cout << "Minimum element is: " << minmax[0] << endl;
    cout << "Maximum element is: " << minmax[1] << endl;
    return 0;
}
/*
Output:
Minimum element is: 2
Maximum element is: 23
*/