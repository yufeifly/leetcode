#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
	queue<TreeNode *> up;
	queue<TreeNode *> dn;
	vector<vector<int>> answer;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		if(root == NULL) return answer;
 		up.push(root);
		while(true){
			vector<int> tmp;
			while(!up.empty()) {
				TreeNode *node = up.front();
				up.pop();
				//cout << node->val << endl;
				tmp.push_back(node->val);
				if(node->left != NULL){
					dn.push(node->left);
				}
				if(node->right !=NULL){
					dn.push(node->right);
				}
			}
			answer.push_back(tmp);
			//cout << endl;
			if(dn.empty()) break;
			swap(up,dn);
		}
		reverse(answer.begin(),answer.end());
		return answer;
    }
};

int main(){
	TreeNode *root = new TreeNode(3);
	TreeNode *node1 = new TreeNode(9);
	TreeNode *node2 = new TreeNode(20);
	TreeNode *node3 = new TreeNode(15);
	TreeNode *node4 = new TreeNode(7);
	root->left = node1;
	root->right = node2;
	node2->left = node3;
	node2->right = node4;
	Solution sol;
	vector<vector<int>> answer = sol.levelOrderBottom(NULL);
	for(auto s : answer){
		for(auto t : s){
			cout << t << " ";
		}
		cout << endl;
	}
	return 0;
}
