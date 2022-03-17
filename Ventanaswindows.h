#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

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
		delay(20);
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
		delay(20);
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
		delay(100);
		errasePonTextoXY(40 - strlen(Texto) / 2, i, Texto);
		delay(100);
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
	printf("\u2551");
	gotoxy(c2, r);
	printf("\u2551");

	for (c = c1 + 1; c < c2; c++)
	{
		gotoxy(c, r);
		ColorRandom();
		printf("\u2550\n");
		delay(10);
	}
	ColorTexto(33);
	gotoxy(c1, r);
	printf("\u2551");
	gotoxy(c2, r);
	printf("\u2551");

	for (c = c1 + 1; c < c2; c++)
	{
		gotoxy(c, r);

		printf("\u2550\n");
		delay(10);
	}
}

void LineaVertical(short r1, short r2, short c, short tipo)
{
	short r;
	gotoxy(c, r1);
	printf("\u2550");
	gotoxy(c, r2);
	printf("%c", 202);

	for (r = r1 + 1; r < r2; r++)
		gotoxy(c, r);
	printf("\u2550");
}

void Recuadro(short c1, short r1, short c2, short r2, short Tipo)
{
	short c, r, ctwo = c2, rtwo = r2;

	gotoxy(c1, r1);
	printf("\u2554");

	gotoxy(c2, r1);
	printf("\u2557");

	gotoxy(c1, r2);
	printf("\u255A");

	gotoxy(c2, r2);
	printf("\u255D");

	for (c = c1 + 1; c < c2; c++)
	{
		gotoxy(c, r1);
		ColorRandom();
		printf("\u2550\n");
		gotoxy(ctwo-- - 1, r2);
		ColorRandom();
		printf("\u2550\n");
		delay(10);
	}

	for (r = r1 + 1; r < r2; r++)
	{
		gotoxy(c1, r);
		ColorRandom();
		printf("\u2551\n");
		gotoxy(c2, rtwo-- - 1);
		ColorRandom();
		printf("\u2551\n");
		delay(10);
	}
}

void RecuadroTextoCentrado(short c1, short r1, short c2, short r2, short Tipo, char *Texto)
{
	Recuadro(c1, r1, c2, r2, Tipo);
	PonTextoXY((c1 + c2) / 2 - strlen(Texto) / 2, r1, Texto);
}

short MenuMetodosNumericos(char *Menu[], short NumeroDeOpciones, char *Texto)
{
	short Opcion, x;

	system("cls");

	Recuadro(1, 1, 80, 24, 1);
	LineaHorizontal(1, 80, 3, 1);
	PonTextoCentradoPantalla(2, "Sistema para soluciones numericas");
	PonTextoCentradoPantalla(6, Texto);
	LineaHorizontal(1, 80, 21, 1);
	PonTextoCentradoPantalla(21, " Mensajes ");

	for (x = 0; x < NumeroDeOpciones; x++)
		PonTextoCentradoPantalla(8 + x, Menu[x]);

	do
	{
		gotoxy(64, 8 + x - 1);
		scanf("%hi", &Opcion);

		if (Opcion < 1 || Opcion > NumeroDeOpciones - 1)
			PonTextoCentradoPantalla(22, "La opcion esta fuera de rango");
	} while (Opcion < 1 || Opcion > NumeroDeOpciones - 1);
	return Opcion;
}