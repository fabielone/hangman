#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>


void delay(int delay)
{
	Sleep(delay);
	
}
// Funcion para posicionar el cursor en la posicion  x, y de la pantalla
void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Imprime un texto en la columna c y el renglon r  de la pantalla
void PonTextoXY(short c, short r, char *Texto)
{
	gotoxy(c, r);
	printf("%s", Texto);
}

void PonTextoXYANIMADO(short c, short r, char *Texto)
{
	int l = strlen(Texto);
	char *arra = Texto;
	;

	for (int i = 0; i < l; i++)
	{
		gotoxy(c + i, r);
		printf("%c\n", arra[i]);
		delay(1);
	}
	gotoxy(c, r);
	printf("%s", Texto);
}

void errasePonTextoXYdelay(short c, short r, char *Texto)
{
	int l = strlen(Texto);
	char *arra = Texto;
	;

	for (int i = 0; i < l; i++)
	{
		gotoxy(c + i, r);
		printf(" \n");
		delay(1);
	}
}

void errasePonTextoXY(short c, short r, char *Texto)
{
	int l = strlen(Texto);
	char *arra = Texto;
	;

	for (int i = 0; i < l; i++)
	{
		gotoxy(c + i, r);
		printf(" \n");
	}
}

void PonTextoCentradoPantalla(short r, char *Texto)
{
	PonTextoXY(40 - strlen(Texto) / 2, r, Texto);
}

void PonTextoCentradoPantallaDELAY(short r, char *Texto)
{

	PonTextoXYANIMADO(40 - strlen(Texto) / 2, r, Texto);
}

void PonTextoCentradoPantallaAnimadoVERT(short r, short r2, char *Texto)
{
	PonTextoXYANIMADO(40 - strlen(Texto) / 2, r2, Texto);
	errasePonTextoXY(40 - strlen(Texto) / 2, r2, Texto);

	for (int i = r2; i >= r; i = i - 2)
	{
		PonTextoXY(40 - strlen(Texto) / 2, i, Texto);
		delay(1);
		errasePonTextoXY(40 - strlen(Texto) / 2, i, Texto);
		delay(1);
	}

	PonTextoXY(40 - strlen(Texto) / 2, r, Texto);
}

void PonTextoCentradoRecuadro(short c1, short c2, short r, char *Texto)
{
	PonTextoXY((c2 - c1 + strlen(Texto)) / 2, r, Texto);
}

void ColorTexto(int Clr)
{
	HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Color, Clr);
}

void ColorRandom()
{
	int R[7] = {0, 31, 33, 34, 35, 36, 32};
	int Ra = rand() % 7;
	ColorTexto(R[Ra]);
}

void LineaHorizontal(short c1, short c2, short r, short tipo)
{
	short c;
	gotoxy(c1, r);
	printf("%c", 204);
	gotoxy(c2, r);
	printf("%c", 185);

	for (c = c1 + 1; c < c2; c++)
	{
		gotoxy(c, r);
		ColorRandom();
		printf("%c", 205);
		delay(1);
	}
	ColorTexto(33);
	gotoxy(c1, r);
	printf("%c", 204);
	gotoxy(c2, r);
	printf("%c", 185);

	for (c = c1 + 1; c < c2; c++)
	{
		gotoxy(c, r);

	    printf("%c", 205);
		delay(1);
	}
}

void LineaVertical(short r1, short r2, short c, short tipo)
{
	short r;
	gotoxy(c, r1);
	printf("%c", 203);
	gotoxy(c, r2);
	printf("%c", 202);

	for (r = r1 + 1; r < r2; r++)
		gotoxy(c, r);
	printf("\u2550");
}

void Recuadro(short c1, short r1, short c2, short r2, short Tipo)
{
	short c, r, ctwo = c2, rtwo = r2;

 gotoxy(c1, r1); printf("%c", 201);
    gotoxy(c2, r1); printf("%c", 187);
    gotoxy(c1, r2); printf("%c", 200);
    gotoxy(c2, r2); printf("%c", 188);

	for (c = c1 + 1; c < c2; c++)
	{
		gotoxy(c, r1);
		ColorRandom();
		printf("%c", 205);
		gotoxy(ctwo-- - 1, r2);
		ColorRandom();
		printf("%c", 205);
		delay(1);
	}

	for (r = r1 + 1; r < r2; r++)
	{
		gotoxy(c1, r);
		ColorRandom();
		printf("%c", 186);
		gotoxy(c2, rtwo-- - 1);
		ColorRandom();
		printf("%c", 186);
		delay(1);
	}
}

void RecuadroTextoCentrado(short c1, short r1, short c2, short r2, short Tipo, char *Texto)
{
	Recuadro(c1, r1, c2, r2, Tipo);
	PonTextoXY((c1 + c2) / 2 - strlen(Texto) / 2, r1, Texto);
}


