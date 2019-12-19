#pragma once

#include"Error.h"
#include <string>

#define	LEXEMA_FIXSIZE	1			// Фиксированный размер таблицы лексем
#define	LT_MAXSIZE		65536		// Максимальный размер таблицы лексем
#define	LT_TI_NULLDX	0xffffffff	// Пустота в таблице лексем
#define LT_TI_NULLIDX	0xfffffff	// нет элемента таблицы идентификаторов
#define LEX_SEPARATORS	'S'
#define	LEX_BYTE		't'			// Целый 1 байт
#define	LEX_WORD		'w'			// Строка
#define LEX_BOOL		'b'			// Логический
#define LEX_OBJECT      't'			// Обьект						
#define	LEX_ID			'i'			// Индентификатор
#define	LEX_LITERAL		'l'			// Литерал
#define	LEX_FUNCTION	'f'			// Функция
#define	LEX_VAR			'd'			// var
#define LEX_POW		    'p'         // Пользовательский тип 1
#define LEX_SQRT        's'         // Пользовательский тип 2
#define	LEX_RETURN		'r'			// Return
#define	LEX_OUTPUT		'o'			// output
#define	LEX_MAIN		'm'			// Main
#define LEX_CONDITION	'c'			// condition
#define LEX_ELSE		'a'			// else
#define	LEX_SEPARATOR	';'			// ;
#define	LEX_COMMA		','			// ,
#define	LEX_LEFTBRACE	'{'			// {
#define	LEX_RIGHTBRACE	'}'			// } 
#define	LEX_LEFTHESIS	'('			// (
#define	LEX_RIGHTTHESIS	')'			// )
#define	LEX_PLUS		'+'			// +
#define	LEX_MINUS		'-'			// -
#define	LEX_STAR		'*'			// *
#define	LEX_DIRSLASH	'/'			// /
#define	LEX_EQUAL		'='			// =
#define LEX_MORE		'>'			// >
#define LEX_LESS		'<'			// <
#define	LEX_OPERATION	'v'			// v
#define LEX_RIGHT		']'			//>>
#define LEX_LEFT		'['			//<<
#define LEX_EQUALS		'&'  //==
#define LEX_NOT_EQUAL	'!'	//!=
#define SPACE			' '
#define LEX_TYPE_BOOL		"bool"
#define	LEX_TYPE_BYTE	    "byte"	
#define	LEX_TYPE_WORD	    "word"	
#define	LEX_TYPE_FUNCTION	"function"	
#define	LEX_TYPE_VARIABLE	"variable"	
#define LEX_TYPE_PARAMETR	"parametr"	
#define LEX_TYPE_LITERAL	"literal"
#define LEX_TYPE_STANDART	"standart"
namespace LT
{
	struct Entry
	{
		char lexema;			// Лексема
		int sn;					// Номер строки в исходном тексте
		int idxTI;				// Индекс в таблице идентификаторов или LT_TI_NULLIDX
		int priority;
		int tokenId = 0;
		char operation;
		/*std::string*/char value;
		Entry() {};
		Entry(char lexema, int snn, int idxti = LT_TI_NULLDX);
		Entry(char lexema, int snn, char v, int idxti = LT_TI_NULLDX);

	};

	struct LexTable						// Экземпляр таблицы лексем
	{
		int maxsize;					// Ёмкость таблицы лексем
		int size;						// Текущий размер таблицы лексем
		Entry* table;					// Массив строк таблицы лексем
	};
	LexTable Create(int size);			// Ёмкость < LT_MAXSIZE
	void Add(LexTable &lextable, Entry entry);	// Экземпляр таблицы лексем, строка таблицы лексем
	Entry GetEntry(LexTable &lextable, int n);	// Экземпляр таблицы лексем, номер получаемой строки
	void Delete(LexTable &lextable);	// Удалить таблицу лексем (освободить память)

	struct LIT {
		std::string name[65];
		std::string literals[65];
		std::string typel[65];
	};
}