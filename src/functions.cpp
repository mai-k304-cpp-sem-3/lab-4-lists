#include <iostream>
#include <iomanip>
#include <fstream>

#include "functions.h"

using namespace std;

const char verticalLine = (char)186;		// "║" - Вертикальная линия
const char horizontalLine = (char)205;		// "═" - Горизонтальная линия
const char topLeftCorner = (char)201;		// "╔" - Левый верхний угол
const char topRightCorner = (char)187;		// "╗" - Правый верхний угол
const char bottomLeftCorner = (char)200;	// "╚" - Левый нижний угол
const char bottomRightCorner = (char)188;	// "╝" - Правый нижний угол
const char leftJunction = (char)185;		// "╣" - вертикальная "труба влево"
const char rightJunction = (char)204;		// "╠" - вертикальная "труба вправо"
const char bottomJunction = (char)203;		// "╦" - Горизонтальная вниз "труба"
const char topJunction = (char)202;			// "╩" - Горизонтальная вниз "труба"
const char crossJunction = (char)206;		// "╬" - пересечение линий
const char space = (char)32;				// Пустое пространство

const int numCellSize = 4;			  // Размер ячейки с номерами элементов
const int valueCellSize = 10;		  // Размер ячейки со значениями элементов

void makeList (
	List* start,		// Начало списка
	int size,			// Размер будущего списка
	float minValue,		// Нижняя граница
	float maxValue		// Верхняя граница
) {
	List* current = start;
	List* temp;

	srand(time(0) + rand());

	for (int i = 0; i < size; i++) {
		temp = new List;
		current->value = (maxValue - minValue) * rand() / RAND_MAX + minValue;
		current->next = temp;
		current = current->next;
	}
	current->next = NULL;
}

void deleteList (
	List* start			// Начало списка
) {
	List* current = start;
	while (start->next != NULL) {
		current = start;
		start = start->next;
		delete current;
	}
	delete start;
}

void consolePrintList( // Вывод списка в консоль
	List* start		   // Начало списка
) {
	List* current = start;
	int i = 0;

	setlocale(LC_ALL, "C");

	// Выводим заголовок таблицы
	cout << setfill(horizontalLine)					
		 << topLeftCorner  << setw(numCellSize)
		 << bottomJunction << setw(valueCellSize)
		 << topRightCorner << endl;

	while (current->next != NULL) {
		// Печать столбцов с данными
		cout	<< setfill(space)
				<< verticalLine << setw(numCellSize-1)   << right << i
				<< verticalLine	<< setw(valueCellSize-1) << right << current->value 
				<< verticalLine << endl;
		current = current->next;
		i++;
	}
	// Вывод "дна" таблицы
	cout << setfill(horizontalLine)
		 << bottomLeftCorner  << setw(numCellSize)
		 << topJunction    << setw(valueCellSize)
		 << bottomRightCorner << endl;

	cout << endl;

	setlocale(LC_ALL, "ru");
}

void filePrintList( // Вывод данных в файл
	List* start,	// Начальный элемент
	string fName	// Имя файлы для вывода
) {
	List* current = start;
	int i = 0;

	ofstream ofs_func(fName); // Создаем файл

	while (current->next != NULL) { // Печатаем элементы пока не встретим ссылку на NULL (конец списка)
		ofs_func << '[' << setw(3) << right << i << "] = "
			<< current->value << endl;
		current = current->next;
		i++;
	}
	ofs_func << endl;
	ofs_func.close(); 
}

void addNewInPosition(  // Добавление элемента в заданную позицию
	List* start,		// Начальный элемент
	float value,		// Значение нового элемента
	int position		// Позиция нового элемента
) {
	List* current = start; 
	List* temp = new List;  // Элемент который будем добавлять
	temp->value = value;	// Сразу присваиваем значение


	for (int i = 0; (i < position - 1); i++) {

		if (current->next->next == NULL) { // Если оказалось, что желаемая позиция за границами списка, добавляем элемент в конец. 

			temp->next = current->next;    // "Внедряем" элемент
			current->next = temp;
			return;
		}
			
		current = current->next;
	}

	temp->next = current->next;	// "Внедряем" элемент
	current->next = temp;
}

void deleteInPosition (  // Удаление элемнта из списка с заданной позицией
	List* start,		// Начальный элемент
	int position		// Позиция элемента
) {
	List* current = start;
	List* temp;

	for (int i = 0; i < position - 1; i++) {     //Движение до нужного элемента
		if (current->next->next->next == NULL) { // Если данного элемента не существует
			cout << "Элемент не обнаружен." << endl;
			return;
		}
		current = current->next;    // Переход к следующему элементу
	}
	temp = current->next;			// Удаляемый элемент
	current->next = current->next->next; // "Сшиваем" список
	delete(temp);
}

List* findMaxValue (		// Поиск максимального значения в списке
	List* start,		// Начальный элемент		
	int& position		// Позиция элемента
) {
	List* current = start;
	List* maxElement = current;   // Берем первый элемент за стартовый
	position = 0;				  // Позиция наибольшего элемента
	int i = 0;					  // Счетчик

	while (current->next != NULL) {
		i++;
		current = current->next;  // Движемся по списку
		if (maxElement->value < current->value) { // Проверяем, больше ли текущий элемент того, что мы запомнили
			position = i;			  // Если да, то запоминаем его позицию и значение
			maxElement->value = current->value;
		}
	}
	return maxElement;  //Возвращаем наибольшее значение элемента
}