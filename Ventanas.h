#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void gotoxy(short x, short y)                                                          
{
 printf("%c[%d;%df", 0x1B, y, x);
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
	//HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(Color, Clr);
}

void LineaHorizontal(short c1, short c2, short r, short tipo)
{
	short c;
	gotoxy(c1, r); printf("%c", 204);
    gotoxy(c2, r); printf("%c", 185);
    
    for (c=c1+1; c<c2; c++)
	{
	   	 gotoxy(c, r); printf("%c", 205);
	}
}

void LineaVertical(short r1, short r2, short c, short tipo )
{
	short r;
	gotoxy(c, r1); printf("%c", 203);
    gotoxy(c, r2); printf("%c", 202);
    
     for (r=r1+1; r<r2; r++)
	    gotoxy(c, r); printf("%c", 205);
}

void Recuadro(short c1, short r1, short c2, short r2, short Tipo)
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

}

void RecuadroTextoCentrado(short c1, short r1, short c2, short r2, short Tipo, char *Texto)
{  
  Recuadro(c1, r1, c2, r2, Tipo);  
  PonTextoXY((c1 + c2)/2 - strlen(Texto) / 2, r1, Texto);
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
  
     
  for (x=0; x<NumeroDeOpciones; x++)
     PonTextoCentradoPantalla( 8+x, Menu[x]);
 
  do
  {  
    gotoxy(64,8+x-1); scanf("%i",&Opcion);
    
    if(Opcion<1 || Opcion>NumeroDeOpciones-1)
     PonTextoCentradoPantalla(22, "La opcion esta fuera de rango");
  }  
  while(Opcion<1 || Opcion>NumeroDeOpciones-1);
  return Opcion;
}