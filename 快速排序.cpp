#include<stdlib.h>
#include<stdio.h>
void quicksort(int a[],int left, int right)
{
	int i, j, t, temp;
	if (left > right)
		return;
	temp = a[left]; //temp中存的就是基准数
	i = left;
	j = right;
	while (i != j)
	{
		//顺序很重要，要先从右往左找
		while (a[j] >= temp && i<j)
			j--;
		//再从左往右找
		while (a[i] <= temp && i<j)
			i++;
		//交换两个数在数组中的位置
		if (i<j)//当哨兵i和哨兵j没有相遇时
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//最终将基准数归位
	a[left] = a[i];
	a[i] = temp;
	quicksort(a, left, i - 1);//继续处理左边的，这里是一个递归的过程
	quicksort(a, i + 1, right);//继续处理右边的，这里是一个递归的过程
}
void ch_sort(int a[], int n)
{
	int temp, min, max;
	int j;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		if (min != i) {
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
	return;
}
int main(void)
{
	int num[30];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	//quicksort(num, 0, n - 1);
	ch_sort(num, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
	putchar('\n');
	return 0;
}