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

void crear_archivo(string identificacion){

	// Definicion de variables a utilizar.
	string usuario;
	string propiedad;
	string direccion;
	int telefono1;
	int telefono2;
	string correo;
	string nombre;
	ofstream archivo;
	
	 // Impresion en pantalla.
	cout << "Su usuario no existe. Por favor cree uno \n \n";
	
	 // Impresion en pantalla.
	cout << "Digite el nombre de usuario \n>>> ";
	cin >> usuario;
	
	system("cls");
	
	 // Impresion en pantalla.
	cout << "Digite el tipo de propiedad \n>>> ";
	cin >> propiedad;
	
	system("cls");
	
	 // Impresion en pantalla.
	cout << "Digite la direccion fisica \n>>> ";
	cin >> direccion;
	
	system("cls");
	
	 // Impresion en pantalla.
	cout << "Digite el primer telefono \n>>> ";
	cin >> telefono1;
	
	system("cls");
	
	 // Impresion en pantalla.
	cout << "Digite el segundo telefono \n>>> ";
	cin >> telefono2;
	
	system("cls");
	
	 // Impresion en pantalla.
	cout << "Digite el correo electronico \n>>> ";
	cin >> correo;
						
	system("cls");
	
	// Creacion y edicion de archvo.
	archivo.open("Usuarios.txt",ios::out);
	archivo << identificacion << "\n" << usuario << "\n" << propiedad << "\n" << direccion << "\n" << telefono1 << "\n" << telefono2 << "\n" << correo << "\n";
	archivo.close();
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(estado).txt";
	archivo.open(nombre.c_str(),ios::out);
	archivo << "desactivado";
	archivo.close();
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(AD).txt";
	archivo.open(nombre.c_str(),ios::out);
	archivo << "desarmado";
	archivo.close();
	
}

void agregar_usuario(string identificacion){
	
	// Definicion de variables a utilizar.
	string usuario;
	string propiedad;
	string direccion;
	int telefono1;
	int telefono2;
	string correo;
	ofstream archivo;
	string nombre;
	
	 // Impresion en pantalla.		
	cout << "Digite el nombre de usuario \n>>> ";
	cin >> usuario;
	
	system("cls");
	
	 // Impresion en pantalla.
	cout << "Digite el tipo de propiedad \n>>> ";
	cin >> propiedad;
	
	system("cls");
	
	 // Impresion en pantalla.
	cout << "Digite la direccion fisica \n>>> ";
	cin >> direccion;
	
	system("cls");
	
	 // Impresion en pantalla.
	cout << "Digite el primer telefono \n>>> ";
	cin >> telefono1;
	
	system("cls");
	
	 // Impresion en pantalla.
	cout << "Digite el segundo telefono \n>>> ";
	cin >> telefono2;
	
	system("cls");
	
	 // Impresion en pantalla.
	cout << "Digite el correo electronico \n>>> ";
	cin >> correo;
						
	system("cls");
	
	// Creacion y edicion de archvo.
	archivo.open("Usuarios.txt",ios::app);
	archivo << identificacion << "\n" << usuario << "\n" << propiedad << "\n" << direccion << "\n" << telefono1 << "\n" << telefono2 << "\n" << correo << "\n";
	archivo.close();
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(estado).txt";
	archivo.open(nombre.c_str(),ios::out);
	archivo << "desactivado";
	archivo.close();
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(AD).txt";
	archivo.open(nombre.c_str(),ios::out);
	archivo << "desarmado";
	archivo.close();
	
}

void eliminar(string identificacion,string opcion){
	
	// Definicion de variables a utilizar.
	ifstream archivo;
	ifstream otro;
	ofstream nuevo;
	string guia;
	string linea;
	string datos;
	string nombre;
	bool membresia = false;
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(AD).txt";
	otro.open(nombre.c_str(),ios::in);
	
	getline(otro,guia);
	
	otro.close();
	
	archivo.open("Usuarios.txt",ios::in);
	
	while(!archivo.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
		
		getline(archivo,linea);
	
		if(linea == identificacion){ // Cindicion que verifica se identificacion existe.
			
			membresia = true;
			
		}
	
	}
	
	archivo.close();
	
	if(membresia == true){
		
		if(guia == "desarmado"){
			
			archivo.open("Usuarios.txt",ios::in);
		
			while(!archivo.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
			
				getline(archivo,linea);
				
				if(linea != identificacion){ // Condicion que si la identificacion es diferente a la linea del archivo
					
					datos = datos + linea + "\n"; // Se agrega la linea a un string.
						
				}else{
					
					for (int i = 0; i < 6; i++){ // Iteracion para eliminar lineas
						
						getline(archivo,linea);
					
					}
					
				}
					
			}
			
			// Creacion y edicion de archvo.
			nuevo.open("Usuarios.txt",ios::out);
			nuevo << datos;
			nuevo.close();
			
			// Eliminacion del archvo.
			nombre = identificacion + "(estado).txt";
			remove(nombre.c_str());
			
			// Eliminacion del archvo.
			nombre = identificacion + "(AD).txt";
			remove(nombre.c_str());
			
			// Eliminacion del archvo.
			nombre = identificacion + "(Zonas).txt";
			remove(nombre.c_str());
			
			// Eliminacion del archvo.
			nombre = identificacion + "(Bitacora).txt";
			remove(nombre.c_str());
			
			// Eliminacion del archvo.
			nombre = identificacion + "(Principal).txt";
			remove(nombre.c_str());
			
			// Eliminacion del archvo.
			nombre = identificacion + "(Secundarias).txt";
			remove(nombre.c_str());

			if(opcion == "Si" or opcion == "si"){
				
				agregar_usuario(identificacion);
				
			}
				
		}else{
			
			cout << "No se puede eliminar el usuario porque el sistema se encuentra armado \n \n"; // Impresion en pantalla.
			
		}
		
	}else{
		
		cout << "No se puede eliminar porque el usuario no exite \n \n"; // Impresion en pantalla.
		
	}
		
}

void dar_informacion(string identificacion){
	
	// Definicion de variables a utilizar.
	ifstream archivo;
	string linea;
	string opcion;
	
	archivo.open("Usuarios.txt",ios::in);
	
	while(!archivo.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
	
		getline(archivo,linea);
		
		if(linea == identificacion){
			
			 // Impresion en pantalla.
			cout << "Identificacion del Sistema: " << linea << "\n";
			
			getline(archivo,linea);
			
			 // Impresion en pantalla.
			cout << "Usuario: " << linea << "\n";
			
			getline(archivo,linea);
			
			 // Impresion en pantalla.
			cout << "Propiedad: " << linea << "\n";
			
			getline(archivo,linea);
			
			 // Impresion en pantalla.
			cout << "Direccion fisica: " << linea << "\n";
			
			getline(archivo,linea);
			
			 // Impresion en pantalla.
			cout << "Telefono 1: " << linea << "\n";
			
			getline(archivo,linea);
			
			 // Impresion en pantalla.
			cout << "Telefono 2: " << linea << "\n";
			
			getline(archivo,linea);
			
			 // Impresion en pantalla.
			cout << "Correo electronico: " << linea << "\n \n";
			
		}
	
	}
	
	archivo.close();

	 // Impresion en pantalla.
	cout << "Desea cambiar la informacion actual? (Si o No) \n>>> ";
	cin >> opcion;
	cout << "\n";
	
	system("cls");
	
	if(opcion == "Si" or opcion == "si"){
	
		eliminar(identificacion,opcion);
		
	}
	
	system("cls");
	
}

void monitorear(string identificacion){

	// Definicion de variables a utilizar.
	string linea;
	ifstream archivo;
	bool guia = false;
	bool bandera = true;
	int cont = 0;
	int opcion;
	
	// Creacion y edicion de archvo.
	archivo.open("Bitacora.txt",ios::in);
	
	if(archivo.fail()){
		
		 // Impresion en pantalla.
		cout << "Aun no existen registros \n \n";
		
	}else{
		
		getline(archivo,linea);
		
		 // Impresion en pantalla.
		cout << "Fecha" << "		" << "Hora" << "		" << "Usuario" << "		" << "Alerta" << "		" << "Zona/Cod" << "	" << "Descripcion" << "\n";
		
		do{
			
			while(!archivo.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
				
				// Algoritmo que servira para imprimir todas las acciones de la bitacora en forma ordenada
				for (int i = 0; i < 7; i++){
				
					getline(archivo,linea);
					
					if(linea == "armar"){
						
						cout << "	";// Impresion en pantalla.
						
						cout << linea;
						
						cout << "		";// Impresion en pantalla.
						
						getline(archivo,linea);
						
						i++;
						
					}
					
					if(i == 3 or i == 5){
						
						cout << "	";// Impresion en pantalla.
						
					}
					
					if(i != 6){
						
					cout << linea << "	";	// Impresion en pantalla.
						
					}
				
				}
			
				cout << "\n";// Impresion en pantalla.
				
				cont = cont + 1;
				
				if(cont > 14){
					
					break;
					
				}
			
			}
			
			 // Impresion en pantalla.
			cout << "\n1- Siguientes Registros \n2- Actualizar Monitoreo \n3- Salir \n \n>>> ";
			cin >> opcion;
			
			if(opcion == 1){
				
				system("cls");
				
				cont = 0;
				
				// Impresion en pantalla.
				cout << "Fecha" << "		" << "Hora" << "		" << "Usuario" << "		" << "Alerta" << "		" << "Zona/Cod" << "	" << "Descripcion" << "\n";
				
			}
			
			if(opcion == 2){
				
				archivo.close();
				
				system("cls");
				
				bandera = false;
				
				monitorear(identificacion); // Llamada a la funcion
				
			}
			
			if(opcion == 3){
				
				bandera = false;
				
			}

		}while(bandera == true);
		
	}
	
	archivo.close();
	
	system("cls");	

}
	
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
