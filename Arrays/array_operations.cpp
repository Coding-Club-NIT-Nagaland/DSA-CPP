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

    int findMin(const vector<int>& arr) {
        int n=arr.size();
        if (n==0) {
            throw runtime_error("Array is empty!");
        }
        int minVal = arr[0];
        for (int i=0;i<n;i++) {
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
        }
        return minVal;
    }

    bool searchArray(const vector<int>& arr, int target) {
        int n=arr.size();
        for (int i=0;i<n;i++) {
            if (arr[i] == target) {
                return true;
            }
        }
        return false;
    }
    void printSubarray(vector<int>& arr){
        int n = arr.size();

        for(int st=0 ; st<n ; st++){
            for(int end= st; end<n ; end++){
                for(int k = st ; k<=end ; k++){
                    cout<<arr[k];
                }
                cout<<" ";
            }
            cout<<endl;
        }
    }
    int maxSubarraySum(vector<int>& arr){
        int n = arr.size();
        int arrSum = 0 , maxSum = INT16_MIN;
        for(int i = 0 ; i<n ; i++){
            arrSum += arr[i];
            maxSum = max(arrSum , maxSum);
            if(arrSum<0){
                arrSum = 0;
            }
        }
        return maxSum;
    }

    void sortAscending(vector<int>& arr){
        int n = arr.size();
        for(int i =0 ; i<n; i++){
            for(int j=0 ; j<n-i-1 ;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
    void sortDescending(vector<int>& arr){
        int n = arr.size();
        for(int i =0 ; i<n; i++){
            for(int j=0 ; j<n-i-1 ;j++){
                if(arr[j]<arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
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
         << (arrayOps.searchArray(arr, target) ? "Yes" : "No") << endl;
    arrayOps.Array_reverse(arr);
     cout << "Array elements in revrse : ";
    arrayOps.displayArray(arr);
    cout<<"Subarray elements : "<<endl;
    arrayOps.printSubarray(arr);
    cout<<"Maximum Subarray Sum : "<<arrayOps.maxSubarraySum(arr)<<endl;
    cout<<"Minimum element : "<<arrayOps.findMin(arr)<<endl;

    arrayOps.sortAscending(arr);
    cout<<"Element in Accending order : ";
    arrayOps.displayArray(arr);
    arrayOps.sortDescending(arr);
    cout<<"Element in decending order : ";
    arrayOps.displayArray(arr);
    

    return 0;
}
