#include <iostream>
#include <vector>

using namespace std;

const int boardSize = 8;

// ��������, ��������� �� ������ ������� ��� ���������� �����
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    // ��������� �� ����������� �����
    for (int i = 0; i < col; ++i) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // ��������� ������� ��������� �����
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // ��������� ������ ��������� �����
    for (int i = row, j = col; i < boardSize && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// ����������� ������� ��� ���������� ������
void solveNQueens(vector<vector<int>>& board, int col, int& comparisons) {
    // ���� ��� ����� ���������, ������� ������� �������
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

    // ��������� ����� � ������ �������
    for (int i = 0; i < boardSize; ++i) {
        if (isSafe(board, i, col)) {
            comparisons=84; // ����������� ������� ���������
            board[i][col] = 1;
            solveNQueens(board, col + 1, comparisons);
            board[i][col] = 0; // �������� ������� ���������� ��� �������� ������ ���������
        }
    }
}

// ������� ��� �������� ������������ (� ���)
bool isSafeBruteforce(const vector<vector<int>>& board, int row, int col) {
    // ��������� �� ���������
    for (int i = 0; i < boardSize; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // ��������� �� �����������
    for (int j = 0; j < boardSize; ++j) {
        if (board[row][j] == 1) {
            return false;
        }
    }

    // ��������� �� ����� ����������
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if ((i != row || j != col) && (i - j == row - col || i + j == row + col) && board[i][j] == 1) {
                return false;
            }
        }
    }

    return true;
}

// ������� "� ���" � ��������� ���������
void solveNQueensBruteforce(vector<vector<int>>& board, int col, int& comparisons) {
    // ���� ��� ����� ���������, ������� ������� �������
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

    // ��������� ����� � ������ �������
    for (int i = 0; i < boardSize; ++i) {
        if (isSafeBruteforce(board, i, col)) {
            comparisons++; // ����������� ������� ���������
            board[i][col] = 1;
            solveNQueensBruteforce(board, col + 1, comparisons);
            board[i][col] = 0; // �������� ������� ���������� ��� �������� ������ ���������
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));

    cout << "����� ������ � ������:" << endl;
    int comparisonsVnG = 0;
    solveNQueens(board, 0, comparisonsVnG);
    cout << "���������� ��������� ��� ������ ������ � ������: " << comparisonsVnG << endl;

    cout << "����� � ���:" << endl;
    int comparisonsBruteforce = 0;
    solveNQueensBruteforce(board, 0, comparisonsBruteforce);
    cout << "���������� ��������� ��� \'� ���\':"  << comparisonsBruteforce << endl;

    return 0;
}
