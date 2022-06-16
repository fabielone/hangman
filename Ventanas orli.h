#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

// Funcion para posicionar el cursor en la posicion  x, y de la pantalla
void gotoxy(short x, short y)
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Imprime un texto en la columna c y el renglon r  de la pantalla
void PonTextoXY(short c, short r, char *Texto)
{
  gotoxy(c, r);
  printf("%s", Texto);
}

void PonTextoCentradoPantalla(short r, char *Texto)
{
  PonTextoXY(40 - strlen(Texto) / 2, r, Texto);
}

void PonTextoCentradoRecuadro(short c1, short c2, short r, char* Texto)
{
  PonTextoXY((c2-c1 + strlen(Texto)) / 2, r, Texto);
}


void ColorTexto(int Clr)
{
	HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Color, Clr);
}

void LineaHorizontal(short c1, short c2, short r)
{
	short c;
	gotoxy(c1, r); printf("%c", 204);
    gotoxy(c2, r); printf("%c", 185);

    for (c=c1+1; c<c2; c++)
	{
	   	 gotoxy(c, r); printf("%c", 205);
	}

}

void LineaVertical(short r1, short r2, short c )
{
	short r;
	gotoxy(c, r1); printf("%c", 203);
    gotoxy(c, r2); printf("%c", 202);

     for (r=r1+1; r<r2; r++){

	    gotoxy(c, r); printf("%c", 205);
	    }

}
void Recuadro(short c1, short r1, short c2, short r2)
{
    short c, r;

    gotoxy(c1, r1); printf("%c", 201);
    gotoxy(c2, r1); printf("%c", 187);
    gotoxy(c1, r2); printf("%c", 200);
    gotoxy(c2, r2); printf("%c", 188);

    for (c=c1+1; c<c2; c++)
	{
	    gotoxy(c, r1); printf("%c", 205);
	    gotoxy(c, r2); printf("%c", 205);
	}

    for (r=r1+1; r<r2; r++)
	{
	    gotoxy(c1, r); printf("%c", 186);
	    gotoxy(c2, r); printf("%c", 186);
	}
	printf("\n");
}

void RecuadroTextoCentrado(short c1, short r1, short c2, short r2, char *Texto)
{
  Recuadro(c1, r1, c2, r2);
  PonTextoXY((c1 + c2)/2 - strlen(Texto) / 2, r1, Texto);
}
