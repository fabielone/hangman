#include <stdio.h>
#include "ventanas.h"

int InterfazInicio();

int main()
{
	InterfazInicio();
	// Interfaz General

	//

	system("cls");

	return 0;
}

int InterfazInicio(void)
{
	int opc;
	// Este es el cuadro principal
	Recuadro(0, 0, 82, 22, 2);
	// Recuadro(1, 1, 82, 22, 2);
	// Recuadro(1, 1, 82, 22, 2);
	//  Los textos centrados en el cuadro
	LineaHorizontal(0, 82, 3, 2);
	LineaHorizontal(0, 82, 20, 2);
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
	PonTextoCentradoPantallaDELAY(13, "Selecciona-------[ ]");
	// Escaner el numero de opcion
	do
	{
		gotoxy(48, 13);
		scanf("%d", &opc);
		// if(opc==4)
		//{
		//	return 0;
		// }
		if (opc < 1 || opc > 4)
		{
			PonTextoCentradoPantallaDELAY(21, "OPCION NO VALIDA");
		}
	} while (opc < 1 || opc > 4);
	// El salto para que no se coma el cuadro el mensaje de abajo
	scanf("%d");
	return opc;
}
