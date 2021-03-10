#include <iostream>
#include<windows.h>
#include<conio.h>
#include<string.h>
#define escribir cout
#define leer cin
using namespace std;
/* realizar un menu con diversas opciones para mostrar un registro de la notas de varios estudiantes,
visualizandolas,borrandolas,modificandolas y eliminarlas, mostrando el menu en el recuadro */
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
struct notas{
	char cedula[12];
	char names[30];
	char lastnames[30];
	char google[12];
	char activo;
	float nota1,nota2,nota3,promedioallnd;
};
int main(int argc, char** argv) {
	int opcion=1;
	float promedioallnd;
	notas estudiantes;
    FILE *archivo;
	while(opcion!=0)
	{
	system("cls");
	cuadropantalla(22,78);
	system("color a0");
	gotoxy(10,5);escribir<<" MENU ";
	gotoxy(7,7);escribir<<" 1. ingresar notas  ";
	gotoxy(7,8);escribir<<" 2. visualizar notas ";
	gotoxy(7,9);escribir<<" 3. consulta por cedula ";
	gotoxy(7,10);escribir<<" 4. modificar notas  ";
	gotoxy(7,11);escribir<<" 5. eliminar el registro del student ";
	gotoxy(7,12);escribir<<" 6. mantenimiento ";
	gotoxy(7,13);escribir<<" 0. salir ";
	gotoxy(7,15);escribir<<" seleccione una opcion: ";leer>>opcion;
	switch(opcion)
	{
	 case 1: {
				system("cls");
				system("color c1");
				cuadropantalla(22,78);
                notas estudiantes;
                FILE *archivo;
	            leer.ignore(256,'\n');
                gotoxy(8,5);escribir<<" tenga un buen dia; registre los estudiantes"<<endl;
                gotoxy(12,7);escribir<<" ingrese el numero de identificacion del estudiante: "<<endl;
	            gotoxy(13,8);leer.getline(estudiantes.cedula,12);
                gotoxy(12,9);escribir<<" ingrese sus nombres: "<<endl;
                gotoxy(13,10);leer.getline(estudiantes.names,30);
                gotoxy(12,11);escribir<<" ingrese sus apellidos: "<<endl;
                gotoxy(13,12);leer.getline(estudiantes.lastnames, 30);
                gotoxy(12,13);escribir<<" ingrese su primer nota del corte1: "<<endl;
                gotoxy(13,14);leer>>estudiantes.nota1;
                gotoxy(12,15);escribir<<" ingrese  su segunda nota del corte2: "<<endl;
                gotoxy(13,16);leer>>estudiantes.nota2;
                gotoxy(12,17);escribir<<" ingrese su tercer nota del corte3: "<<endl;
                gotoxy(13,18);leer>>estudiantes.nota3;
                gotoxy(13,19);estudiantes.activo='s';
	            archivo=fopen("notas_estudiantes.txt", "ab");
                if(archivo==NULL){
	            archivo=fopen("notas_estudiantes.txt","wb");}
                fwrite(&estudiantes,sizeof(estudiantes),1,archivo);
                rewind(archivo);
                fclose(archivo);
				break;
			 }
	 case 2:{
	 	    system("cls");
	 	    system("color 3e");
			cuadropantalla(22,78);
	        archivo=fopen("notas_estudiantes.txt", "rb");
            rewind(archivo);
            int No_reg=1;
            int reg=9;
            while(fread(&estudiantes,sizeof(estudiantes),1,archivo)){
            	if (estudiantes.activo=='s'){
                 system("color 1f");
                 
                 promedioallnd=((estudiantes.nota1+estudiantes.nota2+estudiantes.nota3)/3);
                 gotoxy(7,8);escribir<<"REG: ";
                 gotoxy(7,reg);escribir<<No_reg<<endl;
                 gotoxy(12,8);escribir<<"ESTUDIANTE: ";
				 gotoxy(12,reg);escribir<<estudiantes.names<<" "<<estudiantes.lastnames<<endl;
			     gotoxy(45,8);escribir<<"IDENT: ";
				 gotoxy(45,reg);escribir<<estudiantes.cedula<<endl;
		         gotoxy(60,8);escribir<<"PROM: ";
				 gotoxy(60,reg);escribir<<promedioallnd<<endl;
			  /* gotoxy(70,8);escribir<<"ACTIVO: ";
				 gotoxy(70,reg);escribir<<estudiantes.activo<<endl;*/
                 No_reg++;
                 reg++;
	        }       
		    }
		    	
		    system("pause");
	        fclose(archivo);
		        break;
	        }
	 case 3:{
	 	    system("cls");
	 	    system("color f1");
			cuadropantalla(22,78);
			char google[5];
	        gotoxy(7,8);escribir<<" ingrese la cedula del estudiante a buscar: "<<endl;
	        gotoxy(7,9);leer>>google;
	        archivo=fopen("notas_estudiantes.txt", "rb");
            rewind(archivo);
            int cod=0;
            int No_reg=1;
            int reg=12;
            while(fread(&estudiantes,sizeof(estudiantes),1,archivo)){
               if (strcmp(google,estudiantes.cedula)==0 && estudiantes.activo=='s'){
                 system("color 1f");
                 promedioallnd=((estudiantes.nota1+estudiantes.nota2+estudiantes.nota3)/3);
                 gotoxy(7,11);escribir<<"REG: ";
                 gotoxy(7,reg);escribir<<No_reg<<endl;
                 gotoxy(reg,11);escribir<<"ESTUDIANTE: ";
				 gotoxy(12,reg);escribir<<estudiantes.names<<" "<<estudiantes.lastnames<<endl;
			     gotoxy(45,11);escribir<<"IDENT: ";
				 gotoxy(45,reg);escribir<<estudiantes.cedula<<endl;
		         gotoxy(60,11);escribir<<"PROM: ";
				 gotoxy(60,reg);escribir<<promedioallnd<<endl;
	             cod=1;
	             No_reg++;
                 reg++;
	            }
		    }
		    if (cod==0){
		       gotoxy(12,12);escribir<<" no existe "<<endl;
		   }
	        fclose(archivo);
	        system("pause");
		        break;
	        }
	 case 4: {
	 	    system("cls");
	 	    system("color b8");
			cuadropantalla(22,78);
			char google[5],newnames[30],newlastnames[30];
			float newnota1,newnota2,newnota3;
	        gotoxy(7,2);escribir<<" ingrese la cedula del estudiante a buscar: "<<endl;
	        gotoxy(8,3);leer>>google;
	        archivo=fopen("notas_estudiantes.txt", "rb+");
            rewind(archivo);
            int No_reg=1;
            int reg=6;
            int change=1;
            int cod=0;
            while(fread(&estudiantes,sizeof(estudiantes),1,archivo)){
               if (strcmp(google,estudiantes.cedula)==0 && estudiantes.activo=='s'){
                 system("color 4f");
                 promedioallnd=((estudiantes.nota1+estudiantes.nota2+estudiantes.nota3)/3);
                 gotoxy(7,5);escribir<<"REG: ";
                 gotoxy(7,reg);escribir<<No_reg<<endl;
                 gotoxy(12,5);escribir<<"ESTUDIANTE: ";
				 gotoxy(12,reg);escribir<<estudiantes.names<<" "<<estudiantes.lastnames<<endl;
			     gotoxy(45,5);escribir<<"IDENT: ";
				 gotoxy(45,reg);escribir<<estudiantes.cedula<<endl;
		         gotoxy(60,5);escribir<<"PROM: ";
				 gotoxy(60,reg);escribir<<promedioallnd<<endl;
			     gotoxy(70,5);escribir<<"ACTIVO: ";
				 gotoxy(70,reg);escribir<<estudiantes.activo<<endl;
                 No_reg++;
                 reg++;
	             cod=1;
	             break;
	            }
		    }
		    if (cod==0){
		       gotoxy(12,12);escribir<<" no existe "<<endl;
		   }else {
		   		gotoxy(6,11);escribir<<" digite 1.para cambiar el nombre del estudiante"<<endl;
		   		gotoxy(13,12);escribir<<" 2.para sus apellidos"<<endl;
		   		gotoxy(13,13);escribir<<" 3.para su primer nota"<<endl;
		   		gotoxy(13,14);escribir<<" 4.para su segunda nota"<<endl;
		   		gotoxy(13,15);escribir<<" 5.para su tercer nota del semestre"<<endl;
		   		gotoxy(13,16);escribir<<" 0. para salir"<<endl;
		        gotoxy(13,18);leer>>change;
		        switch (change){
		        	case 1:{
		        		system("cls");
				        system("color c1");
				        cuadropantalla(22,78);
				        cin.ignore(256,'\n');
		        		gotoxy(8,13);escribir<<" digite su nuevo nombre: "<<endl;
		        		gotoxy(9,14);leer.getline(newnames,30);
		        		fseek(archivo,ftell(archivo)-sizeof(estudiantes),SEEK_SET);
	                    fread(&estudiantes,sizeof(estudiantes),1,archivo);
                        strcpy(estudiantes.names,newnames);
	                    fseek(archivo,ftell(archivo)-sizeof(estudiantes),SEEK_SET);
                        fwrite(&estudiantes,sizeof(estudiantes),1,archivo);			
	                    fclose(archivo);
						break;
					}
					case 2:{
		        		system("cls");
				        system("color c1");
				        cuadropantalla(22,78);
				        cin.ignore(256,'\n');
		        		gotoxy(8,13);escribir<<" digite sus nuevos apellidos: "<<endl;
		        		gotoxy(9,14);leer.getline(newlastnames,30);
		        		fseek(archivo,ftell(archivo)-sizeof(estudiantes),SEEK_SET);
	                    fread(&estudiantes,sizeof(estudiantes),1,archivo);
                        strcpy(estudiantes.lastnames,newlastnames);
	                    fseek(archivo,ftell(archivo)-sizeof(estudiantes),SEEK_SET);
                        fwrite(&estudiantes,sizeof(estudiantes),1,archivo);			
	                    fclose(archivo);
						break;
					}
					case 3:{
		        		system("cls");
				        system("color c1");
				        cuadropantalla(22,78);
		        		gotoxy(8,13);escribir<<" digite su nueva nota1: "<<endl;
		        		gotoxy(9,14);leer>>newnota1;
		        		fseek(archivo,ftell(archivo)-sizeof(estudiantes),SEEK_SET);
	                    fread(&estudiantes,sizeof(estudiantes),1,archivo);
                        estudiantes.nota1=newnota1;
                        promedioallnd=((estudiantes.nota1+estudiantes.nota2+estudiantes.nota3)/3);
	                    fseek(archivo,ftell(archivo)-sizeof(estudiantes),SEEK_SET);
                        fwrite(&estudiantes,sizeof(estudiantes),1,archivo);			
	                    fclose(archivo);
						break;
					}
					case 4:{
		        		system("cls");
				        system("color c1");
				        cuadropantalla(22,78);
		        		gotoxy(8,13);escribir<<" digite su nueva nota2: "<<endl;
		        		gotoxy(9,14);leer>>newnota2;
		        		fseek(archivo,ftell(archivo)-sizeof(estudiantes),SEEK_SET);
	                    fread(&estudiantes,sizeof(estudiantes),1,archivo);
                        estudiantes.nota2=newnota2;
                        promedioallnd=((estudiantes.nota1+estudiantes.nota2+estudiantes.nota3)/3);
	                    fseek(archivo,ftell(archivo)-sizeof(estudiantes),SEEK_SET);
                        fwrite(&estudiantes,sizeof(estudiantes),1,archivo);			
	                    fclose(archivo);
						break;
					}
					case 5:{
		        		system("cls");
				        system("color c1");
				        cuadropantalla(22,78);
		        		gotoxy(8,13);escribir<<" digite su nueva nota3: "<<endl;
		        		gotoxy(9,14);leer>>newnota3;
		        		fseek(archivo,ftell(archivo)-sizeof(estudiantes),SEEK_SET);
	                    fread(&estudiantes,sizeof(estudiantes),1,archivo);
                        estudiantes.nota3=newnota3;
                        promedioallnd=((estudiantes.nota1+estudiantes.nota2+estudiantes.nota3)/3);
	                    fseek(archivo,ftell(archivo)-sizeof(estudiantes),SEEK_SET);
                        fwrite(&estudiantes,sizeof(estudiantes),1,archivo);			
	                    fclose(archivo);
						break;
					}
					case 0:{
		        		system("cls");
				        system("color c1");
				        cuadropantalla(22,78);
		        		gotoxy(8,13);escribir<<" no hubo modificaciones."<<endl;		
	                    fclose(archivo);
						break;
					}
					default :{
						system("cls");
				        system("color c1");
				        cuadropantalla(22,78);
		        		gotoxy(8,13);escribir<<" opcion no valida "<<endl;
						break;
					}
				}
			   }		
	        fclose(archivo);
	        system("pause");
				break;
		    }
	 case 5: {
	 	    system("cls");
	 	    system("color 0d");
			cuadropantalla(22,78);
			char desactivar;
			char google[5];
	        gotoxy(7,2);escribir<<" ingrese la cedula del estudiante estudiante a buscar: "<<endl;
	        gotoxy(8,3);leer>>google;
	        archivo=fopen("notas_estudiantes.txt", "rb+");
            rewind(archivo);
            int cod=0;
            while(fread(&estudiantes,sizeof(estudiantes),1,archivo)){
               if (strcmp(google,estudiantes.cedula)==0 && estudiantes.activo=='s'){
                 system("color 4f");
                 gotoxy(8,5);escribir<<"estudiante: "<<estudiantes.names <<endl;
			     gotoxy(30,6);escribir<<estudiantes.lastnames<<endl;
		         gotoxy(8,9);escribir<<" activo: "<<estudiantes.activo<<endl<<endl;
	             cod=1;
	             break;
	            }
		    }
		    if (cod==0){
		       gotoxy(12,12);escribir<<" no existe "<<endl;
		   }else {
				gotoxy(8,13);escribir<<"si desea desactivarlo escriba n, de lo contrario escriba s: "<<endl;
                gotoxy(9,14);leer>>desactivar;
            }
				fseek(archivo,ftell(archivo)-sizeof(estudiantes),SEEK_SET);
	            fread(&estudiantes,sizeof(estudiantes),1,archivo);
                estudiantes.activo=desactivar;
	            fseek(archivo,ftell(archivo)-sizeof(estudiantes),SEEK_SET);
                fwrite(&estudiantes,sizeof(estudiantes),1,archivo);			
	        
	        fclose(archivo);
	        system("pause");
				break;
		     }
	 case 6: {
	 	    system("cls");
	 	    system("color 0c");
			cuadropantalla(22,78);
			char eliminar;
			char google[5];
	        archivo=fopen("notas_estudiantes.txt", "rb+");
            rewind(archivo);
            int cod=0;
            while(fread(&estudiantes,sizeof(estudiantes),1,archivo)){
               if (estudiantes.activo=='n'){
                 system("color 4f");

	             cod=1;
	             break;
	            }
		    }
		    if (cod==0){
		       gotoxy(12,12);escribir<<" se actualizaron sus datos "<<endl;
		   }else {
		   	
	       }
	        fclose(archivo);
	        system("pause");
				break;
			 }  
	 case 0: {
	 	        system("cls");
				system("color ec");
				cuadropantalla(24,70);
				gotoxy(16,10);escribir<<" GOOD BYE... "<<endl<<endl;
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
