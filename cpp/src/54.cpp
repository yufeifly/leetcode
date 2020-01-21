#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	struct node {
		int x,y;
		node(int _x,int _y) :x(_x),y(_y) {}
	};
	
	int direction;
	int row, col;
	
	node findnext(int x,int y,vector<vector<int>> &next,vector<vector<bool>> &visited) {
		int tmp_x = x + next[direction][0];
		int tmp_y = y + next[direction][1];
		if(tmp_x >= 0 && tmp_x < row && tmp_y >= 0 && tmp_y < col && visited[tmp_x][tmp_y] == false) {
			return node(tmp_x,tmp_y);
		} else {
			direction = (direction != 3) ? direction + 1 : 0;
			tmp_x = x + next[direction][0];
			tmp_y = y + next[direction][1];
			if(tmp_x >= 0 && tmp_x < row && tmp_y >= 0 && tmp_y < col && visited[tmp_x][tmp_y] == false){
				return node(tmp_x,tmp_y);
			}
		}
		return node(-1,-1);
	}
public:
	
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> answer;
		row = (int)matrix.size(); 
        if(row <= 0) return answer;
		col = (int)matrix[0].size();
		vector<vector<int>> next = {
			{0,1},{1,0},{0,-1},{-1,0}
		};
		vector<vector<bool>> visited(row,vector<bool>(col,0));
		answer.push_back(matrix[0][0]);
		visited[0][0] = true;
		direction = 0;
		int x = 0, y = 0;
		while(true) {
			node tmp = findnext(x,y,next,visited);
			if(tmp.x == -1) break;
			x = tmp.x;
			y = tmp.y;
			visited[x][y] = true;
			answer.push_back(matrix[x][y]);
		}
		return answer;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> vec = {
		{ 1, 2, 3 },
 		{ 4, 5, 6 },
 		{ 7, 8, 9 }	
	};
	vector<int> answer = sol.spiralOrder(vec);
	for(auto s : answer) {
		cout << s << endl;
	}
	return 0;
}

