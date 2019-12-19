#include "pch.h"
#include "Error.h"
namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
	//				0 -  100 - ��������� ������
	//				101 - 200 - ������ ����������
	//				201 - 300 - ������ ������������ �������
	//				301 - 400 - ������ ��������������� �������
	//				401 - 500 - ������ �������������� �������
	//				501 - 600 - ������ ������

		ERROR_ENTRY(0, "������������ ��� ������"),
		ERROR_ENTRY(1, "��������� ����"),
		ERROR_ENTRY_NODEF(2),ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6),ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8),ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),ERROR_ENTRY_NODEF(100),
		ERROR_ENTRY(101, "�������� -in ������ ���� �����"),
		ERROR_ENTRY(102,"��������� ����� �������� ���������"),
		ERROR_ENTRY(103,"������ ��� �������� ����� � �������� �����(-in)"),
		ERROR_ENTRY(104,"������������ ������ � �������� ����� (-in)"),
		ERROR_ENTRY(105,"������ ��� �������� ����� ���������(-log)"),
		ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107),	ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY_NODEF(110),	ERROR_ENTRY_NODEF(111),	ERROR_ENTRY_NODEF(112),
		ERROR_ENTRY_NODEF(113),	ERROR_ENTRY_NODEF(114),	ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY_NODEF(116),	ERROR_ENTRY_NODEF(117),
		ERROR_ENTRY(118, "�������������� ������� ������������� ���� �������"),
		ERROR_ENTRY_NODEF(119),	ERROR_ENTRY_NODEF10(120),ERROR_ENTRY_NODEF10(130),	
		ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF(200),
		ERROR_ENTRY(201,"�������� ������ ������� ������"),
		ERROR_ENTRY(202,"�� ������� ��������� �����"),
		ERROR_ENTRY_NODEF(203),
		ERROR_ENTRY(204,"���������� ���� byte ����� ��������� �������� �� 0 �� 255"),
		ERROR_ENTRY(205,"��������� ������������ ����� ������"),
		ERROR_ENTRY_NODEF(206),
		ERROR_ENTRY_NODEF(207),ERROR_ENTRY_NODEF(208),
		ERROR_ENTRY_NODEF(209),ERROR_ENTRY_NODEF10(210),ERROR_ENTRY_NODEF10(220),
		ERROR_ENTRY_NODEF10(230),ERROR_ENTRY_NODEF10(240),ERROR_ENTRY_NODEF10(250),
		ERROR_ENTRY_NODEF10(260),ERROR_ENTRY_NODEF10(270),ERROR_ENTRY_NODEF10(280),
		ERROR_ENTRY_NODEF10(290),ERROR_ENTRY_NODEF(300),
		ERROR_ENTRY(301,"�������� ��������� ���������"),
		ERROR_ENTRY(302,"������ � ���������"),
		ERROR_ENTRY(303,"��������� ��������"),
		ERROR_ENTRY(304,"������ � ���������� �������"),
		ERROR_ENTRY(305,"������ � ���������� ���������� �������"),
		ERROR_ENTRY(306,"��������� ��������"),
		ERROR_ENTRY(307,"������ � �������������� �������"),
		ERROR_ENTRY(308, "��� ���������� ������"),
		ERROR_ENTRY_NODEF(309),ERROR_ENTRY_NODEF10(310),
		ERROR_ENTRY_NODEF10(320),ERROR_ENTRY_NODEF10(330),ERROR_ENTRY_NODEF10(340),
		ERROR_ENTRY_NODEF10(350),ERROR_ENTRY_NODEF10(360),ERROR_ENTRY_NODEF10(370),
		ERROR_ENTRY_NODEF10(380),ERROR_ENTRY_NODEF10(390),ERROR_ENTRY_NODEF(400),
		ERROR_ENTRY(401, "������� ������� (main) ������ ���� ����"),
		ERROR_ENTRY(402, "����� ����� main �� �������"),
		ERROR_ENTRY(403, "������� ���������������"), 
		ERROR_ENTRY(404, "����������� ��������������� �����������"),
		ERROR_ENTRY(405, "�������� ���������� ���������� ��� ������ �������"),
		ERROR_ENTRY(406, "��� ������������ �������� �� ������������ ���� �������"),
		ERROR_ENTRY(407, "��������� ������������ ���������� ������������ ���������� ��� ������ �������"),
		ERROR_ENTRY(408, "��������� ������������ ���������� ������������ ���������� ��� ����������� �������"),
		ERROR_ENTRY(409," ������ ���������� ���������� ���� bool � word � ��������� ������� sqrt � pow"),
		ERROR_ENTRY_NODEF(410),	ERROR_ENTRY_NODEF(411),
		ERROR_ENTRY(412, "�������� ���� ����������"),
		ERROR_ENTRY(413, "������������� ���a �������������� � ����������� ��� ��������"),
		ERROR_ENTRY(414,"� ������� ������ ������������ �������������� ���� word"),
		ERROR_ENTRY(415, "������� �������������� �����"),
		ERROR_ENTRY(416,"������ ������������ ������� ��������� ���� � ������� ��������� ������������� ���� bool"),
		ERROR_ENTRY(417, "������� ���������� �������� �� ��������� ����� ������"),
		ERROR_ENTRY(418,"�������� ���������� ������������ ���������� � sqrt"),
		ERROR_ENTRY(419, "�������� ���������� ������������ ���������� � pow"),
		ERROR_ENTRY(420,"�������� ������� pow ����� ���� ��������� ������ �������������� ���� byte"),
		ERROR_ENTRY(421,"�������� ������� sqrt ����� ���� ��������� ������ �������������� ���� byte"),
		ERROR_ENTRY_NODEF(422),ERROR_ENTRY_NODEF(423),
		ERROR_ENTRY_NODEF(424),ERROR_ENTRY_NODEF(425),ERROR_ENTRY_NODEF(426),
		ERROR_ENTRY_NODEF(427),ERROR_ENTRY_NODEF(428),ERROR_ENTRY_NODEF(429),
		ERROR_ENTRY_NODEF10(430),ERROR_ENTRY_NODEF10(440),
		ERROR_ENTRY_NODEF10(450),ERROR_ENTRY_NODEF10(460),ERROR_ENTRY_NODEF10(470),
		ERROR_ENTRY_NODEF10(480), ERROR_ENTRY_NODEF10(490),
		ERROR_ENTRY_NODEF100(500),ERROR_ENTRY_NODEF(600) /* -�������������� ����� � �������;
-���������� ��������� �������� ��������;
-���������� ��������� �������� �������.*/

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