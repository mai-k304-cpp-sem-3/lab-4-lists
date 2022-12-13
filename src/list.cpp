#include <iostream>
#include <iomanip>
#include <fstream>

#include "functions.h"

using namespace std;

void makeList
(	List* start,		// ������ �������
	int size,			// ����� ������
	float minValue,		// ������ �������
	float maxValue		// ������� �������
) {
	List* current = start;
	List* temp;

	srand(time(0)+rand());

	for (int i = 0; i < size; i++) {
		temp = new List;
		current->value = (maxValue - minValue) * rand() / RAND_MAX + minValue;
		current->next = temp;
		current = current->next;
	}
	current->next = NULL;
}

void deleteList(
	List* start			// ������ �������
) {
	List* current = start;
	while (start->next != NULL) {
		current = start;
		start = start->next;
		delete current;
	}
}

void consolePrintList( // ����� ������ � �������
	List* start	// ������ ������
) {
	List* current = start;
	int i = 0;

	while (current->next != NULL) {
		cout <<'['<<setw(3)<<right<<i<< "] = "
			<<current->value <<endl;
		current = current->next;
		i++;
	}
	cout << endl;
}

void filePrintList( // ����� ������ � �������
	List* start,	// ������ ������
	char* fName		// ��� ����� � ������� ������� ������
) {
	List* current = start;
	int i = 0;

	ofstream ofs_func(fName);

	while (current->next != NULL) {
		ofs_func << '[' << setw(3) << right << i << "] = "
			<< current->value << endl;
		current = current->next;
		i++;
	}
	ofs_func << endl;
	ofs_func.close();
}

void addToStart(List start*,float value) {

	List* next = start;
	List* newStart = new List;
	start = newStart;

}

void addNewInPosition(  // ���������� � ��������� ������� ������ �������� 
	List* start,		// ������ ������
	float value,	// �������� ������ ��������
	int position	// ������� ������ ��������
) {
	List* current = start;
	List* temp = new List;


	for (int i = 0; (i < position - 1); i++) {

		current = current->next;
		if (current->next == NULL) break;
	}

	temp->next = current->next;
	current->next = temp;
	
	current->next->value = value;
}

void deleteInPosition(  // ���������� � ��������� ������� ������ �������� 
	List* start,		// ������ ������
	int position		// ������� ������ ��������
) {
	List* current = start;
	List* temp;

	for (int i = 0; i < position - 1; i++) {
		if (current->next->next == NULL) {
			break;
		}
		current = current->next;
	}
	temp = current->next;
	current->next = current ->next->next;
	delete(temp);
}

float findMaxValue(		//����� ����������� ��������
	List* start,		// ������ ������		
	int& position		// ������� ����������� ��������
) {
	List* current = start;
	float value = current->value;
	position = 0;
	int i = 0;

	while (current->next != NULL) {
		i++;
		current = current->next;
		if (value < current->value) {
			position = i;
			value = current->value;
		}
	}
	return value;
}