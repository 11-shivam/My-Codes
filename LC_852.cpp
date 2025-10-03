#include <iostream>
#include <vector>
using namespace std;

int mountain(vector<int> nums , int n) {
    int st =1 , end = n-2 ; // as peak can't be at start or end of vector

    while (st <= end ) {
        int mid = st + (end-st)/2;
        
        if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) {
            return mid;
        } else if (nums[mid-1] < nums[mid]) { //left slant =>> move to next slant
            st = mid +1 ;
        } else { // right slant =>> move to left slant
            end = mid-1;
        }
    }
    return -1;
}

int main () {
    vector <int> nums = {0,3,10,5,2}; // output index of 10 ->2
    int n = nums.size();
    cout<<mountain(nums , n)<<endl;
    return 0;
}