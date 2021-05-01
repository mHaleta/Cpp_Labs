#include<mylib.h>

void rounding(float f, int sign)
{
	char s[256];
	int j, i;
	sprintf(s,"%f",f);
	for(short i=0; i<strlen(s); i++)
		if(s[i]=='.')
		{
			j=i;
			break;
		}
	j=j+sign;
	switch(s[j+1])
	{
		case '5': case '6': case '7': case '8': case '9':
			s[j]+=1;
			break;
	}
	stroka(15,"Округлене число: ");
	for(short i=0; i<=j; i++)
	{
		putchar(s[i]);
		Sleep(15);
	}
}

void division(int *a, unsigned short n, int k)
{
	int b[20];
	char st[10];
	short count=0;
	for(short i=0; i<n; i++)
		if(*(a+i)%k==0)
		{
			*(b+count)=*(a+i);
			count+=1;
		}
	system("cls");
	ukr(1251);
	textcolor(LightCyan);
	gotoxy(27,1);
	printf("Ділення на задане число");
	gotoxy(27,2);
	ukr(866);
	for(short i=0; i<23; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Отримана підпослідовність чисел, які діляться націло на ");
	textcolor(LightMagenta);
	stroka(15,itoa(k,st,10));
	textcolor(White);
	stroka(15,":");
	gotoxy(2,6);
	stroka(15,"n = ");
	textcolor(LightRed);
	stroka(15,"{ ");
	textcolor(White);
	for(short i=0; i<count; i++)
	{
		stroka(15,itoa(*(b+i),st,10));
		stroka(15," ");
	}
	textcolor(LightRed);
	stroka(15,"}");
}

extern void menu();

void frame()
{
	ukr(866);
	system("cls");
	textcolor(LightCyan);
	gotoxy(9,1);
	putchar(218);
	for(short i=0; i<60; i++)
		putchar(196);
	putchar(191);
    for(short i=2; i<20; i++)
    {
  		gotoxy(9,i);
  		putchar(179);
  		gotoxy(70,i);
		putchar(179);
    }
    gotoxy(9,20);
    putchar(192);
    for(short i=0; i<60; i++)
    	putchar(196);
    putchar(217);
    ukr(1251);
    gotoxy(28,3);
	stroka(15,"Лабораторна робота №4");
    gotoxy(22,5);
    stroka(15,"Тема: Вказівники і функії у мові С");
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

extern void work1();

extern void work2();

void menu()
{
	char c;
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
	stroka(15,"1");
	textcolor(White);
	stroka(15,", щоб перейти до виконання першого завдання");
	gotoxy(8,7);
	stroka(15,">Натисніть ");
	textcolor(LightBlue);
	stroka(15,"2");
	textcolor(White);
	stroka(15,", щоб перейти до виконання другого завданя");
	gotoxy(8,8);
	stroka(15,">Натисніть ");
	textcolor(LightBlue);
	stroka(15,"BACKSPACE");
	textcolor(White);
	stroka(15,", щоб повернутись до обкладинки");
	gotoxy(8,9);
	stroka(15,">Натисніть ");
	textcolor(LightBlue);
	stroka(15,"ESC");
	textcolor(White);
	stroka(15,", щоб вийти з програми");
	gotoxy(2,11);
	stroka(15,">Натисніть потрібну клавішу: ");
	c=getch();
	switch (c)
	{
		case '1':
			work1();
			break;
		case '2':
			work2();
			break;
		case 0x8:
			frame();
			break;
		case 0x1B:
			exit(0);
			break;
		default:
			gotoxy(2,13);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			menu();
			break;
	}
}

void work1()
{
	float f;
	int y, sign;
	system("cls");
	ukr(1251);
	textcolor(LightCyan);
	gotoxy(31,1);
	printf("Округлення числа");
	gotoxy(31,2);
	ukr(866);
	for(short i=0; i<16; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Введіть десятковий дріб, який треба округлити, та натисніть ");
	textcolor(LightBlue);
	stroka(15,"ENTER");
	textcolor(White);
	stroka(15,": ");
	y=scanf("%f",&f);
	if(y==0)
	{
		gotoxy(2,6);
		stroka(15,"Помилка введення. Зачекайте");
		Sleep(500);
		fflush(stdin);
		work1();
	}
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("Округлення числа");
		gotoxy(31,2);
		ukr(866);
		for(short i=0; i<16; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,">Введіть кількість знаків після крапки та натисніть ");
		textcolor(LightBlue);
		stroka(15,"ENTER");
		textcolor(White);
		stroka(15,": ");
		y=scanf("%d",&sign);
		if((y==0)||(sign<1))
		{
			gotoxy(2,6);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			fflush(stdin);
		}
		else
			break;
	}
	system("cls");
	textcolor(LightCyan);
	gotoxy(31,1);
	printf("Округлення числа");
	gotoxy(31,2);
	ukr(866);
	for(short i=0; i<16; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	rounding(f,sign);
	NatBudKlav(25,8);
	menu();
}

void work2()
{
	unsigned short y, n;
	int a[20], k;
	short i, j;
	char st[10];
	system("cls");
	ukr(1251);
	textcolor(LightCyan);
	gotoxy(27,1);
	printf("Ділення на задане число");
	gotoxy(27,2);
	ukr(866);
	for(short i=0; i<23; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Введіть кількість членів послідовності (не більше 20) та натисніть ");
	textcolor(LightBlue);
	stroka(15,"ENTER");
	textcolor(White);
	stroka(15,": ");
	y=scanf("%d",&n);
	if((y==0)||(n<1)||(n>20))
	{
		gotoxy(2,6);
		stroka(15,"Помилка введення. Зачекайте");
		Sleep(500);
		fflush(stdin);
		work2();
	}
	for(j=0; j<n; j++)
	{
		while(true)
		{
			system("cls");
			ukr(1251);
			textcolor(LightCyan);
			gotoxy(27,1);
			printf("Ділення на задане число");
			gotoxy(27,2);
			ukr(866);
			for(i=0; i<23; i++)
				putchar(196);
			ukr(1251);
			textcolor(White);
			gotoxy(2,4);
			stroka(15,">Введіть n");
			textcolor(LightRed);
			stroka(15,"[");
			textcolor(White);
			stroka(15,itoa(j+1,st,10));
			textcolor(LightRed);
			stroka(15,"]");
			textcolor(White);
			stroka(15," член послідовності та натисніть ");
			textcolor(LightBlue);
			stroka(15,"ENTER");
			textcolor(White);
			stroka(15,": ");
			y=scanf("%d",&a[j]);
			if(y==0)
			{
				gotoxy(2,6);
				stroka(15,"Помилка введення. Зачекайте");
				Sleep(500);
				fflush(stdin);
			}
			else
				break;
		}
	}
	while(true)
	{
		system("cls");
		ukr(1251);
		textcolor(LightCyan);
		gotoxy(27,1);
		printf("Ділення на задане число");
		gotoxy(27,2);
		ukr(866);
		for(short i=0; i<23; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,">Введіть число, на яке треба ділити члени послідовності, ");
		gotoxy(3,5);
		stroka(15,"та натисніть ");
		textcolor(LightBlue);
		stroka(15,"ENTER");
		textcolor(White);
		stroka(15,": ");
		y=scanf("%d",&k);
		if((y==0)||(k==0))
		{
			gotoxy(2,7);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			fflush(stdin);
		}
		else
			break;
	}
	division(a,n,k);
	NatBudKlav(25,10);
	menu();
}

int main()
{
	frame();
}
