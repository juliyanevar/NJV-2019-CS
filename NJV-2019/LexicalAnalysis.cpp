#include "pch.h"
#include "LexicalAnalysis.h"
#include "Graphs.h"
#include <sstream>
#include <string.h>
#include <iomanip>
#include <cstring>

namespace LeX
{

	bool flag2 = false;
	bool flag1 = false;
	Graph graph[] =
	{
		{ LEX_BYTE, FST::FST(GRAPH_BYTE) },
		{ LEX_POW, FST::FST(GRAPH_POW) },
		{ LEX_SQRT, FST::FST(GRAPH_SQRT) },
		{ LEX_WORD, FST::FST(GRAPH_WORD) },
		{ LEX_BOOL, FST::FST(GRAPH_BOOL) },
		{ LEX_FUNCTION, FST::FST(GRAPH_FUNCTION) },
		{ LEX_VAR, FST::FST(GRAPH_VAR) },
		{ LEX_RETURN, FST::FST(GRAPH_RETURN) },
		{ LEX_CONDITION, FST::FST(GRAPH_CONDITION) },
		{ LEX_ELSE, FST::FST(GRAPH_ELSE) },
		{ LEX_OUTPUT, FST::FST(GRAPH_OUTPUT) },
		{ LEX_MAIN, FST::FST(GRAPH_MAIN) },
		{ LEX_LITERAL, FST::FST(GRAPH_INT_LITERAL) },
		{ LEX_LITERAL, FST::FST(GRAPH_HEX_LITERAL) },
		{ LEX_LITERAL, FST::FST(GRAPH_STRING_LITERAL) },
	    { LEX_LITERAL, FST::FST(GRAPH_TRUE)},
		{ LEX_LITERAL, FST::FST(GRAPH_FALSE)},
		{ LEX_ID, FST::FST(GRAPH_ID) },
		{ LEX_SEPARATOR, FST::FST(GRAPH_SEPARATOR) },
		{ LEX_COMMA, FST::FST(GRAPH_COMMA) },
		{ LEX_LEFTBRACE, FST::FST(GRAPH_LEFT_CURLY_BRACE) },
		{ LEX_RIGHTBRACE, FST::FST(GRAPH_RIGHT_CURLY_BRACE) },
		{ LEX_LEFTHESIS, FST::FST(GRAPH_OPEN_PARENTHESIS) },
		{ LEX_RIGHTTHESIS, FST::FST(GRAPH_CLOSE_PARENTHESIS) },
		{ LEX_PLUS, FST::FST(GRAPH_PLUS) },
		{ LEX_MINUS, FST::FST(GRAPH_MINUS) },
		{ LEX_STAR, FST::FST(GRAPH_ASTERISK) },
		{ LEX_MORE, FST::FST(GRAPH_MORE) },
		{ LEX_LESS, FST::FST(GRAPH_LESS) },
		{ LEX_RIGHT, FST::FST(GRAPH_RIGHT) },
		{ LEX_LEFT, FST::FST(GRAPH_LEFT) },
		{ LEX_DIRSLASH, FST::FST(GRAPH_FORWARD_SLASH) },
		{ LEX_EQUALS, FST::FST(GRAPH_EQUALS) },
		{ LEX_NOT_EQUAL, FST::FST(GRAPH_NOT_EQUAL) },
		{ LEX_EQUAL, FST::FST(GRAPH_EQUAL) }
	};
	LEX INITLEX(In::IN InStruct, Log::LOG &log)
	{
		LEX Tables;
		Tables.Lextable = LT::Create(InStruct.TokenCount);
		Tables.IDtable = IT::Create(65536);
		int maincount = NULL;
		int countpow = NULL;
		bool isVar, isParam, isMainFunc, isExecuted, isLiteral, isIf, isElse, isFunc;
		isVar = isParam = isMainFunc = isExecuted = isLiteral = isIf = isElse = isFunc = false;
		IT::IDDATATYPE funcType = IT::INT;
		IT::IDDATATYPE returnType = IT::INT;
		IT::IDDATATYPE idType = IT::INT;   // тип идентификатора
		char tempTokenFunction[ID_MAXSIZE] = "";
		char tempToken[ID_MAXSIZE] = "";
		char buffer[255] = "";
		char tempTokenFunc[255] = ""; //буфер для имени функции
		for (int i = 0; i < InStruct.TokenCount; i++)
		{
			for (int j = 0; j < LENGTH(graph); j++)
			{
				FST::FST fstex(InStruct.tokens[i].token, graph[j].graph);
				if (FST::execute(fstex))
				{
					isExecuted = true;
					switch (graph[j].Lexema)
					{
					case LEX_CONDITION:
					{
						isIf = true;
						LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line);
						LT::Add(Tables.Lextable, entrylt);
						break;
					}
					case LEX_ELSE:
					{
						isElse = true;
						LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line);
						LT::Add(Tables.Lextable, entrylt);
						break;
					}
					case LEX_POW:
					{
						IT::Entry entryit("pow", i, IT::INT, IT::F); // создаём элемент ТИ с занесением всех собранных данных
						IT::Add(Tables.IDtable, entryit);						 // добавляем созданный элемент
						LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line, IT::IsId(Tables.IDtable, InStruct.tokens[i].token)); // создание
																																		 // элемента таблицы лексем
						LT::Add(Tables.Lextable, entrylt); //занесение в таблицу лексем
						Tables.IDtable.table[Tables.Lextable.table[i].idxTI].count_parm = 1;
						Tables.IDtable.table[Tables.Lextable.table[i].idxTI].parms[0] = 'n';
						//Tables.IDtable.table[Tables.Lextable.table[i].idxTI].parms[1] = 'n';
						break;
						/*if (IT::IsId(Tables.IDtable, InStruct.tokens[i].token) == -1)
						{
							if (Tables.Lextable.table[i - 1].lexema == LEX_BYTE)
							{
								IT::Entry entryit(InStruct.tokens[i].token, i, funcType = IT::INT, IT::S);
								IT::Add(Tables.IDtable, entryit);
							}
						}*/
					}
					case LEX_SQRT:
					{
						IT::Entry entryit("sqrt", i, IT::INT, IT::F); // создаём элемент ТИ с занесением всех собранных данных
						IT::Add(Tables.IDtable, entryit);						 // добавляем созданный элемент
						LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line, IT::IsId(Tables.IDtable, InStruct.tokens[i].token)); // создание
																																		 // элемента таблицы лексем
						LT::Add(Tables.Lextable, entrylt); //занесение в таблицу лексем
						Tables.IDtable.table[Tables.Lextable.table[i].idxTI].count_parm = 1;
						Tables.IDtable.table[Tables.Lextable.table[i].idxTI].parms[0] = 'n';
						break;
					
						/*if (IT::IsId(Tables.IDtable, InStruct.tokens[i].token) == -1)
						{
							if (Tables.Lextable.table[i - 1].lexema == LEX_FUNCTION)
							{
								if (!strcmp(InStruct.tokens[i - 2].token, LEX_TYPE_WORD))
								{
									IT::Entry entryit(InStruct.tokens[i].token, i, funcType = IT::STR, IT::S);
									IT::Add(Tables.IDtable, entryit);
								}
								LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line, Tables.IDtable.size - 1);
								entrylt.tokenId = i;
								LT::Add(Tables.Lextable, entrylt);
								isParam = true;
								break;
							}
						}*/
					}
					case LEX_ID:
					{
						if (Tables.Lextable.table[i - 1].lexema != LEX_FUNCTION && IT::IsId(Tables.IDtable, InStruct.tokens[i].token) == -1 && !isMainFunc )
						{
							strncpy(buffer, tempTokenFunc, ID_MAXSIZE - 1);
							strcat_s(buffer, InStruct.tokens[i].token);
							strncpy(InStruct.tokens[i].token, buffer, ID_MAXSIZE - 1);
						}
						if (isMainFunc)
						{
							strncpy(buffer, "", ID_MAXSIZE - 1);
							strcat_s(buffer, InStruct.tokens[i].token);
							strncpy(InStruct.tokens[i].token, buffer, ID_MAXSIZE - 1);
						}

						strncpy_s(tempToken, InStruct.tokens[i].token, ID_MAXSIZE - 1); // копирование имени идентифкатора
						strncpy_s(InStruct.tokens[i].token, InStruct.tokens[i].token, ID_MAXSIZE - 1); //копирование имени
						if (IT::IsId(Tables.IDtable, InStruct.tokens[i].token) == -1) // если данный идентификатор не найден повторно 
						{
							if (Tables.Lextable.table[i - 1].lexema == LEX_FUNCTION && !isMainFunc) // если предыдущей лексемой была лексема функциии
							{
									strncpy_s(tempTokenFunction, tempToken, ID_MAXSIZE - 1); // копируем обозначение принадлежности к имени идентификатора
									strncpy_s(tempTokenFunc, tempToken, ID_MAXSIZE - 1);
																				
									funcType = idType;     // указываем тип идентификатора
									if (Tables.Lextable.table[i - 2].lexema == LEX_BYTE) idType = IT::INT;
									if (Tables.Lextable.table[i - 2].lexema == LEX_WORD) idType = IT::STR;
									if (Tables.Lextable.table[i - 2].lexema == LEX_BOOL) idType = IT::BOOL;
									IT::Entry entryit(tempTokenFunction, i, idType, IT::F); // создаём элемент ТИ с занесением всех собранных данных
									IT::Add(Tables.IDtable, entryit); // добавляем созданный элемент
									LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line, IT::IsId(Tables.IDtable, InStruct.tokens[i].token)); // создание
																																					 // элемента таблицы лексем
									LT::Add(Tables.Lextable, entrylt); //занесение в таблицу лексем
									isParam = true; // наличие параметров
									if (InStruct.tokens[i + 2].token[0] == LEX_RIGHTTHESIS) // если лексема через одну лексема )
										isParam = false; // параметры закончились
									isFunc = true;
								
								
								break;

							}
							else if (Tables.Lextable.table[i - 1].lexema == LEX_BYTE) //если предыдущая лесема была лексемой целого типа данных 
							{
								
								if (Tables.Lextable.table[i - 2].lexema == LEX_VAR)
								{
									if (Tables.Lextable.table[i - 2].lexema == LEX_SEPARATORS)
									{
										std::cout << Tables.Lextable.table[i - 2].lexema << std::endl;
										throw ERROR_THROW_IN(404, InStruct.tokens[i].line, NULL); // если не сработал иф ошибка о том что
										flag1 = true;																		  //  небыло предварительного определения
									}
								}
								if (isParam == false) // если идентификатор типа переменная не является параметром
								{
									idType = IT::INT;
									IT::Entry entryit(InStruct.tokens[i].token, i, idType, IT::V); // создаём элемент табл инд
									IT::Add(Tables.IDtable, entryit); //заносим в табл инд
								}
								else if (isParam == true) // иначе если параметр
								{
									int qwe = i;
									while (Tables.IDtable.table[qwe].idtype != IT::F)
										qwe--;
									Tables.IDtable.table[qwe].parms[count_p] = 't';
									count_p++;
									if (count_p == INT_MAXSIZE_PARM)
									{
										throw ERROR_THROW_IN(408, InStruct.tokens[i].line, NULL);
										flag1 = true;
									}
									IT::Entry entryit(InStruct.tokens[i].token, i, idType, IT::P);// создаём элемент табл инд
									IT::Add(Tables.IDtable, entryit);//заносим в табл инд
		//
									if (InStruct.tokens[i + 1].token[0] == LEX_RIGHTTHESIS) // если следующая лексема лексема )
									{
										isParam = false; // параметры закончились
										int qwe = i;
										while (Tables.IDtable.table[qwe].idtype != IT::F)
											qwe--;
										Tables.IDtable.table[qwe].count_parm = count_p;
										count_p = 0;
									}
								}

								LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line, IT::IsId(Tables.IDtable, InStruct.tokens[i].token)); // создание элемента табл лекс
								LT::Add(Tables.Lextable, entrylt); // добавление в табл лекс
								break;
							}
							else if (Tables.Lextable.table[i - 1].lexema == LEX_WORD) //если предыдущая лесема была лексемой стокового типа данных
							{
								if (isParam == false) // если идентификатор типа переменная не является параметром
								{
									idType = IT::STR;
									IT::Entry entryit(InStruct.tokens[i].token, i, idType, IT::V); // создаём элемент табл инд
									IT::Add(Tables.IDtable, entryit); //заносим в табл инд
								}
								else if (isParam) // иначе если параметр
								{
									int qwe = i;
									while (Tables.IDtable.table[qwe].idtype != IT::F)
										qwe--;
									Tables.IDtable.table[qwe].parms[count_p] = 'w';
									count_p++;
									if (count_p == INT_MAXSIZE_PARM)
									{
										throw ERROR_THROW_IN(407, InStruct.tokens[i].line, NULL);
										flag1 = true;
									}
									IT::Entry entryit(InStruct.tokens[i].token, i, idType, IT::P);// создаём элемент табл инд
									IT::Add(Tables.IDtable, entryit);//заносим в табл инд
			//
									if (InStruct.tokens[i + 1].token[0] == LEX_RIGHTTHESIS) // если следующая лексема лексема )
									{
										isParam = false; // параметры закончились
										int qwe = i;
										while (Tables.IDtable.table[qwe].idtype != IT::F)
											qwe--;
										Tables.IDtable.table[qwe].count_parm = count_p;
										count_p = 0;
									}
								}

								LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line, IT::IsId(Tables.IDtable, InStruct.tokens[i].token)); // создание элемента табл лекс
								LT::Add(Tables.Lextable, entrylt); // добавление в табл лекс
								break;
							}
							else if (Tables.Lextable.table[i - 1].lexema == LEX_BOOL) //если предыдущая лесема была лексемой булевого типа данных
							{
							if (isParam == false) // если идентификатор типа переменная не является параметром
							{
								idType = IT::BOOL;
								IT::Entry entryit(InStruct.tokens[i].token, i, idType, IT::V); // создаём элемент табл инд
								IT::Add(Tables.IDtable, entryit); //заносим в табл инд
							}
							else if (isParam) // иначе если параметр
							{
								int qwe = i;
								while (Tables.IDtable.table[qwe].idtype != IT::F)
									qwe--;
								Tables.IDtable.table[qwe].parms[count_p] = 'b';
								count_p++;
								if (count_p == INT_MAXSIZE_PARM)
								{
									throw ERROR_THROW_IN(407, InStruct.tokens[i].line, NULL);
									flag1 = true;
								}
								IT::Entry entryit(InStruct.tokens[i].token, i, idType, IT::P);// создаём элемент табл инд
								IT::Add(Tables.IDtable, entryit);//заносим в табл инд
		//
								if (InStruct.tokens[i + 1].token[0] == LEX_RIGHTTHESIS) // если следующая лексема лексема )
								{
									isParam = false; // параметры закончились
									int qwe = i;
									while (Tables.IDtable.table[qwe].idtype != IT::F)
										qwe--;
									Tables.IDtable.table[qwe].count_parm = count_p;
									count_p = 0;
								}
							}

							LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line, IT::IsId(Tables.IDtable, InStruct.tokens[i].token)); // создание элемента табл лекс
							LT::Add(Tables.Lextable, entrylt); // добавление в табл лекс
							break;
							}
							throw ERROR_THROW_IN(404, InStruct.tokens[i].line, NULL); // если не сработал иф ошибка о том что
							flag1 = true;																		  //  небыло предварительного определения
						}
						// далее проверка на переопределение	
						else // в противном случае 
						{
							if (Tables.Lextable.table[i - 1].lexema == LEX_BYTE || Tables.Lextable.table[i - 1].lexema == LEX_WORD || Tables.Lextable.table[i - 1].lexema == LEX_BOOL || Tables.Lextable.table[i - 1].lexema == LEX_FUNCTION) // если предыдущим
																																		   //был тип данных или лексема функции
							{
								throw ERROR_THROW_IN(403, InStruct.tokens[i].line, NULL); //выдаём ошибку о попытке переопределения
								flag1 = true;
							}
							LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line, IT::IsId(Tables.IDtable, InStruct.tokens[i].token)); //создание элемента табл лексем
							LT::Add(Tables.Lextable, entrylt); // занесение элемента в таблицу лексем
							break;
						}
						break;
					}
					case LEX_LITERAL:
					{
						
						isLiteral = true;
						break;
					}
					case LEX_DIRSLASH:					
					case LEX_PLUS:
					case LEX_STAR:					
					case LEX_MINUS:
					case LEX_RIGHT:
					case LEX_LEFT:
					case LEX_MORE:
					case LEX_LESS:
					case LEX_EQUALS:
					case LEX_NOT_EQUAL:
					{
						
						LT::Entry entrylt(LEX_OPERATION, InStruct.tokens[i].line, InStruct.tokens[i].token[0]);
						LT::Add(Tables.Lextable, entrylt);
						break;

					}
					case LEX_SEPARATOR:
					{
						InStruct.tokens[i].isLiteral = false;
						LT::Entry entrylt(InStruct.tokens[i].token[0], InStruct.tokens[i].line);
						LT::Add(Tables.Lextable, entrylt);
						break;
					}
					case LEX_MAIN:
					{
						maincount++;

						if (maincount > 1)
						{
							throw ERROR_THROW_IN(401, InStruct.tokens[i].line, NULL);
						}
						isMainFunc = true;
						funcType = IT::INT;
						LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line);
						LT::Add(Tables.Lextable, entrylt);
						break;
					}
					case LEX_VAR:
					{
						isVar = true;
						LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line);
						LT::Add(Tables.Lextable, entrylt);
						break;
					}
					case LEX_OUTPUT:
					{
						LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line);
						LT::Add(Tables.Lextable, entrylt);
						break;
					}
					default:
					{
						LT::Entry entrylt(graph[j].Lexema, InStruct.tokens[i].line);
						LT::Add(Tables.Lextable, entrylt);
						break;
					}
					}
					break;
				}
			}
			if (!isExecuted || isLiteral)
			{
				if (InStruct.tokens[i].isLiteral || isLiteral)
				{
					switch (Tables.Lextable.table[i - 1].lexema)
					{
					case LEX_EQUAL:
					{
						InStruct.tokens[i].isLiteral = true;
						LT::Entry entrylt(LEX_LITERAL, InStruct.tokens[i].line, Tables.IDtable.size);
						LT::Add(Tables.Lextable, entrylt);
						if (IT::IsId(Tables.IDtable, InStruct.tokens[i - 2].token) != -1)
						
							if ((Tables.IDtable.table[IT::IsId(Tables.IDtable, InStruct.tokens[i - 2].token)].idtype == IT::V ||
								Tables.IDtable.table[IT::IsId(Tables.IDtable, InStruct.tokens[i - 2].token)].idtype == IT::P))
								if (Tables.Lextable.table[i - 4].lexema == LEX_VAR)
								{
									IT::SetValue(Tables.IDtable, IT::IsId(Tables.IDtable, InStruct.tokens[i - 2].token), InStruct.tokens[i].token);
								}
						if (Tables.IDtable.table[IT::IsId(Tables.IDtable, InStruct.tokens[i - 2].token)].idtype == IT::V ||    //если перед = была переменная или параметр
							Tables.IDtable.table[IT::IsId(Tables.IDtable, InStruct.tokens[i - 2].token)].idtype == IT::P)
						{
							IT::SetValue(Tables.IDtable, IT::IsId(Tables.IDtable, InStruct.tokens[i - 2].token), InStruct.tokens[i].token); // устанавливаем им их значение в поле табл идентификаторов
						}
						break;
					}

					case LEX_OUTPUT:
					{
						LT::Entry entrylt(LEX_LITERAL, InStruct.tokens[i].line, Tables.IDtable.size - 1);
						entrylt.tokenId = i;
						LT::Add(Tables.Lextable, entrylt);
						break;
					}
					case LEX_RETURN:
					{
						LT::Entry entrylt(LEX_LITERAL, InStruct.tokens[i].line, Tables.IDtable.size - 1);
						entrylt.tokenId = i;
						LT::Add(Tables.Lextable, entrylt);
						break;
					}
					case LEX_WORD: // лексема типа данных
					case LEX_BYTE: // лексема типа данных
					case LEX_BOOL: // лексема типа данных
					{
						idType = graph[i].graph.type; // заполнение поля типа данных
					}
					default:
						LT::Entry entrylt(LEX_LITERAL, InStruct.tokens[i].line, Tables.IDtable.size);
						entrylt.tokenId = i;
						LT::Add(Tables.Lextable, entrylt);
						break;
					}
				}
				else
					throw ERROR_THROW_IN(202, Tables.Lextable.table[i - 2].sn, NULL);
			}
			isExecuted = false;
			isLiteral = false;
		}

		////Семантический анализ
		if (maincount == 0)
		{
			throw ERROR_THROW(402);
		}

		int count_parm1 = 0;
		int count_parm2 = 0;
		
		
		for (int i = 0; i < Tables.Lextable.size; i++)
		{
			if (Tables.Lextable.table[i].lexema == LEX_POW || Tables.Lextable.table[i].lexema == LEX_POW)
			{
				i++;
				while (Tables.Lextable.table[i].lexema != LEX_RIGHTTHESIS)
				{
					if (Tables.Lextable.table[i].lexema == LEX_ID)
					{
						if (Tables.IDtable.table[Tables.Lextable.table[i].idxTI].iddatatype != IT::INT)
							throw ERROR_THROW_IN(409, Tables.Lextable.table[i].sn, NULL);
					}
					i++;
				}
			}
			
			if (Tables.Lextable.table[i].lexema == LEX_EQUAL)
			{
				if (Tables.Lextable.table[i - 1].lexema == LEX_ID && Tables.Lextable.table[i + 2].lexema == LEX_SEPARATOR) {
					if (Tables.IDtable.table[Tables.Lextable.table[i - 1].idxTI].iddatatype == IT::INT || Tables.IDtable.table[Tables.Lextable.table[i - 1].idxTI].iddatatype == IT::BOOL) {
						if (InStruct.tokens[i + 1].token[0] == (char)34) {
							throw ERROR_THROW_IN(413, InStruct.tokens[i].line, NULL); //Ошибка инициализации
						}
					}
					if (Tables.IDtable.table[Tables.Lextable.table[i - 1].idxTI].iddatatype == IT::STR) {
						if (InStruct.tokens[i + 1].token[0] != (char)34) {
							throw ERROR_THROW_IN(413, InStruct.tokens[i].line, NULL); //Ошибка инициализации
						}
					}
				}
			}
			if (Tables.Lextable.table[i].lexema == LEX_POW)
			{
				i++;
				while (Tables.Lextable.table[i].lexema != LEX_RIGHTTHESIS)
				{
					if (Tables.Lextable.table[i].lexema == LEX_ID || Tables.Lextable.table[i].lexema == LEX_LITERAL)
					{
						count_parm1++;
					}
					i++;
				}
				if(count_parm1!=2)
					throw ERROR_THROW_IN(419, Tables.Lextable.table[i].sn, NULL);
			}
			if (Tables.Lextable.table[i].lexema == LEX_SQRT)
			{
				i++;
				while (Tables.Lextable.table[i].lexema != LEX_RIGHTTHESIS)
				{
					if (Tables.Lextable.table[i].lexema == LEX_ID || Tables.Lextable.table[i].lexema == LEX_LITERAL)
					{
						count_parm2++;
					}
					i++;
				}
				if (count_parm2 != 1)
					throw ERROR_THROW_IN(418, Tables.Lextable.table[i].sn, NULL);
			}
			if (Tables.Lextable.table[i].lexema == LEX_EQUAL && Tables.Lextable.table[i-1].lexema == LEX_ID && Tables.Lextable.table[i+1].lexema == LEX_ID)
			{
				if(Tables.IDtable.table[Tables.Lextable.table[i - 1].idxTI].iddatatype != Tables.IDtable.table[Tables.Lextable.table[i + 1].idxTI].iddatatype)
					throw ERROR_THROW_IN(415, Tables.Lextable.table[i].sn, NULL);
			}
			if (Tables.Lextable.table[i].lexema == LEX_FUNCTION)
			{
				switch (Tables.Lextable.table[i - 1].lexema)
				{
				case LEX_BYTE:
				{
					funcType = IT::INT;
					break;
				}
				case LEX_WORD:
				{
					funcType = IT::STR;
					break;
				}
				case LEX_BOOL:
				{
					funcType = IT::BOOL;
					break;
				}
				default:
					break;
				}
				while (Tables.Lextable.table[i].lexema != LEX_RIGHTBRACE)
				{
					if(Tables.Lextable.table[i].lexema == LEX_RETURN)
						switch (Tables.IDtable.table[Tables.Lextable.table[i + 1].idxTI].iddatatype)
						{
						case 1:
						{
							returnType = IT::INT;
							break;
						}
						case 2:
						{
							returnType = IT::STR;
							break;
						}
						case 3:
						{
							returnType = IT::BOOL;
							break;
						}
						default:
							break;
						}
					i++;
				}
				if(funcType!=returnType)
					throw ERROR_THROW_IN(406, Tables.Lextable.table[i - 2].sn, NULL);
			}
			if (Tables.Lextable.table[i].lexema == LEX_CONDITION)
			{
				if (Tables.IDtable.table[Tables.Lextable.table[i + 2].idxTI].iddatatype == IT::STR)
					throw ERROR_THROW_IN(414, Tables.Lextable.table[i - 2].sn, NULL);
				if (Tables.IDtable.table[Tables.Lextable.table[i + 2].idxTI].iddatatype == IT::BOOL)
					if (Tables.Lextable.table[i + 3].lexema == LEX_OPERATION)
						throw ERROR_THROW_IN(416, Tables.Lextable.table[i - 2].sn, NULL);
			}
			if (Tables.Lextable.table[i].lexema == LEX_POW)
			{
				if (Tables.IDtable.table[Tables.Lextable.table[i - 2].idxTI].iddatatype != IT::INT)
					throw ERROR_THROW_IN(420, Tables.Lextable.table[i - 2].sn, NULL);
			}
			if (Tables.Lextable.table[i].lexema == LEX_SQRT)
			{
				if (Tables.IDtable.table[Tables.Lextable.table[i - 2].idxTI].iddatatype != IT::INT)
					throw ERROR_THROW_IN(421, Tables.Lextable.table[i - 2].sn, NULL);
			}
			if (maincount == 1 && Tables.Lextable.table[i].lexema == LEX_FUNCTION)
			{
				throw ERROR_THROW_IN(118, InStruct.tokens[i + 1].line, NULL);
			}
			if (Tables.Lextable.table[i].lexema == LEX_SEPARATORS && Tables.Lextable.table[i - 1].lexema == LEX_SEPARATORS)
			{
				flag2 = true;
				throw ERROR_THROW_IN(308, InStruct.tokens[i + 1].line, NULL);
			}
			else if (Tables.Lextable.table[i - 1].lexema == LEX_SEPARATORS && Tables.Lextable.table[i - 2].lexema == LEX_SEPARATORS)
			{
				flag2 = true;
				throw ERROR_THROW_IN(308, InStruct.tokens[i + 1].line, NULL);
			}
			else if (Tables.Lextable.table[i - 2].lexema == LEX_SEPARATORS && Tables.Lextable.table[i - 3].lexema == LEX_SEPARATORS)
			{
				flag2 = true;
				throw ERROR_THROW_IN(308, InStruct.tokens[i + 1].line, NULL);
			}
			else if (Tables.Lextable.table[i - 2].lexema == LEX_EQUAL && Tables.Lextable.table[i - 3].lexema == LEX_EQUAL)
			{
				flag2 = true;
				throw ERROR_THROW_IN(308, InStruct.tokens[i + 1].line, NULL);
			}
		}

		if (flag1 == false && flag2 == false)
		{
			for (int i = 0; i < Tables.Lextable.size; i++) // проверка выражний и не стандратных функций
			{
				if (Tables.Lextable.table[i].lexema == LEX_EQUAL && Tables.Lextable.table[i - 1].lexema == LEX_EQUAL)
					flag2 = true;
				if (Tables.Lextable.table[i].lexema == LEX_EQUAL && Tables.Lextable.table[i - 1].lexema == LEX_ID && Tables.Lextable.table[i + 1].lexema != LEX_LEFTHESIS) // если мы словили равно, а до равно стоит идентификатор
				{
					if (Tables.IDtable.table[Tables.Lextable.table[i - 1].idxTI].iddatatype == IT::STR) // и этот идентификатор строкового типа 
					{
						if (Tables.Lextable.table[i + 2].lexema != LEX_SEPARATOR && Tables.IDtable.table[Tables.Lextable.table[i + 1].idxTI].idtype != IT::F) // или же функция
							throw ERROR_THROW_IN(417, InStruct.tokens[i + 2].line, NULL);
					}
				}
			}
			bool flag = false; int some_count = 0; char some_buffer[INT_MAXSIZE_PARM];
			for (int i = 0; i < Tables.Lextable.size; i++)
			{

				if (Tables.Lextable.table[i].lexema == LEX_FUNCTION && flag == false && flag2 == false)
				{

					int j = i, funct = i;
					while (Tables.Lextable.table[j].lexema != LEX_RIGHTTHESIS)
						j++;
					int count = 0;
					for (int p = i; p != j; p++)
					{
						if (Tables.Lextable.table[p].lexema == LEX_BYTE)
						{
							Tables.IDtable.table[Tables.Lextable.table[funct + 1].idxTI].parms[count] = 'n';
							count++;
						}
						if (Tables.Lextable.table[p].lexema == LEX_WORD)
						{
							Tables.IDtable.table[Tables.Lextable.table[funct + 1].idxTI].parms[count] = 'w';
							count++;
						}
					}
				}
				if (Tables.Lextable.table[i].lexema == LEX_MAIN)
					flag = true;

				if (flag == true)
				{
					if (Tables.Lextable.table[i].lexema == LEX_ID || Tables.Lextable.table[i].lexema == LEX_LITERAL)
					{
						if (Tables.IDtable.table[Tables.Lextable.table[i].idxTI].idtype == IT::F)
						{
							int param = 0;

							if (Tables.Lextable.table[i + 1].lexema == LEX_LEFTHESIS)
							{
								int k = i + 1;
								while (Tables.Lextable.table[k].lexema != LEX_RIGHTTHESIS)
								{
									if (Tables.Lextable.table[k].lexema == LEX_ID || Tables.Lextable.table[k].lexema == LEX_LITERAL)
									{
										if (Tables.IDtable.table[Tables.Lextable.table[k].idxTI].iddatatype == IT::STR)
											some_buffer[some_count] = 'w';
										if (Tables.IDtable.table[Tables.Lextable.table[k].idxTI].iddatatype == IT::INT)
											some_buffer[some_count] = 'n';
										some_count++;
									}
									k++;
								}
								if (Tables.IDtable.table[Tables.Lextable.table[i].idxTI].count_parm < 0)
									Tables.IDtable.table[Tables.Lextable.table[i].idxTI].count_parm = 0;
								if (some_count != Tables.IDtable.table[Tables.Lextable.table[i].idxTI].count_parm)
								{
									throw ERROR_THROW_IN(405, InStruct.tokens[i + 1].line, NULL);
								}
								for (int r = 0; r < some_count; r++)
									if (some_buffer[r] != Tables.IDtable.table[Tables.Lextable.table[i].idxTI].parms[r])
									{
										throw ERROR_THROW_IN(412, InStruct.tokens[i + 1].line, NULL);
									}
								some_count = 0;
							}
						}
					}
				}
			}
		}
	
		std::ofstream filetrace;
		filetrace.open("trace.txt");
		MFST_TRACE_START
			MFST::Mfst mfst(Tables, GRB::getGreibach());
		if (!mfst.start(filetrace))
			throw ERROR_THROW(307);
		filetrace << "\n\n";
		mfst.savededucation();
		mfst.printrules(log);
		filetrace.close();

			return Tables;
		}
	}
