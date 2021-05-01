#include<mylib.h>

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
	stroka(15,"Лабораторна робота №6");
    gotoxy(14,5);
    stroka(15,"Тема: Типи даних, визначені користувачем, у мові С");
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
	stroka(15,"BACKSPACE");
	textcolor(White);
	stroka(15,", щоб повернутись до обкладинки");
	gotoxy(8,8);
	stroka(15,">Натисніть ");
	textcolor(LightBlue);
	stroka(15,"ESC");
	textcolor(White);
	stroka(15,", щоб вийти з програми");
	gotoxy(2,10);
	stroka(15,">Натисніть потрібну клавішу: ");
	c=getch();
	switch (c)
	{
		case 0x0D:
			work();
			break;
		case 0x8:
			frame();
			break;
		case 0x1B:
			exit(0);
			break;
		default:
			gotoxy(2,12);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			menu();
			break;
	}
}

void work()
{
	int y, count;
	char c, s[80];
	bool b;
	struct aeroflot
	{
		int number;
		char punkt[80];
		char type[80];
	} tmp, value, mas[5];
	for(short j=0; j<5; j++)
	{
		while(true)
		{
			system("cls");
			textcolor(LightCyan);
			gotoxy(34,1);
			printf("Заповнення");
			gotoxy(34,2);
			ukr(866);
			for(short i=0; i<10; i++)
				putchar(196);
			ukr(1251);
			textcolor(White);
			gotoxy(2,4);
			stroka(15,">Введіть номер рейсу ");
			textcolor(LightBlue);
			stroka(15,"mas");
			textcolor(LightRed);
			stroka(15,"[");
			textcolor(White);
			printf("%d",j+1);
			textcolor(LightRed);
			Sleep(15);
			stroka(15,"]");
			textcolor(White);
			stroka(15,".");
			textcolor(LightBlue);
			stroka(15,"number ");
			textcolor(White);
			stroka(15,"та натисніть ");
			textcolor(LightBlue);
			stroka(15,"ENTER");
			textcolor(White);
			stroka(15,": ");
			y=scanf("%d",&value.number);
			if((y==0)||(value.number<1))
			{
				gotoxy(2,6);
				stroka(15,"Помилка введення. Зачекайте");
				Sleep(500);
				fflush(stdin);
			}
			else
				break;
		}
		gotoxy(2,6);
		stroka(15,">Введіть назву пункту призначення рейсу ");
		textcolor(LightBlue);
		stroka(15,"mas");
		textcolor(LightRed);
		stroka(15,"[");
		textcolor(White);
		printf("%d",j+1);
		textcolor(LightRed);
		Sleep(15);
		stroka(15,"]");
		textcolor(White);
		stroka(15,".");
		textcolor(LightBlue);
		stroka(15,"punkt ");
		textcolor(White);
		gotoxy(3,7);
		stroka(15,"та натисніть ");
		textcolor(LightBlue);
		stroka(15,"ENTER");
		textcolor(White);
		stroka(15,": ");
     	fflush(stdin);
		gets(value.punkt);
		gotoxy(2,9);
		stroka(15,">Введіть тип літака ");
		textcolor(LightBlue);
		stroka(15,"mas");
		textcolor(LightRed);
		stroka(15,"[");
		textcolor(White);
		printf("%d",j+1);
		textcolor(LightRed);
		Sleep(15);
		stroka(15,"]");
		textcolor(White);
		stroka(15,".");
		textcolor(LightBlue);
		stroka(15,"type ");
		textcolor(White);
		stroka(15,"та натисніть ");
		textcolor(LightBlue);
		stroka(15,"ENTER");
		textcolor(White);
		stroka(15,": ");
		gets(value.type);
		mas[j]=value;
	}
	for(short i=0; i<4; i++)
		for(short j=i+1; j<5; j++)
			if(mas[j].number<mas[i].number)
			{
				tmp=mas[i];
				mas[i]=mas[j];
				mas[j]=tmp;
			}
	system("cls");
	textcolor(LightCyan);
	gotoxy(34,1);
	printf("Заповнення");
	gotoxy(34,2);
	ukr(866);
	for(short i=0; i<10; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	printf("Номер рейсу");
	gotoxy(18,4);
	printf("Пункт призначення");
	gotoxy(40,4);
	printf("Тип літака");
	for(short i=0; i<5; i++)
	{
		gotoxy(2,5+i);
		printf("%d",mas[i].number);
		gotoxy(18,5+i);
		printf("%s",mas[i].punkt);
		gotoxy(40,5+i);
		printf("%s",mas[i].type);
	}
	NatBudKlav(25,13);
	m1:
		while(true)
		{
			system("cls");
			textcolor(LightCyan);
			gotoxy(36,1);
			printf("Пошук");
			gotoxy(36,2);
			ukr(866);
			for(short i=0; i<5; i++)
				putchar(196);
			ukr(1251);
			textcolor(White);
			gotoxy(2,4);
			stroka(15,">Введіть рядок для пошуку пункту призначення рейсу");
			gotoxy(3,5);
			stroka(15,"та натисніть ");
			textcolor(LightBlue);
			stroka(15,"ENTER");
			textcolor(White);
			stroka(15,": ");
			gets(s);
			if(strlen(s)>80)
			{
				gotoxy(2,8);
				stroka(15,"Помилка введення. Зачекайте");
				Sleep(500);
			}
			else
				break;
		}
		system("cls");
		textcolor(LightCyan);
		gotoxy(36,1);
		printf("Пошук");
		gotoxy(36,2);
		ukr(866);
		for(short i=0; i<5; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		for(short i=0; i<5; i++)
		{
			if(strcmp(s,mas[i].punkt)==0)
			{
				b=true;
				break;
			}
			else
				b=false;
		}
		if(b==false)
		{
			gotoxy(2,4);
			stroka(15,">Зараз нажаль немає літаків з таким пунктом призначення.");
			NatBudKlav(25,8);
		}
		else
		{
			gotoxy(2,4);
			printf("Номер рейсу");
			gotoxy(18,4);
			printf("Пункт призначення");
			gotoxy(40,4);
			printf("Тип літака");
			count=0;
			for(short i=0; i<5; i++)
				if(strcmp(s,mas[i].punkt)==0)
				{
					gotoxy(2,5+count);
					printf("%d",mas[i].number);
					gotoxy(18,5+count);
					printf("%s",mas[i].punkt);
					gotoxy(40,5+count);
					printf("%s",mas[i].type);
					count+=1;
				}
			NatBudKlav(25,13);
		}
		m2:
			system("cls");
			textcolor(LightCyan);
			gotoxy(36,1);
			printf("Пошук");
			gotoxy(36,2);
			ukr(866);
			for(short i=0; i<5; i++)
				putchar(196);
			ukr(1251);
			textcolor(White);
			gotoxy(2,4);
			stroka(15,">Оберіть одну з перелічених дій");
			gotoxy(8,6);
			stroka(15,">Натисніть ");
			textcolor(LightBlue);
			stroka(15,"R");
			textcolor(White);
			stroka(15,", щоб повторити пошук");
			gotoxy(8,7);
			stroka(15,">Натисніть ");
			textcolor(LightBlue);
			stroka(15,"M");
			textcolor(White);
			stroka(15,", щоб повернутись до головного меню");
			gotoxy(8,8);
			stroka(15,">Натисніть ");
			textcolor(LightBlue);
			stroka(15,"ESC");
			textcolor(White);
			stroka(15,", щоб вийти з програми");
			gotoxy(2,10);
			stroka(15,">Натисніть потрібну клавішу: ");
			c=getch();
			switch (c)
			{
				case 'R': case 'r':
					goto m1;
					break;
				case 'M': case 'm':
					menu();
					break;
				case 0x1B:
					exit(0);
					break;
				default:
					gotoxy(2,12);
					stroka(15,"Помилка введення. Зачекайте");
					Sleep(500);
					goto m2;
					break;
			}
}

int main()
{
	frame();
}
