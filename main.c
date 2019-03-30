#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//aqui se almacena los datos
typedef struct Dato{
	char palabra[4];
}dato;
//aqui se almacena la direccion de el dato y un puntero al siguiente dato
/*typedef struct Registro{
	
	dato *palabra;
	struct Registro *sigiente;
	
}registro;*/



FILE *pf=NULL;

int main(int argc, char *argv[]) {
	int i=0;
	char PalabrasAleatorias[4][4]={"hola","amor","pato"};//palbras que sera las que iran en el archivo
	dato informacion;
	
	
	//este for guarda la informacion
	for(i=0;i<3;i++){
		
		strcpy(informacion.palabra,PalabrasAleatorias[i]);
		
		if(i==0){
			pf=fopen("tets.txt","w");//apertura del archivo
			if(pf == NULL){
				return -1;
			}
		}
		else{
			pf=fopen("tets.txt","a");//apertura del archivo
			if(pf == NULL){
				return -1;
			}
		}
		
		
		
		fwrite(&informacion,sizeof(dato),1,pf);
		fprintf(pf,"\n");
		
		fclose(pf);//cerramos archivo
	}
	char a='a';
	long posicion = 0;
	pf=fopen("tets.txt","r");//apertura del archivo
	if(pf == NULL){
		return -1;
	}
	
	//aqui leo hasta llegar al final
	while(!(feof(pf))){
		if(ftell(pf) == 0){ // compruebo que estoy en la primera linea
			fread(&informacion,sizeof(informacion),1,pf);//si es asi leo la struct
		}
		else{//si no es que estoy en la segunda linea y despues de eso hay un"\n"
			a=fgetc(pf);//leo el \n
			putchar(a);//imprimo "\n"
			fread(&informacion,sizeof(informacion),1,pf);	//leo la struct
		}
		printf("%s",&informacion.palabra);//imprimo los datos de la struct
		if((strcmp(informacion.palabra,"pato")) == 0)//comparo si estoy en la ultima palabra para terminar el ciclo antes
			break;
		
			
	}
	fclose(pf);//cierro el pf
	
	
	
	return 0;
}
