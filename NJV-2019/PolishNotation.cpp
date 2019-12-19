#include "pch.h"
#include "LexicalAnalysis.h"
#include <stack>
#include <queue>

using namespace std;
int prior(char znak)
{
	switch (znak)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	default:
		return 0;
	}
}

LeX::LEX Polish(LeX::LEX tables) 
{
	bool bufferb;
	for (int i = 0; i < tables.Lextable.size; i++) {    //преобразовать в польку где надо
		if (tables.Lextable.table[i].lexema == LEX_EQUAL)
		{
			i++;
			bufferb = PolishNotation(i, tables);
			if (!bufferb)
				std::cout << "Fail polsk";
		}
	}
	return tables;
}

bool PolishNotation(int i, LeX::LEX& lex)
{
	stack<LT::Entry> stack;		// стек дл€ операций
	queue<LT::Entry> queue;		// очередь дл€ операндов
	LT::Entry temp;		temp.idxTI = -1;	temp.lexema = '#';	temp.sn = -1;	// запрещенна€ лексема, все лишние элементы будут замен€тьс€ на нее
	LT::Entry func;		func.idxTI = -1;	func.lexema = '@';	func.sn = -1;	// лексема дл€ вызова функции
	int countLex = 0;			// количество преобразованных лексем
	int countParm = 0;			// количество параметров функции
	int posLex = i;				// запоминаем номер лексемы перед преобразованием
	bool findFunc = false;		// флаг дл€ функции
	bool findComma = false;		// флаг дл€ зап€той (кол-во параметров +1 сразу и +1 при добавлении в очередь лексемы вызова функции)
	char* buf = new char[2];	// буфер дл€ countParm в строковом представлении
	for (int i = 0; i < lex.Lextable.size; i++)// определ€ем приоритет дл€ каждого оператора
	{
		if (lex.Lextable.table[i].lexema == LEX_LEFTHESIS || lex.Lextable.table[i].lexema == LEX_RIGHTTHESIS) //()
			lex.Lextable.table[i].priority = 0;
		if (lex.Lextable.table[i].lexema == LEX_COMMA) //,
			lex.Lextable.table[i].priority = 1;
		if (lex.Lextable.table[i].operation == LEX_PLUS || lex.Lextable.table[i].operation == LEX_MINUS) //+-
			lex.Lextable.table[i].priority = 2;
		if (lex.Lextable.table[i].operation == LEX_STAR || lex.Lextable.table[i].operation == LEX_DIRSLASH) //*/
			lex.Lextable.table[i].priority = 3;
	}
	for (i; lex.Lextable.table[i].lexema != LEX_SEPARATOR; i++, countLex++) //перебор до ;
	{
		switch (lex.Lextable.table[i].lexema)
		{
		case LEX_ID:	// если идентификатор
		{
			if (lex.IDtable.table[lex.Lextable.table[i].idxTI].idtype == IT::F)
				findFunc = true;
			queue.push(lex.Lextable.table[i]);
			continue;
		}
		case LEX_LITERAL:		// если литерал
		{
			queue.push(lex.Lextable.table[i]);	// помещаем в очередь
			continue;
		}
		case LEX_LEFTHESIS:		// если (
		{
			stack.push(lex.Lextable.table[i]); // помещаем ее в стек
			continue;
		}
		case LEX_RIGHTTHESIS:	// если )
		{
			if (findFunc)		// если была найдена функци€, то лексемы () замен€ютс€ на @ и кол-во параметров
			{
				if (findComma)
				{
					countParm++;
				}
				lex.Lextable.table[i] = func;
				queue.push(lex.Lextable.table[i]);		// добавл€ем в очередь лексему вызова функции
				_itoa_s(countParm, buf, 2, 10);			// преобразование числа параметров в строку(если одна зап€та€, то 2 параметра)
				stack.top().lexema = buf[0];
				stack.top().idxTI = -1; stack.top().sn = -1;	// заполн€ем лексему, указывающую количество параметров функции
				queue.push(stack.top());				// добавл€ем в очередь эту лексему
				findFunc = false;
			}
			else {
				while (stack.top().lexema != LEX_LEFTHESIS)	// пока не (
				{
					queue.push(stack.top());	// из стека в очередь
					stack.pop();

					if (stack.empty())
						return false;
				}
			}
			stack.pop();	// уничтожаем ( или лексему, указывающую количество параметров функции
			continue;
		}
		case LEX_OPERATION:	// если оператор
		{
			while (!stack.empty() && lex.Lextable.table[i].priority <= stack.top().priority)	// пока приоритет текущего оператора 
																								//меньше или равен приоритету оператора в вершине стека
			{
				queue.push(stack.top());	// выталкиваем со стека в выходную строку
				stack.pop();
			}
			stack.push(lex.Lextable.table[i]); //если стек пуст, закидываем оператор в стек
			continue;
		}
		case LEX_COMMA:	// если зап€та€
		{
			findComma = true;
			countParm++;
			continue;
		}
		}
	}


	while (!stack.empty())	// если стек не пустой
	{
		if (stack.top().lexema == LEX_LEFTHESIS || stack.top().lexema == LEX_RIGHTTHESIS)
			return false;
		queue.push(stack.top());	// выталкиваем все в очередь
		stack.pop();
	}
	while (countLex != 0)		// замена текущего выражени€ в таблице лексем на выражение в ѕќЋ»«
	{
		if (!queue.empty()) {
			lex.Lextable.table[posLex++] = queue.front();
			queue.pop();
		}
		else
		{
			lex.Lextable.table[posLex++] = temp; //если кол-во замененных лексем меньше, чем первоначальных,недостающие лексемы замен€ютс€ на #
		}
		countLex--;
	}
	for (int i = 0; i < posLex; i++)		// восстановление индексов первого вхождени€ в таблицу лексем у литералов из таблицы идентификаторов
	{
		if (lex.Lextable.table[i].lexema == LEX_LITERAL)
			lex.IDtable.table[lex.Lextable.table[i].idxTI].idxfirstLE = i;
	}
	return true;
}