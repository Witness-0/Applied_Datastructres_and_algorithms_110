#include <iostream>
using namespace std;

// Function to count trailing zeros in factorial of n
int T_Zeroes(int n) {
    int result = 0, temp = 1;
    int i = 1;

    // Count the number of times 5^i divides n
    while (temp <= n) {
        temp = 1;
        for (int j = 0; j < i; j++) {
            temp *= 5;
        }
        if (temp > n) break;
        result += n / temp;
        i++;
    }
    return result;
}

// Binary search to find the smallest number whose factorial has n trailing zeros
void binary_search(int n) {
    if (n < 0) {
        cout << "Invalid input: negative number" << endl;
        return;
    }

    if (n == 0) {
        cout << "1" << endl;  // 0! = 1 has 0 trailing zeros
        return;
    }

    int low = 5, high = n * 5, mid;
    int result = -1;

    while (low <= high) {
        mid = (low + high) / 2;
        int zeros = T_Zeroes(mid);

        if (zeros == n) {
            result = mid;
            high = mid - 1; // Search for smaller one
        }
        else if (zeros < n) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (result == -1) {
        cout << "No number with " << n << " trailing zeros exists" << endl;
    }
    else {
        cout << "Smallest number whose factorial has " << n << " trailing zeros: " << result << endl;
    }
}

int main() {
    int num;
    cout << "Enter a number: ";

    if (!(cin >> num)) {
        cout << "Invalid input: Please enter a valid integer" << endl;
        return 1;
    }

    binary_search(num);
    return 0;
}
