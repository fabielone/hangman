#include <stdio.h>
#include <stdlib.h>
#include "Ventanas.h"


int main(void)
{
    int num;

    system("clear");
    gotoxy(1, 1);


     printf("\u2554");

    gotoxy(80, 1);

    printf("\u2557");

    gotoxy(1, 24);

    printf("\u255A");

    gotoxy(80, 24);

    printf("\u255D");

    for (int a = 2; a < 24; a++)
    {
        gotoxy(1, a);
        printf("\u2551");
        gotoxy(80, a);
        printf("\u2551");
    }

    for (int i = 2; i < 80; i++)
    {
        gotoxy(i, 1);
        printf("\u2550");
        gotoxy(i, 24);
        printf("\u2550");
    }

    for (int a = 2; a < 24; a++)
    {
        gotoxy(3, a);
        printf("\u2551");
        gotoxy(78, a);
        printf("\u2551");
    }

    for (int i = 2; i < 80; i++)
    {
        gotoxy(i, 2);
        printf("\u2550");
        gotoxy(i, 22);
        printf("\u2550");
    }

    gotoxy(24, 1);
    printf("hello");
    gotoxy(25, 1);
    printf("hello");

    gotoxy(24, 2);
    printf("hello");
    gotoxy(1, 25);
    printf("\n ");

    scanf("%d", &num);
    
	//ola, te hice leer :)
    return 0;
}
