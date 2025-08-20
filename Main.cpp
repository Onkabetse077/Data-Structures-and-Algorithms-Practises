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

// ------------------ O(n log n) - Merge Sort ------------------
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);       // sort left half
        mergeSort(arr, mid + 1, right);  // sort right half
        merge(arr, left, mid, right);    // merge halves
    }
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

    // O(n log n) - Merge Sort
    vector<int> arr = { 38, 27, 43, 3, 9, 82, 10 };
    cout << "\nO(n log n) Example: Merge Sort" << endl;
    cout << "Unsorted: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted:   ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
