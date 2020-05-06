#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h> 
#include <time.h>
#include<conio.h >

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80 
 


// Funcion para situarse en algun punto del plano
void gotoxy(int x,int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition (hCon, dwPos);
}

//Funcion para ocultar el cursor
 void OcultarCursor(){
 	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = FALSE;
	
	
	SetConsoleCursorInfo(hCon,&cci);
 	
 }
//Funcion para dibujar los limites del juego
void pintar_limites(){
	int i;
	for(i=2;i<148;i++){
		gotoxy(i,1);printf("%c",205);
		gotoxy(i,35);printf("%c",205);
	}
	for(i=2;i<35;i++){
		gotoxy(1,i);printf("%c",186);
		gotoxy(148,i);printf("%c",186);
	}
	gotoxy(1,1);printf("%c",201);
	gotoxy(1,35);printf("%c",200);
	gotoxy(148,1);printf("%c",187);
	gotoxy(148,35);printf("%c",188);

}

//Conjunto de funciones para programar y manejar al jugador

class JUGADOR{  //Funcion clase, que sirve de inicio
	int x,y;
	
public:
	JUGADOR(int _x,int _y):x(_x),y(_y){}
	void pintar();
	void borrar();
	void mover(); 
	
};

void JUGADOR::pintar(){ //Funcion para dibujar al jugador
	gotoxy(x,y); printf("  %c",111);
	gotoxy(x,y+1); printf(" %c%c%c",45,124,45);
	gotoxy(x,y+2);printf(" %c %c",47,92);
}

void JUGADOR::borrar(){ //Funcion para borrar el ultimo lugar donde estaba el jugador y dar la sensacion de movimiento
	gotoxy(x,y); printf ("     ");
	gotoxy(x,y+1); printf ("     ");
	gotoxy(x,y+2); printf ("     ");
}


 void JUGADOR::mover(){ //Funcion para mover al jugador
 		if(kbhit()){
				char tecla = getch();
				borrar();
				if(tecla == IZQUIERDA && x>3 )x=x-2;
				if(tecla == DERECHA && x+6 < 149 )x=x+2;
				if(tecla == ABAJO && y+3< 35)y++;
				if(tecla == ARRIBA && y>2)y--;
				pintar();
			}
 }
//Funcion principal, donde se aplican las demas para ejecutar el programa
int main (void){
	
	
	OcultarCursor(); 
	pintar_limites();
	JUGADOR J(75,32);
	J.pintar();
	
	bool game_over = false;
	while (!game_over){
		
		
			J.mover();
			Sleep(30);
	}
	return 0;
}
