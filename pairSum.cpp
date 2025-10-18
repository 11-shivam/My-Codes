//We've given with an array & a target sum . We have to return pair of those two element whose sum is equal to target

#include <iostream>
#include <vector>
using namespace std;

void pairSum (vector<int>nums , int n , int target) { // Time Complexity : O(n^2)

    for (int i=0 ; i<n-1 ;i++) {
        int pairSum =0;
        for (int j=i+1 ; j<n ; j++) {
            pairSum = nums[i] + nums[j];
            if (pairSum == target) {
                cout<<i<<","<<j<<endl;
            }
        }
    }
}
void optimise(vector<int>nusm , int n , int target) {
    int st=0 , end=n-1;
    while (st < end) {
        
    }
}

int main () {
    vector <int> nums = {1,2,3,4,5};
    int n = nums.size();
    int target = 9;

    pairSum(nums , n , target);
    return 0;
}