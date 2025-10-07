//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

#include <iostream>
#include <vector>
using namespace std;

void dutchNationalFlagAlgorithm (vector<int>&nums , int n) { // TIme Complexity : O(n)
    int mid = 0, low = 0, high = n-1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap (nums[mid] , nums[low]);
            mid ++;
            low ++;
        } else if (nums[mid] == 2) {
            swap (nums[high] , nums[mid] );
            high --;
        } else {
            mid++;
        }
    }
}

void print (vector<int>nums , int n) {
    for (int i=0; i<n; i++) {
        cout<< nums[i] << " ";
    }
    cout<<endl;
}

int main () {
    vector <int> nums= {1,0,2,2,1,0,2,1,0};
    int n = nums.size();

    dutchNationalFlagAlgorithm (nums , n);
    print (nums , n);

    return 0;
}