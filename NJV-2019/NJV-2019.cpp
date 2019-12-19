#include "pch.h"
#include <iostream>
#include <locale>
#include "MFST.h"


int _tmain(int argc, _TCHAR ** argv)
{
	setlocale(LC_CTYPE, "Russian");
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);// Создание log		
		Log::LOG out = Log::INITLOG;// Инициализация log файла	
		out = Log::getlog(parm.out);// Создание out файла		
		Log::writeLog(log);// Запись протокола			
		Log::writeParm(log, parm);// Запись параметров		
		In::IN in = In::getin(parm.in, parm.out);// Получение входящих параметров
		Log::writeIn(log, in);// Запись входящих параметров	
		LeX::LEX tables = LeX::INITLEX(in, log);// Получение таблицы лексем	                //запуск лексического анализатора
		Generation(tables.Lextable, in.tokens,tables.IDtable);
		tables = Polish(tables);
		Log::writeLexicalTable(log, tables.Lextable);
		Log::writeAllTokens(log, in);// Запись 			
		Log::writeIDtable(log, tables.IDtable);// Запись таблицы индент.
		Log::writeLiterals(log, in);// Запись таблицы литералов
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::writeError(log, e);
	}
	
	return 0;
	
}