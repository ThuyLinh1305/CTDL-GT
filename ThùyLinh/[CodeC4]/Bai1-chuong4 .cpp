//Bai 1-Chuong 4, Cay nhi phan
#include <iostream>
#include <stdio.h>
using namespace std;

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

//Them phan tu vao cay dung de qui
int Insert_Node_Recursive(int x, Node *q)
{
	if (q->info == x)
		return 0;
	else if(q->info>x)
	{
		if (q->left == NULL)
		{
			Node* p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->left = p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x, q->left);
	}
	else
	{
		if (q->right == NULL)
		{
			Node* p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->right = p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x, q->right);
	}
}

void InsertNode(Node*& p, int x)
{
	if (p == NULL)
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

//Tim phan tu trong cay
Node *Search(Node *p,int x)
{
	if(p!=NULL)
	{
		if (p->info == x)
			return p;
		else
			if (x > p->info)
				return Search(p->right, x);
			else 
				return Search(p->left, x);
	}
		return NULL;
}

//Xoa mot nut trong cay dung de qui
void SearchStandFor(Node*& p, Node*& q)
{
	if (q->left == NULL)
	{
		p->info == q->info;
		p = q;
		q = q->right;
	}
	else
		SearchStandFor(p, q->left);
}
int Delete(Node *&T, int x)
{
	if (T = NULL) return 0;
	if(T->info==x)
	{
		Node* p = T;
		if (T->left == NULL) //Bac 1
			T = T->right;
		else if (T->right == NULL) //Bac 1
			T = T->left;
		else //co 2 con
			SearchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)return Delete(T->right, x);
	if (T->info > x)return Delete(T->left, x);

}
//Tim theo LNR
void DuyetLNR(Node *p)
{
	if (p != NULL)
	{
		DuyetLNR(p->left);
		cout << p->info <<" ";
		DuyetLNR(p->right);

	}
}
//Tim theo LRN
void DuyetLRN(Node *p)
{
	if (p != NULL)
	{
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout << p->info << "";

	}
}
//Tim theo NLR
void DuyetNLR(Node* p)
{
	if (p != NULL)
	{
		cout << p->info << "";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}

void print2DUtil(Node*p, int space)
{
	//Base case
	if (p == NULL)
		return;
	//increase distance between levels
	space += COUNT;
	//process right child first
	print2DUtil(p->right, space);
	//print current node after space
	//count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";
	//process left child
	print2DUtil(p->left, space);
}
//wrapper over prinr2DUtil()
void Process_Tree()
{
	//pass initial space count as0
	print2DUtil(root, 0);
}
//MAIN
int main()
	{
	int choice;
	int x,i;
	Node* p;
	cout << "---------------------------Bai1-Chuong 4-Cay nhi phan----------------------------\n";
	cout << "1.Khai bao cau truc cay nhi phan\n";
	cout << "2.Thu tuc them phan tu vao cay nhi phan\n";
	cout << "3.Thu tuc tim phan tu trong cay\n";
	cout << "4.Thu tuc xoa mot nut trong cay\n";
	cout << "5.Duyet theo thu tu LNR\n";
	cout << "6.Duyet theo thu tu NLR\n";
	cout << "7.Duyet theo LRN\n";
	cout << "8.Xuat cay nhi phan tim kiem\n";
	cout << "9.Ket thuc\n";
	cout << "----------------------------------------------------------------------------------\n";
	do {
		cout << "Nhap vao chuong trinh ban muon thuc hien\n";
		cin >> choice;
		switch (choice)
		{
		case 1: tree_empty();
			cout << "Cay nhi phan rong vua duoc khoi tao\n";
			break;
		case 2:
			cout << "Nhap vao gia tri muon them\n";
			cin >> x;
			InsertNode(root, x);
			cout << "Cay nhi phan tim kiem sau khi them: \n";
			Process_Tree();
			break;
		case 3:
			cout << "Nhap vao x can tim \n";
			cin >> x;
			p = Search(root, x);
			if (p != NULL)
				cout << "Tim thay x= " << x << "trong cay nhi phan tim kiem" << endl;
			break;
		case 4:
			cout << "Nhap vao x can xoa:  \n";
			cin >> x;
			i = Delete(root, x);
			if (i == 0)
				cout << "Khong tim thay x= " << x << "de xoa !"<< endl;
			else
		case 5:
			cout << "Cay tim kiem sau khi duyet theo LNR la: \n";
			DuyetLNR(root);
			break;
		case 6:
			cout << "Cay tim kiem sau khi duyet theo LNR la: \n";
			DuyetNLR(root);
			break;
		case 7:
			cout << "Cay tim kiem sau khi duyet theo LNR la: \n";
			DuyetLRN(root);
			break;
		case 8:
			cout << "Cay nhi phan tim kiem:  \n";
			Process_Tree();
			break;
		case 9:
			cout << "--------------GOOD BYE !!!---------------------\n";
			break;
		default:
			break;
		
		}
	} while (choice != 9);
	system("pause");
	return 0;
}
