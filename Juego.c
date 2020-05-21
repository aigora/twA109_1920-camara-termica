//IMPORTANTE!! AL EJECUTAR POR PRIMERA VEZ, PINCHAR EN PROPIEDADES EN LA VENTANA DE EJECUCION, Y EN LA PESTAÑA DE DISEÑO SE ESCRIBE DE ANCHO: 170; Y DE ALTO:36
#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h> 
#include <time.h>
#include<conio.h >
#include <iostream>
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
	for(i=150;i<165;i++){
		gotoxy(i,0);printf("%c",205);
		gotoxy(i,35);printf("%c",205);
		
	}
	for(i=1;i<35;i++){
		gotoxy(1,i);printf("%c",186);
		gotoxy(148,i);printf("%c",186);
		gotoxy(149,i);printf("%c",186);
		gotoxy(165,i);printf("%c",186);
	}
	gotoxy(1,0);printf("%c",201);
	gotoxy(1,35);printf("%c",200);
	gotoxy(148,0);printf("%c",187);
	gotoxy(148,35);printf("%c",188);
	gotoxy(149,0);printf("%c",201);
	gotoxy(149,35);printf("%c",200);
	gotoxy(165,0);printf("%c",187);
	gotoxy(165,35);printf("%c",188);
	gotoxy(74,17);printf("SAFE ZONE");
	gotoxy(150,1);printf("CROSS THE ROAD!");
	gotoxy(150,3);printf("Vidas:");
	gotoxy(150,5);printf("Puntos:");
	gotoxy(150,7);printf("Tiempo:");
	gotoxy(150,9);printf("Monedas:");
	   
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
 //Funcion clase que controla el coche 1
 class COCHES1{
	int x,x1=47,x2=94,y;		
public:
	COCHES1(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover(); 
	
};
void COCHES1::pintar(){ //Funcion para dibujar el coche
	gotoxy(x,y); printf("   %c%c%c",254,254,254);
	gotoxy(x1,y); printf("   %c%c%c",254,254,254);
	gotoxy(x2,y); printf("   %c%c%c",254,254,254);	
}
void COCHES1::borrar(){ //Funcion para borrar el ultimo lugar donde estaba el coche y dar la sensacion de movimiento
	gotoxy(x,y); printf ("     ");	
	gotoxy(x1,y); printf ("     ");	
	gotoxy(x2,y); printf ("     ");			
}

void COCHES1::mover(){
	x++;
	if(x>142){
		borrar();
		y=2;
		x=2;
	}	
	x1++;
	if(x1>142){
		borrar();
		y=2;
		x1=2;
	}	
	x2++;
	if(x2>142){
		borrar();
		y=2;
		x2=2;
	}	
	pintar();	
}
//Funcion clase que controla el coche 2
 class COCHES2{
	int x=25,x1=70,x2=120,y;
		
public:
	COCHES2(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover(); 
	
};
void COCHES2::pintar(){ 
	gotoxy(x,y); printf("   %c%c%c",254,254,254);
	gotoxy(x1,y); printf("   %c%c%c",254,254,254);
	gotoxy(x2,y); printf("   %c%c%c",254,254,254);	
}

void COCHES2::borrar(){ 
	gotoxy(x,y); printf ("     ");	
	gotoxy(x1,y); printf ("     ");	
	gotoxy(x2,y); printf ("     ");			
}

void COCHES2::mover(){
	x++;
	if(x>142){
		borrar();
		y=3;
		x=2;
	}	

	x1++;
	if(x1>142){
		borrar();
		y=3;
		x1=2;
	}	
	x2++;
	if(x2>142){
		borrar();
		y=3;
		x2=2;
	}	

	pintar();	
}
//Funcion clase que controla el coche 3
class COCHES3{
	int x=50,x1=80,x2=120,y;
		
public:
	COCHES3(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover(); 
	
};
void COCHES3::pintar(){ 
	gotoxy(x,y); printf("   %c%c%c%c",111,45,111,217);
	gotoxy(x1,y); printf("   %c%c%c%c",111,45,111,217);
	gotoxy(x2,y); printf("   %c%c%c%c",111,45,111,217);
}

void COCHES3::borrar(){ 
	gotoxy(x,y); printf ("      ");	
	gotoxy(x1,y); printf ("      ");	
	gotoxy(x2,y); printf ("      ");			
}

void COCHES3::mover(){
	x++;
	if(x>141){
		borrar();
		y=7;
		x=2;
	}	

	x1++;
	if(x1>141){
		borrar();
		y=7;
		x1=2;
	}	
	x2++;
	if(x2>141){
		borrar();
		y=7;
		x2=2;
	}	

	pintar();	
}
//Funcion clase que controla el coche 4
class COCHES4{
	int x=95, x1=48,y;
	
public: 
	COCHES4(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover();
};
void COCHES4::pintar(){
	gotoxy(x,y); printf("%c%c%c    ",254,254,254);
	gotoxy(x1,y); printf("%c%c%c    ",254,254,254);
}
void COCHES4::borrar(){
	gotoxy(x,y); printf ("     ");	
	gotoxy(x1,y); printf ("     ");	
}

void COCHES4::mover(){
		x=x-2;
	if(x<4){
		borrar();
		y=5;
		x=141;
	}	

	x1=x1-2;
	if(x1<4){
		borrar();
		y=5;
		x1=141;	
		
}
	pintar();
}
//Funcion clase que controla el coche 5
class COCHES5{
	int x=95,x1=48,x2=25,y;
	
public: 
	COCHES5(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover();
};
void COCHES5::pintar(){
	gotoxy(x,y); printf("   %c%c%c%c",254,254,45,254);
	gotoxy(x1,y); printf("   %c%c%c%c",254,254,45,254);
	gotoxy(x2,y); printf("   %c%c%c%c",254,254,45,254);
}
void COCHES5::borrar(){
	gotoxy(x,y); printf ("      ");	
	gotoxy(x1,y); printf ("      ");	
	gotoxy(x2,y); printf ("      ");	
}

void COCHES5::mover(){
	x++;
	if(x>141){
		borrar();
		y=11;
		x=3;
	}	

	x1++;
	if(x1>141){
		borrar();
		y=11;
		x1=3;
	}	
	x2++;
	if(x2>141){
		borrar();
		y=11;
		x2=3;
	}	

	pintar();	
}
//Funcion clase que controla el coche 6
class COCHES6{
	int x=18,x1=66,x2=113,y;
	
public: 
	COCHES6(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover();
};
void COCHES6::pintar(){
	gotoxy(x,y); printf("%c %c  ",48,48);
	gotoxy(x,y-0.5); printf("%c%c%c  ",191,95,95);	
	gotoxy(x1,y); printf("%c %c  ",48,48);
	gotoxy(x1,y-0.5); printf("%c%c%c  ",191,95,95);	
	gotoxy(x2,y); printf("%c %c  ",48,48);
	gotoxy(x2,y-0.5);printf("%c%c%c  ",191,95,95);
}
void COCHES6::borrar(){
	gotoxy(x,y); printf("        ");
	gotoxy(x,y-0.5); printf("        ");	
	gotoxy(x1,y); printf("        ");
	gotoxy(x1,y-0.5); printf("        ");
	gotoxy(x2,y); printf("        ");
	gotoxy(x2,y-0.5); printf("        ");	
}

void COCHES6::mover(){
		x=x-2;
	if(x<4){
		borrar();
		y=14;
		x=141;
	}	

	x1=x1-2;
	if(x1<4){
		borrar();
		y=14;
		x1=141;	
		
}
	x2=x2-2;
	if(x2<4){
		borrar();
		y=14;
		x2=141;	
		
}
	pintar();
}
//Funcion clase que controla el coche 7
class COCHES7{
	int x=33,x1=78,x2=126,y;
		
public:
	COCHES7(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover(); 
	
};
void COCHES7::pintar(){ 
	gotoxy(x,y); printf("   %c%c%c%c",111,45,111,217);
	gotoxy(x1,y); printf("   %c%c%c%c",111,45,111,217);
	gotoxy(x2,y); printf("   %c%c%c%c",111,45,111,217);
}

void COCHES7::borrar(){ 
	gotoxy(x,y); printf ("      ");	
	gotoxy(x1,y); printf ("      ");	
	gotoxy(x2,y); printf ("      ");			
}

void COCHES7::mover(){
	x=x+2;
	if(x>140){
		borrar();
		y=19;
		x=2;
	}	

	x1=x1+2;
	if(x1>140){
		borrar();
		y=19;
		x1=2;
	}	
	x2=x2+2;
	if(x2>140){
		borrar();
		y=19;
		x2=2;
	}	

	pintar();	
}
//Funcion clase que controla el coche gato
class GATO1{
	int x=10,x1=36,x2=64,x3=101,y;
		
public:
	GATO(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover(); 
	
};
void GATO1::pintar(){ 
	gotoxy(x,y); printf("%c%c%c%c ",47,92,47,92);
	gotoxy(x,y-0.5); printf("%c%c%c ",48,95,95);	
	gotoxy(x1,y); printf("%c%c%c%c ",47,92,47,92);
	gotoxy(x1,y-0.5); printf("%c%c%c ",48,95,95);	
	gotoxy(x2,y); printf("%c%c%c%c ",47,92,47,92);
	gotoxy(x2,y-0.5);printf("%c%c%c ",48,95,95);	
	gotoxy(x3,y); printf("%c%c%c%c ",47,92,47,92);
	gotoxy(x3,y-0.5);printf("%c%c%c ",48,95,95);		
}

void GATO1::borrar(){
	gotoxy(x,y); printf("        ");
	gotoxy(x,y-0.5); printf("        ");	
	gotoxy(x1,y); printf("        ");
	gotoxy(x1,y-0.5); printf("        ");
	gotoxy(x2,y); printf("        ");
	gotoxy(x2,y-0.5); printf("        ");	
	gotoxy(x3,y); printf("        ");
	gotoxy(x3,y-0.5); printf("        ");		
}

void GATO1::mover(){
	x--;
	if(x<3){
		borrar();
		y=10;
		x=143;
	}	

	x1--;
	if(x1<3){
		borrar();
		y=10;
		x1=143;
	}	
	x2--;
	if(x2<3){
		borrar();
		y=10;
		x2=143;
	}	
	x3--;
	if(x3<3){
		borrar();
		y=10;
		x3=143;
	}
	
	pintar();	
}

//Funcion clase que controla el coche 8
class COCHES8{
	int x=90,x1=40,x2=15,y;
	
public: 
	COCHES8(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover();
};
void COCHES8::pintar(){
	gotoxy(x,y); printf("   %c%c%c%c",254,254,45,254);
	gotoxy(x1,y); printf("   %c%c%c%c",254,254,45,254);
	gotoxy(x2,y); printf("   %c%c%c%c",254,254,45,254);
}
void COCHES8::borrar(){
	gotoxy(x,y); printf ("      ");	
	gotoxy(x1,y); printf ("      ");	
	gotoxy(x2,y); printf ("      ");	
}

void COCHES8::mover(){
	x++;
	if(x>141){
		borrar();
		y=25;
		x=3;
	}	

	x1++;
	if(x1>141){
		borrar();
		y=25;
		x1=3;
	}	
	x2++;
	if(x2>141){
		borrar();
		y=25;
		x2=3;
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
	COCHES1 C1(2,2);
	COCHES2 C2(25,3);
	COCHES3 C3(50,7);
	COCHES4 C4(98,5);
	COCHES5 C5(95,11);
	COCHES6 C6(18,14);
	COCHES7 C7(33,19);
	COCHES8 C8(90,25);
    GATO G1(13,10);
    GATO2 G2(8,24);
	
	bool game_over = false;
	while (!game_over){
		
		
			J.mover();
			C1.mover();
			C2.mover();
			C3.mover();	
			C4.mover();
		    C5.mover();
		    C6.mover();
		    C7.mover();
		    C8.mover();
			G1.mover();	
			G2.mover();				
			Sleep(30);
	}
	return 0;
}
