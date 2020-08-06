#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include "graphADT.h"


void printseats()
{
printf("\n                          _____");
printf("\n                         /  |  \\");
printf("\n                        /___|___\\");
printf("\n                      /           \\");
printf("\n                    /               \\");
printf("\n                   /                 \\");
printf("\n                  /                   \\");
printf("\n                 |   A B C     D E F   |");
printf("\n             <<  |  | | | | 1 | | | |  |  >>");
printf("\n                 |  | | | | 2 | | | |  |                        FIRST CLASS");
printf("\n                 |  | | | | 3 | | | |  |");
printf("\n                 |                     |");
printf("\n                /|  | | | | 4 | | | |  |\\");
printf("\n              /  |  | | | | 5 | | | |  |  \\                    BUSINESS CLASS");
printf("\n            /    |  | | | | 6 | | | |  |    \\");
printf("\n          /  <<  |                     |  >>  \\");
printf("\n        /        |  | | | | 7 | | | |  |        \\");
printf("\n      /          |  | | | | 8 | | | |  |          \\");
printf("\n    /            |  | | | | 9 | | | |  |            \\");
printf("\n  /           /  |  | | | |10 | | | |  |  \\          \\        ECONOMY CLASS");
printf("\n/          /     |  | | | |11 | | | |  |     \\         \\");
printf("\n|       /    <<  |  | | | |12 | | | |  |  >>    \\       |");
printf("\n|____/           |  | | | |13 | | | |  |           \\____|");
printf("\n                 |  | | | |14 | | | |  |");
printf("\n                 |  | | | |15 | | | |  |\n");
}



void path_cost(int p_array[][3], struct path *trip, float per)
{
    float total=0;
    for (int i=0; i<trip->num; i++)
    {
        total+= p_array[0][0]*trip->route[i].details.child_first+p_array[0][1]*trip->route[i].details.child_business+p_array[0][2]*trip->route[i].details.child_economy+
        p_array[1][0]*trip->route[i].details.adult_first+p_array[1][1]*trip->route[i].details.adult_business+p_array[1][2]*trip->route[i].details.adult_economy;
    }

    trip->cost=total*per/100;

}

void display(struct path paths[], int path_no, int p_arr[][3] )
{
    char dummy;
    if( path_no==0||paths[0].num==0)
        printf("\nNO FLIGHTS AVAILABLE\n\n");

    else

    {
        printf("\nFlIGHT ROUTES\n");
        for (int i=0; i<path_no; i++)
        {
            printf("%d.", i+1);

            for( int j=0; j<paths[i].num; j++)
            {
                printf("%s", cities[paths[i].route[j].details.source]);
                printf("->");
                if(j==paths[i].num-1)
                    printf("%s", cities[paths[i].route[j].details.destination]);


            }
            printf("\n");

            for( int j=0; j<paths[i].num; j++)
            {
                printf("\n\t%s->%s\n", cities[paths[i].route[j].details.source], cities[paths[i].route[j].details.destination]);
                printf("\tAirline Code: %d\n\tFlight code: %s\n\tDeparture time: %d:%d\n\tArrival time: %d:%d\n", paths[i].route[j].details.acode, paths[i].route[j].details.fcode, paths[i].route[j].details.deptime.hh, paths[i].route[j].details.deptime.mm, paths[i].route[j].details.arrtime.hh, paths[i].route[j].details.arrtime.mm);
                printf("\tDate: %d/%d/%d\n", paths[i].route[j].flight_date.day, paths[i].route[j].flight_date.month, paths[i].route[j].flight_date.year);


                scanf("%c", &dummy);

            }
            printf("\n");
            printf("Total cost of path: %.2f", paths[i].cost);

            scanf("%c", &dummy);

        }

    }

}

int is_direct(struct path *trip)
{
    return trip->num==1;
}

int single(struct path *trip)
{
    return trip->num==2;
}

int multi(struct path *trip)
{
    return trip->num>=3;
}
int no_filter(struct path *trip)
{
    return 1;
}
void filter(struct path paths[], int (*f)(struct path*),  int* path_no)
{
    int count=0;
    for (int i=0; i<*path_no; i++)
    {
        if ((*f)(&paths[i]))
        {
            paths[count]=paths[i];
            count++;
        }


    }
    *path_no=count;

}



int lcost(struct path *trip1, struct path *trip2)
{
    return trip1->cost<trip2->cost;
}

int hcost(struct path *trip1, struct path *trip2)
{
    return trip1->cost>trip2->cost;
}

int stops(struct path *trip1, struct path *trip2)
{
    return trip1->num<trip2->num;
}

void sort(struct path paths[], int path_no, int (*f)(struct path*, struct path*))
{   int min_index;
    for (int i=0; i<path_no-1; i++)
    {
        min_index=i;
        for(int j=i+1; j<path_no; j++)
        {
            if ((*f)(&paths[j], &paths[min_index]))
                min_index=j;
        }

        struct path temp=paths[min_index];
        paths[min_index]=paths[i];
        paths[i]=temp;

    }
}



void book()
{
    //f=fopen("a.bin", "rb+");
    int n; //no. of passengers
    FILE *f;
    float per;
    time_t timer;
    struct tm curr_time;
    int diff;
    struct date dep_date;
    while(1)
    {

        time(&timer);
        curr_time=*localtime(&timer);  //Current time
        printf("\nEnter date of departure as day/month/year: ");
        scanf(" %d/%d/%d", &dep_date.day, &dep_date.month, &dep_date.year);
        diff=convert(dep_date.month, dep_date.day,  dep_date.year)-convert(curr_time.tm_mon+1, curr_time.tm_mday, curr_time.tm_year+1900);
        if (diff<0)
            printf("\n\nEntered date is past current date.\nPlease re-enter.\n\n");
        else if (diff>30)
            printf("\n\nBooking is available only for uptil 30 days before the flight journey.\nPlease re-enter.\n\n");
        else
            break;
    }

    enum days day=convert( dep_date.month, dep_date.day, dep_date.year)%7+1;
    if (diff>20)
        per=90;
    else if(diff>10)
        per=95;
    else
        per=100;
    //Variation in price based on time of booking



    int p_arr[][3]={{0, 0, 0}, {0, 0, 0}}; //Stores no. of passengers in each category
    enum places source;
    enum places dest;
    printf("\n\nSOURCE\n\nOptions:\n0.CHENNAI\n1.BANGALORE\n2.PUNE\n3.DELHI\n4.KOCHI\n5.MUMBAI\n6.HYDERABAD\n7.SINGAPORE\n8.LONDON\n9.DUBAI\n\n");
    printf("Enter option: ");
    scanf(" %u",&source);
    printf("\n\nDESTINATION\nOptions:\n0.CHENNAI\n1.BANGALORE\n2.PUNE\n3.DELHI\n4.KOCHI\n5.MUMBAI\n6.HYDERABAD\n7.SINGAPORE\n8.LONDON\n9.DUBAI\n\n");
    printf("Enter option: ");
    scanf(" %u",&dest);

    system("clear");

    int choice1, choice2;

    printf("Enter no. of passengers: ");
    scanf("%d", &n);

    for (int i=0; i<n; i++)
    {
        printf("Passenger %d\n", i+1);
        printf("\n\nChoose Age Category\n1. Child(Lesser than 12yrs)\n2. Adult\n\nEnter: ");
        scanf("%d", &choice1);
        if (choice1!=1&&choice1!=2)
        {
            printf("Invalid Choice.\nPlease Re-enter.\n");
            i--;
            continue;
        }
        while(1)
        {
            printf("\n\nChoose Class\n1. First Class\n2. Business Class\n3. Economy Class\n\nEnter: ");
            scanf("%d", &choice2);
            if (choice2!=1&&choice2!=2&&choice2!=3)
                printf("Invalid Choice.\nPlease Re-enter.\n");
            else
                break;

        }

        system("clear");

        p_arr[choice1-1][choice2-1]++;


    }



    struct path paths[1024]; //Stores all possible paths from source to destination
    struct path trip;       //Stores a particular path
    trip.num=0;             //No. of flights taken in trip
    int path_no=0;          //Total no. of paths from source->destination
    int visited[10];        //To keep track of visited places to avoid cycles in the graph
    for (int i=0; i<10; i++)
    {
        visited[i]=0;       //Marking all places as unvisited
    }



    struct flight flights[30];
    int num=0; //no. of available flights
    for (int i=0; i<3; i++)
    {
        f=fopen(fnames[i], "rb");
        while(fread(&flights[num].details, sizeof(struct flight_det), 1, f))
        {
            num++;
        }
        fclose(f);
    }






    linkedList* adj_list[10]; //adjacency list
    createAdjList(adj_list, 10);

    for (int i=0; i<num; i++)
    {
       ins_end(flights[i],  adj_list[flights[i].details.source]);
    }




    DFS(source, dest, day, visited, trip, &path_no, adj_list, paths, &dep_date, &curr_time);

    for (int i=0; i<path_no; i++)
    {
        path_cost(p_arr, &paths[i], per);
    }


    //printf("lala\n");
    display(paths, path_no, p_arr);



    if(path_no!=0&&paths[0].num!=0)

    {
        system("clear");

        printf("Enter filter criteria\n1.Direct flights\n2.Single stop routes\n3.Atleast 2 stops\n4.No applied filter\nEnter: ");
        scanf("%d", &choice1);
        printf("Sort based on\n1.Cost(low to high)\n2.Cost(high to low)\n3.No. of stops(low to high)\nEnter: ");

        scanf("%d", &choice2);
        int (*fil)(struct path*);
        int (*s)(struct path*, struct path*);
        switch(choice1)
        {
            case 1: fil=&is_direct;break;
            case 2: fil=&single;break;
            case 3: fil=&multi;break;
            case 4: fil=&no_filter;break;

        }

        switch(choice2)
        {
            case 1: s=&lcost;break;
            case 2: s=&hcost;break;
            case 3: s=&stops;break;

        }


        filter(paths, fil,  &path_no);
        sort(paths, path_no, s);

        display(paths, path_no, p_arr);

        FILE *file;

        char choice[10];
        char user[10];


        file=fopen("bookings.txt","a");

        printf("Enter username: ");
        scanf("%s",user);

        printf("Enter flight code to be booked and X to exit: ");
        scanf("%s",choice);
        fprintf(file,"%s",user);
        while(strcmp("X", choice)!=0)
        {
        fprintf(file," %s ",choice);
        printf("Enter flight code to be booked and X to exit: ");
        scanf("%s",choice);
        }
        fprintf(file,"\n");
        fclose(file);


        system("clear");

        printf("\n\nSEATING ARRANGEMENT\n\n");

        printseats();

    }
}