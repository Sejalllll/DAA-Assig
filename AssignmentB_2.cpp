#include <iostream>
#include <vector>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int min_price = prices[0]; // Initialize to the first day's price
    int max_profit = 0;        // Initialize max profit to 0

    for (int i = 1; i < prices.size(); i++) {
        // Update min_price if the current day's price is lower
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
        // Calculate profit if we sell on this day and update max_profit if it's higher
        else {
            int profit = prices[i] - min_price;
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
    }

    return max_profit;
}

int main() {
    vector<int> arr1 = {2, 3, 5};
    vector<int> arr2 = {8, 5, 1};

    cout << "Maximum Profit for arr1: " << maxProfit(arr1) << endl; // Output: 3
    cout << "Maximum Profit for arr2: " << maxProfit(arr2) << endl; // Output: 0

    return 0;
}
