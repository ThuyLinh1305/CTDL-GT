#include <iostream>
using namespace std;

//7.1 Khai bao cau truc queue
#define MAX 100
int a[MAX];
int front, rear;

//7.2 Khai bao queue rong
void init(int a[], int& front, int& rear)
{
	front = NULL;
	rear = NULL;
}

//7.3 Kiem tra queue rong
int isEmpty()
{
	if (front == rear)
	{
		return 1;
	}
	return 0;
}

//7.4 Kiem tra queue day
int isFull()
{
	if ((front == 0 &&front== MAX-1)||(front-rear==1 ))
	{
		return 1;
	}
	return 0;
}

//7.5 Them phan tu vao queue
int Push(int a[],int &front, int &rear, int x)
{
	if (rear - front == MAX - 1)
		return 0;
	else
	{
		if (front == -1) front = 0;
		if (rear == MAX - 1)
		{
			for (int i = front; i <= rear; i++)
			{
				a[i - front] = a[i];
				rear = MAX - 1 - front;
				front = 0;
			}
			a[++rear] = x;
		}
		return 1;
	}
}
//7.6 Xoa phan tu trong queue
int Pop(int a[], int& front, int& rear, int x)
{
	if ( front ==- 1)
		return 0;
	else
	{
		x = a[front++];
		if (front>rear)
		{
			front = -1;
			rear = -1;
	    }
		return 1;
	}
}
//Xuat queue
void Process_queue(int a[], int f, int r)
{
	cout << "front= " << f << "\t" << "rear= " << r << endl;
	if(f<=r && f!=-1)
	{
		cout << "<--";
		for (int i = f; i < r + 1; i++)
		{
			cout << a[i];
		}
		cout<<endl;
	}
}




int main1()
{
	int choice, front, rear,bien,x;
	cout << "-----------bai7-TH3-chuong2-------------\n";
	cout << "1.Khai bao cau truc queue\n";
	cout << "2.Khai bao queue rong\n";
	cout << "3.Kiem tra queue rong\n";
	cout << "4.Kiem tra queue day\n";
	cout << "5.Them phan tu vao queue\n";
	cout << "6.Xoa phan tu ra khoi queue\n";
	cout << "7.Ket thuc\n";
	cout << "-----------------------------------------\n";
	do
	{
		cout << "Moi ban chon chuong trinh de thuc thi\n";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Ban da khao bao cau truc queue thanh cong!\n";
			break;
		case 2: cout << "Nhap vao lan luot gia tri front va rear cua queue!\n";
			cin >> front >> rear;
			init(a, front, rear);
			cout << "Khai bao queue rong thanh cong!\n";
			break;
		case 3: bien=isEmpty();
			if (bien == 1)
			{
				cout << "Queue cua ban dang rong!\n";
			}
			else cout << "Queue cua ban da day!\n";
			break;
		case 4: bien = isFull();
			if(bien==0)
			{
				cout << "Queue cua ban da day!\n";
			}
			else cout << "Queue cua ban dang rong!\n";
			break;
		case 5:cout << "Nhap vao phan tu x de them vao queue!\n";
			cin >> x;
			bien = Push(a, front, rear,x);
			if (bien == 0)
			{
				cout << "Them vao khong thanh cong vi queue cua ban da day!\n";
			}
			else cout << "Them thanh cong!\n";
			break;
		case 6: bien = Pop(a, front, rear, x);
			if (bien == 0) cout << "Xoa khong thanh cong vi stack ban dang rong!\n";
			else cout << "Xoa thanh cong!\n";
			break;
		case 7: Process_queue(a, front,rear);
			break;
		default:
			break;

	}
	} while (choice != 7);
	system("pause");
	return 0;
}