#include <stdio.h>
#include <stdlib.h>
#include "GVariables.h"
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "Save&Load.h"
#include "NewGame.h"
#include "Read&Write.h"
#include "Welcome.h"
#include "Actions.h"
#include "SettingGameUp.h"
#include "NewGame.h"
int rows,cols;
int noOfblocks=0;
int Moves=0;
int Flags=0;
int QuestionMarks=0;
float Time=0;
int mines;
float startTime;
int main()
{
    system("COLOR F0");
    Welcome();
    return 0;
}
