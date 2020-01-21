// 407.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
using namespace std;

class Solution {

class node
{
public:
	node(int _x, int _y, int _height) :x(_x), y(_y), height(_height) {};
	~node() {};
	int x, y,height;
};
struct comp
{
	bool operator()(node a, node b) {
		return a.height > b.height;
	}
};
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		int answer = 0;
		int next[][2] = {-1,0,1,0,0,1,0,-1};
		priority_queue<node,vector<node>,comp> q;
		int row = (int)heightMap.size();
		if (row == 0) return 0;
		int col = (int)heightMap[0].size();
		vector<vector<bool>> visited(row, vector<bool>(col, 0));
 		for (int i = 0; i < col; ++i) {
			visited[0][i] = true;
			visited[row - 1][i] = true;
			q.push(node(0, i, heightMap[0][i]));
			q.push(node(row - 1, i, heightMap[row - 1][i]));
		}
		for (int i = 0; i < row; ++i) {
			visited[i][0] = visited[i][col - 1] = true;
			q.push(node(i, 0, heightMap[i][0]));
			q.push(node(i, col - 1, heightMap[i][col - 1]));
		}
		while (!q.empty()) {
			node tmp = q.top();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int x = tmp.x + next[i][0];
				int y = tmp.y + next[i][1];
				if (x >= 0 && x < row && y >= 0 && y < col && !visited[x][y]) {
					answer += max(0,tmp.height - heightMap[x][y]);
					visited[x][y] = true;
					q.push(node(x,y,max(tmp.height,heightMap[x][y])));
				}
			}
		}
		return answer;
	}
};
int main()
{
    
	
	Solution sol;
	vector<vector<int>> vec = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
	cout << sol.trapRainWater(vec) << endl;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
