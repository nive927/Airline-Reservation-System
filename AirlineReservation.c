#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include"Booking.h"

// Function to display the introductory opening page

void intro()
{
    system("clear");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t  MINI PROJECT\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t  Airplane Reservation System");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tMADE BY: Lakshmi Priya 185001083\n \t\t\t\t\t\t\t\t\t\t\t Nivedhitha D  185001104\n\t\t\t\t\t\t\t\t\t\t\t Sakthi Sairaj 185001134\n\n");
    printf("\t\t\t\t\t\t\t\t\t\tBRANCH : CSE B\n");
    printf("\n\t\t\t\t\t\t\t\t\t\tCOLLEGE: SSN College of Engineering\n");

    getch();
}

void ticket_enquiry()
{
    system("clear");

    char ch;

    printf("\n\n\n\tBOOKED TICKET ENQUIRY");
    printf("\n\n\tTICKET OPTIONS");
    printf("\n\n\t\t1. View Particular Flight Ticket");
    printf("\n\n\t\t2. View All Flight Tickets");
    printf("\n\n\tBILL OPTIONS");
    printf("\n\n\t\t3. View A Particular Bill");
    printf("\n\n\t\t4. View All Bills");
    printf("\n\n\tEXIT OPTION");
    printf("\n\n\t\t5. BACK TO USER MENU");

    printf("\n\n\n\n\tEnter choice: ");
    scanf(" %c", &ch);

    switch(ch)

    {
        case '1':	system("clear");
					getch();
					ticket_enquiry();
					break;

        case '2':   system("clear");
					getch();
					ticket_enquiry();
					break;

        case '3':   system("clear");
					getch();
					ticket_enquiry();
					break;

        case '4':   system("clear");
					getch();
					ticket_enquiry();
					break;

        case '5':   system("clear");
					break;

        default:    ticket_enquiry();
    }
}

long int read_count_users(struct user_details all_users[])
{
    long int count=0;
    FILE *fptr=fopen("user.bin", "rb");

    fseek(fptr, 0, SEEK_END);
    count=(ftell(fptr))/sizeof(struct user_details);

    fseek(fptr, 0, SEEK_SET);

    for(int i=0; i<count; i++)
        fread(&all_users[i], sizeof(struct user_details), 1, fptr);

    fclose(fptr);

    return count;
}

int search_users(int n, struct user_details all_users[])
{
    char search[40];

    printf("\n\tCURRENT Username: ");
    scanf("%s",search);

    for (int i=0; i<n; i++)
        if(strcmp(all_users[i].username, search)==0)
                return i;

    return -1;
}

void user_det_update()
{
    struct user_details all_users[10];
    int count=0, index=-1;

    count=read_count_users(all_users);

    printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");

    index=search_users(count, all_users);

    FILE *fptr=fopen("user.bin", "wb");

    if(index!=-1)
    {
        char ch;

        do
        {   system("clear");

            printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");

            printf("\n\n\t0. Username");
            printf("\n\n\t1. Password");
            printf("\n\n\t2. Name");
            printf("\n\n\t3. Address");
            printf("\n\n\t4. Nationality");
            printf("\n\n\t5. Mobile Number");
            printf("\n\n\t6. Email ID");
            printf("\n\n\t7. Date Of Birth");
            printf("\n\n\t8. Age");
            printf("\n\n\t9. Gender");
            printf("\n\n\te. BACK TO USER MENU");

            printf("\n\n\n\n\tEnter choice: ");
            scanf(" %c", &ch);

            switch(ch)
            {
                case '0':   system("clear");
							printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
							printf("\n\n\tEnter the NEW Details\n\n");
							printf("\tUSERNAME: ");
							scanf(" %[^\n]", all_users[index].username);
							break;

                case '1':    system("clear");
							printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
							printf("\n\n\tEnter the NEW Details\n\n");
							printf("\tPASSWORD: ");
							scanf(" %[^\n]", all_users[index].password);
							break;

                case '2':   system("clear");
							printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
							printf("\n\n\tEnter the NEW Details\n\n");
							printf("\n\tName: ");
							scanf(" %[^\n]", all_users[index].name);
							break;

                case '3':   system("clear");
							printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
							printf("\n\n\tEnter the NEW Details\n\n");
							printf("\n\tAddress:\n");
							printf("\tStreet: ");
							scanf(" %[^\n]", all_users[index].address.street);

							printf("\tCity: ");
							scanf(" %[^\n]", all_users[index].address.city);

							printf("\tPincode: ");
							scanf(" %[^\n]", all_users[index].address.pincode);

							printf("\tState: ");
							scanf(" %[^\n]", all_users[index].address.state);
							break;

                case '4':   system("clear");
							printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
							printf("\n\n\tEnter the NEW Details\n\n");
							printf("\n\tNationality: ");
							scanf(" %[^\n]", all_users[index].nationality);
							break;

                case '5':   system("clear");
							printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
							printf("\n\n\tEnter the NEW Details\n\n");
							printf("\tMobile: ");
							scanf(" %[^\n]", all_users[index].mobile);
							break;

                case '6':   system("clear");
							printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
							printf("\n\n\tEnter the NEW Details\n\n");
							printf("\tEmail ID: ");
							scanf(" %[^\n]", all_users[index].email);
							break;

                case '7':   system("clear");
							printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
							printf("\n\n\tEnter the NEW Details\n\n");
							printf("\n\tEnter DATE in dd mm yyyy FORMAT\n");
							printf("\tDate of birth: ");
							scanf("%d %d %d", &all_users[index].dob.day, &all_users[index].dob.month, &all_users[index].dob.year);
							break;

                case '8':   system("clear");
							printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
							printf("\n\n\tEnter the NEW Details\n\n");
							printf("\n\tAge: ");
							scanf("%d", &all_users[index].age);
							break;

                case '9':   system("clear");
							printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
							printf("\n\n\tEnter the NEW Details\n\n");
							printf("\n\tF: Female M: Male T:Transgender O:Other\n");
							printf("\tGender: ");
							scanf(" %c", &all_users[index].gender);
							break;

                case 'e':   printf("\n\n\n\tUPDATED USER ACCOUNT PROFILE SUCCESSFULLY...!!!\n");
							getch();
							break;

                default:    system("clear");
							printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
							printf("\n\nINVALID CHOICE\n");
							getch();
            }
        }while(ch!='e');

        fseek(fptr, 0, SEEK_SET);
        fwrite(&all_users, sizeof(struct user_details), count, fptr);

    }

    else
    {
        printf("\n\n\n\tUSER NOT FOUND...!!!");
        printf("\n\n\tINVALID USERNAME/DOESN'T EXIST...!!!\n");
    }

    fclose(fptr);

}

void user_det_delete()
{
    struct user_details all_users[10];
    int count=0, index=-1;

    printf("\n\n\n\tDELETE USER PROFILE\n\n");

    count=read_count_users(all_users);

    index=search_users(count, all_users);

    FILE *fptr=fopen("user.bin", "wb");

    if(index!=-1)
    {
        for(int i=index; i<(count-1); i++)
            all_users[i]=all_users[i+1];

        fseek(fptr, 0, SEEK_SET);

        for(int i=0; i<(count-2); i++)
            fwrite(&all_users[i], sizeof(struct user_details), 1, fptr);

        printf("\n\n\n\tDELETEED USER ACCOUNT PROFILE SUCCESSFULLY...!!!\n");
    }

    else
    {
        printf("\n\n\n\tUSER NOT FOUND...!!!");
        printf("\n\n\tINVALID USERNAME/DOESN'T EXIST...!!!\n");
    }

    fclose(fptr);

    getch();
}

void user_det_view_particular()
{
    struct user_details all_users[10];
    int count=0, index=-1;

    printf("\n\n\n\tVIEW A PARTICULAR USER ACCOUNT PROFILE\n\n");

    count=read_count_users(all_users);

    index=search_users(count, all_users);

    if(index!=-1)
    {
        system("clear");

        printf("\n\n\n\tVIEW A PARTICULAR USER ACCOUNT PROFILE\n\n");

        printf("\tUSERNAME: %s\n", all_users[index].username);

        printf("\tPASSWORD: %s\n", all_users[index].password);

        printf("\n\tName: %s\n", all_users[index].name);

        printf("\n\tAddress:\n");
        printf("\t%s\n\t%s - %s\n\t%s\n", all_users[index].address.street, all_users[index].address.city, all_users[index].address.pincode, all_users[index].address.state);

        printf("\n\tNationality: %s\n", all_users[index].nationality);

        printf("\tMobile: %s\n", all_users[index].mobile);

        printf("\tEmail ID: %s\n", all_users[index].email);

        printf("\tDate of birth: %d-%d-%d\n", all_users[index].dob.day, all_users[index].dob.month, all_users[index].dob.year);

        printf("\n\tAge: %d\n", all_users[index].age);

        printf("\n\tF: Female M: Male T:Transgender O:Other\n");
        printf("\tGender: %c\n", all_users[index].gender);
    }

    else
    {
        printf("\n\n\n\tUSER NOT FOUND...!!!");
        printf("\n\n\tINVALID USERNAME/DOESN'T EXIST...!!!\n");
    }

    getch();

}


void user_det_view_all()
{
    struct user_details all_users[10];
    int count=-1, i=0;
    FILE *fptr= fopen("user.bin", "rb");

    printf("\n\n\n\tVIEW All USER ACCOUNT PROFILE");

    count=read_count_users(all_users);

    if(count==0)
        count=-1;

    while((i<count))
    {
        printf("\n\n\tACCOUNT PROFILE DETAILS\n\n");

        printf("\tUSERNAME: %s\n", all_users[i].username);

        printf("\tPASSWORD: %s\n", all_users[i].password);

        printf("\n\tName: %s\n", all_users[i].name);

        printf("\n\tAddress:\n");
        printf("\t%s\n\t%s - %s\n\t%s\n", all_users[i].address.street, all_users[i].address.city, all_users[i].address.pincode, all_users[i].address.state);

        printf("\n\tNationality: %s\n", all_users[i].nationality);

        printf("\tMobile: %s\n", all_users[i].mobile);

        printf("\tEmail ID: %s\n", all_users[i].email);

        printf("\tDate of birth: %d-%d-%d\n", all_users[i].dob.day, all_users[i].dob.month, all_users[i].dob.year);

        printf("\n\tAge: %d\n", all_users[i].age);

        printf("\n\tF: Female M: Male T:Transgender O:Other\n");
        printf("\tGender: %c\n", all_users[i].gender);

        i++;

        getch();
    }

    fclose(fptr);

}


void user_menu()
{
    system("clear");

    char ch;

    printf("\n\n\n\tUSER OPTIONS");
    printf("\n\n\tTICKET OPTIONS");
    printf("\n\n\t\t1. Book Flight Ticket");
    //printf("\n\n\t\t2. Current Flight Ticket Bookings");
    //printf("\n\n\t\t3. Cancel Flight Ticket");
    printf("\n\n\tACCOUNT OPTIONS");
    printf("\n\n\t\t2. View Account Profile");
    printf("\n\n\t\t3. Update Account Profile");
    printf("\n\n\t\t4. Delete Account");
    printf("\n\n\tEXIT OPTION");
    printf("\n\n\t\t5. BACK TO MAIN MENU");

    printf("\n\n\n\n\tEnter choice: ");
    scanf(" %c", &ch);

    switch(ch)

    {
        case '1':
                system("clear");
                book();
                getch();
                user_menu();
                break;

       /* case '2':    system("clear");
                ticket_enquiry();
                user_menu();
                break;

        case '3':    system("clear");
                getch();
                user_menu();
                break;
        */

        case '2':    system("clear");
                user_det_view_particular();
                user_menu();
                break;

        case '3':    system("clear");
                user_det_update();
                user_menu();
                break;

        case '4':    system("clear");
                user_det_delete();
                break;

        case '5':    system("clear");
                break;

        default:    user_menu();
    }
}

void add_flights(int n, int acode)
{
	struct flight_det flight;
	int day;

for (int i=0;i<n;i++)
{
flight.acode=acode;
printf("\nEnter flight code: ");
scanf(" %5s",flight.fcode);
do
{
printf("Source Options:\n\t0. CHENNAI\n\t1. BANGALORE\n\t2. PUNE\n\t3. DELHI\n\t4. KOCHI\n\t5. MUMBAI\n\t6. HYDERABAD\n\t7. SINGAPORE\n\t8. LONDON\n\t9. DUBAI\n");
printf("Enter option: ");
scanf(" %u",&flight.source);
}while(flight.source<0 || flight.source>9);
do
{
printf("Destination Options:\n\t0. CHENNAI\n\t1. BANGALORE\n\t2. PUNE\n\t3. DELHI\n\t4. KOCHI\n\t5. MUMBAI\n\t6. HYDERABAD\n\t7. SINGAPORE\n\t8. LONDON\n\t9. DUBAI\n");
printf("Enter option: ");
scanf(" %u",&flight.destination);
}while(flight.destination<0 || flight.destination>9);
do
{
printf("Enter departure time(hh/mm) : ");
scanf("%d/%d",&flight.deptime.hh,&flight.deptime.mm);
}while(flight.deptime.hh<0 || flight.deptime.hh>24 || flight.deptime.mm<0 || flight.deptime.mm>60);
do
{
printf("Enter arrival time(hh/mm)   : ");
scanf("%d/%d",&flight.arrtime.hh,&flight.arrtime.mm);
}while(flight.arrtime.hh<0 || flight.arrtime.hh>24 || flight.arrtime.mm<0 || flight.arrtime.mm>60);
do
{
printf("Day of operation of flight option:\n\t1. Sundays\n\t2. Mondays\n\t3. Tuesdays\n\t4. Wednesdays\n\t5. Thursdays\n\t6. Fridays\n\t7. Saturdays\nEnter choice: ");
scanf("%d",&day);
switch (day)
{
case 1: flight.day=SUNDAY;
break;
case 2: flight.day=MONDAY;
break;
case 3: flight.day=TUESDAY;
break;
case 4: flight.day=WEDNESDAY;
break;
case 5: flight.day=THURSDAY;
break;
case 6: flight.day=FRIDAY;
break;
case 7: flight.day=SATURDAY;
break;
}
}while(day<1 || day>7);
printf("Adult ticket prices\n");
printf("\tEnter for first class    : ");
scanf("%f",&flight.adult_first);
printf("\tEnter for business class : ");
scanf("%f",&flight.adult_business);
printf("\tEnter for economy class  : ");
scanf("%f",&flight.adult_economy);
printf("Child ticket prices\n");
printf("\tEnter for first class    : ");
scanf("%f",&flight.child_first);
printf("\tEnter for business class : ");
scanf("%f",&flight.child_business);
printf("\tEnter for economy class  : ");
scanf("%f",&flight.child_economy);

fwrite(&flight, sizeof(struct flight_det), 1, f);
}
}


int read_det(int acode, struct flight_det allflight[])
{
int count;
fseek(f, 0, SEEK_END);
count=ftell(f)/sizeof(struct flight_det);
fseek(f, 0, SEEK_SET);
fread(allflight, sizeof(struct flight_det), count, f);
return count;
}


void disp(int i,struct flight_det allflight[])
{
printf("%-5d %-5s %-10s %-10s   %02d:%02d     %02d:%02d   %-9s %10.2f%10.2f%10.2f%10.2f%10.2f%10.2f\n", allflight[i].acode, allflight[i].fcode, place[allflight[i].source], place[allflight[i].destination], allflight[i].deptime.hh, allflight[i].deptime.mm, allflight[i].arrtime.hh, allflight[i].arrtime.mm, day[allflight[i].day], allflight[i].adult_first, allflight[i].adult_business, allflight[i].adult_economy, allflight[i].child_first, allflight[i].child_business, allflight[i].child_economy);
}


int search(int n, struct flight_det allflight[])
{
char search[20];
printf("Enter flight code: ");
scanf(" %s",search);
for (int i=0;i<n;i++)
{
    if(strcmp(allflight[i].fcode,search)==0)
        return i;
}
return -1;
}


void modify(int index,int n,struct flight_det allflight[])
{
int day;
printf("Source Options:\n\t0. CHENNAI\n\t1. BANGALORE\n\t2. PUNE\n\t3. DELHI\n\t4. KOCHI\n\t5. MUMBAI\n\t6. HYDERABAD\n\t7. SINGAPORE\n\t8. LONDON\n\t9. DUBAI\n");
printf("Enter new option: ");
scanf(" %u",&allflight[index].source);
printf("Destination Options:\n\t0. CHENNAI\n\t1. BANGALORE\n\t2. PUNE\n\t3. DELHI\n\t4. KOCHI\n\t5. MUMBAI\n\t6. HYDERABAD\n\t7. SINGAPORE\n\t8. LONDON\n\t9. DUBAI\n");
printf("Enter new option: ");
scanf(" %u",&allflight[index].destination);
printf("Enter new departure time(hh/mm) : ");
scanf("%d/%d",&allflight[index].deptime.hh,&allflight[index].deptime.mm);
printf("Enter new arrival time(hh/mm)   : ");
scanf("%d/%d",&allflight[index].arrtime.hh,&allflight[index].arrtime.mm);
printf("Day of operation of flight option:\n\t1. Sundays\n\t2. Mondays\n\t3. Tuesdays\n\t4. Wednesdays\n\t5. Thursdays\n\t6. Fridays\n\t7. Saturdays\nEnter new choice: ");
scanf("%d",&day);
switch (day)
    {
    case 1: allflight[index].day=SUNDAY;
    break;
    case 2: allflight[index].day=MONDAY;
    break;
    case 3: allflight[index].day=TUESDAY;
    break;
    case 4: allflight[index].day=WEDNESDAY;
    break;
    case 5: allflight[index].day=THURSDAY;
    break;
    case 6: allflight[index].day=FRIDAY;
    break;
    case 7: allflight[index].day=SATURDAY;
    break;
    }
printf("Adult new ticket prices\n");
printf("\tEnter for first class    : ");
scanf("%f",&allflight[index].adult_first);
printf("\tEnter for business class : ");
scanf("%f",&allflight[index].adult_business);
printf("\tEnter for economy class  : ");
scanf("%f",&allflight[index].adult_economy);
printf("Child new ticket prices\n");
printf("\tEnter for first class    : ");
scanf("%f",&allflight[index].child_first);
printf("\tEnter for business class : ");
scanf("%f",&allflight[index].child_business);
printf("\tEnter for economy class  : ");
scanf("%f",&allflight[index].child_economy);

fseek(f, 0, SEEK_SET);
fwrite(allflight, sizeof(struct flight_det), n, f);
}


void delete(int index,int n,struct flight_det allflight[])
{
for (int i=index;i<n;i++)
    allflight[i]=allflight[i+1];
fwrite(allflight,sizeof(struct flight_det),--n,f);
printf("Flight Record Deleted!!\n");
}


void admin_menu(int acode)
{
    system("clear");

    char ch, file[10];
    int n,index;
    struct flight_det flight, allflight[20];
    if (acode==123)
    strcpy(file,"123.bin");
    else if (acode==456)
    strcpy(file,"456.bin");
    else if (acode==789)
    strcpy(file,"789.bin");

    printf("\n\n\n\tADMINISTRATOR OPTIONS");
    printf("\n\n\tFLIGHT OPTIONS");
    printf("\n\n\t\t1. Add New Flight");
    printf("\n\n\t\t2. Update Existing Flight");
    printf("\n\n\t\t3. Delete A Particular Flight");
    printf("\n\n\t\t4. Display A Particular Flight");
    printf("\n\n\t\t5. Display All Flights");
    printf("\n\n\tCUSTOMER OPTIONS");
    printf("\n\n\t\t6. View A Particular User Account Profile");
    printf("\n\n\t\t7. View All User Account Profiles");
    printf("\n\n\tEXIT OPTION");
    printf("\n\n\t\t8. BACK TO MAIN MENU");

    printf("\n\n\n\n\tEnter choice: ");
    scanf(" %c", &ch);

    switch(ch)

    {
        case '1':    system("clear");
        f=fopen(file,"ab+");
        printf("Enter number of flights to be added: ");
        scanf("%d",&n);
        add_flights(n,acode);
        fclose(f);

                admin_menu(acode);
                break;

        case '2':    system("clear");
                f=fopen(file,"rb+");
        n=read_det(acode, allflight);
        index=search(n, allflight);
        if (index==-1)
            printf("\nFlight details not found!!\n");
        else
            modify(index,n,allflight);
        fclose(f);
                admin_menu(acode);
                break;

        case '3':    system("clear");
        f=fopen(file,"rb");
        n=read_det(acode, allflight);
        index=search(n, allflight);
        if (index==-1)
            printf("\nFlight details not found!!\n");
        else
            {
            f=fopen(file,"wb");
            delete(index,n,allflight);
            }
        fclose(f);
                admin_menu(acode);
                break;

        case '4':    system("clear");
                f=fopen(file,"rb");
        n=read_det(acode, allflight);
        index=search(n, allflight);
        if (index==-1)
            printf("\nFlight code does not exist!!\n");
        else
        {
printf("ACODE FCODE SOURCE    DESTINATION  DEPARTURE ARRIVAL    DAY                ADULT FARES                    CHILD FARES\n");
printf("                                                                    FIRST    BUSINESS  ECONOMY     FIRST    BUSINESS  ECONOMY\n");
            disp(index, allflight);
        }
        getch();
        fclose(f);
        admin_menu(acode);
            break;

        case '5':    system("clear");
                f=fopen(file,"rb");
        n=read_det(acode, allflight);
printf("ACODE FCODE SOURCE    DESTINATION  DEPARTURE ARRIVAL    DAY                ADULT FARES                    CHILD FARES\n");
printf("                                                                    FIRST    BUSINESS  ECONOMY     FIRST    BUSINESS  ECONOMY\n");
        for (int i=0;i<n;i++)
        {
            disp(i,allflight);
        }
        getch();
        fclose(f);
        admin_menu(acode);
                break;

        case '6':    system("clear");
            user_det_view_particular();
            admin_menu(acode);
            break;


        case '7':    system("clear");
            user_det_view_all();
            admin_menu(acode);
            break;


        case '8':    system("clear");
                    break;

        default:    admin_menu(acode);
    }
}

/*  To get the password from the keyboard.
Uses pass by reference to get the entered password
via parameter to function  */

void getPassword(char *pass)
{
    char ch;
      int len=0;

    while((ch=getch())!='\n')
      {
        printf("*");

        pass[len]=ch;
        len++;
      }

    pass[len]='\0';
}


void admin_add()
{
a=fopen("admin_det.bin","wb");
admin alldet[3];
alldet[0].code=123;
strcpy(alldet[0].pw,"abc");
alldet[1].code=456;
strcpy(alldet[1].pw,"def");
alldet[2].code=789;
strcpy(alldet[2].pw,"ghi");
fwrite(alldet, sizeof(admin), 3, a);
fclose(a);
}


int check(admin det)
{
int count;
a=fopen("admin_det.bin","rb");
fseek(a, 0, SEEK_END);
count=ftell(a)/sizeof(admin);
admin alldet[count];
fseek(a, 0, SEEK_SET);
fread(alldet, sizeof(admin), count, a);
for(int i=0;i<count;i++)
    if (det.code==alldet[i].code && strcmp(det.pw,alldet[i].pw)==0)
        return det.code;
return 0;
}


void admin_login()
{
    system("clear");
    admin det;

    int user;
    char pass[30];

    printf("\n\n\n\t\tADMIN LOGIN");
    printf("\n\n\n\t\tAirline code: ");
    scanf(" %d", &det.code);
    printf("\n\t\tPassword: ");
    getPassword(det.pw);

    if (check(det))
    admin_menu(det.code);

    else
    {
        printf("\n\n\n\t\tLOGIN FAILED....!!!!");
        getch();
    }
}

void user_det_input()
{
    FILE *fptr= fopen("user.bin", "ab");
    struct user_details user;

    printf("\n\n\n\tSIGNUP\n\n");
    printf("\tNEW USER ACCOUNT ENTRY\n\n");

    printf("\tUSERNAME: ");
    scanf(" %[^\n]", user.username);

    printf("\tPASSWORD: ");
    scanf(" %[^\n]", user.password);

    printf("\n\tName: ");
    scanf(" %[^\n]", user.name);

    printf("\n\tAddress:\n");
    printf("\tStreet: ");
    scanf(" %[^\n]", user.address.street);

    printf("\tCity: ");
    scanf(" %[^\n]", user.address.city);

    printf("\tPincode: ");
    scanf(" %[^\n]", user.address.pincode);

    printf("\tState: ");
    scanf(" %[^\n]", user.address.state);

    printf("\n\tNationality: ");
    scanf(" %[^\n]", user.nationality);

    printf("\tMobile: ");
    scanf(" %[^\n]", user.mobile);

    printf("\tEmail ID: ");
    scanf(" %[^\n]", user.email);

    printf("\n\tEnter DATE in dd mm yyyy FORMAT\n");
    printf("\tDate of birth: ");
    scanf("%d %d %d", &user.dob.day, &user.dob.month, &user.dob.year);

    printf("\n\tAge: ");
    scanf("%d", &user.age);

    printf("\n\tF: Female M: Male T:Transgender O:Other\n");
    printf("\tGender: ");
    scanf(" %c", &user.gender);

    fwrite(&user, sizeof(struct user_details), 1, fptr);

    fseek(fptr, 0, SEEK_END);

    fclose(fptr);


    printf("\n\n\n\tNEW USER ACCOUNT ENTRY SUCCESSFULL......!!!!!\n");

    getch();

}

void user_login()
{
    system("clear");

    char pass[30];
    struct user_details all_users[10];
    int count=0, index=-1;

    printf("\n\n\n\tUSER LOGIN");

    count=read_count_users(all_users);

    printf("\n");

    index=search_users(count, all_users);

    if(index==-1)
    {
        printf("\n\n\n\tUSERNAME INVALID....!!!!");
        getch();
    }

    else
    {
        printf("\n\tPassword: ");
        getPassword(pass);

        if(strcmp(all_users[index].password, pass)==0)
            user_menu();

        else
        {
            printf("\n\n\n\tLOGIN FAILED....!!!!");
            getch();
        }

    }

}

void user_terminal()
{
    char ch;

    system("clear");

    do
    {    system("clear");

        printf("\n\n\n\tSNL AIRLINE BOOKING");
        printf("\n\n\t1. LOGIN");
        printf("\n\n\t2. SIGNUP");
        printf("\n\n\t3. BACK TO MAIN MENU ");

        printf("\n\n\n\n\tEnter choice: ");
        scanf(" %c", &ch);

        switch(ch)
        {
            case '1':    system("clear");
                    user_login();
                    break;

            case '2':    system("clear");
                    user_det_input();
                    break;

            case '3':    system("clear");
                    break;
        }
    }while(ch!='3');

}

int main()
{
    char ch;
    intro();
    admin_add();

    do
    {    system("clear");

        printf("\n\n\n\tMAIN MENU");
        printf("\n\n\t1. USER");
        printf("\n\n\t2. ADMINISTRATOR");
        printf("\n\n\t3. EXIT");

        printf("\n\n\n\n\tEnter choice: ");
        scanf(" %c", &ch);

        switch(ch)
        {
            case '1':    system("clear");
                    user_terminal();
                    break;

            case '2':    system("clear");
                    admin_login();
                    break;

            case '3':    return 0;
        }
    }while(ch!='3');
}


