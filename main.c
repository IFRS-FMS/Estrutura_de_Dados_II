/* 
 * File:   main.c
 * Author: 0594121
 *
 * Created on 25 de Fevereiro de 2016, 21:22
 */

#include <stdio.h>
#include <stdlib.h>


#define TAMANHO 100
#define LVRAND 1000
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

void ordenarbs(int vetor[]){

    int aux;
    int i, j;
    
    for( i=TAMANHO-1 ; i >= 1 ; i--)
    {  
        for( j=0; j < i ; j++)
        {
            if(vetor[j]>vetor[j+1]) 
            {    
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

int buscabinaria (int valor, int n, int vetor[]) {
   int e, m, d;
   e = 0; d = n-1;
   while (e <= d) {
      m = (e + d)/2;
      if (vetor[m] == valor)
           return m;
      if (vetor[m] < valor)
          e = m + 1;
      else d = m - 1;
   }
   return -1;
}                    

int main(int argc, char** argv) {
    
    int i, valor, busca;
    int vetor[TAMANHO];


    for ( i=0 ; i<TAMANHO ; i++ )
    {
        do
        {
            valor = rand()%LVRAND;
            busca = consulta(valor, i, vetor);
        }while (busca != -1);
        vetor[i] = valor;
    }
    

    ordenarbs(vetor);
    
    scanf("%d", &valor);
//    busca = consulta(valor, TAMANHO, vetor);
//    printf("\n\n%d\n", busca);
    
    busca = buscabinaria(valor, TAMANHO, vetor);
    printf("\n\n%d\n", busca);
    
    return (EXIT_SUCCESS);
}


