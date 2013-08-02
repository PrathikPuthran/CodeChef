#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

double eps = 10e-6;
bool isCol(int x1, int y1, int x2, int y2, int x3, int y3) {
	if(x1 == x2 && x2 == x3) {
		return true;
	} else if((x1==x2) && (x2 != x3)) {
		return false;
	} else if((x1==x3) && (x1 != x2)) {
		return false;
	} else if((x2==x3) && (x1!=x2)) {
		return false;
	}
	double m1 = ((y2-y1)*1.0)/(x2-x1);
	double m2 = ((y3-y2)*1.0)/(x3-x2);
	if(m1 == m2 || abs(m1-m2) < eps) {
		return true;
	}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++) {
		int n;
		scanf("%d", &n);
		int* x = new int[n];
		int* y = new int[n];
		for(int p=0; p<n; p++) {
			scanf("%d", x+p);
			scanf("%d", y+p);
		}	
		int tot = 0;
		int val = 0;
	    for(int p=0; p<n; p++) {
			for(int q=p+1; q<n; q++) {
				for(int r=q+1; r<n; r++) {
					for(int s=0; s<n; s++) {
						if(s!=p && s!=q && s!=r) {
							tot++;
							if(!isCol(x[p], y[p], x[q], y[q], x[r], y[r])) {
								double x1 = ((double)(x[p] + x[q]))/2.0;
								double y1 = ((double)(y[p] + y[q]))/2.0;
								double x2 = ((double)(x[q] + x[r]))/2.0;
								double y2 = ((double)(y[q] + y[r]))/2.0;
								double m1 = ((double)(y[q]-y[p]))/((x[q]-x[p])*1.0);
								double m2 = ((double)(y[r]-y[q]))/((x[r]-x[q])*1.0);
								double x0, y0;
								if(m1 == 0 || m2 == 0) {
									if(m1 ==0 ) {
										x0 = x1;
										m2 = -1/m2;
										y0 = y2 + m2*(x0-x2);
									} else {
										x0 = x2;
										m1 = -1/m1;
										y0 = y1 + m1*(x0-x1);
									}
								} else {
									m1 = -(double)1/m1;
									m2 = -(double)1/m2;
									x0 = ((y2-y1) + m1*x1 - m2*x2)/(m1-m2);
									y0 = y1 + m1*(x0-x1);
								}
								double r = (x0-x[p])*(x0-x[p]) + (y0-y[p])*(y0-y[p]);
								double dt = (x0-x[s])*(x0-x[s]) + (y0-y[s])*(y0-y[s]);
								if(dt<=(r+eps))
									val++;
							}
						}
					}
				}
			}
		}
		printf("%.17lf\n", (val*1.0)/tot); 
		delete x;
		delete y;
	}
}
