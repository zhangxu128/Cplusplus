#include <iostream>
#include <vector>

using namespace std;


int getMost(vector<vector<int> > board) {
	// write code here
	//首列处理
	for (int i = 1; i < board.size(); i++) {
		board[i][0] = board[i][0] > board[i - 1][0] ? board[i][0] : board[i - 1][0];
	}
	
	//首行处理
	for (int i = 1; i < board.size(); i++) {
		board[0][i] = board[0][i] > board[0][i - 1] ? board[0][i] : board[0][i - 1];
	}

	//其它位置处理
	for (int i = 1; i < board.size(); i++) {
		for (int j = 1; j < board[i].size(); j++) {
			board[i][j] = board[i][j] > board[i - 1][j] ? board[i][j] : board[i - 1][j];
			board[i][j] = board[i][j] > board[i][j - 1] ? board[i][j] : board[i][j - 1];
		}
	}
	return board[5][5];
}

int main(void) {

	vector<int> v(6);
	vector<vector<int>>vv(6,v);
	for (int i = 0; i < vv.size(); i++) {
		for (int j = 0; j < vv[i].size(); j++) {
			cin >> vv[i][j];
		}
	}
	cout << getMost(vv) << endl;
	system("pause");
	return 0;
}