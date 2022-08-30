#include <iostream>
#include <stdio.h>
using namspace std;
#define COUNT 10
//Khai bao cau truc cay nhi phan
struct Node {
	int info;
	Node* left;
	Node* right;
};
Node* root;

//Thu tuc tao cay rong
void tree_empty()
{
	root = NULL;
}

//Them phan tu vao cay khong dung de qui
void InsertNode(Node *&p, int x)
{
	if(p==NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else if (p->info > x)
			return InsertNode(p->left, x);
		else
			return InsertNode(p->right, x);
	}
}