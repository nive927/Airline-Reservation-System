
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include "linkedList_dec.h"

void createAdjList( linkedList* adjList[], int n)
{
    for (int i=0; i<n; i++)
    {
        adjList[i]=create();
        
    }
}

/*

struct path
{
    struct flight route[30];
    int num; //no. of flights travelled in the route
    float cost;
};

*/

void DFS(enum places source, enum places dest, enum places day, int visited[], struct path trip,int *path_no, linkedList* adj_list[], struct path paths[], struct date *dep_date, struct tm *curr)
{   

 
	
    
    visited[source]=1;
    int days, time;
    int v_cpy[10]; //copy of the visited array
    struct path trip_cpy;
    if (source==dest)
    {
    	printf("PATH FOUND\n");
        paths[*path_no]=trip;
        (*path_no)++;

    }

    else if (trip.num!=0)
    {
        linkedList* temp= adj_list[source]->next;
        while(temp!=NULL)
        {
            if (visited[temp->flight.details.destination]==0)
            {
            	
                
                if ((int)(temp->flight.details.day-trip.route[trip.num-1].details.day)<0)
                    days=(temp->flight.details.day-trip.route[trip.num-1].details.day+7);
                else
                    days=temp->flight.details.day-trip.route[trip.num-1].details.day; //no. of days passes between arrival of previous flight and departure of the current flight


                time=timediff(days,trip.route[trip.num-1].details.arrtime, temp->flight.details.deptime);
                trip_cpy=trip;       //copy of trip
                trip_cpy.route[trip.num]=temp->flight;
                trip_cpy.num++;
                addtodate(days, trip.route[trip.num-1].flight_date.day, trip.route[trip.num-1].flight_date.month, trip.route[trip.num-1].flight_date.year, &trip_cpy.route[trip_cpy.num-1].flight_date);//adds to days to date
                
                if (time>15&&time<=360) 
                //waiting time must be greater than 15 mins and lesser than 6 hours. Date must not be more than 30 days from the current date
                
                {
                
                	
                   
                    
                    arr_cpy(v_cpy, visited);
                    DFS(temp->flight.details.destination, dest, day, v_cpy, trip_cpy, path_no, adj_list, paths, dep_date, curr);
                }
               
            }


            temp= temp->next;
        }
    }
    else
    {
        linkedList* temp= adj_list[source]->next;
        while(temp!=NULL)
        {
            if (visited[temp->flight.details.destination]==0&&temp->flight.details.day==day)
                //For the first flight, day of operation must be same as the day of departure

            {  
            	
                trip_cpy=trip;
                trip_cpy.route[trip.num]=temp->flight;
                trip_cpy.route[trip.num].flight_date=*dep_date;
                trip_cpy.num++;
                arr_cpy(v_cpy, visited);
                DFS(temp->flight.details.destination, dest, day, v_cpy, trip_cpy, path_no, adj_list, paths, dep_date, curr);
            }

            temp=temp->next;
        }
    
    }
    return;
}