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
		gotoxy(i,0);printf("%c",205);
		gotoxy(i,35);printf("%c",205);
		gotoxy(i,16);printf("%c",207);
    	gotoxy(i,18);printf("%c",207);
    	gotoxy(i,26);printf("%c",196);
    	gotoxy(i,8);printf("%c",196);
    	gotoxy(i,4);printf("%c",'-');
    	gotoxy(i,12);printf("%c",'-');
    	gotoxy(i,22);printf("%c",'-');
    	gotoxy(i,30);printf("%c",'-');
    	
	}
	for(i=1;i<35;i++){
		gotoxy(1,i);printf("%c",186);
		gotoxy(148,i);printf("%c",186);
	}
	gotoxy(1,0);printf("%c",201);
	gotoxy(1,35);printf("%c",200);
	gotoxy(148,0);printf("%c",187);
	gotoxy(148,35);printf("%c",188);
	gotoxy(74,17);printf("SAFE ZONE");
   
	
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
	gotoxy(x,y); printf("  %c%c%c",62,229,60);


}

void JUGADOR::borrar(){ //Funcion para borrar el ultimo lugar donde estaba el jugador y dar la sensacion de movimiento
	gotoxy(x,y); printf ("     ");
	
	
}


 void JUGADOR::mover(){ //Funcion para mover al jugador
 int i;
 		if(kbhit()){
				char tecla = getch();
				borrar();
				if(tecla == IZQUIERDA && x>3 )x=x-2;
				if(tecla == DERECHA && x+4 < 147 )x=x+2;
				if(tecla == ABAJO && y< 34)y++;
				if(tecla == ARRIBA && y>1)y--;
			    if(tecla==ARRIBA && y==16 )y--;
				if(tecla==ARRIBA && y==18 )y--;
				if(tecla==ABAJO&& y==16 )y++;
				if(tecla==ABAJO && y==18 )y++;
				if(tecla==ARRIBA && y==4 )y--;
				if(tecla==ABAJO && y==4 )y++;
				if(tecla==ARRIBA && y==8 )y--;
				if(tecla==ABAJO && y==8 )y++;
				if(tecla==ARRIBA && y==12 )y--;
				if(tecla==ABAJO && y==12 )y++;
				if(tecla==ARRIBA && y==22 )y--;
				if(tecla==ABAJO && y==22 )y++;
				if(tecla==ARRIBA && y==26 )y--;
				if(tecla==ABAJO && y==26 )y++;
				if(tecla==ARRIBA && y==30 )y--;
				if(tecla==ABAJO && y==30 )y++;
				pintar();
				
			}
		
    
			
 }
 
 
 class COCHE{
 	int x,y;
public:
	COCHE(int_x,int_y):x(_x),y(_y){}
	void pintar():
	void mover();
 };
 
 void COCHE::pintar(){
 	gotoxy(x,y):printf("%c,184");
 }
 
 void COCHE::mover(){
 	gotoxy(x,y):printf("%c",184);
 	x++;
 	if(x > 147){
 		y=rand()%71 +4//Nos da un numero entre 0 y 71+4
	 }
	 pintar():
 }
 
 class COCHE{
 	int x,y;
public:
	COCHE(int _x,int _y):x(_x),y(_y){}
	void pintar();
	void mover();
 };
 
 void COCHE::pintar(){
 	gotoxy(x,y); 
	printf("-");
 }
 
 void COCHE::mover(){
 	gotoxy(x,y);
	printf("%c",184);
 	x++;
 	if(x > 147){
 		y=rand()%71 +4;//Nos da un numero entre
	 }
	 pintar();
 }
//Funcion principal, donde se aplican las demas para ejecutar el programa
int main (void){
	
	system("COLOR 02");
	OcultarCursor(); 
	pintar_limites();
	JUGADOR J(75,34);
	J.pintar();
	
	COCHE coche(10,4);
	
	bool game_over = false;
	while (!game_over){
		
		    coche.mover();
			J.mover();
			Sleep(30);
	}
	return 0;
}