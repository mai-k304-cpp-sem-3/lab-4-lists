#include <iostream>
#include <fstream>
#include <string>

#include "functions.h"

const char OUT_PATH[] = "output\\";      // Путь для сохранения выходных данных
const char INPUT_FILE[] = "input.txt";


using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");

	string out_file;
	int num_out_file = 0;

	bool operation = true;
	bool maded = false;
	//bool devKey = true;
	bool devKey = false;

	int position;			// Позиция элемента
	int size;				// Размер изачального списка
	float value;			// Значение
	float minValue;			// Нижняя граница генерации
	float maxValue;		    // Верхняя граница генерации
	List* maxValueInList;	// Наибольший элемент списка

	List* list = new List;

	int answ = -1;
	cout << "Добро пожаловать в меню." << endl;

	while (answ != 8) { // Гуляем по программе, пока не получим сигнал на выход
		operation = false;
		
		cout << "Выберите 1 вариант из нижеперчисленных." << endl
			<< "\t1.Сгенерировать список.\n"
			<< "\t2.Удалить список.\n"
			<< "\t3.Создать элемент в заданной позиции.\n"
			<< "\t4.Удалить элемент в заданной позиции.\n"
			<< "\t5.Найти наибольший элемент в списке.\n"
			<< "\t6.Печать списка в файл.\n"
			<< "\t7.Печать списка в консоль.\n"
			<< "\t8.Выход из программы.\n"
			<< "Пожалуйста, укажите номер операции: ";
		cin >> answ;
		// Меню представлено в виде switch case 
		switch (answ) {
		case 1:     // Генерация списка
			operation = true;
			if (maded) {
				cout << "\nСначала предыдущий список должен быть удален.\n";
			}
			else {
				maded = true;
				list = new List;
				if (!devKey) {
					ifstream ifs(INPUT_FILE);
					if (!ifs.is_open()) {
						cout << "File not founded!" << endl;
						exit(1);
					}

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
			break;

		case 2: // Удаление списка
			operation = true;
			if (maded) {
				maded = false;
				deleteList(list);
				cout << "\nСписок удален.\n";
			}
			else {
				cout << "\nНевозможно удалить список так как он и не был создан.\n";
			}
			break;

		case 3: // Добавление элемента в заданную позицию 
			operation = true;
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
			break;

		case 4: // Удалить элемент в заданной позиции
			operation = true;
			if (maded) {
				cout << "\n\nПожалуйста, введите номер позиции элемента: ";
				cin >> position;
				deleteInPosition(list, position);
				consolePrintList(list);
			}
			else {
				cout << "\nСначала нужно создать список.\n";
			}
			break;

		case 5: // Нахождение наибольшего элемента в списке
			operation = true;
			if (maded) {
				maxValueInList = findMaxValue(list, position);
				cout << "\n\nПозиция элемента  = " << position
					 << "\nЗначение = " << maxValueInList->value << endl;
			}
			else {
				cout << "\nСначала нужно создать список.\n";
			}
			break;

		case 6: //Печать списка в файл
			operation = true;
			if (maded) {

				out_file = OUT_PATH;
				out_file += "input_" + to_string(num_out_file) + ".txt"; // Формирование имени файла
				filePrintList(list, out_file);
				cout <<endl<<"Список сохранен в файл:\n" << out_file << endl<<endl;		
				
			}
			else {
				cout << endl << "Сначала создайте список" << endl << endl;
			}			
			break;

		case 7: //Печать списка в консоль
			operation = true;
			if (maded) {
				consolePrintList(list);
			}
			else {
				cout << endl << "Сначала создайте список" << endl << endl;
			}
			break;
		}		

		if (!operation) { // Если не выполнено ни 1 операции со списком
			cout << "\nВведите корректный ответ.\n\n";
		}
		
	} // end while
}

