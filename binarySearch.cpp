#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>nums , int n , int target) {
  int st = 0 , end = n-1;

  while ( st <= end ) {
    int mid = st + (end-st)/2; // optimized to ovecome overflow scenerio
    if (nums[mid] == target ) {
      return mid;
    } else if (target < nums[mid]) { //move to 1st half of vector
      end = mid - 1;
    } else {
      st = mid + 1;
    }
  }
  return -1;
}

int main () {
  vector<int> nums = {5,10,15,20};
  int n = nums.size();
  int key = 5; // output = index of 5 -> 0

  cout<<binarySearch(nums , n , key) <<endl;

  return 0;
}
