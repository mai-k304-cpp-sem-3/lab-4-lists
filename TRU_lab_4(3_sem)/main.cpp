#include <iostream>
#include <fstream>


#include "Struct.h"
#include "Functions.h"

const char OUT_PATH[] = "output//";      // Путь для сохранения выходных данных
const char INPUT_FILE[] = "input.txt";

using namespace std;
int main()
{


	setlocale(LC_ALL, "ru");

	bool operation  = true;
	bool maded = false;
	bool devKey = false;

	int position;
	int size;
	float value;
	float minValue;
	float maxValue;
	float maxValueInList;

	List* list = new List;

	int answ = 0;
	cout << "Добро пожаловать в меню." << endl;

	while (answ != 6) {

		if (operation = false) {
			cout << "Введите корректный ответ.\n\n";
		}

		operation = false;
		cout << "Выберите 1 вариант из нижеперчисленных." << endl
			<< "\t1.Сгенерировать список.\n"
			<< "\t2.Удалить список.\n"
			<< "\t3.Создать элемент в заданной позиции.\n"
			<< "\t4.Удалить элемент в заданной позиции.\n"
			<< "\t5.Найти наибольший элемент в списке.\n"
			<< "\t6.Выход из программы.\n"
			<< "Пожалуйста, укажите номер операции: ";
		cin >> answ;

		if (answ == 1 ) {
			if (maded) {
				cout << "\nСначала предыдущий список должен быть удален\n";
			}
			else {
				maded = true;
				list = new List;
				if(!devKey){
					ifstream ifs(INPUT_FILE);

					ifs >> size;
					ifs >> minValue;
					ifs >> maxValue;

					cout << "size = " << size << endl
						<< "minValue = " << minValue << endl
						<< "maxValue = " << maxValue << endl << endl;
				}
				else {
					cout << "\n\nПожалуйста, введите размер списка: ";
					cin >> size;
					cout << "\nПожалуйста, введите нижнюю границу: ";
					cin >> minValue;
					cout << "\nПожалуйста, введите верхнюю границу: ";
					cin >> maxValue;
				}

				makeList(list, size, minValue, maxValue);
				consolePrintList(list);
			}

		}
		if (answ == 2) {
			if (maded) {
				maded = false;
				deleteList(list);
				cout << "\nСписок удален.\n";
			}
			else {
				cout << "\nНевозможно удалить список так как он и не был создан.\n";
			}
		}
		if (answ == 3) {
			if (maded) {
				cout << "\n\nПожалуйста, введите номер позиции элемента: ";
				cin >> position;
				cout << "\n\nПожалуйста, введите значение : ";
				cin >> value;
				addNewInPosition(list, value, position);
				consolePrintList(list);
			}
			else {
				cout << "\nСначала нужно создать список.\n";
			}
		}
		if (answ == 4) {
			if (maded) {
				cout << "\n\nПожалуйста, введите номер позиции элемента: ";
				cin >> position;
				deleteInPosition(list, position);
				consolePrintList(list);
			}
			else {
				cout << "\nСначала нужно создать список.\n";
			}
		}
		if (answ == 5) {
			if (maded) {
				maxValueInList = findMaxValue(list, position);
				cout << "\n\nПозиция элемента  = " << position
					<< "\nЗначение = " << maxValueInList << endl;
			}
			else {
				cout << "\nСначала нужно создать список.\n";
			}
		}

	}
}

