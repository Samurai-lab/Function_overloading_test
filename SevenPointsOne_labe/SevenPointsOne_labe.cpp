#include <iostream>
using namespace std;

int** arrFilling(int** arr, int rows, int cols) {
   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 50;
        }
    }
    return arr;
}

int* arrFilling(int* arr, int lenght) {
    cout << "Ввод элементов массива: \n";
    int a = 0;
    for (int i = 0; i < lenght; i++) {
        cin >> a;
        arr[i] = a;
    }
    return arr;
}

void arrOutput(int** arr, int rows, int cols) {
    cout << "\nДвумерный массив: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "_________________________\n";
}

void arrOutput(int* arr, int lenght) {
    cout << "\nОдномерный массив: \n";
        for (int i = 0; i < lenght; i++) {
            cout << arr[i] << " ";
        }
    cout << "\n_________________________\n";
}

int** arrOperations(int** arr, int rows, int cols) {
    int** arrTwo = new int* [rows - rows/2];
    for (int i = 0; i < rows - rows / 2; i++) {
        arrTwo[i] = new int[cols];
    }

    for (int i = 0, ii = 0; i < rows; i = i + 2, ii++) {
        for (int j = 0; j < cols; j++) {
            arrTwo[ii][j] = arr[i][j];
        }
    }
    arrOutput(arrTwo, rows - rows / 2, cols);
    return arrTwo;
}


int* arrOperations(int* arr, int lenght) {
    int count = 0;
    
    int j = 0;
    for (int i = 0; i < lenght; i++) {
        if (arr[i] == 0 && count <= 1) {
            count++;
            cout << arr[i] << " " << count << endl;
        }
        else if (count == 2 || count == 0) {
            count = 0;
            cout << arr[i] << " " << count << endl;
            j++;
        }
    }
    count = 0;
    int* arrTwo = new int[j];
    for (int i = 0, g = 0; i < lenght && g < j;i++) {
        if (arr[i] == 0 && count <= 1) {
            count++;
        }
        else if (count == 2 || count == 0) {
            count = 0;
            arrTwo[g] = arr[i];
            g++;
        }
    }
    arrOutput(arrTwo, j);
    return arrTwo;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    int rows;
    int cols;

    cout << "Введите кол-во строк: ";
    cin >> rows;
    cout << "\nВведите количество столбцов: ";
    cin >> cols;

    int** testArrOne = new int* [rows];
    for (int i = 0; i < rows; i++) {
        testArrOne[i] = new int[cols];
    }

    arrFilling(testArrOne, rows, cols);
    arrOutput(testArrOne, rows, cols);
    arrOperations(testArrOne, rows, cols);

    for (int i = 0; i < rows - rows / 2; i++) {
        delete[] testArrOne[i];
    }
    delete[] testArrOne;

    int lenght;
    cout << "\nВведите длинну одномерного массива: ";
    cin >> lenght;

    int* testArrTwo = new int [lenght];
    
    arrFilling(testArrTwo, lenght);
    arrOutput(testArrTwo, lenght);
    arrOperations(testArrTwo, lenght);
}