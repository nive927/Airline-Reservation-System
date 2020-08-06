#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include "dateADT.h"

char *fnames[]={"123.bin", "456.bin", "789.bin"};
char* cities[]={"CHENNAI", "BANGALORE", "PUNE", "DELHI", "KOCHI", "MUMBAI", "HYDERABAD", "SINGAPORE", "LONDON", "DUBAI"}; 

FILE *fp;

FILE *a, *f;
enum days {SUNDAY=1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
enum places{CHENNAI, BANGALORE, PUNE, DELHI, KOCHI, MUMBAI, HYDERABAD, SINGAPORE, LONDON, DUBAI};
typedef float price;
char place[][10]={"CHENNAI", "BANGALORE", "PUNE", "DELHI", "KOCHI", "MUMBAI", "HYDERABAD", "SINGAPORE", "LONDON", "DUBAI"};
char day[][10]={"", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

typedef struct
{
	int code;
	char pw[15];
}admin;


struct flight_det
{
	int acode;                   //airline code
	char fcode[10];
	enum places source;
	enum places destination;
	struct time deptime;
	struct time arrtime;
	enum days day;
	price adult_first;
	price adult_business;
	price adult_economy;
	price child_first;
	price child_business;
	price child_economy;
};

struct flight
{
    struct flight_det details;
    struct date flight_date;
   

    
};

struct path
{
    struct flight route[30];
    int num; //no. of flights travelled in the route
    float cost;
};

struct location
{
    char street[40];
    char city[25];
    char pincode[10];
    char state[25];
};


FILE *f;

struct user_details
{
    char username[40];
    char password[40];
    char name[40];
    struct location address;
    char nationality[40];
    char mobile[12];
    char email[45];
    struct date dob;
    int age;
    char gender;
};

/* Function to implement getch() due to absence of <conio.h> in gcc compliler */

char getch()
{
    char buf=0;

    struct termios old={0};

    fflush(stdout);

    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    
    old.c_lflag&=~ICANON;
        old.c_lflag&=~ECHO;
        old.c_cc[VMIN]=1;
        old.c_cc[VTIME]=0;
    
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    
    if(read(0,&buf,1)<0)
        perror("read()");
    
    old.c_lflag|=ICANON;
       old.c_lflag|=ECHO;
    
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
        
    return buf;
 }

// Identifiers used for admin login

#define USERNAME     "admin"
#define PASSWORD    "admin20"

/*
AIRLINE CODE              PASSWORD           
123                        abc
456                       def
789                        ghi
*/

void arr_cpy(int a[10], int b[10])
{
    for (int i=0; i<10; i++)
    {
        a[i]=b[i];
    }
}
void lower(char str[])

{   int i=0;
    while (str[i]!='\0')
    {
        str[i]=tolower(str[i]);
        i++;
    }
}
