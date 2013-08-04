#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++) {
		int n, u;
		double d;
		scanf("%lf", &d);
		scanf("%d", &u);
		scanf("%d", &n);
		double bCost = d*u;
		int bP = 0;
		for(int j=1; j<=n;j++) {
			int m, c;
			double r;
			scanf("%d", &m);
			scanf("%lf", &r);
			scanf("%d", &c);
			double pM = r*u + (c*1.0)/m;
			if(pM < bCost) {
				bCost = pM;
				bP = j;
			}
		}
		printf("%d\n", bP);
	}
}
