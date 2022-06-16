#include <stdio.h>
#include "ventanas.h"
#include "getch.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

void InterfazInicio();
void Esqueleto();
void Horca();
void Puntaje();
void abc();
void tachar(char *descarte);
void InterfazWinLose();
int Categorias(int op);
int Jugar(char *palabra);

int main()
{
  InterfazInicio();
  return 0;
}

void Esqueleto()
{
  Recuadro(1, 1, 80, 24, 12);
  LineaHorizontal(1, 80, 3, 12);
  LineaHorizontal(1, 80, 21, 12);
}

void InterfazInicio()
{
  int juego = 1;
  do // el ciclo while empieza desde aqui para que se repita el juego desde el inicio
  {
    system("clear");
    int op;
    Esqueleto();
    RecuadroTextoCentrado(20, 6, 60, 16, 12, "Categorias");
    PonTextoCentradoPantalla(2, "Juego del Ahorcado");
    PonTextoCentradoPantalla(21, " Mensajes ");
    PonTextoCentradoRecuadro(20, 60, 8, "Frutas...........[1]");
    PonTextoCentradoRecuadro(20, 60, 9, "Paises...........[2]");
    PonTextoCentradoRecuadro(20, 60, 10, "Deportes.........[3]");
    PonTextoCentradoRecuadro(20, 60, 11, "Exit.............[4]");
    PonTextoCentradoRecuadro(20, 60, 12, "Opcion.............");
    scanf("%d", &op);

    system("clear");
    Esqueleto();
    Horca();
    Categorias(op);

    scanf("%d", &juego); // este escan es el scan de la pantalla WinLose, solo que se pone aqui porque la variable que termina el juego es de aqui
  } while (juego == 1);
  system("clear");
  InterfazWinLose(3);
  gotoxy(0, 24);
  printf(" ");
  // este print solo es para que los numeros de cuando termina el codigo queden hasta abajo
}

void Horca()
{
  int i, j, salto;
  Esqueleto();
  for (i = 5; i < 19; i++)
  {
    gotoxy(i, 18);
    printf("%c", 178);
  }

  for (j = 18; j > 8; j = j - 1)
  {
    gotoxy(12, j);
    printf("%c", 178);
    gotoxy(11, j);
    printf("%c", 178);
  }

  for (i = 12; i < 22; i++)
  {
    gotoxy(i, 9);
    printf("%c", 178);
  }

  gotoxy(20, 10);
  printf("%c", 178);
  gotoxy(21, 10);
  printf("%c", 178);

  Puntaje();
  abc();
}

void Monito(int error) // aqui solamente es una funcion con un switch que dependiendo del num que reciba, imprime una parte del monito
{
  switch (error)
  {
  case 1:
    gotoxy(19, 11);
    printf("(%c_%c)\n", 158, 158);
    break;

  case 2:
    gotoxy(19, 12);
    printf("  |  \n");
    gotoxy(19, 13);
    printf("  |  \n");
    break;

  case 3:
    gotoxy(20, 12);
    printf("/");
    break;

  case 4:
    gotoxy(22, 12);
    printf("%c", 92); // debido a que la barra inversa no la imprime, tuve que usar ASCII paara poder imprimirlo
    break;

  case 5:
    gotoxy(20, 14);
    printf("/");
    break;

  case 6:
    gotoxy(22, 14);
    printf("%c", 92);
    break;
  }
}

void Puntaje(int aciertos, int error)
{
  int puntos;
  gotoxy(48, 4);
  printf("Ptos: %d, Aciertos: %d, Error: %d ", puntos, aciertos, error);
}

void abc()
{
  int i;
  gotoxy(15, 20);
  for (i = 97; i <= 122; i++)
  {
    printf("%c ", i);
  }
}

void tachar(char *descarte)
{
  int i;
  char *barra[125];
  gotoxy(15, 20);
  for (i = 97; i <= 122; i++)
  {
    if (descarte == i)
    {
      barra[i] = "/ ";
      printf("/ ");
    }
    else
    {
      printf("%c ", i);
      barra[i] = "%c", i;
    }
  }
}

void InterfazWinLose(int eleccion)
{
  Esqueleto();
  switch (eleccion) // aqui en lugar de un if, use un siwtch porque no me quería agarrar con ifs, idk why
  {
  case 1:
    PonTextoCentradoPantalla(5, "888     888 d8b          888                     d8b         ");
    PonTextoCentradoPantalla(6, "888     888 Y8P          888                     Y8P         ");
    PonTextoCentradoPantalla(7, "888     888              888                                 ");
    PonTextoCentradoPantalla(8, "Y88b   d88P 888  .d8888b 888888  .d88b.  888d888 888  8888b. ");
    PonTextoCentradoPantalla(9, " Y88b d88P  888 d88P     888    d88  88b 888P    888     88b ");
    PonTextoCentradoPantalla(10, "  Y88o88P   888 888      888    888  888 888     888 .d888888");
    PonTextoCentradoPantalla(11, "   Y888P    888 Y88b.    Y88b.  Y88..88P 888     888 888  888");
    PonTextoCentradoPantalla(12, "    Y8P     888  Y8888P   Y888    Y88P   888     888 Y888888 ");
    break;

  case 2:
    PonTextoCentradoPantalla(5, "8888888b.                        888  d8b           888             ");
    PonTextoCentradoPantalla(6, "888   Y88b                       888  Y8P           888             ");
    PonTextoCentradoPantalla(7, "888    888                       888                888             ");
    PonTextoCentradoPantalla(8, "888   d88P  .d88b.  888d888  .d88888  888  .d8888b  888888  .d88b.  ");
    PonTextoCentradoPantalla(9, "8888888P   d8P  Y8b 888P     d88 888  888  88K      888    d8P  Y8b ");
    PonTextoCentradoPantalla(10, "888        88888888 888     888  888  888  Y8888b.  888    88888888 ");
    PonTextoCentradoPantalla(11, "888        Y8b.     888     Y88b 888  888      X88  Y88b.  Y8b.     ");
    PonTextoCentradoPantalla(12, "888         Y8888   888       Y88888  888   88888P'  Y888   Y8888   ");
    break;

  case 3:
    PonTextoCentradoPantalla(5, "       d8888      888 d8b                           8888888b. ");
    PonTextoCentradoPantalla(6, "      d88888      888 Y8P                           888  Y88b ");
    PonTextoCentradoPantalla(7, "     d88P888      888                               888    888");
    PonTextoCentradoPantalla(8, "    d88P 888  .d88888 888  .d88b.  .d8888b     d8b  888    888");
    PonTextoCentradoPantalla(9, "   d88P  888 d88  888 888 d88  88b 88K         Y8P  888    888 ");
    PonTextoCentradoPantalla(10, "  d88P   888 888  888 888 888  888 Y8888b.          888    888");
    PonTextoCentradoPantalla(11, " d8888888888 Y88b 888 888 Y88..88P      X88    d8b  888  .d88P");
    PonTextoCentradoPantalla(12, "d88P     888   Y88888 888   Y88P    88888P     Y8P  8888888P  ");
    break;
  }
}

int Categorias(int op)
{
  int random;
  char Frutas[19][12] = {"fresa", "naranja", "platano", "aguacate", "carambola", "coco", "datil", "kiwi", "mango", "papaya", "pina", "melon", "sandia", "limon", "mandarina", "toronja", "arandano", "frambuesa", "zarzamora"};
  char Paises[19][12] = {"ucrania", "rusia", "espana", "mexico", "francia", "uruguay", "brasil", "argentina", "paraguay", "peru", "bolivia", "australia", "tailandia", "corea", "egipto", "india", "argelia", "senegal", "cuba"};
  char Deportes[19][16] = {"atletismo", "tenis", "rugby", "voleibol", "karate", "boxeo", "vale todo", "futbol", "padel", "beisbol", "basquetbol", "tiro con arco", "halterofilia", "ecuestre", "esgrima", "ciclismo", "esqui", "taekwondo", "natacion"};

  srand(time(NULL));
  random = rand() % 18;
  switch (op)
  {
  case 1:
    Jugar(Frutas[random]);
    break;

  case 2:
    Jugar(Paises[random]);
    break;
  case 3:
    Jugar(Deportes[random]);
    break;
  case 4:
    system("clear");
    InterfazWinLose(3);
    break;
  }
}

int Jugar(char *palabra)
{
  gotoxy(30, 13);
  int longi = strlen(palabra);
  int i, j, aciertos1 = 0, aciertos2 = 0, win; // la forma que pensé para contabilidar los errores fue con 2 vars de aciertos
  int error = 0;                               // En donde al principio, ambas son iguales, pero si el jugador le atina, acierto 1 aumenta, y ahora es dif de la 2
  char *aux[longi + 1];
  char letra;
  // esto genera los guiones
  for (i = 0; i < longi; i++)
  {
    aux[i] = 95;
    printf("%c ", aux[i]);
  }

  gotoxy(32, 10);
  printf("Digite una letra: ");

  do
  {
    gotoxy(50, 10);
    aciertos2 = aciertos1;
    letra = getch(); // cambie el scanf por el getch
    gotoxy(30, 13);
    for (i = 0; i < longi; i++)
    {
      if (letra == palabra[i])
      {
        aux[i] = palabra[i];
        aciertos1++;
      } // al acertar, aumenta solo aciertos1, lo que quiere decir que es dif de aciertos 2
      printf("%c ", aux[i]);
    }

    if (aciertos1 == aciertos2) // y si despues del proceso sigue siendo igual, a1 y a2, quiere decir que no acertó, osea, que falló
    {
      error++;
      Monito(error);
    }
    Puntaje(aciertos1, error);
    tachar(letra);
  } while (error != 6 && aciertos1 != longi);

  system("clear");

  if (error >= 6)
  {
    InterfazWinLose(2);
  }
  else
  {
    InterfazWinLose(1);
  }
  PonTextoCentradoPantalla(15, "La palabra era: ");
  printf("%s", palabra);
  PonTextoCentradoPantalla(18, "Quiere volver a jugar?\t");
  PonTextoCentradoPantalla(19, "SI = 1");
  PonTextoCentradoPantalla(20, "NO = 0\t");
}
