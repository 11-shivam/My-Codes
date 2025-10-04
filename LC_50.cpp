//Calculate x^n where -100<x<100 & -2^31 <= n <= 2^31 - 1;

#include <iostream>
#include <vector>
using namespace std;

void bruteForce(double x , int n) { // Time complexity : O(n) =>> TLE 
    double ans = 1;

    if (n < 0) { // Tackling negative power case;
        x = 1/x;
        n = - n;
    }
    for (int i=0 ; i<n ; i++) {
        ans = ans*x;
    }
    cout<< ans <<endl;
}

void optimise (double x , int n ) { // Time complexity : O(logn)
    long binForm = n;    
    if(n < 0) {
        x = 1/x;
        binForm = -binForm;
    }
    double ans = 1;
    while (binForm > 0) {
        int rem = binForm%2;
        if (rem == 1) {
            ans = ans * x;
        }
        x = x* x;
        binForm /= 2;
    }
   cout<< ans<<endl;
}

int main () {
    double x=-2;
    int n=-10;
    
    bruteForce (x , n);
    optimise (x , n );

    return 0;
}