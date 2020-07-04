//
// Created by bytedance on 2020/5/10.
//
#include <iostream>
#include <vector>
using namespace std;



class Solution {
    // 需要实现三个函数
    // find(int m) 找到m的根结点
    // isConnected(int m, int n) 判断m和n是否在一个连通区域
    // myunion(int m,int n) 合并m，n所在的联通区域
    class UnionFind{
    public:
        vector<int> parents;
        UnionFind(int totalNodes) {
            parents.resize(totalNodes);
            for(int i=0;i<totalNodes;++i) {
                parents[i] = i;
            }
        }
        int find(int node) {
            while(parents[node] != node) {
                parents[node] = parents[parents[node]];
                node = parents[node];
            }
            return node;
        }
        bool isConnected(int node1,int node2) {
            return find(node1) == find(node2);
        }
        void myunion(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);
            if(root1 != root2) {
                parents[root2] = root1;
            }
        }
    };
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows <= 0) return ;
        int cols = board[0].size();
        if(cols <=0) return ;

        UnionFind *uf = new UnionFind(rows*cols+1);
        int dummyNode = rows * cols;
        
        for(int i=0;i<rows;++i) {
            for(int j=0;j<cols;++j) {
                if(board[i][j] == 'O') {
                    // 如果o在边界，那么直接把它跟dummynode归为一个集合
                    if(i == 0 || i == rows-1 || j == 0 || j == cols-1) {
                        uf->myunion(node(i,j,cols),dummyNode);
                    } else {
                        // 如果o不在边界，则看它的上下左右
                        if(i>0 && board[i-1][j] == 'O') {
                            uf->myunion(node(i,j,cols),node(i-1,j,cols));
                        } 
                        if(i<rows-1 && board[i+1][j]=='O') {
                            uf->myunion(node(i,j,cols),node(i+1,j,cols));
                        }
                        if(j>0 && board[i][j-1]=='O') {
                            uf->myunion(node(i,j,cols),node(i,j-1,cols));
                        }
                        if(j<cols-1 && board[i][j+1]== 'O') {
                            uf->myunion(node(i,j,cols),node(i,j+1,cols));
                        }
                    }
                }
            }
        }
        // 将和dummynode连接的‘O’点恢复为‘O’，其他的‘O’点变为‘X’
        for (int i = 0; i < rows; i++) {
            for(int j=0;j<cols;++j) {
                if(uf->isConnected(node(i,j,cols),dummyNode)) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
    // 将二维坐标转换为一维序号
    int node(int i,int j,int cols) {
        return i * cols + j;
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
