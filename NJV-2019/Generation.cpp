#include "pch.h"
#include "Error.h"
#include "Generation.h"
#include "IT.h"

ofstream fout("..\\NJV-2019Gen\\NJV-2019Gen\\Program.cs");
//ofstream fout("file.cs");
void Head()
{
	fout << "using System;\nusing System.Collections.Generic;\nusing System.Linq;\nusing System.Text;\nusing System.Threading.Tasks;\nusing lib;\n " << endl;
	fout << "namespace CS\n{\n\tclass Program\n\t{\n" << endl;
}
void Down()
{
	fout << "\t}\n}";
	fout.close();
}


void Generation(LT::LexTable &Lextable, In::StToken *tokens, IT::IdTable idtable)
{
	Head();
	bool isExptr = false;
	bool isFunc = false;

	for (int i = 0; i < Lextable.size; i++)
	{
		switch (Lextable.table[i].lexema)
		{
		default:
			break;
		case LEX_CONDITION:
		{
			fout << "\t\t\tif";
			break;
		}
		case LEX_ELSE:
		{
			fout << "\t\t\telse";
			break;
		}
		case LEX_MAIN:
			fout << "\t\tstatic void Main(string[] args)\n";
			//tab_count++;
			break;
		case LEX_OPERATION:
		{
			if (Lextable.table[i].operation == LEX_LEFT)
			{
				fout << " << ";
			}
			else if (Lextable.table[i].operation == LEX_RIGHT)
			{
				fout << " >> ";
			}
			else if (Lextable.table[i].operation == LEX_EQUALS)
			{
				fout << " == ";
			}
			else if (Lextable.table[i].operation == LEX_NOT_EQUAL)
			{
				fout << " != ";
			}
			else
			{
				fout << " " << Lextable.table[i].operation << " ";
			}
			break;
		}
		case LEX_EQUAL:
		{
			fout << " " << Lextable.table[i].lexema << " ";
			if (idtable.table[Lextable.table[i - 1].idxTI].iddatatype == IT::INT)
			{
				fout << "(byte)(";
				isExptr = true;
			}
			break;
		}
		case LEX_COMMA:
		case SPACE:
		{
			fout << Lextable.table[i].lexema << " ";
			break;
		}
		case LEX_EQUALS:
		{
			fout << " == ";
			break;
		}
		case LEX_RIGHTTHESIS:
		case LEX_LEFTHESIS:
		{
			fout << Lextable.table[i].lexema;
			break;
		}
		case LEX_LEFTBRACE:
		{
			if (Lextable.table[i - 1].lexema == LEX_MAIN || isFunc)
			{
				fout << "\t\t" << Lextable.table[i].lexema << "\n\t\t\tLib lib = new Lib();" << endl;
				isFunc = false;
			}
			else
			{
				fout << " " << Lextable.table[i].lexema << endl;
			}
			break;
		}
		case LEX_RIGHTBRACE:
		{
			fout << "\t\t\t" << Lextable.table[i].lexema;
			if (Lextable.size - i != 1)
			{
				fout << endl;
			}
			break;
		}
		case LEX_SEPARATOR:
		{
			if (isExptr)
			{
				fout << ')';
				isExptr = false;
			}
			if (Lextable.table[i - 1].lexema != LEX_RIGHTBRACE)
			{
				fout << Lextable.table[i].lexema << endl;
			}
			break;
		}
		case  LEX_VAR:
		{
			break;
		}
		case LEX_BYTE:
			if (Lextable.table[i + 1].lexema != LEX_FUNCTION)
			{
				if (Lextable.table[i - 1].lexema != LEX_LEFTHESIS)
				{
					fout << "\t\t\t";
				}
				fout << "byte ";
			}
			break;
		case LEX_BOOL:
			if (Lextable.table[i + 1].lexema != LEX_FUNCTION)
			{
				if (Lextable.table[i - 1].lexema != LEX_LEFTHESIS)
				{
					fout << "\t\t\t";
				}
				fout << "bool ";
			}
			break;
		case LEX_WORD:
			if (Lextable.table[i + 1].lexema != LEX_FUNCTION)
			{
				if (Lextable.table[i - 1].lexema != LEX_LEFTHESIS)
				{
					fout << "\t\t\t";
				}
				fout << "string ";
			}
			break;
		case LEX_LITERAL:
		case LEX_ID:
		{
			/*if (Lextable.table[i - 1].lexema == LEX_RETURN)
			{
				break;
			}*/
			if (isExptr &&Lextable.table[i].lexema == LEX_ID && idtable.table[Lextable.table[i-2].idxTI].idtype != IT::F)
				fout << "(int)";

			if ((Lextable.table[i - 1].lexema == LEX_SEPARATOR) || (Lextable.table[i - 1].lexema == LEX_RIGHTBRACE) || (Lextable.table[i - 1].lexema == LEX_LEFTBRACE))
			{
				fout << "\t\t\t";
			}
			fout << tokens[i].token;
			if (Lextable.table[i - 1].lexema == LEX_OUTPUT)
			{
				fout << ")";
			}
			break;
		}
		case LEX_OUTPUT:
		{
			fout << "\t\t\tConsole.WriteLine(";
			break;
		}
		case LEX_FUNCTION:
		{
			fout << "\t\tpublic static ";
			switch (Lextable.table[i - 1].lexema)
			{
			case LEX_BYTE:
				fout << "byte ";
				break;
			case LEX_WORD:
				fout << "string ";
				break;
			case LEX_BOOL:
				fout << "bool ";
				break;
			case LEX_RIGHTBRACE:
				fout << "void ";
				break;
			}
			isFunc = true;
			break;
		}
		case LEX_RETURN:
		{
			fout << "\t\t\treturn "; 
			break;
		}
		case LEX_SQRT:
		{
			fout << "lib.sqrt";
			break;
		}
		case LEX_POW:
		{
			fout << "lib.pow";
			break;
		}
		}
	}
	Down();

}