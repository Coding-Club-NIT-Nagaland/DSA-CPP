#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class ArrayOperations {
public:
    void Array_reverse(vector<int>& arr){
        int n=arr.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    void displayArray(const vector<int>& arr) {
        int n=arr.size();
        for (int i=0;i<n;i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int sumArray(const vector<int>& arr) {
        int n=arr.size();
        int sum = 0;
        for (int i=0;i<n;i++) {
            sum += arr[i];
        }
        return sum;
    }

    int findMax(const vector<int>& arr) {
        int n=arr.size();
        if (n==0) {
            throw runtime_error("Array is empty!");
        }
        int maxVal = arr[0];
        for (int i=0;i<n;i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }

    void sort (vector<int>& arr ) {
        int n = arr.size() ;
        for(int i = 0 ; i < n-1 ; i++ ) {
            bool swapped = false ;
            for(int j = 0 ; j < n-i-1 ; j++ ) {
                if( arr[j] > arr[j+1] ) {
                    swap( arr[j] , arr[j+1]) ;
                    swapped = true ;
                }
            }
            if( swapped == false ) {
                break ;
            }
        }
    }

    bool search_element(vector<int>& arr , int key ) {
        sort(arr) ;
        int n = arr.size() ;
        int start = 0 ;
        int end = n-1 ;
        int mid = start + (end-start)/2 ;
        while(start <= end ) {
            if(arr[mid] == key ) {
                return true ;
            }
            if(arr[mid] > key ) {
                end = mid - 1 ;
            }
            if(arr[mid] < key ) {
                start = mid + 1 ;
            }
            mid = start + (end - start)/2 ;

        }
        return false ;
    }
    
};

int main() {
    ArrayOperations arrayOps;
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n=sizeof(a)/sizeof(a[0]);
    //vector can't be initialised as initialiser list 
    //vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    vector<int> arr(a,a+n);
    cout << "Array elements: ";
    arrayOps.displayArray(arr);

    cout << "Sum of elements: " << arrayOps.sumArray(arr) << endl;
    
    try {
        cout << "Maximum element: " << arrayOps.findMax(arr) << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    int target = 4;
    cout << "Is " << target << " in the array? " 
         << (arrayOps.search_element(arr, target) ? "Yes" : "No") << endl;
    arrayOps.Array_reverse(arr);
     cout << "Array elements in revrse : ";
    arrayOps.displayArray(arr);

    return 0;
}
