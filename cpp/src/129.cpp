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
	vector<int> arr;
	int answer;

	void sum(TreeNode *root) {
		if(root != NULL) {
			arr.push_back(root->val);
			if(root->left == NULL && root->right == NULL) {
				answer += toint(arr);
			} else {
				if(root->left != NULL)
					sum(root->left);
				if(root->right != NULL)
					sum(root->right);
			} 
			arr.pop_back();
		} 
	}

   /*  int toint(vector<int> &arr) { */
		// int ret = 0;
		// int power = 1;
		
		// int st = 0;
		// for(int i=0;i<(int)arr.size();++i) {
			// if(arr[i] != 0) {
				// st = i;
				// break;
			// }
		// }

		// for(int i = (int)arr.size()-1;i>=st;--i) {
			// ret += power * arr[i];
			// if(i != st)
				// power *= 10;
		// }
		// return ret;
	/* } */
	int toint(vector<int> &arr) {
//		for(auto dig : arr) cout << dig << endl;
		int ret = 0;
		for(int i=0;i<(int)arr.size();++i) {
			ret = ret * 10 + arr[i];
		}
//		cout << "ret " << ret << endl;
		return ret;
	}

public:
    int sumNumbers(TreeNode* root) {
        answer = 0;
		sum(root);
		return answer;
    }
};


int main() {
	vector<int> vec = {1,2,3};
	TreeNode *node[3];
	for(int i=0;i<(int)vec.size();++i) {
		node[i] = new TreeNode(vec[i]);
	}
	node[0]->left = node[1];
	node[0]->right = node[2];
	Solution sol;
	cout << sol.sumNumbers(node[0]) << endl;
	return 0;
}
