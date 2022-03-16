	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include <conio.h>
	#include <windows.h>
	#include <dos.h>
	#include <locale.h>
	#include <time.h>
	#define RETURNTIME 15
	
	char categories[][15] = {"Computer", "Electronics", "Electrical", "Physics", "Maths", "English"};
	void returnfun();
	void mainmenu();
	void addbooks();
	void deletebooks();
	void editbooks();
	void searchbooks();
	void issuebooks();
	void viewbooks();
	void closeapplication();
	int getdata();
	int checkid(int);
	int t(void);
	void notification();
	void Password();
	void issuerecord();
	void loaderanim();
	void design();
	
	FILE *fp, *ft, *fs;
	COORD coord = {0, 0};
	
	int s;
	char findbook,G;
	char password[4] = {"byme"};
	
	void gotoxy(int x, int y)
	{
	    coord.X = x;
	    coord.Y = y;
	    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	struct meroDate
	{
	    int mm, dd, yy;
	};
	struct books
	{
	    int id;
	    char stname[20];
	    char name[20];
	    char Author[20];
	    int quantity;
	    float price;
	    int count;
	    char *cat;
	    int rackno;
	    struct meroDate issued;
	    struct meroDate duedate;
	};
	struct books a;
	/*struct datelk{
	
	SYSTEMTIME dtime;
	GetSystemTime(&dtime);
	int day = dtime.wDay;
	int month = dtime.wMonth;
	int year = dtime.wYear;
	};*/
	//GetSystemTime(&stime);
	struct issuedate
	{
	int day,month,year;
	}d;
	struct returndate
	{
	int day,moth,year;
	}e;
	void timedate()
	{
	SYSTEMTIME stime;
	GetSystemTime(&stime);
	printf("\nDate: %d/%d/%d", stime.wDay, stime.wMonth, stime.wYear);
	printf("\nDay: ");
	switch (stime.wDayOfWeek)
	{
	case 1:
	printf("Monday");
	break;
	case 2:
	printf("Tuesday");
	break;
	case 3:
	printf("Wednesday");
	break;
	case 4:
	printf("Thursday");
	break;
	case 5:
	printf("Friday");
	break;
	case 6:
	printf("Saturday");
	break;
	case 7:
	printf("Sunday");
	break;
	}
	
	}
	
	int main()
	{
	    // Password();
	    mainmenu();
	    getch();
	    return 0;
	}
	void mainmenu()
	{
	    system("cls");
	    system("color e4");
	    int i;
	    gotoxy(20, 2);
	    printf("\xB04\xB04\xB04\xB04\xB04\xB04\xB04  Main Menu  \xB04\xB04\xB04\xB04\xB04\xB04\xB04");
	    gotoxy(20, 4);
	    printf("\xB10 1. Add Books ");
	    gotoxy(20, 6);
	    printf("\xB10 2. Delete Books  ");
	    gotoxy(20, 8);
	    printf("\xB10 3. Search Books  ");
	    gotoxy(20, 10);
	    printf("\xB10 4. Issue Books  ");
	    gotoxy(20, 12);
	    printf("\xB10 5. View Books list  ");
	    gotoxy(20, 14);
	    printf("\xB10 6. Edit Book`s record  ");
	    gotoxy(20, 16);
	    printf("\xB10 7. Close Application ");
	    notification();
	    gotoxy(20, 18);
	    printf("\xB10 8.");
	    gotoxy(20, 20);
	    printf("\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04\xB04");
	    gotoxy(20, 21);
	    t();
	    gotoxy(20, 22);
	    printf("Enter your choice: ");
	    switch (getch())
	    {
	
	    case '1':
	        addbooks();
	        break;
	    case '2':
	        deletebooks();
	        break;
	    case '3':
	        searchbooks();
	        break;
	    case '4':
	        issuebooks();
	        break;
	    case '5':
	    //timedate();
	        viewbooks();
	        break;
	    case '6':
	        editbooks();
	        break;
	    case '7':
	    {
	        system("cls");
	        exit(0);
	    }
	    case '8':
	    {
	        printf("Not defined yet");
	        break;
	    }
	
	    default:
	    {
	
	        printf("PLease re enter correct option");
	        if (getch())
	           
	        mainmenu();
	    }
	    }
	}
	int t()
	{
	    time_t t;
	    time(&t);
	    printf("Date and Time:%s", ctime(&t));
	    return 0;
	}
	
	void Password()
	{
	
	    system("cls");
	    char d[25] = "Password Protected";
	    char ch, pass[10];
	    int i = 0, j, c = 0;
	    gotoxy(10, 4);
	    for (j = 0; j < 20; j++)
	    {
	        Sleep(30);
	        printf("*");
	    }
	    for (j = 0; j < 20; j++)
	    {
	        Sleep(100);
	        printf("%c", d[j]);
	    }
	    for (j = 0; j < 20; j++)
	    {
	        Sleep(30);
	        printf("*");
	    }
	    gotoxy(15, 7);
	    printf("Enter the password: ");
	    while (ch != 13)
	    {
	        ch = getch();
	        if (ch != 13 && ch != 8)
	        {
	            putch('*');
	            c++;
	            pass[i] = ch;
	            i++;
	        }
	        if (ch == 8)
	        {
	            while (c)
	            {
	                putch('\b');
	                putch(' ');
	                putch('\b');
	                pass[i] = ch;
	                i--;
	                c--;
	                break;
	            }
	        }
	    }
	    pass[i] = '\0';
	    if (strcmp(pass, password) == 0)
	    {
	        gotoxy(15, 9);
	        printf("Password Matched");
	        gotoxy(17, 11);
	        printf("Press any key to continue");
	        getch();
	        mainmenu();
	    }
	    else
	    {
	        gotoxy(15, 10);
	        printf("\aEnter correct Password, Press any key to try again");
	        getch();
	        Password();
	    }
	}
	void addbooks()
	{
	    system("cls");
	    int i;
	    gotoxy(20, 5);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(20, 7);
	    printf("\xDB\xDB\xDB\xDB\xB2 1. Computer");
	    gotoxy(20, 9);
	    printf("\xDB\xDB\xDB\xDB\xB2 2. Electronics");
	    gotoxy(20, 11);
	    printf("\xDB\xDB\xDB\xDB\xB2 3. Electrical");
	    gotoxy(20, 13);
	    printf("\xDB\xDB\xDB\xDB\xB2 4. Physics");
	    gotoxy(20, 15);
	    printf("\xDB\xDB\xDB\xDB\xB2 5. Maths");
	    gotoxy(20, 17);
	    printf("\xDB\xDB\xDB\xDB\xB2 6. English");
	    gotoxy(20, 19);
	    printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
	    gotoxy(20, 21);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(20, 22);
	    printf("Enter your choice: ");
	    scanf("%d", &s);
	    if (s == 7)
	    {
	        mainmenu();
	    }
	    system("cls");
	    fp = fopen("Booksrecord.txt", "ab+");
	    if (getdata() == 1)
	    {
	        a.cat = categories[s - 1];
	        fseek(fp, 0, SEEK_END);
	        //fprintf(fp,"%s%s%d%f%d",a.name,a.Author,a.quantity,a.price,a.rackno);
	        fwrite(&a, sizeof(a), 1, fp);
	        fclose(fp);
	        gotoxy(21, 14);
	        printf("The record is successfully saved");
	        gotoxy(21, 15);
	        printf("Save any more? (Y/N)");
	        if (getch == 'n')
	        {
	            mainmenu();
	        }
	        else
	        {
	            system("cls");
	            addbooks();
	        }
	    }
	}
	void design()
	{
	    gotoxy(20, 3);
	    printf("Enter the information below");
	    gotoxy(18, 4);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(20, 5);
	    printf("\xB2");
	    gotoxy(46, 5);
	    printf("\xB2");
	    gotoxy(20, 6);
	    printf("\xB2");
	    gotoxy(46, 6);
	    printf("\xB2");
	    gotoxy(20, 7);
	    printf("\xB2");
	    gotoxy(46, 7);
	    printf("\xB2");
	    gotoxy(20, 8);
	    printf("\xB2");
	    gotoxy(46, 8);
	    printf("\xB2");
	    gotoxy(20, 9);
	    printf("\xB2");
	    gotoxy(46, 9);
	    printf("\xB2");
	    gotoxy(20, 10);
	    printf("\xB2");
	    gotoxy(46, 10);
	    printf("\xB2");
	    gotoxy(20, 11);
	    printf("\xB2");
	    gotoxy(46, 11);
	    printf("\xB2");
	    gotoxy(20, 12);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(21, 5);
	}
	int getdata()
	{
	    int t;
	    gotoxy(20, 3);
	    printf("Enter the information below");
	    gotoxy(20, 4);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(20, 5);
	    printf("\xB2");
	    gotoxy(46, 5);
	    printf("\xB2");
	    gotoxy(20, 6);
	    printf("\xB2");
	    gotoxy(46, 6);
	    printf("\xB2");
	    gotoxy(20, 7);
	    printf("\xB2");
	    gotoxy(46, 7);
	    printf("\xB2");
	    gotoxy(20, 8);
	    printf("\xB2");
	    gotoxy(46, 8);
	    printf("\xB2");
	    gotoxy(20, 9);
	    printf("\xB2");
	    gotoxy(46, 9);
	    printf("\xB2");
	    gotoxy(20, 10);
	    printf("\xB2");
	    gotoxy(46, 10);
	    printf("\xB2");
	    gotoxy(20, 11);
	    printf("\xB2");
	    gotoxy(46, 11);
	    printf("\xB2");
	    gotoxy(20, 12);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(21, 5);
	    printf("Category");
	    gotoxy(31, 5);
	    printf("%s", categories[s - 1]);
	    gotoxy(21, 6);
	    printf("Book ID:\t");
	    gotoxy(30, 6);
	    scanf("%d", &t);
	    if (checkid(t) == 0)
	    {
	        gotoxy(21, 13);
	        printf("\aThe Book id already exists");
	        getch();
	        mainmenu();
	        return 0;
	    }
	    a.id = t;
	    gotoxy(21, 7);
	    printf("Book Name: ");
	    gotoxy(33, 7);
	    scanf("%s", a.name);
	    gotoxy(21, 8);
	    printf("Author: ");
	    gotoxy(30, 8);
	    scanf("%s", a.Author);
	    gotoxy(21, 9);
	    printf("Quantity: ");
	    gotoxy(31, 9);
	    scanf("%d", &a.quantity);
	    gotoxy(21, 10);
	    printf("Price: ");
	    gotoxy(28, 10);
	    scanf("%f", &a.price);
	    gotoxy(21, 11);
	    printf("Rack no: ");
	    gotoxy(30, 11);
	    scanf("%d", &a.rackno);
	    return 1;
	}
	int checkid(int t)
	{
	    rewind(fp); //brings file pointer at the beginning of the file.
	    while (fread(&a, sizeof(a), 1, fp) == 1)
	    {
	        if (a.id == t)
	            return 0;
	    }
	    return 1;
	}
	
	void deletebooks()
	{
	    system("cls");
	    int d;
	
	    char another = 'y';
	    while (another == 'y')
	    {
	        system("cls");
	        design();
	        gotoxy(20, 5);
	        printf("Enter the Book Id to delete: ");
	        scanf("%d", &d);
	        fp = fopen("Booksrecord.txt", "rb+");
	        rewind(fp);
	        while (fread(&a, sizeof(a), 1, fp) == 1)
	        {
	            if (a.id == d)
	            {
	                gotoxy(10, 7);
	                printf("The book record is availbale");
	                gotoxy(10, 8);
	                printf("Book name is %s", a.name);
	                gotoxy(10, 9);
	                printf("Rack no is %d", a.rackno);
	                findbook = 't';
	            }
	        }
	        if (findbook != 't')
	        {
	
	            gotoxy(10, 10);
	            printf("No record is found");
	            if (getch())
	                ;
	            mainmenu();
	        }
	        if (findbook == 't')
	        {
	            gotoxy(10, 9);
	            printf("do you want to delete it(Y/N)?");
	            if (getch() == 'y')
	            {
	                ft = fopen("temprecord.txt", "wb+");
	                rewind(fp);
	                while (fread(&a, sizeof(a), 1, fp) == 1)
	                {
	                    if (a.id != d)
	                    {
	                        fseek(ft, 0, SEEK_CUR);
	                        fwrite(&a, sizeof(a), 1, ft);
	                    }
	                }
	                fclose(fp);
	                fclose(ft);
	                remove("Booksrecord.txt");
	                rename("temprecord.txt", "Booksrecord.txt");
	                fp = fopen("Booksrecord.txt", "rb+");
	                if (findbook == 't')
	                {
	                    gotoxy(10, 10);
	                    printf("The record is successfully deleted");
	                    gotoxy(10, 11);
	                    printf("Dlete another record (Y/N)?");
	                }
	            }
	            else
	
	                mainmenu();
	            fflush(stdin);
	            another = getch();
	        }
	    }
	    gotoxy(10, 15);
	    mainmenu();
	}
	void searchbooks()
	{
	    system("cls");
	    int d;
	    printf("Search books");
	    gotoxy(20, 10);
	    printf("\xDB\xDB 1. search by ID");
	    gotoxy(20, 14);
	    printf("\xDB\xDB 2. search by Name");
	    gotoxy(15, 20);
	    printf("Enter your choice");
	    fp = fopen("Booksrecord.txt", "rb+");
	    rewind(fp);
	    switch (getch())
	    {
	    case '1':
	    {
	        system("cls");
	        gotoxy(21, 4);
	        printf("*** Searching book by Id ***");
	        gotoxy(20, 5);
	        printf("Enter the book ID: ");
	        scanf("%d", &d);
	        gotoxy(20, 7);
	        printf("Searching...");
	        while (fread(&a, sizeof(a), 1, fp) == 1)
	        {
	            if (a.id == d)
	            {
	                sleep(1);
	                gotoxy(20, 7);
	                printf("The book is available");
	                gotoxy(20, 8);
	                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	                gotoxy(20, 9);
	                printf("\xB2 ID : %d", a.id);
	                gotoxy(47, 9);
	                printf("\xB2");
	                gotoxy(20, 10);
	                printf("\xB2 Name:%s", a.name);
	                gotoxy(47, 10);
	                printf("\xB2");
	                gotoxy(20, 11);
	                printf("\xB2 Author:%s ", a.Author);
	                gotoxy(47, 11);
	                printf("\xB2");
	                gotoxy(20, 12);
	                printf("\xB2 Qantity:%d ", a.quantity);
	                gotoxy(47, 12);
	                printf("\xB2");
	                gotoxy(47, 11);
	                printf("\xB2");
	                gotoxy(20, 13);
	                printf("\xB2 Price:Rs.%.2f", a.price);
	                gotoxy(47, 13);
	                printf("\xB2");
	                gotoxy(20, 14);
	                printf("\xB2 Rack No:%d ", a.rackno);
	                gotoxy(47, 14);
	                printf("\xB2");
	                gotoxy(20, 15);
	                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	                findbook = 't';
	
	            }
	        }
	
	        if (findbook != 't')
	        {
	
	            gotoxy(20, 8);
	            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	            gotoxy(20, 9);
	            printf("\xB2");
	            gotoxy(38, 9);
	            printf("\xB2");
	            gotoxy(20, 10);
	            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	            gotoxy(22, 9);
	            printf("\aNo Record Found");
	        }
	        gotoxy(20,17);
	        printf("Search Another Book (Y/N)?");
	        if(getch()=='y')
	        searchbooks();
	        else
	        mainmenu();
	   
	        break;
	}
	      case '2':
	      {
	           char s[15];
	      system("cls");
	      gotoxy(21,4);
	      printf("*** Search Book by Name ***");
	      gotoxy(20,5);
	      printf("Enter Book name: ");
	      scanf("%s",&s);
	      int d = 0;
	      gotoxy(20,7);
	      printf("Searching...");
	      while(fread(&a,sizeof(a),1,fp)==1)
	       {
	        sleep(1);
	        if(strcmp(a.name,s)==0)
	        {
	      gotoxy(20, 7);
	                printf("The Book is available");
	                gotoxy(20, 8);
	                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	                gotoxy(20, 9);
	                printf("\xB2 ID:%d", a.id);
	                gotoxy(47, 9);
	                printf("\xB2");
	                gotoxy(20, 10);
	                printf("\xB2 Name:%s", a.name);
	                gotoxy(47, 10);
	                printf("\xB2");
	                gotoxy(20, 11);
	                printf("\xB2 Author:%s", a.Author);
	                gotoxy(47, 11);
	                printf("\xB2");
	                gotoxy(20, 12);
	                printf("\xB2 Qantity:%d", a.quantity);
	                gotoxy(47, 12);
	                printf("\xB2");
	                gotoxy(20, 13);
	                printf("\xB2 Price:Rs.%.2f", a.price);
	                gotoxy(47, 13);
	                printf("\xB2");
	                gotoxy(20, 14);
	                printf("\xB2 Rack No:%d ", a.rackno);
	                gotoxy(47, 14);
	                printf("\xB2");
	                gotoxy(20, 15);
	                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	        d=1;
	  }
	  }
	  if(d==0)
	  {
	  gotoxy(20, 8);
	            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	            gotoxy(20, 9);
	            printf("\xB2");
	            gotoxy(38, 9);
	            printf("\xB2");
	            gotoxy(20, 10);
	            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	            gotoxy(22, 9);
	            printf("\aNo Record Found");
	  }
	      gotoxy(20, 17);
	        printf("Try another search?(Y/N)");
	        if(getch()=='y')
	        {
	        searchbooks();
	       
	}
	else
	{
	mainmenu();
	}
	break;
	 }
	 default:
	  getch();
	  searchbooks();
	    }
	    fclose(fp);
	}
	void returnfunc(void)
	{
	  {
	 
	  printf("Press Enter to return to the main menu");
	  }
	  a:
	  if(getch()==13)
	  mainmenu();
	  else
	  goto a;
	 
	}
	void issuerecord()
	{
	system("cls");
	gotoxy(10,8);
	if(G=='M')
	{
	
	printf("The book is taken by Mr %s",a.stname);
	    }
	   else
	   {
	
	    printf("The book is taken by Miss %s",a.stname);
	    }
	gotoxy(10,9);
	printf("Issued Date : %d-%d-%d",d.day,d.month,d.year);
	gotoxy(10,10);
	printf("Returning Date: %d-%d-%d",e.day,e.moth,e.year);
	
	}
	void issuebooks()
	{
	int t;
	SYSTEMTIME stime;
	GetSystemTime(&stime);
	system("cls");
	printf("***** Issue Section *****");
	gotoxy(10,5);
	printf("\xDB\xDB\xDB 1. Issue a Book");
	gotoxy(10,7);
	printf("\xDB\xDB\xDB 2. View Issued Book");
	gotoxy(10,9);
	printf("\xDB\xDB\xDB 3. Search Issued Book");
	gotoxy(10,11);
	printf("\xDB\xDB\xDB 4. Remove Issued Book");
	gotoxy(10,14);
	printf("Enter a choice:");
	switch(getch())
	{
	case '1':
	{
	
	system("cls");
	int c=0;
	char another = 'y';
	while(another == 'y')
	{
	system("cls");
	gotoxy(15,4);
	printf("**** Issue Book Section ****");
	gotoxy(10,6);
	printf("Enter the book id: ");
	       scanf("%d",&t);
	       fp=fopen("Booksrecord.txt","rb");
	       fs=fopen("issue.txt","ab+");
	       if(checkid(t)==0)
	       {
	        gotoxy(10,8);
	        printf("The book record is available");
	        gotoxy(10,9);
	        printf("There are %d isssued books in library",a.quantity);
	        gotoxy(10,10);
	        printf("The name of the book is %s",a.name);
	        gotoxy(10,11);
	        printf("Enter student name: ");
	        scanf("%s",a.stname);
	        gotoxy(10,12);
	        /*printf("Enter Gender (M/F): ");
	        scanf("%s",G);
	        gotoxy(10,13);*/
	        printf("Issued date = %d/%d/%d",stime.wDay,stime.wMonth,stime.wYear);
	        gotoxy(10,14);
	        printf("Enter after how many days book is to be return");
	       // scanf("%d",&RETURNTIME);
	             gotoxy(10,15);
	        printf("The book of Id %d is issued ",a.id);
	        a.duedate.dd=stime.wDay + RETURNTIME;
	        a.duedate.mm=stime.wMonth;
	        a.duedate.yy=stime.wYear;
	        //
	        d.day=stime.wDay;
	        d.month=stime.wMonth;
	        d.year=stime.wYear;
	        e.day=a.duedate.dd;
	        e.moth=a.duedate.mm;
	        e.moth=a.duedate.yy;
	        if(a.duedate.dd>30)
	        {
	        a.duedate.mm += a.duedate.dd/30;
	        a.duedate.dd -=30;
	        e.day=a.duedate.dd;
	}
	if(a.duedate.mm>12)
	{
	a.duedate.yy +=a.duedate.mm/12;
	a.duedate.mm -=12;
	e.moth=a.duedate.mm;
	}
	gotoxy(10,16);
	printf("To be return : %d/%d/%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
	fseek(fs,sizeof(a),SEEK_END);
	fwrite(&a,sizeof(a),1,fs);
	fclose(fs);
	c=1;
	
	}
	if(c==0)
	{
	gotoxy(10,11);
	printf("No record is found ");
	
	}
	gotoxy(10,17);
	printf("Issue any more (Y/N)?");
	fflush(stdin);
	another=getche();
	fclose(fp);
	
	}
	break;
	}
	
	case '2':
	{
	system("cls");
	int j = 4;
	printf("****** Isssue Book List ******");
	gotoxy(2,2);
	printf("Student Name     Category     ID     Book Name     Issued Book     Return Date");
	fs=fopen("issue.txt","rb");
	while(fread(&a,sizeof(a),1,fs)==1)
	{
	gotoxy(2,j);
	printf("%s",a.stname);
	gotoxy(18,j);
	//puts(a.cat);
	printf("%s",a.cat);
	gotoxy(30,j);
	printf("%d",a.id);
	gotoxy(36,j);
	printf("%s",a.name);
	gotoxy(51,j);
	printf("%d/%d/%d ",stime.wDay,stime.wMonth,stime.wYear);
	gotoxy(65,j);
	printf("%d/%d/%d ",a.duedate.dd,a.duedate.mm,a.duedate.yy);
	gotoxy(50,25);
	j++;
	}
	fclose(fs);
	gotoxy(1,25);
	returnfunc();
	
	}
	break;
	case '3':
	{
	system("cls");
	gotoxy(10,6);
	printf("Enter book Id");
	int p,c=0;
	char another = 'y';
	while(another == 'y')
	{
	scanf("%d",&p);
	fs=fopen("issue.txt","rb");
	while(fread(&a,sizeof(a),1,fs)==1)
	{
	if(a.id==p)
	{
	issuerecord();
	gotoxy(10,12);
	printf("Press any key...");
	getch();
	issuerecord();
	c=1;
	 }
	 }
	 fflush(stdin);
	 fclose(fs);
	 if(c==0)
	 {
	 gotoxy(10,8);
	 printf("No record found");
	 
	 }
	 gotoxy(10,13);
	 printf("Try another search (Y/N)?");
	 another = getch();
	}
	
	}
	break;
	case '4':
	{
	system("cls");
	int b;
	FILE *fg;
	char another = 'y';
	while(another == 'y')
	{
	gotoxy(10,15);
	printf("Enter Book Id to remove");
	scanf("%d",&b);
	fs=fopen("issue.txt","rb+");
	while(fread(&a,sizeof(a),1,fs)==1)
	{
	if(a.id==b)
	{
	 issuerecord();
	 findbook='t';
	 
	}
	if(findbook=='t');
	{
	
	gotoxy(10,12);
	printf("Do you want to Remove it (Y/N)?");
	if(getch()=='y')
	 {
	  fg=fopen("record.txt","wb+");
	  rewind(fs);
	  while(fread(&a,sizeof(a),1,fs)==1)
	  {
	  if(a.id !=b)
	  {
	  fseek(fs,0,SEEK_CUR);
	  fwrite(&a,sizeof(a),1,fg);
	 
	}
	 
	                             }
	                             fclose(fs);
	                        fclose(fg);
	                        remove("issue.txt");
	                        rename("record.txt","issue.txt");
	                        gotoxy(10,14);
	                        printf("The issued book is removed from the list");
	                       
	 }
	                       
	                    }
	                        if(findbook != 't')
	                         {
	                         gotoxy(10,15);
	                         printf("No record found");
	                         
	}
	}
	
	gotoxy(10,16);
	printf("Delete any more (Y/N)");
	another = getch();
	}
	}
	default:
	gotoxy(10,18);
	printf("\aWrong Entery");
	getch();
	issuebooks();
	break;
	}
	gotoxy(1,30);
	returnfunc;
	
	
	}
	void viewbooks()
	{
	int i = 0,j;
	system("cls");
	gotoxy(1,1);
	printf("***** Book List *****");
	gotoxy(2,2);
	printf(" Category     Id    Book Name     Author       Qty     Price     RackNo ");
	j = 4;
	fp=fopen("Booksrecord.txt","rb");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	gotoxy(3,j);
	printf("%s",a.cat);
	gotoxy(16,j);
	printf("%d",a.id);
	gotoxy(22,j);
	printf("%s",a.name);
	gotoxy(36,j);
	printf("%s",a.Author);
	gotoxy(50,j);
	printf("%d",a.quantity);
	gotoxy(57,j);
	printf("%.2f",a.price);
	gotoxy(69,j);
	printf("%d",a.rackno);
	printf("\n\n");
	j++;
	i=i+a.quantity;
	
	}
	// gotoxy(3,25);
	    printf("\n");
	printf("Total Books = %d",i);
	fclose(fp);
	printf("\n");
	//gotoxy(35,25);
	returnfunc();
	
	}
	void editbooks()
	{
	  system("cls");
	  int c = 0;
	  int d,e;
	  gotoxy(20,4);
	  printf("***** Edit Book`s section *****");
	  char another = 'y';
	  while(another == 'y')
	  {
	  system("cls");
	  gotoxy(15,6);
	  printf("Enter a book id to be edited:");
	  scanf("%d",&d);
	  fp=fopen("Booksrecord.txt","rb+");
	  while(fread(&a,sizeof(a),1,fp)==1)
	  {
	  if(checkid(d)==0)
	  {
	  gotoxy(15,7);
	  printf("The book is available");
	  gotoxy(15,8);
	  printf("The book Id %d",a.id);
	  gotoxy(15,9);
	  printf("Enter a new name:");
	  scanf("%s",a.name);
	  gotoxy(15,10);
	  printf("Enter a new Author:");
	  scanf("%s",a.Author);
	  gotoxy(15,11);
	  printf("Enter new Quantity:");
	  scanf("%d",&a.quantity);
	  gotoxy(15,12);
	  printf("Enter new Price:");
	  scanf("%f",&a.price);
	  gotoxy(15,13);
	  printf("Enter new rack no:");
	  scanf("%d",&a.rackno);
	  gotoxy(15,14);
	  printf("The Record is modified");
	  fseek(fp,ftell(fp)-sizeof(a),0);
	  fclose(fp);
	  c=1;
	 }
	 if(c==0)
	 {
	  gotoxy(15,9);
	  printf("No record Found");
	 }
	 
	 
	 }
	 gotoxy(15,16);
	 printf("Modify another record?(Y/N)");
	 fflush(stdin);
	 another=getch();
	  }
	  gotoxy(15,17);
	  returnfunc();
	}
