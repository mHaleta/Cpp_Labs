#include<mylib.h>
#include<fstream>
#include<iostream>
using namespace std;

struct lines
{
	char row[73];
	struct lines *next;
};

lines *head=NULL;

int count=0;

string ArrStr[12]=
{
	"Збереження до файлу",
	", в який треба зберегти",
	"Копіювання до файлу",
	", з якого треба скопіювати",
	"Введіть рядок, починаючи з якого треба копіювати, та натисніть ",
	", в який треба скопіювати",
	"Завантаження з файлу",
	", з якого треба завантажити",
	"Видалення з файлу",
	", з якого треба видалити",
	"Видалення файлу",
	", який треба видалити"
};

void stroka(int j, string str)
{
	int i=0;
	while(i<str.length())
	{
		cout<<str[i];
		Sleep(j);
		i+=1;
	}
}

int length(char *str)
{
	int j=strlen(str);
	int i=j-1;
	while(i!=0)
	{
		if(str[i]==0x20)
			break;
		i-=1;
	}
	if(i==0)
		return(j);
	else
		return(j-i-1);
}

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
	stroka(15,"Лабораторна робота №8");
    gotoxy(24,5);
    stroka(15,"Тема: Текстові файли у мові С");
    gotoxy(34,7);
    stroka(15,"4 варіант");
    gotoxy(47,13);
    stroka(15,"Виконав ст. гр. КМ-53");
    gotoxy(50,14);
    stroka(15,"Галета Максим");
    gotoxy(38,19);
    stroka(15,"2016");
    NatBudKlav(25,22);
    system("cls");
    menu();
}

int position(string str1, string str2, int l, int p)
{
	int pos, y;
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(p,1);
		cout<<str1;
		gotoxy(p,2);
		ukr(866);
		for(short i=0; i<l; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,str2);
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
		y=scanf("%d",&pos);
		fflush(stdin);
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

void Delete(int position)
{
	if(head==NULL)
		return;
	lines *pred;
	lines *current=pred=head;
	for(short i=1; i<position && current!=NULL; i++)
	{
		pred=current;
		current=current->next;
	}
	if(current==NULL)
		return;
	else
	{
		if (current==head)
		{
			head=current->next;
			delete current;
			current==NULL;
		}
		else
		{
			pred->next=current->next;
			delete current;
			current=NULL;
		}
	}
   	count-=1;
}

lines *NewLine();

void AddNewLine(lines *element);

string NameOfFile(string str1, string str2, int l, int p);

void SaveToFile(string name);

void CopyToFile(string name1, int position, string name2);

void List();

void DeleteFromFile(string name);

void DeleteFile(string str);

void FreeMemory();

void menu()
{
	int punkt=0, ch;
	string PunktMenu[7]=
	{
		"1) Додати новий рядок ",
		"2) Зберегти до файлу  ",
		"3) Скопіювати до файлу",
		"4) Завантажити з файлу",
		"5) Видалити з файлу   ",
		"6) Видалити файл      ",
		"7) Вийти з програми   "
	};
	while(true)
	{
		ukr(1251);
		textcolor(LightCyan);
		gotoxy(37,1);
		printf("МЕНЮ");
		gotoxy(37,2);
		ukr(866);
		for(short i=0; i<4; i++)
			putchar(196);
		ukr(1251);
		for(int i=0; i<7; i++)
		{
			if (i==punkt)
			{
				textcolor(Black);
				textbackground(LightCyan);
	       		gotoxy(2,4+i);
				cout<<PunktMenu[i];
				textbackground(Black);
	      	}
	      	else
	      	{
	      		textbackground(Black);
	      		textcolor(White);
	   			gotoxy(2,4+i);
				cout<<PunktMenu[i];
			}
		}
		gotoxy(79,13);
		ch=getch();
		switch(ch)
		{
			case 80:
				punkt+=1;
				if(punkt>6)
					punkt=0;
				break;
			case 72:
				punkt-=1;
				if(punkt<0)
					punkt=6;
				break;
			case 13:
				if(punkt==0)
					AddNewLine(NewLine());
				if(punkt==1)
					SaveToFile(NameOfFile(ArrStr[0],ArrStr[1],19,29));
				if(punkt==2)
					CopyToFile(NameOfFile(ArrStr[2],ArrStr[5],19,29),position(ArrStr[2],ArrStr[4],19,29),NameOfFile(ArrStr[2],ArrStr[3],19,29));
				if(punkt==3)
					List();
				if(punkt==4)
					DeleteFromFile(NameOfFile(ArrStr[8],ArrStr[9],17,30));
				if(punkt==5)
					DeleteFile(NameOfFile(ArrStr[10],ArrStr[11],15,31));
				if(punkt==6)
				{
					FreeMemory();
					return;
				}
				break;
		}
	}
}

lines *NewLine()
{
	lines *element=new lines();
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(28,1);
		printf("Додавання нового рядка");
		gotoxy(28,2);
		ukr(866);
		for(short i=0; i<22; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);	
		stroka(15,"Введіть рядок (не більше 73 символів) та натисніть ");
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
		gets(element->row);
		if(strlen(element->row)>73)
		{
			gotoxy(2,9);
			stroka(15,"Рядок містить більше 73 символів. Повторіть введення");
			Sleep(1500);
		}
		else
			break;
	}
	system("cls");
	return(element);
}

void AddNewLine(lines *element)
{
	lines *current;
	if(head==NULL)
	{
		element->next=NULL;
		head=element;
	}
	else
	{
		current=head;
		while(current->next!=NULL)
			current=current->next;
		current->next=element;
		element->next=NULL;
	}
	count+=1;
	return;
}

string NameOfFile(string str1, string str2, int l, int p)
{
	string name;
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(p,1);
		cout<<str1;
		gotoxy(p,2);
		ukr(866);
		for(short i=0; i<l; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);	
		stroka(15,"Введіть ім'я файлу");
		stroka(15,str2);
		stroka(15," та натисніть ");
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
		ukr(1251);
		gotoxy(3,6);
		textcolor(White);
		getline(cin,name);
		int posiziya=name.find(".txt");
		if((name.length()>73)||(posiziya==-1))
		{
			gotoxy(2,9);
			stroka(15,"Занадто довге ім'я файлу/Ім'я файлу не з розширенням .txt. Повторіть введення");
			Sleep(1500);
		}
		else
			break;
	}
	return(name);
}

void SaveToFile(string name)
{
	lines *current=head;
	char imya[73];
	int z;
	for(short i=0; i<name.length(); i++)
	{
		imya[i]=name[i];
		z=i;
	}
	imya[z+1]='\0';
	ofstream file;
	file.open(imya, ios_base::out);
	if(!file.is_open())
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(29,1);
		printf("Збереження до файлу");
		gotoxy(29,2);
		ukr(866);
		for(short i=0; i<19; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Неможливо відкрити файл.");
		Sleep(2500);
		system("cls");
		return;	
	}
	while(current->next!=NULL)
	{
		file<<current->row<<endl;
		current=current->next;
	}
	file<<current->row;
	file.close();
	system("cls");
	return;
}

void CopyToFile(string name_1, int position, string name_2)
{
	if(head!=NULL)
		FreeMemory();
	lines *element, *current;
	char imya_1[73], imya_2[73];
	int z, x;
	for(short i=0; i<name_1.length(); i++)
	{
		imya_1[i]=name_1[i];
		x=i;
	}
	imya_1[x+1]='\0';
	for(short i=0; i<name_2.length(); i++)
	{
		imya_2[i]=name_2[i];
		z=i;
	}
	imya_2[z+1]='\0';
	ifstream fin;
	fin.open(imya_2,ios_base::in);
	if(!fin.is_open())
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(29,1);
		printf("Копіювання до файлу");
		gotoxy(29,2);
		ukr(866);
		for(short i=0; i<20; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Неможливо відкрити файл або ім'я файлу введено неправильно");
		Sleep(2000);
		system("cls");
		return;
	}
	long fin_size;
	fin.seekg(0,ios_base::end);
	fin_size=fin.tellg();
	if(fin_size==0)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(33,1);
		printf("Вміст файлу");
		gotoxy(33,2);
		ukr(866);
		for(short i=0; i<11; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Файл пустий");
		Sleep(1500);
		system("cls");
		fin.close();
		return;
	}
	fin.seekg(0,ios_base::beg);
	while(!fin.eof())
	{
		element=new lines();
		fin.getline(element->row,73);
		if(head==NULL)
		{
			element->next=NULL;
			head=element;
		}
		else
		{
			current=head;
			while(current->next!=NULL)
				current=current->next;
			current->next=element;
			element->next=NULL;
		}
		count+=1;
	}
	fin.close();
	if(position>count)
	{
		FreeMemory();
		system("cls");
		return;
	}
	current=head;
	while(position!=1)
	{
		current=current->next;
		position-=1;
	}
	ofstream fout;
	fout.open(imya_1, ios_base::out);
	if(!fout.is_open())
	{
		system("cls");
		return;	
	}
	while(current->next!=NULL)
	{
		fout<<current->row<<endl;
		current=current->next;
	}
	fout<<current->row;
	fout.close();
	FreeMemory();
	system("cls");
	return;
}

void DownloadFromFile(string name)
{
	if(head!=NULL)
		FreeMemory();
	lines *element, *current;
	char imya[73];
	int z;
	for(short i=0; i<name.length(); i++)
	{
		imya[i]=name[i];
		z=i;
	}
	imya[z+1]='\0';
	ifstream file;
	file.open(imya,ios_base::in);
	if(!file.is_open())
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(29,1);
		printf("Завантаження з файлу");
		gotoxy(29,2);
		ukr(866);
		for(short i=0; i<20; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Неможливо відкрити файл або ім'я файлу введено неправильно");
		Sleep(2000);
		system("cls");
		return;
	}
	long file_size;
	file.seekg(0,ios_base::end);
	file_size=file.tellg();
	if(file_size==0)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(33,1);
		printf("Вміст файлу");
		gotoxy(33,2);
		ukr(866);
		for(short i=0; i<11; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Файл пустий");
		Sleep(1500);
		system("cls");
		file.close();
		return;
	}
	file.seekg(0,ios_base::beg);
	while(!file.eof())
	{
		element=new lines();
		file.getline(element->row,73);
		if(head==NULL)
		{
			element->next=NULL;
			head=element;
		}
		else
		{
			current=head;
			while(current->next!=NULL)
				current=current->next;
			current->next=element;
			element->next=NULL;
		}
		count+=1;
	}
	file.close();
}

void List()
{
	DownloadFromFile(NameOfFile(ArrStr[6],ArrStr[7],20,29));
	if(head==NULL)
		return;
	int counter=0;
	lines *prev, *tmp=head;
	system("cls");
	textcolor(LightCyan);
	gotoxy(33,1);
	printf("Вміст файлу");
	gotoxy(33,2);
	ukr(866);
	for(short i=0; i<11; i++)
		putchar(196);
	ukr(1251);
	textcolor(White);
	tmp=head;
	while(tmp!=NULL)
	{
		prev=tmp;
		gotoxy(2,4+counter);
		cout<<tmp->row;
		tmp=tmp->next;
		counter+=1;
	}
	gotoxy(2, 5+counter);
	printf("Довжина останнього слова останнього рядка = %d",length(prev->row));
	NatBudKlav(25,9+counter);
	system("cls");
	return;
}

void DeleteFromFile(string name)
{
	if(head!=NULL)
		FreeMemory();
	lines *element, *current;
	char imya[73];
	int z;
	for(short i=0; i<name.length(); i++)
	{
		imya[i]=name[i];
		z=i;
	}
	imya[z+1]='\0';
	fstream file;
	file.open(imya,ios_base::in);
	if(!file.is_open())
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(30,1);
		printf("Видалення з файлу");
		gotoxy(30,2);
		ukr(866);
		for(short i=0; i<17; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Неможливо відкрити файл або ім'я файлу введено неправильно");
		Sleep(2000);
		system("cls");
		return;
	}
	long file_size;
	file.seekg(0,ios_base::end);
	file_size=file.tellg();
	if(file_size==0)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(33,1);
		printf("Вміст файлу");
		gotoxy(33,2);
		ukr(866);
		for(short i=0; i<11; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Файл пустий");
		Sleep(1500);
		system("cls");
		file.close();
		return;
	}
	file.seekg(0,ios_base::beg);
	while(!file.eof())
	{
		element=new lines();
		file.getline(element->row,73);
		if(head==NULL)
		{
			element->next=NULL;
			head=element;
		}
		else
		{
			current=head;
			while(current->next!=NULL)
				current=current->next;
			current->next=element;
			element->next=NULL;
		}
		count+=1;
	}
	file.close();
	Delete(position("Видалення з файлу","Введіть позицію видалення та натисніть ",17,30));
	file.open(imya, ios::out);
	if(!file.is_open())
	{
		system("cls");
		return;
	}
	if(head==NULL)
	{
		file.close();
		system("cls");
		return;
	}
	current=head;
	while(current->next!=NULL)
	{
		file<<current->row<<endl;
		current=current->next;
	}
	file<<current->row;
	file.close();
	FreeMemory();
	system("cls");
	return;
}

void DeleteFile(string name)
{
	char imya[73];
	int z;
	for(short i=0; i<name.length(); i++)
	{
		imya[i]=name[i];
		z=i;
	}
	imya[z+1]='\0';
	remove(imya);
	system("cls");
	return;
}

void FreeMemory()
{
	if(head==NULL)
		return;
	lines *prev=head;
	while(prev!=NULL)
	{
		head=prev;
		prev=prev->next;
		delete head;
		head=NULL;
	}
	count=0;
}

int main()
{
	frame();
}
