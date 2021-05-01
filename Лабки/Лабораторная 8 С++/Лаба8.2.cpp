#include<mylib.h>
#include<iostream>
#include<fstream>
using namespace std;

struct patient
{
	char pib[40];
	char adress[40];
	int number_of_medical_card;
	int number_of_insurance_policy;
	patient *next;
};

patient *head_main=NULL, *first_main=NULL, *head_accesory=NULL;

int count1=0, count2=0;

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
    gotoxy(25,5);
    stroka(15,"Тема: Бінарні файли у мові С");
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

patient *new_patient();

void add_new_patient(patient *);

void save();

void load();

void list(patient *);

void choose_sort();

void choose_search();

void delete_patient();

void recovery_patient();

void free_memory_head_main();

void free_memory_first_main();

void free_memory_head_accesory();

void menu()
{
	int punkt=0, ch;
	string PunktMenu[9]=
	{
		" Завантажити               ",
		" Додати нового пацієнта    ",
		" Зберегти                  ",
		" Cписок пацієнтів          ",
		" Пошук пацієнтів           ",
		" Видалити пацієнта         ",
		" Відновити пацієнта        ",
		" Список видалених пацієнтів",
		" Вийти з програми          ",
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
		for(int i=0; i<9; i++)
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
				if(punkt>8)
					punkt=0;
				break;
			case 72:
				punkt-=1;
				if(punkt<0)
					punkt=8;
				break;
			case 13:
				if(punkt==0)
					load();
				if(punkt==1)
					add_new_patient(new_patient());
				if(punkt==2)
					save();
				if(punkt==3)
				{
					system("cls");
					choose_sort();
				}
				if(punkt==4)
				{
					system("cls");
					choose_search();
				}
				if(punkt==5)
					delete_patient();
				if(punkt==6)
					recovery_patient();
				if(punkt==7)
					list(head_accesory);
				if(punkt==8)
				{
					free_memory_head_main();
					free_memory_head_accesory();
					return;
				}
				break;
		}
	}
}

patient *new_patient()
{
	int y;
	patient *element=new patient();
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(26,1);
		printf("Додавання нового пацієнта");
		gotoxy(26,2);
		ukr(866);
		for(short i=0; i<25; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);	
		stroka(15,"Введіть ПІБ пацієнта та натисніть ");
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
		gets(element->pib);
		if(strlen(element->pib)>40)
		{
			gotoxy(2,9);
			stroka(15,"Рядок містить більше 40 символів. Повторіть введення");
			Sleep(1500);
		}
		else
			break;
	}
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(26,1);
		printf("Додавання нового пацієнта");
		gotoxy(26,2);
		ukr(866);
		for(short i=0; i<25; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);	
		stroka(15,"Введіть адресу пацієнта та натисніть ");
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
		gets(element->adress);
		if(strlen(element->adress)>40)
		{
			gotoxy(2,9);
			stroka(15,"Рядок містить більше 40 символів. Повторіть введення");
			Sleep(1500);
		}
		else
			break;
	}
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(26,1);
		printf("Додавання нового пацієнта");
		gotoxy(26,2);
		ukr(866);
		for(short i=0; i<25; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);	
		stroka(15,"Введіть номер медичної картки пацієнта та натисніть ");
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
		y=scanf("%d",&element->number_of_medical_card);
		if(y==0)
		{
			gotoxy(2,9);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(1500);
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
		printf("Додавання нового пацієнта");
		gotoxy(26,2);
		ukr(866);
		for(short i=0; i<25; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);	
		stroka(15,"Введіть номер страхового поліса пацієнта та натисніть ");
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
		y=scanf("%d",&element->number_of_insurance_policy);
		if(y==0)
		{
			gotoxy(2,9);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(1500);
			fflush(stdin);
		}
		else
			break;
	}
	return(element);
}

void add_new_patient(patient *element)
{
	patient *current;
	if(head_main==NULL)
	{
		element->next=NULL;
		head_main=element;
	}
	else
	{
		current=head_main;
		while(current->next!=NULL)
			current=current->next;
		current->next=element;
		element->next=NULL;
	}
	count1+=1;
	system("cls");
	return;
}

void save()
{
	if(head_main==NULL)
	{
		system("cls");
		return;
	}
	patient *current=head_main;
	ofstream file;
	file.open("patients.dat",ios::binary|ios::out);
	if(!file.is_open())
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(29,1);
		printf("Збереження до файлу");
		gotoxy(29,2);
		ukr(866);
		for(short i=0; i<19; i++)
			putchar(196);
		ukr(1251);
		textcolor(Yellow);
		gotoxy(2,4);
		stroka(15,"Неможливо відкрити файл");
		Sleep(2500);
		system("cls");
		return;
	}
	while(current!=NULL)
	{
		file.write(current->pib,sizeof(current->pib));
		file.write(current->adress,sizeof(current->adress));
		file.write((char*)&current->number_of_medical_card,sizeof(current->number_of_medical_card));
		file.write((char*)&current->number_of_insurance_policy,sizeof(current->number_of_insurance_policy));
		current=current->next;
	}
	file.close();
	free_memory_head_main();
	system("cls");
	return;
}

void load()
{
	if(head_main!=NULL)
		free_memory_head_main();
	patient *element, *current=head_main, *prev=head_main;
	ifstream file;
	file.open("patients.dat",ios::binary|ios::in);
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
		stroka(15,"Неможливо відкрити файл");
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
		system("cls");
		return;
	}
	file.seekg(0,ios_base::beg);
	while(!file.eof())
	{
		element=new patient();
		file.read(element->pib,sizeof(element->pib));
		file.read(element->adress,sizeof(element->adress));
		file.read((char*)&element->number_of_medical_card,sizeof(element->number_of_medical_card));
		file.read((char*)&element->number_of_insurance_policy,sizeof(element->number_of_insurance_policy));
		if(head_main==NULL)
		{
			element->next=NULL;
			head_main=element;
		}
		else
		{
			current=head_main;
			while(current->next!=NULL)
				current=current->next;
			current->next=element;
			element->next=NULL;
		}
		count1+=1;
	}
	file.close();
	current=head_main;
	while(current->next!=NULL)
	{
		prev=current;
		current=current->next;
	}
	prev->next=current->next;
	delete current;
	current=NULL;
	count1-=1;
	system("cls");
	return;
}

int compare_pib(const void *x1, const void *x2)
{
    patient *a=*(patient**)x1;
    patient *b=*(patient**)x2;
    return(strcmp(a->pib,b->pib));
}

int compare_number_card(const void *x1, const void *x2)
{
    patient *a=*(patient**)x1;
    patient *b=*(patient**)x2;
    return(a->number_of_medical_card-b->number_of_medical_card);
}

void sort_pib();

void sort_number_card();

void choose_sort()
{
	int punkt=0, ch;
	string PunktMenu[3]=
	{
		" Впорядкувати пацієнтів за ПІБ                     ",
		" Впорядкувати пацієнтів за номером медичної картки ",
		" Повернутися до головного меню                     "
	};
	while(true)
	{
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("Список пацієнтів");
		gotoxy(31,2);
		ukr(866);
		for(short i=0; i<16; i++)
			putchar(196);
		ukr(1251);
		for(int i=0; i<3; i++)
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
				if(punkt>2)
					punkt=0;
				break;
			case 72:
				punkt-=1;
				if(punkt<0)
					punkt=2;
				break;
			case 13:
				if(punkt==0)
					sort_pib();
				if(punkt==1)
					sort_number_card();
				if(punkt==2)
				{
					system("cls");
					return;
				}
				break;
		}
	}
}

void sort_pib()
{
	if(head_main==NULL)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("Список пацієнтів");
		gotoxy(31,2);
		ukr(866);
		for(short i=0; i<16; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Список пустий");
		Sleep(1500);
		system("cls");
		return;
	}
	patient **array_of_patients, *current=head_main;
	array_of_patients=(patient**)calloc(count1,sizeof(patient*));
	current=head_main;
	for(int i=0; i<count1; i++)
	{
		array_of_patients[i]=current;
		current=current->next;
	}
	qsort(array_of_patients,count1,sizeof(patient*),compare_pib);
	head_main=array_of_patients[0];
	current=head_main;
	for(int i=1; i<count1; i++)
	{
		current->next=array_of_patients[i];
		current=current->next;
	}
	current->next=NULL;
	list(head_main);
	return;
}

void sort_number_card()
{
	if(head_main==NULL)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("Список пацієнтів");
		gotoxy(31,2);
		ukr(866);
		for(short i=0; i<16; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Список пустий");
		Sleep(1500);
		system("cls");
		return;
	}
	patient **array_of_patients, *current=head_main;
	array_of_patients=(patient**)calloc(count1,sizeof(patient*));
	current=head_main;
	for(int i=0; i<count1; i++)
	{
		array_of_patients[i]=current;
		current=current->next;
	}
	qsort(array_of_patients,count1,sizeof(patient*),compare_number_card);
	head_main=array_of_patients[0];
	current=head_main;
	for(int i=1; i<count1; i++)
	{
		current->next=array_of_patients[i];
		current=current->next;
	}
	current->next=NULL;
	list(head_main);
	return;
}

void list(patient *pointer)
{
	if(pointer==NULL)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("Список пацієнтів");
		gotoxy(31,2);
		ukr(866);
		for(short i=0; i<16; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Список пустий");
		Sleep(1500);
		system("cls");
		return;
	}
	int counter=0;
	patient *temp=pointer;
	system("cls");
	textcolor(LightCyan);
	gotoxy(31,1);
	printf("Список пацієнтів");
	gotoxy(31,2);
	ukr(866);
	for(short i=0; i<16; i++)
		putchar(196);
	gotoxy(1,4);
	putchar(218);
	for(short i=0; i<42; i++)
		putchar(196);
	putchar(194);
	for(short i=0; i<42; i++)
		putchar(196);
	putchar(194);
	for(short i=0; i<12; i++)
		putchar(196);
	putchar(194);
	for(short i=0; i<12; i++)
		putchar(196);
	putchar(191);
	gotoxy(1,5);
	putchar(179);
	textcolor(White);
	ukr(1251);
	printf("   Прізвише, ім'я, по-батькові пацієнта   ");
	ukr(866);
	textcolor(LightCyan);
	putchar(179);
	textcolor(White);
	ukr(1251);
	printf("             Адреса пацієнта              ");
	ukr(866);
	textcolor(LightCyan);
	putchar(179);
	textcolor(White);
	ukr(1251);
	printf("  № картки  ");
	ukr(866);
	textcolor(LightCyan);
	putchar(179);
	textcolor(White);
	ukr(1251);
	printf("  № полісу  ");
	ukr(866);
	textcolor(LightCyan);
	putchar(179);
	gotoxy(1,6);
	putchar(195);
	for(short i=0; i<42; i++)
		putchar(196);
	putchar(197);
	for(short i=0; i<42; i++)
		putchar(196);
	putchar(197);
	for(short i=0; i<12; i++)
		putchar(196);
	putchar(197);
	for(short i=0; i<12; i++)
		putchar(196);
	putchar(180);
	while(temp->next!=NULL)
	{
		textcolor(LightCyan);
		gotoxy(1,7+(2*counter));
		ukr(866);
		putchar(179);
		ukr(1251);
		textcolor(White);
		gotoxy(3,7+(2*counter));
		printf("%s",temp->pib);
		textcolor(LightCyan);
		gotoxy(44,7+(2*counter));
		ukr(866);
		putchar(179);
		ukr(1251);
		textcolor(White);
		gotoxy(46,7+(2*counter));
		printf("%s",temp->adress);
		textcolor(LightCyan);
		gotoxy(87,7+(2*counter));
		ukr(866);
		putchar(179);
		ukr(1251);
		textcolor(White);
		gotoxy(89,7+(2*counter));
		printf("%d",temp->number_of_medical_card);
		textcolor(LightCyan);
		gotoxy(100, 7+(2*counter));
		ukr(866);
		putchar(179);
		ukr(1251);
		textcolor(White);
		gotoxy(102,7+(2*counter));
		printf("%d",temp->number_of_insurance_policy);
		textcolor(LightCyan);
		gotoxy(113, 7+(2*counter));
		ukr(866);
		putchar(179);
		gotoxy(1,8+(2*counter));
		putchar(195);
		for(short i=0; i<42; i++)
			putchar(196);
		putchar(197);
		for(short i=0; i<42; i++)
			putchar(196);
		putchar(197);
		for(short i=0; i<12; i++)
			putchar(196);
		putchar(197);
		for(short i=0; i<12; i++)
			putchar(196);
		putchar(180);
		temp=temp->next;
		counter+=1;
	}
	textcolor(LightCyan);
	gotoxy(1,7+(2*counter));
	ukr(866);
	putchar(179);
	ukr(1251);
	textcolor(White);
	gotoxy(3,7+(2*counter));
	printf("%s",temp->pib);
	textcolor(LightCyan);
	gotoxy(44,7+(2*counter));
	ukr(866);
	putchar(179);
	ukr(1251);
	textcolor(White);
	gotoxy(46,7+(2*counter));
	printf("%s",temp->adress);
	textcolor(LightCyan);
	gotoxy(87,7+(2*counter));
	ukr(866);
	putchar(179);
	ukr(1251);
	textcolor(White);
	gotoxy(89,7+(2*counter));
	printf("%d",temp->number_of_medical_card);
	textcolor(LightCyan);
	gotoxy(100, 7+(2*counter));
	ukr(866);
	putchar(179);
	ukr(1251);
	textcolor(White);
	gotoxy(102,7+(2*counter));
	printf("%d",temp->number_of_insurance_policy);
	textcolor(LightCyan);
	gotoxy(113, 7+(2*counter));
	ukr(866);
	putchar(179);
	gotoxy(1,8+(2*counter));
	putchar(192);
	for(short i=0; i<42; i++)
		putchar(196);
	putchar(193);
	for(short i=0; i<42; i++)
		putchar(196);
	putchar(193);
	for(short i=0; i<12; i++)
		putchar(196);
	putchar(193);
	for(short i=0; i<12; i++)
		putchar(196);
	putchar(217);
	ukr(1251);
	NatBudKlav(31,11+(2*counter));
	system("cls");
	return;
}

void search_pib();

void search_number_card();

void choose_search()
{
	int punkt=0, ch;
	string PunktMenu[3]=
	{
		" Пошук пацієнта за ПІБ                     ",
		" Пошук пацієнта за номером медичної картки ",
		" Повернутися до головного меню             "
	};
	while(true)
	{
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("Пошук пацієнтів");
		gotoxy(31,2);
		ukr(866);
		for(short i=0; i<15; i++)
			putchar(196);
		ukr(1251);
		for(int i=0; i<3; i++)
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
		textcolor(White);
		gotoxy(79,13);
		ch=getch();
		switch(ch)
		{
			case 80:
				punkt+=1;
				if(punkt>2)
					punkt=0;
				break;
			case 72:
				punkt-=1;
				if(punkt<0)
					punkt=2;
				break;
			case 13:
				if(punkt==0)
					search_pib();
				if(punkt==1)
					search_number_card();
				if(punkt==2)
				{
					system("cls");
					return;
				}
				break;
		}
	}
}

void search_pib()
{
	if(head_main==NULL)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("Пошук пацієнтів");
		gotoxy(31,2);
		ukr(866);
		for(short i=0; i<15; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Список пустий");
		Sleep(1500);
		system("cls");
		return;
	}
	char s[40];
	patient *tmp=head_main, *element_for_first, *current_for_first=first_main;
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("Пошук пацієнтів");
		gotoxy(31,2);
		ukr(866);
		for(short i=0; i<15; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);	
		stroka(15,"Введіть ПІБ пацієнта та натисніть ");
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
		gets(s);
		if(strlen(s)>40)
		{
			gotoxy(2,9);
			stroka(15,"Рядок містить більше 40 символів. Повторіть введення");
			Sleep(1500);
		}
		else
			break;
	}
	while(tmp!=NULL)
	{
		if(strcmp(s,tmp->pib)==0)
		{
			element_for_first=new patient();
			strcpy(element_for_first->pib, tmp->pib);
			strcpy(element_for_first->adress, tmp->adress);
			element_for_first->number_of_medical_card=tmp->number_of_medical_card;
			element_for_first->number_of_insurance_policy=tmp->number_of_insurance_policy;
			if(first_main==NULL)
			{
				element_for_first->next=NULL;
				first_main=element_for_first;
			}
			else
			{
				current_for_first=first_main;
				while(current_for_first->next!=NULL)
					current_for_first=current_for_first->next;
				current_for_first->next=element_for_first;
				element_for_first->next=NULL;
			}
		}
		tmp=tmp->next;
	}
	list(first_main);
	free_memory_first_main();
}

void search_number_card()
{
	if(head_main==NULL)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("Пошук пацієнтів");
		gotoxy(31,2);
		ukr(866);
		for(short i=0; i<15; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Список пустий");
		Sleep(1500);
		system("cls");
		return;
	}
	int y, number;
	patient *tmp=head_main, *element_for_first, *current_for_first=first_main;
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(31,1);
		printf("Пошук пацієнтів");
		gotoxy(31,2);
		ukr(866);
		for(short i=0; i<15; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);	
		stroka(15,"Введіть номер картки пацієнта та натисніть ");
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
		y=scanf("%d",&number);
		if(y==0)
		{
			gotoxy(2,9);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(1500);
			fflush(stdin);
		}
		else
			break;
	}
	while(tmp!=NULL)
	{
		if(number==tmp->number_of_medical_card)
		{
			element_for_first=new patient();
			strcpy(element_for_first->pib, tmp->pib);
			strcpy(element_for_first->adress, tmp->adress);
			element_for_first->number_of_medical_card=tmp->number_of_medical_card;
			element_for_first->number_of_insurance_policy=tmp->number_of_insurance_policy;
			if(first_main==NULL)
			{
				element_for_first->next=NULL;
				first_main=element_for_first;
			}
			else
			{
				current_for_first=first_main;
				while(current_for_first->next!=NULL)
					current_for_first=current_for_first->next;
				current_for_first->next=element_for_first;
				element_for_first->next=NULL;
			}
		}
		tmp=tmp->next;
	}
	list(first_main);
	free_memory_first_main();
}

void delete_patient()
{
	if(head_main==NULL)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(29,1);
		printf("Видалення пацієнтів");
		gotoxy(29,2);
		ukr(866);
		for(short i=0; i<19; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Список пустий");
		Sleep(1500);
		system("cls");
		return;
	}
	char s[40];
	int y, number;
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(29,1);
		printf("Видалення пацієнтів");
		gotoxy(29,2);
		ukr(866);
		for(short i=0; i<19; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Введіть ПІБ пацієнта та натисніть ");
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
		gets(s);
		if(strlen(s)>40)
		{
			gotoxy(2,9);
			stroka(15,"Рядок містить більше 40 символів. Повторіть введення");
			Sleep(1500);
		}
		else
			break;
	}
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(29,1);
		printf("Видалення пацієнтів");
		gotoxy(29,2);
		ukr(866);
		for(short i=0; i<19; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Введіть номер картки пацієнта та натисніть ");
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
		y=scanf("%d",&number);
		if(y==0)
		{
			gotoxy(2,9);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(1500);
			fflush(stdin);
		}
		else
			break;
	}
	patient *prev_main=head_main, *current_main=head_main, *current_accesory, *element_accesory;
	while(current_main!=NULL)
	{
		if((strcmp(s,current_main->pib)==0)&&(number==current_main->number_of_medical_card))
		{
			element_accesory=new patient();
			strcpy(element_accesory->pib,current_main->pib);
			strcpy(element_accesory->adress,current_main->adress);
			element_accesory->number_of_medical_card=current_main->number_of_medical_card;
			element_accesory->number_of_insurance_policy=current_main->number_of_insurance_policy;
			if(current_main==head_main)
			{
				
				if(head_accesory==NULL)
				{
					element_accesory->next=NULL;
					head_accesory=element_accesory;
				}
				else
				{
					current_accesory=head_accesory;
					while(current_accesory->next!=NULL)
						current_accesory=current_accesory->next;
					current_accesory->next=element_accesory;
					element_accesory->next=NULL;
				}
				count2+=1;
				head_main=head_main->next;
				delete current_main;
				current_main=NULL;
				count1-=1;
				break;
			}
			else
			{
				if(head_accesory==NULL)
				{
					element_accesory->next=NULL;
					head_accesory=element_accesory;
				}
				else
				{
					current_accesory=head_accesory;
					while(current_accesory->next!=NULL)
						current_accesory=current_accesory->next;
					current_accesory->next=element_accesory;
					element_accesory->next=NULL;
				}
				count2+=1;
				prev_main->next=current_main->next;
				delete current_main;
				current_main=NULL;
				count1-=1;
				break;
			}
		}
		else
		{
			prev_main=current_main;
			current_main=current_main->next;
		}
	}
	system("cls");
	return;
}

void recovery_patient()
{
	if(head_accesory==NULL)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(28,1);
		printf("Відновлення пацієнтів");
		gotoxy(28,2);
		ukr(866);
		for(short i=0; i<19; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Список видалених пацієнтів пустий");
		Sleep(1500);
		system("cls");
		return;
	}
	char s[40];
	int y, number;
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(29,1);
		printf("Видалення пацієнтів");
		gotoxy(29,2);
		ukr(866);
		for(short i=0; i<19; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Введіть ПІБ пацієнта та натисніть ");
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
		gets(s);
		if(strlen(s)>40)
		{
			gotoxy(2,9);
			stroka(15,"Рядок містить більше 40 символів. Повторіть введення");
			Sleep(1500);
		}
		else
			break;
	}
	while(true)
	{
		system("cls");
		textcolor(LightCyan);
		gotoxy(29,1);
		printf("Видалення пацієнтів");
		gotoxy(29,2);
		ukr(866);
		for(short i=0; i<19; i++)
			putchar(196);
		ukr(1251);
		textcolor(White);
		gotoxy(2,4);
		stroka(15,"Введіть номер картки пацієнта та натисніть ");
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
		y=scanf("%d",&number);
		if(y==0)
		{
			gotoxy(2,9);
			stroka(15,"Помилка введення. Зачекайте");
			Sleep(1500);
			fflush(stdin);
		}
		else
			break;
	}
	patient *current_main, *element_main, *current_accesory=head_accesory, *prev_accesory=head_accesory;
	while(current_accesory!=NULL)
	{
		if((strcmp(s,current_accesory->pib)==0)&&(number==current_accesory->number_of_medical_card))
		{
			element_main=new patient();
			strcpy(element_main->pib,current_accesory->pib);
			strcpy(element_main->adress,current_accesory->adress);
			element_main->number_of_medical_card=current_accesory->number_of_medical_card;
			element_main->number_of_insurance_policy=current_accesory->number_of_insurance_policy;
			if(current_accesory==head_accesory)
			{
				if(head_main==NULL)
				{
					element_main->next=NULL;
					head_main=element_main;
				}
				else
				{
					current_main=head_main;
					while(current_main->next!=NULL)
						current_main=current_main->next;
					current_main->next=element_main;
					element_main->next=NULL;
				}
				count1+=1;
				head_accesory=head_accesory->next;
				delete current_accesory;
				current_accesory=NULL;
				count2-=1;
				break;
			}
			else
			{
				if(head_main==NULL)
				{
					element_main->next=NULL;
					head_main=element_main;
				}
				else
				{
					current_main=head_main;
					while(current_main->next!=NULL)
						current_main=current_main->next;
					current_main->next=element_main;
					element_main->next=NULL;
				}
				count1+=1;
				prev_accesory->next=current_accesory->next;
				delete current_accesory;
				current_accesory=NULL;
				count2-=1;
				break;
			}
		}
		else
		{
			prev_accesory=current_accesory;
			current_accesory=current_accesory->next;
		}
	}
	system("cls");
	return;
}

void free_memory_head_main()
{
	if(head_main==NULL)
		return;
	patient *prev=head_main;
	while(prev!=NULL)
	{
		head_main=prev;
		prev=prev->next;
		delete head_main;
		head_main=NULL;
	}
	count1=0;
}

void free_memory_first_main()
{
	if(first_main==NULL)
		return;
	patient *prev=first_main;
	while(prev!=NULL)
	{
		first_main=prev;
		prev=prev->next;
		delete first_main;
		first_main=NULL;
	}
}

void free_memory_head_accesory()
{
	if(head_accesory==NULL)
		return;
	patient *prev=head_accesory;
	while(prev!=NULL)
	{
		head_accesory=prev;
		prev=prev->next;
		delete head_accesory;
		head_accesory=NULL;
	}
	count2=0;
}

int main()
{
	frame();
}
