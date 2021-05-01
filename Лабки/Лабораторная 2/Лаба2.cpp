#include<time.h>
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
	stroka(15,"Лабораторна робота №2");
    gotoxy(24,5);
    stroka(15,"Тема: Обробка масивiв у мовi С");
    gotoxy(34,7);
    stroka(15,"4 варiант");
    gotoxy(47,13);
    stroka(15,"Виконав ст. гр. КМ-53");
    gotoxy(50,14);
    stroka(15,"Галета Максим");
    gotoxy(38,19);
    stroka(15,"2016");
    NatBudKlav(25,22);
    menu();
}

extern void subwork1();

extern void subwork2();

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
	stroka(15,">Оберiть одну з перелiчених дiй");
	gotoxy(8,6);
	stroka(15,">Натиснiть ");
	textcolor(LightBlue);
	stroka(15,"1");
	textcolor(White);
	stroka(15,", щоб перейти до обробки векторiв");
	gotoxy(8,7);
	stroka(15,">Натиснiть ");
	textcolor(LightBlue);
	stroka(15,"2");
	textcolor(White);
	stroka(15,", щоб перейти до обробки матриць");
	gotoxy(8,8);
	stroka(15,">Натиснiть ");
	textcolor(LightBlue);
	stroka(15,"BACKSPACE");
	textcolor(White);
	stroka(15,", щоб повернутись до обкладинки");
	gotoxy(8,9);
	stroka(15,">Натиснiть ");
	textcolor(LightBlue);
	stroka(15,"ESC");
	textcolor(White);
	stroka(15,", щоб вийти з програми");
	gotoxy(2,11);
	stroka(15,">Натиснiть потрiбну клавiшу: ");
	c=getch();
	switch (c)
	{
		case '1':
			subwork1();
			break;
		case '2':
			subwork2();
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

extern void vector1();

extern void vector2();

void KeyChooseSubwork()
{
	gotoxy(2,4);
	textcolor(White);
	stroka(15,">Оберiть один з перелiчених варiантiв");
	gotoxy(8,6);
	stroka(15,">Натиснiть ");
	textcolor(LightBlue);
	stroka(15,"1 ");
	textcolor(White);
	stroka(15,"для ручного введення елементiв");
	gotoxy(8,7);
	stroka(15,">Натиснiть ");
	textcolor(LightBlue);
	stroka(15,"2 ");
	textcolor(White);
	stroka(15,"для генерацiї випадкового введення елементiв");
	gotoxy(8,8);
	stroka(15,">Натиснiть ");
	textcolor(LightBlue);
	stroka(15,"M");
	textcolor(White);
	stroka(15,", щоб повернутися до головного меню");
	gotoxy(2,10);
	stroka(15,">Натиснiть потрiбну клавiшу: ");	
}

void subwork1()
{
	char c;
	system("cls");
	gotoxy(31,1);
	textcolor(LightCyan);
	printf("Обробка векторiв");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<16; i++)
		putchar(196);
	ukr(1251);
	KeyChooseSubwork();
	c=getch();
	switch (c)
	{
		case '1':
			vector1();
			break;
		case '2':
			vector2();
			break;
		case 'm': case 'M': case 'м': case 'М':
			menu();
			break;
		default:
			gotoxy(2,12);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			subwork1();
			break;
	}
}

extern void matrix1();

extern void matrix2();

void subwork2()
{
	char c;
	system("cls");
	gotoxy(31,1);
	textcolor(LightCyan);
	printf("Обробка матриць");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<15; i++)
		putchar(196);
	ukr(1251);
	KeyChooseSubwork();
	c=getch();
	switch (c)
	{
		case '1':
			matrix1();
			break;
		case '2':
			matrix2();
			break;
		case 'm': case 'M': case 'м': case 'М':
			menu();
			break;
		default:
			gotoxy(2,12);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			subwork2();
			break;
	}	
}

void ChooseVariant(int l)
{
	textcolor(White);
	gotoxy(2,4+l);
	stroka(15,">Оберiть одну з перелiчених дiй");
	gotoxy(8,6+l);
	stroka(15,">Натиснiть ");
	textcolor(LightBlue);
	stroka(15,"R");
	textcolor(White);
	stroka(15,", щоб перезапустити програму");
	gotoxy(8,7+l);
	stroka(15,">Натиснiть ");
	textcolor(LightBlue);
	stroka(15,"BACKSPACE");
	textcolor(White);
	stroka(15,", щоб повернутись до поточного меню");
	gotoxy(8,8+l);
	stroka(15,">Натиснiть ");
	textcolor(LightBlue);
	stroka(15,"M");
	textcolor(White);
	stroka(15,", щоб повернутись до головного меню");
	gotoxy(8,9+l);
	stroka(15,">Натиснiть ");
	textcolor(LightBlue);
	stroka(15,"ESC");
	textcolor(White);
	stroka(15,", щоб вийти з програми");
	gotoxy(2,11+l);
	stroka(15,">Натиснiть потрiбну клавiшу: ");
}

void result(int count1, int count2, int a, int b)
{
	char c, *str, st[5];
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Добуток максимального i мiнiмального елементiв:");
	gotoxy(4,6);
	stroka(15,"a");
	textcolor(LightRed);
	stroka(15,"[");
	textcolor(White);
	str=itoa(count1+1,st,10);
	stroka(15,str);
	textcolor(LightRed);
	stroka(15,"]");
	textcolor(LightBlue);
	stroka(15," * ");
	textcolor(White);
	stroka(15,"b");
	textcolor(LightRed);
	stroka(15,"[");
	textcolor(White);
	str=itoa(count2+1,st,10);
	stroka(15,str);
	textcolor(LightRed);
	stroka(15,"]");
	textcolor(LightBlue);
	stroka(15," = ");
	textcolor(White);
	str=itoa(a,st,10);
	stroka(15,str);
	textcolor(LightBlue);
	stroka(15," * ");
	textcolor(White);
	str=itoa(b,st,10);
	stroka(15,str);
	textcolor(LightBlue);
	stroka(15," = ");
	textcolor(White);
	str=itoa(a*b,st,10);
	stroka(15,str);
}

void vector1()
{
	char c, *str, st[5];
	int y, n, m, max, min, count1, count2, a[20], b[20];
	bool flag;
	system("cls");
	gotoxy(31,1);
	textcolor(LightCyan);
	printf("Обробка векторiв");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<16; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Введiть кiлькiсть елементiв ");
	textcolor(LightMagenta);
	stroka(15,"n ");
	textcolor(White);
	stroka(15,"(1-20) у векторi ");
	textcolor(LightMagenta);
	stroka(15,"a ");
	textcolor(White);
	gotoxy(3,5);
	stroka(15,"та натиснiть ");
	textcolor(LightMagenta);
	stroka(15,"ENTER");
	textcolor(White);
	stroka(15,": ");
	y=scanf("%d", &n);
	if((y==0)||(n<1)||(n>20))
	{
		gotoxy(2,7);
		stroka(15,"Помилка введення. Зачекайте");
		Sleep(500);
		fflush(stdin);
		vector1();
	}
	for(int j=0; j<n; j++)
	{
		while(true)
		{
			system("cls");
			gotoxy(31,1);
			textcolor(LightCyan);
			printf("Обробка векторiв");
			ukr(866);
			gotoxy(31,2);
			for(int i=0; i<16; i++)
				putchar(196);
			ukr(1251);
			textcolor(White);
			gotoxy(2,4);
			stroka(15,">Введiть елемент вектора цiлих чисел (0-100) a");
			textcolor(LightRed);
			stroka(15,"[");
			textcolor(White);
			str=itoa(j+1,st,10);
			stroka(15,str);
			textcolor(LightRed);
			stroka(15,"] ");
			gotoxy(3,5);
			textcolor(White);
			stroka(15,"та натиснiть ");
			textcolor(LightBlue);
			stroka(15,"ENTER");
			textcolor(White);
			stroka(15,": ");
			y=scanf("%d", &a[j]);
			if((y==0)||(a[j]<0)||(a[j]>100))
			{
				gotoxy(2,7);
				stroka(15,"Помилка введення. Зачекайте");
				Sleep(500);
				fflush(stdin);
			}
			else
				break;	
		}
	}
	system("cls");
	gotoxy(31,1);
	textcolor(LightCyan);
	printf("Обробка векторiв");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<16; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Отриманий вектор:");
	gotoxy(4,6);
	if(n==1)
	{
		count1=0;
		stroka(15,"a = ");
		textcolor(LightRed);
		stroka(15,"{ ");
		textcolor(LightGreen);
		str=itoa(a[0],st,10);
		stroka(50,str);
		textcolor(LightRed);
		stroka(15," }");
		textcolor(White);
		gotoxy(2,8);
		stroka(15,">Максимальний елемент a");
		textcolor(LightRed);
		stroka(15,"[");
		textcolor(White);
		stroka(15,"1");
		textcolor(LightRed);
		stroka(15,"]");
		textcolor(White);
		stroka(15,"=");
		textcolor(LightGreen);
		str=itoa(a[0],st,10);
		stroka(15,str);
	}
	else
	{
		count1=0;
		stroka(15,"a = ");
		textcolor(LightRed);
		stroka(15,"{ ");
		textcolor(White);
		max=a[0];
		for(int i=1; i<n; i++)
			if(max<a[i])
			{
				max=a[i];
				count1=i;
			}
		for(int i=0; i<n; i++)
			if(i==count1)
			{
				textcolor(LightGreen);
				str=itoa(a[i],st,10);
				stroka(50,str);
				stroka(50," ");
				textcolor(White);
			}
			else
			{
				str=itoa(a[i],st,10);
				stroka(50,str);
				stroka(50," ");
			}
		textcolor(LightRed);
		stroka(15,"}");
		textcolor(White);
		gotoxy(2,8);
		stroka(15,">Максимальний елемент a");
		textcolor(LightRed);
		stroka(15,"[");
		textcolor(White);
		str=itoa(count1+1,st,10);
		stroka(15,str);
		textcolor(LightRed);
		stroka(15,"]");
		textcolor(White);
		stroka(15,"=");
		textcolor(LightGreen);
		str=itoa(a[count1],st,10);
		stroka(15,str);
	}
	NatBudKlav(25,12);
	while(true)
	{
		system("cls");
		gotoxy(31,1);
		textcolor(LightCyan);
		printf("Обробка векторiв");
		gotoxy(31,2);
		ukr(866);
		for(int i=0; i<16; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,">Введiть кiлькiсть елементiв ");
		textcolor(LightMagenta);
		stroka(15,"m ");
		textcolor(White);
		stroka(15,"(1-20) у векторi ");
		textcolor(LightMagenta);
		stroka(15,"b ");
		textcolor(White);
		gotoxy(3,5);
		stroka(15,"та натиснiть ");
		textcolor(LightMagenta);
		stroka(15,"ENTER");
		textcolor(White);
		stroka(15,": ");
		y=scanf("%d", &m);
		if((y==0)||(m<1)||(m>20))
		{
			gotoxy(2,7);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			fflush(stdin);
		}
		else
			break;
	}
	for(int j=0; j<m; j++)
	{
		while(true)
		{
			system("cls");
			gotoxy(31,1);
			textcolor(LightCyan);
			printf("Обробка векторiв");
			gotoxy(31,2);
			ukr(866);
			for(int i=0; i<16; i++)
				putchar(196);
			ukr(1251);
			textcolor(White);
			gotoxy(2,4);
			stroka(15,">Введiть елемент вектора цiлих чисел (0-100) b");
			textcolor(LightRed);
			stroka(15,"[");
			textcolor(White);
			str=itoa(j+1,st,10);
			stroka(15,str);
			textcolor(LightRed);
			stroka(15,"] ");
			gotoxy(3,5);
			textcolor(White);
			stroka(15,"та натиснiть ");
			textcolor(LightBlue);
			stroka(15,"ENTER");
			textcolor(White);
			stroka(15,": ");
			y=scanf("%d", &b[j]);
			if((y==0)||(b[j]<0)||(b[j]>100))
			{
				gotoxy(2,7);
				stroka(15,"Помилка введення. Зачекайте");
				Sleep(500);
				fflush(stdin);
			}
			else
				break;	
		}
	}
	system("cls");
	gotoxy(31,1); 
	textcolor(LightCyan);
	printf("Обробка векторiв");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<16; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Отриманий вектор:");
	gotoxy(4,6);
	if(m==1)
	{
		count2=0;
		stroka(15,"b = ");
		textcolor(LightRed);
		stroka(15,"{ ");
		textcolor(LightGreen);
		str=itoa(b[0],st,10);
		stroka(50,str);
		textcolor(LightRed);
		stroka(15," }");
		textcolor(White);
		gotoxy(2,8);
		stroka(15,">Мiнiмальний елемент b");
		textcolor(LightRed);
		stroka(15,"[");
		textcolor(White);
		stroka(15,"1");
		textcolor(LightRed);
		stroka(15,"]");
		textcolor(White);
		stroka(15,"=");
		textcolor(LightGreen);
		str=itoa(b[0],st,10);
		stroka(15,str);
	}
	else
	{
		count2=0;
		stroka(15,"b = ");
		textcolor(LightRed);
		stroka(15,"{ ");
		textcolor(White);
		min=b[0];
		for(int i=1; i<m; i++)
			if(min>b[i])
			{
				min=b[i];
				count2=i;
			}
		for(int i=0; i<m; i++)
			if(i==count2)
			{
				textcolor(LightGreen);
				str=itoa(b[i],st,10);
				stroka(50,str);
				stroka(50," ");
				textcolor(White);
			}
			else
			{
				str=itoa(b[i],st,10);
				stroka(50,str);
				stroka(50," ");
			}
		textcolor(LightRed);
		stroka(15,"}");
		textcolor(White);
		gotoxy(2,8);
		stroka(15,">Мiнiмальний елемент b");
		textcolor(LightRed);
		stroka(15,"[");
		textcolor(White);
		str=itoa(count2+1,st,10);
		stroka(15,str);
		textcolor(LightRed);
		stroka(15,"]");
		textcolor(White);
		stroka(15,"=");
		textcolor(LightGreen);
		str=itoa(b[count2],st,10);
		stroka(15,str);
	}
	NatBudKlav(25,12);
	system("cls");
	gotoxy(31,1);
	textcolor(LightCyan);
	printf("Обробка векторiв");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<16; i++)
		putchar(196);
	ukr(1251);
	result(count1,count2,a[count1],b[count2]);
	NatBudKlav(25,10);
	flag=false;
	while(flag==false)
	{
		system("cls");
		gotoxy(31,1);
		textcolor(LightCyan);
		printf("Обробка векторiв");
		gotoxy(31,2);
		ukr(866);
		for(int i=0; i<16; i++)
			putchar(196);;
		ukr(1251);
		ChooseVariant(0);
		c=getch();
		switch (c)
		{
			case 'r': case 'R': case 'к': case 'К':
				vector1();
				break;
			case 0x8:
				subwork1();
				break;
			case 'm': case 'M': case 'м': case 'М':
				menu();
				break;
			case 0x1B:
				exit(0);
				break;
			default:
				gotoxy(2,13);
				stroka(15,"Помилка введення. Зачекайте");
				Sleep(500);
				break;
		}
	}	
}

void vector2()
{
	char c, *str, st[5];
	int y, n, m, max, min, count1, count2, a[20], b[20];
	bool flag;
	system("cls");
	gotoxy(31,1);
	textcolor(LightCyan);
	printf("Обробка векторiв");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<16; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Введiть кiлькiсть елементiв ");
	textcolor(LightMagenta);
	stroka(15,"n ");
	textcolor(White);
	stroka(15,"(1-20) у векторi ");
	textcolor(LightMagenta);
	stroka(15,"a ");
	textcolor(White);
	gotoxy(3,5);
	stroka(15,"та натиснiть ");
	textcolor(LightMagenta);
	stroka(15,"ENTER");
	textcolor(White);
	stroka(15,": ");
	y=scanf("%d", &n);
	if((y==0)||(n<1)||(n>20))
	{
		gotoxy(2,7);
		stroka(15,"Помилка введення. Зачекайте");
		Sleep(500);
		fflush(stdin);
		vector2();
	}
	gotoxy(4,7);
	srand(time(NULL));
	for(int i=0; i<n; i++)
		a[i]=rand()%101;
	if(n==1)
	{
		count1=0;
		stroka(15,"a = ");
		textcolor(LightRed);
		stroka(15,"{ ");
		textcolor(LightGreen);
		stroka(50,itoa(a[0],st,10));
		textcolor(LightRed);
		stroka(15," }");
		textcolor(White);
		gotoxy(2,9);
		stroka(15,">Максимальний елемент a");
		textcolor(LightRed);
		stroka(15,"[");
		textcolor(White);
		stroka(15,"1");
		textcolor(LightRed);
		stroka(15,"]");
		textcolor(White);
		stroka(15,"=");
		textcolor(LightGreen);
		str=itoa(a[0],st,10);
		stroka(15,str);
	}
	else
	{
		count1=0;
		stroka(15,"a = ");
		textcolor(LightRed);
		stroka(15,"{ ");
		textcolor(White);
		max=a[0];
		for(int i=1; i<n; i++)
			if(max<a[i])
			{
				max=a[i];
				count1=i;
			}
		for(int i=0; i<n; i++)
			if(i==count1)
			{
				textcolor(LightGreen);
				str=itoa(a[i],st,10);
				stroka(50,str);
				stroka(50," ");
				textcolor(White);
			}
			else
			{
				str=itoa(a[i],st,10);
				stroka(50,str);
				stroka(50," ");
			}
		textcolor(LightRed);
		stroka(15,"}");
		textcolor(White);
		gotoxy(2,9);
		stroka(15,">Максимальний елемент a");
		textcolor(LightRed);
		stroka(15,"[");
		textcolor(White);
		str=itoa(count1+1,st,10);
		stroka(15,str);
		textcolor(LightRed);
		stroka(15,"]");
		textcolor(White);
		stroka(15,"=");
		textcolor(LightGreen);
		str=itoa(a[count1],st,10);
		stroka(15,str);
	}
	NatBudKlav(25,13);
	while(true)
	{
		system("cls");
		gotoxy(31,1);
		textcolor(LightCyan);
		printf("Обробка векторiв");
		gotoxy(31,2);
		ukr(866);
		for(int i=0; i<16; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,">Введiть кiлькiсть елементiв ");
		textcolor(LightMagenta);
		stroka(15,"m ");
		textcolor(White);
		stroka(15,"(1-20) у векторi ");
		textcolor(LightMagenta);
		stroka(15,"b ");
		textcolor(White);
		gotoxy(3,5);
		stroka(15,"та натиснiть ");
		textcolor(LightMagenta);
		stroka(15,"ENTER");
		textcolor(White);
		stroka(15,": ");
		y=scanf("%d", &m);
		if((y==0)||(m<1)||(m>20))
		{
			gotoxy(2,7);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			fflush(stdin);
		}
		else
			break;
	}
	gotoxy(4,7);
	srand(time(NULL));
	for(int i=0; i<m; i++)
		b[i]=rand()%101;
	if(m==1)
	{
		count2=0;
		stroka(15,"b = ");
		textcolor(LightRed);
		stroka(15,"{ ");
		textcolor(LightGreen);
		str=itoa(b[0],st,10);
		stroka(50,str);
		textcolor(LightRed);
		stroka(15," }");
		textcolor(White);
		gotoxy(2,9);
		stroka(15,">Мiнiмальний елемент b");
		textcolor(LightRed);
		stroka(15,"[");
		textcolor(White);
		stroka(15,"1");
		textcolor(LightRed);
		stroka(15,"]");
		textcolor(White);
		stroka(15,"=");
		textcolor(LightGreen);
		str=itoa(b[0],st,10);
		stroka(15,str);
	}
	else
	{
		count2=0;
		stroka(15,"b = ");
		textcolor(LightRed);
		stroka(15,"{ ");
		textcolor(White);
		min=b[0];
		for(int i=1; i<m; i++)
			if(min>b[i])
			{
				min=b[i];
				count2=i;
			}
		for(int i=0; i<m; i++)
			if(i==count2)
			{
				textcolor(LightGreen);
				str=itoa(b[i],st,10);
				stroka(50,str);
				stroka(50," ");
				textcolor(White);
			}
			else
			{
				str=itoa(b[i],st,10);
				stroka(50,str);
				stroka(50," ");
			}
		textcolor(LightRed);
		stroka(15,"}");
		textcolor(White);
		gotoxy(2,9);
		stroka(15,">Мiнiмальний елемент b");
		textcolor(LightRed);
		stroka(15,"[");
		textcolor(White);
		str=itoa(count2+1,st,10);
		stroka(15,str);
		textcolor(LightRed);
		stroka(15,"]");
		textcolor(White);
		stroka(15,"=");
		textcolor(LightGreen);
		str=itoa(b[count2],st,10);
		stroka(15,str);
	}
	NatBudKlav(25,13);
	system("cls");
	gotoxy(31,1);
	textcolor(LightCyan);
	printf("Обробка векторiв");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<16; i++)
		putchar(196);
	ukr(1251);
	result(count1,count2,a[count1],b[count2]);
	NatBudKlav(25,10);
	flag=false;
	while(flag==false)
	{
		system("cls");
		gotoxy(31,1);
		textcolor(LightCyan);
		printf("Обробка векторiв");
		gotoxy(31,2);
		ukr(866);
		for(int i=0; i<16; i++)
			putchar(196);
		ukr(1251);
		ChooseVariant(0);
		c=getch();
		ukr(866);
		switch (c)
		{
			case 'r': case 'R': case 'к': case 'К':
				vector1();
				break;
			case 0x8:
				subwork1();
				break;
			case 'm': case 'M': case 'м': case 'М':
				menu();
				break;
			case 0x1B:
				exit(0);
				break;
			default:
				gotoxy(2,13);
				ukr(1251);
				stroka(15,"Помилка введення. Зачекайте");
				Sleep(500);
				break;
		}
	}
}

int col(int n)
{
	int sum;
	if(n==1)
		return(1);
	sum=col(n-1)+2;
	return(sum);
}

void matrix1()
{
	char c, *str, st[3];
	int y, n, l, k, p, count, a[10][10];
	bool flag;
	system("cls");
	textcolor(LightCyan);
	gotoxy(31,1);
	printf("Обробка матриць");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<15; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Введiть розмiрнiсть ");
	textcolor(LightMagenta);
	stroka(15,"n ");
	textcolor(White);
	stroka(15,"(1-10) квадратної матрицi ");
	textcolor(LightMagenta);
	stroka(15,"A ");
	textcolor(White);
	gotoxy(3,5);
	stroka(15,"та натиснiть ");
	textcolor(LightMagenta);
	stroka(15,"ENTER");
	textcolor(White);
	stroka(15,": ");
	y=scanf("%d", &n);
	if((y==0)||(n<1)||(n>10))
	{
		gotoxy(2,7);
		stroka(15,"Помилка введення. Зачекайте");
		Sleep(500);
		fflush(stdin);
		matrix1();
	}
	for(int j=0; j<n; j++)
		for(int k=0; k<n; k++)
			while(true)			
			{
				system("cls");
				textcolor(LightCyan);
				gotoxy(31,1);
				printf("Обробка матриць");
				gotoxy(31,2);
				ukr(866);
				for(int i=0; i<15; i++)
					putchar(196);
				ukr(1251);
				textcolor(White);
				gotoxy(2,4);
				stroka(15,">Введiть елемент матрицi цiлих чисел (0-9) a");
				textcolor(LightRed);
				stroka(15,"[");
				textcolor(White);
				str=itoa(j+1,st,10);
				stroka(15,str);
				textcolor(LightRed);
				stroka(15,"][");
				textcolor(White);
				str=itoa(k+1,st,10);
				stroka(15,str);
				textcolor(LightRed);
				stroka(15,"] ");
				textcolor(White);
				gotoxy(3,5);
				stroka(15,"та натиснiть ");
				textcolor(LightBlue);
				stroka(15,"ENTER");
				textcolor(White);
				stroka(15,": ");
				y=scanf("%d", &a[j][k]);
				if((y==0)||(a[j][k]<0)||(a[j][k]>9))
				{
					gotoxy(2,7);
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
	printf("Обробка матриць");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<15; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Матриця А:");
	count=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			gotoxy(6+3*j,6+i);
			if(a[i][j]==0)
			{
				count+=1;
				textcolor(LightGreen);
				str=itoa(a[i][j], st, 10);
				stroka(50,str);
				textcolor(White);
			}
			else
			{
				str=itoa(a[i][j], st, 10);
				stroka(50,str);
			}
		}
	gotoxy(2,7+n);
	stroka(15,">Кiлькiсть ");
	textcolor(LightGreen);
	stroka(15,"0");
	textcolor(White);
	stroka(15,"-елементiв: ");
	str=itoa(count,st,10);
	stroka(15,str);
	NatBudKlav(25,11+n);
	system("cls");
	textcolor(LightCyan);
	gotoxy(31,1);
	printf("Обробка матриць");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<15; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Оброблена матриця А:");
	int b[n*n];
	k=0;
	l=n-1;
	p=col(n);
	while(p!=0)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(j-i==l)
				{
					b[k]=a[i][j];
					k+=1;
				}
		l-=1;
		p-=1;
	}
	l=0;
	for(int i=0; i<k; i++)
		if(b[i]==0)
		{
			b[i]=b[l];
			b[l]=0;
			l+=1;
		}
	k=0;
	l=n-1;
	p=col(n);
	while(p!=0)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(j-i==l)
				{
					a[i][j]=b[k];
					k+=1;
				}
		l-=1;
		p-=1;
	}
	l=n-1;
	p=col(n);
	while(p!=0)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(j-i==l)
				{
					gotoxy(6+3*j, 6+i);
					if(a[i][j]==0)
					{
						textcolor(LightGreen);
						str=itoa(a[i][j],st,10);
						stroka(100,str);
						textcolor(White);
					}
					else
					{
						str=itoa(a[i][j],st,10);
						stroka(100,str);
					}
				}
		p-=1;
		l-=1;
	}
	NatBudKlav(25,9+n);
	flag=false;
	while(flag==false)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("Обробка матриць");
		gotoxy(31,2);
		ukr(866);
		for(int i=0; i<15; i++)
			putchar(196);
		ukr(1251);
		ChooseVariant(0);
		c=getch();
		switch (c)
		{
			case 'r': case 'R': case 'к': case 'К':
				matrix1();
				break;
			case 0x8:
				subwork2();
				break;
			case 'm': case 'M': case 'м': case 'М':
				menu();
				break;
			case 0x1B:
				exit(0);
				break;
			default:
				gotoxy(2,13);
				stroka(15,"Помилка введення. Зачекайте");
				Sleep(500);
				break;
		}
	}
}

void matrix2()
{
	char c, *str, st[3];
	int y, n, l, k, p, count, a[10][10];
	bool flag;
	system("cls");
	textcolor(LightCyan);
	gotoxy(31,1);
	printf("Обробка матриць");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<15; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Введiть розмiрнiсть ");
	textcolor(LightMagenta);
	stroka(15,"n ");
	textcolor(White);
	stroka(15,"(1-10) квадратної матрицi ");
	textcolor(LightMagenta);
	stroka(15,"A ");
	textcolor(White);
	gotoxy(3,5);
	stroka(15,"та натиснiть ");
	textcolor(LightMagenta);
	stroka(15,"ENTER");
	textcolor(White);
	stroka(15,": ");
	y=scanf("%d", &n);
	if((y==0)||(n<1)||(n>10))
	{
		gotoxy(2,7);
		stroka(15,"Помилка введення. Зачекайте");
		Sleep(500);
		fflush(stdin);
		matrix2();
	}
	system("cls");
	textcolor(LightCyan);
	gotoxy(31,1);
	printf("Обробка матриць");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<15; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Матриця А:");
	srand(time(NULL));
	count=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			a[i][j]=rand()%6;
			gotoxy(6+3*j,6+i);
			if(a[i][j]==0)
			{
				count+=1;
				textcolor(LightGreen);
				str=itoa(a[i][j],st,10);
				stroka(50,str);
				textcolor(White);
			}
			else
			{
				str=itoa(a[i][j],st,10);
				stroka(50,str);
			}
		}
	gotoxy(2,7+n);
	stroka(15,">Кiлькiсть ");
	textcolor(LightGreen);
	stroka(15,"0");
	textcolor(White);
	stroka(15,"-елементiв: ");
	str=itoa(count,st,10);
	stroka(15,str);
	NatBudKlav(25,11+n);
	system("cls");
	textcolor(LightCyan);
	gotoxy(31,1);
	printf("Обробка матриць");
	gotoxy(31,2);
	ukr(866);
	for(int i=0; i<15; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Оброблена матриця А:");
	int b[n*n];
	k=0;
	l=n-1;
	p=col(n);
	while(p!=0)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(j-i==l)
				{
					b[k]=a[i][j];
					k+=1;
				}
		l-=1;
		p-=1;
	}
	l=0;
	for(int i=0; i<k; i++)
		if(b[i]==0)
		{
			b[i]=b[l];
			b[l]=0;
			l+=1;
		}
	k=0;
	l=n-1;
	p=col(n);
	while(p!=0)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(j-i==l)
				{
					a[i][j]=b[k];
					k+=1;
				}
		l-=1;
		p-=1;
	}
	l=n-1;
	p=col(n);
	while(p!=0)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(j-i==l)
				{
					gotoxy(6+3*j, 6+i);
					if(a[i][j]==0)
					{
						textcolor(LightGreen);
						str=itoa(a[i][j],st,10);
						stroka(100,str);
						textcolor(White);
					}
					else
					{
						str=itoa(a[i][j],st,10);
						stroka(100,str);
					}
				}
		p-=1;
		l-=1;
	}
	NatBudKlav(25,9+n);
	flag=false;
	while(flag==false)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("Обробка матриць");
		gotoxy(31,2);
		ukr(866);
		for(int i=0; i<15; i++)
			putchar(196);
		ukr(1251);
		ChooseVariant(0);
		c=getch();
		switch (c)
		{
			case 'r': case 'R': case 'к': case 'К':
				matrix2();
				break;
			case 0x8:
				subwork2();
				break;
			case 'm': case 'M': case 'м': case 'М':
				menu();
				break;
			case 0x1B:
				exit(0);
				break;
			default:
				gotoxy(2,13);
				stroka(15,"Помилка введення. Зачекайте");
				Sleep(500);
				break;
		}
	}
}

int main()
{
	frame();
}
