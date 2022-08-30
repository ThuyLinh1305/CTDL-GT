//MSSV:2151053035
//Ten: Vo Thuy Linh

#include <iostream.h>
#include <stdlib.h>
#define max 100
typedef struct {
    int n;
    char a;
    char b;
    char c;
}nhom;
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
    if (sp < MAX - 1)
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

typedef nhom elem;
void main()
{
    stack s;
    nhom bo;
    char A;
    char B;
    char C;
    int N;
    int m;
    cout << "Nhap so: "; cin >> m;
    createstack(s);
    bo.n = m; bo.a = 'A'; bo.b = 'B'; bo.c = 'C';
    push(s, bo);
    do
    {
        pop(s, bo);
        A = bo.a; B = bo.b; C = bo.c;
        if (bo.n == 1)
            cout << "\nChuyen " << bo.a << " qua " << bo.c;
        else
        {
            N = bo.n;
            bo.n = N - 1; bo.a = B; bo.b = A; bo.c = C;
            push(s, bo);
            bo.n = 1; bo.a = A; bo.b = ' '; bo.c = C;
            push(s, bo);
            bo.n = N - 1; bo.a = A; bo.b = C; bo.c = B;
            push(s, bo);
        }
    } while (!emptystack(s));

}