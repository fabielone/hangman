#include "Ventanas.h"

int main()
{
	system("clear");

	Recuadro(1, 1, 82, 22,1);
	
	LineaHorizontal(1, 82, 4,2);
	//PonTextoCentradoRecuadro(1,46, 1,"[Juego del ahorcado]");
	LineaHorizontal(1, 82, 20,2);	
	PonTextoCentradoPantalla(2,"Juego del Ahoracado");
	
	scanf("%d");
}
