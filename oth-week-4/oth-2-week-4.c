#include <stdio.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard)
{
    chessBoard[i * size + j] = 1;

    int di[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dj[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

    for (int k = 0; k < 8; k++)
    {
        int newi = i + di[k];
        int newj = j + dj[k];

        if (0 <= newi && newi < size && 0 <= newj && newj < size)
        {
            chessBoard[newi * size + newj] = 1;
        }
    }
}

int main()
{
    int size = 8;
    int chessBoard[size * size];
    int i, j;

    scanf("%d %d", &i, &j);

    koboImaginaryChess(i, j, size, chessBoard);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", chessBoard[i * size + j]);
        }
        printf("\n");
    }

    return 0;
}
