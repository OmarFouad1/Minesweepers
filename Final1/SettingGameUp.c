#include <stdio.h>
#include <stdlib.h>
#include "GVariables.h"
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "SettingGameUp.h"
int check(char x[],char y[]){
    if(strlen(x)!=strlen(y)){   //Check if String are identical
        return 0;
    }
    else{
        int i;
        int c=0;
        for(i=0;i<strlen(x);i++){
            if(x[i]==y[i]){
                c++;
            }
        }
        if(c==strlen(x)){
            return 1;
        }
        else if(c!=strlen(x)){
            return 0;
        }
    }
}
void Initialize(int arrR[][cols],char arrD[][cols]){
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){        //Initialize
               arrR[i][j]=0;
               arrD[i][j]='X';
        }
    }
}
void MinesDis(int arrR[][cols],char arrD[][cols],int dir1,int dir2){
    int i,j;
     mines = 1+(cols*rows)/10;
    srand(time(NULL));
    for(i=0;i<mines;i++){           //distribute mines randomly
            int v1=rand()%rows;
            int v2=rand()%cols;
            if(arrR[v1][v2]==-1 || ((v1==dir1)&&(v2==dir2))){
                    i--;
        }
        else{
            arrR[v1][v2]=-1;
        }
    }
}
void NumDis(int arrR[][cols],char arrD[][cols]){
    int i,j;
    for(i=0;i<rows;i++){                // distributeNumbers
        for(j=0;j<cols;j++){
             if(arrR[i][j]==-1){
                    int ii;
                    int jj;
                for(ii=i-1;ii<=i+1;ii++){
                    for(jj=j-1;jj<=j+1;jj++){

                        if(ii>=0 && ii<rows && jj>=0 && jj<cols && arrR[ii][jj]!=-1){
                            arrR[ii][jj]++;
                        }
                    }

            }
        }
    }}
}
