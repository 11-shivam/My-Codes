// -------> SPIRAL MATRIX <--------
//Given an m x n matrix, return all elements of the matrix in spiral order.

#include <iostream>
#include <vector>
using namespace std;

void spiralMatrix (vector<vector<int>> matrix , int m , int n ,vector<int> &answer ) {

    int x = 0; // Starting Row;
    int y = m-1; // Ending Row;

    int i = 0; // Starting Column;
    int j = n-1;// Ending Column;

    while ( x <= y && i <= j ) { // Time Complexity : O( log(m*n) );

        // Top :
        for(int l = i ; l <= j ; l++) {
            answer.push_back(matrix[x][l]);
        }
        x++;

        // Right :
        for ( int l = x ; l <= y ; l++) {
            answer.push_back( matrix[l][j] );
        }
        j--;

        // Bottom :
        if(x == y) break;
        for(int l = j ; l >= i ; l--) {
            answer.push_back( matrix[y][l] );
        }
        y--;

        // Left :
        for(int l = y ; l >= x ; l-- ) {
            if (i == j) break;
            answer.push_back( matrix[l][i] );
        } 
        i++;

    }

}



int main () {
    vector<vector<int>> matrix = {{1,2,3} , {4,5,6} , {7,8,9}};
    int m = matrix.size(); // No. Of Rows;
    int n = matrix[0].size(); // No. Of Columns;
    vector<int> answer;

    spiralMatrix(matrix , m , n ,answer);

    for (int i =0 ; i < m*n ; i++) {
        cout << answer[i] << " ";
    }
    cout<<endl;
    return 0;
}