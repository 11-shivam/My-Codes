// Maximum Subarray Sum : Given an integer array nums, find the subarray with the largest sum, and return its sum.
//size  of array can be 10^5.

#include <iostream>
#include <vector>
using namespace std;

void printSubArray (vector<int> nums , int n) {
    for (int i=0 ; i<n ; i++) {
        for (int j=i ; j<n ; j++) {
            for (int k=i ; k<j ; k++) {
                cout<<nums[k];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

int bruteForce (vector<int>nums , int n) { //Time Complexity : O(n^2)
    int maxSum = INT_MIN;
    for (int i=0 ; i<n ; i++) {
        int currSum =0;
        for (int j=i ; j<n ; j++) {
            currSum += nums[j];
            maxSum = max (currSum , maxSum);
        }
    }
    return maxSum;
}

int KadanesAlgorithm (vector<int>nums , int n) { // Time Complexity : O(n)
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i=0 ; i<n ; i++) {
        currSum += nums[i];
        maxSum = max (currSum , maxSum);
        if (currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

int main () {
    vector<int> nums = {-2,1,-3,4,6,2,1,-5,4};
    int n = nums.size();

    //printSubArray (nums , n);
    cout<<bruteForce(nums , n)<<endl;
    cout<<KadanesAlgorithm (nums , n) <<endl;
    return 0;
}