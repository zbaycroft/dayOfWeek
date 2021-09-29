/* weekday.c
   CSC 111 - Fall 2021 - Assignment 3

   Zachary Baycroft V00952013
*/

#include <stdio.h>
#include <stdlib.h>

int leapYear(int a){              //this is a function that tests whether a year 
    if(a % 4 != 0){               //is a leap year. 1 is true, 0 is false
        return 0;
    }else if(a % 100 != 0){
        return 1;
    }else if(a % 400 != 0){
        return 0;
    }else{
        return 1;
    }
}


int dayOfWeek(int year, int month, int day){         //day of month determiner
    int a = year % 100;
    a /= 4;
    a += day;
        if(month == 1 || month == 10){
            a += 1;
        }else if (month == 2 || month == 3 || month == 11){
            a += 4;
        }else if(month == 5){                   //month depandant addition
            a += 2;
        }else if(month == 6){
            a += 5;
        }else if(month == 8){
            a += 3;
        }else if(month == 9 || month == 12){
            a += 6;
        }else{
            a = a;    //redundant but helps me think abt it
        }
    
        if(leapYear(year) == 1 && (month == 1 || month == 2)){
            a -= 1;
        }
        
        int b = year/100;
        b = b % 4;
        b *= 2;
        a -= b;
        a = a + (year%100);
        a += 12;
        a = a%7;
    
        return a;
}



int main(){
    
    /* INPUT DATA */
    /* You may modify the values of each variable below, but DO NOT
       rename the variables, change their type or move the declarations. */

    int year = 2021;                       //data input
    int month = 9;
    int day = 30;
    
    if(year < 1 || year > 10000){           //error handling
        printf("Error: Invalid year\n");
        exit(0); 
    }else if(month < 1 || month > 12){
        printf("Error: Invalid month\n");
        exit(0);                                    //CHANGE ORDER TO CORRESPOND WITH SPECIFICATIONS
    }else if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31)){
        printf("Error: Invalid day\n");
        exit(0);
    }else if((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30)){
        printf("Error: Invalid day\n");
        exit(0);
    }else if(month == 2 && day > 28){
        printf("Error: Invalid day\n");
        exit(0);
    }else if(day < 1){
        printf("Error: Invalid day\n");
        exit(0);
    }
    
    int DOW = dayOfWeek(year, month, day);
    
    if(DOW == 0){
        printf("%d-%d-%d: Sunday\n", year, month, day);            //output
    }else if(DOW == 1){
        printf("%d-%d-%d: Monday\n", year, month, day);
    }else if(DOW == 2){
        printf("%d-%d-%d: Tuesday\n", year, month, day);
    }else if(DOW == 3){
        printf("%d-%d-%d: Wednesday\n", year, month, day);
    }else if (DOW == 4){
        printf("%d-%d-%d: Thursday\n", year, month, day);
    }else if (DOW == 5){
        printf("%d-%d-%d: Friday\n", year, month, day);
    }else if(DOW == 6){
        printf("%d-%d-%d: Saturday\n", year, month, day);
    }
    
    
    return 0;
}


