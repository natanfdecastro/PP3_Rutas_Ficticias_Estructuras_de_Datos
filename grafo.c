#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Tamano 16 // Variable global para uso de tamaño

// Declaracion variables globales

int visitado[Tamano]; // Arreglo para utilizacion de nodos visitados

void bfs(int rutas[Tamano][Tamano], int nodo_Inicio) {

	/* Función destinada a realizar el recorrido en anchura de la matriz de adyacencia de rutas
	 * 
	 * Entradas: Matriz de 
	 * Salidas: Ninguna
	 * Restricciones: Ninguna																				*/

	// Implementacion de cola
	int anterior = 0;
	int posterior = 0;
	int cola[Tamano] = { 0 };

	int infinito = 999; // Variable para representar número infinito en la matriz de adyacencia

    // Marcar nodo inicio como visitado
    visitado[nodo_Inicio] = 1;

    // Se ingresa en la cola el nodo inicio
    cola[posterior] = nodo_Inicio; // insert at rear

    posterior++; // Se incrementa el posterior

    while (posterior != anterior) // Caso mientras las cola tenga valores restantes
    {

        // Se ingresa en la cola
        int fila = cola[anterior];

        //printf("%d ", fila); // Imprimir en medio proceso

        anterior++; // Se incrementa el anterior

        // Se revisan los nodos adyacentes en la fila
        int columna = 0;

        for (columna = 0; columna < Tamano; columna++) {

            // Caso que haya nodo adyacente, encolarlo
            if (rutas[fila][columna] != infinito && !visitado[columna]) {

                cola[posterior] = columna; // Se ingresa en la cola el nodo adyacente

                posterior++; // Se incrementa el posterior

                visitado[columna] = 1; // Se marca como visitado 

            }
        }
    }

    printf("\n>>> Resultado recorrido en anchura (BFS) de grafo rutas GOT: ");
    printf("[ ");

    for (int i = 0; i < Tamano; i++){ // Se recorre la cola para imprimir el registro del recorrido en anchura

        
        printf("%d ", cola[i]); // Se imprime el indice en la cola


    }

    printf("] \n");
    printf("\n"); // Salto de linea 

}

void floyd(int rutas[Tamano][Tamano], char nombres[Tamano][50], char caminos[Tamano][Tamano][50]){

    /* Algoritmo de Floyd-Warshall
     *
     * Entradas: Matrices de rutas, caminos y lista de nombres
     * Salidas: Ninguna
     * Restricciones: Las matrices tienen que ser de Tamano x Tamano y no deben contener strings de mas de 50 chars  */

    printf("\n");

    int cambios = 1;

    while(cambios){

        cambios = 0;

        for(int i = 0; i < Tamano; i++){

            for(int y = 0; y < Tamano; y++){

                for(int x = 0; x < Tamano; x++){

                    if(x != i && y != i){

                        if(x != y){

                            if(rutas[i][x] + rutas[y][i] < rutas[y][x]){

                                rutas[y][x] = rutas[i][x] + rutas[y][i];

                                strcpy(caminos[y][x], nombres[i]);

                                cambios = 1;

                            }
                        }
                    } 
                }
            }
        }
    }
    //printf("\n");
    /*
    printf("\n\n");
    for(int i = 0; i < Tamano; i++){
        for(int j = 0; j < Tamano; j++){
            printf("%c", caminos[i][j][0]);
            printf("%c", caminos[i][j][1]);
            printf("%c | ", caminos[i][j][2]);
        }
        printf("\n");
    }
    */
    // Mostrar matriz de adyacencia
    /*
	for (int i = 0; i < Tamano; i++){
		
		for(int j = 0; j < Tamano; j++){
			
			 printf("%d ", rutas[i][j]);
			
			}
		
		printf("\n");
	 }
     printf("\nRutas optimizadas con exito");
	 printf("\n");
    */
}
