//Reverse a string
#include <iostream>
#include <string>
using namespace std;

void bruteForce(string str , int n) {
    int i = 0 , j = n-1;

    while ( i < j) {
        swap (str[i] , str[j]);
        i++;
        j--;
    }
    for ( int i = 0 ; i < n; i++) {
        cout<<str[i] << " ";
    }
    cout<<endl;
}

void STL_Function (string str) {
    reverse (str.begin() , str.end());
}

int main () {
    string str = "Hello";
    int n = str.length();

    bruteForce(str , n);
    STL_Function(str);
    return 0;
}