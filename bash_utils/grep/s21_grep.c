#include "s21_grep.h"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("usage: grep [options] template [file_name]\n");
    return 1;
  }

  int fileArg, templateArg;
  options fl = getFlags(argc, argv, &fileArg, &templateArg);
  if (fl.inv) {
    if (!fl.s) printf("s21_grep: invalid option\n");
    return 1;
  }

  int files = argc - fileArg;
  char template[1024];
  strcpy(template, argv[templateArg]);
  getTemplate(template, &fl);
  if (fl.inv) return 1;

  while (fileArg <= argc - 1) {
    printLines(&fl, argv, fileArg, template, files);
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

void combineFlags(options *f, options *f2) {
  if (f2->e) f->e = 1;
  if (f2->i) f->i = 1;
  if (f2->v) f->v = 1;
  if (f2->c) f->c = 1;
  if (f2->l) f->l = 1;
  if (f2->n) f->n = 1;
  if (f2->h) f->h = 1;
  if (f2->s) f->s = 1;
  if (f2->o) f->o = 1;
  if (f2->f) f->f = 1;
  if (f2->inv) f->inv = 1;
}

options getFlags(int argc, char *argv[], int *fileArg, int *tArg) {
  options fl = {0};
  *fileArg = argc - 1;
  *tArg = argc - 2;

  for (int i = argc - 3; i > 0; i--) {
    if (isFile(argv[i])) {
      *fileArg = i + 1;
      *tArg = i;
    }
  }

  for (int i = 1; i < *tArg; i++) {
    options fl2 = {0};
    if (argv[i][0] != '-') fl2.inv = 1;

    for (int j = 0; argv[i][j] != '\0'; j++) {
      char c = argv[i][j];
      if (j > 0) {
        if (c == 'f' && !fl2.inv)
          fl2.f = 1;
        else if (c == 'e')
          fl2.e = 1;
        else if (c == 'i')
          fl2.i = 1;
        else if (c == 'v')
          fl2.v = 1;
        else if (c == 'c')
          fl2.c = 1;
        else if (c == 'l')
          fl2.l = 1;
        else if (c == 'n')
          fl2.n = 1;
        else if (c == 'h')
          fl2.h = 1;
        else if (c == 's')
          fl2.s = 1;
        else if (c == 'o')
          fl2.o = 1;
        else
          fl2.inv = 1;
      }
    }
    if (isFile(argv[*tArg]) && !fl2.f) (*tArg)--, (*fileArg)--;
    if (i != *tArg) combineFlags(&fl, &fl2);
  }

  return fl;
}

char *getTemplate(char *template, options *f) {
  if (f->f) {
    FILE *fileT = fopen(template, "r");
    if (fileT != NULL) {
      fgets(template, sizeof(template), fileT);
      fclose(fileT);
    } else {
      if (!f->s) printf("s21_grep: %s: No such file or directory\n", template);
      f->inv = 1;
    }
  }
  return template;
}

void printForO(options *f, char *line, char *t, char *file, int files,
               int lineN) {
  char *pos = line;
  if (!f->i) {
    while ((pos = strstr(pos, t)) != NULL) {
      if (files > 1 && !f->h) printf("%s:", file);
      if (f->n) printf("%d:", lineN);
      printf("%s\n", t);
      pos += strlen(t);
    }
  } else {
    while ((pos = strcasestr(pos, t)) != NULL) {
      if (files > 1 && !f->h) printf("%s:", file);
      if (f->n) printf("%d:", lineN);

      int len = strlen(t);
      char buf[len + 1];
      strncpy(buf, pos, len);
      buf[len] = '\0';
      printf("%s\n", buf);
      pos += strlen(t);
    }
  }
}

int printLines(options *fl, char *argv[], int fileArg, char *template,
               int files) {
  FILE *file = fopen(argv[fileArg], "r");
  if (file == NULL) {
    if (!fl->s)
      printf("s21_grep: %s: No such file or directory\n", argv[fileArg]);
    return 1;
  }

  char line[4096];
  int lineN = 1, print = 0, printType = 1, matchingLines = 0, filePrinted = 0,
      res, change = 0, printedLast = 0;
  char *ptr;

  regex_t regex;
  res = regcomp(&regex, template, 0);
  if (res) {
    printf("s21_grep: Error compiling regular\n");
    return 1;
  }

  while (fgets(line, sizeof(line), file) != NULL) {
    print = 0, printType = 1, printedLast = 0;

    if (line[strlen(line) - 1] == '\n') {
      ptr = &line[strlen(line) - 1];
      *ptr = '\0';
      change = 1;
    }
    res = regexec(&regex, line, 0, NULL, 0);
    if (change) {
      *ptr = '\n';
      change = 0;
    }

    if (fl->i) {
      if (strcasestr(line, template) != NULL)
        res = 0;
      else
        res = 1;
    }
    if (fl->v) {
      res = !res;
    }
    if (!res) print = 1;

    if ((fl->c || fl->l) && !res) matchingLines++;

    if (fl->o && !fl->v && !fl->c && !fl->l) {
      print = 0;
      printForO(fl, line, template, argv[fileArg], files, lineN);
    }

    if (fl->l)
      printType = 3;
    else if (fl->c)
      printType = 2;

    if (fl->o && fl->v) print = 0;

    if (print) {
      printedLast = 1;
      if (files > 1 && printType != 3 && printType != 2 && !fl->h)
        printf("%s:", argv[fileArg]);
      if (fl->n && !fl->c && !fl->l) printf("%d:", lineN);
      if (printType == 1)
        fputs(line, stdout);
      else if (printType == 3 && !filePrinted) {
        printf("%s\n", argv[fileArg]);
        filePrinted = 1;
      }
    }
    lineN++;
  }

  if (printType == 2) {
    if (files > 1 && !fl->h) printf("%s:", argv[fileArg]);
    printf("%d\n", matchingLines);
  }
  if (printedLast && printType == 1) putchar('\n');
  if (fl->c && fl->l && !filePrinted) {
    if (files > 1) printf("%s:", argv[fileArg]);
    printf("0\n");
  }

  fclose(file);
  regfree(&regex);
  return 0;
}