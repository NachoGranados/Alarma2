#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;

void crear_archivo(string identificacion){ // Esta funcion se utiliza para crear por primera vez el archivo que contendra las zonas estableciadas por el usuario.
	
	// Definicion de variables a utilizar.
	string descripcion;
	string dispositivo;
	string nombre;
	string zona;
	ofstream archivo;
	
	// Impresiones en pantalla, junto con la respectiva asignacion de variables que se piden.				
	cout << "Digite el numero de zona que desea agregar \n>>> ";
	cin >> zona;
	
	system("cls");
	
	cout << "Digite la descripcion de la zona \n>>> ";
	cin >> descripcion;	
					
	system("cls");
	
	cout << "Digite el dispositivo de proteccion instalado en la zona \n>>> ";
	cin >> dispositivo;	
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(Zonas).txt";
	archivo.open(nombre.c_str(),ios::out);
	archivo << zona << "\n" << descripcion << "\n" << dispositivo << "\n";
	archivo.close();
	
	system("cls");
	
}

void agregar_zona(string identificacion){ // Funcion que agrega una zona a la lista de zonas.
	
	// Definicion de variables a utilizar.
	string descripcion;
	string dispositivo;
	string nombre;
	string guia;
	string zona;
	ofstream archivo;
	ifstream otro;

	// Creacion y lectura de archvo.
	nombre = identificacion + "(AD).txt";
	otro.open(nombre.c_str(),ios::in);
	
	getline(otro,guia);
	
	otro.close();


	if(guia == "desarmado"){ // Condicion que determina si la zona esta armada o desarmada.
		
		// Impresiones en pantalla, junto con la respectiva asignacion de variables que se piden.
		cout << "Digite el numero de zona que desea agregar \n>>> ";
		cin >> zona;
		
		system("cls");
		
		cout << "Digite la descripcion de la zona \n>>> ";
		cin >> descripcion;	
						
		system("cls");
		
		cout << "Digite el dispositivo de proteccion instalado en la zona \n>>> ";
		cin >> dispositivo;	
		
		// Creacion y edicion de archvo.
		nombre = identificacion + "(Zonas).txt";
		archivo.open(nombre.c_str(),ios::app);
		archivo << zona << "\n" << descripcion << "\n" << dispositivo << "\n";
		archivo.close();
		
		system("cls");
			
		}else{
		
			cout << "No se puede agregar la zona porque el sistema se encuentra armado \n \n";
		
		}
		
	}

void eliminar(string identificacion,string opcion,string zona){ // Esta funcion se utiliza para eliminar las zonas establecidas.
	
	// Definicion de variables a utilizar.
	ifstream archivo;
	ifstream otro;
	ofstream nuevo;
	string guia;
	string linea;
	string datos;
	string nombre;
	
	// Creacion y lectura de archvo.
	nombre = identificacion + "(AD).txt";
	otro.open(nombre.c_str(),ios::in);
	
	getline(otro,guia);
	
	otro.close();
		
	if(guia == "desarmado"){ // Condicion que determina si la zona esta armada o desarmada.
		
		// Apertura del archivo.
		nombre = identificacion + "(Zonas).txt";
		archivo.open(nombre.c_str(),ios::in);
	
		while(!archivo.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
		
			getline(archivo,linea);
			
			if(linea != zona){ // Si la linea es diferente de la zona, entonces se concatenara a un string.
				
				datos = datos + linea + "\n";
					
			}else{
				
				for (int i = 0; i < 2; i++){ // Iteracion utilizada para eliminar las linea donde se encuentra la informacion de las zonas.
					
					getline(archivo,linea);
				
				}
				
			}
				
		}
		
		// Creacion y edicion de archvo.
		nuevo.open(nombre.c_str(),ios::out);
		nuevo << datos;
		nuevo.close();
		
		if(opcion == "Si" or opcion == "si"){ // Condicion que determina si el usuario desea actualizar la informacion de la zona.
			
			agregar_zona(identificacion);
			
		}
		
	}else{
		
		cout << "No se puede eliminar la zona porque el sistema se encuentra armado \n \n";
		
	}
		
}

void dar_informacion(string identificacion,string zona){ // Funcion que se utiliza para dar la informacion de cada zona.
	
	// Definicion de variables a utilizar.
	ifstream archivo;
	string linea;
	string nombre;
	string opcion;
	
	// Apertura del archivo.
	nombre = identificacion + "(Zonas).txt";
	archivo.open(nombre.c_str(),ios::in);
	
	while(!archivo.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
	
		getline(archivo,linea);
		
		if(linea == zona){ // Si se encuentra la zona buscada, imprimira sus datos en pantalla.
			
			cout << "Identificacion del sistema de alarma: " << identificacion << "\n";
				
			cout << "Numero de zona: " << linea << "\n";
			
			zona = linea;
			
			getline(archivo,linea);
			
			cout << "Descripcion de la zona: " << linea << "\n";
			
			getline(archivo,linea);
			
			cout << "Dispositivo de proteccion instalado en la zona: " << linea << "\n \n";
			
		}
	
	}
	
	archivo.close();

	cout << "Desea cambiar la informacion actual? (Si o No) \n>>> "; // Condicion que determina se se desea actualizar la informacion de la zona actual.
	cin >> opcion;
	cout << "\n";
	
	system("cls");

	if(opcion == "Si" or opcion == "si"){
	
		eliminar(identificacion,opcion,zona);
		
	}
	
}

void imprimir_zonas(string identificacion){ // Funcion que mostrara la lista de las zonas en pantalla.
	
	// Definicion de variables a utilizar.
	ifstream archivo;
	string nombre;
	string linea;
	string datos;
	int cont = 0;
	
	// Apertura del archivo.
	nombre = identificacion + "(Zonas).txt";
	archivo.open(nombre.c_str(),ios::in);
	
	cout << "Zona		" << "Descripcion		" << "Dispositivo \n";
	
	while(!archivo.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
		
		for (int i = 0; i < 3; i++){ // Iteracion que sirvira para agregar espacios al momento de imprimir la lista zonas.
						
			getline(archivo,linea);
			
			if(i == 2){
				
				cout << "	";
				
			}
			
			cout << linea << "		";
					
		}
		
		cout << "\n";
		
	}
	
}

void crear_principal(string identificacion){ // Funcion que crea la contraseņa por primera vez

	// Definicion de variables a utilizar.
	string nombre;
	string principal;
	ofstream archivo;
		
	// Creacion y edicion de archvo.
	nombre = identificacion + "(Principal).txt";
	archivo.open(nombre.c_str(),ios::out);
	
	cout << "Digite la contrasena principal que desea utilizar \n>>> ";
	cin >> principal;
	
	archivo << principal;
	
	archivo.close();
	
	system("cls");
		
}

void eliminar_principal(string identificacion){ // Funcion que actualiza la contraseņa principal.
	
	// Definicion de variables a utilizar.
	string nombre;
	
	nombre = identificacion + "(Principal).txt";
	remove(nombre.c_str());
	
	crear_principal(identificacion);
	
}

void crear_secundarias(string identificacion){ // Funcion que crea las contraseņas secundarias.
	
	// Definicion de variables a utilizar.
	string nombre;
	string secundaria;
	ofstream archivo;
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(Secundarias).txt";
	archivo.open(nombre.c_str(),ios::out);
	
	cout << "Digite la contrasena secundaria que desea agregar \n>>> ";
	cin >> secundaria;
	
	archivo << secundaria << "\n";
	
	archivo.close();
	
	system("cls");	
	
}

void agregar_secundarias(string identificacion){ // Funcion que agrega contraseņas secundarias.
	
	// Definicion de variables a utilizar.
	string nombre;
	string secundaria;
	ofstream archivo;
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(Secundarias).txt";
	archivo.open(nombre.c_str(),ios::app);
	
	cout << "Digite la contrasena secundaria que desea agregar \n>>> ";
	cin >> secundaria;
	
	archivo << secundaria << "\n";
	
	archivo.close();
	
	system("cls");

}

void eliminar_secundaria(string identificacion,string secundaria,string opcion){ // Funcion que elimina contraseņas secundarias.
	
	// Definicion de variables a utilizar.
	string nombre;
	string linea;
	string datos;
	ifstream archivo;
	ofstream nuevo;
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(Secundarias).txt";
	archivo.open(nombre.c_str(),ios::in);

	while(!archivo.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
	
		getline(archivo,linea);
		
		if(linea != secundaria){ // Si la linea es diferente de la zona, entonces se concatenara a un string.
			
			datos = datos + linea + "\n";
				
		}else{
				
			getline(archivo,linea);
			
		}
			
	}

	// Creacion y edicion de archvo.
	nombre = identificacion + "(Secundarias).txt";
	nuevo.open(nombre.c_str(),ios::out);
	
	nuevo << datos;
	
	nuevo.close();
	
	if(opcion == "Si" or opcion == "si"){ // Condicion que determina si el usuario desea actualizar la informacion de la zona.
			
		agregar_secundarias(identificacion);
		
	}
	
}

bool buscar_contrasena(string identificacion,string contrasena){ // Funcion que se utiliza para verificar si la contraseņa digitada existe o no.
	
	// Definicion de variables a utilizar.
	bool guia = false;
	string nombre;
	string linea;
	ifstream principal;
	ifstream secundarias;
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(Principal).txt";
	principal.open(nombre.c_str(),ios::in);	
	
	while(! principal.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
		
		getline(principal,linea);
		
		if(linea == contrasena){ // Condicion que determina si la contraseņa existe o no.
			
			guia = true;
			
			break;
			
		}
		
	}
	
	principal.close();

	nombre = identificacion + "(Secundarias).txt";
	secundarias.open(nombre.c_str(),ios::in);	
	
	while(! secundarias.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
		
		getline(secundarias,linea);
		
		if(linea == contrasena){ // Condicion que determina si la contraseņa existe o no.
			
			guia = true;
			
			break;
			
		}
		
	}
	
	secundarias.close();
	
	return guia;
	
}

void crear_bitacora(string identificacion,string usuario,string alerta,string zona){ // Funcion que crear la bitacora por primera vez.
	
	// Definicion de variables a utilizar.
	string nombre;
	ofstream archivo;
	string linea;
	ifstream otro;
	string fecha;
	ifstream prueba;
	ofstream bitacora;
	string lugar;
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(Zonas).txt";
	otro.open(nombre.c_str(),ios::in);
	
	if(zona != "0"){
		
		while(! otro.eof())	{ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
			
			getline(otro,linea);
			
			if(linea == zona){ // Asignacion de la decripcion de la zona.
				
				getline(otro,linea);
				
				lugar = linea;
				
				break;
				
			}
		
		}		
		
	}else{
		
		linea = " ";
		
	}
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(Bitacora).txt";
	archivo.open(nombre.c_str(),ios::out);	
	
	// Utilizacion de la libreria de tiempo para poder obtener la fecha y la hora de la computadora.
	time_t tiempo = time(NULL);
    struct tm *actual = localtime(&tiempo);
    char output[10];
    strftime(output,10,"%d/%m/%y",actual);
    
	time_t tiempo_ahora;
	time(&tiempo_ahora);
	
	struct tm *puntero = localtime(&tiempo_ahora);
	
	// Edicion del archivo.
	archivo << "\n";
	archivo << output << "\n";
	archivo << puntero -> tm_hour << ":" << puntero -> tm_min << ":" << puntero -> tm_sec << "\n";
	archivo << usuario << "\n";
	archivo << alerta << "\n";
	archivo << zona << "\n"; 
	archivo << lugar;
	
    archivo.close();
    
    prueba.open("Bitacora.txt",ios::in);
    
	bitacora.open("Bitacora.txt",ios::out);
	
	// Edicion del archivo.
	bitacora << "\n";
	bitacora << output << "\n";
	bitacora << puntero -> tm_hour << ":" << puntero -> tm_min << ":" << puntero -> tm_sec << "\n";
	bitacora << usuario << "\n";
	bitacora << alerta << "\n";
	bitacora << zona << "\n"; 
	bitacora << lugar;
    
    bitacora.close();
    
}

void actualizar_bitacora(string identificacion,string usuario,string alerta,string zona){ // Funcion que agrega cualquier accion o alerta a la bitacora.

	// Definicion de variables a utilizar.
	string nombre;
	ofstream nuevo;
	string linea;
	ifstream otro;
	string fecha;
	string palabras;
	string datos;
	ifstream bitacora;
	ofstream bitacora_nueva;
	string lugar;
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(Zonas).txt";
	otro.open(nombre.c_str(),ios::in);
	
	if(zona != "0"){
		
		while(! otro.eof())	{ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
			
			getline(otro,linea);
			
			if(linea == zona){ // Asignacion de la decripcion de la zona.
				
				getline(otro,linea);
				
				lugar = linea;
				
				break;
				
			}
		
		}		
		
	}else{
		
		linea = " ";
		
	}
	
	otro.close();
	
	// Creacion y edicion de archvo.
	ifstream archivo;
	
	nombre = identificacion + "(Bitacora).txt";
	archivo.open(nombre.c_str(),ios::in);	
	
	while(!archivo.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
	
		getline(archivo,linea);
		
		datos = datos + linea + "\n"; // Se agrega cada linea del archivo a un string.
	
	}
	
	archivo.close();
	
	nombre = identificacion + "(Bitacora).txt";
	nuevo.open(nombre.c_str(),ios::out);	
	
	// Utilizacion de la libreria de tiempo para poder obtener la fecha y la hora de la computadora.
	time_t tiempo = time(NULL);
    struct tm *actual = localtime(&tiempo);
    char output[10];
    strftime(output,10,"%d/%m/%y",actual);
    
	time_t tiempo_ahora;
	time(&tiempo_ahora);
	
	struct tm *puntero = localtime(&tiempo_ahora);
	
	// Edicion del archivo.
	nuevo << "\n";
	nuevo << output << "\n";
	nuevo << puntero -> tm_hour << ":" << puntero -> tm_min << ":" << puntero -> tm_sec << "\n";
	nuevo << usuario << "\n";
	nuevo << alerta << "\n";
	nuevo << zona << "\n"; 
	nuevo << lugar << "\n";
	nuevo << datos;
	
    nuevo.close();
	
	bitacora.open("Bitacora.txt",ios::in);	
	
	while(!bitacora.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
	
		getline(bitacora,linea);
		
		palabras = palabras + linea + "\n";
	
	}
	
	bitacora.close();
    
	bitacora_nueva.open("Bitacora.txt",ios::out);
	
	// Edicion del archivo.
	bitacora_nueva << "\n";
	bitacora_nueva << output << "\n";
	bitacora_nueva << puntero -> tm_hour << ":" << puntero -> tm_min << ":" << puntero -> tm_sec << "\n";
	bitacora_nueva << usuario << "\n";
	bitacora_nueva << alerta << "\n";
	bitacora_nueva << zona << "\n"; 
	bitacora_nueva << lugar << "\n";
	bitacora_nueva << palabras;
    
    bitacora_nueva.close();
    
}

void imprimir_bitacora(string identificacion){ // Funcion que muestra la bitacora en pantalla.
	
	// Definicion de variables a utilizar.
	string nombre;
	string linea;
	ifstream archivo;
	bool guia = false;
	
	// Creacion y edicion de archvo.
	nombre = identificacion + "(Bitacora).txt";
	archivo.open(nombre.c_str(),ios::in);
	
	if(archivo.fail()){ // COndicion que vreirifaca si existen registros o no.
		
		cout << "Aun no existen registros \n \n";
		
	}else{

		cout << "Fecha" << "		" << "Hora" << "		" << "Usuario" << "		" << "Alerta" << "		" << "Zona/Cod" << "	" << "Descripcion" << "\n";
		
		while(!archivo.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
			
			if(guia == false){ // Condicion que servira para hacer un salto de linea un unica vez.
				
				getline(archivo,linea);
				
				guia = true;
				
			}
			
			for (int i = 0; i < 7; i++){ // Algoritmo que imprimira cada una de las lineas del archivo de en una manera ordenada.
			
				getline(archivo,linea);
				
				if(linea == "armar"){
					
					cout << "	";
					
					cout << linea;
					
					cout << "		";
					
					getline(archivo,linea);
					
					i++;
					
				}
				
				if(i == 3 or i == 5){ // Agregara espacios de ser necesario.
					
					cout << "	";
					
				}
				
				if(i != 6){
					
				cout << linea << "	";	
					
				}
			
			}
		
			cout << "\n";
		
		}	
		
	}
	
	archivo.close();
	
}

string obtener_usuario(string identificacion){ // Funcion que buscara el usuario correspondiente.
	
	// Definicion de variables a utilizar.
	string linea;
	ifstream archivo;

	// Creacion y edicion de archvo.
	archivo.open("Usuarios.txt",ios::in);
	
	while(!archivo.eof()){ // Iteracion que finaliza cuando se llega a la ultima linea del mismo.
	
		getline(archivo,linea);
		
		if(linea == identificacion){ // Condicion que busca la identificacion para retornar el usuario.
			
			getline(archivo,linea);
			
			break;
			
		}
	
	}	
	
	return linea;
	
}

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
		
		if(archivo.fail()){ // Condicion que servira para crear la contraseņa principal.
			
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
						
						for (int i = 0; i < 6; i++){ // Iteracion para buscar la contraseņa secundaria.
							
							getline(archivo,linea);
							
							if(linea == secundaria){
								
								guia = true;
								
							}
							
						}
							
						if(guia == true){ // Condicion para buscar la contraseņa secundaria.
							
							cout << "Una de sus contrasenas secundarias es: " << secundaria << "\n \n";// Impresion en pantalla.
							
							cout << "Desea actualizar su contrasena? (Si o No) \n>>> ";// Impresion en pantalla.
							cin >> opcion;
							
							system("cls");
							
							if(opcion == "Si" or opcion == "si"){
								
								eliminar_secundaria(identificacion,secundaria,opcion);// Llamada de la funcion.
								
							}
							
	
						}else{ // Condicion para buscar la contraseņa secundaria.
						
							cout << "Su contrasena no existe, desea crearla? (Si o No) \n>>> ";// Impresion en pantalla.
							cin >> opcion;
							
							system("cls");
							
							if(opcion == "Si" or opcion == "si"){ // Condicion para buscar la contraseņa secundaria.
								
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
