#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h> 
#include <time.h>
#include <fstream>
#include<conio.h >
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80 
 


// Funcion para situarse en algun punto del plano
void gotoxy(int x,int y){
	HANDLE hCon;//Creamos un identificardor de la ventana
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);//Recuperamos el identificador de la consola
	COORD dwPos;//Esta estructutura viene definia en windows.h
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition (hCon, dwPos);//Funcion de la biblioteca windows.h que nos permite dar una posición al cursor 
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
	   
}

//Conjunto de funciones para programar y manejar al jugador

class JUGADOR{  //Funcion clase, que sirve de inicio
	int x,y,vidas,monedas;
	float tiempo;
	
public:
	JUGADOR(int _x,int _y,int _vidas,int _monedas,float _tiempo):x(_x),y(_y),vidas(_vidas),monedas(_monedas),tiempo(_tiempo){}
	int X(){return x;}
	int Y(){return y;}
	int money(){return monedas;}
	int lifes(){return vidas;}
	void pintar();
	void borrar();
	void mover(); 
	void pintar_vidas();
	void perder_vidas();
	void mostrar_monedas();
	void sumar_monedas(){monedas++;}
	void mostrar_tiempo();
	void contar_tiempo();
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
				if(tecla==ARRIBA&& y==1){
					gotoxy(74,17);printf("HAS GANADO!!!");
						_getch();
						exit(1);
				}
				pintar();
				
			}
		
    
			
 }
 void JUGADOR::pintar_vidas(){//Funcion para dibujar las vidas del jugador
	gotoxy(150,3);
	printf("Vidas: %d",vidas);
	
 }
 void JUGADOR::perder_vidas(){

 	if(vidas==1){
 		system("cls");
 		gotoxy(63, 18);
		printf("Game Over :( \n");
		_getch();
		system("PAUSE");
		exit(1);
	 }
	 else{
 	vidas--;
 	borrar();
 	x=75;
 	y=34;

 }
 }
 
 void JUGADOR::mostrar_monedas(){
 	gotoxy(150,5);
 	printf("Monedas: %d",monedas);
 } 
 
 void JUGADOR::contar_tiempo(){
 	int min,sec,x=1000;
	
	for(min=0;min<60;min++){
			for(sec=0;sec<60;sec++)
			{
				gotoxy(150,7);printf("Tiempo: %02i:%02i\r",min,sec);
				Sleep(x);
			}
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
	void choque(class JUGADOR &J); 
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
void COCHES1::choque(class JUGADOR &J){
	if(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	x++;
	if(x>142){
		borrar();
		y=2;
		x=2;
	}	
}
	if(x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	x1++;
	if(x1>142){
		borrar();
		y=2;
		x1=2;
	}
}
	if(x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	x2++;
	if(x2>142){
		borrar();
		y=2;
		x2=2;
	}
}
}
//Funcion clase que controla el coche 2
 class COCHES2{
	int x=25,x1=70,x2=120,y;
		
public:
	COCHES2(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover(); 
	void choque(class JUGADOR &J); 
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
void COCHES2::choque(class JUGADOR &J){
	if(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x++;
	if(x>142){
		borrar();
		y=3;
		x=2;
	}	
}
	if(x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	
	x1++;
	if(x1>142){
		borrar();
		y=3;
		x1=2;
	}	
}
	if(x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x2++;
	if(x2>142){
		borrar();
		y=3;
		x2=2;
	}
}
}
//Funcion clase que controla el coche 3
class COCHES3{
	int x=50,x1=80,x2=120,y;
		
public:
	COCHES3(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover(); 
	void choque(class JUGADOR &J); 
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
void COCHES3::choque(class JUGADOR &J){
	if(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x++;
	if(x>141){
		borrar();
		y=7;
		x=2;
	}	
}
	if(x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	
	x1++;
	if(x1>141){
		borrar();
		y=7;
		x1=2;
	}	
}
	if(x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x2++;
	if(x2>141){
		borrar();
		y=7;
		x2=2;
	}
}
}
//Funcion clase que controla el coche 4
class COCHES4{
	int x=95, x1=48,y;
	
public: 
	COCHES4(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover();
	void choque(class JUGADOR &J); 
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
void COCHES4::choque(class JUGADOR &J){
	if(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x=x-2;
	if(x<4){
		borrar();
		y=5;
		x=141;			
    }		
}
	if(x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	
	x1=x1-2;
	if(x1<4){
		borrar();
		y=5;
		x1=141;			
    }	
}
}
//Funcion clase que controla el coche 5
class COCHES5{
	int x=95,x1=48,x2=25,y;
	
public: 
	COCHES5(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover();
	void choque(class JUGADOR &J); 
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
void COCHES5::choque(class JUGADOR &J){
	if(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x++;
	if(x>141){
		borrar();
		y=11;
		x=3;
	}
}
	if(x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	
	x1++;
	if(x1>141){
		borrar();
		y=11;
		x1=3;
	}	
}
	if(x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x2++;
	if(x2>141){
		borrar();
		y=11;
		x2=3;
	}	
}
}
//Funcion clase que controla el coche 6
class COCHES6{
	int x=18,x1=66,x2=113,y;
	
public: 
	COCHES6(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover();
	void choque(class JUGADOR &J); 
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
void COCHES6::choque(class JUGADOR &J){
	if((x+2>=J.X() && x+2<=J.X()+4 && y==J.Y())||(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()+1)){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
		borrar();

	x=x-2;
	if(x<4){
		borrar();
		y=14;
		x=141;	
		
}
}
	if((x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y())||(x1+2>=J.X() && x1+2<=J.X()+4  && y==J.Y()+1)){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
		borrar();
	
	x1=x1-2;
	if(x1<4){
		borrar();
		y=14;
		x1=141;	
		
}	
}
	if((x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y())||(x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y()+1)){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
		borrar();

	x2=x2-2;
	if(x2<4){
		borrar();
		y=14;
		x2=141;	
		
}
}
}
//Funcion clase que controla el coche 7
class COCHES7{
	int x=33,x1=78,x2=126,y;
		
public:
	COCHES7(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover(); 
	void choque(class JUGADOR &J); 
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
void COCHES7::choque(class JUGADOR &J){
	if(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x=x+2;
	if(x>140){
		borrar();
		y=19;
		x=2;
	}	
}
	if(x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	
	x1=x1+2;
	if(x1>140){
		borrar();
		y=19;
		x1=2;
	}	
}
	if(x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x2=x2+2;
	if(x2>140){
		borrar();
		y=19;
		x2=2;
	}
}
}
//Funcion clase que controla el coche gato 1
class GATO1{
	int x=10,x1=36,x2=64,x3=101,y;
		
public:
	GATO1(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover();
	void choque(class JUGADOR &J); 
	
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

void GATO1::choque(class JUGADOR &J){
	if((x+2>=J.X() && x+2<=J.X()+4 && y==J.Y())||(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()+1)){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
		borrar();

	x--;
	if(x<3){
		borrar();
		y=10;
		x=143;
	}
}
	if((x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y())||(x1+2>=J.X() && x1+2<=J.X()+4  && y==J.Y()+1)){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
		borrar();
	
	x1--;
	if(x1<3){
		borrar();
		y=10;
		x1=143;
	}	
}
	if((x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y())||(x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y()+1)){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
		borrar();

	x2--;
	if(x2<3){
		borrar();
		y=10;
		x2=143;
	}
}
	if((x3+2>=J.X() && x3+2<=J.X()+4 && y==J.Y())||(x3+2>=J.X() && x3+2<=J.X()+4 && y==J.Y()+1)){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
		borrar();

	x3--;
	if(x3<3){
		borrar();
		y=10;
		x3=143;
	}
}
}


//Funcion clase que controla el coche 8
class COCHES8{
	int x=90,x1=40,x2=15,y;
	
public: 
	COCHES8(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover();
	void choque(class JUGADOR &J);
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
void COCHES8::choque(class JUGADOR &J){
	if(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x++;
	if(x>141){
		borrar();
		y=25;
		x=3;
	}
}
	if(x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	
	x1++;
	if(x1>141){
		borrar();
		y=25;
		x1=3;
	}	
}
	if(x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x2++;
	if(x2>141){
		borrar();
		y=25;
		x2=3;
	}
}
}
//Funcion clase que controla el coche gato 2
class GATO2{
	int x=8,x1=72,x2=30,y;
		
public:
	GATO2(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover(); 
	void choque(class JUGADOR &J);
};
void GATO2::pintar(){ 
	gotoxy(x,y); printf("%c%c%c%c ",47,92,47,92);
	gotoxy(x,y-0.5); printf("%c%c%c ",48,95,95);	
	gotoxy(x1,y); printf("%c%c%c%c ",47,92,47,92);
	gotoxy(x1,y-0.5); printf("%c%c%c ",48,95,95);	
	gotoxy(x2,y); printf("%c%c%c%c ",47,92,47,92);
	gotoxy(x2,y-0.5);printf("%c%c%c ",48,95,95);			
}

void GATO2::borrar(){
	gotoxy(x,y); printf("        ");
	gotoxy(x,y-0.5); printf("        ");	
	gotoxy(x1,y); printf("        ");
	gotoxy(x1,y-0.5); printf("        ");
	gotoxy(x2,y); printf("        ");
	gotoxy(x2,y-0.5); printf("        ");			
}

void GATO2::mover(){
	x--;
	if(x<3){
		borrar();
		y=24;
		x=143;
	}	

	x1--;
	if(x1<3){
		borrar();
		y=24;
		x1=143;
	}	
	x2--;
	if(x2<3){
		borrar();
		y=24;
		x2=143;
	}	
	pintar();	
}
void GATO2::choque(class JUGADOR &J){
	if((x+2>=J.X() && x+2<=J.X()+4 && y==J.Y())||(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()+1)){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
		borrar();

	x--;
	if(x<3){
		borrar();
		y=24;
		x=143;
	}
}
	if((x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y())||(x1+2>=J.X() && x1+2<=J.X()+4  && y==J.Y()+1)){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
		borrar();
	
	x1--;
	if(x1<3){
		borrar();
		y=24;
		x1=143;
	}	
}
	if((x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y())||(x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y()+1)){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
		borrar();

	x2--;
	if(x2<3){
		borrar();
		y=24;
		x2=143;
	}
}
}

//Funcion clase que controla el coche 9
class COCHES9{
	int x,x1=49,x2=94,y=27;		
public:
	COCHES9(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover(); 
	void choque(class JUGADOR &J);
	
};
void COCHES9::pintar(){ 
	gotoxy(x,y); printf("   %c%c%c",254,254,254);
	gotoxy(x1,y); printf("   %c%c%c",254,254,254);
	gotoxy(x2,y); printf("   %c%c%c",254,254,254);	
}
void COCHES9::borrar(){ 
	gotoxy(x,y); printf ("     ");	
	gotoxy(x1,y); printf ("     ");	
	gotoxy(x2,y); printf ("     ");			
}

void COCHES9::mover(){
	x=x+2;
	if(x>141){
		borrar();
		y;
		x=2;
	}	
	x1=x1+2;
	if(x1>141){
		borrar();
		y;
		x1=2;
	}	
	x2=x2+2;
	if(x2>141){
		borrar();
		y;
		x2=2;
	}	
	pintar();	
}
void COCHES9::choque(class JUGADOR &J){
	if(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x=x+2;
	if(x>141){
		borrar();
		y;
		x=2;
	}
}
	if(x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	
	x1=x1+2;
	if(x1>141){
		borrar();
		y;
		x1=2;
	}	
}
	if(x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x2=x2+2;
	if(x2>141){
		borrar();
		y;
		x2=2;
	}
}
}
//Funcion clase que controla el coche 10
 class COCHES10{
	int x=25,x1=70,x2=120,y=29;
		
public:
	COCHES10(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover();
	void choque(class JUGADOR &J);
	
};
void COCHES10::pintar(){ 
	gotoxy(x,y); printf("   %c%c%c",254,254,254);
	gotoxy(x1,y); printf("   %c%c%c",254,254,254);
	gotoxy(x2,y); printf("   %c%c%c",254,254,254);	
}

void COCHES10::borrar(){ 
	gotoxy(x,y); printf ("     ");	
	gotoxy(x1,y); printf ("     ");	
	gotoxy(x2,y); printf ("     ");			
}

void COCHES10::mover(){
	x++;
	if(x>142){
		borrar();
		y;
		x=2;
	}	

	x1++;
	if(x1>142){
		borrar();
		y;
		x1=2;
	}	
	x2++;
	if(x2>142){
		borrar();
		y;
		x2=2;
	}	

	pintar();	
}
void COCHES10::choque(class JUGADOR &J){
	if(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x++;
	if(x>142){
		borrar();
		y;
		x=2;
	}
}
	if(x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	
	x1++;
	if(x1>142){
		borrar();
		y;
		x1=2;
	}	
}
	if(x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x2++;
	if(x2>142){
		borrar();
		y;
		x2=2;
	}
}
}
//Funcion clase que controla el coche 11
class COCHES11{
	int x=50,x1=80,x2=120,y;
		
public:
	COCHES11(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover(); 
	void choque(class JUGADOR &J);
	
};
void COCHES11::pintar(){ 
	gotoxy(x,y); printf("   %c%c%c%c",111,45,111,217);
	gotoxy(x1,y); printf("   %c%c%c%c",111,45,111,217);
	gotoxy(x2,y); printf("   %c%c%c%c",111,45,111,217);
}

void COCHES11::borrar(){ 
	gotoxy(x,y); printf ("      ");	
	gotoxy(x1,y); printf ("      ");	
	gotoxy(x2,y); printf ("      ");			
}

void COCHES11::mover(){
	x++;
	if(x>141){
		borrar();
		y=31;
		x=2;
	}	

	x1++;
	if(x1>141){
		borrar();
		y=31;
		x1=2;
	}	
	x2++;
	if(x2>141){
		borrar();
		y=31;
		x2=2;
	}	

	pintar();	
}
void COCHES11::choque(class JUGADOR &J){
	if(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x++;
	if(x>141){
		borrar();
		y=31;
		x=2;
	}
}
	if(x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y() ){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	
	x1++;
	if(x1>141){
		borrar();
		y=31;
		x1=2;
	}	
}
	if(x2+2>=J.X() && x2+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x2++;
	if(x2>141){
		borrar();
		y=31;
		x2=2;
	}
}
}
//Funcion clase que controla el coche 12
class COCHES12{
	int x=94, x1=48,y=21;
	
public: 
	COCHES12(int _x,int _y):x(_x),y(_y){}	
	void pintar();
	void borrar();
	void mover();
	void choque(class JUGADOR &J);
};
void COCHES12::pintar(){
	gotoxy(x,y); printf("%c%c%c    ",254,254,254);
	gotoxy(x1,y); printf("%c%c%c    ",254,254,254);
}
void COCHES12::borrar(){
	gotoxy(x,y); printf ("     ");	
	gotoxy(x1,y); printf ("     ");	
}

void COCHES12::mover(){
	x--;
	if(x<4){
		borrar();
		y;
		x=141;
	}	

	x1--;
	if(x1<4){
		borrar();
		y;
		x1=141;	
		
}
	pintar();
}
void COCHES12::choque(class JUGADOR &J){
	if(x+2>=J.X() && x+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();

	x--;
	if(x<4){
		borrar();
		y;
		x=141;
	}
}
	if(x1+2>=J.X() && x1+2<=J.X()+4 && y==J.Y()){
		J.perder_vidas();
		J.pintar();
		J.pintar_vidas();
	
	x1--;
	if(x1<4){
		borrar();
		y;
		x1=141;	
	}	
}

}
class MONEDA{
	int x,y;
	
public:
    MONEDA(int _x,int _y):x(_x),y(_y){}
    void pintar();
    void borrar();
    void contar_monedas( class JUGADOR &J);
	
};
void MONEDA::pintar(){
	gotoxy(x,y); printf("%c",284);
}
void MONEDA::borrar(){
	gotoxy(x,y); printf ("  ");	
}
void MONEDA::contar_monedas(class JUGADOR &J){
	if(x >=J.X() && x< J.X()+5 && y>=J.Y())
	{
		J.sumar_monedas();
		J.pintar();
		J.mostrar_monedas();
		x=0;
		y=0;
	
	}
	
}

//Funcion principal, donde se aplican las demas para ejecutar el programa
int main (void){
	system("COLOR 02");
	FILE *fichero;
	int max_distancia;
	int vector[2];
	int cierre,i;
	int recorrido;
	OcultarCursor(); 
	pintar_limites();
	JUGADOR J(75,34,3,0,0);
	J.pintar();
	J.pintar_vidas();
	J.mostrar_monedas();
	COCHES1 C1(2,2);
	COCHES2 C2(25,3);
	COCHES3 C3(50,7);
	COCHES4 C4(98,5);
	COCHES5 C5(95,11);
	COCHES6 C6(18,14);
	COCHES7 C7(33,19);
	COCHES8 C8(90,25);
	COCHES9 C9(2,27);
	COCHES10 C10(25,29);
	COCHES11 C11(50,31);
	COCHES12 C12(94,21);
    GATO1 G1(13,10);
    GATO2 G2(8,24);
    MONEDA M1(75,28);
    MONEDA M2(85,17);
    MONEDA M3(70,6);
    MONEDA M4(70,15);
    MONEDA M5(76,20);
    
	
//Creamos una varible lógica 
	while (J.lifes()!=0)//Para que el juego se repita mientras que la variable game over sea flaso
	{
		
			J.mover();
			C1.mover();C1.choque(J);
			C2.mover();C2.choque(J);
			C3.mover();C3.choque(J);	
			C4.mover();C4.choque(J);
		    C5.mover();C5.choque(J);
		    C6.mover();C6.choque(J);
		    C7.mover();C7.choque(J);
		    C8.mover();C8.choque(J);
		    C9.mover();C9.choque(J);
			C10.mover();C10.choque(J);
			C11.mover();C11.choque(J);
			C12.mover();C12.choque(J);
			G1.mover();G1.choque(J);
			G2.mover();G2.choque(J);
			M1.pintar();M1.contar_monedas(J);
			M2.pintar();M2.contar_monedas(J);
			M3.pintar();M3.contar_monedas(J);	
			M4.pintar(); M4.contar_monedas(J);	
			M5.pintar(); M5.contar_monedas(J);
			Sleep(30);
			
			vector[0]=J.money();
			vector[1]=J.lifes()-1;
			
			//Calcular el recorrido del jugador
			if(J.lifes() == 3){
				max_distancia=34;
			}
			else 
			if (J.lifes()==2){
				recorrido=34-J.Y();
			}
			if(J.lifes()==1 && (34-J.Y())>recorrido){
				max_distancia=34-J.Y();			
			}
			else max_distancia=recorrido;
	fichero=fopen("Resultados.txt","wt"); 
	if(fichero==NULL)
	  printf("Error");
	else
	{ 
			fprintf(fichero,"Monedas recogidas : %d \nVidas no utilizadas: %d\nMaxima distancia recorrida: %d m",vector[0],vector[1],max_distancia );
			fclose(fichero);
    }

}


    
		    
	system("PAUSE");
	return 0;
}

