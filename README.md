# C: библиотеки и Unix-утилиты

Четыре независимых проекта на C11 в одном репозитории. Демонстрируют ручное управление памятью, битовую арифметику, разбор format-строк, POSIX API и тестирование.

## Проекты

| Проект | Что реализовано | Ключевые детали |
| --- | --- | --- |
| [string_plus](string_plus/README.md) | Собственная `string.h` + `sprintf`/`sscanf` | 15 функций libc, 706 тестов, сравнение с libc |
| [decimal](decimal/README.md) | 96-битный decimal с фиксированной точкой | `uint32_t bits[4]`, 192-битные промежуточные вычисления, банковское округление |
| [matrix](matrix/README.md) | Матричная алгебра на `double**` | Определитель, миноры, обратная матрица, коды ошибок |
| [bash_utils](bash_utils/README.md) | Клоны `cat` и `grep` | POSIX `regex.h`, побайтовая обработка, интеграционные diff-тесты |

## Сборка и тесты

Каждый проект собирается независимо, корневого Makefile нет:

```sh
cd string_plus && make && make test
cd decimal     && make && make test
cd matrix      && make && make test
cd bash_utils/cat  && make && make test
cd bash_utils/grep && make && make test
```

- `make` - собрать библиотеку или исполняемый файл.
- `make test` - собрать и запустить тесты.
- `make gcov_report` - HTML-отчёт покрытия (кроме `bash_utils`).

Зависимости: `gcc`, `make`; для unit-тестов - Check (`check.h`, pkg-config); для покрытия - `lcov` и `genhtml`.

## Структура

```text
string_plus/   string.h, sprintf, sscanf
decimal/       96-битный decimal
matrix/        матричная библиотека
bash_utils/    s21_cat и s21_grep
```
