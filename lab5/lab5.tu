00, ,<,00- // переход к началу числа
00-,0,<,00-
00-,1,<,00-
00-, ,>,01


// Работа с нечётными разрядами

01,0, ,02o0 // замена на пробел
01,1, ,02o1
01o, , ,08o0

02o0, ,>,03o0 // переход в крайнюю правую позицию заданного числа
02o1, ,>,03o1
03o0,0,>,03o0
03o0,1,>,03o0
03o0, ,>,04o0
03o1,0,>,03o1
03o1,1,>,03o1
03o1, ,>,04o1

04o0, ,0,05o0 // копирование цифры
04o0,0,>,04o0
04o0,1,>,04o0
04o1, ,1,05o1
04o1,0,>,04o1
04o1,1,>,04o1

05o0, ,<,05o0- // переход к исходной позиции взятой цифры
05o0,0,<,05o0
05o0,1,<,05o0
05o1, ,<,05o1-
05o1,0,<,05o1
05o1,1,<,05o1

05o0-, ,0,06o0 // возврат взятой цифры
05o0-,0,<,05o0-
05o0-,1,<,05o0-
05o1-, ,1,06o1
05o1-,0,<,05o1-
05o1-,1,<,05o1-

06o0-, , ,07o0 // переход к работе со следующей цифрой
06o0-,0,>,07o0 
06o0-,1,>,07o0
06o0,0,>,06o0-
06o1-, , ,07o1
06o1-,0,>,07o1 
06o1-,1,>,07o1
06o1,1,>,06o1-

08o0, ,>,08o0- // переход от работы с нечётными к чётным цифрам
08o0-,0,>,01e
08o0-,1,>,01e
08o0,0,<,08o0
08o0,1,<,08o0
08o1, ,>,08o0-
08o1,0,<,08o1
08o1,1,<,08o1

07o0, ,<,08o0 // первая чётная цифра
07o0,0,0,01
07o0,1,1,01
07o1, ,<,08o1
07o1,0,0,01
07o1,1,1,01


// Работа с чётными разрядами

01e,0, ,02e0 // замена на пробел
01e,1, ,02e1
01e, , ,07e0-

02e0, ,>,03e0 // переход в крайнюю правую позицию заданного числа
02e1, ,>,03e1
03e0,0,>,03e0
03e0,1,>,03e0
03e0, ,>,04e0-
03e1,0,>,03e1
03e1,1,>,03e1
03e1, ,>,04e1-

04e0-,0,>,04e0- // переход в крайнюю правую позицию первого результата
04e0-,1,>,04e0-
04e0-, ,>,04e0
04e1-,0,>,04e1-
04e1-,1,>,04e1-
04e1-, ,>,04e1

04e0, ,0,05e0 // копирование цифры
04e0,0,>,04e0
04e0,1,>,04e0
04e1, ,1,05e1
04e1,0,>,04e1
04e1,1,>,04e1

05e0, ,<,05e0-- // обратный путь через первый результат
05e0,0,<,05e0
05e0,1,<,05e0
05e1, ,<,05e1--
05e1,0,<,05e1
05e1,1,<,05e1

05e0--, ,<,05e0- // переход к исходной позиции взятой цифры
05e0--,0,<,05e0--
05e0--,1,<,05e0--
05e1--, ,<,05e1-
05e1--,0,<,05e1--
05e1--,1,<,05e1--

05e0-, ,0,06e0 // возврат взятой цифры
05e0-,0,<,05e0-
05e0-,1,<,05e0-
05e1-, ,1,06e1
05e1-,0,<,05e1-
05e1-,1,<,05e1-

06e0-, , ,07e0 // переход к работе со следующей цифрой
06e0-,0,>,07e0
06e0-,1,>,07e0
06e0,0,>,06e0-
06e1-, , ,07e1
06e1-,0,>,07e1 
06e1-,1,>,07e1
06e1,1,>,06e1-


// Конец программы 

07e0, ,>,07e0-
07e0---, , ,07e0---
07e0--, , ,07e0---
07e0--,0,>,07e0--
07e0--,1,>,07e0--
07e0-, ,>,07e0--
07e0-,0,>,07e0-
07e0-,1,>,07e0-
07e0,0,0,01e
07e0,1,1,01e
07e1, ,>,07e1-
07e1---, , ,07e1---
07e1--, , ,07e1---
07e1--,0,>,07e1--
07e1--,1,>,07e1--
07e1-, ,>,07e1--
07e1-,0,>,07e1-
07e1-,1,>,07e1-
07e1,0,0,01e
07e1,1,1,01e
