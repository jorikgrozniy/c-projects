#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdint.h>
#include <stdlib.h>

#include "s21_strerror.h"

#define S21_NULL (void *)0
typedef unsigned long int s21_size_t;

int s21_sprintf(char *str, const char *format, ...);
char *s21_strchr(const char *str, int c);
s21_size_t s21_strlen(const char *str);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
void *s21_memset(void *dest, int value, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
int s21_memcmp(const void *s1, const void *s2, s21_size_t n);
void *s21_memchr(const void *ptr, int value, s21_size_t num);
s21_size_t s21_strcspn(const char *str1, const char *str2);
void int_to_str(int n, char *str);
char *s21_strerror(int errnum);
int s21_isspace(char c);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
char *s21_strdup(const char *src);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strcpy(char *dest, const char *src);
char *s21_strstr(const char *haystack, const char *needle);
int s21_sscanf(const char *str, const char *format, ...);
int s21_strspn(const char *str, const char *accept);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strrchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);

#endif