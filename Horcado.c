#include <stdio.h>

#include "ventanas.h"

int main()
{

	system("clear");
	// Este es el cuadro principal
	Recuadro(1, 1, 82, 22, 2);
	Recuadro(1, 1, 82, 22, 2);
	Recuadro(1, 1, 82, 22, 2);
	// Los textos centrados en el cuadro
	LineaHorizontal(1, 82, 3, 2);
	LineaHorizontal(1, 82, 20, 2);
	PonTextoCentradoPantallaAnimadoVERT(2, 10, "Juego Del Horcado");
	// PonTextoCentradoPantalla(2, "JUEGO DEL HORCADO");
	PonTextoCentradoPantallaDELAY(20, "[MENSAJES]");
	// El cuando del menu de la primera interfaz
	Recuadro(24, 7, 56, 15, 2);
	RecuadroTextoCentrado(24, 7, 56, 15, 2, "[MENU]");
	// Textos Del menu
	PonTextoCentradoPantallaDELAY(9, "FRUTAS-----------[1]");
	PonTextoCentradoPantallaDELAY(10, "PAISES-----------[2]");
	PonTextoCentradoPantallaDELAY(11, "DEPORTES---------[3]");
	PonTextoCentradoPantallaDELAY(12, "SALIR------------[4]");
	Recuadro(1, 1, 82, 22, 2);
	Recuadro(1, 1, 82, 22, 2);
	// Escaner el numero de opcion

	// El salto para que no se coma el cuadro el mensaje de abajo
	scanf("%d");
	return 0;
}
