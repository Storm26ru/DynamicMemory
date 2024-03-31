#include<iostream>
using namespace std;
#define TAB "\t "

void Allocate(int** arr, const int rows, const int cols);
void Randl_arr(int** arr, const int rows, const int cols);
void Randl_rows(int** arr, int row, const int cols);
void Print(int** arr, const int rows, const int cols);
void Clear(int** arr, const int rows);
void push_row_back(int**& arr,  int & rows, const int cols);
void push_row_front(int**& arr,  int & rows, const int cols);

void main()
{
	setlocale(LC_ALL, "");
	
	int rows;
	int cols;
	cout << "Введите количество строк :"; cin >> rows;
	cout << "Введите количество элементов строки :"; cin >> cols;
	int** arr = new int* [rows];
	Allocate(arr, rows, cols);
	Randl_arr(arr, rows, cols);
	Print(arr, rows, cols);
	push_row_back(arr, rows, cols);
	Print(arr, rows,cols);
	push_row_front(arr, rows, cols);
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
void Randl_rows(int** arr, int row, const int cols)
{
	for (int i = 0; i < cols; i++) arr[row][i] = rand() % 100;
}
void push_row_back(int**&arr, int& rows, const int cols)
{
	int** bufer = new int* [rows+1];
	Allocate(bufer, rows+1, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) bufer[i][j] = arr[i][j];
	Clear(arr, rows);
	Randl_rows(bufer, rows,cols);
	rows++;
	arr = bufer;
}
void push_row_front(int**& arr, int& rows, const int cols)
{
	int** bufer = new int* [rows + 1];
	Allocate(bufer, rows + 1, cols);
	for (int i = 0; i < rows; i++) for (int j = 0; j < cols; j++) bufer[i+1][j] = arr[i][j];
	Clear(arr, rows);
	Randl_rows(bufer, rows-rows, cols);
	rows++;
	arr = bufer;
	//Print(arr, rows,cols);
}