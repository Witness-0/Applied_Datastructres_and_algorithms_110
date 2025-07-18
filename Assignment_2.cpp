/*
Problem 2: Move all zeroes to the end of an array.
Statement: Given an array of random numbers, push all zeroes to the end 
           while maintaining the relative order of the non-zero elements.

Approach 1: Apply Merge Sort manually and then push all 0s to the end.
Approach 2: Optimized Two-Pointer in-place method.
*/

#include <iostream>
#include <vector>
using namespace std;

// Merge two sorted halves and collect non-zero elements first
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); ++k)
        arr[left + k] = temp[k];
}

// Recursive merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Apply merge sort and then move zeroes to end (stable order)
void mergeSortZeroPush(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);

    // Create result vector by moving non-zero elements first
    vector<int> result;
    for (int x : arr)
        if (x != 0)
            result.push_back(x);
    for (int x : arr)
        if (x == 0)
            result.push_back(x);

    arr = result;
}

// Optimized in-place two-pointer approach
void moveZerosOptimized(vector<int>& arr) {
    int insert_pos = 0;
    for (int num : arr)
        if (num != 0)
            arr[insert_pos++] = num;
    while (insert_pos < arr.size())
        arr[insert_pos++] = 0;
}

void printArray(const vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<int> arr1 = arr, arr2 = arr;

    mergeSortZeroPush(arr1);
    moveZerosOptimized(arr2);

    cout << "MergeSort + Zero Push Output: "; printArray(arr1);
    cout << "Optimized Two-Pointer Output: "; printArray(arr2);

    return 0;
}
