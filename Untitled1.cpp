#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <fstream>
#include "stdio.h"
#include "dos.h"
#include "time.h"
#include "conio.h"

using namespace std;


















int main(){
	
	do{
		
		// Definicion de variables a utilizar.
		int opcion;
		ifstream archivo;
		ofstream nuevo;
		
		// Creacion y edicion de archvo.
   		archivo.open("Bitacora.txt",ios::in);
   		
   		if(archivo.fail()){
   			
   			// Creacion y edicion de archvo.
   			nuevo.open("Bitacora.txt",ios::out);
   			nuevo.close();
   			
		   }
		   
		archivo.close();
		
		 // Impresion en pantalla.
		cout << "Bienvenido al Centro de Monitoreo \n \nCual opcion desea realizar? \n \n1- Monitorear \n2- Establecer Usuarios \n3- Eliminar Usuarios \n4- Salir \n \n>>> ";
		cin >> opcion;
		
		system("cls");
		
		switch(opcion){
			
			case 1:{
				
				// Definicion de variables a utilizar.
				string identificacion;
				
				 // Impresion en pantalla.
				cout << "Digite la identificacion del sistema de alarma \n>>> ";
				cin >> identificacion;
				
				system("cls");
				
				monitorear(identificacion);// Llamada de la funcion.
				break;
				
			}
			
			case 2:{
				
				// Definicion de variables a utilizar.
				string identificacion;
				string linea;			
				ifstream archivo;
				bool bandera = false;
				
				 // Impresion en pantalla.
				cout << "Digite la identificacion del sistema de alarma \n>>> ";
				cin >> identificacion;
				
				system("cls");
				
				// Creacion y edicion de archvo.
				archivo.open("Usuarios.txt",ios::in);
				
				if (archivo.fail()){
					
					// Creacion y edicion de archvo.
					archivo.close();
					crear_archivo(identificacion);// Llamada de la funcion.
					
				}else{
										
					while(!archivo.eof()){
						
						getline(archivo,linea);
						
						if (linea == identificacion){
							
							dar_informacion(identificacion);// Llamada de la funcion.
							bandera = true;
							break;
							
						}
							
					}
					
					if(bandera == false){
						
						 // Impresion en pantalla.
						cout << "Su usuario no existe. Por favor cree uno \n \n";		
						agregar_usuario(identificacion);// Llamada de la funcion.
						archivo.close();
						break;
						
					}
								
				}

			break;

			}
				
			case 3:{
				
				// Definicion de variables a utilizar.
				string identificacion;
				string opcion = "No";
				
				 // Impresion en pantalla.
				cout << "Digite la identificacion del sistema de alarma que desea eliminar \n>>> ";
				cin >> identificacion;
				cout << "\n";
				
				system("cls");
				
				eliminar(identificacion,opcion);// Llamada de la funcion.
				
				break;
			}
				
			case 4:{
				
				 // Impresion en pantalla.
				cout << "Hasta Luego \n";
				exit(1);
				break;
				
			}
				
			default:
				
				 // Impresion en pantalla.
				cout << "Opcion incorrecta \n \n";
			
		}	
		
	}while(true);
		
}
