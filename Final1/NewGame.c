#include <stdio.h>
#include <stdlib.h>
#include "GVariables.h"
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "NewGame.h"
struct scores{
        char name1[100];
        int scorez;
        }player; //This Structure saves name and score of player after he win
struct scoreboard{
            char x[100];
            int y;
            }data[100]; //This Structure saves Names and scores to view scoreboard
void startthegame (char arrD[rows][cols],int arrR[rows][cols]){
    int ii,jj;
    FILE *x=fopen("Array.txt","w");
    for(ii=0;ii<rows;ii++){
        for(jj=0;jj<cols;jj++){
            fprintf(x,"%d ",arrR[ii][jj]);
        }
        fprintf(x,"\n");
    }
    fclose(x);
    printarray(arrD);
    int dir1,dir2;
    char stat[3];
    char h1,h2;
    int counter=0;
    while(rows*cols-noOfblocks!=mines){  //This condition is responsible for starting the game
            stat[0]=' ';
        while(stat[0]!='O'&&stat[0]!='F'&&stat[0]!='U'&&stat[0]!='Q'&&stat[0]!='S'&&stat[0]!='E' || sscanf(stat,"%c %c",&h1,&h2)!=1){
            if(counter!=0) //prevent Error first time.
                printf("Error..Invalid Input\n");
            printf("Enter One Of The Operations(O(open),F(flag),U(unmark),Q(put ?),S(save),Please: ");
            gets(stat); // Here We put Error Msgs
            counter++;
        if(stat[0]=='S') //ToSaveGame
                {
            Save(arrR,arrD,mines);
            stat[0]=' ';
            counter=0;
                }
        }
        counter=0;
        ReadDirection(&dir1,&dir2);
        if(stat[0]=='O'){ //ToOpen
            open(arrR,arrD,dir1,dir2);
            Moves++;
        }
        else if(stat[0]=='F'){ //Flag
            flag(arrR,arrD,dir1,dir2);
            Flags++;
        }
        else if(stat[0]=='Q'){ //Uncertain
            question(arrR,arrD,dir1,dir2);
            QuestionMarks++;
        }
        else if(stat[0]=='U'){//Unmark
            if(arrD[dir1][dir2]=='?'){
                QuestionMarks--;
            }
            if(arrD[dir1][dir2]=='F'){
                Flags--;
            }
            unmark(arrR,arrD,dir1,dir2);
        }
        system("cls");
        printarray(arrD);
    }
    printf("Congratulations,You Won\n");
    int score=(cols)*(cols)*(cols)*(cols)*(rows)*(rows)*(rows)*(rows)/((Moves)*(Time));
    char names[100];
    printf("Write Your Name: "); //taking names to put in scoreboard
    scanf("%s",player.name1);
    int i;
    for(i=0;i<strlen(player.name1);i++){
        player.name1[i]=tolower(player.name1[i]);  //making it case insensitive
    }
    player.scorez=score;
    FILE *Pointer=fopen("scoreboard.txt","ab");
    fwrite(&player,sizeof(player),1,Pointer);
    fclose(Pointer);
}
void newgame (){
    rows=0;
    cols=0;
    while (!(rows>=2||cols>=2)){
    printf("Enter Number of Rows: ");
    scanf("\n");
    ReadNumber(&rows);
    printf("Enter Number of cols: ");
    ReadNumber(&cols);
    if (!(rows>=2||cols>=2)){
        printf(" ONE OF ROWS OR COLS MUST BE GREATER THAN 2...RETRY>>\n");
    }
    }
     mines = 1+(cols*rows)/10;
    int arrR[rows][cols];
    char arrD[rows][cols];
    Initialize(arrR,arrD);
    int dir1,dir2;
    system("cls");
    startTime=clock();
    printarray(arrD);
    ReadDirection(&dir1,&dir2);
    printf("\n");
    system("cls");
    MinesDis(arrR,arrD,dir1,dir2);
    NumDis(arrR,arrD);
    open(arrR,arrD,dir1,dir2);
    Moves++;
    startthegame(arrD,arrR);

}


