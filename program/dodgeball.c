#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#include <string.h>

typedef struct                                                                                                               //strukturka odpowiedzialna za nazwe i wynik gracza
{
  char imie[50];
  int wynik;
}gracz;

int screen(int,int,int);
int screen0(int,int,int,int,int,int,int,int,int,int,int,int,int,gracz);
int przegrana(int,gracz,int);
void menu();                                                                                                                //inicjalizacje funkcji

int main()
{
  int click,wysokosc,wysokosc2,iteracja,wyskursora=0,lvl=1,score=0,wys2del,wysokosc3,wys3del,wysokosc4,wys4del,wysokosc5,wys5del;    //inicjalizacje zmiennych i tablic
  char imie[50];
  gracz gracz1;

menu();




printf("Podaj nazwe gracza:");
scanf("%s",gracz1.imie);
printf("Witaj %s",gracz1.imie);
sleep(2);
system("@cls||clear");


srand(time(NULL));                                                                                                            //losowanie zmiennych odpowiedzialnych za opoznienie "o" i ich wysokosc
  while(click!=27)
  {
  wysokosc = rand()%10;
  wysokosc2 = rand()%4;
  wysokosc3 = rand()%4;
  wysokosc4 = rand()%4;
  wysokosc5 = rand()%4;
  wys2del =  (rand()%8)*lvl;
  wys3del = (rand()%8)*lvl+wys2del;
  wys4del = (rand()%8)*lvl+wys3del;
  wys5del = (rand()%8)*lvl+wys4del;


    if(wysokosc<=4)                                                                                                         //warunek wejscia do funkcji
    {
      for(iteracja=99+wys5del;iteracja>=0 && click != 27;iteracja=iteracja-lvl)                                                 // iteracje - wyświetlanie klatki 100+wys2del razy
      {
      screen0(wysokosc,iteracja,wyskursora,lvl,wysokosc2,wys2del,wysokosc3,wys3del,wysokosc4,wys4del,wysokosc5,wys5del,score,gracz1);
      printf("score-%d ",score);
      if(kbhit())
        {
        click = getch();
        if(click == 's' && wyskursora!=4)                                                     //zmiana pozycji kursora
        wyskursora++;
        if(click == 'w' && wyskursora!=0)
        wyskursora--;
      }
      }
      score=score+1;


      if(score==2)
      lvl++;
      if(score==4)
      lvl++;


    }
    if(wysokosc>4)
      {
        screen(wysokosc,wyskursora,lvl);
        if(kbhit())
          {
          click = getch();
          if(click == 's' && wyskursora!=4)                                                     //zmiana pozycji kursora
          wyskursora++;
          if(click == 'w' && wyskursora!=0)
          wyskursora--;
          }
      }
    if(kbhit())
      click = getch();

  }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
void menu()
{                                                                                                                       //menu początkowe
  int menu=0;
  printf("Witaj w dodgeball v1.0 ! \n");
  sleep(2);

  while(menu!=1)
  {
    printf("Menu: \n 1- GRAJ!!! \n 2- instrukcje \n 3- wyjdz\n");
    printf("Wybierz opcje i zatwierdz enterem.\n");
    scanf("%d",&menu);
    switch (menu)
      {
        case 1 :
          menu=1;
          break;
          system("@cls||clear");
        case 2:
          printf("Jestes 'x', musisz unikac 'O' \nAby poruszac sie w gore i dol uzywaj 'w' i 's'  ");
          sleep(2);
          system("@cls||clear");
          break;
        case 3:
        exit(0);
        default:
        printf("podaj jeszcze raz");
        sleep(1);
        system("@cls||clear");
        break;
      }
    }
return;
}


int screen(int wysokosc,int wyskursora,int lvl)                                                                     //wyswietlanie tablicy bez przeszkód - 1 klatka
{
 int y=0; int x=0; char tab [500][5];

printf("poziom-%d",lvl);

     for(y=0;y<5;y++)
     {
       printf("\n");
        for(x=0;x<100;x++)
        {
          if(wyskursora!=y || x!=0)
          {
            tab[x][y] = ' ';
            printf("%c",tab[x][y]);
          }
          else
          {
            tab[x][y] = 'x';
            printf("%c",tab[x][y]);
          }
        }

     }
       system("@cls||clear");

  return 0;
}

int screen0(int wysokosc,int iteracja,int wyskursora,int lvl,int wysokosc2,int wys2del,int wysokosc3, int wys3del,int wysokosc4,int wys4del,int wysokosc5, int wys5del, int score, gracz gracz1)        // wyswietlanie tablicy z przeszkoda w lini - 1 klatka
{
int y=0; int x=0; char tab [500][5]; int wyklvl=0;

printf("poziom-%d",lvl);
  for(y=0;y<5;y++)
  {
    printf("\n");
    for(x=0;x<100;x++)
    {
      if(x==iteracja && y==wysokosc5 && (wyskursora!=y || x!=0 ))                                                          //warunki wypisania przeszkody
      {

              tab[x][y] = 'O';
              printf("%c",tab[x][y]);

      }
      if(x==iteracja-wys2del && y==wysokosc4  && (wyskursora!=y || x!=0 ))
      {
              tab[x][y] = 'O';
              printf("%c",tab[x][y]);
      }
      if(x==iteracja-wys3del && y==wysokosc3  && (wyskursora!=y || x!=0 ))
      {
              tab[x][y] = 'O';
              printf("%c",tab[x][y]);
      }
      if(x==iteracja-wys4del && y==wysokosc2 && (wyskursora!=y || x!=0 ))
      {
              tab[x][y] = 'O';
              printf("%c",tab[x][y]);
      }
      if(x==iteracja-wys5del && y==wysokosc  && (wyskursora!=y || x!=0 ))
      {
              tab[x][y] = 'O';
              printf("%c",tab[x][y]);
      }


      else
      {
        if(wyskursora!=y || x!=0)                                                                                                 //warunek wypisania pustego pola
        {
          tab[x][y] = ' ';
          printf("%c",tab[x][y]);
        }
        else
        {
          tab[x][y] = 'X';                                                                                                       //warunek wypisania kursora
          printf("%c",tab[x][y]);
        }
      }
    }
  }



  if(lvl==1)                                                                                                                    //waruneki na zwiększanie poziomu
    wyklvl=0;
  if(lvl==2)
    wyklvl=1;
  if(lvl==3)
    wyklvl=0;

if(wyskursora==wysokosc && iteracja-wys5del==0+wyklvl)                                                                         //wykrywanie przegranej i wejscie do funkcji pozegnalnej
  przegrana(score,gracz1,score);
if(wyskursora==wysokosc2 && iteracja-wys4del==0+wyklvl)
  przegrana(score,gracz1,score);
if(wyskursora==wysokosc3 && iteracja-wys3del==0+wyklvl)
  przegrana(score,gracz1,score);
if(wyskursora==wysokosc4 && iteracja-wys2del==0+wyklvl)
  przegrana(score,gracz1,score);
if(wyskursora==wysokosc5 && iteracja==0+wyklvl)
  przegrana(score,gracz1,score);


  system("@cls||clear");
return 1;
}

int przegrana(int score,gracz gracz1, int a)                                                                                  //funkcja przegralno pożegnalna
{
  FILE *fptr;
  fptr= fopen("scores.txt","a");
  fprintf(fptr,"%s - ",gracz1.imie);
  fprintf(fptr,"%d\n",score);
  fclose(fptr);
  system("@cls||clear");
  printf("PRZEGRANA! \n");
  printf("Twoj wynik to %d pkt ",score);
  sleep(1);
  exit(0);
}
