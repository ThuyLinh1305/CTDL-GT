#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node *link;
};
Node *first;
int  init()
{
	first=NULL;
}
void Xuatphatuds()
{
	Node *p;
	p=first;
	while (p!=NULL)
	{
		cout<<p ->info<<endl;
		p=p->link;
	}
}
Node *Timphantu( int x)
{
	Node *p=first;
	while (p!=NULL) && (p->infor !=x)
		p=p->link;
	return p;
}
void Themdauds(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->link=first;
	first=p;
}
int Xoadauds()
{
	if(first!=NULL)
	{
		Node *p=first;
		first=first->link;
		delete p;
		return 1;
	}
	return 0;
	}
void Themcuoids(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->link=NULL;
	if(first==NULL)
		first=p;
	else
	{
		Node *q=first;
		while(q->link!=NULL)
			q=q->link;
		q->link=p;
}
}
int Xoacuoids()
{
	if(first!=NULL)
	{
		Node *p,*q;
		p=first; q=NULL;
		if(p!=NULL)
			while(p->link !=NULL)
			{
				q=p;
				p=p->link;
			}
			if(p!=first)
				q->link=NULL;
			else first=NULL;
			delete p;
			return 1;
	}
	return 0;
}
int main()
{
	cout<<"----------Baitap3-CHUONG 2--------\n";
	cout<<"1. Khai báo c?u trúc danh sách\n"
        <<"2. Vi?t th? t?c kh?i t?o danh sách r?ng\n"
        <<"3. Vi?t th? t?c xu?t các ph?n t? trong danh sách\n"
		<<"4. Vi?t th? t?c tìm m?t ph?n t? trong danh sách.\n"
		<<"5. Vi?t th? t?c thêm m?t ph?n t? vào ??u danh sách\n"
		<<"6. Vi?t th? t?c xóa m?t ph?n t? d?u danh sách.\n"
		<<"7. Vi?t th? t?c thêm m?t ph?n t? vào cu?i danh sách\n"
		<<"8. Vi?t th? t?c xóa m?t ph?n t? cu?i danh sách.\n"
		<<"9. Vi?t th? t?c tìm m?t ph?n t? trong danh sách. N?u tìm th?y, hãy xóa ph?n t? này\n"
		<<"---------Moi ban chon lenh de thuc thi-------\n";
	system("pause");
	return 0;
}