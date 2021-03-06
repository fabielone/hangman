#include <stdio.h>

#include "ventanas.h"

void clearportion(short c1, short r1, short c2, short r2);
char *renglonesvacios(char *Texto);
int endgame(int *score);
void intro();
void hangman(short wrong);
void tablero(short wrong, short correct);
void highscore(int score, char *name);
int menu();
void mensajes(char *mensaje, short clr);
char *palabra(short cate);
char *winorlose(int score, int score2);
void abcdario();
void underscore();

int engine(char *palabra, int highscore);

int main()
{
	system("clear");
	intro();
    

	//tablero(30, 30);

	char *pal = palabra(menu());

	highscore(40, "fernando");
	int score = engine(pal, 0);
	char *champ = winorlose(score, 0);
	int seguir = endgame(score);

	while (seguir == 1)

	{
		char *pal2 = palabra(2);
		highscore(score, champ);
		int score2 = engine(pal2, score);
		champ = winorlose(score2, score);
		score = score2;
		seguir = endgame(score);
	}

	printf("adios amigos");
}

void clearportion(short c1, short r1, short c2, short r2)
{

	for (int i = c1; i <= c2; i++)

	{
		for (int j = r1; j <= r2; j++)
		{
			gotoxy(i, j);
			printf(" \n");
			delay(10);
		}
	}
}

char *renglonesvacios(char *Texto)
{

	int charlength = strlen(Texto);
	char *stringy = malloc(sizeof(char) * charlength);

	for (int i = 0; i < charlength; i++)
	{
		strcat(stringy, "_");
	}
	stringy[charlength] = '\0';

	return stringy;
}

int engine(char *palabra, int highscore)

{

	char *string1 = renglonesvacios(palabra);

	PonTextoXYANIMADO(60,12,string1);
	//printf("%s\n", string1);
	//  printf("%s\n", palabra);
	char *s = palabra;
	char *alfabeto = "abcdefghijklmnopqrstuvwxyz";
	char *malas = renglonesvacios(alfabeto);
	PonTextoCentradoPantallaDELAY(19,alfabeto);
	//PonTextoCentradoPantallaAnimadoVERT(27, 19, alfabeto);
	//printf("%s", alfabeto);
	char c;

	int count = 0, correct = 0, wrong = 0;

	while (strcmp(string1, s) != 0 && wrong < 6)
	{
		gotoxy(1, 7);
		PonTextoXYANIMADO(45,15,"Ingresa una letra en minuscula: ");
		//printf("Ingresa una letra en minuscula: ");

		scanf(" %c%*c", &c);

		while (strchr(alfabeto, c) == NULL)
		{
			gotoxy(1, 7);
			printf("%c\n", c);
			mensajes("Letra no valida vuelva intentar: ", 31);
			

			scanf(" %c%*c", &c);
			printf("%c", c);
		}

		// verificar que la letra no hayga sido ingresada anterior mente

		if (strchr(string1, c) == NULL && strchr(malas, c) == NULL)
		{
			// si la letra esta en la palabra entonces agregar al renglon vacio
			if (strchr(s, c) != NULL)
			{
				for (int i = 0; i < strlen(s); i++)
				{
					if (s[i] == c)
					{
						int index;
						char *e;
						e = strchr(alfabeto, c);
						index = (int)(e - alfabeto);
						string1[i] = c;
						//gotoxy(1, 2);
						PonTextoXYANIMADO(60,12,string1);
						
						
						gotoxy(index + 27, 19);
						ColorTexto(32);
						printf("%c", c);
						ColorTexto(0);
						correct++;
						count++;
					}
				}
			}
			// de lo contrario agregar palabra a string malas y wrong++
			else if (strchr(s, c) == NULL)
			{
				int index;
				char *e;

				e = strchr(alfabeto, c);
				index = (int)(e - alfabeto);
				malas[index] = c;
				wrong++;
				gotoxy(60, 6);
				printf("wrongs:%d\n", wrong);
				gotoxy(index + 27, 19);
				ColorTexto(31);
				printf("%c", c);
				ColorTexto(0);
			}
		}
		else
		{
			gotoxy(6, 1);
			mensajes("Ya ingresastes esa letra \n", 31);
			
		}
	}

	return 2400 - wrong * 400;
}

int endgame(int *score)

{

	char *pregunta, *respuestas[] = {"yes", "y", "Y", "no", "n", "N"};
	printf("Quieres volver a jugar y/n?\n");
	scanf("%s", pregunta);

	while (strcmp(pregunta, respuestas[0]) && strcmp(pregunta, respuestas[1]) && strcmp(pregunta, respuestas[2]) && strcmp(pregunta, respuestas[3]) && strcmp(pregunta, respuestas[4]) && strcmp(pregunta, respuestas[5]))
	{
		printf("No te entendi .. Quieres volver a jugar y/n?\n");
		scanf("%s%*c", pregunta);
	}

	if (!strcmp(pregunta, respuestas[0]) || !strcmp(pregunta, respuestas[1]) || !strcmp(pregunta, respuestas[2]))
	{

		return 1;
	}

	else
	{
		return 0;
	}
}

int menu()
{
	int opc;

	RecuadroTextoCentrado(24, 7, 56, 15, 35, "[MENU]");
	// Textos Del menu
	ColorTexto(0);
	PonTextoCentradoPantallaDELAY(9, "FRUTAS-----------[1]");
	PonTextoCentradoPantallaDELAY(10, "PAISES-----------[2]");
	PonTextoCentradoPantallaDELAY(11, "DEPORTES---------[3]");
	PonTextoCentradoPantallaDELAY(12, "SALIR------------[4]");
	PonTextoCentradoPantallaDELAY(13, "Selecciona-------[ ]");
	// Escaner el numero de opcion

	gotoxy(48, 13);

	do
	{
		gotoxy(48, 13);

		if (scanf(" %d%*c", &opc) == 1 && (opc >= 1 && opc <= 4))
		{

			clearportion(24, 7, 56, 15);
			return opc;
		}
		else
		{
			mensajes("opcion no valida", 31);
			gotoxy(48, 13);
		}
	} while (opc < 1 || opc > 4);
	// El salto para que no se coma el cuadro el mensaje de abajo
}

void mensajes(char *mensaje, short clr)
{

	clearportion(2, 21, 80, 21);
	ColorTexto(clr);
	PonTextoCentradoPantallaDELAY(21, mensaje);
	ColorTexto(0);
}

void intro()
{

	system("clear");
	// Este es el cuadro principal
	Recuadro(1, 1, 82, 22, 32);
	Recuadro(1, 1, 82, 22, 33);
	Recuadro(1, 1, 82, 22, 35);
	// Los textos centrados en el cuadro
	LineaHorizontal(1, 82, 3, 35);
	LineaHorizontal(1, 82, 20, 35);
	ColorTexto(33);
	PonTextoCentradoPantallaAnimadoVERT(2, 10, "Juego Del Horcado");

	PonTextoCentradoPantallaDELAY(20, "[MENSAJES]");
	// El cuando del menu de la primera interfaz
	Recuadro(24, 7, 56, 15, 35);
};
void hangman(short wrong){};
void tablero(short wrong, short correct){

};
void highscore(int score, char *name)
{
	char str[4];
	sprintf(str, "%d", score);
	//clearportion(4, 50, 4, 80);
	//gotoxy(50, 4);
	PonTextoXYANIMADO(50, 4, "High Score ");
	PonTextoXYANIMADO(62, 4, str);
	PonTextoXYANIMADO10(67, 4, name);
};
char *palabra(short cate)
{


	char *palabra;
	int numPalabra;
	srand(time(NULL));
	numPalabra=rand()%20;
	
	switch(cate)
	{
		case 1:
			{
				char *Frutas[20] = {"naranja", "toronja", "aguacate", "cereza", "ciruela", "manzana", "platano", "sanddia", "nectarina","melocoton", "mango", "durazno", "granada", "mandarina", "zarzamora", "pera", "pina", "papaya", "maracuya", "mandarina"};
				palabra=Frutas[numPalabra];
				break;
			}
		case 2:
			{
				char *Paises[20]={"mexico", "argentina", "estados unidos", "venezuela", "rusia", "ucrania", "guatemala", "trinidad y tobago", "el salvador", "paraguay", "colombia", "canada", "costa Rica", "peru", "brazil", "japon", "corea del sur", "corea del norte", "madagascar","nicaragua"};
				palabra=Paises[numPalabra];
				break;
			}
		case 3:
			{
				char* Deportes[20]={"natacion", "parapente", "montanismo", "atletismo", "futbol", "tenis", "ajedrez", "motociclismo", "salto largo", " gimnasia ritmica", "boxeo", "basquetbol", "tiro al arco", "skate", "snowboard", " ciclismo de ruta", " escalada", "golf", "balonmano", "esgrima"};
			    palabra=Deportes[numPalabra];
			}
	}
	return palabra;



	
};

char *winorlose(int score, int score2)
{

	if (score == 0)
	{
		printf("perdistes");
	}
	else
	{
		printf("ganastes obtubistes el highscore");
	}

	return "win";
}
