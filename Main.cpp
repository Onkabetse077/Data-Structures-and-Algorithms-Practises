#include <iostream>
#include <vector>
using namespace std;

// O(1) - Constant time
void constantExample(vector<int>& arr) {
    cout << "\nO(1) Example: First element is " << arr[0] << endl;
}

// O(n) - Linear time
void linearExample(vector<int>& arr) {
    cout << "\nO(n) Example: Printing all elements -> ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// O(n^2) - Quadratic time
void quadraticExample(vector<int>& arr) {
    cout << "\nO(n^2) Example: All pairs -> " << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
}

// O(n^3) - Cubic time
void cubicExample(vector<int>& arr) {
    cout << "\nO(n^3) Example: All triplets -> " << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            for (int k = 0; k < arr.size(); k++) {
                cout << "(" << arr[i] << "," << arr[j] << "," << arr[k] << ") ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

// O(log n) - Logarithmic time (Binary Search)
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // found
        }
        else if (arr[mid] < target) {
            left = mid + 1; // search right half
        }
        else {
            right = mid - 1; // search left half
        }
    }
    return -1; // not found
}

int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5 };

    // Demonstrate different complexities
    constantExample(numbers);
    linearExample(numbers);
    quadraticExample(numbers);
    cubicExample(numbers);

    // Binary search demo
    vector<int> sortedNumbers = { 1, 3, 5, 7, 9, 11, 13, 15 };
    int target = 7;
    int index = binarySearch(sortedNumbers, target);

    cout << "\nO(log n) Example: Searching for " << target << endl;
    if (index != -1)
        cout << "Found " << target << " at index " << index << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
