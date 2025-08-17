#include <iostream>
#include <vector>
using namespace std;

// O(1) - Constant time
void constantExample(vector<int>& arr) {
    cout << "O(1) Example: First element is " << arr[0] << endl;
}

// O(n) - Linear time
void linearExample(vector<int>& arr) {
    cout << "O(n) Example: Printing all elements -> ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// O(n^2) - Quadratic time
void quadraticExample(vector<int>& arr) {
    cout << "O(n^2) Example: All pairs -> " << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
        cout << endl;
    }
}

// O(n^3) - Cubic time
void cubicExample(vector<int>& arr) {
    cout << "O(n^3) Example: All triplets -> " << endl;
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

int main() {
    vector<int> numbers = { 1, 2, 3 };

    constantExample(numbers);
	cout << endl;
    linearExample(numbers);
    cout << endl;
    quadraticExample(numbers);
    cout << endl;
    cubicExample(numbers);
    cout << endl;

    return 0;
}
