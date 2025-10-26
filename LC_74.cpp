//-------> SEARCH IN A 2D MATRIX <--------

// You are given an m x n integer matrix matrix with the following two properties:
// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.


#include <iostream>
#include <vector>
using namespace std;

int searchRow (vector<vector<int>> matrix , int m ,int n ,int target) {
    int st = 0 , end = m - 1 ; // To Search in Row;

    while ( st <= end ) {
        int mid = st + (end - st)/2;

        if (  matrix[mid][0] <= target && target <= matrix[mid][n-1]  ) {
            return mid; //Returns Row number where target lies;
        } else if ( matrix[mid][0] < target ) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return 0 ;
}

bool searchMatrix (vector<vector<int>> matrix , int m , int n , int target ) {
    int st = 0 , end = n - 1 ; // To Search in Column;

    int Row = searchRow (matrix , m , n , target ) ; // Gives Row number where target lies;

    while ( st <= end ) {
        int mid = st + (end - st)/2;
        if ( matrix[Row][mid] == target ) {
            return true; // Target Found -> 1;
        } else if ( matrix[Row][mid] > target ) {
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return false; // Target Not Found -> 0;
}

int main () {
    vector<vector<int>> matrix = {{1,3,5,7} , {10,11,16,20} , {23,30,34,60}};
    int m = matrix.size(); // No. Of Rows
    int n = matrix[0].size(); // No. Of Columns
    int target = 34;

    cout<< searchMatrix( matrix , m , n , target) <<endl;
    return 0;
}