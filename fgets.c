/********************************************************************************
* fgets.c: Demonstration av inmatning via funktionen fgets i C. 
*
*          Funktionen fgets innehar flera fördelar jämfört med funktionen scanf, 
*          primärt att maximalt antal tecken som matas in kan kontrolleras,
*          inmatning av text till en sträng innehållande blanksteg fungerar 
*          (så man kan mata in både för- och efternamn i en enda sträng) samt 
*          att man slipper problem med att programmet skenar iväg okontrollerat
*          vid felinmatning. 
*
*          Nackdelen med fgets är att ett nyradstecken läses in vid nedtryckning 
*          av ENTER- tangenten. Detta nyradstecken bör lämpligen ersättas med 
*          ett nolltecken, såsom genomförs i funktionen read_line nedan.
* 
*          Vid inläsning av heltal och flyttal måste också typomvandling ske
*          via funktionen atoi (alpha to integer) samt atof (alpha to float)
*          från C:s standardbibliotek, se funktionen get_integer samt get_double.
*          Därmed måste C Standard Library (stdlib.h) inkluderas.
********************************************************************************/
#include <stdio.h>  
#include <stdlib.h> 

/********************************************************************************
* read_line: Läser in text från tangentbordet och lagrar i angiven sträng.
*            Det nyradstecken som läses in vid nedtryckning av ENTER-tangenten
*            ersätts med ett nolltecken. Nästa utskrift hamnar en rad ned.
* 
*            - s   : Pekare till strängen där inläst text skall lagras.
*            - size: Strängens storlek, dvs. antalet tecken den rymmer.
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
* get_integer: Läser in och returnerar ett heltal inläst från tangentbordet.
*              Innehåll läses in som text från tangentbordet och typomvandlas
*              sedan till ett heltal via funktionen atoi innan det returneras.
*              Varje tecken läses in tills ett felaktigt tecken nås. Som exempel,
*              om bara text matas in så returneras 0. Om exempelvis "43haha"
*              matas in så returneras 43.
********************************************************************************/
int get_integer(void)
{
   char s[40] = { '\0' };
   read_line(s, sizeof(s));
   return atoi(s);
}

/********************************************************************************
* get_double: Läser in och returnerar ett flyttal inläst från tangentbordet.
*             Innehåll läses in som text från tangentbordet och typomvandlas
*             sedan till ett flyttal via funktionen atof innan det returneras.
*             Eventuellt kommatecken som matas in ersätts med en punkt, vilket
*             medför att flyttal kan matas in både med punkt och kommatecken
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
* get_character: Läser in och returnerar ett tecken från tangentbordet. Endast
*                det första tecknet returneras ifall multipla tecken matas
*                in samtidigt.
********************************************************************************/
char get_character(void)
{
   char s[40] = { '\0' };
   read_line(s, sizeof(s));
   return s[0];
}

/********************************************************************************
* main: Deklarerar variabler för att läsa in text, ett heltal, ett flyttal samt
*       ett tecken. Användaren ombeds kontinuerligt mata in sitt namn, sin
*       ålder, ett flyttal samt ett tecken, vilket sedan skrivs ut i terminalen.
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