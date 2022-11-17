#include "Main.h"

int main()
{
	auto a = 3.1415;
	auto b = 35;
	auto c = 0.5432;

	auto d = "3.1415";
	auto e = "35";
	auto f = "0.5432";

	int delay = 2000;

	Sleep(delay);
	cout << "type of a : " << typeid(a).name() << endl;
	cout << "type of d : " << typeid(d).name() << endl;

	Sleep(delay);

	try
	{
		//Создать контейнер (пустой)
		Array<double>* array1Ptr = new Array<double>();
		Array<double>& array1 = *array1Ptr;

		cout << "Set size = 10" << endl;
		array1.setNewSize(10);
		cout << "Size = " << array1.getSize() << endl;


		Sleep(delay);

		//Изменить размер контейнера
		cout << "Set new size = 12" << endl;
		array1.setNewSize(12);
		cout << "size = " << array1.getSize() << endl;

		Sleep(delay);

		//Заполнить контейнер значениями, равными порядковому номеру элемента
		//с использованием индекса 
		for (size_t i = 0; i < array1.getSize(); i++)
		{
			array1[i] = static_cast<double>(i);
		}
		cout << endl << "array filled 0,1,2..n " << endl;
		array1.print();
		cout << "size = " << array1.getSize() << endl;

		Sleep(delay);
		cout << "Set Array[3] = 3.1415" << endl;
		//установить значение элемента
		array1[3] = a;
		Sleep(delay);
		//получить значение элемента
		cout << "Get Array[3] =" << array1[3] << endl;
		Sleep(delay);

		//записать элемент за пределами контейнера
		cout << endl << "setting an element outside the array" << endl;
		try
		{
			array1[1000] = 101;
		}
		catch (exception& except)
		{
			cout << endl << except.what() << endl;
		}

		Sleep(delay);
		//вставить элемент
		array1.insertElement(10, b);
		cout << endl << "inserted element 10 = 35 " << endl;

		Sleep(delay);
		//убрать элемент
		array1.removeElement(9);
		cout << endl << "removed element 9" << endl;



		Sleep(delay);
		array1[5] = c;
		cout << endl << "Set element [5] =" << c << endl;
		
		//поиск елемента
		cout << endl << "an element " << c << " search started..." << endl;
		try
		{
			int elIndex = array1.findElement(c);
			cout << "found element with index: " << elIndex << " = " << array1[elIndex] << endl;
		}
		catch (exception& except)
		{
			cout << endl << except.what() << endl;
		}

		//Копирование контейнера
		Array<double>* array2Ptr = new Array<double>();
		Array<double>& array2 = *array2Ptr;

		Sleep(delay);
		cout << endl << "Print array 2 before copy:" << endl;
		Sleep(delay);
		array2.print();
		array2 = array1;
		delete array1Ptr;
		Sleep(delay);
		cout << "Print array 2 after copy:" << endl;
		Sleep(delay);
		array2.print();
		delete array2Ptr;

		
		Sleep(5000);

		cout << endl << "String array:" << endl;
		Sleep(delay);
		Array<string>* array3Ptr = new Array<string>();
		Array<string>& array3 = *array3Ptr;
		array3.setNewSize(22);
		array3[3] = "What is it?";
		array3[4] = d;
		array3[5] = e;
		array3[6] = f;
		array3Ptr->print();

		Sleep(delay);
		//поиск елемента
		cout << endl << "element search \"What is it ?\" started..." << endl;
		try
		{
			Sleep(delay);
			int elIndex = array3.findElement("What is it?");
			cout << "found element with index: " << elIndex << " = " << array3[elIndex] << endl;
		}
		catch (exception& except)
		{
			cout << endl << except.what() << endl;
		}


	}
	catch (exception& except)
	{
		cout << except.what() << endl;
	}
	Sleep(delay);
	cout << endl << "//////////// Goodbye! //////////////" << endl;
	return 0;
}