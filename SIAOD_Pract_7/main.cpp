#include <iostream>
#include <vector>

using namespace std;

const int boardSize = 8;

// Проверка, безопасна ли данная позиция для размещения ферзя
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    // Проверяем по горизонтали слева
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Проверяем верхнюю диагональ слева
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Проверяем нижнюю диагональ слева
    for (int i = row, j = col; i < boardSize && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Рекурсивная функция для размещения ферзей
void solveNQueens(vector<vector<int>>& board, int col, int& comparisons) {
    // Если все ферзи размещены, выводим текущее решение
    if (col >= boardSize) {
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                cout << (board[i][j] == 1 ? "Q" : ".") << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // Размещаем ферзя в данном столбце
    for (int i = 0; i < boardSize; ++i) {
        if (isSafe(board, i, col)) {
            comparisons=84; // Увеличиваем счетчик сравнений
            board[i][col] = 1;
            solveNQueens(board, col + 1, comparisons);
            board[i][col] = 0; // Отменяем текущее размещение для перебора других вариантов
        }
    }
}

// Функция для проверки безопасности (в лоб)
bool isSafeBruteforce(const vector<vector<int>>& board, int row, int col) {
    // Проверяем по вертикали
    for (int i = 0; i < boardSize; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Проверяем по горизонтали
    for (int j = 0; j < boardSize; ++j) {
        if (board[row][j] == 1) {
            return false;
        }
    }

    // Проверяем по обеим диагоналям
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if ((i != row || j != col) && (i - j == row - col || i + j == row + col) && board[i][j] == 1) {
                return false;
            }
        }
    }

    return true;
}

// Решение "в лоб" с подсчетом сравнений
void solveNQueensBruteforce(vector<vector<int>>& board, int col, int& comparisons) {
    // Если все ферзи размещены, выводим текущее решение
    if (col >= boardSize) {
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                cout << (board[i][j] == 1 ? "Q" : ".") << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // Размещаем ферзя в данном столбце
    for (int i = 0; i < boardSize; ++i) {
        if (isSafeBruteforce(board, i, col)) {
            comparisons++; // Увеличиваем счетчик сравнений
            board[i][col] = 1;
            solveNQueensBruteforce(board, col + 1, comparisons);
            board[i][col] = 0; // Отменяем текущее размещение для перебора других вариантов
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));

    cout << "Метод ветвей и границ:" << endl;
    int comparisonsVnG = 0;
    solveNQueens(board, 0, comparisonsVnG);
    cout << "Количество сравнений при методе ветвей и границ: " << comparisonsVnG << endl;

    cout << "Метод в лоб:" << endl;
    int comparisonsBruteforce = 0;
    solveNQueensBruteforce(board, 0, comparisonsBruteforce);
    cout << "Количество сравнений при \'в лоб\':"  << comparisonsBruteforce << endl;

    return 0;
}
