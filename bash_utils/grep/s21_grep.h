#ifndef S21_GREP_H
#define S21_GREP_H

#define _GNU_SOURCE
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int e, i, v, c, l, n, h, s, f, o, inv;
} options;

int isFile(char *name);
void combineFlags(options *f, options *f2);
options getFlags(int argc, char *argv[], int *fileArg, int *tArg);
char *getTemplate(char *template, options *f);
void printForO(options *f, char *line, char *t, char *file, int files,
               int lineN);
int printLines(options *fl, char *argv[], int fileArg, char *template,
               int files);

#endif