#include <iostream>
using namespace std;

class Matrix
{
private:
int mat[10][10];
int rows, cols;

public:

void input()  
{  
    cout << "Enter number of rows: ";  
    cin >> rows;  

    cout << "Enter number of columns: ";  
    cin >> cols;  

    cout << "Enter matrix elements:\n";  

    for (int i = 0; i < rows; i++)  
    {  
        for (int j = 0; j < cols; j++)  
        {  
            cin >> mat[i][j];  
        }  
    }  
}  

void display()  
{  
    for (int i = 0; i < rows; i++)  
    {  
        for (int j = 0; j < cols; j++)  
        {  
            cout << mat[i][j] << " ";  
        }  
        cout << endl;  
    }  
}  

bool sameSize(Matrix m)  
{  
    return (rows == m.rows && cols == m.cols);  
}  

Matrix add(Matrix m)  
{  
    Matrix result;  

    result.rows = rows;  
    result.cols = cols;  

    for (int i = 0; i < rows; i++)  
    {  
        for (int j = 0; j < cols; j++)  
        {  
            result.mat[i][j] = mat[i][j] + m.mat[i][j];  
        }  
    }  

    return result;  
}  

Matrix subtract(Matrix m)  
{  
    Matrix result;  

    result.rows = rows;  
    result.cols = cols;  

    for (int i = 0; i < rows; i++)  
    {  
        for (int j = 0; j < cols; j++)  
        {  
            result.mat[i][j] = mat[i][j] - m.mat[i][j];  
        }  
    }  

    return result;  
}  

Matrix multiply(Matrix m)  
{  
    Matrix result;  

    result.rows = rows;  
    result.cols = m.cols;  

    for (int i = 0; i < rows; i++)  
    {  
        for (int j = 0; j < m.cols; j++)  
        {  
            result.mat[i][j] = 0;  

            for (int k = 0; k < cols; k++)  
            {  
                result.mat[i][j] +=  
                    mat[i][k] * m.mat[k][j];  
            }  
        }  
    }  

    return result;  
}  

Matrix transpose()  
{  
    Matrix result;  

    result.rows = cols;  
    result.cols = rows;  

    for (int i = 0; i < rows; i++)  
    {  
        for (int j = 0; j < cols; j++)  
        {  
            result.mat[j][i] = mat[i][j];  
        }  
    }  

    return result;  
}  

int getRows()  
{  
    return rows;  
}  

int getCols()  
{  
    return cols;  
}

};

int main()
{
Matrix A, B, result;
int choice;

do  
{  
    cout << "\n====================================\n";  
    cout << "       MATRIX OPERATION SYSTEM\n";  
    cout << "====================================\n";  

    cout << "1. Matrix Addition\n";  
    cout << "2. Matrix Subtraction\n";  
    cout << "3. Matrix Multiplication\n";  
    cout << "4. Matrix Transpose\n";  
    cout << "5. Reset\n";  
    cout << "6. Exit\n";  

    cout << "Enter your choice: ";  
    cin >> choice;  

    if (choice == 1)  
    {  
        cout << "\nEnter Matrix A:\n";  
        A.input();  

        cout << "\nEnter Matrix B:\n";  
        B.input();  

        if (A.sameSize(B))  
        {  
            result = A.add(B);  

            cout << "\nResult of Matrix Addition:\n";  
            result.display();  
        }  
        else  
        {  
            cout << "\nError: Addition requires matrices "  
                 << "of the same size.\n";  
        }  
    }  

    else if (choice == 2)  
    {  
        cout << "\nEnter Matrix A:\n";  
        A.input();  

        cout << "\nEnter Matrix B:\n";  
        B.input();  

        if (A.sameSize(B))  
        {  
            result = A.subtract(B);  

            cout << "\nResult of Matrix Subtraction:\n";  
            result.display();  
        }  
        else  
        {  
            cout << "\nError: Subtraction requires matrices "  
                 << "of the same size.\n";  
        }  
    }  

    else if (choice == 3)  
    {  
        cout << "\nEnter Matrix A:\n";  
        A.input();  

        cout << "\nEnter Matrix B:\n";  
        B.input();  

        if (A.getCols() == B.getRows())  
        {  
            result = A.multiply(B);  

            cout << "\nResult of Matrix Multiplication:\n";  
            result.display();  
        }  
        else  
        {  
            cout << "\nError: Number of columns of Matrix A "  
                 << "must be equal to the number of rows "  
                 << "of Matrix B.\n";  
        }  
    }  

    else if (choice == 4)  
    {  
        cout << "\nEnter Matrix:\n";  
        A.input();  

        result = A.transpose();  

        cout << "\nTranspose of Matrix:\n";  
        result.display();  
    }  

    else if (choice == 5)  
    {  
        cout << "\nSystem has been reset.\n";  
    }  

    else if (choice == 6)  
    {  
        cout << "\nExiting Matrix Operation System...\n";  
    }  

    else  
    {  
        cout << "\nInvalid choice. Please try again.\n";  
    }  

} while (choice != 6);  

return 0;

}

