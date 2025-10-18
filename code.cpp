#include <iostream>
#include <vector>
using namespace std;


int main () {
   vector <int> v1 ={4,5,6,0,0,0}; // n elements
   vector<int> v2 = {1,2,3}; // m elements
    int n = v1.size() - v2.size();
    int m = v2.size();
    int i=n-1 , j=m-1;
    int l = v1.size();

    while(i>=0 && j>=0) {
        if(v2[j] > v1[i]) {
            v1[l-1] = v2[j];
            l--;
            j--;
        } else {
            v1[l-1] = v1[i];
            l--;
            i--;
        }
    }

    for (int i=0; i<n+m; i++) {
        cout << v1[i] << " ";
    }
    cout<<endl;

    return 0;
}