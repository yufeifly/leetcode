#include <iostream>
#include <string>
#include <vector>

using namespace std;


void addstring(vector<string> &vec){
	string s = "hello,yufei!";
	vec.push_back(s);
}

int main() {
	vector<string> vec;
	addstring(vec);
	for(auto e : vec) cout << e << endl;
	return 0;
}
