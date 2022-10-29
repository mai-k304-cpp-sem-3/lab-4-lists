#include "Struct.h"

#ifndef FUNC
#define FUNC



void makeList
(List* start,		// Первый элемент
	int size,			// Длина списка
	float minValue,		// Нижняя граница
	float maxValue		// Верхняя граница
);

void deleteList(
	List* start			// Первый элемент
);

void consolePrintList(
	List* start	// Начало списка
);

void filePrintList( // Вывод списка в консоль
	List* start,	// Начало списка
	char* fName		// Имя файла в который выводим данные
);

void addNewInPosition(  // Добавление в указанную позицию списка элемента 
	List* start,		// Начало списка
	float value,	// Значение нового элемента
	int position	// Позиция нового элемента
);

void deleteInPosition(  // Добавление в указанную позицию списка элемента 
	List* start,		// Начало списка
	int position	// Позиция нового элемента
);

float findMaxValue(		//Поиск наибольшего элемента
	List* start,		// Начало списка		
	int& position		// Позиция наибольшего элемента
);

#endif
