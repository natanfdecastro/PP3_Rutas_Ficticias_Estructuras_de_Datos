#include "terminal.h"
#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Tamano 16 // Variable global para uso de tamaño

// Declaracion variables globales

int rutas[Tamano][Tamano]; // Matriz rutas con peso
int rutas_original[Tamano][Tamano]; // Matriz original rutas con peso
char nombres[Tamano][50]; // Arreglo de nombres de nodo asociado al grafo de rutas
char caminos[Tamano][Tamano][50]; //Matriz que indica cual es el camino mas corto entre las rutas
int actualizado = 0; //Variable para saber si la matriz de recorridos esta actualizada

int comparar_strings(char *string1, char *string2) {
    /* Compara strings hasta llegar a el final de uno de los dos strings o un salto de linea
	 * 
	 * Entradas: Dos Strings
	 * Salidas: Int
	 * Restricciones: Ninguna
     */
    for(int i = 0; (string1[i] != '\n' && string1[i] != '\0') && (string2[i] != '\n' && string2[i] != '\0'); i++) {
        if(string1[i] != string2[i]) {
            return 0;
        }
    }
    return 1;
}

void copiar_matriz(int matriz_1[Tamano][Tamano], int matriz_2[Tamano][Tamano]) {
    /* Función destinada para cargar el archivo csv que se requerirá para generar la matriz de adyacencia
	 * 
	 * Entradas: matriz_1 a la que se le van a copiar los valores de la matriz_2
	 * Salidas: Ninguna
	 * Restricciones: Ninguna
     */
    for (int i = 0; i < Tamano; i++){
		
		for(int j = 0; j < Tamano; j++){
			
			matriz_1[i][j] = matriz_2[i][j];
			
        }

	 }
}

void cargar_rutas(){

	/* Función destinada para cargar el archivo csv que se requerirá para generar la matriz de adyacencia
	 * 
	 * Entradas: Ninguna
	 * Salidas: Matriz de rutas con peso generada
	 * Restricciones: Ninguna																				*/
	
	// Declaracion de variables

	char buffer[2048];
	char *registro, *linea;
	
	int i = 0; 
	int j = 0;
	
	FILE *fstream = fopen("rutas.csv","r"); // Se abre el archivo según el nombre y la "r" representa read de lectura
	
	if(fstream == NULL){ // Caso que haya error al abrir el archivo
		
			printf(">>> [ ERROR AL ABRIR ARCHIVO ] <<<"); // Mensaje de error

	}
	
	while((linea = fgets(buffer, sizeof(buffer), fstream)) != NULL){ // Ciclo mientras el archivo tenga contenido
		
		registro = strtok(linea,","); // Copia el contenido de linea a registro hasta encontrar coma
			
		while(registro != NULL){
			
			
			rutas[i][j] = atoi(registro);
			
			registro = strtok(NULL,",");

			j++;

		}
		
	}

	printf("\n\t\t\t   >>> [ Archivo de Rutas Cargado EXITOSAMENTE ] <<<\n");
	printf("\n\t\t\t  >>> [ Matriz Adyacencia Generada EXITOSAMENTE ] <<<");

	/*
	// Mostrar matriz de adyacencia
	for (int i = 0; i < Tamano; i++){
		
		for(int j = 0; j < Tamano; j++){
			
			printf("%d ", rutas[i][j]);
			
        }
		
		printf("\n");
	 }
	 */

	 printf("\n");
	
    copiar_matriz(rutas_original, rutas);
}

void cargar_nombres(){

	/* Función destinada para cargar el archivo csv que se requerirá para generar el arreglo de nombres 
	 * relacionado a la matriz de adyacencia
	 * 
	 * Entradas: Ninguna
	 * Salidas: Arreglo de nombres de rutas generado
	 * Restricciones: Ninguna																				*/

	char buffer[2048];
	char *registro, *linea;
	
	int i = 0; 

	FILE *fstream = fopen("nombres.csv","r");

	while((linea = fgets(buffer, sizeof(buffer), fstream)) != NULL){

		registro = strtok(linea,","); // Copia el contenido de linea a registro hasta encontrar coma

		while(registro != NULL){
			
			
			strcpy(nombres[i], registro);

			registro = strtok(NULL,",");

			i++;

		}
	}

	/*
	// Mostrar arreglo de nombres
	for(int i = 0; i < Tamano; i++){

	    printf("%s | ", nombres[i]);

	}
	*/

}

void cargar_caminos(){
    /* Carga la matriz de caminos
	 * 
	 * Entradas: Ninguna
	 * Salidas: Ninguna
	 * Restricciones: Ninguna	
     */
    for(int i = 0; i < Tamano; i++){

        for(int j = 0; j < Tamano; j++){

            strcpy(caminos[i][j], nombres[j]);
            
        }
    }

}

void realizar_bfs(){


	bfs(rutas, 0);


}

void optimizar_rutas(){
    //Llama a la funcion floyd y asigna un 1 a la variable actualizado
    floyd(rutas, nombres, caminos);    

    actualizado = 1;

}


void buscar_recorrido_mas_corto(){
    /* Pide al usuario que digite la ubicacion de partida y destino para imprimir la distancia minima del recorrido consultandola en la matriz de recorridos
	 * Si la matriz de recorridos no esta actualizada llama a optimizar_rutas
     *
	 * Entradas: Ninguna
	 * Salidas: Ninguna
	 * Restricciones: Ninguna	
     */
    if(!actualizado) {
        optimizar_rutas();
    }
    
    for (int i = 0; i < Tamano; i++){

	    printf("%s | ", nombres[i]);

	}
    printf("\n");
    
    int y = 0, x = 0;

    char lugar1[50], lugar2[50], *deCamino;

    printf("\nIngrese el nombre del lugar de partida.\nPartida: ");

    fgets(lugar1, 50, stdin);

    while(y < Tamano && !comparar_strings(lugar1, nombres[y])) {

        y++;

    }

    if(y == Tamano) {

        printf("\nEl sitio de partida no existe\n");
        return;

    }

    printf("\nIngrese el nombre del lugar de destino.\nDestino: ");

    fgets(lugar2, 50, stdin);

    while(x < Tamano && !comparar_strings(lugar2, nombres[x])) {

        x++;

    }

    if(x >= Tamano) {

        printf("\nEl sitio de partida no existe\n");
        return;

    }

    if(rutas[y][x] >= 999) {

        printf("\n%s es inaccesible desde %s\n",nombres[x], nombres[y]);
		return;

    }

    printf("\n\nDistancia Total: %d", rutas[y][x]);

    printf("\n\nRecorrido: ");

    deCamino = nombres[y];

    while(!comparar_strings(deCamino, nombres[x])) {

        printf("%s -> ",deCamino);

        deCamino = caminos[y][x];

        y = 0;

        while(y < Tamano && !comparar_strings(deCamino, nombres[y])) {

            y++;

        }
    }

    printf("%s\n", nombres[x]);
    
}

void reto_random() {

    /* Busca la ruta optima entre dos nodos aleatorios
	 * Si actualizado = 0 llama a optimizar rutas
     *
	 * Entradas: Ninguna
	 * Salidas: Ninguna
	 * Restricciones: Ninguna	
     */

    if(!actualizado) {

        optimizar_rutas();

    }

    int x = rand() % Tamano, y = rand() % Tamano;

    printf("\nPartida = %s",nombres[y]);

    printf("\n\nDestino = %s",nombres[x]);

    printf("\n\nDistancia Total: %d", rutas[y][x]);
}

void actualizar_mapa() {
    /* Actualiza la ruta indicada por el usuario
	 * 
	 * Entradas: Ninguna
	 * Salidas: Ninguna
	 * Restricciones: Ninguna	
     */
    
    for(int i = 0; i < Tamano; i++){

	    printf("%s | ", nombres[i]);

	}
    int y = 0, x = 0, distancia;

    char lugar1[50], lugar2[50];

    printf("\nIngrese la ruta que desea actualizar");

    printf("\n\nDe: ");

    fgets(lugar1, 50, stdin);

    while(y < Tamano && !comparar_strings(lugar1, nombres[y])) {
        y++;
    }

    if(y == Tamano) {

        printf("\nEl sitio no existe\n");
        return;

    }

    printf("\nA: ");

    fgets(lugar2, 50, stdin);

    while(x < Tamano && !comparar_strings(lugar2, nombres[x])) {

        x++;

    }

    if(x == Tamano) {

        printf("\nEl sitio no existe\n");

        return;

    }
    printf("\nIngrese la distancia entre %s y %s: \n", nombres[y], nombres[x]);

    scanf("%i", &distancia);

    getchar();

    rutas_original[y][x] = distancia;

    copiar_matriz(rutas, rutas_original);

    cargar_caminos();

    actualizado = 0;

	char *registro, *linea;
	
	int i = 0; 
	int j = 0;

    FILE *fp;

    fp = fopen("rutas.csv", "r+");// Se abre el archivo según el nombre y la "r+" representa lectura y escritura

    while(i < y){ // Ciclo para llegar a la linea que quiero modificar

        fgets(linea, 100, fp);

        strcpy(linea, "");

        i++;

    }

	while(j < Tamano - 1){

		fprintf(fp, "%d,", rutas[i][j]);//Se escribe cada valor con una coma al inicio

		j++;

	}

    fprintf(fp, "%d\n", rutas[i][j]);

    fclose(fp);

    // Mostrar matriz de adyacencia
	for (int i = 0; i < Tamano; i++){
		
		for(int j = 0; j < Tamano; j++){
			
			printf("%d ", rutas[i][j]);
			
        }
		
		printf("\n");
	 }

	 printf("\n");
}
