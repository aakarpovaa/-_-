#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NQueens {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> board(n, string(n, '.'));

		solveNQueensHelper(board, 0, result);

		return result;
	}

private:
	void solveNQueensHelper(vector<string>& board, int row, vector<vector<string>>& result) {
		if (row == board.size()) {
			result.push_back(board);
			return;
		}

		for (int col = 0; col < board.size(); ++col) {
			if (isSafe(board, row, col)) {
				board[row][col] = 'Q';
				solveNQueensHelper(board, row + 1, result);
				board[row][col] = '.';  
			}
		}
	}

	bool isSafe(const vector<string>& board, int row, int col) {
		
		for (int i = 0; i < row; ++i) {
			if (board[i][col] == 'Q') {
				return false;
			}
		}

		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
			if (board[i][j] == 'Q') {
				return false;
			}
		}

		for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j) {
			if (board[i][j] == 'Q') {
				return false;
			}
		}

		return true;
	}
};

int main() {
	int n = 5; // тут указываем любое нужное нам n и живём счастливо
	NQueens solver;
	vector<vector<string>> result = solver.solveNQueens(n);

	for (const auto& solution : result) {
		for (const auto& row : solution) {
			cout << row << endl;
		}
		cout << "---------" << endl;
	}


	return 0;
}
// С Наступающим Новым годом!!!