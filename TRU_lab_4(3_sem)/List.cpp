#include <iostream>
#include <iomanip>
#include <fstream>

#include "Functions.h"
#include "Struct.h"


using namespace std;


void makeList
(	List* start,		// Первый элемент
	int size,			// Длина списка
	float minValue,		// Нижняя граница
	float maxValue		// Верхняя граница
)
{

	List* current = start;
	List* temp;

	srand(time(0));

	for (int i = 0; i < size; i++) {
		temp = new List;
		current->value = (maxValue - minValue) * rand() / RAND_MAX + minValue;
		current->next = temp;
		current = current->next;
	}
	current->next = NULL;

}

void deleteList(
	List* start			// Первый элемент
) {
	List* current = start;
	while (start->next != NULL) {
		current = start;
		start = start->next;
		delete current;
	}
}

void consolePrintList( // Вывод списка в консоль
	List* start	// Начало списка
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

void filePrintList( // Вывод списка в консоль
	List* start,	// Начало списка
	char* fName		// Имя файла в который выводим данные
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

void addNewInPosition(  // Добавление в указанную позицию списка элемента 
	List* start,		// Начало списка
	float value,	// Значение нового элемента
	int position	// Позиция нового элемента
) {
	List* current = start;
	List* temp = new List;


	for (int i = 0; (i < position - 1); i++) {

		current = current->next;
		if (current->next == NULL) break;
	}

	temp->next = current->next;
	current->next = temp;
	
	current->value = value;
}

void deleteInPosition(  // Добавление в указанную позицию списка элемента 
	List* start,		// Начало списка
	int position		// Позиция нового элемента
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

float findMaxValue(		//Поиск наибольшего элемента
	List* start,		// Начало списка		
	int& position		// Позиция наибольшего элемента
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