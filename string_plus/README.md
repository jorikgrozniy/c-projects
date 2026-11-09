# string_plus

Собственная реализация `string.h` и функций форматирования `sprintf`/`sscanf` на C11. В коде библиотеки не используются функции стандартной `string.h`.

## Реализовано

- `memchr`, `memcmp`, `memcpy`, `memset`
- `strncat`, `strchr`, `strncmp`, `strncpy`, `strcspn`, `strerror`, `strlen`, `strpbrk`, `strrchr`, `strstr`, `strtok`
- `to_upper`, `to_lower`, `insert`, `trim`
- `s21_sprintf`: `%c`, `%d`, `%f`, `%s`, `%u`, `%%`; флаги `-`, `+`, пробел; ширина; точность; длины `h`, `l`
- `s21_sscanf`: `%d`, `%i`, `%o`, `%u`, `%x/%X`, `%e/%E`, `%g/%G`, `%f`, `%c`, `%s`, `%p`, `%n`, `%%`; подавление `*`, ширина, длины `h`, `l`, `L`
- `s21_strerror`: собственные таблицы сообщений для Linux и macOS, без `sys_errlist`/`sys_nerr`

## Тесты

706 Check-кейсов. Функции `string.h` и `sprintf`/`sscanf` сравниваются с реализацией libc.

## Сборка

```sh
make          # s21_string.a
make test     # требует Check
make gcov_report
```

Файлы: `s21_string.c`, `s21_sprintf.c`, `s21_sscanf.c`, `s21_strerror.h`.
