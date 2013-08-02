#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	int d[100001][6];
	memset(d, 0, sizeof(d));
	d[2][1] = 1;
	d[3][1] = 2;
	for(int i=4; i<=100000; i++) {
		int nD = 0;
		int n = i;
		for(int j=2; j<=sqrt(i); j++) {
			bool isD = false;
			while(n%j==0) {
			  	isD = true;
				n = n/j;
			} 
			if(isD) 
				nD++;
		}	
		if(n!=1) 
			nD++;
		for(int p=0; p<6; p++) {
			if(p!=nD)
				d[i][p] = d[i-1][p];
		}
		if(nD <=5) {
			d[i][nD] = d[i-1][nD] + 1;
		}
	} 
/*	for(int m=0; m<=20; m++) {
		for(int h=0; h<6; h++) {
			printf("%d  ", d[m][h]);
		}
		printf("\n");
	} */
	for(int i=0; i<t; i++) {
		int a;
		int b;
		int k;
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &k);	
		printf("%d\n", d[b][k] - d[a-1][k]);
	}	
}
