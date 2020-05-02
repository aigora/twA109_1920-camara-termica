// Representar pieza

#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h> 

// Funciones prototipo. 
void gotoxy(int, int);

// Funci�n principal 
int    main(void)
{
	 char pieza='*'; // Representaci�n gr�fica de la pieza   
	 int f=0,c=30;  // Coordenadas iniciales de la pieza 
	 
	 gotoxy(c,f);  // Ubicamos el cursor    
	 printf("%c",pieza);  // Mostramos la pieza
	 
	 printf ("\n");
	 return 0;
}
// Funciones auxiliares visualizaci�n 
void gotoxy (int x,int y )  
{
	HANDLE hcon;      
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;     
	dwPos.X = x;
	dwPos.Y= y;      
	SetConsoleCursorPosition(hcon,dwPos);
}
