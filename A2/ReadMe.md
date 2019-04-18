#A2 合并二叉树

##算法核心思想
主要运用了递归调用的算法思想。合并可以分为三个步骤，将两棵树的当前节点的数值相加，再将两棵树的左子树合并，再将两棵树的右子树合并。每个子树都是结构相同的二叉树，所以运用递归是完美的解决方案。

以下是算法核心代码
```
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
```

##运行截图
![运行截图](/screen_shot.jpg)

###构造树以及打印树的代码
1. 用于建立一颗二叉树
```
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
```

2. 用于按层次顺序输出一颗二叉树
```
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
```