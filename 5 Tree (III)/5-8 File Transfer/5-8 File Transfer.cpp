// 5-8 File Transfer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 05-树8 File Transfer （25 分）
// We have a network of computers and a list of bi-directional connections.
// Each of these connections allows a file transfer from one computer to another. 
// Is it possible to send a file from any computer on the network to any other?

// 提示: 并查集问题

#include "iostream"
#include "cstdio"

const int max_n = 10000;

void connect(int net[], int c1, int c2);
bool is_connect(int net[], int c1, int c2);
void _union(int net[], int root1, int root2);
int _find(int net[], int c);

int main() {
	int n, k = 0;
	int net[max_n + 1];	// suffix: host; value > 0: root's suffix; value < 0: -scale
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		net[i] = -1;
	
	while (1) {
		int c1, c2; char ch;
		scanf("%c", &ch);
		if (ch == 'S') break;
		scanf("%d %d", &c1, &c2);
		if (ch == 'I')
			connect(net, c1, c2);
		if (ch == 'C') {
			if (is_connect(net, c1, c2) == true)
				printf("yes\n");
			else
				printf("no\n");
		}
	}

	for (int i = 1; i <= n; i++)
		if (net[i] < 0) k++;
	if (k == 1)
		printf("The network is connected.");
	else
		printf("There are %d components.", k);

	return 0;
}

void connect(int net[], int c1, int c2) {
	if (is_connect(net, c1, c2) == true)
		return;
	int root1 = _find(net, c1);
	int root2 = _find(net, c2);
	_union(net, root1, root2);
}

bool is_connect(int net[], int c1, int c2) {
	int root1 = _find(net, c1);
	int root2 = _find(net, c2);
	if (root1 == root2)
		return true;
	return false;
}

void _union(int net[], int root1, int root2) {
	if (-net[root2] > -net[root1]) {
		net[root2] += net[root1];
		net[root1] = root2;
	}
	else {
		net[root1] += net[root2];
		net[root2] = root1;
	}
}

int _find(int net[], int c) {
	if (net[c] < 0)
		return c;
	else
		return net[c] = _find(net, net[c]);
}