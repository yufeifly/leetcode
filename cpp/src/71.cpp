#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	vector<string> elem;
	string _path;
	int my_find(char ch,int pos) {
		for(int i = pos;i<(int)_path.size();++i) {
			if(_path[i] == ch) return i;
		}
		return -1;
	}
public:
    string simplifyPath(string path) {
   		int i = 0;
		_path = path;
		int sz = (int)path.size();
		int pos = 0;
		while(i<sz) {
			if(path[i] == '/') {
				if(i+1 < sz && path[i+1] != '/'){
					if((pos = my_find('/',i+1)) != -1) {
						string str = path.substr(i+1,pos-i-1);
						elem.push_back(str);
						i = pos;
					} else {
						elem.push_back(path.substr(i+1));
						i = sz;
					}
				}
				else ++i;
			}
			else ++i;
		}
		//
		//printvec();
		//
		i = 0;
		while(i < (int)elem.size()) {
			if(elem[i] == "."){
				elem.erase(elem.begin()+i);
			} else if(elem[i] == "..") {
				if(i == 0) {
					elem.erase(elem.begin()+i);
				} else {
					elem.erase(elem.begin()+i-1,elem.begin()+i+1);
					--i;
				}
			} else {
				++i;
			}
		}
		//printvec();
		string answer = "";
		if((int)elem.size() == 0) answer += "/";
		for(auto s : elem) {
			answer += "/" + s;
		}
		//
		//
		return answer;
    }
	void printvec(){
		for(auto s : elem) {
			cout << s << endl;
		}
	}
};

int main() {
	Solution sol;
	cout << sol.simplifyPath("/a/../../b/../c//.//") << endl;
	return 0;
}
