#include<mylib.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;

void conststroka(string s)
{
	int i=0;
	while(i<s.length())
	{
		putchar(s[i]);
		Sleep(40);
		i+=1;
		if(kbhit())
			break;
	}
}

void stroka(int j, string s)
{
	int i=0;
	while(i<s.length())
	{
		putchar(s[i]);
		Sleep(j);
		i+=1;
	}
}

void menu();

void frame()
{
	ukr(866);
	system("cls");
	textcolor(LightCyan);
	gotoxy(5,1);
	putchar(218);
	for(int i=0; i<68; i++)
		putchar(196);
	putchar(191);
    for(int i=2; i<20; i++)
    {
  		gotoxy(5,i);
  		putchar(179);
  		gotoxy(74,i);
		putchar(179);
    }
    gotoxy(5,20);
    putchar(192);
    for(int i=0; i<68; i++)
    	putchar(196);
    putchar(217);
    ukr(1251);
    gotoxy(32,3);
	stroka(15,"������� ������");
    gotoxy(8,5);
    stroka(15,"����: ����'�������� ������ ������� ������ ������� ����������");
    gotoxy(47,13);
    stroka(15,"������� ��. ��. ��-53");
    gotoxy(50,14);
    stroka(15,"������ ������");
    gotoxy(38,19);
    stroka(15,"2016");
    NatBudKlav(25,22);
    menu();
}

void task();

void work();

void menu()
{
	int item=0, ch;
	string MenuItem[3]={"��������� �������� �� ���������","������� �����������           ","����� � ��������               "};
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(37,1);
		printf("����");
		gotoxy(37,2);
		ukr(866);
		for(short i=0; i<4; i++)
			putchar(196);
		ukr(1251);
		for(int i=0; i<3; i++)
		{
			if (i==item)
			{
				textcolor(Black);
				textbackground(LightCyan);
	       		gotoxy(2,4+i);
				cout<<MenuItem[i];
				textbackground(Black);
	      	}
	      	else
	      	{
	      		textbackground(Black);
	      		textcolor(White);
	   			gotoxy(2,4+i);
				cout<<MenuItem[i];
			}
		}
		gotoxy(79,6);
		ch=getch();
		switch(ch)
		{
			case 80:
				item+=1;
				if(item>2)
					item=0;
				break;
			case 72:
				item-=1;
				if(item<0)
					item=2;
				break;
			case 13:
				if(item==0)
					work();
				if(item==1)
					task();
				if(item==2)
					return;
				break;
		}
	}
}

void work()
{
	int y, n, tmp;
	float **matrix, *b, *x, *diag, *r, *sum, max;
	bool flag;
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("����� ����������");
		gotoxy(31,2);
		ukr(866);
		for(short i=0; i<16; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"� ������������ ������ ���������� ������� ����������� �� ��������� ");
		textcolor(LightGreen);
		stroka(15,"ENTER");
		ukr(866);
		textcolor(LightCyan);
		gotoxy(1,5);
		putchar(218);
		for(short i=0; i<76; i++)
			putchar(196);
		gotoxy(78,5);
		putchar(191);
		gotoxy(1,6);
		putchar(179);
		gotoxy(78,6);
		putchar(179);
		gotoxy(1,7);
		putchar(192);
		for(short i=0; i<76; i++)
			putchar(196);
		gotoxy(78,7);
		putchar(217);
		gotoxy(3,6);
		ukr(1251);
		textcolor(White);
		y=scanf("%d",&n);
		if((y==0)||(n<2))
		{
			gotoxy(2,9);
			stroka(15,"�� ����� ���������� ����. �������� ����-����� ��������");
			Sleep(1000);
			fflush(stdin);
		}
		else
			break;
	}
	matrix=(float**)calloc(n,sizeof(float*));
	if(matrix==NULL)
		exit(-1);
	for(int i=0; i<n; i++)
	{
		matrix[i]=(float*)calloc(n,sizeof(float));
		if(matrix[i]==NULL)
			exit(-1);
	}
	b=(float*)calloc(n,sizeof(float));
	if(b==NULL)
		exit(-1);
	x=(float*)calloc(n,sizeof(float));
	if(x==NULL)
		exit(-1);
	r=(float*)calloc(n,sizeof(float));
	if(r==NULL)
		exit(-1);
	diag=(float*)calloc(n,sizeof(float));
	if(diag==NULL)
		exit(-1);
	sum=(float*)calloc(n,sizeof(float));
	if(sum==NULL)
		exit(-1);	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			while(true)
			{
				system("cls");
				textcolor(LightCyan);
				gotoxy(31,1);
				printf("����� ����������");
				gotoxy(31,2);
				ukr(866);
				for(short k=0; k<16; k++)
					putchar(196);
				ukr(1251);
				textcolor(White);
				gotoxy(2,4);
				stroka(15,"� ������������ ������ ���������� A");
				textcolor(LightRed);
				stroka(15,"[");
				textcolor(White);
				printf("%d",i+1);
				Sleep(15);
				textcolor(LightRed);
				stroka(15,"][");
				textcolor(White);
				printf("%d",j+1);
				Sleep(15);
				textcolor(LightRed);
				stroka(15,"]");
				textcolor(White);
				stroka(15," �� ��������� ");
				textcolor(LightGreen);
				stroka(15,"ENTER");
				ukr(866);
				textcolor(LightCyan);
				gotoxy(1,5);
				putchar(218);
				for(short k=0; k<76; k++)
					putchar(196);
				gotoxy(78,5);
				putchar(191);
				gotoxy(1,6);
				putchar(179);
				gotoxy(78,6);
				putchar(179);
				gotoxy(1,7);
				putchar(192);
				for(short k=0; k<76; k++)
					putchar(196);
				gotoxy(78,7);
				putchar(217);
				gotoxy(3,6);
				ukr(1251);
				textcolor(White);
				y=scanf("%f",&matrix[i][j]);
				if(y==0)
				{
					gotoxy(2,9);
					stroka(15,"�� ����� ���������� ����. �������� ����-����� ��������");
					Sleep(1000);
					fflush(stdin);
				}
				else
					break;
			}		
	for(int i=0; i<n; i++)
		while(true)
		{
			system("cls");
			textcolor(LightCyan);
			gotoxy(31,1);
			printf("����� ����������");
			gotoxy(31,2);
			ukr(866);
			for(short k=0; k<16; k++)
				putchar(196);
			ukr(1251);
			textcolor(White);
			gotoxy(2,4);
			stroka(15,"� ������������ ������ ������ ���� B");
			textcolor(LightRed);
			stroka(15,"[");
			textcolor(White);
			printf("%d",i+1);
			Sleep(15);
			textcolor(LightRed);
			stroka(15,"]");
			textcolor(White);
			stroka(15," �� ��������� ");
			textcolor(LightGreen);
			stroka(15,"ENTER");
			ukr(866);
			textcolor(LightCyan);
			gotoxy(1,5);
			putchar(218);
			for(short k=0; k<76; k++)
				putchar(196);
			gotoxy(78,5);
			putchar(191);
			gotoxy(1,6);
			putchar(179);
			gotoxy(78,6);
			putchar(179);
			gotoxy(1,7);
			putchar(192);
			for(short k=0; k<76; k++)
				putchar(196);
			gotoxy(78,7);
			putchar(217);
			gotoxy(3,6);
			ukr(1251);
			textcolor(White);
			y=scanf("%f",&b[i]);
			if(y==0)
			{
				gotoxy(2,9);
				stroka(15,"�� ����� ���������� ����. �������� ����-����� ��������");
				Sleep(1000);
				fflush(stdin);
			}
			else
				break;
		}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(i==j)
				diag[i]=matrix[i][j];
	for(int i=0; i<n; i++)
	{
		b[i]=b[i]/diag[i];
		for(int j=0; j<n; j++)
			matrix[i][j]=matrix[i][j]/diag[i];
	}
	for(int i=0; i<n; i++)
		x[i]=0;	
	flag=false;
	while(flag==false)
	{
		for(int i=0; i<n; i++)
		{
			sum[i]=0;
			for(int j=0; j<n; j++)
				sum[i]=sum[i]+(matrix[i][j]*x[j]);
		}
		for(int i=0; i<n; i++)
		{
			r[i]=b[i]-sum[i];
		}
		max=r[0];
		tmp=0;
		for(int i=1; i<n; i++)
			if(max<r[i])
			{
				max=r[i];
				tmp=i;
			}
		for(int i=0; i<n; i++)
			if(i==tmp)
				x[i]=x[i]+max;
		for(int i=0; i<n; i++)
		{
			if((r[i]==0)||(r[i]<0.000001))
				flag=true;
			else
			{
				flag=false;
				break;
			}
		}
	}
	system("cls");
	textcolor(LightCyan);
	gotoxy(31,1);
	printf("����� ����������");
	gotoxy(31,2);
	ukr(866);
	for(short k=0; k<16; k++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	for(int i=0; i<n; i++)
	{
		gotoxy(2,4+i);
		printf("X");
		textcolor(LightRed);
		printf("[");
		textcolor(White);
		printf("%d",i+1);
		textcolor(LightRed);
		printf("]");
		textcolor(White);
		printf(" = ");
		cout<<x[i];
	}
	NatBudKlav(25,8+n);
	for(int i=0; i<n; i++)
		free(matrix[i]);
	free(matrix);
	free(b);
	free(x);
	free(r);
	free(diag);
	free(sum);
	return;
}

void task()
{
	system("cls");
	textcolor(LightCyan);
	gotoxy(30,1);
	printf("�������� ��������");
	gotoxy(30,2);
	ukr(866);
	for(short k=0; k<17; k++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(3,4);
	stroka(15,"����� ���������� ��������� ����� ������������ ������� ������ ������� ��-");
	gotoxy(1,5);
	stroka(15,"����. �����������, �� ������ ��� ��������, ��������� ��������� �������, �");
	gotoxy(1,6);
	stroka(15,"����� �������� - ������ ������ ������. ��� ����, ��� ����� ���������, ����-");
	gotoxy(1,7);
	stroka(15,"�����, ��� ���������� �������� ���� ������� ���� ���������� ��������, �����");
	gotoxy(1,8);
	stroka(15,"���������� ����������� ������� �� ������ �� ���� ������ �� �� ���� ����-");
	gotoxy(1,9);
	stroka(15,"�������� �������� ��� ������� �� ������, ��������� �������� ������� ������");
	gotoxy(1,10);
	stroka(15,"������. � ������ ������� ���� ��c���� ��������� ����'����� ������� ����������,");
	gotoxy(1,11);
	stroka(15,"� ����'��� ������� ������ ��������.");
	NatBudKlav(25,14);
	system("cls");
	textcolor(LightCyan);
	gotoxy(30,1);
	printf("�������� ��������");
	gotoxy(30,2);
	ukr(866);
	for(short k=0; k<17; k++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(3,4);
	stroka(15,"���������� �� ������ � ��������� ��������� ��� ����'������ ����, � ����:");
	gotoxy(6,5);
	stroka(15,"- ���������� ��������� ������� ����������� ��� �������� (��������");
	gotoxy(8,6);
	stroka(15,"����� � ���� ���������� ������� ������ ������);");
	gotoxy(6,7);
	stroka(15,"- ����������� ������� (����������� ��������);");
	gotoxy(6,8);
	stroka(15,"- �������� ������� ������ ������ (����������� ��������).");
	gotoxy(3,9);
	stroka(15,"ϳ��� ����� �� ����� ���� �������� ������ �������� ������ - ����'���� ��-");
	gotoxy(1,10);
	stroka(15,"�����");
	NatBudKlav(25,13);
}

int main()
{
	frame();
}
