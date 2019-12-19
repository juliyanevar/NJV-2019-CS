#include "pch.h"
#include "Error.h"
namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
	//				0 -  100 - системные ошибки
	//				101 - 200 - ошибки параметров
	//				201 - 300 - ошибки лексического анализа
	//				301 - 400 - ошибки синтаксического анализа
	//				401 - 500 - ошибки семантического анализа
	//				501 - 600 - ошибки другие

		ERROR_ENTRY(0, "Недопустимый код ошибки"),
		ERROR_ENTRY(1, "Системный сбой"),
		ERROR_ENTRY_NODEF(2),ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6),ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8),ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),ERROR_ENTRY_NODEF(100),
		ERROR_ENTRY(101, "Параметр -in должен быть задан"),
		ERROR_ENTRY(102,"Превышена длина входного параметра"),
		ERROR_ENTRY(103,"Ошибка при открытии файла с исходным кодом(-in)"),
		ERROR_ENTRY(104,"Недопустимый символ в исходном файле (-in)"),
		ERROR_ENTRY(105,"Ошибка при создании файла протокола(-log)"),
		ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),	ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY_NODEF(110),	ERROR_ENTRY_NODEF(111),	ERROR_ENTRY_NODEF(112),
		ERROR_ENTRY_NODEF(113),	ERROR_ENTRY_NODEF(114),	ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116),	ERROR_ENTRY_NODEF(117),
		ERROR_ENTRY(118, "Дополнительная функция распологается ниже главной"),
		ERROR_ENTRY_NODEF(119),	ERROR_ENTRY_NODEF10(120),ERROR_ENTRY_NODEF10(130),	
		ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF(200),
		ERROR_ENTRY(201,"Превышен размер таблицы лексем"),
		ERROR_ENTRY(202,"Не удалось разобрать слово"),
		ERROR_ENTRY_NODEF(203),
		ERROR_ENTRY(204,"Переменная типа byte может принимать значения от 0 до 255"),
		ERROR_ENTRY(205,"Превышена максимальная длина строки"),
		ERROR_ENTRY_NODEF(206),
		ERROR_ENTRY_NODEF(207),ERROR_ENTRY_NODEF(208),
		ERROR_ENTRY_NODEF(209),ERROR_ENTRY_NODEF10(210),ERROR_ENTRY_NODEF10(220),
		ERROR_ENTRY_NODEF10(230),ERROR_ENTRY_NODEF10(240),ERROR_ENTRY_NODEF10(250),
		ERROR_ENTRY_NODEF10(260),ERROR_ENTRY_NODEF10(270),ERROR_ENTRY_NODEF10(280),
		ERROR_ENTRY_NODEF10(290),ERROR_ENTRY_NODEF(300),
		ERROR_ENTRY(301,"Неверная структура программы"),
		ERROR_ENTRY(302,"Ошибка в выражении"),
		ERROR_ENTRY(303,"Ошибочный оператор"),
		ERROR_ENTRY(304,"Ошибка в параметрах функции"),
		ERROR_ENTRY(305,"Ошибка в параметрах вызываемой функции"),
		ERROR_ENTRY(306,"Ошибочный оператор"),
		ERROR_ENTRY(307,"Ошибка в синтаксическом анализе"),
		ERROR_ENTRY(308, "Два сепаратора подряд"),
		ERROR_ENTRY_NODEF(309),ERROR_ENTRY_NODEF10(310),
		ERROR_ENTRY_NODEF10(320),ERROR_ENTRY_NODEF10(330),ERROR_ENTRY_NODEF10(340),
		ERROR_ENTRY_NODEF10(350),ERROR_ENTRY_NODEF10(360),ERROR_ENTRY_NODEF10(370),
		ERROR_ENTRY_NODEF10(380),ERROR_ENTRY_NODEF10(390),ERROR_ENTRY_NODEF(400),
		ERROR_ENTRY(401, "Главная функция (main) должна быть одна"),
		ERROR_ENTRY(402, "Точка входа main не найдена"),
		ERROR_ENTRY(403, "Попытка переопределения"), 
		ERROR_ENTRY(404, "Отсутствует предварительное определение"),
		ERROR_ENTRY(405, "Неверное количество параметров при вызове функции"),
		ERROR_ENTRY(406, "Тип возращаемого значения не соответсвует типу функции"),
		ERROR_ENTRY(407, "Превышено максимальное количество передаваемых параметров при вызове функции"),
		ERROR_ENTRY(408, "Превышено максимальное количество передаваемых параметров при определении функции"),
		ERROR_ENTRY(409," Нельзя передавать переменные типа bool и word в параметры функций sqrt и pow"),
		ERROR_ENTRY_NODEF(410),	ERROR_ENTRY_NODEF(411),
		ERROR_ENTRY(412, "Неверные типы параметров"),
		ERROR_ENTRY(413, "Несоответсвие типa идентификатора и присваемого ему значения"),
		ERROR_ENTRY(414,"В условии нельзя использовать идентификаторы типа word"),
		ERROR_ENTRY(415, "Попытка преобразования типов"),
		ERROR_ENTRY(416,"Нельзя использовать символы сравнения если в условие передаётся идентификатор типа bool"),
		ERROR_ENTRY(417, "Попытка проведения операций со строковым типом данных"),
		ERROR_ENTRY(418,"Неверное количество передаваемых параметров в sqrt"),
		ERROR_ENTRY(419, "Неверное количество передаваемых параметров в pow"),
		ERROR_ENTRY(420,"Значение функции pow может быть присвоено только идентификатору типа byte"),
		ERROR_ENTRY(421,"Значение функции sqrt может быть присвоено только идентификатору типа byte"),
		ERROR_ENTRY_NODEF(422),ERROR_ENTRY_NODEF(423),
		ERROR_ENTRY_NODEF(424),ERROR_ENTRY_NODEF(425),ERROR_ENTRY_NODEF(426),
		ERROR_ENTRY_NODEF(427),ERROR_ENTRY_NODEF(428),ERROR_ENTRY_NODEF(429),
		ERROR_ENTRY_NODEF10(430),ERROR_ENTRY_NODEF10(440),
		ERROR_ENTRY_NODEF10(450),ERROR_ENTRY_NODEF10(460),ERROR_ENTRY_NODEF10(470),
		ERROR_ENTRY_NODEF10(480), ERROR_ENTRY_NODEF10(490),
		ERROR_ENTRY_NODEF100(500),ERROR_ENTRY_NODEF(600) /* -несоответствие типов в условии;
-невозможно присвоить значение литералу;
-невозможно присвоить значение функции.*/

	};
	ERROR geterror(int id)
	{
		if (id < 0 || id >= ERROR_MAX_ENTRY)	throw ERROR_THROW(0);
		return errors[id];
	};
	ERROR geterrorin(int id, int line, int col)
	{
		ERROR a = geterror(id);
		a.inext.line = line;
		a.inext.col = col;
		return a;
	};
}