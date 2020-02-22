#include <iostream>
#include <vector>
#include <algorithm>

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
		if((int)prices.size() < 2) return 0;
		int buttom = 0, top = -1;
		int maxP = 0;
		vector<int> nprices;
		while(true) {
			buttom = find_buttom(prices, top+1);
			if(buttom == -1) {
				break;
			}
			top = find_top(prices,buttom+1);
			nprices.push_back(prices[buttom]);
			nprices.push_back(prices[top]);
			if(top == (int)prices.size()-1) {
				break;
			}
		}   
		//
		//print_vec(nprices);
		int nsz = (int)nprices.size();
		if(nsz < 2) return 0;
		if(nsz == 2) return nprices[1] - nprices[0];
		vector<vector<int>> dp(nsz,vector<int>(nsz,0));
		for(int i=0;i<nsz-1;i=i+2) {
			for(int j=i+1;j<nsz;j=j+2) {
				int high = nprices[j];
				int ind = j - 2;
				while(ind > i) {
					if(nprices[ind] > high) {
						high = nprices[ind];
					}
					ind = ind - 2;
				}
				dp[i][j] = high - nprices[i];
				//cout << i <<" " <<  j << " " << dp[i][j] << endl;
			}
		}
		//
		//print_dp(dp);
		for(int i=2;i<nsz-1;i=i+2) {
			int tmpL = 0;
			for(int k=0;k<i-1;k=k+2) {
				tmpL = max(dp[k][i-1], tmpL);
			}
			int tmpR = 0;
			for(int k=i;k<nsz;k=k+2) {
				tmpR = max(dp[k][nsz-1], tmpR);
			}
			maxP = max(maxP, tmpR + tmpL);
		}
		return maxP;
    }
	void print_dp(vector<vector<int>> & dp) {
		for(auto s : dp) {
			for(auto t : s) {
				cout << t << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void print_vec(vector<int> &vec) {
		for(auto elem : vec) {
			cout << elem << " ";
		}
		cout << endl;
	}
};

int main() {
	vector<int> vec = {5,2,3,0,3,5,6,8,1,5};
	Solution sol;
	cout << sol.maxProfit(vec) << endl;
	return 0;
}
