// A2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//定义树节点
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//通过完全二叉树的数组，建立一颗二叉链表。
TreeNode* buildTree(vector<int*> & nums) {
	if (nums.size() == 0) {
		return NULL;
	}
	TreeNode* root = new TreeNode(*nums[0]);
	vector<TreeNode*> nodes(nums.size());
	nodes[0] = root;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] == NULL) {
			continue;
		}
		nodes[i] = new TreeNode(*nums[i]);
		TreeNode* father = NULL;
		//子节点的父节点，在序号为奇数和偶数时情况不同。
		if (i % 2 == 1) {
			father = nodes[(i - 1) / 2];
			father->left = nodes[i];
		}
		else {
			father = nodes[(i - 1) / 2];
			father->right = nodes[i];
		}
	}
	return root;
}
//按层次顺序输出一颗二叉树。
void printTree(TreeNode* root) {
	cout << "按层次序输出：";
	if (root == NULL) {
		cout << "NULL" << endl;
		return;
	}
	TreeNode* curr = root;
	queue<TreeNode*> q;
	q.push(curr);
	while (!q.empty()) {
		curr = q.front();
		q.pop();
		if (curr) {
			TreeNode* left = curr->left;
			TreeNode* right = curr->right;
			q.push(left); q.push(right);
			cout << curr->val << " ";
		}
		else {
			cout << "NULL ";
		}
	}
	cout << endl;
}
//主体合并算法
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	//排除特殊情况。
	if (t1 == NULL && t2 != NULL) { return t2; }
	if (t2 == NULL && t1 != NULL) { return t1; }
	if (t1 == NULL && t2 == NULL) { return NULL; }
	//若左侧都不为空，则在左子树递归调用。
	if (t1->left != NULL && t2->left != NULL) {
		mergeTrees(t1->left, t2->left);
	}
	//若右侧都不为空，则在右子树递归调用。
	if (t1->right != NULL && t2->right != NULL) {
		mergeTrees(t1->right, t2->right);
	}
	//若左侧的左子树为空，右侧的左子树不为空，则将右侧的子树链给左边的子树。
	if (t1->left == NULL && t2->left != NULL) {
		t1->left = t2->left;
	}
	//若左侧的右子树为空，右侧的右子树不为空，则将右侧的子树链给左边的子树。
	if (t1->right == NULL && t2->right != NULL) {
		t1->right = t2->right;
	}
	//将数值合并
	t1->val = t1->val + t2->val;
	//以左边的子树作为结果子树，返回。
	return t1;
}

//该函数用来进行测试
void test(vector<int*> & v1, vector<int*> & v2) {
	cout << "左边的二叉树";
	TreeNode* t1 = buildTree(v1);
	printTree(t1);
	cout << endl;
	cout << "右边的二叉树";
	TreeNode* t2 = buildTree(v2);
	printTree(t2);
	cout << endl;
	TreeNode* root = mergeTrees(t1, t2);
	cout << "合并后的二叉树";
	printTree(root);
	cout << endl;
}

void test_1() {
	int o1[3] = { 1, 2, 3 };
	// 1, 2, 3
	vector<int*> v1 = { o1, o1 + 1, o1 + 2 };
	int o2[5] = { 2, 5, 7, 6, 8 };
	// 2, 5, 7, 6, NULL, 8, NULL
	vector<int*> v2 = { o2, o2 + 1, o2 + 2, o2 + 3, NULL, o2 + 4, NULL };
	test(v1, v2);
}

void test_2() {
	// NULL
	vector<int*> v1 = {};
	int o2[3] = { 1, 2, 3 };
	// 1, 2, 3
	vector<int*> v2 = { o2, o2 + 1, o2 + 2 };
	test(v1, v2);
}

void test_3() {
	int o1[3] = { 1, 2, 3 };
	// 1, 2, 3
	vector<int*> v1 = { o1, o1 + 1, o1 + 2 };
	int o2[3] = { 4, 5, 6 };
	// 4, 5, 6
	vector<int*> v2 = { o2, o2 + 1, o2 + 2 };
	test(v1, v2);
}

int main() {
	cout << "第一个测试样例：" << endl;
	test_1();
	cout << "第二个测试样例：" << endl;
	test_2();
	cout << "第三个测试样例：" << endl;
	test_3();
}


