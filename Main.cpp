#include <iostream>
#include <vector>
using namespace std;

// -------------------- O(1) --------------------
void constantExample() {
    cout << "O(1) Example: Constant Time" << endl;
    int x = 42;
    cout << "Answer: " << x << "\n\n";
}

// -------------------- O(n) --------------------
void linearExample(vector<int>& arr) {
    cout << "O(n) Example: Linear Time" << endl;
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n\n";
}

// -------------------- O(n^2) --------------------
void quadraticExample(vector<int>& arr) {
    cout << "O(n^2) Example: Quadratic Time" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

// -------------------- O(n^3) --------------------
void cubicExample(vector<int>& arr) {
    cout << "O(n^3) Example: Cubic Time" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            for (int k = 0; k < arr.size(); k++) {
                cout << "(" << arr[i] << "," << arr[j] << "," << arr[k] << ") ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}

// -------------------- O(log n) --------------------
// Iterative Binary Search
int binarySearchIterative(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Recursive Binary Search
int binarySearchRecursive(vector<int>& arr, int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, right, target);
    else return binarySearchRecursive(arr, left, mid - 1, target);
}

// -------------------- O(n log n) --------------------
void printArray(vector<int>& arr, int left, int right) {
    cout << "[";
    for (int i = left; i <= right; i++) {
        cout << arr[i];
        if (i < right) cout << ", ";
    }
    cout << "]";
}

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

void mergeSort(vector<int>& arr, int left, int right, int depth = 0) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        cout << string(depth * 2, ' ') << "Splitting: ";
        printArray(arr, left, right);
        cout << endl;

        mergeSort(arr, left, mid, depth + 1);
        mergeSort(arr, mid + 1, right, depth + 1);

        merge(arr, left, mid, right);

        cout << string(depth * 2, ' ') << "Merging:  ";
        printArray(arr, left, right);
        cout << endl;
    }
}

// -------------------- MAIN --------------------
int main() {
    vector<int> arr = { 1, 2, 3, 4 };
    vector<int> sortedArr = { 1, 3, 5, 7, 9, 11 };
    vector<int> mergeArr = { 38, 27, 43, 3, 9, 82, 10 };

    constantExample();
    linearExample(arr);
    quadraticExample(arr);
    cubicExample(arr);

    cout << "O(log n) Example: Binary Search (Iterative)" << endl;
    int index = binarySearchIterative(sortedArr, 7);
    cout << "Found 7 at index: " << index << "\n\n";

    cout << "O(log n) Example: Binary Search (Recursive)" << endl;
    index = binarySearchRecursive(sortedArr, 0, sortedArr.size() - 1, 7);
    cout << "Found 7 at index: " << index << "\n\n";

    cout << "O(n log n) Example: Merge Sort\n" << endl;
    cout << "Original: ";
    for (int x : mergeArr) cout << x << " ";
    cout << "\n\n";

    mergeSort(mergeArr, 0, mergeArr.size() - 1);

    cout << "\nSorted:   ";
    for (int x : mergeArr) cout << x << " ";
    cout << endl;

    return 0;
}
