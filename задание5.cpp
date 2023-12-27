#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.empty() || matrix[0].empty()) {
		return 0;
	}

	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<vector<int>> heights(rows, vector<int>(cols, 0));
	int maxArea = 0;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			matrix[i][j] -= '0';
			if (i > 0 && matrix[i][j] == 1) {
				heights[i][j] = heights[i - 1][j] + 1;
			}
			else {
				heights[i][j] = matrix[i][j];
			}
		}
	}

	for (int i = 0; i < rows; ++i) {
		stack<int> s;
		for (int j = 0; j <= cols; ++j) {
			while (!s.empty() && (j == cols || heights[i][j] < heights[i][s.top()])) {
				int height = heights[i][s.top()];
				s.pop();
				int width = s.empty() ? j : j - s.top() - 1;
				maxArea = max(maxArea, height * width);
			}
			s.push(j);
		}
	}

	return maxArea;
}

int main() {
	vector<vector<char>> matrix1 = {
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'}
	};

	cout << maximalRectangle(matrix1) << endl; 

	return 0;
}
