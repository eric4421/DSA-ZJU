// 6-1 Connected Set.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 06-图1 列出连通集 （25 分）
// 给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。

#include "iostream"
#include "cstdio"
#include "queue"

using namespace std;
const int max_n = 10;
int G[max_n][max_n];
bool visited[max_n];
int N, E;

void DFS(int v){
	visited[v] = true;
	printf("%d ", v);
	for (int i = 0; i < N; i++) {
		if (visited[i] == false && G[v][i] == 1)
			DFS(i);
	}
}

void BFS(int v) {
	queue<int> _queue;
	visited[v] = true;
	_queue.push(v);
	while (!_queue.empty()) {
		int v1 = _queue.front();
		_queue.pop();
		printf("%d ", v1);
		for (int i = 0; i < N; i++) {
			if (visited[i] == false && G[v1][i] == 1) {
				_queue.push(i);
				visited[i] = 1;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &E);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			G[i][j] = 0;

	for (int i = 0; i < E; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		G[v1][v2] = G[v2][v1] = 1;
	}

	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			printf("{ ");
			DFS(i);
			printf("}\n");
		}
	}

	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			printf("{ ");
			BFS(i);
			printf("}\n");
		}
	}
	
	return 0;
}