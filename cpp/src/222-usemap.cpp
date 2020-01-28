#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int height;
public:
    int countNodes(TreeNode* root) {
		if(root == NULL) return 0;
		height = 0;
		get_height(root);
		--height;
		if(height == 0) return 1;
		int max = mypow(2,height) - 1;
		int left = 0, right = max;
		vector<int> ex(max+1,-1);
		while(left <= right) {
			int mid = (left + right) / 2;
			bool e1 = exist(mid,root,ex);
			if(e1 == false) {
				right = mid - 1;
			} else{
				if(mid == max) {
					return (mypow(2,height)-1) + mid + 1;
				}	
				bool e2 = exist(mid+1,root,ex);
				if(e2 == false) {
					return (mypow(2,height)-1) + mid + 1;
				} else {
					left = mid + 1;
				}
			}
		}
		return 0;
    }
    void get_height(TreeNode *root) {
		if(root != NULL) {
			++height;
			get_height(root->left);
		}
    }
	int mypow(int base,int pow) {
		int ret = 1;
		for(int i=0;i<pow;++i) {
			ret *= base;
		}
		return ret;
	}
	bool exist(int mid, TreeNode *root,vector<int> &ex) {
		int bak = mid;
		if(ex[mid] == 0) return false;
		if(ex[mid] == 1) return true;
		vector<int> vec(height);
		for(int i=0;i<height;++i) {
			int remain = mid % 2;
			mid /= 2;
			vec[i] = remain;  
		}
		for(int i=height - 1;i>=0;--i) {
			if(vec[i] == 0) root = root->left;
			else root = root->right;
		}
		if(root == NULL) {
			ex[bak] = 0;
			return false;
		}
		ex[bak] = 1;
		return true;
	}
};

int main() {
	TreeNode *node[4];
	vector<int> vec = {1,2,3,4};
	for(int i=0;i<(int)vec.size();++i) {
		node[i] = new TreeNode(vec[i]);
	}
	node[0]->left = node[1];
	node[0]->right = node[2];
	node[1]->left = node[3];
//	node[1]->right = node[4];
//	node[2]->left = node[5];
//	node[2]->right = node[6];
	Solution sol;
	cout << sol.countNodes(node[0]) << endl;
	return 0;
}
