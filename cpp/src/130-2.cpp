#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	int row,col;
	void link(vector<vector<char>> & board,vector<vector<bool>> &vis,int i,int j) {
		if(i < 0 || i>=row || j <0 || j >= col) return ;
		if(board[i][j] != 'O') return ;
		if(vis[i][j] == false)
			vis[i][j] = true;
		else return;
		//if(i == 0 || i == row-1 || j == 0 || j == col-1) border = true;
		link(board,vis,i,j+1);
		link(board,vis,i+1,j);
		link(board,vis,i,j-1);
		link(board,vis,i-1,j);
	}
	void fill(vector<vector<char>> & board,vector<vector<bool>> &vis,char ch) {
		for(int i=0;i<row;++i) {
			for(int j=0;j<col;++j) {
				if(vis[i][j] == true) {
					board[i][j] = ch;
				}
			}
		}
	}
public:
    void solve(vector<vector<char>>& board) {
		row = (int)board.size();
		if(row <= 0) return ;
		col = (int)board[0].size();
		for(int i=0;i<col;++i) {
			if(board[0][i] == 'O') {
				vector<vector<bool>> vis(row,vector<bool>(col,false));
				link(board,vis,0,i);
				fill(board,vis,'b');
			}
		}
		for(int i=1;i<row;++i) {
			if(board[i][col-1] == 'O') {
				vector<vector<bool>> vis(row,vector<bool>(col,false));
				link(board,vis,i,col-1);
				fill(board,vis,'b');
			}
		}
		for(int i=0;i<col-1;++i) {
			if(board[row-1][i] == 'O') {
				vector<vector<bool>> vis(row,vector<bool>(col,false));
				link(board,vis,row-1,i);
				fill(board,vis,'b');
			}
		}
		for(int i=1;i<row-1;++i) {
			if(board[i][0] == 'O') {
				vector<vector<bool>> vis(row,vector<bool>(col,false));
				link(board,vis,i,0);
				fill(board,vis,'b');
			}
		}
		for(int i=0;i<row;++i) {
			for(int j=0;j<col;++j) {
				if(board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
		for(int i=0;i<row;++i) {
			for(int j=0;j<col;++j) {
				if(board[i][j] == 'b') board[i][j] = 'O';
			}
		}
    }
};

int main() {
	vector<vector<char>> vec = {
		{'X','O','X','O','X','O'},
		{'O','X','O','X','O','X'},
		{'X','O','X','O','X','O'},
		{'O','X','O','X','O','X'}
	};
	Solution sol;
	sol.solve(vec);
	for(auto s:vec) {
		for(auto t:s) {
			cout<< t << " ";
		}
		cout << endl;
	}
	return 0;
}
