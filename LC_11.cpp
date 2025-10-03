//Container With Most Water
//Given vector is height of containers.

#include <iostream>
#include <vector>
using namespace std;

int bruteForce (vector<int>hgt , int n ) { //Time Complexity : O(n^2)
    int maxArea = INT_MIN;

    for (int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++ ) {
            int ht = min (hgt[i] , hgt[j]);
            int width = j-i;
            int currArea = width * ht;
            maxArea = max (currArea , maxArea);
        } 
    }
    return maxArea;
}

int optimise (vector<int>hgt , int n) { //Time Complexity : O(n) ; Two pointer Approach
    int i=0 , j= n-1;
    int maxArea =INT_MIN;
    while(i < j) {
        int width = j - i;
        int ht = min (hgt[i] , hgt[j]) ;
        int currArea = width * ht;
        maxArea = max (currArea , maxArea);
        if (hgt[i] < hgt[j] ) {
            i++;
        } else {
            j--;
        }
    }
    return maxArea;
}

int main () {

vector <int> hgt ={1,8,6,2,5,4,8,3,7}; //Given Heights
int n = hgt.size();

cout<<bruteForce(hgt , n)<<endl;
cout<<optimise(hgt ,n)<<endl;
    return 0;
}