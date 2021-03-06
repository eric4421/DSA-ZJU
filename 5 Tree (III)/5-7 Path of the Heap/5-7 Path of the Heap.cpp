// 5-7 Path of the Heap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 05-树7 堆中的路径 （25 分）
// 将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。

#include "iostream"
#include "cstdio"

const int max_n = 1000;
const int max_m = 1000;
const int min_h = -10000;

int main()
{
	int m, n, h[max_n + 1];
	scanf("%d %d", &n, &m);
	h[0] = min_h;	// 小顶堆, 标志位不大于所有元素
	for (int i = 0; i < n;) {
		int input, j = ++i;
		scanf("%d", &input);
		for (; h[j / 2] > input; j /= 2) {
			h[j] = h[j / 2];
		}
		h[j] = input;
	}
	for (int i = 0; i < m; i++) {
		int j;
		scanf("%d", &j);
		printf("%d", h[j]);
		for (; j > 1; j /= 2) {
			printf(" %d", h[j / 2]);
		}
		printf("\n");
	}
    return 0; 
}

