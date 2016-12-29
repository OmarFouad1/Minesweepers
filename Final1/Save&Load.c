#include <stdio.h>
#include <stdlib.h>
#include "GVariables.h"
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "Save&Load.h"
struct scores{
        char name1[100];
        int scorez;
        }player; //This Structure saves name and score of player after he win
struct scoreboard{
            char x[100];
            int y;
            }data[100]; //This Structure saves Names and scores to view scoreboard
void scores(){
    FILE *p1=fopen("scoreboard.txt","rb"); //reading binary files
    if(p1==NULL){
        printf("\t\t\t\t\t\t\tScoreboard is Empty\n");
        printf("\n\t\t\t\t\t\tPress Any Key to Go To Main Menu...");
        char g=getch();
        system("cls");
        Welcome();
    }
    int i;
    int noOfElements=-1; //it starts at -1 because when it reads a file it counts last empty line
    for(i=0;!feof(p1);i++){
    fseek(p1,i*sizeof(data[i]),0);
    fread(&data[i],sizeof(data[i]),1,p1); //reading names+scores in the structure mentioned above
    noOfElements++;
    }
    fclose(p1);
    int j=0;
    int counter=0;
    char abs[5]="";
    for(i=0;i<noOfElements;i++){
        for(j=i+1;j<noOfElements;j++){
            if(check((data[i].x),(data[j].x))&&!check((data[i].x),abs)){
                    strcpy((data[j].x),abs); //this loop check if there are repeated names
                    data[i].y+=data[j].y;
                    counter++;
            }
        }
    }
    for(i=0;i<noOfElements;i++){
        for(j=0;j<noOfElements;j++){
            if((data[j].y)<(data[j+1].y)){
                int temp;
                char temp1[100];
                strcpy(temp1,(data[j+1].x));
                strcpy((data[j+1].x),(data[j].x)); //This Loop for Sorting
                strcpy((data[j].x),(temp1));
                temp=data[j+1].y;
                data[j+1].y=data[j].y;
                data[j].y=temp;
            }
        }
    }


    int rank=1;
    for(i=0;i<noOfElements;i++){
    if(check((data[i].x),(abs))){
    }
    else {
    printf("\t\t\t\t\t\t%d-%s   \t\t%d\n",rank,data[i].x,data[i].y); //Here We filter the names and put ranks
            rank++;
    }
    }
    printf("\n\t\t\t\t\t\tPress Any Key to Go To Main Menu...");
    char g=getch();
    system("cls");
    Welcome();
}
void Load (){
    int i,j;
    printf("Kindly,write down the name of saved file: ");
        int mines;
        char fileName[100];
        gets(fileName);
        FILE *f=fopen(fileName,"rb");
        while(f==NULL)
            {
        printf("Failed to Find File,Retry: ");
        gets(fileName);                         //Check if the file is there or not
        f=fopen(fileName,"rb");
            }
        fseek(f,0,0);
        fread(&rows,4,1,f);
        fread(&cols,4,1,f);
        int arrR[rows][cols];
        char arrD[rows][cols];
        fread(&Time,sizeof(float),1,f);
        fread(&mines,4,1,f);
        fread(&noOfblocks,4,1,f);   //There Part Read data from the file
        fread(&Moves,4,1,f);
        fread(&Flags,4,1,f);
        fread(&QuestionMarks,4,1,f);
        fread(arrD,1,rows*cols,f);
        fread(arrR,4,rows*cols,f);
        fclose(f);
        startTime=clock()-Time*pow(10,3);
        startthegame(arrD,arrR);  //Go To Game with loaded data
    }

    void Save(int arrR[][cols],char arrD[][cols],int mines){
    char saveFile[100];
    printf("\tWrite The Name of File to save: ");
    gets(saveFile);
    FILE *check=fopen(saveFile,"r");
    while(check!=NULL){
            printf("This Name already exists,Retry: "); //check if the name is taken
            gets(saveFile);
            check=fopen(saveFile,"r");
    }
    FILE *fR=fopen(saveFile,"wb");
    fwrite(&rows,4,1,fR);
    fwrite(&cols,4,1,fR);
    fwrite(&Time,sizeof(float),1,fR);
    fwrite(&mines,4,1,fR);
    fwrite(&noOfblocks,4,1,fR);
    fwrite(&Moves,4,1,fR);
    fwrite(&Flags,4,1,fR);          //Write Saved data to binary file
    fwrite(&QuestionMarks,4,1,fR);
    fwrite(arrD,1,rows*cols,fR);
    fwrite(arrR,4,rows*cols,fR);
    fclose(fR);
    printf("\tThe Game is saved as %s\n",saveFile);
}

