#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, d;
	scanf("%d", &n);
	scanf("%d", &d);
	int a[n];
	for(int i=0; i<n; i++) {
		scanf("%d", (a+i));
	}
	sort(a, a+n);
	int i=1;
	int c= 0;
	while(i<n) {
		if(a[i]-a[i-1] <=d) {
			c++;
			i = i+2;
		} else {
			i++;
		}
	}
	printf("%d\n", c);
}
