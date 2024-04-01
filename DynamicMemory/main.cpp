#include<iostream>
using namespace std;
#define TAB "\t "

void Allocate(int** arr, const int rows, const int cols);
void Randl_arr(int** arr, const int rows, const int cols);
void Randl_row(int** arr, const int row, const int cols);
void Print(int** arr, const int rows, const int cols);
void Clear(int** arr, const int rows);
void push_row_back(int**& arr,  int & rows, const int cols);
void push_row_front(int**& arr,  int & rows, const int cols);
void insert_row(int**& arr, int& rows, const int cols, const int index );
void pop_row_back(int**& arr,  int & rows, const int cols);
void pop_row_front(int**& arr,  int & rows, const int cols);
void erase_row(int**& arr, int& rows, const int cols, const int index );


void main()
{
	setlocale(LC_ALL, "");
	
	int rows;
	int cols;
	cout << "¬ведите количество строк :"; cin >> rows;
	cout << "¬ведите количество элементов строки :"; cin >> cols;
	int** arr = new int* [rows];
	Allocate(arr, rows, cols);
	Randl_arr(arr, rows, cols);
	Print(arr, rows, cols);
	push_row_back(arr, rows, cols);
	Print(arr, rows,cols);
	push_row_front(arr, rows, cols);
	Print(arr, rows,cols);
	int index;
	do
	{
		cout << "¬ведите индекс дл€ вставки строки в массив от 0 до " << rows - 1<<" "; cin >> index;
	} while (index>=rows);
	insert_row(arr, rows, cols, index);
	Print(arr, rows,cols);
	pop_row_back(arr, rows, cols);
	Print(arr, rows,cols);
	pop_row_front(arr, rows, cols);
	Print(arr, rows,cols);
	do
	{
		cout << "¬ведите индекс дл€ удаление строки из массив от 0 до " << rows - 1<<" "; cin >> index;
	} while (index>=rows);
	erase_row(arr, rows,cols,index);
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
void Randl_arr(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) arr[i][j] = rand() % 100;
}
void Randl_row(int** arr, const int row, const int cols)
{
	for (int i = 0; i < cols; i++) arr[row][i] = rand() % 100;
}
void push_row_back(int**&arr, int& rows, const int cols)
{
	int** bufer = new int* [rows+1];
	Allocate(bufer, rows+1, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) bufer[i][j] = arr[i][j];
	Clear(arr, rows);
	Randl_row(bufer, rows,cols);
	rows++;
	arr = bufer;
}
void push_row_front(int**& arr, int& rows, const int cols)
{
	int** bufer = new int* [rows + 1];
	Allocate(bufer, rows + 1, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) bufer[i+1][j] = arr[i][j];
	Clear(arr, rows);
	Randl_row(bufer, rows-rows, cols);
	rows++;
	arr = bufer;
}
void insert_row(int**& arr, int& rows, const int cols, const int index)
{
	int** bufer = new int* [rows+1];
	Allocate(bufer, rows+1, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) i < index ? bufer[i][j] = arr[i][j] : bufer[i + 1][j] = arr[i][j];
	Clear(arr, rows);
	Randl_row(bufer, index, cols);
	rows++;
	arr = bufer;
}
void pop_row_back(int**& arr, int& rows, const int cols)
{
	int** bufer = new int* [rows - 1];
	Allocate(bufer, rows - 1, cols);
	for (int i = 0; i < rows-1; i++) for (int j = 0; j < cols; j++) bufer[i][j] = arr[i][j];
	Clear(arr, rows);
	--rows;
	arr = bufer;
}
void pop_row_front(int**& arr, int& rows, const int cols)
{
	int** bufer = new int* [rows - 1];
	Allocate(bufer, rows - 1, cols);
	for (int i = 0; i < rows-1; i++) for (int j = 0; j < cols; j++) bufer[i][j] = arr[i+1][j];
	Clear(arr, rows);
	--rows;
	arr = bufer;
}
void erase_row(int**& arr, int& rows, const int cols, const int index)
{
	int** bufer = new int* [rows - 1];
	Allocate(bufer, rows - 1, cols);
	for (int i = 0; i < rows-1; i++) for (int j = 0; j < cols; j++) i < index ? bufer[i][j] = arr[i][j] : bufer[i][j] = arr[i+1][j];
	Clear(arr, rows);
	--rows;
	arr = bufer;
}