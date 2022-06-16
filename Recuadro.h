#include <stdio.h>
#include <windows.h>
#include <string.h>

void gotoxy(short x, short y);
void ponTextoCentrado(int ext,int y, char* palabra);
void recuadro(short l1,short a1,short l2,short a2);

void recuadro(short l1,short a1,short l2,short a2)
{
	char s[6] = "fruta";
	int i;
	for(i =l1; i<l2; i++)
	{
		gotoxy(i,a1);
		printf("%c",196);
		
		gotoxy(i,a2);
		printf("%c",196);
	}
		for(i =a1; i<a2; i++)
	{
		gotoxy(l1,i);
		printf("%c",179);
		
		gotoxy(l2,i);
		printf("%c",179);
	}
	gotoxy(l1,a1);
	printf("%c",218);
	gotoxy(l2,a1);
	printf("%c",191);
	gotoxy(l1,a2);
	printf("%c",192);
	gotoxy(l2,a2);
	printf("%c",217); 
	int ext = (l2+l1)/2;
	ponTextoCentrado(ext,a1,s);
}

void gotoxy(short x, short y)
{
	//controlador de nuestro objeto; la ventana
	 HANDLE ventana;
	 ventana= GetStdHandle(STD_OUTPUT_HANDLE);
	 //creamos objeto de las coordenadas dentro de las estructuras
	 COORD coordenadas;
	 coordenadas.X= x;
	 coordenadas.Y= y;
	 SetConsoleCursorPosition(ventana, coordenadas);
}
void ponTextoCentrado(int ext,int y, char* palabra)
{
	
	int longi = strlen("palabra");
	gotoxy((ext) - (longi/2) , y);
	printf("%s", palabra);
}
