#include<stdio.h>
int fun(int m, int n)
{
	int t;
	if (m < n) {
		t = m;
		m = n;
		n = t;
	}
	while (n) {
		t = m % n;
		m = n;
		n = t;
	}
	return m;
}
int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	int result = fun(a, b);
	printf("%d %d", result, a*b / result);
	return 0;
}