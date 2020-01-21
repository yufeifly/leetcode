#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int left;		
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
 		int len = (int)gas.size();
		for(int i=0;i<len;++i) {
			left = 0;
			bool found = true;
			for(int j=0;j<len;++j){
				int locate = (i+j) % len;
				left += gas[locate];
				if(left < cost[locate]) {
					found = false;
					break;
				}
			}
			if(found) return i;
		}
		return -1;
    }
};


int main() {
	Solution sol;
	vector<int> gas = {1,2,3,4,5};
	vector<int> cost = {3,4,5,1,2};
	cout << sol.canCompleteCircuit(gas,cost) << endl;
	return 0;
}
