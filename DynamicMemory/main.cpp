#include<iostream>
using namespace std;
#define TAB "\t "

void Allocate(int** arr, const int rows, const int cols);//Выделение пямяти под двумерный динамический массив
void FillRand_arr(int** arr, const int rows, const int cols);//Заполнение массива произвольными числами
void FillRand_row(int** arr, const int row, const int cols);//Заполнение строки массива произвольными числами
void FillRand_col(int** arr, const int rows, const int col);//Заполнение столбца массива призвольными числами
void Print(int** arr, const int rows, const int cols);//Вывод массива в консоль
void Clear(int** arr, const int rows);//Удаление двумерного динамического массива из памяти

void push_row_back(int**& arr,  int & rows, const int cols);//Добавление строки в конец массива
void push_row_front(int**& arr,  int & rows, const int cols);//Добавление строки в начало массива
void insert_row(int**& arr, int& rows, const int cols, const int index );//Вставка строки в массив по указанному индексу
void pop_row_back(int**& arr,  int & rows, const int cols);//Удаление последней строки массива
void pop_row_front(int**& arr,  int & rows, const int cols);//Удаление нулевой строки массива
void erase_row(int**& arr, int& rows, const int cols, const int index );//Удаление строки в массиве по указанному индексу

void push_col_back(int**& arr, const int rows, int& cols);//Добавление столбца в конец массива
void push_col_front(int**& arr, const int rows, int& cols);//Добавление столбца в начало массива
void insert_col(int**& arr, const int rows, int& cols, const int index );//Добавление столбца в массив по указанному индексу
void pop_col_back(int**& arr, const int rows, int& cols);//Удаление последнего столбца в массиве
void pop_col_front(int**& arr, const int rows, int& cols);//Удаление нулевого столбца в массиве
void erase_col(int**& arr, const int rows, int& cols, const int index);//Удаление столбца в массиве по указанному индексу



void main()
{
	setlocale(LC_ALL, "");
	
	int rows;
	int cols;
	int index;
	cout << "Введите количество строк :"; cin >> rows;
	cout << "Введите количество элементов строки :"; cin >> cols;
	int** arr = new int* [rows];
	Allocate(arr, rows, cols);
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
void Allocate(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) arr[i] = new int[cols] {};
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) cout << arr[i][j]<<TAB;
		cout << endl;
	}
	cout << endl;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++) delete[] arr[i];
	delete[] arr;
}
void FillRand_arr(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) arr[i][j] = rand() % 100;
}
void FillRand_row(int** arr, const int row, const int cols)
{
	for (int i = 0; i < cols; i++) arr[row][i] = rand() % 100;
}
void FillRand_col(int** arr, const int rows, const int col)
{
	for (int i = 0; i < rows; i++) arr[i][col] = rand() % 100;
}

void push_row_back(int**&arr, int& rows, const int cols)
{
	cout << "Вставляем строку в конец массива" << endl;
	int** bufer = new int* [rows+1];
	Allocate(bufer, rows+1, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) bufer[i][j] = arr[i][j];
	Clear(arr, rows);
	FillRand_row(bufer, rows,cols);
	rows++;
	arr = bufer;
}
void push_row_front(int**& arr, int& rows, const int cols)
{
	cout << "Вставляем строку в начало массива"<< endl;
	int** bufer = new int* [rows + 1];
	Allocate(bufer, rows + 1, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) bufer[i+1][j] = arr[i][j];
	Clear(arr, rows);
	FillRand_row(bufer, rows-rows, cols);
	rows++;
	arr = bufer;
}
void insert_row(int**& arr, int& rows, const int cols, const int index)
{
	cout << "Вставляем строку в массив по индексу "<<index << endl;
	int** bufer = new int* [rows+1];
	Allocate(bufer, rows+1, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) (i < index ? bufer[i][j] : bufer[i + 1][j]) = arr[i][j];
	Clear(arr, rows);
	FillRand_row(bufer, index, cols);
	rows++;
	arr = bufer;
}
void pop_row_back(int**& arr, int& rows, const int cols)
{
	cout << "Удаляем последнюю строку из массива" << endl;
	int** bufer = new int* [rows - 1];
	Allocate(bufer, rows - 1, cols);
	for (int i = 0; i < rows-1; i++) for (int j = 0; j < cols; j++) bufer[i][j] = arr[i][j];
	Clear(arr, rows);
	--rows;
	arr = bufer;
}
void pop_row_front(int**& arr, int& rows, const int cols)
{
	cout << "Удаляем нулевую строку из массива" << endl;
	int** bufer = new int* [rows - 1];
	Allocate(bufer, rows - 1, cols);
	for (int i = 0; i < rows-1; i++) for (int j = 0; j < cols; j++) bufer[i][j] = arr[i+1][j];
	Clear(arr, rows);
	--rows;
	arr = bufer;
}
void erase_row(int**& arr, int& rows, const int cols, const int index)
{
	cout << "Удаляем строку из массива по индексу "<<index << endl;
	int** bufer = new int* [rows - 1];
	Allocate(bufer, rows - 1, cols);
	for (int i = 0; i < rows-1; i++) for (int j = 0; j < cols; j++) i < index ? bufer[i][j] = arr[i][j] : bufer[i][j] = arr[i+1][j];
	Clear(arr, rows);
	--rows;
	arr = bufer;
}

void push_col_back(int**& arr, const int rows, int& cols)
{
	cout << "Добавляем столбец в конец массива" << endl;
	int** bufer = new int* [rows];
	Allocate(bufer, rows, cols+1);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) bufer[i][j] = arr[i][j];
	Clear(arr, rows);
	FillRand_col(bufer, rows, cols);
	cols++;
	arr = bufer;

}
void push_col_front(int**& arr, const int rows, int& cols)
{
	cout << "Добавляем столбец в начало массива" << endl;
	int** bufer = new int* [rows];
	Allocate(bufer, rows, cols + 1);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) bufer[i][j+1] = arr[i][j];
	Clear(arr, rows);
	FillRand_col(bufer, rows, cols-cols);
	cols++;
	arr = bufer;

}
void insert_col(int**& arr, const int rows, int& cols, const int index)
{
	cout << "Вставляем столбец в массив по индексу " << index << endl;
	int** bufer = new int* [rows];
	Allocate(bufer, rows, cols+1);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) (j < index ? bufer[i][j] : bufer[i][j+1])=arr[i][j];
	Clear(arr, rows);
	FillRand_col(bufer, rows, index);
	cols++;
	arr = bufer;

}
void pop_col_back(int**& arr, const int rows, int& cols)
{
	cout << "Удаление последнего столбца из массива" << endl;
	int** bufer = new int* [rows];
	Allocate(bufer, rows, --cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) bufer[i][j] = arr[i][j];
	Clear(arr, rows);
	arr = bufer;
}
void pop_col_front(int**& arr, const int rows, int& cols)
{
	cout << "Удаление нулевого столбца из массива" << endl;
	int** bufer = new int* [rows];
	Allocate(bufer, rows, --cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) bufer[i][j] = arr[i][j+1];
	Clear(arr, rows);
	arr = bufer;

}
void erase_col(int**& arr, const int rows, int& cols, const int index)
{
	cout << "Удаление столбца из массива по идексу " << index << endl;
	int** bufer = new int* [rows];
	Allocate(bufer, rows, --cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) j < index ? bufer[i][j] = arr[i][j] : bufer[i][j] = arr[i][j+1];
	Clear(arr, rows);
	arr = bufer;
}