//Best Time to Buy & Sell Stock
//Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include <iostream>
#include <vector>
using namespace std;

int stock(vector<int>prices , int n) {
    int buy =  INT_MAX , sell =INT_MIN ;
    int maxProfit = 0;
 
    for (int i=0 ; i<n-1 ; i++) { // Time Complexity : O(n)
        int buy = min (prices[i] ,buy);
        int sell = max (prices[i+1] , buy);
        int currProfit = sell - buy;
        maxProfit = max (currProfit ,maxProfit);
    }
    return maxProfit;
}

int main () {
    vector<int> prices = {7,6,4,3,1};
    int n= prices.size();

    cout<<stock( prices , n ) <<endl;
    return 0;
}