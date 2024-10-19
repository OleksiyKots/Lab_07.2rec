#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo);
void CreateRows(int** a, const int k, const int n, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int N, int colNo);
void PrintRows(int** a, const int k, const int n, int rowNo);
void FindMaxMinInRow(int* row, int n, int& maxIndex, int& minIndex, int j);
void SwapMaxMinInEvenRows(int** a, const int k, const int n, int rowNo);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int k, n;
    cout << "Enter number of rows (k): "; cin >> k;
    cout << "Enter number of columns (n): "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    // ��������� �� ��������� ��������� �������
    CreateRows(a, k, n, Low, High, 0);
    cout << "Original matrix:" << endl;
    PrintRows(a, k, n, 0);

    // ����� ������������� �� ���������� �������� � ������ ������
    SwapMaxMinInEvenRows(a, k, n, 0);
    cout << "Modified matrix:" << endl;
    PrintRows(a, k, n, 0);

    // �������� ���'��
    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// ���������� ��������� �����
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

// ���������� ��������� ��� �����
void CreateRows(int** a, const int k, const int n, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < k - 1)
        CreateRows(a, k, n, Low, High, rowNo + 1);
}

// ���������� ��������� �����
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

// ���������� ��������� ��� �����
void PrintRows(int** a, const int k, const int n, int rowNo)
{
    PrintRow(a, rowNo, n, 0);
    if (rowNo < k - 1)
        PrintRows(a, k, n, rowNo + 1);
}

// ����������� ����� ������������� � ���������� �������� � �����
void FindMaxMinInRow(int* row, int n, int& maxIndex, int& minIndex, int j)
{
    if (row[j] > row[maxIndex])
        maxIndex = j;
    if (row[j] < row[minIndex])
        minIndex = j;

    if (j < n - 1)
        FindMaxMinInRow(row, n, maxIndex, minIndex, j + 1);
}

// ���������� ����� ������������� � ���������� �������� � ������ ������
void SwapMaxMinInEvenRows(int** a, const int k, const int n, int rowNo)
{
    if (rowNo < k) {
        if (rowNo % 2 == 0) {  // ��� ������ �����
            int maxIndex = 0, minIndex = 0;
            FindMaxMinInRow(a[rowNo], n, maxIndex, minIndex, 1);
            swap(a[rowNo][maxIndex], a[rowNo][minIndex]);
        }
        SwapMaxMinInEvenRows(a, k, n, rowNo + 1);
    }
}
