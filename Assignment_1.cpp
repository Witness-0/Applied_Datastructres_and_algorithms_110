/*
Problem 1: Count number of zeroes in an array.
Statement: Given an array of 1s and 0s where all 1s come first and then all 0s,
           count the number of 0s in the array.

Approach 1: Binary Search – Find the first occurrence of 0.
Approach 2: Linear Scan – Scan from start and stop at first 0.
*/

#include <iostream>
#include <vector>
using namespace std;

// Binary Search approach
int countZerosBinarySearch(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int firstZero = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == 0) {
            firstZero = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (firstZero == -1) ? 0 : arr.size() - firstZero;
}

// Linear approach
int countZerosOptimized(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i] == 0)
            return arr.size() - i;
    return 0;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements (1s followed by 0s): ";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    cout << "Binary Search Count: " << countZerosBinarySearch(arr) << endl;
    cout << "Optimized Count: " << countZerosOptimized(arr) << endl;

    return 0;
}
