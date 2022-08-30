//chuyen sang he luc phan
//Ten: Vo Thuy Linh
//MSSV:2151053035
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
struct stacknode
{
	int item;
	stacknode* next;
};
struct stack
{
	stacknode* top;
};
int stackempty(struct stack* s);
stack* creatstack();
void disp(stack* s);
void pushstack(stack* s, int n);
int popstack(stack* s);

main()
{
	int n, m;
	stacknode* node;
	stack* s;
	s = creatstack();
	cout << "Nhap so tu nhien n:";
	cin >> n;
	while (n != 0)
	{
		m = n % 2;
		n = (n / 2);
		pushstack(s, m);
	}
	disp(s);
	getch();
}
//kiem tra Stack rong
int stackempty(struct stack* s)
{
	return(s->top == NULL);
}
//tao 1 Stack
stack* creatstack()
{
	stack* s;
	s = (stack*)malloc(sizeof(stack));
	s->top == NULL;
	return s;
}
void disp(stack* s)
{
	int m;
	stacknode* node;
	while (stackempty(s) != 1)
	{
		m = popstack(s);
		cout << m;
	}
}
void pushstack(stack* s, int n)
{
	stacknode* node;
	node = (stacknode*)malloc(sizeof(stacknode));
	node->item = n;
	node->next = NULL;
	if (s->top == NULL)
	{
		s->top = node;
	}
	else
	{
		node->next = s->top;
		s->top = node;
	}
}
int popstack(stack* s)
{
	stacknode* node;
	node = s->top;
	s->top = node->next;
	return node->item;
	free(node);

}