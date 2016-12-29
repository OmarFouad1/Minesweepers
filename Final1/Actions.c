#include <stdio.h>
#include <stdlib.h>
#include "GVariables.h"
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "Actions.h"
void open(int a[rows][cols],char b[rows][cols],int dir1,int dir2){
    int i,j;
if(a[dir1][dir2]!=0&&a[dir1][dir2]!=-1&&b[dir1][dir2]=='X'){
    b[dir1][dir2]=a[dir1][dir2]+'0';
    noOfblocks++; //Open to find a number
}
else if (a[dir1][dir2]==0&&b[dir1][dir2]=='X'){
            b[dir1][dir2]=' ';
            noOfblocks++;
            for (i=dir1-1;i<=dir1+1;i++){
                for(j=dir2-1;j<=dir2+1;j++){ //open empty cell DFS
                    if (i>=0 && i<rows && j>=0 && j<cols && b[i][j]=='X') {
                    open(a,b,i,j);
                    }
                }
            }
}else if (a[dir1][dir2]!=-1&&a[dir1][dir2]!=0&&b[dir1][dir2]==a[dir1][dir2]+'0'){
    int noflags=0;
    for (i=dir1-1;i<=dir1+1;i++){
        for (j=dir2-1;j<=dir2+1;j++){
            if (b[i][j]=='F'&&i>=0 && i<rows && j>=0 && j<cols){
                noflags++; //count number of Flags
            }
        }
    }
    if (a[dir1][dir2]==noflags){
        for (i=dir1-1;i<=dir1+1;i++){
            for (j=dir2-1;j<=dir2+1;j++){
                if (i>=0 && i<rows && j>=0 && j<cols && b[i][j]!='F' &&b[i][j]=='X'){
                    open(a,b,i,j); //use number of Flags to open the opened cell
                }
            }
        }
    }
}
else if(a[dir1][dir2]==-1){ //lose
    b[dir1][dir2]='!';
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            if((b[i][j]=='X' ||b[i][j]=='?')  &&a[i][j]!=0&&a[i][j]!=-1){
                b[i][j]=a[i][j]+'0';
            }
            else if(b[i][j]=='F' && a[i][j]!=-1){
                b[i][j]='-';
            }
            else if(b[i][j]=='F'&&a[i][j]==-1){
                b[i][j]='*';
            }
            else if(a[i][j]==-1&&(b[i][j]=='?'||b[i][j]=='X')){
                b[i][j]='M';
            }
            else if(a[i][j]==0&&(b[i][j]=='X'||b[i][j]=='?')){
                b[i][j]=' ';
            }
        }
    }
    system("cls");
    printarray(b);
    Moves++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 252); //red color
    printf("                                                                YOU LOST!!\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    printf("\t\t\t\t\t\t\tPress AnyThing To continue..");
    getch();
    exit(0);
        }
    }
void flag (int a[rows][cols],char b[rows][cols],int dir1,int dir2){ //flags
    if (b[dir1][dir2]=='X'){
        b[dir1][dir2]='F';
    }
}
void question (int a[rows][cols],char b[rows][cols],int dir1,int dir2){ //Uncertainty
    if(b[dir1][dir2]=='X'){
        b[dir1][dir2]='?';
    }
}
void unmark(int a[rows][cols],char b[rows][cols],int dir1,int dir2){ //Unmark
    if (b[dir1][dir2]=='F'||b[dir1][dir2]=='?'){
        b[dir1][dir2]='X';
    }
}

