#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;




int main(){
	
	// Definicion de variables a utilizar.
	string identificacion;
	ifstream archivo;
	string linea;
	string usuario;
	int guia = 0;
	ofstream nuevo;
	
	// Creacion y edicion de archvo.
	archivo.open("Bitacora.txt",ios::in);
	
	if(archivo.fail()){
		
		nuevo.open("Bitacora.txt",ios::out);
		nuevo.close();
		
	   }
	   
	archivo.close();
	
	// Impresiones en pantalla, junto con la asignacion de las variables solicitadas.
	cout << "Digite la identificacion del sistema de alarma \n>>> ";
	cin >> identificacion;
	
	system("cls");
	
	archivo.open("Usuarios.txt",ios::in);
	
	if(archivo.fail()){ // Condicion que determina si existe algun usuario.
		
		cout << "Por favor crear un usuario desde el centro de monitoreo \n";
		
		exit(1);
		
	}
	
	while(! archivo.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
		
		getline(archivo,linea);
		
		if(linea == identificacion){ // Condicion que busca la identificacion en su respectivo archivo.
			
			guia = true;
			
		}
		
	}
	
	if(guia == true){
		
		// Definicion de variables a utilizar.
		string nombre;
		ifstream archivo;
		
		// Creacion y edicion de archvo.
		nombre = identificacion + "(Principal).txt";
		archivo.open(nombre.c_str(),ios::in);
		
		if(archivo.fail()){ // Condicion que servira para crear la contraseña principal.
			
			archivo.close();
			crear_principal(identificacion);
									
		}
		
		do{
			
			// Definicion de variables a utilizar.
			int opcion;
			string nombre;
			ifstream archivo;
			string linea;
			
			// Impresion en pantalla.
			cout << "Bienvenido al Menu de Usuario \n \nCual opcion desea realizar? \n \n1- Activar Sistema \n2- Desactivar Sistema \n3- Armar Sistema \n4- Desarmar Sistema \n5- Programar Zonas \n6- Borrar Zonas \n7- Lista de Zonas \n8- Bitocora \n9- Borrar Bitacora \n10- Establecer codigo de acceso principal \n11- Establecer codigos de acceso secundarios \n12- Fuego (Alerta) \n13- Ayuda (Alerta) \n14- Panico (Alerta) \n15- Manual de Usuario \n16- Salir \n \n>>> ";
			cin >> opcion;
			
			system("cls");
			
			switch(opcion){ // Esta sera el algoritmo que servira para realizar cada una de las funciones que desee realizar el usuario.
				
				case 1:{
					
					// Definicion de variables a utilizar.
					string contrasena;
					ifstream otro;
					bool guia;
					
					// Impresion en pantalla.
					cout << "Digite la contrasena principal o secundaria \n>>> ";
					cin >> contrasena;
					
					system("cls");
					
					guia = buscar_contrasena(identificacion,contrasena); // Llamada de la funcion.
					
					if(guia == 1){
						
						// Creacion y edicion de archvo.
						nombre = identificacion + "(estado).txt";
						archivo.open(nombre.c_str(),ios::in);
						
						getline(archivo,linea);
						
						archivo.close();
						
						if(linea == "desactivado"){
							
							// Definicion de variables a utilizar.
							ofstream archivo;
							
							// Creacion y edicion de archvo.
							nombre = identificacion + "(estado).txt";
							archivo.open(nombre.c_str(),ios::out);
							archivo << "activado";
							archivo.close();
							cout << "Se ha activado el sistema exitosamente\n \n";
							
							// Creacion y edicion de archvo.
							nombre = identificacion + "(Bitacora).txt";
							archivo.open(nombre.c_str(),ios::in);
							
							usuario = obtener_usuario(identificacion); // Llamada de la funcion.
							
							if(archivo.fail()){
								
								archivo.close();
								crear_bitacora(identificacion,usuario,"ACTIVACION","0"); // Llamada de la funcion.
								
							}else{
								
								actualizar_bitacora(identificacion,usuario,"ACTIVACION","0"); // Llamada de la funcion.
								
							}
							
							archivo.close();
							
						}else{
							
							cout << "Su sistema se encuentra activo \n \n";// Impresion en pantalla.
							
						}	
						
					}else{
						
						cout << "Contrasena incorrecta \n \n";// Impresion en pantalla.
						
					}
					
					break;
						
				}
				
				case 2:{
					
					// Definicion de variables a utilizar.
					string contrasena;
					ifstream otro;
					bool guia;
					
					// Impresion en pantalla.
					cout << "Digite la contrasena principal o secundaria \n>>> ";
					cin >> contrasena;
					
					system("cls");
					
					guia = buscar_contrasena(identificacion,contrasena); // Llamada de la funcion.
					
					if(guia == 1){
						
						// Creacion y edicion de archvo.
						nombre = identificacion + "(estado).txt";
						archivo.open(nombre.c_str(),ios::in);
						
						getline(archivo,linea);
						
						if(linea == "activado"){
							
							// Definicion de variables a utilizar.
							ofstream archivo;
							
							// Creacion y edicion de archvo.
							nombre = identificacion + "(estado).txt";
							archivo.open(nombre.c_str(),ios::out);
							archivo << "desactivado";
							archivo.close();
							cout << "Se ha desactivado el sistema exitosamente \n \n"; // Impresion en pantalla.
							
							// Creacion y edicion de archvo.
							nombre = identificacion + "(Bitacora).txt";
							archivo.open(nombre.c_str(),ios::in);
							
							usuario = obtener_usuario(identificacion);
							
							if(archivo.fail()){
								
								archivo.close();
								crear_bitacora(identificacion,usuario,"DESACTIVACION","0"); // Llamada de la funcion.
								
							}else{
								
								actualizar_bitacora(identificacion,usuario,"DESACTIVACION","0"); // Llamada de la funcion.
								
							}
							
							archivo.close();
							
						}else{
							
							cout << "No se puede desactivar el sistema porque se encuentra desactivado \n \n"; // Llamada de la funcion.
							
						}
						
					}else{
						
						cout << "Contrasena incorrecta \n \n"; // Llamada de la funcion.
						
					}
					
					break;
						
				}	
					
				case 3:{
					
					// Definicion de variables a utilizar.
					string contrasena;
					ifstream otro;
					bool guia;
					string zona;
					string usuario;
					
					 // Impresion en pantalla.
					cout << "Digite la contrasena principal o secundaria \n>>> ";
					cin >> contrasena;
					
					system("cls");
					
					 // Impresion en pantalla.
					cout << "Digite la zona que desea armar \n>>> ";
					cin >> zona;
					
					system("cls");
					
					guia = buscar_contrasena(identificacion,contrasena); // Llamada de la funcion.
					
					if(guia == 1){
						
						// Creacion y edicion de archvo.
						nombre = identificacion + "(AD).txt";
						archivo.open(nombre.c_str(),ios::in);
						
						getline(archivo,linea);
						
						if(linea == "desarmado"){
							
							// Definicion de variables a utilizar.
							ofstream archivo;
							
							// Creacion y edicion de archvo.
							nombre = identificacion + "(AD).txt";
							archivo.open(nombre.c_str(),ios::out);
							archivo << "armado";
							archivo.close();
							cout << "Se ha armado la zona exitosamente\n \n";
							
							// Creacion y edicion de archvo.
							nombre = identificacion + "(Bitacora).txt";
							archivo.open(nombre.c_str(),ios::in);
							
							usuario = obtener_usuario(identificacion); // Llamada de la funcion.
							
							if(archivo.fail()){
								
								archivo.close();
								crear_bitacora(identificacion,usuario,"armar",zona); // Llamada de la funcion.
								
							}else{
								
								actualizar_bitacora(identificacion,usuario,"armar",zona); // Llamada de la funcion.
								
							}
							
							archivo.close();
							
						}else{
							
							cout << "La zona se encuentra armada \n \n"; // Impresion en pantalla.
							
						}	
						
					}else{
						
						cout << "Contrasena incorrecta \n \n"; // Impresion en pantalla.
						
					}
					
					break;
						
				}
				
				case 4:{
					
					// Definicion de variables a utilizar.
					string contrasena;
					ifstream otro;
					bool guia;
					string zona;
					
					 // Impresion en pantalla.
					cout << "Digite la contrasena principal o secundaria \n>>> ";
					cin >> contrasena;
					
					system("cls");
					
					 // Impresion en pantalla.
					cout << "Digite la zona que desea desarmar \n>>> ";
					cin >> zona;
					
					system("cls");
					
					guia = buscar_contrasena(identificacion,contrasena); // Llamada de la funcion.
					
					if(guia == 1){
						
						// Creacion y edicion de archvo.
						nombre = identificacion + "(AD).txt";
						archivo.open(nombre.c_str(),ios::in);
						
						getline(archivo,linea);
						
						if(linea == "armado"){
							
							// Definicion de variables a utilizar.
							ofstream archivo;
							
							// Creacion y edicion de archvo.
							nombre = identificacion + "(AD).txt";
							archivo.open(nombre.c_str(),ios::out);
							archivo << "desarmado";
							archivo.close();
							cout << "Se ha desarmado la zona exitosamente\n \n"; // Impresion en pantalla.
							
							nombre = identificacion + "(Bitacora).txt";
							archivo.open(nombre.c_str(),ios::in);
							
							usuario = obtener_usuario(identificacion);
							
							if(archivo.fail()){
								
								archivo.close();
								crear_bitacora(identificacion,usuario,"desarmar",zona); // Llamada de la funcion.
								
							}else{
								
								actualizar_bitacora(identificacion,usuario,"desarmar",zona); // Llamada de la funcion.
								
							}
							
							archivo.close();
							
						}else{
							
							cout << "No se puede desarmar la zona porque se encuentra desarmada \n \n"; // Impresion en pantalla.
							
						}	
						
					}else{
						
						cout << "Contrasena incorrecta \n \n"; // Impresion en pantalla.
						
					}
					
					break;
						
				}
					
				case 5:{
				
					// Definicion de variables a utilizar.
					string zona;
					string principal;
					bool bandera = false;
					ifstream archivo;
					ifstream otro;
					
					 // Impresion en pantalla.
					cout << "Digite la contrasena principal \n>>> ";
					cin >> principal;
					
					system("cls");
					
					// Creacion y edicion de archvo.
					nombre = identificacion + "(Principal).txt";
					otro.open(nombre.c_str(),ios::in);
					
					getline(otro,linea);
					
					if(linea == principal){
						
						// Creacion y edicion de archvo.
						nombre = identificacion + "(Zonas).txt";
						archivo.open(nombre.c_str(),ios::in);
						
						if (archivo.fail()){
							
							archivo.close();
							cout << "Su zona no existe. Por favor cree una \n \n"; // Impresion en pantalla.
							crear_archivo(identificacion);
							break;
							
						}else{
							
							 // Impresion en pantalla.
							cout << "Digite el numero de zona \n>>> ";
							cin >> zona;
							
							system("cls");
												
							while(!archivo.eof()){ // Iteracion que termina cuando se llega a la ultima linea del archivo.
								
								getline(archivo,linea);
								
								if (linea == zona){ // Condicion que determina si se quiera actualizar la informacion.
									
									dar_informacion(identificacion,zona);
									bandera = true;
									break;
									
								}
									
							}
							
							if(bandera == false){
								
								 // Impresion en pantalla.
								cout << "Su zona no existe. Por favor cree una \n \n";		
								agregar_zona(identificacion);
								archivo.close();
								break;
								
							}
										
						}	
						
					}else{
						
						cout << "Contrasena incorrecta \n \n"; // Impresion en pantalla.
						
					}
					
					break;
						
				}
				
				case 6:{
					
					// Definicion de variables a utilizar.
					string zona;
					string principal;
					bool bandera = false;
					ifstream archivo;
					ifstream otro;
					
					 // Impresion en pantalla.
					cout << "Digite la contrasena principal \n>>> ";
					cin >> principal;
					
					system("cls");
					
					// Creacion y edicion de archvo.
					nombre = identificacion + "(Principal).txt";
					otro.open(nombre.c_str(),ios::in);
					
					getline(otro,linea);
					
					if(linea == principal){
						
						// Definicion de variables a utilizar.
						string opcion = "No";
						string zona;
						
						 // Impresion en pantalla.
						cout << "Digite el numero de zona \n>>> ";
						cin >> zona;
							
						system("cls");
						
						eliminar(identificacion,opcion,zona);
						
					}else{
						
						cout << "Contrasena incorrecta \n \n"; // Impresion en pantalla.
						
					}
					
					break;
						
				}
					
				case 7:{
					
					// Definicion de variables a utilizar.
					string contrasena;
					ifstream otro;
					bool guia;
					
					 // Impresion en pantalla.
					cout << "Digite la contrasena principal o secundaria \n>>> ";
					cin >> contrasena;
					
					system("cls");
					
					guia = buscar_contrasena(identificacion,contrasena); // Llamada de la funcion.
					
					if(guia == 1){
						
						imprimir_zonas(identificacion);	// Llamada de la funcion.
						
					}else{
						
						cout << "Contrasena incorrecta \n \n"; // Impresion en pantalla.
						
					}
					
					break;
						
				}		
					
				case 8:{
					
					// Definicion de variables a utilizar.
					string principal;
					string usuario;
					ifstream otro;
					
					 // Impresion en pantalla.
					cout << "Digite la contrasena principal \n>>> ";
					cin >> principal;
					
					system("cls");
					
					// Creacion y edicion de archvo.
					nombre = identificacion + "(Principal).txt";
					otro.open(nombre.c_str(),ios::in);
					
					getline(otro,linea);
					
					if(linea == principal){
						
						 // Impresion en pantalla.
						cout << "Digite su usuario actual \n>>> ";
						cin >> usuario;
						
						system("cls");
						
						imprimir_bitacora(identificacion); // Llamada de la funcion.
						
						cout << "\n";
						
					}else{
						
						cout << "Contrasena incorrecta \n \n"; // Impresion en pantalla.
						
					}
					
					break;
						
					}
					
				case 9:{
					
					// Definicion de variables a utilizar.
					string principal;
					ifstream otro;
					
					 // Impresion en pantalla.
					cout << "Digite la contrasena principal \n>>> ";
					cin >> principal;
					
					system("cls");
					
					// Creacion y edicion de archvo.
					nombre = identificacion + "(Principal).txt";
					otro.open(nombre.c_str(),ios::in);
					
					getline(otro,linea);
					
					if(linea == principal){
						
						continue;	
						
					}else{
						
						cout << "Contrasena incorrecta \n \n"; // Impresion en pantalla.
						
					}
					
					break;
						
					}

				case 10:{
					
					// Definicion de variables a utilizar.
					string nombre;
					string linea;
					string opcion;
					string principal;
					
					// Creacion y edicion de archvo.
					nombre = identificacion + "(Principal).txt";
					archivo.open(nombre.c_str(),ios::in);
						
					getline(archivo,linea);
					
					archivo.close();
					
					 // Impresion en pantalla.
					cout << "Digite la contrasena principal \n>>> ";
					cin >> principal;
					
					system("cls");
					
					if(linea == principal){
						
						cout << "Su contrasena principal es: " << principal << "\n \n"; // Impresion en pantalla.
						
						 // Impresion en pantalla.
						cout << "Desea actualizar su contrasena? (Si o No) \n>>> ";
						cin >> opcion;
						
						system("cls");
						
						if(opcion == "Si" or opcion == "si"){
							
							eliminar_principal(identificacion);// Llamada de la funcion.
							
						}
							
					}else{
						
						cout << "Contrasena incorrecta \n \n"; // Impresion en pantalla.
					
					}
					
					break;
					
				}
					
				case 11:{

					// Definicion de variables a utilizar.
					string opcion;
					string secundaria;
					bool guia = false;
					
					// Creacion y edicion de archvo.
					nombre = identificacion + "(Secundarias).txt";
					archivo.open(nombre.c_str(),ios::in);
					
					if(archivo.fail()){
						
						archivo.close();
						crear_secundarias(identificacion);
												
					}else{
						
						 // Impresion en pantalla.
						cout << "Digite alguna de contrasenas secundarias \n>>> ";
						cin >> secundaria;
						
						system("cls");
						
						for (int i = 0; i < 6; i++){ // Iteracion para buscar la contraseña secundaria.
							
							getline(archivo,linea);
							
							if(linea == secundaria){
								
								guia = true;
								
							}
							
						}
							
						if(guia == true){ // Condicion para buscar la contraseña secundaria.
							
							cout << "Una de sus contrasenas secundarias es: " << secundaria << "\n \n";// Impresion en pantalla.
							
							cout << "Desea actualizar su contrasena? (Si o No) \n>>> ";// Impresion en pantalla.
							cin >> opcion;
							
							system("cls");
							
							if(opcion == "Si" or opcion == "si"){
								
								eliminar_secundaria(identificacion,secundaria,opcion);// Llamada de la funcion.
								
							}
							
	
						}else{ // Condicion para buscar la contraseña secundaria.
						
							cout << "Su contrasena no existe, desea crearla? (Si o No) \n>>> ";// Impresion en pantalla.
							cin >> opcion;
							
							system("cls");
							
							if(opcion == "Si" or opcion == "si"){ // Condicion para buscar la contraseña secundaria.
								
								agregar_secundarias(identificacion);// Llamada de la funcion.
								
							}
						
						}
						
					}
					
					break;
					
				}
				
				case 12:{
					
					// Definicion de variables a utilizar.
					string zona;
					
					// Impresion en pantalla.
					cout << "Digite la zona en la que desea generar la alerta \n>>> ";
					cin >> zona;
					
					system("cls");
					
					// Creacion y edicion de archvo.
					nombre = identificacion + "(Bitacora).txt";
					archivo.open(nombre.c_str(),ios::in);
					
					usuario = obtener_usuario(identificacion);// Llamada de la funcion.
					
					if(archivo.fail()){
						
						archivo.close();
						crear_bitacora(identificacion,usuario,"FUEGO	",zona);// Llamada de la funcion.
						
					}else{
						
						actualizar_bitacora(identificacion,usuario,"FUEGO	",zona);// Llamada de la funcion.
						
					}
					
					archivo.close();

					break;
					
				}
					
				case 13:{
					
					// Definicion de variables a utilizar.
					string zona;
					
					// Impresion en pantalla.
					cout << "Digite la zona en la que desea generar la alerta \n>>> ";
					cin >> zona;
					
					system("cls");
					
					// Creacion y edicion de archvo.
					nombre = identificacion + "(Bitacora).txt";
					archivo.open(nombre.c_str(),ios::in);
					
					usuario = obtener_usuario(identificacion);// Llamada de la funcion.
					
					if(archivo.fail()){
						
						archivo.close();
						crear_bitacora(identificacion,usuario,"AYUDA	",zona);// Llamada de la funcion.
						
					}else{
						
						actualizar_bitacora(identificacion,usuario,"AYUDA	",zona);// Llamada de la funcion.
						
					}
					
					archivo.close();

					break;
					
				}
				
				case 14:{	
					
					// Definicion de variables a utilizar.
					string zona;
					
					// Impresion en pantalla.
					cout << "Digite la zona en la que desea generar la alerta \n>>> ";
					cin >> zona;
					
					system("cls");
					
					// Creacion y edicion de archvo.
					nombre = identificacion + "(Bitacora).txt";
					archivo.open(nombre.c_str(),ios::in);
					
					usuario = obtener_usuario(identificacion);// Llamada de la funcion.
					
					if(archivo.fail()){
						
						archivo.close();
						crear_bitacora(identificacion,usuario,"PANICO	",zona);// Llamada de la funcion.
						
					}else{
						
						actualizar_bitacora(identificacion,usuario,"PANICO	",zona);// Llamada de la funcion.
						
					}
					
					archivo.close();

					break;
					
				}
				
				case 15:{	
					
					// Funcion que abrira el manual de usuario.
					ShellExecute(GetDesktopWindow(), "open", "manual_de_usuario_alarma2.pdf", NULL, NULL, SW_SHOWNORMAL);
					break;
					
				}
				
				case 16:{
					
					// Funcion para salir del programa.
					cout << "Hasta pronto \n";
					exit(1);
					break;
					
				}
					
				default:
					
					cout << "Opcion incorrecta \n \n"; // Validacion en casa de que la opcion digita no exista.
				
			}	
			
		}while(true);
		
	}else{
		
		cout << "Su usuario no existe \n"; // Impresion en pantalla.
		
		exit(1);
		
	}
	
}
