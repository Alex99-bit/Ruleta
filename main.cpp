//MIC ROXANA HERRERA
//PROGRAMACION 2
//librerias
# include <stdio.h>
# include <conio.h>
# include <string.h>
# include <stdlib.h>
# include <windows.h>
# include <time.h>
# include "listas.h"
int menu();
void setcolor(int value);
void gotoxy(int x,int y); 
 
main(){
	srand(time(0));
	int op, i;
	nodo *ruleta1=NULL,*ultr1=NULL;
	nodo *ruleta2=NULL,*ultr2=NULL;
	nodo *ruleta3=NULL,*ultr3=NULL;
	datos info;
	setcolor(1);
	for(i=0;i<10;i++)
	{
			info.color=1+rand()%2;
			info.car=1+rand()%3;			
			inserta_inicio(&ruleta1,&ultr1,info);
		
			info.color=1+rand()%2;
			info.car=1+rand()%3;
			inserta_inicio(&ruleta2,&ultr2,info); 
			
			info.color=1+rand()%2;
			info.car=1+rand()%3;
			inserta_inicio(&ruleta3,&ultr3,info);		
	}
	
	do{
		setcolor(1);
		op=menu();
		switch(op){
			case 1: 			
				recorrido(ruleta1,ruleta2,ruleta3);
				Sleep(200);
				fflush(stdin);
				getch();
				break;			
			case 2:	
			printf("Bye\n");
			break;
		}
		fflush(stdin);
		getch();
	}while(op!=2);//Fin do-while	
}

int menu()
{
 	int op=0;
	system("cls"); 
	printf("M.I.C. ROXANA HERRERA\n\n");
	 printf("\n\tRULETA");
	 printf("\n1. Gira Ruleta");
	 printf("\n2. Salir");
	 printf("\n\n\tSelecciona una opcion: ");	
	 scanf("%d",&op);
 	return op;	 
}

void setcolor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
