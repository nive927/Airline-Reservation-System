#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>
#include<time.h>
#include<ctype.h>



struct date
{
    int day;
    int month;
    int year;
};

struct time
{
    int hh;
    int mm;
};

int isleap(int y)
{
    if (y%4==0)
        if (y%100==0)
            if (y%400==0)
                return 1;
            else
                return 0;
        else
            return 1;
    else
        return 0;

}
int datetoday(int d, int m, int y)
{
    //no. of days since the beginning of the year
    int month[12] = { 31, 28, 31, 30, 31, 30, 
                      31, 31, 30, 31, 30, 31 }; 

    if (isleap(y))
        month[1]=29;
    int days=0;
    for (int i=0; i<m-1; i++)
    {
        days+=month[i];
    }

    days+=d;
    return days;
}

void addtodate(int x, int d, int m, int y, struct date *newdate)
{
    int days, total, rem;
    int month[12] = { 31, 28, 31, 30, 31, 30, 
                      31, 31, 30, 31, 30, 31 }; 

    days= datetoday(d, m, y)+x;
    total=isleap(y)?366:365;
    if (isleap(y))
        month[1]=29;
    rem=total-(days-x);
    if (x>rem)
    {
        newdate->year=y+1;
        days=x-rem;
        if (isleap(y))
            month[1]=29;
        else
            month[1]=28;
        newdate->month=1;
        int i=0;
        while(days>month[i])
        {
            days-=month[i];
            (newdate->month)++;
            i++;

        }
        



    }

    else
    {
        newdate->year=y;
        newdate->month=1;
        int i=0;
        while(days>month[i])
        {
            days-=month[i];
            (newdate->month)++;
            i++;

        }
        
    }
    newdate->day=days;
}


int convert(int mm, int dd, int yy) /* convert date to numerical day of week */ 

{ 

    long ndays; /* number of days from start of 1900 */ 

    long ncycles; /* number of 4-year cycles beyond 1900 */ 

    int nyears; /* number of years beyond last 4-year cycle */ 

    /* numerical conversions */
    yy-=1900; 

    ndays = (long) (30.42 * (mm - 1)) + dd; /* approximate day of year */ 

    if (mm == 2) ++ndays; /* adjust for February */ 

    if ((mm > 2) && (mm < 8)) --ndays; /* adjust for March - July */ 

    if ((yy % 4 == 0) && (mm > 2)) ++ndays; /* adjust for leap year */ 

    ncycles = yy / 4; /* 4-year cycles beyond 1900 */ 

    ndays += ncycles * 1461; /* add days for 4-year cycles */ 

    nyears = yy % 4; /* years beyond last 4-year cycle */ 

    if (nyears > 0) /* add days for yrs beyond last 4-year cycle */ 

    ndays += 365 * nyears + 1 ; 

    if (ndays > 59) --ndays; /* adjust for 1900 (NOT a leap year) */ 
     
    return(ndays) ; 

} 

int timediff(int days, struct time arr, struct time dep)
{
    int result=(days*24*60) + (dep.hh-arr.hh)*60+(dep.mm-arr.mm);
    return result;
}
