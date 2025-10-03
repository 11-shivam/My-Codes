//Linear Search Algorithm
//Time complexity O(n)
//mostly used to reduce time complexity of O(n^2) of nested loops

#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> nums , int n , int key ) {
    
    for (int i=0 ; i<n ; i++) {
        if (nums[i] == key ) {
            return i; //Key is found
        }
    }
    return -1; //Key mot foumd
}

int main () {
    vector<int> nums ={10,15,24,21,3,55};
    int n =nums.size();
    int key = 3 ; //output is index of 3 -> 4

    cout<<linearSearch(nums, n , key)<<endl;

    return 0;
}