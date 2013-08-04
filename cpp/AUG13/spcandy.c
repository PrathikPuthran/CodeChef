#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int t;
	scanf("%d", &t);
	for(int i=0;i<t; i++) {
		long long int n,k;
		scanf("%lld", &n);
		scanf("%lld", &k);
		if(k!=0) {
		    printf("%lld %lld\n", n/k, n%k);
		} else {
			printf("%lld %lld\n", 0LL, n);
		}
	}
}
