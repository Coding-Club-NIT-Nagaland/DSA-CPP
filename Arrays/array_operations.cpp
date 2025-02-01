#include <iostream>
#include <vector>
using namespace std;

class ArrayOperations {
public:
    void displayArray(const vector<int>& arr) {
        cout << "Array elements: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    int sumArray(const vector<int>& arr) {
        int sum = 0;
        for (int num : arr) {
            sum += num;
        }
        return sum;
    }

    int findMax(const vector<int>& arr) {
        if (arr.empty()) {
            throw runtime_error("Array is empty!");
        }
        int maxVal = arr[0];
        for (int num : arr) {
            if (num > maxVal) {
                maxVal = num;
            }
        }
        return maxVal;
    }

    bool searchArray(const vector<int>& arr, int target) {
        for (int num : arr) {
            if (num == target) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    ArrayOperations arrayOps;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    arrayOps.displayArray(arr);

    cout << "Sum of elements: " << arrayOps.sumArray(arr) << endl;
    
    try {
        cout << "Maximum element: " << arrayOps.findMax(arr) << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    int target = 4;
    cout << "Is " << target << " in the array? " 
         << (arrayOps.searchArray(arr, target) ? "Yes" : "No") << endl;

    return 0;
}
