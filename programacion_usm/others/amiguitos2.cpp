#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector< vector<int> > get_matrix(int rows, int columns) {
    vector<vector<int>> matrix(rows, vector<int>(columns) );

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Ingresa el elemento (" << (i+1) << ", " << (j+1) << "): ";
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

void print_matrix(vector<vector<int>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    cout << "|";
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "|" << endl;
  }
}

bool can_multiply(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
  int m1_cols = matrix1[0].size();
  int m2_rows = matrix2.size();
  return m1_cols == m2_rows;
}

vector<vector<int>> multiply_matrices(vector<vector<int>> matrix1, 
                                      vector<vector<int>> matrix2) {
  int m1_rows = matrix1.size();
  int m1_cols = matrix1[0].size();
  int m2_cols = matrix2[0].size();

  vector<vector<int>> product(m1_rows, vector<int>(m2_cols));

  for (int i = 0; i < m1_rows; i++) {
    for (int j = 0; j < m2_cols; j++) {
      int product_element = 0;
      for (int k = 0; k < m1_cols; k++) {
        product_element += matrix1[i][k] * matrix2[k][j];
      }
      product[i][j] = product_element;
    }
  }

  return product;
}

int main() {
    vector< vector<int> > first_matrix;
    vector< vector<int> > second_matrix;
    int rows_f, columns_f;
    int rows_s, columns_s;

    cout << "Ingresa el numero de filas de la primera matriz: ";
    cin >> rows_f;
    cout << "Ingresa el numero de columnas de la segunda matriz: ";
    cin >> columns_f;

    first_matrix = get_matrix(rows_f, columns_f);
    system("cls");

    cout << "Ingresa el numero de filas de la segunda matriz: ";
    cin >> rows_s;
    cout << "Ingresa el numero de columnas de la segunda matriz: ";
    cin >> columns_s;

    second_matrix = get_matrix(rows_s, columns_s);
    system("cls");

    cout << "Primera matriz: " << endl;
    print_matrix(first_matrix);
    cout << endl;

    cout << "Segunda matriz: " << endl;
    print_matrix(second_matrix);
    cout << endl;

    if(can_multiply(first_matrix, second_matrix)) {
        vector<vector<int>> product = multiply_matrices(first_matrix, second_matrix);
        cout << "Matriz Multiplicada: " << endl;
        print_matrix(product);
    } 
    else {
      cout << "Las matrices no se pueden multiplicar" << endl;
    }

    return 0;
}
