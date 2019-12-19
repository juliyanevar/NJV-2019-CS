#pragma once
#include "Greibach.h"
#define GRB_ERROR_SERIES 301
#define NS(n)	GRB::Rule::Chain::N(n)
#define TS(n)	GRB::Rule::Chain::T(n)
#define ISNS(n)	GRB::Rule::Chain::isN(n)

namespace GRB
{
	Greibach greibach(
		NS('S'), TS('$'),                     // стартовый символ, дно стека
		6,									  // количество правил
		Rule(
			NS('S'), GRB_ERROR_SERIES + 0,    // неверная структура программы
			20,                                //S→|nfi(F){NrE;};S| m{N};|m{N};S
			Rule::Chain(5, TS('m'), TS('{'), NS('N'),  TS('}'), TS(';')),
			Rule::Chain(6, TS('m'), TS('{'), NS('N'),  TS('}'), TS(';'), NS('S')),
			Rule::Chain(13, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(14, TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(13, TS('w'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(14, TS('w'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(13, TS('b'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(14, TS('b'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(12, TS('t'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(13, TS('t'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(12, TS('w'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(13, TS('w'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(12, TS('b'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(13, TS('b'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('N'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(11, TS('t'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(12, TS('t'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(11, TS('w'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(12, TS('w'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(11, TS('b'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';')),
			Rule::Chain(12, TS('b'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), TS('r'), NS('E'), TS(';'), TS('}'), TS(';'), NS('S'))
		),
		Rule(
			NS('N'), GRB_ERROR_SERIES + 1,    // ошибочный оператор
			34,                               // 
			Rule::Chain(4, TS('d'), TS('t'), TS('i'), TS(';')),
			Rule::Chain(5, TS('d'), TS('t'), TS('i'), TS(';'), NS('N')),
			Rule::Chain(4, TS('d'), TS('w'), TS('i'), TS(';')),
			Rule::Chain(5, TS('d'), TS('w'), TS('i'), TS(';'), NS('N')),
			Rule::Chain(4, TS('d'), TS('b'), TS('i'), TS(';')),
			Rule::Chain(5, TS('d'), TS('b'), TS('i'), TS(';'), NS('N')),
			Rule::Chain(6, TS('d'), TS('t'), TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(7, TS('d'), TS('t'), TS('i'), TS('='), NS('E'), TS(';'), NS('N')),
			Rule::Chain(6, TS('d'), TS('w'), TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(7, TS('d'), TS('w'), TS('i'), TS('='), NS('E'), TS(';'), NS('N')),
			Rule::Chain(6, TS('d'), TS('b'), TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(7, TS('d'), TS('b'), TS('i'), TS('='), NS('E'), TS(';'), NS('N')),
			Rule::Chain(3, TS('r'), NS('E'), TS(';')),
			Rule::Chain(4, TS('r'), NS('E'), TS(';'), NS('N')),
			Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('N')),
			Rule::Chain(8, TS('d'), TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS(';')),
			Rule::Chain(9, TS('d'), TS('t'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS(';'), NS('N')),
			Rule::Chain(8, TS('d'), TS('w'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS(';')),
			Rule::Chain(9, TS('d'), TS('w'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS(';'), NS('N')),
			Rule::Chain(8, TS('d'), TS('b'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS(';')),
			Rule::Chain(9, TS('d'), TS('b'), TS('f'), TS('i'), TS('('), NS('F'), TS(')'), TS(';'), NS('N')),
			Rule::Chain(3, TS('o'), TS('i'), TS(';')),
			Rule::Chain(3, TS('o'), TS('l'), TS(';')),
			Rule::Chain(3, TS('o'), NS('E'), TS(';')),
			Rule::Chain(4, TS('o'), TS('i'), TS(';'), NS('N')),
			Rule::Chain(4, TS('o'), TS('l'), TS(';'), NS('N')),
			Rule::Chain(4, TS('o'), NS('E'), TS(';'), NS('N')),

			Rule::Chain(12, TS('c'), TS('('), NS('E'), TS(')'), TS('{'), NS('N'), TS('}'), TS('a'), TS('{'), NS('N'), TS('}'), NS('N')),
			Rule::Chain(11, TS('c'), TS('('), NS('E'), TS(')'), TS('{'), NS('N'), TS('}'), TS('a'), TS('{'), NS('N'), TS('}')),
			Rule::Chain(7, TS('c'), TS('('), NS('E'), TS(')'), TS('{'), NS('N'), TS('}')),
			Rule::Chain(8, TS('c'), TS('('), NS('E'), TS(')'), TS('{'), NS('N'), TS('}'), NS('N')),
			Rule::Chain(6, TS('c'), TS('('), NS('E'), TS(')'),  NS('N'), TS(';')),
			Rule::Chain(7, TS('c'), TS('('), NS('E'), TS(')'),  NS('N'), TS(';'), NS('N'))
		),
		Rule(
			NS('E'), GRB_ERROR_SERIES + 2,    // ошибка в выражении
			13,                                // 
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('('), NS('E'), TS(')')),
			Rule::Chain(3, TS('i'), TS('('), TS(')')),
			Rule::Chain(4, TS('i'), TS('('), NS('W'), TS(')')),			
			Rule::Chain(2, TS('i'), NS('M')),
			Rule::Chain(2, TS('l'), NS('M')),
			Rule::Chain(4, TS('('), NS('E'), TS(')'), NS('M')),
			Rule::Chain(5, TS('i'), TS('('), NS('W'), TS(')'), NS('M')),
			Rule::Chain(4, TS('p'), TS('('), NS('W'), TS(')')),
			Rule::Chain(5, TS('p'), TS('('), NS('W'), TS(')'), NS('M')),
			Rule::Chain(4, TS('s'), TS('('), NS('W'), TS(')')),
			Rule::Chain(5, TS('s'), TS('('), NS('W'), TS(')'), NS('M'))
		),
		Rule(
			NS('F'), GRB_ERROR_SERIES + 3,    // ошибка в параметрах функции
			6,                                // 
			Rule::Chain(2, TS('t'), TS('i')),
			Rule::Chain(4, TS('t'), TS('i'), TS(','), NS('F')),
			Rule::Chain(2, TS('w'), TS('i')),
			Rule::Chain(4, TS('w'), TS('i'), TS(','), NS('F')),
			Rule::Chain(2, TS('b'), TS('i')),
			Rule::Chain(4, TS('b'), TS('i'), TS(','), NS('F'))
		),
		Rule(
			NS('W'), GRB_ERROR_SERIES + 4,    // ошибка в параметрах вызываемой функции 
			4,                                // 
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('i'), TS(','), NS('W')),
			Rule::Chain(3, TS('l'), TS(','), NS('W'))
		),
		Rule(
			NS('M'), GRB_ERROR_SERIES + 5,    // оператор
			2,								  //
			Rule::Chain(2, TS('v'), NS('E')),
			Rule::Chain(3, TS('v'), NS('E'), NS('M'))
		)
	);
}