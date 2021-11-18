typedef struct
{
 int color;//informacion
 char car;
}datos;


typedef struct nodo
{
 datos info;//informacion
 nodo *sig;// liga al siguiente nodo
};

void gotoxy(int x,int y);
void setcolor(int value);

nodo* crea_nodo(datos info)
{
   nodo *aux;
   // se genera espacio de memoria para aux
   aux= (nodo *)malloc(sizeof(nodo));
   aux->info=info; // se iguala la informacion
   aux->sig=NULL;// el apuntador a sig se pone en NULL
   return aux; // se regresa el nodo creado
}

void recorrido(nodo *cab1, nodo *cab2, nodo *cab3){
	nodo *aux1,*aux2,*aux3;
	system("cls");
	for(aux1=cab1,aux2=cab2,aux3=cab3; !kbhit(); aux1=aux1->sig,aux2=aux2->sig,aux3=aux3->sig){
		gotoxy(5,5);
		setcolor(aux1->info.color);
		printf("%c\t", aux1->info.car);
		gotoxy(7,5);
		setcolor(aux1->info.color);
		printf("%c\t", aux2->info.car);
		gotoxy(9,5);
		setcolor(aux1->info.color);
		printf("%c\n", aux3->info.car);
		Sleep(100);
	}
	if(aux1->info.car == aux2->info.car && aux2->info.car == aux3->info.car && aux1->info.color == aux2->info.color && aux2->info.color == aux3->info.color){
		system("cls");
		printf("HAS GANADO 100 PUNTOS\n");
	}else{
		if(aux1->info.car == aux2->info.car || aux2->info.car == aux3->info.car){
			printf("HAS GANADO 50 PUNTOS\n");
		}else{
			if(aux1->info.color == aux2->info.color || aux2->info.color == aux3->info.color){
				printf("HAS GANADO 25 PUNTOS");
			}else{
				printf("HAS PERDIDO :c\n");
			}
		}
	}
/*or(aux1=cab1;!kbhit();aux1=aux1->sig){
		printf("%c\t", aux1->info.car);
		//intf("%c\t", aux2->info.car);
//intf("%c\n", aux3->info.car);
		Sleep(100);
	}*/
}

void inserta_inicio(nodo **cab,nodo **ultimo,datos info)
{
	nodo *actual, *nuevo, *anterior;
	nuevo=crea_nodo(info);
	if(*cab==NULL)
	{
			nuevo->sig=nuevo;
	 		*cab=nuevo;
	 		*ultimo=nuevo;
	}
	else
	{
		nuevo->sig=*cab;
		*cab=nuevo;
		(*ultimo)->sig=nuevo;
		
	}
}

