#include <mylib.h>
#include <stdlib.h>

struct AEROFLOT
{
	int number;
	char punkt[40];
	char type[40];
	AEROFLOT *next;
};

int count=0;

typedef struct AEROFLOT aeroflot;

aeroflot *head=NULL;

void menu();

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
    stroka(15,"Тема: Динамічна пам'ять (списки) у мові С");
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

int position(const char str[])
{
	int pos, y;
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(26,1);
		printf("Динамічна пам'ять (списки)");
		gotoxy(26,2);
		ukr(866);
		for(short i=0; i<26; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,str);
		textcolor(LightBlue);
		stroka(15,"ENTER");
		textcolor(White);
		stroka(15,": ");
		y=scanf("%d",&pos);
		if((y==0)||(pos<1))
		{
			gotoxy(2,6);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			fflush(stdin);
		}
		else
		{
			return(pos);
		}
	}
}

void ChooseAdd();

void ChooseDelete();

void List();

void Search();

void FreeMemory();

void menu()
{
	char c;
	while (true)
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
		stroka(15,">Натисніть");
		textcolor(LightBlue);
		stroka(15," 1 ");
		textcolor(White);
		stroka(15,"для додавання нової структури у список");
		gotoxy(8,7);
		stroka(15,">Натисніть");
		textcolor(LightBlue);
		stroka(15," 2 ");
		textcolor(White);
		stroka(15,"для видалення структури зі списку");
		gotoxy(8,8);
		stroka(15,">Натисніть");
		textcolor(LightBlue);
		stroka(15," 3 ");
		textcolor(White);
		stroka(15,"для виведення списку на екран");
		gotoxy(8,9);
		stroka(15,">Натисніть");
		textcolor(LightBlue);
		stroka(15," 4 ");
		textcolor(White);
		stroka(15,"для пошуку структури у списку");
		gotoxy(8,10);
		stroka(15,">Натисніть");
		textcolor(LightBlue);
		stroka(15," D ");
		textcolor(White);
		stroka(15,"для видалення всього списку");
		gotoxy(8,11);
		stroka(15,">Натисніть");
		textcolor(LightBlue);
		stroka(15," ESC ");
		textcolor(White);
		stroka(15,"для виходу з програми");
		gotoxy(2,13);
		stroka(15,">Натисніть потрібну клавішу: ");
		c=getch();
		switch(c)
		{
			case '1':
				ChooseAdd();
				break;
			case '2':
				ChooseDelete();
				break;
			case '3':
				List();
				break;
			case '4':
				Search();
				break;
			case 'd': case 'D':
				FreeMemory();
				break;
			case 0x1B:
				FreeMemory();
				return;
			default:
				gotoxy(2,15);
				stroka(15,"Помилка введення. Зачекайте");
				Sleep(500);
				break;
		}
	}
}

void Add(int position);

void ChooseAdd()
{
	char c;
	system("cls");
	textcolor(LightCyan);
	gotoxy(26,1);
	printf("Динамічна пам'ять (списки)");
	gotoxy(26,2);
	ukr(866);
	for(short i=0; i<26; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Оберіть одну з перелічених дій");
	gotoxy(8,6);
	stroka(15,">Натисніть");
	textcolor(LightBlue);
	stroka(15," 1 ");
	textcolor(White);
	stroka(15,"для додавання структури на початок списку");
	gotoxy(8,7);
	stroka(15,">Натисніть");
	textcolor(LightBlue);
	stroka(15," 2 ");
	textcolor(White);
	stroka(15,"для додавання структури в середину списку");
	gotoxy(8,8);
	stroka(15,">Натисніть");
	textcolor(LightBlue);
	stroka(15," 3 ");
	textcolor(White);
	stroka(15,"для додавання структури в кінець списку");
	gotoxy(8,9);
	stroka(15,">Натисніть");
	textcolor(LightBlue);
	stroka(15," BACKSPACE");
	textcolor(White);
	stroka(15,", щоб повернутись до головного меню");
	gotoxy(8,10);
	stroka(15,">Натисніть");
	textcolor(LightBlue);
	stroka(15," ESC ");
	textcolor(White);
	stroka(15,"для виходу з програми");
	gotoxy(2,12);
	stroka(15,">Натисніть потрібну клавішу: ");
	c=getch();
	switch(c)
	{
		case '1':
			Add(1);
			break;
		case '2':
			Add(position(">Введіть позицію додавання структури до списку та натисніть "));
			break;
		case '3':
			Add(count+1);
			break;
		case 0x8:
			break;
		case 0x1B:
			FreeMemory();
			exit(0);
		default:
			gotoxy(2,14);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			ChooseAdd();
			break;
	}
}

void Add(int position)
{
	int y;
	aeroflot *current, *prev, *element, *tmp;
	element=(aeroflot*)malloc(sizeof(aeroflot));
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(26,1);
		printf("Динамічна пам'ять (списки)");
		gotoxy(26,2);
		ukr(866);
		for(short i=0; i<26; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);	
		stroka(15,">Введіть номер рейсу та натисніть ");
		textcolor(LightBlue);
		stroka(15,"ENTER");
		textcolor(White);
		stroka(15,": ");
		y=scanf("%d",&element->number);
		if((y==0)||(element->number<1))
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
	gotoxy(26,1);
	printf("Динамічна пам'ять (списки)");
	gotoxy(26,2);
	ukr(866);
	for(short i=0; i<26; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Введіть пункт призначення рейсу та натисніть ");
	textcolor(LightBlue);
	stroka(15,"ENTER");
	textcolor(White);
	stroka(15,": ");
	fflush(stdin);
	gets(element->punkt);
	system("cls");
	textcolor(LightCyan);
	gotoxy(26,1);
	printf("Динамічна пам'ять (списки)");
	gotoxy(26,2);
	ukr(866);
	for(short i=0; i<26; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Введіть тип літака та натисніть ");
	textcolor(LightBlue);
	stroka(15,"ENTER");
	textcolor(White);
	stroka(15,": ");
	gets(element->type);
	if(head==NULL)
	{
		element->next=NULL;
		head=element;
	}
	else
	{	
		prev=current=head;
		for(short i=1; i<position && current!=NULL; i++)
		{
			prev=current;
			current=current->next;
		}
		if (current == head)
		{
			head = element;
			head->next = current;
		}
		else
		{
			if (current == NULL)
			{
				prev->next = element;
				element->next=NULL;
			}
			else
			{
				tmp = prev->next;
				prev->next=element;
				element->next=tmp;
			}
		}
	}
	count+=1;
}

void Delete(int position);

void ChooseDelete()
{
	char c;
	system("cls");
	textcolor(LightCyan);
	gotoxy(26,1);
	printf("Динамічна пам'ять (списки)");
	gotoxy(26,2);
	ukr(866);
	for(short i=0; i<26; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	stroka(15,">Оберіть одну з перелічених дій");
	gotoxy(8,6);
	stroka(15,">Натисніть");
	textcolor(LightBlue);
	stroka(15," 1 ");
	textcolor(White);
	stroka(15,"для видалення структури з початку списку");
	gotoxy(8,7);
	stroka(15,">Натисніть");
	textcolor(LightBlue);
	stroka(15," 2 ");
	textcolor(White);
	stroka(15,"для видалення структури з середини списку");
	gotoxy(8,8);
	stroka(15,">Натисніть");
	textcolor(LightBlue);
	stroka(15," 3 ");
	textcolor(White);
	stroka(15,"для видалення структури з кінця списку");
	gotoxy(8,9);
	stroka(15,">Натисніть");
	textcolor(LightBlue);
	stroka(15," BACKSPACE");
	textcolor(White);
	stroka(15,", щоб повернутись до головного меню");
	gotoxy(8,10);
	stroka(15,">Натисніть");
	textcolor(LightBlue);
	stroka(15," ESC ");
	textcolor(White);
	stroka(15,"для виходу з програми");
	gotoxy(2,12);
	stroka(15,">Натисніть потрібну клавішу: ");
	c=getch();
	switch(c)
	{
		case '1':
			Delete(1);
			break;
		case '2':
			Delete(position(">Введіть позицію видалення структури зі списку та натисніть "));
			break;
		case '3':
			Delete(count);
			break;
		case 0x8:
			break;
		case 0x1B:
			FreeMemory();
			exit(0);
		default:
			gotoxy(2,14);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(500);
			break;
	}
}

void Delete(int position)
{
	if(head==NULL)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(26,1);
		printf("Динамічна пам'ять (списки)");
		gotoxy(26,2);
		ukr(866);
		for(short i=0; i<26; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Список пустий");
		Sleep(1000);
		return;
	}
	aeroflot *prev;
	aeroflot *current=prev=head;
	for(short i=1; i<position && current!=NULL; i++)
	{
		prev=current;
		current=current->next;
	}
	if(current==NULL)
		return;
	else
	{
		prev->next=current->next;
		if (current==head)
		{
			head=current->next;
		}
		free(current);
		current=NULL;
	}
   	count-=1;
}

void List()
{
	if(head==NULL)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(26,1);
		printf("Динамічна пам'ять (списки)");
		gotoxy(26,2);
		ukr(866);
		for(short i=0; i<26; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Список пустий");
		Sleep(1000);
		return;
	}
	int counter=0;
	aeroflot *tmp=head;
	system("cls");
	textcolor(LightCyan);
	gotoxy(26,1);
	printf("Динамічна пам'ять (списки)");
	gotoxy(26,2);
	ukr(866);
	for(short i=0; i<26; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(2,4);
	printf("Номер рейсу");
	gotoxy(18,4);
	printf("Пункт призначення");
	gotoxy(40,4);
	printf("Тип літака");
	while(tmp!=NULL)
	{
		gotoxy(2,5+counter);
		printf("%d",tmp->number);
		gotoxy(18,5+counter);
		printf("%s",tmp->punkt);
		gotoxy(40,5+counter);
		printf("%s",tmp->type);
		tmp=tmp->next;
		counter+=1;
	}
	NatBudKlav(25,8+counter);
}

void Search()
{
	char s[40];
	aeroflot *tmp;
	bool b;
	int counter=0;
	if(head==NULL)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(26,1);
		printf("Динамічна пам'ять (списки)");
		gotoxy(26,2);
		ukr(866);
		for(short i=0; i<26; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Список пустий");
		Sleep(1000);
		return;
	}
	system("cls");
	textcolor(LightCyan);
	gotoxy(26,1);
	printf("Динамічна пам'ять (списки)");
	gotoxy(26,2);
	ukr(866);
	for(short i=0; i<26; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	gotoxy(1,4);
	stroka(15,"Введіть пункт призначення, за яким буде здійснюватися пошук та натисніть ");
	textcolor(LightBlue);
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
	gets(s);
	tmp=head;
	b=false;
	while(tmp!=NULL)
	{
		if(strcmp(s,tmp->punkt)==0)
		{
			b=true;
			break;
		}
		else
			tmp=tmp->next;
	}
	system("cls");
	textcolor(LightCyan);
	gotoxy(26,1);
	printf("Динамічна пам'ять (списки)");
	gotoxy(26,2);
	ukr(866);
	for(short i=0; i<26; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	if(b==false)
	{
		gotoxy(2,4);
		stroka(15,">Зараз нажаль немає літаків з таким пунктом призначення");
		NatBudKlav(25,8);
		return;
	}
	else
	{
		gotoxy(2,4);
		printf("Номер рейсу");
		gotoxy(18,4);
		printf("Пункт призначення");
		gotoxy(40,4);
		printf("Тип літака");
		tmp=head;
		while(tmp!=NULL)
		{
			if(strcmp(s,tmp->punkt)==0)
			{
				gotoxy(2,5+counter);
				printf("%d",tmp->number);
				gotoxy(18,5+counter);
				printf("%s",tmp->punkt);
				gotoxy(40,5+counter);
				printf("%s",tmp->type);
				counter+=1;
				tmp=tmp->next;
			}
			else
				tmp=tmp->next;
		}
		NatBudKlav(25,8+counter);
	}
}

void FreeMemory()
{
	if(head==NULL)
		return;
	while(head!=NULL)
	{
		free(head);
		head=head->next;
	}
}

int main()
{
	frame();
}
