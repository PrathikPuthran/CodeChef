#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int mi;
void dfs(int node, vector<int> *gp, bool *vis, int n, int *cost, int par) {
	if(vis[node]) {
		return;
	}
	vis[node] = true;
	if(cost[node]>=0) {
		mi = min(mi, cost[node]);
	}
	vector<int> cur = gp[node];
	for(int i=0; i<cur.size(); i++) {
		if(par != cur[i]) {
			dfs(cur[i], gp, vis, n, cost, i);
		}
	}
}

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	vector<int> gp[n+1];
	for(int i=0; i<m; i++) {
		int n1, n2;
		scanf("%d", &n1);
		scanf("%d", &n2);
		gp[n1].push_back(n2);
		gp[n2].push_back(n1);
	}
	int cost[n+1];
	for(int i=1; i<=n; i++) {
		scanf("%d", cost+i);
	}
	bool vis[n+1];
	vector<int> comp;
	memset(vis, 0, sizeof(vis));
	bool type2 = false;
	int nComp = 0;
	for(int i=1; i<=n; i++) {
		mi = 100000;
		if(!vis[i]) {
			nComp ++;
			dfs(i, gp, vis, n, cost, -1);
			if(mi == 100000) {
				type2 = true;
			} else {
				comp.push_back(mi);
			}
		}
	}
	if(type2 && nComp > 1) {
		cout << -1 << endl;
	} else {
		sort(comp.begin(), comp.end());	
		int t = 0;
		for(int i=1; i< comp.size(); i++) {
			t += comp[0] + comp[i]; 
		}
		cout << t << endl;
	}
}
