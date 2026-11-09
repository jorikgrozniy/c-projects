#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  while (*str && *str != c) str++;
  return *str == c ? (char *)str : S21_NULL;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  while (str[len]) len++;
  return len;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int found = 0;
  if (*needle) {
    while (*haystack && !found) {
      if (*haystack == *needle) {
        found = 1;
        const char *ptr1 = haystack;
        const char *ptr2 = needle;
        for (; *ptr1 && *ptr2; ptr1++, ptr2++)
          if (*ptr1 != *ptr2) found = 0;
        if (!*ptr1 && *ptr2) found = 0;
      }
      if (!found) haystack++;
    }
  } else
    found = 1;
  return found ? (char *)haystack : S21_NULL;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int diff = 0;
  if (n > 0) {
    while (*str1 && *str1 == *str2 && n > 1) {
      str1++;
      str2++;
      n--;
    }
    diff = (unsigned char)*str1 - (unsigned char)*str2;
  }
  return diff;
}
char *s21_strrchr(const char *str, int c) {
  const char *last = S21_NULL;
  while (*str) {
    if (*str == c) last = str;
    str++;
  }
  if (*str == c) last = str;
  return (char *)last;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *ptr = str2;
  int found = 0;
  while (*str1 && !found) {
    while (*ptr && !found) {
      if (*str1 == *ptr) found = 1;
      ptr++;
    }
    ptr = str2;
    if (!found) str1++;
  }
  return found ? (char *)str1 : S21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
  static char *last_pos;
  char *token = S21_NULL;
  if (str) last_pos = str;

  if (last_pos) {
    int found = 0;
    do {
      found = 0;
      for (const char *ptr = delim; *ptr; ptr++)
        if (*last_pos == *ptr) found = 1;
      if (found) last_pos++;
    } while (*last_pos && found);

    token = last_pos;
    for (; *last_pos && !found; last_pos++) {
      for (const char *ptr = delim; *ptr; ptr++)
        if (*last_pos == *ptr) found = 1;
      if (found) *last_pos = '\0';
    }
  }
  return token;
}

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest;

  while (*ptr != '\0') ptr++;

  while (*src != '\0' && n-- > 0) {
    *ptr++ = *src++;
  }

  *ptr = '\0';

  return dest;
}

void *s21_memset(void *dest, int value, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)dest;

  for (s21_size_t i = 0; i < n; i++) {
    ptr[i] = (unsigned char)value;
  }

  return dest;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }

  return dest;
}

int s21_memcmp(const void *s1, const void *s2, s21_size_t n) {
  const unsigned char *p1 = (const unsigned char *)s1;
  const unsigned char *p2 = (const unsigned char *)s2;

  while (n > 0 && ((uintptr_t)p1 & (sizeof(s21_size_t) - 1))) {
    if (*p1 != *p2) return *p1 - *p2;
    p1++;
    p2++;
    n--;
  }

  while (n >= sizeof(s21_size_t)) {
    s21_size_t block1 = *(const s21_size_t *)p1;
    s21_size_t block2 = *(const s21_size_t *)p2;

    if (block1 != block2) {
      for (s21_size_t i = 0; i < sizeof(s21_size_t); ++i) {
        if (p1[i] != p2[i]) return p1[i] - p2[i];
      }
    }

    p1 += sizeof(s21_size_t);
    p2 += sizeof(s21_size_t);
    n -= sizeof(s21_size_t);
  }

  while (n > 0) {
    if (*p1 != *p2) return *p1 - *p2;
    p1++;
    p2++;
    n--;
  }

  return 0;
}

void *s21_memchr(const void *ptr, int value, s21_size_t num) {
  void *result = S21_NULL;
  const unsigned char *p = ptr;

  int is_found = 0;
  for (s21_size_t i = 0; i < num && !is_found; i++) {
    if (p[i] == (unsigned char)value) {
      result = (void *)(p + i);
      is_found = 1;
    }
  }
  return result;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *p = str1;
  s21_size_t result = 0;

  int match_found = 0;

  while (*p != '\0' && !match_found) {
    const char *q;
    q = str2;
    while (*q != '\0' && !match_found) {
      if (*p == *q) {
        match_found = 1;
      }
      q++;
    }
    if (!match_found) {
      result++;
    }
    p++;
  }

  return result;
}

void int_to_str(int n, char *str) {
  int counter = 0, temp;

  if (n < 0) {
    *str++ = '-';
    n = -n;
  }

  temp = n;
  do {
    counter++;
    temp /= 10;
  } while (temp > 0);

  temp = n;
  while (counter > 0) {
    int power = 1;
    for (int i = 0; i < counter - 1; i++) {
      power *= 10;
    }
    *str++ = (temp / power) + '0';
    temp %= power;
    counter--;
  }
  *str = '\0';
}

char *s21_strerror(int errnum) {
  static char unknown[128];
  const char *errors_list[] = ERRLIST;
  const char *error_text = S21_NULL;

  if (errnum >= 0 && errnum < MAX_ERRS) {
    error_text = errors_list[errnum];
  } else {
    s21_strncpy(unknown, ERR_UNKNOWN, s21_strlen(ERR_UNKNOWN) + 1);
    char unknown_err_num[32];
    int_to_str(errnum, unknown_err_num);
    s21_strncat(unknown, unknown_err_num,
                sizeof(unknown) - s21_strlen(unknown) - 1);
    error_text = unknown;
  }

  return (char *)error_text;
}

void *s21_to_upper(const char *str) {
  if (str == S21_NULL) return S21_NULL;
  int len = (int)s21_strlen(str);

  char *new_str = malloc(len + 1);

  if (new_str == S21_NULL) return S21_NULL;

  for (int i = 0; i <= len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      new_str[i] = str[i] - ('a' - 'A');
    } else {
      new_str[i] = str[i];
    }
  }

  return new_str;
}

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) return S21_NULL;
  int len = (int)s21_strlen(str);

  char *new_str = malloc(len + 1);

  if (new_str == S21_NULL) return S21_NULL;

  for (int i = 0; i <= len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      new_str[i] = str[i] + ('a' - 'A');
    } else {
      new_str[i] = str[i];
    }
  }

  return new_str;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (!src || !str) return S21_NULL;
  if (start_index > s21_strlen(src)) return S21_NULL;

  char *new_str = malloc(s21_strlen(src) + s21_strlen(str) + 1);
  if (!new_str) return S21_NULL;

  char *ptr = new_str;

  for (s21_size_t i = 0; i < start_index; i++) {
    *new_str = src[i];
    new_str++;
  }

  while (*str) {
    *new_str = *str;
    new_str++;
    str++;
  }

  for (s21_size_t i = start_index; i < s21_strlen(src); i++) {
    *new_str = src[i];
    new_str++;
  }

  *new_str = '\0';
  return ptr;
}

char *s21_strdup(const char *src) {
  char *result = S21_NULL;

  if (src != NULL) {
    s21_size_t len = s21_strlen(src) + 1;
    result = (char *)malloc(len);

    if (result != NULL) {
      s21_memcpy(result, src, len);
    }
  }

  return result;
}

int s21_isspace(char c) {
  return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' ||
          c == '\f');
}

int s21_strspn(const char *str, const char *accept) {
  int count = 0;
  int stop = 0;
  while (str[count] && !stop) {
    int match_found = 0;
    for (int j = 0; accept[j]; j++) {
      if (str[count] == accept[j]) {
        match_found = 1;
      }
    }
    if (!match_found) {
      stop = 1;
    } else {
      count++;
    }
  }

  return count;
}

void *s21_trim(const char *src, const char *trim_chars) {
  void *result = S21_NULL;

  if (src != S21_NULL && trim_chars != S21_NULL) {
    s21_size_t src_len = s21_strlen(src);

    if (src_len == 0) {
      result = s21_strdup("");
    } else {
      int use_default_whitespace = (*trim_chars == '\0');
      const char *start = src;
      const char *end = src + src_len - 1;

      while (*start != '\0' &&
             (use_default_whitespace
                  ? s21_isspace(*start)
                  : s21_strchr(trim_chars, *start) != S21_NULL)) {
        start++;
      }

      while (end >= start && (use_default_whitespace
                                  ? s21_isspace(*end)
                                  : s21_strchr(trim_chars, *end) != S21_NULL)) {
        end--;
      }

      s21_size_t result_len = (end >= start) ? (end - start + 1) : 0;

      if (result_len == 0) {
        result = s21_strdup("");
      } else {
        char *tmp = (char *)malloc(result_len + 1);
        if (tmp != S21_NULL) {
          s21_memcpy(tmp, start, result_len);
          tmp[result_len] = '\0';
          result = tmp;
        }
      }
    }
  }

  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n && src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  while (i < n) {
    dest[i++] = '\0';
  }
  return dest;
}
