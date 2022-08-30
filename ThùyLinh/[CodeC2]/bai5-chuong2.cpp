#include <iostream>
using namespace std;

//5.1 Khai bao cau truc stack
#define MAX 100
int b[MAX];
int sp;
//5.2 Khai bao stack rong
void init(int b[], int& sp)
{
	sp = -1;
}

//5.3 Kiem tra stack rong
int isEmpty(int b[], int sp)
{
	if (sp == -1)
	{
		return 1;
	}
	return 0;
}

//5.4 Kiem tra stack day
int isFull(int b[], int sp)
{
	if (sp == MAX - 1)
	{
		return 1;
	}
	return 0;
}

//5.5 Them phan tu vao stack
int Push(int b[], int& x, int& sp)
{
	if (sp < MAX-1)
	{
		b[++sp] = x;
		return 1;
	}
	return 0;
}

//5.6 Xoa phan tu khoi stack
int Pop(int b[], int& sp, int& x)
{
	if (sp != -1)
	{
		x = b[sp--];
			return 1;
	}
	return 0;
}

//Xuat stack
void Process_stack(int b[], int sp)
{
	for (int i = 0; i < sp++; i++)
	{
		cout << b[i] << "<--";
		cout << endl;
	}
}


int main()
{
	int choice,sp,b[MAX],tam,x;
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
			init(b, sp);
			cout << "Stack rong vua duoc khai tao!\n";
			break;
		case 3: tam=isEmpty(b,sp);
			if (tam == 1)
			{
				cout << "Stack cua ban dang rong!\n";
			}
			else cout << "Stack cua ban da day!\n";
			break;
		case 4: tam = isFull(b, sp);
			if (tam == 1)
			{
				cout << "Stack cua ban da day!\n";
			}
			else cout << "Stack cua ban dang rong!\n";
			break;
		case 5: cout << "Nhap vao phan tu x ban muon them!\n";
			cin >> x;
			tam=Push(b, sp, x);
			if (tam == 1) {
				cout << "Them thanh cong!  "<<"x=  "<<x<<endl; 
				cout << "Stack sau them la:  \n";
				Process_stack(b, sp);
			}
			else { cout << "Them khong thanh cong!\n"; }
			break;
		case 6: tam = Pop(b, sp, x);
			if (tam == 1) { 
				cout << "Xoa thanh cong!" << "  Gia tri x= " << x << endl;
				cout << "Sau khi lay ra phan tu stack la:  \n";
				Process_stack(b, sp);
			}
			else { cout << "Xoa khong thanh cong!\n"; }
			break;
		case 7: Process_stack(b, sp);
			break;
		case 8: break;
		default:
			break;
		}
		
	} while (choice != 8);
	system("pause");
	return 0;
}