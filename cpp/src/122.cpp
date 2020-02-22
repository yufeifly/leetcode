#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int find_buttom(vector<int> &prices, int i) {
		while(i+1 <(int)prices.size() && prices[i+1] <= prices[i]) ++i;
		if(i+1 == (int)prices.size()) return -1;
		return i;
	}
	
	int find_top(vector<int> &prices, int i) {
		while(i+1 <(int)prices.size() && prices[i+1] >= prices[i]) ++i;
		return i;
	}
public:
    int maxProfit(vector<int>& prices) {
		int maxP = 0;
		int buttom = 0, top = -1;
		if((int)prices.size() <= 0) return 0;
		while(true) {
			buttom = find_buttom(prices, top+1);
			if(buttom == -1) return maxP;
			top = find_top(prices, buttom+1);
			maxP += prices[top] - prices[buttom];
			if(top == (int)prices.size()-1) {
				return maxP;
			}
		}
		return maxP;
    }
};

int main() {
	vector<int> vec = {7,6,4,3,1};
	Solution sol;
	cout << sol.maxProfit(vec) << endl;
	return 0;
}
