#include <iostream>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//*********************************************************************************
//Diseñar un programa para el siguiente enunciado: calcular el promedio de edad de las mujeres
//que ingresaran a un estadio de fútbol, cuantas son mayores a 50 años y cuantas menores de 40
//años.
//*********************************************************************************

using namespace std;
int main(int argc, char** argv) {
	
	int m,edad,promedio, cantmujeres, mcuaren, mcincuen,sexo;
	float promedio1;
	mcincuen=0;
	mcuaren=0;
	promedio=0;
	sexo==1;

    while (sexo!=0){
    	cout<<" ingrese 1.si es mujer 2.si es hombre o 0.si desea salir "<<endl;
	    cin>>sexo;
	    if(sexo==1){
	    	cout<<"ingrese su edad"<<endl;
		    cin>>edad;
		    if(edad>=50){
			 mcincuen= mcincuen+1;
					}else{	
					if(edad<=40){
						mcuaren=mcuaren+1;
					}
		           }
					promedio=promedio+edad;
			        promedio1=promedio/(mcuaren+mcincuen);
					}else{
					cout<<" ingrese 1.si es mujer 2.si es hombre o 0.si desea salir "<<endl;	
					}
	}
	cout <<" el promedio de edad de las mujeres que ingresan a un estadio es: "<<promedio1<<endl;
    cout<<" la cantidad de mujeres mayores de 50 a\244os son: "<<mcincuen<<endl;	
	cout<<" la cantidad de mujeres menores de 40 a\244os son: "<<mcuaren<<endl;
	    
	system("pause");
	return 0;
}
