#pragma once
#define ID_MAXSIZE		8			//���� ����� �������� ��������������
#define TI_MAXSIZE		4096		//���� ����� ���������� ����� � ������� ���������������
#define TI_INT_DEFAULT	0		//�������� �� ��������� ��� int
#define TI_STR_DEFAULT	NULL		//�������� �� ��������� ��� word
#define TI_BOOL_DEFAULT false		//�������� �� ��������� ��� bool
#define TI_NULLIDX		0xffffffff	//��� �������� ������� ���������������
#define TI_STR_MAXSIZE	255
#define TI_BOOL_MAXSIZE	8
#define INT_MAXSIZE_PARM   10

namespace IT
{
	enum IDDATATYPE { INT = 1, STR = 2, BOOL = 3};			        //���� ������ ���������������
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, S = 5 };		//���� ���������������: ����������, �������, ��������, �������,��������.����.
	struct Entry
	{
		int			idxfirstLE;						//������ � ������� ������	
		int         line;                           //������ ������ � �������� ����
		char		id[ID_MAXSIZE];					//�������������, ��������� ��������� �� ID_MAXSIZE
		IDDATATYPE	iddatatype;						//��� ������
		IDTYPE		idtype;							//��� ��������������
		int count_parm;
		char parms[INT_MAXSIZE_PARM];
																																																												//string      obolv[ID_MAXSIZE];				// ������� ��������� 
		union
		{
			struct
			{
				int len;							//���������� �������� � bool
				char str[TI_BOOL_MAXSIZE - 1];
			}vbool;
			int	vint;								//�������� integer
			struct
			{
				int len;							//���������� �������� � string
				char str[TI_STR_MAXSIZE - 1];		//������� string
			}vstr;									//�������� string
		}value;										//�������� ��������������
		Entry()
		{
			this->value.vint = TI_INT_DEFAULT;
			this->value.vstr.len = NULL;
			this->value.vbool.len = TI_BOOL_DEFAULT;
		}
		Entry(char* id, int idxLT, IDDATATYPE datatype, IDTYPE idtype);
	};
	struct IdTable									//��������� ������� ���������������
	{
		int maxsize;								//������� ������� ��������������� < TI_MAXSIZE
		int size;									//������� ������ ������� ��������������� < maxsize
		Entry* table;								//������ ����� ������� ���������������
	};
	IdTable Create(int size = NULL);				//������� ������� ��������������� < TI_MAXSIZE
	void Add(										//�������� ������ � ������� ���������������
		IdTable &idtable,							//��������� ������� ���������������
		Entry entry);								//������ ������� ��������������� 
	Entry GetEntry(									//�������� ������ ������� ���������������
		IdTable &idtable,							//��������� ������� ���������������
		int n);										//����� ���������� ������
	int IsId(										//�������: ����� ������(���� ����), TI_NULLIDX(���� ����)
		IdTable &idtable,							//��������� ������� ���������������
		char id[ID_MAXSIZE]);						//�������������
	int GetSize(IdTable &idtable);					//�������� ������
	void SetValue(IdTable &idtable, int, char*);	//������ �������� ��������������

}