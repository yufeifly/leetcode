#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//private:
//	bool same_sign(int a,int b) {
//		return (a > 0 && b >0) || (a<0 && b<0);
//	}
//public:
//    int maxProduct(vector<int>& nums) {
//		int sz = (int)nums.size();
//        vector<int> dpmax(sz,0);
//		vector<int> dpmin(sz,0);
//		dpmax[0] = nums[0];
//		dpmin[0] = nums[0];
//		
//		int maxV = nums[0];
//
//		for(int i=1;i<sz;++i) {
//			if(nums[i] == 0) {
//				dpmax[i] = 0;
//				dpmin[i] = 0;
//			}
//			if(dpmax[i-1] == 0 && dpmin[i-1] == 0) {
//				if(nums[i] > 0) {
//					dpmax[i] = nums[i];
//					dpmin[i] = 0;
//				} else if(nums[i] < 0){
//					dpmax[i] = 0;
//					dpmin[i] = nums[i];
//				} 
//			}
//			else if(dpmax[i-1] == 0) {
//				if(nums[i] > 0) {
//					dpmax[i] = nums[i];
//					dpmin[i] = nums[i] * dpmin[i-1];
//				} else if(nums[i] < 0) {
//					dpmax[i] = nums[i] * dpmin[i-1];
//					dpmin[i] = nums[i];
//				}
//			} 
//			else if(dpmin[i-1] == 0) {
//				if(nums[i] > 0) {
//					dpmax[i] = nums[i] * dpmax[i-1];
//					dpmin[i] = 0;
//				} else if(nums[i] < 0) {
//					dpmax[i] = 0;
//					dpmin[i] = nums[i] * dpmax[i-1];
//				}
//			}
//			else if(same_sign(nums[i],dpmax[i-1]) && same_sign(nums[i],dpmin[i-1])) {
//				dpmax[i] = max(nums[i] * dpmax[i-1], nums[i]*dpmin[i-1]);
//				dpmin[i] = nums[i];
//			} else if(!same_sign(nums[i],dpmax[i-1]) && same_sign(nums[i],dpmin[i-1])){
//				dpmax[i] = nums[i] * dpmin[i-1];
//				dpmin[i] = nums[i] * dpmax[i-1];
//			} else if(same_sign(nums[i],dpmax[i-1]) && !same_sign(nums[i],dpmin[i-1])){
//				dpmax[i] = nums[i] * dpmax[i-1];
//				dpmin[i] = nums[i] * dpmin[i-1];
//			} else if(!same_sign(nums[i],dpmax[i-1]) && !same_sign(nums[i],dpmin[i-1])) {
//				dpmax[i] = nums[i];
//				dpmin[i] = min(nums[i]*dpmax[i-1], nums[i]*dpmin[i-1]);
//			}
//			maxV = max(maxV,dpmax[i]);
//		}
//		return maxV;
//    }
//};

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int sz = (int)nums.size();
        vector<int> dpmax(sz,0);
		vector<int> dpmin(sz,0);
		dpmax[0] = nums[0];
		dpmin[0] = nums[0];
		
		int maxV = nums[0];
		for(int i=1;i<sz;++i) {
			int a = nums[i] * dpmax[i-1];
			int b = nums[i] * dpmin[i-1];
			if(a > b) {
				dpmax[i] = max(a,nums[i]);
				dpmin[i] = min(b,nums[i]);
			} else {
				dpmax[i] = max(b,nums[i]);
				dpmin[i] = min(a,nums[i]);
			}
			maxV = max(maxV,dpmax[i]);
		}
		return maxV;
	}
};

int main() {
	Solution sol;
	vector<int> vec = {1,-3,2,0,-1,0,-2,-3,1,2,-3,2};
	cout << sol.maxProduct(vec) << endl;
	return 0;
}
