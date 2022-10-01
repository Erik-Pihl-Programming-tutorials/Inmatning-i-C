/********************************************************************************
* fgets.c: Demonstration av inmatning via funktionen fgets i C. 
*
*          Funktionen fgets innehar flera f�rdelar j�mf�rt med funktionen scanf, 
*          prim�rt att maximalt antal tecken som matas in kan kontrolleras,
*          inmatning av text till en str�ng inneh�llande blanksteg fungerar 
*          (s� man kan mata in b�de f�r- och efternamn i en enda str�ng) samt 
*          att man slipper problem med att programmet skenar iv�g okontrollerat
*          vid felinmatning. 
*
*          Nackdelen med fgets �r att ett nyradstecken l�ses in vid nedtryckning 
*          av ENTER- tangenten. Detta nyradstecken b�r l�mpligen ers�ttas med 
*          ett nolltecken, s�som genomf�rs i funktionen read_line nedan.
* 
*          Vid inl�sning av heltal och flyttal m�ste ocks� typomvandling ske
*          via funktionen atoi (alpha to integer) samt atof (alpha to float)
*          fr�n C:s standardbibliotek, se funktionen get_integer samt get_double.
*          D�rmed m�ste C Standard Library (stdlib.h) inkluderas.
********************************************************************************/
#include <stdio.h>  
#include <stdlib.h> 

/********************************************************************************
* read_line: L�ser in text fr�n tangentbordet och lagrar i angiven str�ng.
*            Det nyradstecken som l�ses in vid nedtryckning av ENTER-tangenten
*            ers�tts med ett nolltecken. N�sta utskrift hamnar en rad ned.
* 
*            - s   : Pekare till str�ngen d�r inl�st text skall lagras.
*            - size: Str�ngens storlek, dvs. antalet tecken den rymmer.
********************************************************************************/
void read_line(char* s, 
               const int size)
{
   fgets(s, size, stdin);
   printf("\n");

   for (int i = 0; s[i] != '\0'; ++i)
   {
      if (s[i] == '\n')
      {
         s[i] = '\0';
      }
   }

   return;
}

/********************************************************************************
* get_integer: L�ser in och returnerar ett heltal inl�st fr�n tangentbordet.
*              Inneh�ll l�ses in som text fr�n tangentbordet och typomvandlas
*              sedan till ett heltal via funktionen atoi innan det returneras.
*              Varje tecken l�ses in tills ett felaktigt tecken n�s. Som exempel,
*              om bara text matas in s� returneras 0. Om exempelvis "43haha"
*              matas in s� returneras 43.
********************************************************************************/
int get_integer(void)
{
   char s[40] = { '\0' };
   read_line(s, sizeof(s));
   return atoi(s);
}

/********************************************************************************
* get_double: L�ser in och returnerar ett flyttal inl�st fr�n tangentbordet.
*             Inneh�ll l�ses in som text fr�n tangentbordet och typomvandlas
*             sedan till ett flyttal via funktionen atof innan det returneras.
*             Eventuellt kommatecken som matas in ers�tts med en punkt, vilket
*             medf�r att flyttal kan matas in b�de med punkt och kommatecken
*             decimalpunkt/separator.
********************************************************************************/
double get_double(void)
{
   char s[40] = { '\0' };
   read_line(s, sizeof(s));

   for (int i = 0; s[i] != '\0'; ++i)
   {
      if (s[i] == ',')
      {
         s[i] = '.';
      }
   }

   return atof(s);
}

/********************************************************************************
* get_character: L�ser in och returnerar ett tecken fr�n tangentbordet. Endast
*                det f�rsta tecknet returneras ifall multipla tecken matas
*                in samtidigt.
********************************************************************************/
char get_character(void)
{
   char s[40] = { '\0' };
   read_line(s, sizeof(s));
   return s[0];
}

/********************************************************************************
* main: Deklarerar variabler f�r att l�sa in text, ett heltal, ett flyttal samt
*       ett tecken. Anv�ndaren ombeds kontinuerligt mata in sitt namn, sin
*       �lder, ett flyttal samt ett tecken, vilket sedan skrivs ut i terminalen.
********************************************************************************/
int main(void)
{
   char name[100] = { '\0' };
   int age = 0;
   double num = 0.0;
   char c = '\0';

   while (1)
   {
      printf("Enter your name:\n");
      read_line(name, sizeof(name));

      printf("Enter your age:\n");
      age = get_integer();

      printf("Enter a floating pointer number:\n");
      num = get_double();

      printf("Enter a character:\n");
      c = get_character();

      printf("Name: %s\n", name);
      printf("Age: %d\n", age);
      printf("Floating point number: %lg\n", num);
      printf("Character: %c\n", c);

      printf("\n");
   }
}