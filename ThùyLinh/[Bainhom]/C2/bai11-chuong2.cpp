//Bai 11 queue voi ds lien ket

#include <iostream>
using namespace std;
//Khao bao danh sach lien ket don
struct  Node
{
	Node  *link;
	int info;
};
Node* front;
Node* rear; 
//11.2 Khoi tao queue rong
int init()
{
	front = NULL;
	rear = NULL;
}

//11.3 Kiem tra queue rong
int isEmpty()
{
	if (front == NULL) return 1;
	return 0;
}

//11.4 Them phan tu vao queue
int Push( int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
	{
		front = p;
	}
	else
	{
		rear->link = p;
		rear = p;
	}
}

//11.5 Xoa phan tu trong queue
int Pop( int x)
{
	if (front != NULL)
	{
		Node* p = front;
		x = p->info;
		front = front->link;
		if (front == NULL)
		{
			rear = NULL;
			delete p;
		}
		return 1;
	}
	return 0;
}
//Xuat queue
void Process_queue()
{
	Node* p = front;
	do
	{
		cout << p->info << "<--";
		p = p->link;
	} while (p != NULL);
	cout << "\n";
}

int main()
{
	int choice, tam, x;
	system("cls");
	cout << "---------------Bai5-TH3-Chuong2----------------\n";
	cout << "1.Khai bao cau truc stack\n";
	cout << "2.Khai bao queue rong\n";
	cout << "3.Kiem tra queue rong\n";
	cout << "4.Kiem tra queue day\n";
	cout << "5.Them phan tu vao queue\n";
	cout << "6.Xoa phan tu vao queue\n";
	cout << "7.Xuat queue\n";
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
		case 2: cout << "Chon phan tu max cho queue\n";
			init();
			cout << "queue rong vua duoc khai tao!\n";
			break;
		case 3: tam = isEmpty();
			if (tam == 1)
			{
				cout << "queue cua ban dang rong!\n";
			}
			else cout << "queue cua ban da day!\n";
			break;
		case 5: cout << "Nhap vao phan tu x ban muon them!\n";
			cin >> x;
			tam = Push(x);
			if (tam == 1) {
				cout << "Them thanh cong!  " << "x=  " << x << endl;
				cout << "queue sau them la:  \n";
				Process_queue();
			}
			else { cout << "Them khong thanh cong!\n"; }
			break;
		case 6: tam = Pop(x);
			if (tam == 1) {
				cout << "Xoa thanh cong!" << "  Gia tri x= " << x << endl;
				cout << "Sau khi lay ra phan tu queue la:  \n";
				Process_queue();
			}
			else { cout << "Xoa khong thanh cong!\n"; }
			break;
		case 7: Process_queue();
			break;
		case 8: break;
		default:
			break;
		}

	} while (choice != 8);
	system("pause");
	return 0;

}

