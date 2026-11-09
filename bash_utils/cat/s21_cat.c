#include "s21_cat.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("usage: cat [OPTION] [FILE]...\n");
    return 1;
  }

  int fileArg;
  options fl = getFlags(argc, argv, &fileArg);

  if (fl.inv == 1) {
    printf("s21_cat: invalid option\n");
    return 1;
  }

  while (fileArg <= argc - 1) {
    printFile(&fl, argv, fileArg);
    fileArg++;
  }

  return 0;
}

int isFile(char *name) {
  int res = 0;
  FILE *file = fopen(name, "r");
  if (file != NULL) {
    res = 1;
    fclose(file);
  }
  return res;
}

options getFlags(int argc, char *argv[], int *fileArg) {
  options fl = {0};
  *fileArg = argc - 1;

  for (int i = argc - 1; i > 0; i--) {
    if (isFile(argv[i])) *fileArg = i;
  }

  for (int i = 1; i < *fileArg; i++) {
    for (int j = 0; argv[i][j] != '\0'; j++) {
      char c = argv[i][j];
      if (argv[i][1] != '-' && j > 0) {
        if (c == 'b')
          fl.b = 1;
        else if (c == 'e')
          fl.e = 1;
        else if (c == 'E')
          fl.E = 1;
        else if (c == 'n')
          fl.n = 1;
        else if (c == 's')
          fl.s = 1;
        else if (c == 't')
          fl.t = 1;
        else if (c == 'T')
          fl.T = 1;
        else if (c == 'v')
          fl.v = 1;
        else
          fl.inv = 1;
      }

      if (argv[i][0] != '-')
        fl.inv = 1;
      else if (argv[i][1] == '-') {
        if (strcmp(argv[i], "--number-nonblank") == 0)
          fl.b = 1;
        else if (strcmp(argv[i], "--number") == 0)
          fl.n = 1;
        else if (strcmp(argv[i], "--squeeze-blank") == 0)
          fl.s = 1;
        else
          fl.inv = 1;
      }
    }
  }
  return fl;
}

int isFlagInvis(options *f) {
  int res = 0;
  if (f->e || f->t || f->v) res = 1;
  return res;
}

int printFile(options *fl, char *argv[], int fileArg) {
  FILE *file = fopen(argv[fileArg], "rb");
  if (file == NULL) {
    printf("s21_cat: %s: No such file or directory\n", argv[fileArg]);
    return 1;
  }

  unsigned char c, pc = '\n';
  int ch, spaces, blankLines = 0, line = 1;
  while ((ch = fgetc(file)) != EOF) {
    c = ch;
    spaces = 5 - line / 10;

    if (fl->s && pc == '\n') {
      if (c == '\n')
        blankLines++;
      else
        blankLines = 0;
    }

    if (blankLines < 2) {
      if (fl->b) {
        if (pc == '\n' && c != '\n') {
          while (spaces > 0) {
            putchar(' ');
            spaces--;
          }
          printf("%d\t", line);
          line++;
        } else if (fl->e && pc == '\n')
          printf("      \t");
      } else if (fl->n && pc == '\n') {
        while (spaces > 0) {
          putchar(' ');
          spaces--;
        }
        printf("%d\t", line);
        line++;
      }

      if ((fl->e || fl->E) && c == '\n') putchar('$');
      if (!isprint(c) && c != '\n' &&
          (((fl->e || fl->v) && c != '\t') || fl->t))
        printf("^%c", c + 64);
      if (fl->T && c == '\t') printf("^%c", c + 64);
      if (!((fl->t || fl->T) && c == '\t') &&
          (!isFlagInvis(fl) || isprint(c) || c == '\n' || c == '\t'))
        putchar(c);
    }

    pc = c;
  }

  fclose(file);
  return 0;
}