#include <iostream>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//*************************************************************************************
//Una compañía dedicada al alquiler de automóviles cobra un monto fijo de $3000 para los
//primeros 300 Km. de recorrido. Para más de 300 Km. y hasta 1000 Km., cobra un monto adicional
//de $ 100 por cada kilómetro en exceso sobre 300. Para más de 1000 Km. cobra un monto
//adicional de $ 50 por cada kilómetro en exceso sobre 1000. Los precios ya incluyen el 19% del
//impuesto general a las ventas, IVA. Diseñar un programa que determine el monto a pagar por el
//alquiler de un vehículo y el monto del impuesto IVA
//******************************************************************************************

using namespace std;

int main(int argc, char** argv) {
	
	int km, montofijo, costadic1, costadic2, iva;
	float montoadic;
	cout<<" ingrese su kilometraje recorrido "<<endl;
	cin>>km;
	montofijo=3000;
	
	iva=(montofijo*0.19);
	if (km<=300){
		cout<<"su monto por el kilometraje recorrido es: "<<montofijo<<endl;
		cout<<" su iva es: "<<iva<<endl;
	}else{
		if (km<1000){
			costadic1=(km-300)*100;
			montoadic=montofijo+costadic1;
			iva=montoadic*0.19;
		}else{
			costadic2=(km- 1000) * 50;
			montoadic=montofijo+costadic2;
			iva=montoadic*0.19;
		}
	 cout<<" el total a pagar por el alquiler del vehiculo es: "<<montoadic<<endl;
	 cout<<" su iva es: "<<iva<<endl;
	}
	system("pause");
	return 0;
}
