#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>
using namespace std;
int rand_get(int l, int r)
{
    int val = rand() % (r - l + 1);
    return l + val;
}
int partition(int l, int r, vector<int> &arr)
{
    int rand_ind = rand_get(l, r);
    int pivot_element = arr[rand_ind];
    int pivot_ind = l;
    for (int i = l; i <= r; i++)
    {
        if (arr[i] < pivot_element)
        {
            if (pivot_ind == rand_ind)
            {
                rand_ind = i;
                swap(arr[i], arr[pivot_ind]);
            }
            else
            {
                swap(arr[i], arr[pivot_ind]);
            }
            pivot_ind++;
        }
    }
    swap(arr[rand_ind], arr[pivot_ind]);
    return pivot_ind;
}
void quicksort1(vector<int> &v, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int pivot_index = partition(l, r, v);
    quicksort1(v, l, pivot_index - 1);
    quicksort1(v, pivot_index + 1, r);
}
int findMedian(vector<int> &arr, int start, int end)
{
    if (end - start <= 5)
    {
        sort(arr.begin() + start, arr.begin() + end);
        return arr[(start + end) / 2];
    }
    vector<int> medians;
    for (int i = start; i <= end; i += 5)
    {
        int subEnd = min(i + 4, end);
        sort(arr.begin() + i, arr.begin() + subEnd);
        medians.push_back(arr[(i + subEnd) / 2]);
    }
    int medianofMedians = findMedian(medians, 0, medians.size() - 1);
    return medianofMedians;
}
int partition2(vector<int> &arr, int start, int end, int pivot)
{
    int pivotIdx = start;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == pivot)
        {
            pivotIdx = i;
            break;
        }
    }
    swap(arr[pivotIdx], arr[end]);
    pivotIdx = end;
    int i = start - 1;
    for (int j = start; j < pivotIdx; j++)
    {
        if (arr[j] < arr[pivotIdx])
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pivotIdx]);
    return i + 1;
}
void quicksort2(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int pivot = findMedian(arr, start, end);
        int partitionIdx = partition2(arr, start, end, pivot);
        quicksort2(arr, start, partitionIdx - 1);
        quicksort2(arr, partitionIdx + 1, end);
    }
}
int main()
{
    int n;
    cout << "\nEnter the size of the Array: ";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int val = rand() % (n);
        v[i] = val;
    }
    cout << "\nBefore Sorting: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    auto start1 = std::chrono::steady_clock::now();
    quicksort1(v, 0, v.size() - 1);
    cout << "\nAfter Sorting: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    auto fin1 = std::chrono::steady_clock::now();
    double time1 = std::chrono::duration_cast<std::chrono::duration<double>>(fin1 - start1).count();
    cout << "\nTime Taken for Sorting using Divide & Conquer: " << fixed << time1 << setprecision(10) << endl;
    auto start2 = std::chrono::steady_clock::now();
    quicksort2(v, 0, v.size() - 1);
    cout << endl;
    auto fin2 = std::chrono::steady_clock::now();
    double time2 =
        std::chrono::duration_cast<std::chrono::duration<double>>(fin2 -
                                                                  start2)
            .count();
    cout << "\nTime Taken for Sorting using Median of Median Method: " << fixed << time2 << setprecision(10) << endl;
}
/*
Output:
Enter the size of the Array: 7

Before Sorting:
6 1 6 5 3 2 5

After Sorting:
1 2 3 5 5 6 6

Time Taken for Sorting using Divide & Conquer: 0.001001
*/
