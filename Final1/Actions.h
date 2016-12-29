#ifndef ACTIONS
#define ACTIONS
#include "GVariables.h"
void open(int a[rows][cols],char b[rows][cols],int dir1,int dir2);
void flag (int a[rows][cols],char b[rows][cols],int dir1,int dir2);
void question (int a[rows][cols],char b[rows][cols],int dir1,int dir2);
void unmark(int a[rows][cols],char b[rows][cols],int dir1,int dir2);
#endif // ACTIONS
