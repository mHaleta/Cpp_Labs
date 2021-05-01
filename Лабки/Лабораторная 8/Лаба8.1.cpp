#include<mylib.h>

struct lines
{
	char row[73];
	struct lines *next;
};

lines *head=NULL;

int count=0;

const char *ArrStr[12]=
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

void stroka(int j, const char *str)
{
	int i=0;
	while(i<strlen(str))
	{
		putchar(str[i]);
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

int position(const char *str1, const char *str2, int l, int p)
{
	int pos, y;
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(p,1);
		printf("%s",str1);
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
			free(current);
			current==NULL;
		}
		else
		{
			pred->next=current->next;
			free(current);
			current=NULL;
		}
	}
   	count-=1;
}

lines *NewLine();

void AddNewLine(lines *element);

char *NameOfFile(const char *str1, const char *str2, int l, int p);

void SaveToFile(char *name);

void CopyToFile(char *name1, int position, char *name2);

void List();

void DownloadFromFile(char *name);

void DeleteFromFile(char *name);

void DeleteFile(char *name);

void FreeMemory();

void menu()
{
	int punkt=0, ch;
	const char *PunktMenu[7]=
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
				printf("%s",PunktMenu[i]);
				textbackground(Black);
	      	}
	      	else
	      	{
	      		textbackground(Black);
	      		textcolor(White);
	   			gotoxy(2,4+i);
				printf("%s",PunktMenu[i]);
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
	lines *element=(lines*)malloc(sizeof(lines));
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
		fflush(stdin);
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
	system("cls");
	return;
}

char *NameOfFile(const char *str1, const char *str2, int l, int p)
{
	char *name=(char*)malloc(sizeof(char));
	char st[]=".txt";
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(p,1);
		printf("%s",str1);
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
		fflush(stdin);
		gets(name);
		if((strlen(name)>73)||(strstr(name,st)==NULL))
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

void SaveToFile(char *name)
{
	if(head==NULL)
	{
		system("cls");
		return;
	}
	lines *current=head;
	FILE *fp=fopen(name,"w");
	if(fp==NULL)
		exit(-1);
	while(current->next!=NULL)
	{
		fputs(current->row,fp);
		fputs("\n",fp);
		current=current->next;
	}
	fputs(current->row,fp);
	fclose(fp);
	FreeMemory();
	free(name);
	system("cls");
	return;
}

void DownloadFromFile(char *name)
{
	lines *element;
	if(head!=NULL)
		FreeMemory();
	lines *prev=head;
	lines *current;
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
	FILE *fp=fopen(name,"r");
	if(fp==NULL)
	{
		stroka(15,"Не існує такого файлу або ім'я файлу введено неправильно");
		Sleep(2000);
		free(name);
		system("cls");
		return;
	}
	long file_size;
	fseek(fp,0,SEEK_END);
	file_size=ftell(fp);
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
		fclose(fp);
		system("cls");
		return;
	}
	fseek(fp,0,SEEK_SET);
	while(!feof(fp))
	{
		element=(lines*)malloc(sizeof(lines));
		fgets(element->row,73,fp);
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
	fclose(fp);
	free(name);
}

void CopyToFile(char *name1, int position, char *name2)
{
	lines *element;
	if(head!=NULL)
		FreeMemory();
	lines *prev=head;
	lines *current;
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
	FILE *f1=fopen(name2,"r");
	if(f1==NULL)
	{
		stroka(15,"Не існує такого файлу ");
		textcolor(LightGreen);
		stroka(15,name2);
		textcolor(White);
		stroka(15," або ім'я файлу введено неправильно");
		Sleep(3000);
		system("cls");
		free(name2);
		return;
	}
	long file_size;
	fseek(f1,0,SEEK_END);
	file_size=ftell(f1);
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
		fclose(f1);
		system("cls");
		free(name2);
		return;
	}
	fseek(f1,0,SEEK_SET);
	while(!feof(f1))
	{
		element=(lines*)malloc(sizeof(lines));
		fgets(element->row,73,f1);
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
	fclose(f1);
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
	FILE *f2=fopen(name1,"w");
	if(f2==NULL)
		exit(-1);
	while(current->next!=NULL)
	{
		fputs(current->row,f2);
		fputs("\n",f2);
		current=current->next;
	}
	fputs(current->row,f2);
	fclose(f2);
	FreeMemory();
	free(name1);
	free(name2);
	system("cls");
	return;
}

void List()
{
	DownloadFromFile(NameOfFile(ArrStr[6],ArrStr[7],20,29));
	if(head==NULL)
		return;
	int counter=0;
	lines *tmp=head, *prev;
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
	while(tmp!=NULL)
	{
		prev=tmp;
		gotoxy(2,4+counter);
		printf("%s",tmp->row);
		tmp=tmp->next;
		counter+=1;
	}
	gotoxy(2, 5+counter);
	printf("Довжина останнього слова останнього рядка = %d",length(prev->row));
	NatBudKlav(25,9+counter);
	system("cls");
	return;
}

void DeleteFromFile(char *name)
{
	if(head!=NULL)
		FreeMemory();
	lines *current, *element;
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
	FILE *fp=fopen(name,"r");
	if(fp==NULL)
	{
		stroka(15,"Не існує такого файлу або ім'я файлу введено неправильно");
		Sleep(2000);
		free(name);
		system("cls");
		return;
	}
	long file_size;
	fseek(fp,0,SEEK_END);
	file_size=ftell(fp);
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
		fclose(fp);
		system("cls");
		return;
	}
	fseek(fp,0,SEEK_SET);
	while(!feof(fp))
	{
		element=(lines*)malloc(sizeof(lines));
		fgets(element->row,73,fp);
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
	fclose(fp);
	Delete(position("Видалення з файлу","У прямокутнику введіть позицію видалення та натисніть ",17,30));
	fp=fopen(name,"w");
	current=head;
	if(fp==NULL)
		exit(-1);
	while(current->next!=NULL)
	{
		fputs(current->row,fp);
		fputs("\n",fp);
		current=current->next;
	}
	fputs(current->row,fp);
	fclose(fp);
	free(name);
	FreeMemory();
	system("cls");
	return;
}

void DeleteFile(char *name)
{
	remove(name);
	free(name);
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
		free(head);
		head=NULL;
	}
	count=0;
}

int main()
{
	frame();
}
