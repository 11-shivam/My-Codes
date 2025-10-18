// We dont use these sorting algorithm to sort our data but these is important from interview point of view.
//Time complexity for buubleSort , selectionSort & intertionSort : O(n^2)

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>&nums , int n) { // compare adjacent elements & swap them if they are placed in wrong position.
    for (int i=0 ; i<n-1 ; i++) {
        bool isSwap = false;
    for (int j=0; j<n-i-1 ; j++) {
        if (nums[j] > nums[j+1]) {
            swap (nums[j] , nums[j+1]);
            isSwap = true;
        }
    }
    if(isSwap == false) {
        return;
    }
}
}

void selectionSort(vector<int>&nums , int n) { // selecting smallest number & swap it by nums[i] (i=0,1,2,,,,n-1).
    for (int i=0; i<n-1; i++) {
        int index = i ; //assuming nums[i] is smallest element

        for (int j=i+1; j<n; j++) {
            if(nums[j] < nums[index]) {
                index = j;
            }
        }
        swap (nums[i] , nums[index]);
    }
}

void intertionSort(vector<int>&nums , int n) { 
    for (int i=1; i<n; i++) {
        int curr = nums[i]; // slecting i=1,2,3,,,n to check
        int prev = i-1;

        while (prev >=0 && nums[prev] > curr) {
            nums[prev+1] = nums[prev];
            prev--;
        }
        nums[prev+1] = curr; // placing curr at right place.
    }
}

void printSort ( vector<int>nums , int n ) {
    for (int i=0 ; i<n ; i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main () {
    vector <int> nums = {4,1,5,2,3};
    int n = nums.size();

    // bubbleSort(nums , n);
    // printSort(nums , n);   

    // selectionSort (nums , n);
    // printSort(nums,n);

    
    // intertionSort (nums , n);
    // printSort(nums , n);

    return 0;
}