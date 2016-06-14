#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int n, nMax, i, j, totalDivisores;
 
    // Recebe o limite para exibição dos números primos
    printf("Digite o limite superior para os numeros primos(Minimo 2): ");
    scanf("%d", &nMax);
 
    // Verifica se o limite superior é um número válido
    // O menor número primo é 2
    while(nMax < 2) {
        system("cls");
        printf("Digite o limite superior para os numeros primos(Minimo 2): ");
        scanf("%d", &nMax);
    }
 
    // Verifica se o número é primo e imprime o valor na tela
    for(i = 0; i <= nMax; i++) {
        totalDivisores = 0;
        // Conta os divisores para verificar se o valor é primo
        for(j = 1; j <= i; j++) {
            if(i % j == 0) {
                totalDivisores++;
            }
        }
        // Se o total de divisores é dois, imprime o primo com formatação de 4 casas
        if(totalDivisores == 2) {
            printf("%4d ", i);
        }
    }
 
    printf("\n");
    return 0;
}