#include<mylib.h>

struct patient
{
	char pib[40];
	char adress[40];
	long long int number_of_medical_card;
	long long int number_of_insurance_policy;
	patient *next;
};

patient *head=NULL;

int count=0;

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

long number_of_records()
{
	FILE *file=fopen("patients.dat","rb");
	long number=0;
	if (file==NULL)
		exit(-1);
	fseek(file,0L,2);
	number=ftell(file)/sizeof(patient);
	fclose(file);
	return(number);
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

void list();

void free_memory();

void menu()
{
	int punkt=0, ch;
	const char *PunktMenu[10]=
	{
		" Додати нового пацієнта    ",
		" Зберегти                  ",
		" Зберегти як               ",
		" Завантажити               ",
		" Cписок пацієнтів          ",
		" Пошук пацієнтів           ",
		" Видалити пацієнта         ",
		" Список видалених пацієнтів",
		" Видалити файл             ",
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
		for(int i=0; i<10; i++)
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
				if(punkt>9)
					punkt=0;
				break;
			case 72:
				punkt-=1;
				if(punkt<0)
					punkt=9;
				break;
			case 13:
				if(punkt==0)
					add_new_patient(new_patient());
				if(punkt==1)
					save();
				/*if(punkt==2)
					save_as(name_of_file());*/
				if(punkt==3)
					load();
				if(punkt==4)
					//choose_sort_main();
					list();
				/*if(punkt==5)
					choose_search();*/
				/*if(punkt==6)
					choose_delete();*/
				/*if(punkt==7)
					choose_sort_accesory();*/
				if(punkt==9)
				{
					free_memory();
					return;
				}
				break;
		}
	}
}

patient *new_patient()
{
	int y;
	patient *element=(patient*)malloc(sizeof(patient));
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

void save()
{
	if(head==NULL)
	{
		system("cls");
		return;
	}
	patient *current=head;
	patient *array_of_patients[count];
	for(int i=0; i<count; i++)
	{
		array_of_patients[i]=current;
		current=current->next;
	}
	FILE *file=fopen("patients.dat","ab");
	if(file==NULL)
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
		fwrite(&array_of_patients,sizeof(array_of_patients),count,file);
		current=current->next;
	}
	fclose(file);
	free_memory();
	system("cls");
	return;
}

void load()
{
	system("cls");
	printf("%lu",number_of_records());
	getch();
	system("cls");
	return;
	if(head!=NULL)
		free_memory();
	patient *element, *current;
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
	FILE *file=fopen("patients.dat","rb");
	if(file==NULL)
	{
		stroka(15,"Не існує такого файлу або ім'я файлу введено неправильно");
		Sleep(2000);
		system("cls");
		return;
	}
	long file_size;
	fseek(file,0,SEEK_END);
	file_size=ftell(file);
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
		fclose(file);
		system("cls");
		return;
	}
	fseek(file,0,SEEK_SET);
	//patient **array_of_patients=();
	while(!feof(file))
	{
		element=(patient*)malloc(sizeof(patient));
		fread(&element,sizeof(element),1,file);
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
	fclose(file);
	system("cls");
	return;
}

void list()
{
	if(head==NULL)
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
	patient *tmp=head;
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
		gotoxy(2,4+counter);
		printf("%s",tmp->pib);
		gotoxy(10,4+counter);
		printf("%s",tmp->adress);
		gotoxy(20,4+counter);
		printf("%d",tmp->number_of_medical_card);
		gotoxy(30,4+counter);
		printf("%d",tmp->number_of_insurance_policy);
		tmp=tmp->next;
		counter+=1;
	}
	NatBudKlav(25,7+counter);
	system("cls");
	return;
}

void free_memory()
{
	if(head==NULL)
		return;
	patient *prev=head;
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
