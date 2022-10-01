/********************************************************************************
* scanf_s.c: Demonstration av inmatningsfunktionen scanf_s, Microsofts s�krare
*            version av funktionen scanf. OBS! Denna funktion fungerar enbart
*            vid C-programmering i Visual Studio med kompilator MSVC! 
* 
*            Funktionen scanf_s har f�rdelen att man kan kontrollera antalet 
*            tecken som matas in i en str�ng, men innehar ocks� samma nackdelar 
*            som scanf, s�som att inl�sning sker enbart till f�rsta blanksteg samt 
*            att vid felinmatning s� kan programmet skena iv�g okontrollerat utan 
*            att v�nta p� efterf�ljande inmatning i en while-sats. Det b�sta �r 
*            d�rmed att anv�nda funktionen fgets f�r inmatning, se filen fgets.c.
********************************************************************************/
#include <stdio.h> 

/********************************************************************************
* main: Deklarerar variabler f�r att l�sa in text, ett heltal, ett flyttal samt
*       ett tecken. Anv�ndaren ombeds kontinuerligt mata in sitt namn, sin
*       �lder, ett flyttal samt ett tecken, vilket sedan skrivs ut i terminalen.
********************************************************************************/
int main(void)
{
   char s1[50] = { '\0' };
   char s2[50] = { '\0' };

   int age = 0;
   double num = 0.0;
   char c = '\0';

   while (1)
   {
      printf("Enter your name:\n");
      scanf_s("%s ", s1, 50);
      scanf_s("%s", s2, 50);

      printf("\nEnter your age:\n");
      scanf_s("%d", &age);

      printf("\nEnter a floating point number:\n");
      scanf_s("%lg", &num);

      printf("\nEnter a character:\n");
      
      while (1)
      {
         scanf_s("%c", &c, 1);
         if (c != '\n') break;
      }

      printf("\nName: %s %s\n", s1, s2);
      printf("Age: %d\n", age);
      printf("Floating point number: %lg\n", num);
      printf("Character: %c\n", c);

      printf("\n");
   }

   return 0;
}