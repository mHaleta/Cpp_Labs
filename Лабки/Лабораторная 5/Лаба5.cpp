#include<mylib.h>

int length(char *s)  //функция подсчёта длины строки
{
	int len;
	if(*s=='\0')    //если строка пуста
		return(0);  //возвращаем длину 0
	len=length(s+1)+1;  //рекурсивно считаем длину строки
	return(len);    //возвращаем длину len
}

/*
Дальше следуют те функции, которые есть во всех лабораторных.
Это frame() — обложка; menu() — меню программы.
*/

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
	stroka(15,"Лабораторна робота №5");
    gotoxy(27,5);
    stroka(15,"Тема: Рекурсія у мові С");
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
	char st[3], s[256];
	int len;
	system("cls");
	textcolor(LightCyan);
	gotoxy(32,1);
	printf("Довжина рядка");
	gotoxy(32,2);
	ukr(866);
	for(short i=0; i<13; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Введіть рядок. Текст буде зчитуватися поки не буде натиснута клавіша ");
	textcolor(LightBlue);
	stroka(15,"ENTER");
	textcolor(White);
	gotoxy(2,6);
	stroka(15,"Рядок (0-256): ");
	gets(s);
	if(strlen(s)>256)
	{
		printf("\n  ");
		stroka(15,"Довжина рядка більша за 256. Повторіть введення");
		Sleep(500);
		work();
	}
	printf("\n  ");
	stroka(15,"Довжина рядка: ");
	len=length(s);
	stroka(15,itoa(len,st,10));
	NatBudKlav(25,15);
	menu();
}

int main()
{
	frame();
}
