//Given an array arr[] and k, where the array represents the boards and each element of the given array represents the length of each board. k numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. The task is to find the minimum time to get this job done by painting all the boards under the constraint that any painter will only paint the continuous sections of boards. say board [2, 3, 4] or only board [1] or nothing but not board [2, 4, 5].

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>arr , int n ,int k, int minimumAllowedTime) {
    int painter = 1 , time = 0;

    for (int i=0; i<n; i++) {
        if(arr[i] > minimumAllowedTime) {
            return false;
        }

        if (time + arr[i] <= minimumAllowedTime) {
            time += arr[i];
        } else {
            time = arr[i];
            painter ++;
            if (painter > k) return false;
        }
    }
    return true;
}

int PainterPartition (vector<int> arr , int n , int k ) { // Time Complexity : O (n*logN + 2n ) -> O(n*logN) : N ==> Range
    int minimumValue = INT_MAX;
    int arrSum = 0;

    for(int i=0; i < n; i++) { 
        minimumValue = min (arr[i] ,minimumValue );
    }

    for(int i=0; i<n; i++) {
        arrSum += arr[i];
    }

    int st = minimumValue; // Starting Range Of Possible Time;
    int end = arrSum; // Ending Range Of Possible Time;
    int minimumTime = 0;

    while ( st <= end ) {
        int mid = st + (end-st)/2;

        if (isPossible (arr,n,k, mid ) ) { // Left Of Ranges Of Time;
            minimumTime = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return minimumTime;
}

int main () {
    vector<int> arr = {5, 10, 30, 20, 15};
    int n = arr.size(); // Number Of Boards;
    int k = 3 ; // Number Of painters;

    cout<< PainterPartition(arr , n , k) <<endl;

    return 0;
}