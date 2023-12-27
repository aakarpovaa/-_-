#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
	int n = prices.size();
	if (n == 0) {
		return 0;
	}

	int max_transactions = 2; 
	vector<vector<int>> dp(n, vector<int>(max_transactions + 1, 0));

	for (int j = 1; j <= max_transactions; ++j) {
		int max_diff = -prices[0];
		for (int i = 1; i < n; ++i) {
			dp[i][j] = max(dp[i - 1][j], prices[i] + max_diff);
			max_diff = max(max_diff, dp[i][j - 1] - prices[i]);
		}
	}

	return dp[n - 1][max_transactions];
}

int main() {

	vector<int> prices1 = { 3, 3, 5, 0, 0, 3, 1, 4 };
	cout << maxProfit(prices1) << endl; 
	return 0;
}
