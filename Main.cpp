#include <iostream>
#include <vector>
using namespace std;

// ------------------ O(1) ------------------
void constantExample(vector<int>& arr) {
    cout << "\nO(1) Example: First element is " << arr[0] << endl;
}

// ------------------ O(n) ------------------
void linearExample(vector<int>& arr) {
    cout << "\nO(n) Example: Printing all elements -> ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ------------------ O(n^2) ------------------
void quadraticExample(vector<int>& arr) {
    cout << "\nO(n^2) Example: All pairs -> " << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
}

// ------------------ O(n^3) ------------------
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

// ------------------ O(log n) Iterative ------------------
int binarySearchIterative(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // found
        else if (arr[mid] < target)
            left = mid + 1; // search right half
        else
            right = mid - 1; // search left half
    }
    return -1; // not found
}

// ------------------ O(log n) Recursive ------------------
int binarySearchRecursive(vector<int>& arr, int left, int right, int target) {
    if (left > right) return -1; // base case: not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid; // found
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target); // right half
    else
        return binarySearchRecursive(arr, left, mid - 1, target); // left half
}

// ------------------ MAIN ------------------
int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5 };

    // O(1), O(n), O(n^2), O(n^3)
    constantExample(numbers);
    linearExample(numbers);
    quadraticExample(numbers);
    cubicExample(numbers);

    // O(log n) Iterative & Recursive
    vector<int> sortedNumbers = { 1, 3, 5, 7, 9, 11, 13, 15 };
    int target = 7;

    int indexIter = binarySearchIterative(sortedNumbers, target);
    cout << "\nO(log n) Iterative: Searching for " << target << endl;
    if (indexIter != -1)
        cout << "Found at index " << indexIter << endl;
    else
        cout << "Not found" << endl;

    int indexRec = binarySearchRecursive(sortedNumbers, 0, sortedNumbers.size() - 1, target);
    cout << "\nO(log n) Recursive: Searching for " << target << endl;
    if (indexRec != -1)
        cout << "Found at index " << indexRec << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
