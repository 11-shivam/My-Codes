// You are given an integer array height of length n. There 
// are n vertical lines drawn such that the two endpoints of the
//  ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container,
//  such that the container contains the most water.

// Return the maximum amount of water a container can store.

#include <iostream>
#include <vector>
using namespace std;

int main () {
vector <int> hgt ={1,8,6,2,5,4,8,3,7};
int n = hgt.size();
int maxArea=INT_MIN;
for (int i=0 ; i<n-1 ;i++ ){
    
    for (int j=i+1 ; j<n ; j++) {
        int height = min (hgt[i],hgt[j]);
        int size = j-i;
        int area = size*height;
        maxArea = max (area , maxArea);
    }
}
cout<<maxArea<<endl;
    return 0;
}