#include "terminal.h"
#include "operaciones.h"
#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void mostrar_menu_capturar_comando(){
	
			
		printf("\n\n======================================= [ ✠ RUTAS FICTICIAS ✠ ] =======================================\n\n");
		printf("	 ▒█▀▀█ ░█▀▀█ ▒█▀▄▀█ ▒█▀▀▀ 　 ▒█▀▀▀█ ▒█▀▀▀ 　 ▀▀█▀▀ ▒█░▒█ ▒█▀▀█ ▒█▀▀▀█ ▒█▄░▒█ ▒█▀▀▀ ▒█▀▀▀█ \n");
		printf("	 ▒█░▄▄ ▒█▄▄█ ▒█▒█▒█ ▒█▀▀▀ 　 ▒█░░▒█ ▒█▀▀▀ 　 ░▒█░░ ▒█▀▀█ ▒█▄▄▀ ▒█░░▒█ ▒█▒█▒█ ▒█▀▀▀ ░▀▀▀▄▄ \n");
		printf("	 ▒█▄▄█ ▒█░▒█ ▒█░░▒█ ▒█▄▄▄ 　 ▒█▄▄▄█ ▒█░░░ 　 ░▒█░░ ▒█░▒█ ▒█░▒█ ▒█▄▄▄█ ▒█░░▀█ ▒█▄▄▄ ▒█▄▄▄█ \n\n\n");
			
		printf(">>> Digite la acción que desea realizar: ");
	
	
}

void mostrar_asistente_carga_archivo(){
	
		
		cargar_rutas();
		cargar_nombres();
        cargar_caminos();
		
	
}

void mostrar_asistente_bfs(){


		realizar_bfs();

}

void mostrar_asistente_ruta(){

        buscar_recorrido_mas_corto();

}

void mostrar_ayuda(){

		system("clear"); //Limpia la pantalla de terminal

		printf("\n\n");
		printf("             | = = = = = = = = = = = = = = = = = A Y U D A = = = = = = = = = = = = = = = = = = = |\n");
		printf("             |                                                                                   |\n");
		printf("             |   cargar_archivo: Carga archivo tipo .CSV y genera matriz de adyacencia           |\n");
		printf("             |   recorrer_grafo: Imprime en consola el recorrido en anchura del grafo BFS        |\n");
		printf("             |   actualizar_mapa: Conectar-Desconectar dos nodos dados en matriz de adyacencia   |\n");
		printf("             |   ruta_mas_corta: Busca camino más corto utilizando algoritmo de Floyd-Warshall   |\n");
		printf("             |   reto_random: Busca camino más corto entre 2 nodos aleatorios con Floyd-Warshall |\n");
		printf("             |   ayuda: Imprimir en consola comandos disponibles                                 |\n");
		printf("             |   acerca_de: Imprimir en consola parámetros del programa, curso y desarrolladores |\n");
		printf("             |                                                                                   |\n");
		printf("             | = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = |\n");

}

void mostrar_acerca_de(){

		system("clear"); //Limpia la pantalla de terminal
		
        printf("\n\n");    
		printf("               | = = = = = = = = = = = = = = = = = A B O U T = = = = = = = = = = = = = = = = = |\n");
		printf("               |                                                                               |\n");
		printf("               |                        Rutas Ficticias JUEGO DE TRONOS                        |\n");
		printf("               |                                                                               |\n");
		printf("               |   Estructura tu mapa de Juego de Tronos (GOT). Puedes recorrer el mapa,       |\n");
		printf("               |   buscar la ruta mas corta entre dos puntos además de conectar o              |\n");
		printf("               |   desconectar dos puntos cualesquiera en el mapa.    	                       |\n");
		printf("               |                                                                               |\n");
		printf("               |                                                                               |\n");
		printf("               |   Instituto Tecnológico de Costa Rica                                         |\n");
		printf("               |   Estructuras de Datos II Semestre 2018                                       |\n");
		printf("               |   III Proyecto Programado                                                     |\n");
		printf("               |                                                                               |\n");
		printf("               |   Desarrolladores                                                             |\n");
		printf("               |   Natán Fernández de Castro - 2017105774                                      |\n");
		printf("               |   Pablo Venegas Sánchez - 2018083497                                          |\n");
		printf("               | = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = |\n");


}

void mostrar_asistente_random() {
    reto_random();
}

void mostrar_asistente_actualizar() {
    actualizar_mapa();
}
