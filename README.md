# ЛР 3. Вычисление арифметических выражений

__Цель работы:__ Разработать программу, выполняющую вычисление арифметического выражения с вещественными числами. 
Выражение в качестве операндов может содержать переменные и вещественные числа. Допустимые операции известны: +, -, /, *. 
Допускается наличие знака "-" в начале выражения или после открывающей скобки.
Программа должна выполнять предварительную проверку корректности выражения и сообщать пользователю вид ошибки 
и номера символов строки, в которых были найдены ошибки.

__Этапы выполнения работы:__

1. Разработка стека на шаблоне
1. Разбиение исходного арифметического выражения на лексемы (т.е. выделить операнды, операции, переменные)
1. Проверка корректности выражения:
  - правильность расстановки скобок (с использованием стека для хранения индексов скобок).
  - пропущены ли операнды или знаки операций
  - недопустимые символы
1. Перевод выражения в постфиксную (польскую) запись
1. Вычисление выражения по постфиксной записи
1. Создание консольного интерфейса пользователя
1. Написание отчета

Все функции должны тестироваться с помощью Google test-ов.