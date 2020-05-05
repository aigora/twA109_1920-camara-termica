// Representar pieza

#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h> 
#include <time.h>
#define FILAS 22

// Funciones prototipo. 
void gotoxy(int, int);

// Función principal 
int    main(void)
{
	 char pieza='*'; // Representación gráfica de la pieza   
	 int f=0,c=30;  // Coordenadas iniciales de la pieza 
	 
	 clock_t t_inicio,t_actual; //Medidas del tiempo
	 double segundos;
	 
	 gotoxy(c,f);  // Ubicamos el cursor    
	 printf("%c",pieza);  // Mostramos la pieza
	 
	 while (f<FILAS)
	 {
	 	t_actual = clock();  //Tiempo inicial
	 	
	 	segundos= (double)(t_actual-t_inicio)/CLOCKS_PER_SEC;
	 	
	 	if (segundos>0.2)
	 	{
	 		gotoxy(c,f);
	 		printf(" ");
	 		
	 		f++;
	 	    gotoxy(c,f); //Ubicamos la pieza
	 	    printf("%c",pieza);
	 	    t_inicio = clock(); //Restauramos el tiempo
	 		
		 }	
	 	
	 }
	 
	 printf ("\n");
	 return 0;
}
// Funciones 
void gotoxy (int x,int y )  //Intercambia el orden habitual, ya que la “x” identifica la columna, mientras la coordenada “y” representa la fila
{
	HANDLE hcon;      
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;     
	dwPos.X = x;
	dwPos.Y= y;      
	SetConsoleCursorPosition(hcon,dwPos);
}
