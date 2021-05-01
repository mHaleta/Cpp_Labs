#include <stdlib.h>
#include<fstream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;

enum color
{
	Black,
    Blue,
    Green,
    Cyan,
    Red,
    Magenta,
    Brown,
    LightGray,
	DarkGray,
	LightBlue,
    LightGreen,
    LightCyan,
	LightRed,
    LightMagenta,
    Yellow,
    White
};

void textcolor(color text)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD) text);
}

void textbackground(color background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD) (background<<4));
}

void set_color(color text, color background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD) (text|background<<4));
}

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput,scrn);
}

void const_row(string str)
{
	int i=0;
	while(i<str.length())
	{
		cout<<str[i];
		Sleep(40);
		i+=1;
		if(kbhit())
			break;
	}
}

void row(int j, string str)
{
	int i=0;
	while(i<str.length())
	{
		cout<<str[i];
		Sleep(j);
		i+=1;
	}
}

void press_any_key(int l, int p)
{
	while(true)
    {
    	gotoxy(l,p);
    	textcolor(Yellow);
    	const_row("Press any key...");
		if(kbhit())
    		break;
    	gotoxy(l,p);
    	textcolor(LightBlue);
    	const_row("Press any key...");
		if(kbhit())
    		break;
    }
    getch();
}

struct route
{
	int number;
	char spunkt[33];
	char fpunkt[33];
	route *next;
};

struct route_1
{
	int number_route;
	char spunkt_route[33];
	char fpunkt_route[33];
};

int count=0;

route *head=NULL;

void menu();

void frame()
{
	system("cls");
	textcolor(LightBlue);
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
    textcolor(Yellow);
    gotoxy(33,3);
	row(15,"Course work");
    gotoxy(23,5);
    row(15,"The theme: Bus routes in Ukraine");
    gotoxy(36,13);
    textcolor(Yellow);
    row(15,"Performed by student group KM-53");
    gotoxy(46,14);
    row(15,"Kuzina Anna");
    gotoxy(38,19);
    row(15,"2016");
    press_any_key(31,22);
    system("cls");
    menu();
}

int compare_number(const void *x1, const void *x2)
{
    route *a=*(route**)x1;
    route *b=*(route**)x2;
    return(a->number-b->number);
}

int compare_depature_point(const void *x1, const void *x2)
{
    route *a=*(route**)x1;
    route *b=*(route**)x2;
    return(strcmp(a->spunkt,b->spunkt));
}

int compare_destination_point(const void *x1, const void *x2)
{
    route *a=*(route**)x1;
    route *b=*(route**)x2;
    return(strcmp(a->fpunkt,b->fpunkt));
}

route_1 *name_of_route()
{
	route_1 *elem=new route_1();
	int y;
	while(true)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(30,1);
		printf("Deleting the route");
		gotoxy(30,2);
		for(short i=0; i<18; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,">Enter a route number and press ");
		textcolor(LightBlue);
		row(15,"ENTER");
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
		textcolor(Yellow);
		y=scanf("%d",&elem->number_route);
		if((y==0)||(elem->number_route<1))
		{
			gotoxy(2,9);
			row(15,"Typing error. Wait");
			Sleep(500);
			fflush(stdin);
		}
		else
			break;
	}
	while(true)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(30,1);
		printf("Deleting the route");
		gotoxy(30,2);
		for(short i=0; i<18; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,">Enter the departure point of the route and press ");
		textcolor(LightBlue);
		row(15,"ENTER");
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
		fflush(stdin);
		textcolor(Yellow);
		gets(elem->spunkt_route);
		if(strlen(elem->spunkt_route)>33)
		{
			gotoxy(2,9);
			row(15,"The length of the line is over then 33. Repeat the input");
			Sleep(1500);
		}
		else
			break;
	}
	while(true)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(30,1);
		printf("Deleting the route");
		gotoxy(30,2);
		for(short i=0; i<18; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,">Enter the destination of the route and press ");
		textcolor(LightBlue);
		row(15,"ENTER");
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
		textcolor(Yellow);
		gets(elem->fpunkt_route);
		if(strlen(elem->fpunkt_route)>33)
		{
			gotoxy(2,9);
			row(15,"The length of the line is over then 33. Repeat the input");
			Sleep(1500);
		}
		else
			break;
	}
	return(elem);
}

void delete_from_list(route_1 *elem)
{
	route *current, *prev;
	current=head;
	prev=head;
	while(current!=NULL)
	{
		if((current->number==elem->number_route)&&(strcmp(current->spunkt,elem->spunkt_route)==0)&&(strcmp(current->fpunkt,elem->fpunkt_route)==0))
		{
			if(current==head)
			{
				head=head->next;
				delete current;
				current=NULL;
				count-=1;
				break;
			}
			else
			{
				prev->next=current->next;
				delete current;
				current=NULL;
				count-=1;
				break;
			}
		}
		else
		{
			prev=current;
			current=current->next;
		}
	}
	system("cls");
	return;
}

route *new_route();

void add_new_route(route *element);

void save_to_file();

void load_from_file();

void choose_sort();

	void sort_number();

	void sort_depature_point();

	void sort_destination_point();

void choose_search();
	
	void search_number();
	
	void search_depature_point();
	
	void search_destination_point();

void list();

void free_memory();

void menu()
{
	int punkt=0, ch;
	string PunktMenu[8]=
	{
		"1) Add new route to the list       ",
		"2) Delete a route from the list    ",
		"3) Display the list on screen      ",
		"4) Search for the route in the list",
		"5) Save the list of routes         ",
		"6) Restore the list of routes      ",
		"7) Delete the whole list           ",
		"8) Exit the program                "
	};
	while(true)
	{
		textcolor(LightBlue);
		gotoxy(37,1);
		printf("MENU");
		gotoxy(37,2);
		for(short i=0; i<4; i++)
			putchar(196);
		textcolor(Yellow);
		for(int i=0; i<8; i++)
		{
			if (i==punkt)
			{
				set_color(Yellow,LightBlue);
	       		gotoxy(2,4+i);
				cout<<PunktMenu[i];
				textbackground(Black);
	      	}
	      	else
	      	{
	      		set_color(Yellow,Black);
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
				if(punkt>7)
					punkt=0;
				break;
			case 72:
				punkt-=1;
				if(punkt<0)
					punkt=7;
				break;
			case 13:
				if(punkt==0)
					add_new_route(new_route());
				if(punkt==1)
				{
					if(head==NULL)
					{
						system("cls");
						textcolor(LightBlue);
						gotoxy(30,1);
						printf("Deleting the route");
						gotoxy(30,2);
						for(short i=0; i<18; i++)
							putchar(196);
						textcolor(Yellow);
						gotoxy(2,4);
						row(15,"The list is empty.");
						Sleep(1500);
						system("cls");
					}
					else
						delete_from_list(name_of_route());
				}
				if(punkt==2)
				{
					system("cls");
					choose_sort();
				}
				if(punkt==3)
				{
					system("cls");
					choose_search();
				}
				if(punkt==4)
					save_to_file();
				if(punkt==5)
					load_from_file();
				if(punkt==6)
					free_memory();
				if(punkt==7)
				{
					free_memory();
					return;
				}
				break;
		}
	}
}

void choose_sort()
{
	int punkt=0, ch;
	string PunktMenu[4]=
	{
		"1) Sort by route number     ",
		"2) Sort by depature point   ",
		"3) Sort by destination point",
		"4) Back to the main menu       "
	};
	while(true)
	{
		textcolor(LightBlue);
		gotoxy(31,1);
		printf("Choose the sort");
		gotoxy(31,2);
		for(short i=0; i<15; i++)
			putchar(196);
		textcolor(Yellow);
		for(int i=0; i<4; i++)
		{
			if (i==punkt)
			{
				set_color(Yellow,LightBlue);
	       		gotoxy(2,4+i);
				cout<<PunktMenu[i];
				textbackground(Black);
	      	}
	      	else
	      	{
	      		set_color(Yellow,Black);
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
				if(punkt>3)
					punkt=0;
				break;
			case 72:
				punkt-=1;
				if(punkt<0)
					punkt=3;
				break;
			case 13:
				if(punkt==0)
					sort_number();
				if(punkt==1)
					sort_depature_point();
				if(punkt==2)
					sort_destination_point();
				if(punkt==3)
				{
					system("cls");
					return;
				}
				break;
		}
	}
}

void choose_search()
{
	int punkt=0, ch;
	string PunktMenu[4]=
	{
		"1) Search the route number     ",
		"2) Search the depature point   ",
		"3) Search the destination point",
		"4) Back to the main menu    "
	};
	while(true)
	{
		textcolor(LightBlue);
		gotoxy(31,1);
		printf("Choose searching");
		gotoxy(31,2);
		for(short i=0; i<16; i++)
			putchar(196);
		textcolor(Yellow);
		for(int i=0; i<4; i++)
		{
			if (i==punkt)
			{
				set_color(Yellow,LightBlue);
	       		gotoxy(2,4+i);
				cout<<PunktMenu[i];
				textbackground(Black);
	      	}
	      	else
	      	{
	      		set_color(Yellow,Black);
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
				if(punkt>3)
					punkt=0;
				break;
			case 72:
				punkt-=1;
				if(punkt<0)
					punkt=3;
				break;
			case 13:
				if(punkt==0)
					search_number();
				if(punkt==1)
					search_depature_point();
				if(punkt==2)
					search_destination_point();
				if(punkt==3)
				{
					system("cls");
					return;
				}
				break;
		}
	}
}

route *new_route()
{
	route *element=new route();
	int y;
	while(true)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(31,1);
		printf("Adding new route");
		gotoxy(31,2);
		for(short i=0; i<16; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,">Enter a route number and press ");
		textcolor(LightBlue);
		row(15,"ENTER");
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
		textcolor(Yellow);
		y=scanf("%d",&element->number);
		if((y==0)||(element->number<1))
		{
			gotoxy(2,9);
			row(15,"Typing error. Wait");
			Sleep(500);
			fflush(stdin);
		}
		else
			break;
	}
	while(true)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(31,1);
		printf("Adding new route");
		gotoxy(31,2);
		for(short i=0; i<16; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,">Enter the departure point of the route and press ");
		textcolor(LightBlue);
		row(15,"ENTER");
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
		fflush(stdin);
		textcolor(Yellow);
		gets(element->spunkt);
		if(strlen(element->spunkt)>33)
		{
			gotoxy(2,9);
			row(15,"The length of the line is over then 33. Repeat the input");
			Sleep(1500);
		}
		else
			break;
	}
	while(true)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(31,1);
		printf("Adding new route");
		gotoxy(31,2);
		for(short i=0; i<16; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,">Enter the destination of the route and press ");
		textcolor(LightBlue);
		row(15,"ENTER");
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
		textcolor(Yellow);
		gets(element->fpunkt);
		if(strlen(element->fpunkt)>33)
		{
			gotoxy(2,9);
			row(15,"The length of the line is over then 33. Repeat the input");
			Sleep(1500);
		}
		else
			break;
	}
	return(element);
}

void add_new_route(route *element)
{
	route *current;
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

void sort_number()
{
	if(head==NULL)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(30,1);
		printf("The list of routes");
		gotoxy(30,2);
		for(short i=0; i<18; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,"The list is empty.");
		Sleep(1500);
		system("cls");
		return;
	}
	route **arr, *current=head;
	arr=(route**)calloc(count,sizeof(route*));
	current=head;
	for(int i=0; i<count; i++)
	{
		arr[i]=current;
		current=current->next;
	}
	qsort(arr,count,sizeof(route*),compare_number);
	head=arr[0];
	current=head;
	for(int i=1; i<count; i++)
	{
		current->next=arr[i];
		current=current->next;
	}
	current->next=NULL;
	list();
	return;
}

void sort_depature_point()
{
	if(head==NULL)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(30,1);
		printf("The list of routes");
		gotoxy(30,2);
		for(short i=0; i<18; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,"The list is empty.");
		Sleep(1500);
		system("cls");
		return;
	}
	route **arr, *current=head;
	arr=(route**)calloc(count,sizeof(route*));
	current=head;
	for(int i=0; i<count; i++)
	{
		arr[i]=current;
		current=current->next;
	}
	qsort(arr,count,sizeof(route*),compare_depature_point);
	head=arr[0];
	current=head;
	for(int i=1; i<count; i++)
	{
		current->next=arr[i];
		current=current->next;
	}
	current->next=NULL;
	list();
	return;
}

void sort_destination_point()
{
	if(head==NULL)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(30,1);
		printf("The list of routes");
		gotoxy(30,2);
		for(short i=0; i<18; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,"The list is empty.");
		Sleep(1500);
		system("cls");
		return;
	}
	route **arr, *current=head;
	arr=(route**)calloc(count,sizeof(route*));
	current=head;
	for(int i=0; i<count; i++)
	{
		arr[i]=current;
		current=current->next;
	}
	qsort(arr,count,sizeof(route*),compare_destination_point);
	head=arr[0];
	current=head;
	for(int i=1; i<count; i++)
	{
		current->next=arr[i];
		current=current->next;
	}
	current->next=NULL;
	list();
	return;
}

void search_number()
{
	if(head==NULL)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(34,1);
		printf("Searching");
		gotoxy(34,2);
		for(short i=0; i<9; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,"The list is empty.");
		Sleep(1500);
		system("cls");
		return;
	}
	int y, number, counter=0;
	route *tmp=head;
	bool b=false;
	while(true)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(34,1);
		printf("Searching");
		gotoxy(34,2);
		for(short i=0; i<9; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,">Enter a route number and press ");
		textcolor(LightBlue);
		row(15,"ENTER");
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
		textcolor(Yellow);
		y=scanf("%d",&number);
		if((y==0)||(number<1))
		{
			gotoxy(2,9);
			row(15,"Typing error. Wait");
			Sleep(500);
			fflush(stdin);
		}
		else
			break;
	}
	while(tmp!=NULL)
	{
		if(number==tmp->number)
		{
			b=true;
			break;
		}
		else
			tmp=tmp->next;
	}
	system("cls");
	textcolor(LightBlue);
	gotoxy(34,1);
	printf("Searching");
	gotoxy(34,2);
	for(short i=0; i<9; i++)
		putchar(196);
	textcolor(Yellow);
	if(b==false)
	{
		gotoxy(2,4);
		row(15,">Now there are no routes with this number");
		press_any_key(31,8);
		system("cls");
		return;
	}
	system("cls");
	textcolor(LightBlue);
	gotoxy(30,1);
	printf("The list of routes");
	gotoxy(30,2);
	for(short i=0; i<18; i++)
		putchar(196);
	gotoxy(1,4);
	putchar(218);
	for(short i=0; i<4; i++)
		putchar(196);
	putchar(194);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(194);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(191);
	gotoxy(1,5);
	putchar(179);
	textcolor(Yellow);
	printf(" No ");
	textcolor(LightBlue);
	putchar(179);
	textcolor(Yellow);
	printf("          Depature point           ");
	textcolor(LightBlue);
	putchar(179);
	textcolor(Yellow);
	printf("         Destination point         ");
	textcolor(LightBlue);
	putchar(179);
	gotoxy(1,6);
	putchar(195);
	for(short i=0; i<4; i++)
		putchar(196);
	putchar(197);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(197);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(180);
	tmp=head;
	while(tmp->next!=NULL)
	{
		if(number==tmp->number)
		{
			textcolor(LightBlue);
			gotoxy(1,7+(2*counter));
			putchar(179);
			textcolor(Yellow);
			gotoxy(3,7+(2*counter));
			printf("%d",tmp->number);
			textcolor(LightBlue);
			gotoxy(6,7+(2*counter));
			putchar(179);
			textcolor(Yellow);
			gotoxy(8,7+(2*counter));
			printf("%s",tmp->spunkt);
			textcolor(LightBlue);
			gotoxy(42,7+(2*counter));
			putchar(179);
			textcolor(Yellow);
			gotoxy(44,7+(2*counter));
			printf("%s",tmp->fpunkt);
			textcolor(LightBlue);
			gotoxy(78, 7+(2*counter));
			putchar(179);
			gotoxy(1,8+(2*counter));
			putchar(195);
			for(short i=0; i<4; i++)
				putchar(196);
			putchar(197);
			for(short i=0; i<35; i++)
				putchar(196);
			putchar(197);
			for(short i=0; i<35; i++)
				putchar(196);
			putchar(180);
			tmp=tmp->next;
			counter+=1;
		}
		else
			tmp=tmp->next;
	}
	if(number==tmp->number)
	{
		textcolor(LightBlue);
		gotoxy(1,7+(2*counter));
		putchar(179);
		textcolor(Yellow);
		gotoxy(3,7+(2*counter));
		printf("%d",tmp->number);
		textcolor(LightBlue);
		gotoxy(6,7+(2*counter));
		putchar(179);
		textcolor(Yellow);
		gotoxy(8,7+(2*counter));
		printf("%s",tmp->spunkt);
		textcolor(LightBlue);
		gotoxy(42,7+(2*counter));
		putchar(179);
		textcolor(Yellow);
		gotoxy(44,7+(2*counter));
		printf("%s",tmp->fpunkt);
		textcolor(LightBlue);
		gotoxy(78, 7+(2*counter));
		putchar(179);
		gotoxy(1,8+(2*counter));
		putchar(192);
		for(short i=0; i<4; i++)
			putchar(196);
		putchar(193);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(193);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(217);
		press_any_key(31,11+(2*counter));
		system("cls");
		return;
	}
	else
	{
		gotoxy(1,6+(2*counter));
		putchar(192);
		for(short i=0; i<4; i++)
			putchar(196);
		putchar(193);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(193);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(217);
		press_any_key(31,9+(2*counter));
		system("cls");
		return;
	}
}

void search_depature_point()
{
	if(head==NULL)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(34,1);
		printf("Searching");
		gotoxy(34,2);
		for(short i=0; i<9; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,"The list is empty.");
		Sleep(1500);
		system("cls");
		return;
	}
	int counter=0;
	route *tmp=head;
	bool b=false;
	char str[33];
	while(true)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(34,1);
		printf("Searching");
		gotoxy(34,2);
		for(short i=0; i<9; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,">Enter the departure point of the route and press ");
		textcolor(LightBlue);
		row(15,"ENTER");
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
		textcolor(Yellow);
		fflush(stdin);
		gets(str);
		if(strlen(str)>33)
		{
			gotoxy(2,9);
			row(15,"The length of the line is over then 33. Repeat the input");
			Sleep(500);
		}
		else
			break;
	}
	while(tmp!=NULL)
	{
		if(strcmp(str,tmp->spunkt)==0)
		{
			b=true;
			break;
		}
		else
			tmp=tmp->next;
	}
	system("cls");
	textcolor(LightBlue);
	gotoxy(34,1);
	printf("Searching");
	gotoxy(34,2);
	for(short i=0; i<9; i++)
		putchar(196);
	textcolor(Yellow);
	if(b==false)
	{
		gotoxy(2,4);
		row(15,">Now there are no routes with this depature point");
		press_any_key(31,8);
		system("cls");
		return;
	}
	system("cls");
	textcolor(LightBlue);
	gotoxy(30,1);
	printf("The list of routes");
	gotoxy(30,2);
	for(short i=0; i<18; i++)
		putchar(196);
	gotoxy(1,4);
	putchar(218);
	for(short i=0; i<4; i++)
		putchar(196);
	putchar(194);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(194);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(191);
	gotoxy(1,5);
	putchar(179);
	textcolor(Yellow);
	printf(" No ");
	textcolor(LightBlue);
	putchar(179);
	textcolor(Yellow);
	printf("          Depature point           ");
	textcolor(LightBlue);
	putchar(179);
	textcolor(Yellow);
	printf("         Destination point         ");
	textcolor(LightBlue);
	putchar(179);
	gotoxy(1,6);
	putchar(195);
	for(short i=0; i<4; i++)
		putchar(196);
	putchar(197);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(197);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(180);
	tmp=head;
	while(tmp->next!=NULL)
	{
		if(strcmp(str,tmp->spunkt)==0)
		{
			textcolor(LightBlue);
			gotoxy(1,7+(2*counter));
			putchar(179);
			textcolor(Yellow);
			gotoxy(3,7+(2*counter));
			printf("%d",tmp->number);
			textcolor(LightBlue);
			gotoxy(6,7+(2*counter));
			putchar(179);
			textcolor(Yellow);
			gotoxy(8,7+(2*counter));
			printf("%s",tmp->spunkt);
			textcolor(LightBlue);
			gotoxy(42,7+(2*counter));
			putchar(179);
			textcolor(Yellow);
			gotoxy(44,7+(2*counter));
			printf("%s",tmp->fpunkt);
			textcolor(LightBlue);
			gotoxy(78, 7+(2*counter));
			putchar(179);
			gotoxy(1,8+(2*counter));
			putchar(195);
			for(short i=0; i<4; i++)
				putchar(196);
			putchar(197);
			for(short i=0; i<35; i++)
				putchar(196);
			putchar(197);
			for(short i=0; i<35; i++)
				putchar(196);
			putchar(180);
			tmp=tmp->next;
			counter+=1;
		}
		else
			tmp=tmp->next;
	}
	if(strcmp(str,tmp->spunkt)==0)
	{
		textcolor(LightBlue);
		gotoxy(1,7+(2*counter));
		putchar(179);
		textcolor(Yellow);
		gotoxy(3,7+(2*counter));
		printf("%d",tmp->number);
		textcolor(LightBlue);
		gotoxy(6,7+(2*counter));
		putchar(179);
		textcolor(Yellow);
		gotoxy(8,7+(2*counter));
		printf("%s",tmp->spunkt);
		textcolor(LightBlue);
		gotoxy(42,7+(2*counter));
		putchar(179);
		textcolor(Yellow);
		gotoxy(44,7+(2*counter));
		printf("%s",tmp->fpunkt);
		textcolor(LightBlue);
		gotoxy(78, 7+(2*counter));
		putchar(179);
		gotoxy(1,8+(2*counter));
		putchar(192);
		for(short i=0; i<4; i++)
			putchar(196);
		putchar(193);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(193);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(217);
		press_any_key(31,11+(2*counter));
		system("cls");
		return;
	}
	else
	{
		gotoxy(1,6+(2*counter));
		putchar(192);
		for(short i=0; i<4; i++)
			putchar(196);
		putchar(193);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(193);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(217);
		press_any_key(31,9+(2*counter));
		system("cls");
		return;
	}
}

void search_destination_point()
{
	if(head==NULL)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(34,1);
		printf("Searching");
		gotoxy(34,2);
		for(short i=0; i<9; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,"The list is empty.");
		Sleep(1500);
		system("cls");
		return;
	}
	int counter=0;
	route *tmp=head;
	bool b=false;
	char str[33];
	while(true)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(34,1);
		printf("Searching");
		gotoxy(34,2);
		for(short i=0; i<9; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,">Enter the destination of the route and press ");
		textcolor(LightBlue);
		row(15,"ENTER");
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
		textcolor(Yellow);
		fflush(stdin);
		gets(str);
		if(strlen(str)>33)
		{
			gotoxy(2,9);
			row(15,"The length of the line is over then 33. Repeat the input");
			Sleep(500);
		}
		else
			break;
	}
	while(tmp!=NULL)
	{
		if(strcmp(str,tmp->fpunkt)==0)
		{
			b=true;
			break;
		}
		else
			tmp=tmp->next;
	}
	system("cls");
	textcolor(LightBlue);
	gotoxy(34,1);
	printf("Searching");
	gotoxy(34,2);
	for(short i=0; i<9; i++)
		putchar(196);
	textcolor(Yellow);
	if(b==false)
	{
		gotoxy(2,4);
		row(15,">Now there are no routes with this destination point");
		press_any_key(25,8);
		system("cls");
		return;
	}
	system("cls");
	textcolor(LightBlue);
	gotoxy(30,1);
	printf("The list of routes");
	gotoxy(30,2);
	for(short i=0; i<18; i++)
		putchar(196);
	gotoxy(1,4);
	putchar(218);
	for(short i=0; i<4; i++)
		putchar(196);
	putchar(194);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(194);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(191);
	gotoxy(1,5);
	putchar(179);
	textcolor(Yellow);
	printf(" No ");
	textcolor(LightBlue);
	putchar(179);
	textcolor(Yellow);
	printf("          Depature point           ");
	textcolor(LightBlue);
	putchar(179);
	textcolor(Yellow);
	printf("         Destination point         ");
	textcolor(LightBlue);
	putchar(179);
	gotoxy(1,6);
	putchar(195);
	for(short i=0; i<4; i++)
		putchar(196);
	putchar(197);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(197);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(180);
	tmp=head;
	while(tmp->next!=NULL)
	{
		if(strcmp(str,tmp->fpunkt)==0)
		{
			textcolor(LightBlue);
			gotoxy(1,7+(2*counter));
			putchar(179);
			textcolor(Yellow);
			gotoxy(3,7+(2*counter));
			printf("%d",tmp->number);
			textcolor(LightBlue);
			gotoxy(6,7+(2*counter));
			putchar(179);
			textcolor(Yellow);
			gotoxy(8,7+(2*counter));
			printf("%s",tmp->spunkt);
			textcolor(LightBlue);
			gotoxy(42,7+(2*counter));
			putchar(179);
			textcolor(Yellow);
			gotoxy(44,7+(2*counter));
			printf("%s",tmp->fpunkt);
			textcolor(LightBlue);
			gotoxy(78, 7+(2*counter));
			putchar(179);
			gotoxy(1,8+(2*counter));
			putchar(195);
			for(short i=0; i<4; i++)
				putchar(196);
			putchar(197);
			for(short i=0; i<35; i++)
				putchar(196);
			putchar(197);
			for(short i=0; i<35; i++)
				putchar(196);
			putchar(180);
			tmp=tmp->next;
			counter+=1;
		}
		else
			tmp=tmp->next;
	}
	if(strcmp(str,tmp->fpunkt)==0)
	{
		textcolor(LightBlue);
		gotoxy(1,7+(2*counter));
		putchar(179);
		textcolor(Yellow);
		gotoxy(3,7+(2*counter));
		printf("%d",tmp->number);
		textcolor(LightBlue);
		gotoxy(6,7+(2*counter));
		putchar(179);
		textcolor(Yellow);
		gotoxy(8,7+(2*counter));
		printf("%s",tmp->spunkt);
		textcolor(LightBlue);
		gotoxy(42,7+(2*counter));
		putchar(179);
		textcolor(Yellow);
		gotoxy(44,7+(2*counter));
		printf("%s",tmp->fpunkt);
		textcolor(LightBlue);
		gotoxy(78,7+(2*counter));
		putchar(179);
		gotoxy(1,8+(2*counter));
		putchar(192);
		for(short i=0; i<4; i++)
			putchar(196);
		putchar(193);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(193);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(217);
		press_any_key(31,11+(2*counter));
		system("cls");
		return;
	}
	else
	{
		gotoxy(1,6+(2*counter));
		putchar(192);
		for(short i=0; i<4; i++)
			putchar(196);
		putchar(193);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(193);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(217);
		press_any_key(31,9+(2*counter));
		system("cls");
		return;
	}
}

void list()
{
	if(head==NULL)
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(30,1);
		printf("The list of routes");
		gotoxy(30,2);
		for(short i=0; i<18; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,"The list is empty.");
		Sleep(1500);
		system("cls");
		return;
	}
	int counter=0;
	route *tmp=head;
	system("cls");
	textcolor(LightBlue);
	gotoxy(30,1);
	printf("The list of routes");
	gotoxy(30,2);
	for(short i=0; i<18; i++)
		putchar(196);
	gotoxy(1,4);
	putchar(218);
	for(short i=0; i<4; i++)
		putchar(196);
	putchar(194);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(194);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(191);
	gotoxy(1,5);
	putchar(179);
	textcolor(Yellow);
	printf(" No ");
	textcolor(LightBlue);
	putchar(179);
	textcolor(Yellow);
	printf("          Depature point           ");
	textcolor(LightBlue);
	putchar(179);
	textcolor(Yellow);
	printf("         Destination point         ");
	textcolor(LightBlue);
	putchar(179);
	gotoxy(1,6);
	putchar(195);
	for(short i=0; i<4; i++)
		putchar(196);
	putchar(197);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(197);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(180);
	tmp=head;
	while(tmp->next!=NULL)
	{
		textcolor(LightBlue);
		gotoxy(1,7+(2*counter));
		putchar(179);
		textcolor(Yellow);
		gotoxy(3,7+(2*counter));
		printf("%d",tmp->number);
		textcolor(LightBlue);
		gotoxy(6,7+(2*counter));
		putchar(179);
		textcolor(Yellow);
		gotoxy(8,7+(2*counter));
		printf("%s",tmp->spunkt);
		textcolor(LightBlue);
		gotoxy(42,7+(2*counter));
		putchar(179);
		textcolor(Yellow);
		gotoxy(44,7+(2*counter));
		printf("%s",tmp->fpunkt);
		textcolor(LightBlue);
		gotoxy(78, 7+(2*counter));
		putchar(179);
		gotoxy(1,8+(2*counter));
		putchar(195);
		for(short i=0; i<4; i++)
			putchar(196);
		putchar(197);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(197);
		for(short i=0; i<35; i++)
			putchar(196);
		putchar(180);
		tmp=tmp->next;
		counter+=1;
	}
	textcolor(LightBlue);
	gotoxy(1,7+(2*counter));
	putchar(179);
	textcolor(Yellow);
	gotoxy(3,7+(2*counter));
	printf("%d",tmp->number);
	textcolor(LightBlue);
	gotoxy(6,7+(2*counter));
	putchar(179);
	textcolor(Yellow);
	gotoxy(8,7+(2*counter));
	printf("%s",tmp->spunkt);
	textcolor(LightBlue);
	gotoxy(42,7+(2*counter));
	putchar(179);
	textcolor(Yellow);
	gotoxy(44,7+(2*counter));
	printf("%s",tmp->fpunkt);
	textcolor(LightBlue);
	gotoxy(78, 7+(2*counter));
	putchar(179);
	gotoxy(1,8+(2*counter));
	putchar(192);
	for(short i=0; i<4; i++)
		putchar(196);
	putchar(193);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(193);
	for(short i=0; i<35; i++)
		putchar(196);
	putchar(217);
	press_any_key(31,11+(2*counter));
	system("cls");
	return;
}

void save_to_file()
{
	route *tmp=head;
	ofstream file;
	file.open("routes.dat",ios::binary|ios::out);
	if(!file.is_open())
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(32,1);
		printf("Saving to file");
		gotoxy(32,2);
		for(short i=0; i<14; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,"Cannot open the file");
		Sleep(2500);
		system("cls");
		return;	
	}
	while(tmp!=NULL)
	{
		file.write((char*)&tmp->number,sizeof(tmp->number));
		file.write((char*)&tmp->spunkt,sizeof(tmp->spunkt));
		file.write((char*)&tmp->fpunkt,sizeof(tmp->fpunkt));
		tmp=tmp->next;
	}
	file.close();
	free_memory();
	system("cls");
	textcolor(LightBlue);
	gotoxy(32,1);
	printf("Saving to file");
	gotoxy(32,2);
	for(short i=0; i<14; i++)
		putchar(196);
	textcolor(Yellow);
	gotoxy(2,4);
	row(15,"The routes have saved");
	Sleep(2500);
	system("cls");
	return;
}

void load_from_file()
{
	if(head!=NULL)
		free_memory();
	route *element, *prev=head, *current=head;
	ifstream file;
	file.open("routes.dat",ios::binary|ios::in);
	if(!file.is_open())
	{
		system("cls");
		textcolor(LightBlue);
		gotoxy(30,1);
		printf("Loading from file");
		gotoxy(30,2);
		for(short i=0; i<17; i++)
			putchar(196);
		textcolor(Yellow);
		gotoxy(2,4);
		row(15,"Cannot open the file");
		Sleep(2500);
		system("cls");
		return;	
	}
	long file_size;
	file.seekg(0,ios_base::end);
	file_size=file.tellg();
	if(file_size==0)
	{
		system("cls");
		file.close();
		return;
	}
	file.seekg(0,ios_base::beg);
	while(!file.eof())
	{
		element=new route();
		file.read((char*)&element->number,sizeof(element->number));
		file.read(element->spunkt,sizeof(element->spunkt));
		file.read(element->fpunkt,sizeof(element->fpunkt));
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
	current=head;
	while(current->next!=NULL)
	{
		prev=current;
		current=current->next;
	}
	prev->next=current->next;
	delete current;
	current=NULL;
	count-=1;
	return;
}

void free_memory()
{
	if(head==NULL)
		return;
	route *prev=head;
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
