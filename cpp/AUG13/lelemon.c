#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
	int a[101];
	int size;
	int cur;
} Data;

int main() {
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++) {
		int n, m;
		scanf("%d", &n); scanf("%d", &m);
		int mr[m];
		for(int j=0; j<m; j++) {
			scanf("%d", (mr+j));
		}
		Data di[n];
		for(int j=0; j<n; j++) {
			int max = -1;
			int c;
			scanf("%d", &c);
			di[j].size = c-1;
			di[j].cur = 0;
			for(int k=0; k<c; k++) {
				int val;
				scanf("%d", &val);
				if(k==0) {
					di[j].a[k] = val;
				} else {
					int l = k-1;
					while(di[j].a[l]>val) {
						di[j].a[l+1] = di[j].a[l];
						l--;
					}
					di[j].a[l+1] = val;
				}
			}
		}
		long long int res = 0;
		for(int j=0; j<m; j++) {
			Data d = di[mr[j]];
			int cur = d.cur;
			int size = d.size;
			if(size>=0) {
				res += d.a[size];
				di[mr[j]].size--;
			}
		}
		printf("%lld\n", res);
	}
}
