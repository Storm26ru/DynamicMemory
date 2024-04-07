#include<iostream>
using namespace std;
#define TAB "\t "

template<typename T> T** Allocate(const int rows, const int cols);//Выделение пямяти под двумерный динамический массив
template<typename T> void FillRand_arr(T** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);//Заполнение массива произвольными числами
void FillRand_row(int** arr, const int row, const int cols);//Заполнение строки массива произвольными числами
void FillRand_col(int** arr, const int rows, const int col);//Заполнение столбца массива призвольными числами
template<typename T> void Print(T** arr, const int rows, const int cols);//Вывод массива в консоль
template<typename T> void Clear(T** arr, const int rows);//Удаление двумерного динамического массива из памяти

template<typename T>void push_row_back(T**& arr,  int & rows, const int cols);//Добавление строки в конец массива
template<typename T>void push_row_front(T**& arr,  int & rows, const int cols);//Добавление строки в начало массива
template<typename T>void insert_row(T**& arr, int& rows, const int cols, const int index );//Вставка строки в массив по указанному индексу
template<typename T>void pop_row_back(T**& arr,  int & rows, const int cols);//Удаление последней строки массива
template<typename T>void pop_row_front(T**& arr,  int & rows, const int cols);//Удаление нулевой строки массива
template<typename T>void erase_row(T**& arr, int& rows, const int cols, const int index );//Удаление строки в массиве по указанному индексу

template <typename T> void push_col_back(T**& arr, const int rows, int& cols);//Добавление столбца в конец массива
template <typename T> void push_col_front(T**& arr, const int rows, int& cols);//Добавление столбца в начало массива
template <typename T> void insert_col(T**& arr, const int rows, int& cols, const int index );//Добавление столбца в массив по указанному индексу
template <typename T> void pop_col_back(T**& arr, const int rows, int& cols);//Удаление последнего столбца в массиве
template <typename T> void pop_col_front(T**& arr, const int rows, int& cols);//Удаление нулевого столбца в массиве
template <typename T> void erase_col(T**& arr, const int rows, int& cols, const int index);//Удаление столбца в массиве по указанному индексу



void main()
{
	setlocale(LC_ALL, "");
	
	int rows;
	int cols;
	int index;
	cout << "Введите количество строк :"; cin >> rows;
	cout << "Введите количество элементов строки :"; cin >> cols;
	int** arr = Allocate<int>(rows,cols);
	FillRand_arr(arr, rows, cols);
	cout << "Исходный двумерный динамический массив" << endl;
	Print(arr, rows, cols);

	// Работа со строками массива
	
	push_row_back(arr, rows, cols);
	Print(arr, rows,cols);
	push_row_front(arr, rows, cols);
	Print(arr, rows,cols);
	do
	{
		cout << "Введите индекс для вставки строки в массив от 0 до " << rows - 1<<": "; cin >> index;
	} while (index>=rows);
	insert_row(arr, rows, cols, index);
	Print(arr, rows,cols);
	pop_row_back(arr, rows, cols);
	Print(arr, rows,cols);
	pop_row_front(arr, rows, cols);
	Print(arr, rows,cols);
	do
	{
		cout << "Введите индекс для удаление строки из массив от 0 до " << rows - 1<<": "; cin >> index;
	} while (index>=rows);
	erase_row(arr, rows,cols,index);
	Print(arr, rows,cols);

	// Работа со столбцами массива

	push_col_back(arr, rows, cols);
	Print(arr, rows,cols);
	push_col_front(arr, rows, cols);
	Print(arr, rows,cols);
	do
	{
		cout << "Введите индекс для вставки столбца в массив от 0 до " << cols - 1 << ": "; cin >> index;
	} while (index >= cols);
	insert_col(arr, rows, cols, index);
	Print(arr, rows,cols);
	pop_col_back(arr, rows, cols);
	Print(arr, rows,cols);
	pop_col_front(arr, rows, cols);
	Print(arr, rows,cols);
	do
	{
		cout << "Введите индекс для удаления столбца в массив от 0 до " << cols - 1 << ": "; cin >> index;
	} while (index >= cols);
	erase_col(arr, rows, cols, index);
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
void FillRand_row(int** arr, const int row, const int cols)
{
	for (int i = 0; i < cols; i++) arr[row][i] = rand() % 100;
}
void FillRand_col(int** arr, const int rows, const int col)
{
	for (int i = 0; i < rows; i++) arr[i][col] = rand() % 100;
}

template<typename T>void push_row_back(T**&arr, int& rows, const int cols)
{
	cout << "Вставляем строку в конец массива" << endl;
	T** bufer = new T* [rows+1];
	for (int i = 0; i < rows; i++) bufer[i] = arr[i];
	delete[] arr;
	bufer[rows] = new T [cols] {};
	rows++;
	arr = bufer;
}
template<typename T>void push_row_front(T**& arr, int& rows, const int cols)
{
	cout << "Вставляем строку в начало массива"<< endl;
	T** bufer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)bufer[i+1] = arr[i];
	delete[] arr;
	bufer[0] = new T[cols]{};
	rows++;
	arr = bufer;
}
template<typename T>void insert_row(T**& arr, int& rows, const int cols, const int index)
{
	cout << "Вставляем строку в массив по индексу "<<index << endl;
	T** bufer = new T* [rows+1];
	for (int i = 0; i < rows; i++)(i < index ? bufer[i] : bufer[i + 1]) = arr[i];
	delete[] arr;
	bufer[index] = new T[cols]{};
	rows++;
	arr = bufer;
}
template<typename T>void pop_row_back(T**& arr, int& rows, const int cols)
{
	cout << "Удаляем последнюю строку из массива" << endl;
	T** bufer = new T* [--rows];
	delete[] arr[rows];
	for (int i = 0; i < rows; i++)bufer[i] = arr[i];
	delete[] arr;
	arr = bufer;
}
template<typename T>void pop_row_front(T**& arr, int& rows, const int cols)
{
	cout << "Удаляем нулевую строку из массива" << endl;
	T** bufer = new T* [--rows];
	delete[] arr[0];
	for (int i = 0; i < rows; i++) bufer[i] = arr[i+1];
	delete[]arr;
	arr = bufer;
}
template<typename T>void erase_row(T**& arr, int& rows, const int cols, const int index)
{
	cout << "Удаляем строку из массива по индексу "<<index << endl;
	T** bufer = new T* [--rows];
	delete[] arr[index];
	for (int i = 0; i < rows; i++) i < index ? bufer[i]=arr[i] : bufer[i] = arr[i+1];
	delete[] arr;
	arr = bufer;
}

template<typename T> void push_col_back(T**& arr, const int rows, int& cols)
{
	cout << "Добавляем столбец в конец массива" << endl;
	for (int i = 0; i < rows; i++)
	{
		T* bufer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++) bufer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = bufer;
	}
	cols++;
}
template<typename T> void push_col_front(T**& arr, const int rows, int& cols)
{
	cout << "Добавляем столбец в начало массива" << endl;
	for (int i = 0; i < rows; i++)
	{
		T* bufer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++) bufer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = bufer;
	}
	cols++;
}
template<typename T> void insert_col(T**& arr, const int rows, int& cols, const int index)
{
	cout << "Вставляем столбец в массив по индексу " << index << endl;
	for (int i = 0; i < rows; i++)
	{
		T* bufer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++) (i < index ? bufer[j] : bufer[j + 1]) = arr[i][j];
		delete[] arr[i];
		arr[i] = bufer;
	}
	cols++;
}
template<typename T> void pop_col_back(T**& arr, const int rows, int& cols)
{
	cout << "Удаление последнего столбца из массива" << endl;
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* bufer = new T[cols]{};
		for (int j = 0; j < cols; j++) bufer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = bufer;
	}
}
template<typename T> void pop_col_front(T**& arr, const int rows, int& cols)
{
	cout << "Удаление нулевого столбца из массива" << endl;
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* bufer = new T[cols];
		for (int j = 0; j < cols; j++) bufer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = bufer;
	}
}
template<typename T> void erase_col(T**& arr, const int rows, int& cols, const int index)
{
	cout << "Удаление столбца из массива по идексу " << index << endl;
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* bufer = new T[cols];
		for (int j = 0; j < cols; j++) j < index ? bufer[j] = arr[i][j] : bufer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = bufer;
	}
}