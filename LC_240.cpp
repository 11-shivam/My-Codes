// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.


#include <iostream>
#include <vector>
using namespace std;


bool searchMatrix (vector<vector<int>> matrix , int m , int n , int target ) { // Time Complexity : O( log(m*n) )

    int i = 0; // Row tracking variable;
    int j = n-1; // Column tracking variable;

    while ( i < m && j >=0 ) {
        
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] > target) {
            j--;
        } else {
            i++;
        }

    }

    return false;
}


int main () {

        vector<vector<int>> matrix = {{1,4,7,11,15} , {2,5,8,12,19} , {3,6,9,16,22} , {10,13,14,17,24} , {18,21,23,26,30}};
        int m = matrix.size(); // No. Of Rows;
        int n = matrix[0].size(); // No. Of Columns;
        int target = 30;

        cout<< searchMatrix(matrix , m , n , target) <<endl;
    return 0;
}