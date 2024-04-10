#include<iostream>
using namespace std;
#define TAB "\t "

template<typename T> T** Allocate(const int rows, const int cols);//Выделение пямяти под двумерный динамический массив
template<typename T> void FillRand_arr(T** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);//Заполнение массива произвольными числами
template<typename T> void FillRand_row(T** arr, const int row, const int cols, int minRand = 0, int maxRand = 100);//Заполнение строки массива произвольными числами
template<typename T> void FillRand_col(T** arr, const int rows, const int col, int minRand = 0, int maxRand = 100);//Заполнение столбца массива призвольными числами
template<typename T> void Print(T** arr, const int rows, const int cols);//Вывод массива в консоль
template<typename T> void Clear(T** arr, const int rows);//Удаление двумерного динамического массива из памяти

template<typename T>void push_row(T**& arr, int& rows, const int cols, int index = 0 );//Добавление строки в массив
template<typename T>void pop_row(T**& arr, int& rows, const int cols, int index = 0 );//Удаление строки в массиве

template <typename T> void push_col(T**& arr, const int rows, int& cols, int index = 0 );//Добавление столбца в массив
template <typename T> void pop_col(T**& arr, const int rows, int& cols, int index = 0);//Удаление столбца в массиве



void main()
{
	setlocale(LC_ALL, "");
	
	int rows;
	int cols;
	int index;
	cout << "Введите количество строк :"; cin >> rows;
	cout << "Введите количество элементов строки :"; cin >> cols;
	int** arr = Allocate<int>(rows,cols);
	//double** arr = Allocate<double>(rows, cols);
	FillRand_arr(arr, rows, cols);
	cout << "Исходный двумерный динамический массив" << endl;
	Print(arr, rows, cols);

	///////////////////////// РАБОТА СО СТРОКАМИ МАССИВА //////////////////////////////////////////////
	
	cout << "Добавляем строку в конец массива"<<endl;
	push_row(arr, rows, cols, rows);
	FillRand_row(arr, rows-1, cols);
	Print(arr, rows,cols);
	cout << "Добавляем строку в начало массива " << endl;
	push_row(arr, rows, cols);
	FillRand_row(arr, rows-rows, cols);
	Print(arr, rows,cols);
	do
	{
		cout << "Введите индекс для вставки строки в массив от 0 до " << rows - 1<<": "; cin >> index;
	} while (index>=rows);
	push_row(arr, rows, cols, index);
	FillRand_row(arr, index, cols);
	Print(arr, rows,cols);
	cout << "Удаляем строку в конце массива " << endl;
	pop_row(arr, rows, cols, rows);
	Print(arr, rows,cols);
	cout << "Удаляем 0 строку массива " << endl;
	pop_row(arr, rows, cols);
	Print(arr, rows,cols);
	do
	{
		cout << "Введите индекс для удаление строки из массив от 0 до " << rows - 1<<": "; cin >> index;
	} while (index>=rows);
	pop_row(arr, rows,cols,index);
	Print(arr, rows,cols);

	//////////////////////// РАБОТЕ СО СТОЛБЦАМИ МАССИВА ////////////////////////////////////////////////

	cout << "Добавляем столбец в конец массива"<<endl;
	push_col(arr, rows, cols,cols);
	FillRand_col(arr, rows, cols - 1);
	Print(arr, rows,cols);
	cout << "Добавляем столбец в начало массива"<<endl;
	push_col(arr, rows, cols);
	FillRand_col(arr, rows, cols - cols);
	Print(arr, rows,cols);
	do
	{
		cout << "Введите индекс для вставки столбца в массив от 0 до " << cols - 1 << ": "; cin >> index;
	} while (index >= cols);
	push_col(arr, rows, cols, index);
	FillRand_col(arr, rows, index);
	Print(arr, rows,cols);
	cout << "Удаление последнего столбца в массиве" << endl;
	pop_col(arr, rows, cols,cols);
	Print(arr, rows,cols);
	cout << "Удаление нулевого столбца в массиве" << endl;
	pop_col(arr, rows, cols);
	Print(arr, rows,cols);
	do
	{
		cout << "Введите индекс для удаления столбца в массив от 0 до " << cols - 1 << ": "; cin >> index;
	} while (index >= cols);
	pop_col(arr, rows, cols, index);
	Print(arr, rows,cols);
	Clear(arr, rows);

}
template<typename T> T** Allocate(const int rows, const int cols)
{
	T** arr = new T * [rows];
	for (int i = 0; i < rows; i++) arr[i] = new T[cols] {};
	return arr;
}
template<typename T> void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) cout << arr[i][j]<<TAB;
		cout << endl;
	}
	cout << endl;
}
template<typename T> void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[] arr;
}
template<typename T> void FillRand_arr(T** arr, const int rows, const int cols, int minRand, int maxRand)
{
	if (minRand > maxRand)
	{
		int bufer = minRand;
		minRand = maxRand;
		maxRand = bufer;
	}
	if (typeid(arr) == typeid(double**) || typeid(arr) == typeid(float**))
	{
		minRand *= 100;
		maxRand *= 100;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
			if (typeid(arr) == typeid(double**) || typeid(arr) == typeid(float**))arr[i][j] /= 100;
		}
	}
}
template<typename T>void FillRand_row(T** arr, const int row, const int cols, int minRand, int maxRand)
{
	if (minRand > maxRand)
	{
		int bufer = minRand;
		minRand = maxRand;
		maxRand = bufer;
	}
	if (typeid(arr) == typeid(double**) || typeid(arr) == typeid(float**))
	{
		minRand *= 100;
		maxRand *= 100;
	}
	for (int i = 0; i < cols; i++)
	{
		arr[row][i] = rand() % (maxRand - minRand) + minRand;
		if (typeid(arr) == typeid(double**) || typeid(arr) == typeid(float**))arr[row][i] /= 100;
	}
}
template<typename T>void FillRand_col(T** arr, const int rows, const int col, int minRand, int maxRand)
{
	if (minRand > maxRand)
	{
		int bufer = minRand;
		minRand = maxRand;
		maxRand = bufer;
	}
	if (typeid(arr) == typeid(double**) || typeid(arr) == typeid(float**))
	{
		minRand *= 100;
		maxRand *= 100;
	}
	for (int i = 0; i < rows; i++)
	{
		arr[i][col] = rand() % (maxRand - minRand) + minRand;
		if (typeid(arr) == typeid(double**) || typeid(arr) == typeid(float**))arr[i][col] /= 100;
	}
}

template<typename T>void push_row(T**& arr, int& rows, const int cols, int index)
{
	T** bufer = new T* [rows+1];
	for (int i = 0; i < rows; i++)(i < index ? bufer[i] : bufer[i + 1]) = arr[i];
	delete[] arr;
	bufer[index] = new T[cols]{};
	rows++;
	arr = bufer;
}
template<typename T>void pop_row(T**& arr, int& rows, const int cols, int index)
{
	T** bufer = new T* [--rows];
	if (index > rows) index = rows;
	delete[] arr[index];
	for (int i = 0; i < rows; i++) i < index ? bufer[i]=arr[i] : bufer[i] = arr[i+1];
	delete[] arr;
	arr = bufer;
}

template<typename T> void push_col(T**& arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* bufer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++) (i < index ? bufer[j] : bufer[j + 1]) = arr[i][j];
		delete[] arr[i];
		arr[i] = bufer;
	}
	cols++;
}
template<typename T> void pop_col(T**& arr, const int rows, int& cols, int index)
{
	cols--;
	if (index > cols) index = cols;
	for (int i = 0; i < rows; i++)
	{
		T* bufer = new T[cols];
		for (int j = 0; j < cols; j++) j < index ? bufer[j] = arr[i][j] : bufer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = bufer;
	}
}