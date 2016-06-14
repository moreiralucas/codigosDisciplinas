/* 
   Problema Parque Jurassico -- parque.c
   Seletiva IOI 2003 
   Guilherme Ottoni
   Algoritmo: programacao dinamica.
              complexidade: O(n^2)
*/

#include <stdio.h>
#include <string.h>

#define TAM 110
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

int tab[TAM][TAM];
char seq1[TAM], seq2[TAM];

int main()
{
  int i1, i2, i, teste=1;
  char *s1=seq1 - 1; 
  char *s2=seq2 - 1;
  char s[2*TAM];

  while (scanf("%s %s", seq1, seq2) == 2)
    {
      /* preenche tabela */
      for (i1 = 0; i1 <= strlen(seq1); i1++)
	         tab[i1][0] = i1;
      for (i2 = 0; i2 <= strlen(seq2); i2++)
        	tab[0][i2] = i2;
        
      for (i1 = 1; i1 <= strlen(seq1); i1++)
	       for (i2 = 1; i2 <= strlen(seq2); i2++)
	         if (s1[i1] == s2[i2])
	           tab[i1][i2] = tab[i1-1][i2-1] + 1;
	         else
	           tab[i1][i2] = MIN(tab[i1-1][i2], tab[i1][i2-1]) + 1;
              /* recupera solucao */
              i1 = strlen(seq1);
              i2 = strlen(seq2);
              s[tab[i1][i2]] = '\0';
              i = tab[i1][i2]-1;
              do{
                if (i1 > 0 && i2 > 0 && s1[i1] == s2[i2]){
                  s[i] = s1[i1];
                  i1--; i2--;
                }
                else
                  if (i2 > 0 && tab[i1][i2] - 1 == tab[i1][i2-1])
                    s[i] = s2[i2--];
                  else
                    s[i] = s1[i1--];
              }while (i-- > 0);
      printf("Teste %d\n%s\n\n", teste++, s);
    }
  return 0;
}