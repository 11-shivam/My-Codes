#include <iostream>
#include <vector>
using namespace std;

int main () {
   vector <int> v ={5 , 3 ,4,2 ,1};
   int n = v.size();

   for (int i=0 ; i<n ; i++) {
      int mini =INT_MAX;
    for (int j=i ; j<n ; j++) {
        mini = min (v[j] , mini);
    }
    swap (v[i] , mini);
   }
   for (int i=0 ; i<n ; i ++) {
    cout<<v[i]<< " ";
   }
   cout<<endl;
    return 0;
}