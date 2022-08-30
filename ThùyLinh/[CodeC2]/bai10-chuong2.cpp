//Bai 10 Stack voi danh sach lien ket
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node* link;
};
Node* sp;
//10.2 Khoi tao stack rong
void init()
{
	sp = NULL;
}

//10.3 Kiem tra stack rong
int isEmpty()
{
	if (sp == NULL) return 1;
	else return 0;
}

//10.4 Them phan tu vao stack
int Push( int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
	return 1;
}

//10.5 Xoa phan tu trong stack
int Pop(int &x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = sp->link;
		delete p;
		return 1;
	}
	return 0;
}
//Xuat stack
void Process_stack()
{
	Node* p = sp;
	do
	{
		cout << p->info << "<--";
		p = p->link;
	}
	while (p != NULL);
	cout << "\n";
}

//10.6 Chuyen tu he thap phan sang nhi phan 



int main()
{
	int choice,tam,x;
	system("cls");
	cout << "---------------Bai5-TH3-Chuong2----------------\n";
	cout << "1.Khai bao cau truc stack\n";
	cout << "2.Khai bao stack rong\n";
	cout << "3.Kiem tra stack rong\n";
	cout << "4.Kiem tra stack day\n";
	cout << "5.Them phan tu vao stack\n";
	cout << "6.Xoa phan tu vao stack\n";
	cout << "7.Xuat stack\n";
	cout << "8.Ket thuc\n";
	cout << "------------------------------------------------\n";
	do
	{
		cout << "Moi ban chon chuong trinh de thuc thi\n";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Ban da khai bao cau truc stack xong !\n";
			break;
		case 2: cout << "Chon phan tu max cho stack\n";
			init();
			cout << "Stack rong vua duoc khai tao!\n";
			break;
		case 3: tam = isEmpty();
			if (tam == 1)
			{
				cout << "Stack cua ban dang rong!\n";
			}
			else cout << "Stack cua ban da day!\n";
			break;
		case 5: cout << "Nhap vao phan tu x ban muon them!\n";
			cin >> x;
			 tam= Push(x);
			if (tam == 1) {
				cout << "Them thanh cong!  " << "x=  " << x << endl;
				cout << "Stack sau them la:  \n";
				Process_stack();
			}
			else { cout << "Them khong thanh cong!\n"; }
			break;
		case 6: tam = Pop(x);
			if (tam == 1) {
				cout << "Xoa thanh cong!" << "  Gia tri x= " << x << endl;
				cout << "Sau khi lay ra phan tu stack la:  \n";
				Process_stack();
			}
			else { cout << "Xoa khong thanh cong!\n"; }
			break;
		case 7: Process_stack();
			break;
		case 8: break;
		default:
			break;
		}

	} while (choice != 8);
	system("pause");
	return 0;

}