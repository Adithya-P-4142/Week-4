

#include <iostream>
using namespace std;

class matrix {
private:
    int rows, cols;
    int **data;

public:
    matrix(int m, int n) {
        rows = m;
        cols = n;
        data = new int*[rows];

        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;
            }
        }
    }

    matrix(const matrix& other) {
        rows = other.rows;
        cols = other.cols;
        data = new int*[rows];

    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

void setElement(int i, int j, int value) {
    data[i][j] = value;
}

void display() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

~matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
    cout << "matrix memory released" << endl;
}
};

int main() {
    matrix A(2, 3);
    A.setElement(0, 0, 10);
A.setElement(0, 1, 20);
A.setElement(0, 2, 30);
A.setElement(1, 0, 40);
A.setElement(1, 1, 50);
A.setElement(1, 2, 60);

cout << "Original matrix:" << endl;
A.display();

matrix B = A;

cout << "Copied matrix:" << endl;
B.display();

return 0;
}