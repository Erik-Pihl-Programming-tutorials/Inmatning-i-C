/********************************************************************************
* scanf.c: Demonstration av inmatningsfunktionen scanf i C. Funktionen scanf
*          har fördelen att denna är mycket enkel att använda, men har ett
*          flertal nackdelar, främst:
*
*          1. Inmatning sker enbart till ett första blanksteg, så det är
*             inte möjligt att mata in exempelvis ett för- och efternamn direkt,
*             utan det krävs två strängar.
*          2. Det sker ingen kontroll av antalet inmatade tecken, så man kan
*             utan problem läsa in fler tecken än en given sträng rymmer och
*             därmed råka skriva över annat i minnet.
*          3. Vid felinmatning, exempelvis text i stället för ett heltal, 
*             fungerar programmet inte som det ska. Som exempel, ifall ett
*             heltal skall matas in i en loop, där text matas in i stället,
*             så börjar programmet loopa okontrollerat utan att vänta på
*             efterföljande inmatning. 
*
*          För inläsning av enstaka tecken kan både scanf samt funktionen
*          getchar användas. Funktionen getchar är något enklare att använda,
*          då den returnerar tecknet direkt, medan scanf kräver att man 
*          passerar formatspecificerare %c samt adressen till variabeln,
*          exempelvis &c för en variabel döpt c, medan inläsning med getchar
*          sker genom instruktionen c = getchar();
*
*          Funktionen scanf kan användas för enklare inmatning, men för 
*          bättre funktionalitet föredras funktionen fgets, se filen fgets.c.
********************************************************************************/
#include <stdio.h> /* Funktionen scanf för inmatning. */

/********************************************************************************
* main: Deklarerar variabler för att läsa in text, ett heltal, ett flyttal samt
*       ett tecken. Användaren ombeds kontinuerligt mata in sitt namn, sin
*       ålder, ett flyttal samt ett tecken, vilket sedan skrivs ut i terminalen.
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
      scanf("%s %s", s1, s2);

      printf("\nEnter your age:\n");
      scanf("%d", &age);

      printf("\nEnter a floating point number:\n");
      scanf("%lg", &num);

      printf("\nEnter a character:\n");
      
      while (1) /* Så länge inläst tecken är ett nyradstecken så exekverar loopen. */
      {
         scanf("%c", &c);      /* Läser in ett nytt tecken varje varv. */
         if (c != '\n') break; /* Avbryter loopen så fort inläst tecken ej är ett nyradstecken. */
      }

      printf("\nName: %s %s\n", s1, s2);
      printf("Age: %d\n", age);
      printf("Floating point number: %lg\n", num);
      printf("Character: %c\n", c);

      printf("\n");
   }

   return 0;
}