/* 
 * File:   main.c
 * Author: 0594121
 *
 * Created on 25 de Fevereiro de 2016, 21:22
 */

#include <stdio.h>
#include <stdlib.h>


#define TAMANHO 10
#define LVRAND 100
/*
 * 
 */
int consulta (int valor, int quant, int vetor[])
{
    int i;

    
    for ( i=0 ; i<quant ; i++ )
    {
        if (valor == vetor[i])
        {
            return i;
        }
    }
    return -1;
}


int main(int argc, char** argv) {
    
    int i, valor, busca;
    int vetor[TAMANHO];

/*    
    for ( i=0 ; i<TAMANHO ; i++ )
    {
        vetor[i] = rand()%999;
    }
*/
    for ( i=0 ; i<TAMANHO ; i++ )
    {
        do
        {
            valor = rand()%LVRAND;
            busca = consulta(valor, i, vetor);
        }while (busca != -1);
        vetor[i] = valor;
    }
    
    
    for ( i=0 ; i<TAMANHO ; i++ )
    {
        printf("%d\n", vetor[i]);
    }
    
    scanf("%d", &valor);
    busca = consulta(valor, TAMANHO, vetor);
    
    
    printf("\n\n%d\n", busca);

    
    return (EXIT_SUCCESS);
}


