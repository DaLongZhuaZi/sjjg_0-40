//调试运行闪退

#include<iostream>
#include<queue>

using namespace std;

int i = 0;
int Count = 0;
class binarytree;
class TreeNode
{
	friend class binarytree;
public:
	void getleft(TreeNode * p)
	{
		leftnode = p;
	}
	void getright(TreeNode *p)
	{
		rightnode = p;
	}
	TreeNode(char a) { data = a; leftnode = NULL; rightnode = NULL; };
	char data;
	TreeNode *leftnode;
	TreeNode *rightnode;
};
class binarytree
{
public:
	void getroot(TreeNode* p)
	{
		root = p;
	}

	void leveloder();											//后序遍历
	void leveloder(TreeNode* current);
	void preinsert(TreeNode* &current, char* arr);
	TreeNode * root;
};
void binarytree::leveloder()
{
	if (root)
	leveloder(root);
}
void binarytree::leveloder(TreeNode* current)
{
	
	if (current&&current->leftnode==NULL&&current->rightnode==NULL)Count++;
	
	if(current->leftnode) leveloder(current->leftnode);
	if(current->rightnode) leveloder(current->rightnode);
}
void binarytree::preinsert(TreeNode* &current, char* arr)		//注意这里的是引用地址
{
	if (arr[i] == '#')
	{
		current = NULL;
		i++;
	}
	else
	{
		current = new TreeNode(arr[i]);
		i++;
		preinsert(current->leftnode, arr);
		preinsert(current->rightnode, arr);
	}
}

int main()
{
	binarytree Tree;
	char arr[1000];
	cin >> arr;
	Tree.preinsert(Tree.root, arr);
	Tree.leveloder();
	cout<<Count;
	return 0;
}

