#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;


int main() {
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		string s1, s2;
		cin >> s1;
		cin >> s2;
		int l;
		cin >> l;
		for(int p=1; p<=l; p++) {
			int co = 0;
		    for(int k=0; k<=s1.size() - p; k++) {
				string sub = s1.substr(k, p);
				int pos = 0;
				while((pos=s2.find(sub, pos)) != string::npos) {
					co++;
					pos = pos + 1;
				}
			}
			if(p!=l) {
				printf("%d ", co);
			} else {
				printf("%d\n", co);
			}
		}
	}
}
