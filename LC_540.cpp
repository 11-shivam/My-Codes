#include <iostream>
#include <vector>
using namespace std;


int searchSingleElement (vector<int> A ,int n) {
    int st=0 , end=n-1;
    if (n == 1)  return A[0];
    while (st <= end ) {
        int mid = st + (end-st)/2;
        if (mid==0 && A[0] != A[1]) return A[0];
        if (mid==n-1 && A[n-2] != A[n-1]) return A[n-1];
        if (A[mid-1] != A[mid] && A[mid] != A[mid+1]) {
            return A[mid];
        } else if (mid % 2 !=0) { //mid is odd  =>> both halves are odd
            if (A[mid-1] == A[mid]) { //move to 2nd half
                st = mid-1;
            } else {
                end = mid + 1;
            }
        } else { // mid is even =>> halves are even
            if (A[mid-1] == A[mid]) { //move to 1st half
                end = mid + 1;
            } else {
                st = mid -1;
            }
        }
    }
    return -1; // single element do not exists
}

int main () {

vector<int> A = {1,1,2,3,3,4,4,8,8}; // output : 2
int n = A.size();

cout <<searchSingleElement (A , n)<<endl;

return 0;
}
