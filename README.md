# oop_4

Реализовать класс Date, хранящий в себе информацию о дате (год, месяц, число, час, минута, секунда, эра). За эру отвечает поле isOurEra типа bool (true – наша эра, false – до нашей эры).
В классе Date должны быть реализованы методы со следующей сигнатурой: add/subtract(year, month, day, hour, minute, second), которые должны возвращать новый объект класса Date.
В классе Date должны быть перегружены следующие операторы: оператор копирования, <<, =, +, +=, -, -=, >, <, ==.
Датой инициализации по умолчанию должна быть 1 января 1960 года, 00 часов, 00 минут, 00 секунд.
Должно учитываться, что год может быть високосным.
Нарисовать UML диаграмму.
