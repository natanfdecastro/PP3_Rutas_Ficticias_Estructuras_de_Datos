#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"

int main(){
		
	/* Función principal del programa, destinada a capturar comando y redigirirlos a funciones de asistencia
	 * en terminal
	 * 
	 * Entradas: Ninguna
	 * Salidas: Ninguna
	 * Restricciones: Ninguna																				*/
	 
	 
	while(1){
		
		char comando[50]; // Declaracion de variable
				
		mostrar_menu_capturar_comando();
		
		fgets(comando, 50, stdin); // Captura de char y la transfiere a variable comando
			 
		
		if(strcmp(comando, "cargar_archivo\n") == 0){ // Caso comando sea igual a cargar_archivo
			
			mostrar_asistente_carga_archivo(); // Llamada a funcion 
		
		}

		else if(strcmp(comando, "recorrer_grafo\n") == 0){ // Caso comando sea igual a recorrer_grafo

			mostrar_asistente_bfs();

		}

        else if(strcmp(comando, "ruta_mas_corta\n") == 0){ // Caso comando sea igual a ruta_mas_corta

            mostrar_asistente_ruta();     

        }

        else if(strcmp(comando, "reto_random\n") == 0){ // Caso comando sea igual a reto_random

            mostrar_asistente_random();     

        }

        else if(strcmp(comando, "actualizar_mapa\n") == 0){ // Caso comando sea igual a actualizar_mapa

            mostrar_asistente_actualizar();     

        }

		else if(strcmp(comando, "ayuda\n") == 0){ // Caso comando concuerde con ayuda
					
			mostrar_ayuda();
				
		}

		else if(strcmp(comando, "acerca_de\n") == 0){ // Caso comando con acerca_de
				
				
			mostrar_acerca_de();
			
			
		}

		else if(strcmp(comando, "salir\n") == 0){ // Caso comando sea igual a salir
			
			printf("\n\n");
			
			printf("\t\t\t\t   >>> [ Programa CERRADO ] <<<\n\n");
			
			break;
		
		}

		else{
				
			printf(">>> [ Comando INVÁLIDO ] <<<");
				
			system("clear"); //Limpia la pantalla de terminal
				
		}
			
		printf("\n\n");
		 
	}
	
	return 0;
	
} 
