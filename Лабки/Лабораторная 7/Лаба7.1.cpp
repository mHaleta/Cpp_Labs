#include<mylib.h>
#include<time.h>
#include<stdlib.h>

extern void menu();

void frame()
{
	ukr(866);
	system("cls");
	textcolor(LightCyan);
	gotoxy(9,1);
	putchar(218);
	for(int i=0; i<60; i++)
		putchar(196);
	putchar(191);
    for(int i=2; i<20; i++)
    {
  		gotoxy(9,i);
  		putchar(179);
  		gotoxy(70,i);
		putchar(179);
    }
    gotoxy(9,20);
    putchar(192);
    for(int i=0; i<60; i++)
    	putchar(196);
    putchar(217);
    ukr(1251);
    gotoxy(28,3);
	stroka(15,"Лабораторна робота №7");
    gotoxy(18,5);
    stroka(15,"Тема: Динамічна пам'ять (масиви) у мові С");
    gotoxy(34,7);
    stroka(15,"4 варіант");
    gotoxy(47,13);
    stroka(15,"Виконав ст. гр. КМ-53");
    gotoxy(50,14);
    stroka(15,"Галета Максим");
    gotoxy(38,19);
    stroka(15,"2016");
    NatBudKlav(25,22);
    menu();
}

extern void work();

void menu()
{
	char c;
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(37,1);
		printf("МЕНЮ");
		gotoxy(37,2);
		ukr(866);
		for(short i=0; i<4; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,">Оберіть одну з перелічених дій");
		gotoxy(8,6);
		stroka(15,">Натисніть ");
		textcolor(LightBlue);
		stroka(15,"ENTER");
		textcolor(White);
		stroka(15,", щоб запустити програму на виконання");
		gotoxy(8,7);
		stroka(15,">Натисніть ");
		textcolor(LightBlue);
		stroka(15,"ESC");
		textcolor(White);
		stroka(15,", щоб вийти з програми");
		gotoxy(2,9);
		stroka(15,">Натисніть потрібну клавішу: ");
		c=getch();
		switch (c)
		{
			case 0x0D:
				work();
				break;
			case 0x1B:
				return;
				break;
			default:
				gotoxy(2,11);
				stroka(15,"Помилка введення. Зачекайте");
				Sleep(500);
				break;
		}
	}
}

void work()
{
	char st[3];
	int m, n, **matr, *mas, max, count, y;
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(26,1);
		printf("Динамічна пам'ять (масиви)");
		gotoxy(26,2);
		ukr(866);
		for(short i=0; i<26; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Введіть кількість рядків матриці та натисніть ");
		textcolor(LightBlue);
		stroka(15,"ENTER");
		textcolor(White);
		stroka(15,": ");
		y=scanf("%d",&m);
		if((y==0)||(m<1))
		{
			gotoxy(2,6);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			fflush(stdin);
		}
		else
			break;
	}
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(26,1);
		printf("Динамічна пам'ять (масиви)");
		gotoxy(26,2);
		ukr(866);
		for(short i=0; i<26; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Введіть кількість стовпчиків матриці та натисніть ");
		textcolor(LightBlue);
		stroka(15,"ENTER");
		textcolor(White);
		stroka(15,": ");
		y=scanf("%d",&n);
		if((y==0)||(n<1))
		{
			gotoxy(2,6);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			fflush(stdin);
		}
		else
			break;
	}
	mas=(int*)calloc(n,sizeof(int));
	if(mas==NULL)
		exit(-1);
	matr=(int**)calloc(m,sizeof(int*));
	if(matr==NULL)
		exit(-1);
	for(short i=0; i<m; i++)
	{
		matr[i]=(int*)calloc(n,sizeof(int));
		if(matr[i]==NULL)
			exit(-1);
	}
	system("cls");
	textcolor(LightCyan);
	gotoxy(26,1);
	printf("Динамічна пам'ять (масиви)");
	gotoxy(26,2);
	ukr(866);
	for(short i=0; i<26; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,"Матриця:");
	srand(time(NULL));
	for(short i=0; i<m; i++)
		for(short j=0; j<n; j++)
		{
			gotoxy(6+3*j,6+i);
			matr[i][j]=rand()%10;
			stroka(25,itoa(matr[i][j],st,10));
		}
	for(short j=0; j<n; j++)
	{
		mas[j]=0;
		for(short i=0; i<m; i++)
		{
			mas[j]+=matr[i][j];
		}
	}
	max=mas[0];
	count=0;
	for(short i=1; i<n; i++)
		if(max<mas[i])
		{
			max=mas[i];
			count=i;
		}
	gotoxy(2,7+m);
	stroka(15,"Максимальна сума = ");
	textcolor(LightGreen);
	stroka(15,itoa(max,st,10));
	textcolor(White);
	stroka(15," елементів ");
	textcolor(LightGreen);
	stroka(15,itoa(count+1,st,10));
	textcolor(White);
	stroka(15," стовпчика");
	for(short i=0; i<m; i++)
		free(matr[i]);
	free(matr);
	free(mas);
	NatBudKlav(25,11+m);
}

int main()
{
	frame();
}
