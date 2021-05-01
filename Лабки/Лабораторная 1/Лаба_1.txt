#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include "windows.h"
using namespace std;

void gotoxy(int xpos, int ypos)
{
	COORD scrn;    
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput,scrn);
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background<<4) | text));
}

//char bufUkr[256];

char* Ukr(const char* text) {
      CharToOem(text, bufUkr);
      return bufUkr;
      }

extern void menu();
 
void frame()
{
	system("cls");
	system("COLOR 70");
	gotoxy(9, 1);
	cout<<char(218);
	for(int i=0; i<60; i++)
		cout<<char(196);
	cout<<char(191);
    for(int i=2; i<20; i++)
    {
  		gotoxy(9, i);
  		cout<<char(179);
  		gotoxy(70,i);
		cout<<char(179);
    }
    gotoxy(9, 20);
    cout<<char(192);
    for(int i=0; i<60; i++)
    	cout<<char(196);
    cout<<char(217);
    //setlocale(LC_ALL, "Ukrainian");
    gotoxy(10, 3);
    cout<<Ukr("                    Лабораторна робота №1                   ");
    gotoxy(10, 5);
    cout<<Ukr("              Тема: Базовi типи даних у мовi С              ");
    gotoxy(10,7);
    cout<<Ukr("                          4 варiант                         ");
    gotoxy(47, 13);
    cout<<"Виконав ст. гр. КМ-53";
    gotoxy(47, 14);
    cout<<"   Галета Максим    ";
    gotoxy(38, 19);
    cout<<"2016";
    gotoxy(25, 22);
    cout<<"Натиснiть будь-яку клавiшу..."; 
    getch();
    menu();
}

extern void work1();

extern void work2();

extern void work3();

extern void work4();

void menu()
{
	char c;
	system("cls");
	gotoxy(2,2);
	cout<<">Оберiть одну з перелiчених дiй"<<endl;
	cout<<endl;
	cout<<"      >Натиснiть ";
	SetColor(9, 7);
	cout<<"1";
	SetColor(0, 7);
	cout<<", щоб виконати упаковку коду"<<endl;
	cout<<"      >Натиснiть ";
	SetColor(9, 7);
	cout<<"2";
	SetColor(0,7);
	cout<<", щоб виконати розпаковку коду"<<endl;
	cout<<"      >Натиснiть ";
	SetColor(9, 7);
	cout<<"3";
	SetColor(0,7);
	cout<<", щоб обчислити висоту паралелепiпеда"<<endl;
	cout<<"      >Натиснiть ";
	SetColor(9, 7);
	cout<<"4";
	SetColor(0,7);
	cout<<", щоб обчислити евклiдову довжину мiж двома точками"<<endl;
	cout<<"      >Натиснiть ";
	SetColor(9, 7);
	cout<<"ESC";
	SetColor(0, 7);
	cout<<", щоб вийти з програми"<<endl;
	cout<<endl;
	cout<<"  >Натиснiть потрiбну клавiшу: ";
	c=getch();
	switch (c)
	{
		case '1':
			work1();
			break;
		case '2':
			work2();
			break;
		case '3':
			work3();
			break;
		case '4':
			work4();
			break;
		case 0x8:
			frame();
			break;
		case 0x1B:
			exit(0);
			break;
		default:
			cout<<endl<<endl;
			cout<<"  Помилка введення. Зачекайте";
			Sleep(1500);
			menu();
			break;
	}
}

void work1()
{
 	unsigned int r, a, word;
 	bool d, b;
 	char c;
 	while(true)
 	{
 		system("cls");
 		gotoxy(32, 1);
 		cout<<"Упаковка коду";
 		gotoxy(32, 2);
 		for(int i=0; i<13; i++)
 			cout<<char(150);
 		gotoxy(0, 4);
 		cout<<"  >Команда завантаження/збереження в обчислювальнiй системі\n";
 		cout<<endl;
 		cout<<"     >Введiть напрямок передачi - в регiстр (0)/в пам'ять (1): ";
 		cin>>d;
 		if(!cin)
 		{
 			cout<<endl;
    	    cout<<"     Помилка введення. Зачекайте";
    	    Sleep(1500);
    	    cin.clear();
    	    while(cin.get()!='\n');
 		}
 		else
 			break;
 	}
 	while(true)
 	{
 		system("cls");
 		gotoxy(32, 1);
 		cout<<"Упаковка коду";
 		gotoxy(32, 2);
 		for(int i=0; i<13; i++)
 			cout<<char(150);
 		gotoxy(0, 4);
 		cout<<"  >Команда завантаження/збереження в обчислювальнiй системі\n";
 		cout<<endl;
 		cout<<"     >Введiть напрямок передачi - в регiстр (0)/в пам'ять (1): "<<d<<endl;
 		cout<<"     >Введiть регiстр адреси першого операнда (0-15): ";
 		cin>>r;
 		if((!cin)||(r>15))
 		{
 			cout<<endl;
    	    cout<<"     Помилка введення. Зачекайте";
    	    Sleep(1500);
    	    cin.clear();
    	    while(cin.get()!='\n');
 		}
 		else
 			break;
 	}
 	while(true)
 	{
 		system("cls");
 		gotoxy(32, 1);
 		cout<<"Упаковка коду";
 		gotoxy(32, 2);
 		for(int i=0; i<13; i++)
 			cout<<char(150);
 		gotoxy(0, 4);
 		cout<<"  >Команда завантаження/збереження в обчислювальнiй системі\n";
 		cout<<endl;
 		cout<<"     >Введiть напрямок передачi - в регiстр (0)/в пам'ять (1): "<<d<<endl;
 		cout<<"     >Введiть регiстр адреси першого операнда (0-15): "<<r<<endl;
 		cout<<"     >Введiть регiстр адреси другого операнда (0-15): ";
 		cin>>a;
 		if((!cin)||(a>15))
 		{
 			cout<<endl;
    	    cout<<"     Помилка введення. Зачекайте";
    	    Sleep(1500);
    	    cin.clear();
    	    while(cin.get()!='\n');
 		}
 		else
 			break;
 	}
 	word=0x71<<9;
 	word|=(d&0x1)<<8;
 	word|=(r&0xF)<<4;
 	word|=a&0xF;
 	b=false;
 	while(b==false)
 	{
 		system("cls");
 		gotoxy(32, 1);
 		cout<<"Упаковка коду";
 		gotoxy(32, 2);
 		for(int i=0; i<13; i++)
 			cout<<char(150);
 		gotoxy(0, 4);
 		cout<<"  >Команда завантаження/збереження в обчислювальнiй системі\n";
 		cout<<endl;
 		cout<<"     >Введiть напрямок передачi - в регiстр (0)/в пам'ять (1): "<<d<<endl;
 		cout<<"     >Введiть регiстр адреси першого операнда (0-15): "<<r<<endl;
 		cout<<"     >Введiть регiстр адреси другого операнда (0-15): "<<a<<endl;
 		cout<<endl;
 		printf("  >Слово стану пристрою: %04x", word);
 		cout<<endl<<endl;
 		for(int i=0; i<80; i++)
 			cout<<"=";
 		cout<<endl;
 		cout<<"  >Оберiть одну з наступних дiй\n";
		cout<<endl;
		cout<<"     >Натиснiть ";
		SetColor(9,7);
		cout<<"R ";
		SetColor(0,7);
		cout<<"для перезапуску програми\n";
		cout<<"     >Натиснiть ";
		SetColor(9, 7);
		cout<<"BACKSPACE";
		SetColor(0, 7);
		cout<<", щоб повернутися у головне меню\n";
		cout<<"     >Натиснiть ";
		SetColor(9,7);
		cout<<"ESC";
		SetColor(0, 7);
		cout<<", щоб вийти з програми\n";
		cout<<endl;
		cout<<"  >Натиснiть потрiбну клавiшу: ";
		c=getch();
		switch (c)
		{
			case 'r': case 'R':
				work1();
				break;
			case 0x8:
				menu();
				break;
			case 0x1B:
				exit(0);
				break;
			default:
				cout<<endl;
				cout<<endl;
				cout<<"  Помилка введення. Зачекайте";
				Sleep(1500);
				break;
		}				
	}
}

void work2()
{
	unsigned int d, r, a, word, word0;
	int y;
	char c;
	bool b;
	while(true)
	{
		system("cls");
		gotoxy(31, 1);
		cout<<"Розпаковка коду";
		gotoxy(31, 2);
		for(int i=0; i<15; i++)
			cout<<char(173);
		gotoxy(0, 4);
		cout<<"  >Команда завантаження/збереження в обчислювальнiй системi\n";
		cout<<endl;
		cout<<"     >Введiть слово стану пристрою (0xE200 - 0xE3FF): ";
		y=scanf("%x", &word);
		if((y==0)||(word<0xE200)||(word>0xE3FF))
		{
			cout<<endl;
			cout<<"     Помилка введення. Зачекайте";
			Sleep(1500);
			fflush(stdin);
		}
		else
			break;
	}
	word0=word;
	word=word<<7;
	d=(word>>15)&0x1;
	r=(word>>11)&0xF;
	a=(word>>7)&0xF;
	b=false;
	while(b==false)
	{
		system("cls");
		gotoxy(31, 1);
		cout<<"Розпаковка коду";
		gotoxy(31, 2);
		for(int i=0; i<15; i++)
			cout<<char(173);
		gotoxy(0, 4);
		cout<<"  >Команда завантаження/збереження в обчислювальнiй системi\n";
		cout<<endl;
		printf("     >Введiть слово стану пристрою (0xE200 - 0xE3FF): %x", word0);
		cout<<endl<<endl;
		printf("  >Напрямок передачi - в регiстр/пам'ять: %d", d);
		cout<<endl;
		printf("  >Регiстр адреси першого операнда: %d", r);
		cout<<endl;
		printf("  >Регiстр адреси другого операнда: %d", a);
		cout<<endl<<endl;
		for(int i=0; i<80; i++)
 			cout<<"=";
 		cout<<endl;
 		cout<<"  >Оберiть одну з наступних дiй\n";
		cout<<endl;
		cout<<"     >Натиснiть ";
		SetColor(9,7);
		cout<<"R ";
		SetColor(0,7);
		cout<<"для перезапуску програми\n";
		cout<<"     >Натиснiть ";
		SetColor(9, 7);
		cout<<"BACKSPACE";
		SetColor(0, 7);
		cout<<", щоб повернутися у головне меню\n";
		cout<<"     >Натиснiть ";
		SetColor(9,7);
		cout<<"ESC";
		SetColor(0, 7);
		cout<<", щоб вийти з програми\n";
		cout<<endl;
		cout<<"  >Натиснiть потрiбну клавiшу: ";
		c=getch();
		switch (c)
		{
			case 'r': case 'R':
				work2();
				break;
			case 0x8:
				menu();
				break;
			case 0x1B:
				exit(0);
				break;
			default:
				cout<<endl;
				cout<<endl;
				cout<<"  Помилка введення. Зачекайте";
				Sleep(1500);
				break;
		}	
	}
}

void work3()
{
	float v, s, h;
	char c;
	bool b;
	while(true)
	{
		system("cls");
		system("COLOR 70");
		gotoxy(23, 2);
		for(int i=0; i<32; i++)
			cout<<char(150);
		gotoxy(23, 1);
		cout<<"Обчислення висоти паралелепiпеда";
		gotoxy(0, 4);
		cout<<"  >Введiть об'єм паралелепiпеда (см^3): ";
		cin>>v;
		if((!cin)||(v<=0))
		{
			cout<<endl;
            cout<<"  Помилка введення. Зачекайте";
            Sleep(1500);
            cin.clear();
            while(cin.get()!='\n');
		}
		else
			break;
	}
	while(true)
	{
		system("cls");
		gotoxy(23, 2);
		for(int i=0; i<32; i++)
			cout<<char(150);
		gotoxy(23, 1);
		cout<<"Обчислення висоти паралелепiпеда";
		gotoxy(0, 4);
		cout<<"  >Введiть об'єм паралелепiпеда (см^3): "<<v<<endl;
		cout<<"  >Введiть площу гранi паралелепiда (см^2): ";
		cin>>s;
		if((!cin)||(s<=0))
		{
			cout<<endl;
            cout<<"  Помилка введення. Зачекайте";
            Sleep(1500);
            cin.clear();
            while(cin.get()!='\n');	
		}
		else
			break;	
	}
	h=v/s;
	b=false;
	while(b==false)
	{
		system("cls");
		gotoxy(23, 2);
		for(int i=0; i<32; i++)
			cout<<char(150);
		gotoxy(23, 1);
		cout<<"Обчислення висоти паралелепiпеда";
		gotoxy(0, 4);
		cout<<"  >Введiть об'єм паралелепiпеда (см^3): "<<v<<endl;
		cout<<"  >Введiть площу гранi паралелепiда (см^2): "<<s<<endl;
		cout<<endl;
		cout<<"  >Висота (см): "<<h;
		gotoxy(0,9);
		for(int i=0; i<80; i++)
			cout<<"=";
		cout<<endl;
		cout<<"  >Оберiть одну з наступних дiй\n";
		cout<<endl;
		cout<<"     >Натиснiть ";
		SetColor(9,7);
		cout<<"R ";
		SetColor(0,7);
		cout<<"для перезапуску програми\n";
		cout<<"     >Натиснiть ";
		SetColor(9, 7);
		cout<<"BACKSPACE";
		SetColor(0, 7);
		cout<<", щоб повернутися у головне меню\n";
		cout<<"     >Натиснiть ";
		SetColor(9,7);
		cout<<"ESC";
		SetColor(0, 7);
		cout<<", щоб вийти з програми\n";
		cout<<endl;
		cout<<"  >Натиснiть потрiбну клавiшу: ";
		c=getch();
		switch (c)
		{
			case 'r': case 'R':
				work3();
				break;
			case 0x8:
				menu();
				break;
			case 0x1B:
				exit(0);
				break;
			default:
				cout<<endl<<endl;
				cout<<"  Помилка введення. Зачекайте";
				Sleep(1500);
				break;
		}				
	}
}

void work4()
{
	float x1, y1, z1, x2, y2, z2, d;
	char c;
	bool b;
	while(true)
	{
		system("cls");
		gotoxy(21, 1);
		cout<<"Евклiдова давжина мiж двома точками";
		gotoxy(21, 2);
		for(int i=0; i<35; i++)
			cout<<char(150);
		gotoxy(30, 4);
		cout<<"Введiть координати";
		gotoxy(15, 5);
		cout<<"Точки А";
		gotoxy(15, 6);
		cout<<"X=";
		cin>>x1;
		if(!cin)
		{
			cin.clear();
			while(cin.get()!='\n');
		}
		else
			break;
	}
	while(true)
	{
		system("cls");
		gotoxy(21, 1);
		cout<<"Евклiдова давжина мiж двома точками";
		gotoxy(21, 2);
		for(int i=0; i<35; i++)
			cout<<char(150);
		gotoxy(30, 4);
		cout<<"Введiть координати";
		gotoxy(15, 5);
		cout<<"Точки А";
		gotoxy(15, 6);
		cout<<"X="<<x1;
		gotoxy(15, 7);
		cout<<"Y=";
		cin>>y1;
		if(!cin)
		{
			cin.clear();
			while(cin.get()!='\n');
		}
		else
			break;	
	}
	while(true)
	{
		system("cls");
		gotoxy(21, 1);
		cout<<"Евклiдова давжина мiж двома точками";
		gotoxy(21, 2);
		for(int i=0; i<35; i++)
			cout<<char(150);
		gotoxy(30, 4);
		cout<<"Введiть координати";
		gotoxy(15, 5);
		cout<<"Точки А";
		gotoxy(15, 6);
		cout<<"X="<<x1;
		gotoxy(15, 7);
		cout<<"Y="<<y1;
		gotoxy(15, 8);
		cout<<"Z=";
		cin>>z1;
		if(!cin)
		{
			cin.clear();
			while(cin.get()!='\n');
		}
		else
			break;	
	}
	while(true)
	{
		system("cls");
		gotoxy(21, 1);
		cout<<"Евклiдова давжина мiж двома точками";
		gotoxy(21, 2);
		for(int i=0; i<35; i++)
			cout<<char(150);
		gotoxy(30, 4);
		cout<<"Введiть координати";
		gotoxy(15, 5);
		cout<<"Точки А";
		gotoxy(15, 6);
		cout<<"X="<<x1;
		gotoxy(15, 7);
		cout<<"Y="<<y1;
		gotoxy(15, 8);
		cout<<"Z="<<z1;
		gotoxy(54, 5);
		cout<<"Точки B";
		gotoxy(54, 6);
		cout<<"X=";
		cin>>x2;
		if(!cin)
		{
			cin.clear();
			while(cin.get()!='\n');
		}
		else
			break;	
	}
	while(true)
	{
		system("cls");
		gotoxy(21, 1);
		cout<<"Евклiдова давжина мiж двома точками";
		gotoxy(21, 2);
		for(int i=0; i<35; i++)
			cout<<char(150);
		gotoxy(30, 4);
		cout<<"Введiть координати";
		gotoxy(15, 5);
		cout<<"Точки А";
		gotoxy(15, 6);
		cout<<"X="<<x1;
		gotoxy(15, 7);
		cout<<"Y="<<y1;
		gotoxy(15, 8);
		cout<<"Z="<<z1;
		gotoxy(54, 5);
		cout<<"Точки B";
		gotoxy(54, 6);
		cout<<"X="<<x2;
		gotoxy(54, 7);
		cout<<"Y=";
		cin>>y2;
		if(!cin)
		{
			cin.clear();
			while(cin.get()!='\n');
		}
		else
			break;	
	}
	while(true)
	{
		system("cls");
		gotoxy(21, 1);
		cout<<"Евклiдова давжина мiж двома точками";
		gotoxy(21, 2);
		for(int i=0; i<35; i++)
			cout<<char(150);
		gotoxy(30, 4);
		cout<<"Введiть координати";
		gotoxy(15, 5);
		cout<<"Точки А";
		gotoxy(15, 6);
		cout<<"X="<<x1;
		gotoxy(15, 7);
		cout<<"Y="<<y1;
		gotoxy(15, 8);
		cout<<"Z="<<z1;
		gotoxy(54, 5);
		cout<<"Точки B";
		gotoxy(54, 6);
		cout<<"X="<<x2;
		gotoxy(54, 7);
		cout<<"Y="<<y2;
		gotoxy(54, 8);
		cout<<"Z=";
		cin>>z2;
		if(!cin)
		{
			cin.clear();
			while(cin.get()!='\n');
		}
		else
			break;	
	}
	d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
	b=false;
	while(b==false)
	{
		system("cls");
		gotoxy(21, 1);
		cout<<"Евклiдова давжина мiж двома точками";
		gotoxy(21, 2);
		for(int i=0; i<35; i++)
			cout<<char(150);
		gotoxy(30, 4);
		cout<<"Введiть координати";
		gotoxy(15, 5);
		cout<<"Точки А";
		gotoxy(15, 6);
		cout<<"X="<<x1;
		gotoxy(15, 7);
		cout<<"Y="<<y1;
		gotoxy(15, 8);
		cout<<"Z="<<z1;
		gotoxy(54, 5);
		cout<<"Точки B";
		gotoxy(54, 6);
		cout<<"X="<<x2;
		gotoxy(54, 7);
		cout<<"Y="<<y2;
		gotoxy(54, 8);
		cout<<"Z="<<z2;
		gotoxy(30, 9);
		cout<<"Довжина: "<<d;
		gotoxy(0, 11);
		for(int i=0; i<80; i++)
			cout<<"=";
		cout<<endl;
		cout<<"  >Оберiть одну з наступних дiй\n";
		cout<<endl;
		cout<<"     >Натиснiть ";
		SetColor(9,7);
		cout<<"R ";
		SetColor(0,7);
		cout<<"для перезапуску програми\n";
		cout<<"     >Натиснiть ";
		SetColor(9, 7);
		cout<<"BACKSPACE";
		SetColor(0, 7);
		cout<<", щоб повернутися у головне меню\n";
		cout<<"     >Натиснiть ";
		SetColor(9,7);
		cout<<"ESC";
		SetColor(0, 7);
		cout<<", щоб вийти з програми\n";
		cout<<endl;
		cout<<"  >Натиснiть потрiбну клавiшу: ";
		c=getch();
		switch (c)
		{
			case 'r': case 'R':
				work4();
				break;
			case 0x8:
				menu();
				break;
			case 0x1B:
				exit(0);
				break;
			default:
				cout<<endl<<endl;
				cout<<"  Помилка введення. Зачекайте";
				Sleep(1500);
				break;
		}				
	}		
}

/*typedef BOOL (WINAPI *SETCONSOLEFONT)(HANDLE, DWORD);
SETCONSOLEFONT SetConsoleFont;*/

int main()
{
	/*HMODULE hmod = GetModuleHandleA("KERNEL32.DLL");
    SetConsoleFont =(SETCONSOLEFONT) GetProcAddress(hmod, "SetConsoleFont");
    if (!SetConsoleFont)
    {
    	cout<<"error\n"; 
    	exit(1);
    }
    SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE),8);
    SetConsoleOutputCP(1251);*/
  
    frame();
    return(0);
}
