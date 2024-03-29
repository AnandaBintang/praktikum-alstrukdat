#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int card_value(char card)
{
    if (card >= '2' && card <= '9')
    {
        return card - '0';
    }
    else if (card == 'J' || card == 'j')
    {
        return 11;
    }
    else if (card == 'Q' || card == 'q')
    {
        return 12;
    }
    else if (card == 'K' || card == 'k')
    {
        return 13;
    }
    return 0;
}

int bubble_sort(char cards[], int n)
{
    int i, j;
    int steps = 0;
    int swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (card_value(cards[j]) > card_value(cards[j + 1]))
            {
                char temp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = temp;
                steps++;
                swapped = 1;
                printf("Swap %d = ", steps);
                for (int k = 0; k < n; k++)
                {
                    printf("%c ", cards[k]);
                }
                printf("\n");
            }
        }

        if (swapped == 0)
            break;
    }
    return steps;
}

int main()
{
    int n;
    printf("Masukkan jumlah kartu: ");
    scanf("%d", &n);

    char *cards = (char *)malloc(n * sizeof(char));

    printf("Masukkan nilai kartu (dipisahkan dengan spasi): ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &cards[i]);
    }

    int steps = bubble_sort(cards, n);
    printf("\nJumlah minimal langkah pertukaran: %d\n", steps);

    free(cards);

    return 0;
}
