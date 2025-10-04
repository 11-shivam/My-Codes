//Given an array nums of size n, return the majority element.The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// size of vector can vary to 5*10^4.

#include <iostream>
#include <vector>
using namespace std;

int bruteForce (vector<int>nums , int n) { // Time Complexity : O(n^2)
    for (int i=0 ; i< n ; i++) {
        int freq = 0;
        for (int j=i; j<n ; j++) {
            if (nums[i] == nums[j]) {
                freq++;
            }
        }
        if (freq > n/2) { // Majority element found
            return nums[i];
            
        }
    }
    return -1; // Majority element not exists.
}

int optimise () { //  Using Sorted Array.  Time Complexity : O(nlogn + n) =>> O(nlogn)
    vector<int>nums = {0,1,1,2,2,2,2,2,2,3,3};
    int n = nums.size();
    int freq =1;
    for (int i=0 ; i<n-1 ; i++) {
        if (nums[i] == nums[i+1]) {
            freq ++;
        } else {
            freq = 1;
        }
        if (freq > n/2) {
           return nums[i];
        }       
    }
    return -1;
}

int MooreVotingAlgorithm (vector<int>nums , int n) {
    int freq =0 , ans=0 ;
    for (int i=0 ; i<n ; i++) {
        if (freq == 0) {
            ans = nums[i];
        }
        if(ans == nums[i]) {
            freq++;
        } else {
            freq--;
        }
    }
    return ans;
}

int main () {
    vector <int> nums = {2,1,0,1,2,2,2};
    int n = nums.size();

   cout<< bruteForce(nums , n)<<endl;
   cout<<optimise()<<endl;
   cout<<MooreVotingAlgorithm (nums , n)<<endl;
    return 0;
}