#include <stdio.h>
#include <stdlib.h>
#include "GVariables.h"
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "Welcome.h"
void Welcome(){
    int i;
    for(i=0;i<8;i++){
        printf("\t");
    }
    printf("Welcome To Minesweeper\n"); //putting Welcome Msg
    printf("Minesweeper strategy is the art of solving games. Techniques include learning patterns and where to click first, using guessing tactics and developing efficient clicking and mouse movement.\n\n");
    printf("\t\t\t\t\t********************************************************************\n");
    printf("\t\t\t\t\t\t\t\t1-New Game\n\t\t\t\t\t\t\t\t2-Load Game\n\t\t\t\t\t\t\t\t3-Scores\n");
    printf("\t\t\t\t\tChoose the action by writing the corresponding number..\n");
    int choose=1;
    ReadNumber(&choose); //Decide what do you want
    if(choose==1){
            newgame();
    }
    else if (choose==2){
        system("cls");
        Load();
    }else if (choose==3){
        system("cls");
        scores();
    }
    else{
            while(choose!=1 && choose!=2 && choose!=3)
            {
            printf("You have to choose 1,2 or 3: ");
            ReadNumber(&choose);
            }
            if(choose==1){
                newgame();
            }
            else if (choose==2){
                system("cls");
                Load();
            }
            else if (choose==3){
                system("cls");
                scores();
            }
    }
}


