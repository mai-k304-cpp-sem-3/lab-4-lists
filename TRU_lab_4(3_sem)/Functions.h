#include "Struct.h"

#ifndef FUNC
#define FUNC



void makeList
(List* start,		// ������ �������
	int size,			// ����� ������
	float minValue,		// ������ �������
	float maxValue		// ������� �������
);

void deleteList(
	List* start			// ������ �������
);

void consolePrintList(
	List* start	// ������ ������
);

void filePrintList( // ����� ������ � �������
	List* start,	// ������ ������
	char* fName		// ��� ����� � ������� ������� ������
);

void addNewInPosition(  // ���������� � ��������� ������� ������ �������� 
	List* start,		// ������ ������
	float value,	// �������� ������ ��������
	int position	// ������� ������ ��������
);

void deleteInPosition(  // ���������� � ��������� ������� ������ �������� 
	List* start,		// ������ ������
	int position	// ������� ������ ��������
);

float findMaxValue(		//����� ����������� ��������
	List* start,		// ������ ������		
	int& position		// ������� ����������� ��������
);

#endif
