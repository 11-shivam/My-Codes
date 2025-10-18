// Product of array except itself. Don't use divide operator.
#include <iostream>
#include <vector>
using namespace std;

void productOfArrayExceptItself (vector<int>nums, int n) {
    vector<int>ans(n,1);
    for (int i = 1 ; i<n ; i++) {
        ans[i] = ans[i-1] * nums[i-1]; // Storing left product in ans[i]
    }

    int right = 1;
    for (int i = n-2; i>=0; i--) {
        right = right * nums[i+1]; // Storing right product in ans[i]
        ans[i] = ans[i] * right;
    }

    for(int i=0; i<n; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main () {
    vector<int> nums = {1,2,3,4};
    int n = nums.size();
    vector<int> ans(n,1);

    productOfArrayExceptItself(nums , n);

    return 0;
}
