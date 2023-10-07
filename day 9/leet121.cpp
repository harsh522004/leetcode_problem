 // buy and sell stock to get max profit
 
 #include<iostream>
 #include<algorithm>
 #include<vector>
 using namespace std;
 int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        auto it = max_element(prices.begin(), prices.end());  // Get an iterator to the maximum element
        int max_price = *it;  // Dereference the iterator to get the maximum value
        
        
        
        for (int i = 0; i < prices.size(); i++) {
            cout << "Index : " << i << endl;
            cout << "Price : " << prices[i] << endl;
            int max_ele = *max_element(prices.begin() +i+1, prices.end());
            cout << "Max element is: " << max_ele;
            int val = max_ele - prices[i];
            cout << "Value is : " << val << endl;
            profit = max(profit, val);
            cout << "Profit is : " << profit << endl;
        }
        
        return profit;
    }

    int main(){
        vector<int> prices = { 7,1,5,3,6,4};
        int bol = maxProfit(prices);
        return 0;
    }