#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
	int row,col;
	//int next[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
	int next[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
	void burn(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& visited){
		for(int k=0;k<4;++k) {
			int new_i = i + next[k][0];
			int new_j = j + next[k][1];
			if(new_i>=0 && new_i <row && new_j >=0 && new_j <col && grid[new_i][new_j] == '1' && visited[new_i][new_j] == false){
					visited[new_i][new_j] = true;
					burn(new_i,new_j,grid,visited);
			}
		}
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		row = (int)grid.size();
		if(row <= 0) return 0;
		col = (int)grid[0].size();
		vector<vector<bool>> visited(row,vector<bool>(col,false));
		int answer = 0;
		for(int i=0;i<row;++i) {
			for(int j=0;j<col;++j) {
				if(grid[i][j] == '1' && visited[i][j] == false) {
					++answer;
					visited[i][j] = true;
					burn(i,j,grid,visited);
					//print(visited);
				}
			}
		}
		return answer;
	}
//	void print(vector<vector<bool>> &grid) {
//		for(auto s : grid) {
//			for(auto t : s) {
//				cout << t << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
};

int main() {
	Solution sol;
	vector<vector<char>> mp = {
		{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}
	};
	cout << sol.numIslands(mp) << endl;
	return 0;

}
