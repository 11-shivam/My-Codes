// You are given two integer arrays v1 and v2, sorted in non-decreasing order, and two integers n and m, representing the number of elements in nums1 and nums2 respectively.
// Merge v1 and v2 into a single array sorted in non-decreasing order.
// Input: v1 = [1,2,3,0,0,0], n = 3, v2 = [2,5,6], m = 3
// Output: [1,2,2,3,5,6]

#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<int> v1 = {1,2,3,0,0,0}; // n valid elements
    vector<int> v2 = {2,5,6}; // m elements
    int n = v1.size() - v2.size();
    int m = v2.size();
    int i = m-1 , j = n-1 , l = n+m-1;

    while(i >= 0 && j >= 0) {
        if (v2[j] > v1[i]) {
            v1[l] = v2[j];
            l--;
            j--;
        } else {
            v1[l] = v1[i];
            l--;
            i--;
        }
    }
    while (j >= 0) {
        v1[l] = v2[j];
        l--;
        j--;
    }

    for (int k=0 ; k < n+m ; k++) {
        cout << v1[k] <<" ";
    }
    cout<<endl;
}