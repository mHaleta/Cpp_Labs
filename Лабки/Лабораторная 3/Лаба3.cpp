#include<mylib.h>

bool str(const char s[])
{
	bool b, flag;
	if(strlen(s)==1)
		b=true;
	for(int i=0; i<(strlen(s)-1); i++)
	{
		for(int j=i+1; j<strlen(s); j++)
			if(s[i]!=s[j])
				b=true;
			else
			{
				b=false;
				flag=true;
				break;
			}
		if(flag==true)
			break;
	}
	return(b);
}

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
	stroka(15,"Лабораторна робота №3");
    gotoxy(20,5);
    stroka(15,"Тема: Обробка символьних даних у мові С");
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
	char c, s[256];
	short i;
	system("cls");
	ukr(1251);
	textcolor(LightCyan);
	gotoxy(28,1);
	printf("Обробка символьних даних");
	gotoxy(28,2);
	ukr(866);
	for(short i=0; i<24; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Введіть рядок. Текст буде зчитуватися поки не буде натиснута клавіша ");
	textcolor(LightBlue);
	stroka(15,"ENTER");
	textcolor(White);
	gotoxy(2,6);
	stroka(15,"Рядок (1-256): ");
	gets(s);
	if(strlen(s)>256)
	{
		printf("\n  ");
		stroka(15,"Довжина рядка більша за 256. Повторіть введення");
		Sleep(500);
		work();
	}
	printf("\n  ");
	stroka(15,"Оброблений рядок: ");
	char *pch=strtok(s," ,.-");
	while(pch!=NULL)
	{
		if(str(pch)==true)
		{
			textcolor(LightGreen);
			stroka(15,pch);
			stroka(15," ");
			textcolor(White);
		}
		else
		{
			stroka(15,pch);
			stroka(15," ");
		}
		pch=strtok(NULL," ,.-");
	}
	NatBudKlav(25,13);
	menu();
}

int main()
{
	frame();
}
