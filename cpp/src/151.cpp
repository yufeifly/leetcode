#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int sz = (int)s.size();
        vector<string> vec;
        string answer = ""; 
        for(int i=0;i<sz;) {
            while(s[i]== ' ' && i < sz) ++i;
            int j = i;
            while(s[j] != ' ' && j < sz) ++j;
            --j;
			if(j >= i)
				vec.push_back(s.substr(i,j-i+1));
            i = j+1;
        }   
		int vec_sz = (int)vec.size();
        if(vec_sz > 0){ 
            answer += vec[vec_sz-1];
            for(int i=vec_sz-2;i>=0;--i) {
                answer += " " + vec[i];
            }   
        }                                                                                   
        return answer;
    }   
};

int main() {
    Solution sol;
    string s = "hello world! nihao    ";
    cout << sol.reverseWords(s) << endl;
    return 0;
}
