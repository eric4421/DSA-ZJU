// 02-线性结构2 一元多项式的乘法与加法运算 （20 分）
// 设计函数分别求两个一元多项式的乘积与和。输入输出顺序都是指数递减。指数绝对值均为不超过1000的整数。

#include "iostream"
#include "cstdio"
#include "cmath"

#define N 2002

void poly_input(int *p_p, int *p_n, int &n);
void poly_print(int *res_p, int *res_n);

int main() {
	int n1, n2;
	// 每个多项式按指数正负分为两组
	int p1_p[N] = { 0 };
	int p1_n[N] = { 0 };
	int p2_p[N] = { 0 };
	int p2_n[N] = { 0 };
	int res1_p[N] = { 0 };
	int res1_n[N] = { 0 };
	int res2_p[N] = { 0 };
	int res2_n[N] = { 0 };

	// input polynomials
	poly_input(p1_p, p1_n, n1);
	poly_input(p2_p, p2_n, n2);

	// poly_multiply
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			res1_p[i + j] += p1_p[i] * p2_p[j];
			res1_n[i + j] += p1_n[i] * p2_n[j];
			if (i > j) {
				res1_p[i - j] += p1_p[i] * p2_n[j];
				res1_n[i - j] += p1_n[i] * p2_p[j];
			}
			else {
				res1_p[j - i] += p1_n[i] * p2_p[j];
				res1_n[j - i] += p1_p[i] * p2_n[j];
			}
		}
	}

	// poly_addition
	for (int i = 0; i < N; i++) {
		res2_p[i] += p1_p[i];
		res2_n[i] += p1_n[i];
	}
	for (int i = 0; i < N; i++) {
		res2_p[i] += p2_p[i];
		res2_n[i] += p2_n[i];
	}
	
	// print results
	poly_print(res1_p, res1_n);
	poly_print(res2_p, res2_n);
	return 0;
}

void poly_input(int *p_p, int *p_n, int &n) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int coef, exp;
		scanf("%d", &coef);
		scanf("%d", &exp);
		if (exp > 0)
			p_p[exp] = coef;
		else
			p_n[-exp] = coef;
	}
}

void poly_print(int *res_p, int *res_n) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (res_p[i] != 0 || res_n[i] != 0) {
			count++;
		}
	}
	if (count == 0) {
		printf("0 0\n");
	}
	else {
		for (int i = N - 1; i >= 0; i--) {
			if (res_p[i] != 0) {
				printf("%d %d", res_p[i], i);
				count--;
				if (count > 0)
					printf(" ");
			}
		}
		for (int i = 0; i < N; i++) {
			if (res_n[i] != 0) {
				printf("%d %d", res_n[i], i);
				count--;
				if (count > 0)
					printf(" ");
			}
		}
		printf("\n");
	}
}