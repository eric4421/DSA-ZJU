// 04-树4 是否同一棵二叉搜索树 （25 分）
// 对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "vector"

using namespace std;

const int MAXN = 10;

typedef struct node {
	int data;
	node* left;
	node* right;
	bool checked;
}node;

typedef node* bst;

void create_bst(bst &T, int N);
bool insert_bst(bst &T, int _data);
bool is_same_bst(bst T, int N);
bool search_bst(bst T, int _data);
void clear_checked(bst &T);
void free_bst(bst &T);


int main(){
	int N, L;
	vector<bool> result;
	while(1){
		bst T = NULL;
		scanf("%d", &N);
		if (N == 0)
			break;
		scanf("%d", &L);
		create_bst(T, N);
		for (int i = 0; i < L; i++) {
			result.push_back(is_same_bst(T, N));
			clear_checked(T);
		}
		free_bst(T);
	}
	for (int i = 0; i < result.size() - 1; i++) {
		if (result[i] == true)
			printf("Yes\n");
		else
			printf("No\n");
	}
	if (result[result.size() - 1] == true)
		printf("Yes");
	else
		printf("No");
	return 0;
}

void create_bst(bst &T, int N) {
	int _data;
	for (int i = 0; i < N; i++) {
		scanf("%d", &_data);
		insert_bst(T, _data);
	}
}

bool insert_bst(bst &T, int _data) {
	if (T == NULL) {
		T = (bst)malloc(sizeof(node));
		T->data = _data;
		T->left = T->right = NULL;
		T->checked = false;
		return true;
	}
	else {
		if (_data == T->data)
			return false;
		else if (_data < T->data)
			return insert_bst(T->left, _data);
		else
			return insert_bst(T->right, _data);
	}
}

bool is_same_bst(bst T, int N) {
	int _data;
	bool flag;
	scanf("%d", &_data);
	// check root
	if (_data != T->data)
		flag = false;
	else {
		T->checked = true;
		flag = true;
	}
	// search for other data in BST
	for (int i = 1; i < N; i++) {
		scanf("%d", &_data);
		if ((flag == true) && (search_bst(T, _data) == false))
			flag = false;
	}
	return flag;
}

bool search_bst(bst T, int _data){
	if (T->checked == true) {
		if (_data < T->data)
			return search_bst(T->left, _data);
		else if (_data > T->data)
			return search_bst(T->right, _data);
		else
			return false;
	}
	else
		if (_data == T->data) {
			T->checked = true;
			return true;
		}
	return false;
}

void clear_checked(bst & T){
	if (T->left) clear_checked(T->left);
	if (T->right) clear_checked(T->right);
	T->checked = false;
	return;
}

void free_bst(bst & T) {
	if (T->left) free_bst(T->left);
	if (T->right) free_bst(T->right);
	free(T);
	return;
}
