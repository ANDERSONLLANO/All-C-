#include <iostream>
#include<windows.h>
#include<conio.h>
#include<string.h>
#define escribir cout
#define leer cin
using namespace std;
/* realizar un menu con las funciones del taller 8, mostrando el menu en el recuadro */
void gotoxy( int x, int y )
{
COORD coord;
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void cuadropantalla(int ancho, int largo){
	int i;
	//columna
	for(i=0;i<ancho;i++){
		gotoxy(5,i);escribir<<"\263";
		gotoxy(largo,i);escribir<<"\263";
	}
	//fila
	for(i=6;i<largo;i++){
		gotoxy(i,0);escribir<<"\304";
		gotoxy(i,ancho);escribir<<"\304";
	}
	//esquina superior izquierda
	gotoxy(5,0);escribir<<"\332";
	//esquina superior derecha
	gotoxy(largo,0);escribir<<"\277";
	//esquina inferior derecha
	gotoxy(5,ancho);escribir<<"\300";
	//esquina inferior izquierda
	gotoxy(largo,ancho);escribir<<"\331";
}
 void multiplos(int siete){
    int i,a=7;
    int d=6;
		for(i=7;i<=siete;i++){
			if (i % a ==0){

			gotoxy(35,d++);escribir<<i<<endl;
}
}
}

void sumatoria(int sumpro){
	int i,suma=0;
	for(i=0;i<=sumpro;i++){
		escribir<<i<<"+";
		suma=suma+i;
	}
	escribir<<"="<<suma;
	escribir<<" SUMATORIA "<<endl;
}
void productoria(float sumpro){
	int j;
	float producto;
	producto=1;
	
	for(j=1;j<=sumpro;j++){
		escribir<<j<<"*";
		producto=producto*j;
	}
	escribir<<"="<<producto;
	escribir<<" PRODUCTORIA "<<endl;
}

int vocales(char vocal[80]){
	int contvocales,x,i;
	contvocales=0;
	x=strlen(vocal);
	for(i=0;i<=x;i++){
		switch (vocal[i]){
		case 'a':
			contvocales++;
			break;
			case 'e':
			   contvocales++;
			   break;
			   	case 'i':
			       contvocales++;
			       break;
			   	     case 'o':
			            contvocales++;
			            break;
			   	           case 'u':
			                   contvocales++;
							   break;	
		}
	}
	
	return contvocales;
}

int cambio_caracter(char variable[80]){
	int tamanho,i;
	char x,x1;
	tamanho=strlen(variable);
	return tamanho;
}
int cantpalabras(char frase[100]){
	int x,i,palabras;
	palabras=1; 
	x=strlen(frase);
	for(i=0;i<=x;i++){
		switch (frase[i]){
		case ' ':
		palabras++;
		break;	
		}
	}
	return palabras;
}
struct notas{
	char names[30];
	char lastnames[30];
	float nota1,nota2,nota3,notdef;
};

int main(int argc, char** argv) {
	int opcion=1,t;
	while(opcion!=0)
	{
	cuadropantalla(22,78);
	system("color b5");
	gotoxy(10,5);escribir<<" MENU ";
	gotoxy(7,7);escribir<<" 1. multiplos_7 ";
	gotoxy(7,8);escribir<<" 2. productoria ";
	gotoxy(7,9);escribir<<" 3. vocales ";
	gotoxy(7,10);escribir<<" 4. cambio de caracter ";
	gotoxy(7,11);escribir<<" 5. contador de palabras de una frase ";
	gotoxy(7,12);escribir<<" 6. promedio de notas de un estudiante  ";
	gotoxy(7,13);escribir<<" 0. SALIR ";
	gotoxy(7,14);escribir<<" seleccione una opcion: ";leer>>opcion;	
	switch(opcion)
	{
	 case 1: {
				system("cls");
				system("color a0");
				cuadropantalla(22,78);
				int n,a;
				a=7;
				gotoxy(12,5);escribir<<" ingrese un valor: ";
	            gotoxy(31,5);leer>>n;
                multiplos(n);
                system("pause");
				system("cls");
				break;
			 }
	 case 2: {
				system("cls");
				system("color e2");
				cuadropantalla(22,78);
				int n;
	            gotoxy(12,9);escribir<<" ingrese un valor: "<<endl;
	            gotoxy(31,9);leer>>n;
				gotoxy(30,13);productoria(n);
				gotoxy(30,14);sumatoria(n);
				system("pause");
				system("cls");
				break;
			 }
	 case 3: {
				system("cls");
				system("color c0");
				cuadropantalla(22,78);
                char vocal[80];
				int contvocales,x;
	            leer.ignore(256,'\n');
	            gotoxy(20,8); escribir<<" ingrese un texto de tama\244o menor 80 palabras: ";
	            gotoxy(21,9);leer.getline(vocal,80);
	            gotoxy(20,10);vocales(vocal);
                gotoxy(20,11);x=strlen(vocal);
	            gotoxy(20,12);escribir<<" el dato tiene: "<<x<<" caracteres";
		        gotoxy(20,13);escribir<<" el total de vocales en el texto es: "<<vocales(vocal)<<endl;
	            system("pause");
	            system("cls");
			    break;
			 }
	 case 4: {
				system("cls");
				cuadropantalla(24,70);
				system("color f3");
	            char variable[80];
	            int tamanho,i;
	            char x,x1;
	            leer.ignore(256,'\n');
	            gotoxy(12,9);escribir<<" ingrese cualquier texto menor a 80 caracteres: "<<endl;
	            gotoxy(13,10);leer.getline(variable,80);
	            tamanho=strlen(variable);
		        gotoxy(12,11);escribir<<" ingrese el caracter que desea cambiar: "<<endl;
	            gotoxy(52,11);leer>>x;
	            gotoxy(12,12);escribir<<" ingrese el nuevo caracter: "<<endl;
	            gotoxy(40,12);leer>>x1;
            	for(i=0;i<tamanho;i++){
                if(variable[i]==x){
    	           variable[i]=x1;
	             }
	             }
                gotoxy(13,13);escribir<<variable<<endl;
	            gotoxy(12,14);escribir<<" el tama\244o de la variable es de: "<<cambio_caracter(variable)<<" caracteres"<<endl;
            	system("pause");
            	system("cls");
				break;
			  }
	 case 5: {
				system("cls");
				cuadropantalla(24,70);
				system("color b9");
	            char frase[100];
	            int x,palabras;
	            leer.ignore(256,'\n');
	            gotoxy(12,10);escribir<<" ingrese la frase que desea: "<<endl<<endl;
            	gotoxy(12,11);leer.getline(frase,200);
	            x=strlen(frase);
	            gotoxy(12,14);escribir<<" la cantidad de palabras que tiene la frase es: "<<cantpalabras(frase)<<endl;
	            gotoxy(12,15);escribir<<" la cantidad de caracteres que tiene la frase es: "<<x<<endl;
	            system("pause");
	            system("cls");
				break;
			  }
	 case 6: {
				system("cls");
				cuadropantalla(24,70);
				notas estudiantes;
	            float notdef;
            	system("color b5");
            	int i;
            	leer.ignore(256,'\n');
                gotoxy(8,10);escribir<<" tenga un buen dia, por favor relacione los siguientes datos: ";
                gotoxy(12,11);escribir<<" ingrese sus nombres: "<<endl;
                gotoxy(12,12);leer.getline(estudiantes.names,30);
                gotoxy(12,13);escribir<<" ingrese sus apellidos: "<<endl;
                gotoxy(12,14);leer.getline(estudiantes.lastnames,30);
                gotoxy(12,15);escribir<<" ingrese su primer nota del corte1: "<<endl;
                gotoxy(12,16);leer>>estudiantes.nota1;
                gotoxy(12,17);escribir<<" ingrese  su segunda nota del corte2: "<<endl;
                gotoxy(12,18);leer>>estudiantes.nota2;
                gotoxy(12,19);escribir<<" ingrese su tercer nota del corte3: "<<endl;
                gotoxy(12,20);leer>>estudiantes.nota3;
                system("cls");
                cuadropantalla(24,70);
                system("color a2");
                notdef=((estudiantes.nota1+estudiantes.nota2+estudiantes.nota3)/3);
                gotoxy(6,12);escribir<<"estudiante: "<<estudiantes.names <<" "<< estudiantes.lastnames<< " su calificacion definitiva es: "<<notdef<<endl;
                system("pause");
                system("cls");
				break;
			  }
	 case 0: {
				system("cls");
				cuadropantalla(24,70);
				gotoxy(26,10);escribir<<" SALIR ";
				break;
			  }
	 default :{
				system("cls");
				cuadropantalla(24,70);
				gotoxy(30,10);escribir<<" opcion no valida";
				break;
			}
		}
	}
	system("pause");
	return 0;
}

