#include <stdio.h>
#include <stdlib.h>
#include "GVariables.h"
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "Read&Write.h"
void printarray(char a[][cols]){
    int i,j,ii=0;            //PrintArray
    float endtime=clock();
    Time=(endtime-startTime)/CLOCKS_PER_SEC;
    int coun;
    int count=(149-(5*cols))/10;
    for(coun=0;coun<count;coun++){
        printf("     ");
    }
    for(i=0;i<cols;i++){
        printf("  %d",i);
        if(i<9){
            printf(" ");
        }
    }
    printf("\n");
    for(i=0;i<rows;i++){
            printf("\n");
            for(coun=0;coun<count;coun++){
                printf("     ");
                }
        while(ii<cols){
            printf("____");
            ii++;
        }
        ii=0;
        printf("\n");
        for(coun=0;coun<count;coun++){
        printf("     ");
        }
        for(j=0;j<cols;j++){
            printf("|");
            if(a[i][j]!='X'){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 249);
            }
            if (a[i][j]=='!'||a[i][j]=='*'||a[i][j]=='-'||a[i][j]=='M'){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252);
            }
            printf(" %c ",a[i][j]);
            if(a[i][j]!='X'){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
            }
            if(j==cols-1){
                printf("|");
            }
        }
        printf("    %d",i);
    }
    int minutes=(int)Time/60;
    float seconds=Time-minutes*60;
    printf("\n\t\t\t\t\t\t\t    Time:  %d:%.2f",minutes,seconds);
    printf("\n\t\t\t\t\t\t\t    Moves: %d\n\t\t\t\t\t\t\t    Flags: %d\n\t\t\t\t\t\t\t    QMarks:%d\n\t\t\t\t\t\t\t    Opened:%d",Moves,Flags,QuestionMarks,noOfblocks);
    printf("\n\n");
}
void ReadNumber(int *dir1){
    char read[100];
    char a;
    for (;;){           //ReadIntegers
        scanf("\n");
        gets(read);
        char temp[100];
        int count;
        count=sscanf(read,"%d %s",dir1,&temp);
        if (count==1){
            break;
        }else
        printf("Error ....please enter just an integer: ");
    }
}
void ReadDirection(int *dir1,int *dir2){
      for (;;){                 //Reading both X and Y
        printf("please choose the row of the block to open : ");
        ReadNumber(dir1);
         printf("please choose the col of the block to open : ");
        ReadNumber(dir2);
         if (*dir1<0||*dir1>=rows||*dir2<0||*dir2>=cols){
            printf("Error ...out of range !\n");
         }else{
         break;}}}

