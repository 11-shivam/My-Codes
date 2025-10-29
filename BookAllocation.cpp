// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that
    //Each student receives atleast one book.
    //Each student is assigned a contiguous sequence of books.
    //No book is assigned to more than one student.
//The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.
//Note: If it is not possible to allocate books to all students, return -1.


#include <iostream>
#include <vector>
#include <vector>
using namespace std;

int arrSum (vector<int>arr ) {
    int sum = 0;


    for (int i = 0; i < arr.size() ; i++ ) {
        sum += arr[i];
    }
    return sum;
}

bool isValid (vector<int> arr , int k , int maximumAllowedPages ) { // Time Complexity : O(n);
    int student = 1 , pages = 0;

    for (int i = 0; i < arr.size() ; i++ ) {

        if (arr[i] > maximumAllowedPages ){ // Edge case;
            return false;
        }

        if ( pages + arr[i] <= maximumAllowedPages ) {
            pages += arr[i] ;
        } else {
            pages = arr[i];
            student ++;
        }
    }

    if (student <= k ) {
        return true;
    } else {
        return false;
    }
}

int allocateBook(vector<int>arr , int k) { //Time Complexity : O(n*logN + n )

    if (arr.size() < k ) { // Number of Student(k) > Number of Books (arr.size()); 
        return - 1;
    }

    int st = 0 ; // Start is minimum number of pages a student can have -> 0;
    int end = arrSum(arr) ; // End is maximum number of pages a student can have -> Sum of array;
    int ans = 0;

    while ( st <= end ) {
        int mid = st + (end-st)/2 ;

        if ( isValid(arr , k , mid ) == 1 ) { // Left of the Range
            ans = mid;
            end = mid - 1;
        } else { // Right 
            st = mid + 1;
        }
    }
    return ans ;
}
int main () {
    vector<int> arr = {12, 34, 67, 90};
    int k = 3 ; // Number Of Student;

    cout << allocateBook (arr , k ) << endl;

    return 0;
}
