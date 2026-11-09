#ifndef S21_CAT_H
#define S21_CAT_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int b, e, E, n, s, t, T, v, inv;
} options;

int isFile(char *name);
options getFlags(int argc, char *argv[], int *fileArg);
int isFlagInvis(options *f);
int printFile(options *fl, char *argv[], int fileArg);

#endif