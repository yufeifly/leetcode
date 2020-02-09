#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> answer(n+1,0);
		answer[1] = 1;
		for(int i=2;i<=n;++i) {
			for(int j=1;j<=i;++j) {
				answer[i] += ((j == 1)? 1 : answer[j-1]) * ((i == j)? 1 : answer[i-j]);
			}
		}
		return answer[n];
    }
};

int main() {
	Solution sol;
	cout << sol.numTrees(3) << endl;
	return 0;
}
