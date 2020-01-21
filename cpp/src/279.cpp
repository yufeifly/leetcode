#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
		vector<int> dp(n+1,0);
		for(int i=1;i<=n;++i) {
			dp[i] = i;
			for(int j=1;i-j*j>=0;++j) {
				dp[i] = min(dp[i],dp[i-j*j] + 1);
			}
		}
		return dp[n];
    }
};


//class Solution {
//private:
//    int _numSquares(int n,vector<int> &dp) {
//		int ed = -1;
//		for(int i=1;i<(int)dp.size();++i) {
//			if(dp[i] == 0) {
//				ed = i;break;
//			}
//		}
//		if(ed == -1 || ed > n) {
//			return dp[n];
//		}
//		for(int i=ed;i<=n;++i) {
//			dp[i] = i;
//			for(int j=1;i-j*j>=0;++j) {
//				dp[i] = min(dp[i],dp[i-j*j] + 1);
//			}
//		}
//		return dp[n];
//    }
//
//public:
//	int numSquares(int n) {
//		vector<int> dp(n+1,0);
//		int ret = n;
//		int i=1;
//		for(;i*i<=n;++i) {}
//		
//		for(i=i-1;i>=1;--i) {
//			int answer = 0;
//			int _n = n;
//			for(int j=i;j>=1;--j) {
//				int num = _n / (j*j);
//				if(num >= 1) {
//					answer += num;
//					_n = _n - num*j*j;
//				}
//				else {
//					answer += _numSquares(_n,dp);
//					break;
//				}
//			}
//			//
//			ret = min(ret,answer);
//		}	
//		return ret;
//	}
//};



int main() {
	Solution sol;
	cout << sol.numSquares(43) << endl;
	return 0;
}
