
// Representar pieza

#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h> 
#include <time.h>
#define FILAS 26

typedef struct
{
	char simbolo;
	int fila,columna;
}pieza;

typedef struct
{
	clock_t inicio,actual;
	double segundos;
	double intervalo;
}tiempo;

// Funciones prototipo. 
void gotoxy(int, int);

pieza inicializar_pieza(void);
void dibujar_pieza (pieza);
void borrar_pieza (pieza p);
pieza mover_pieza (pieza,int);

tiempo incializar_tiempo (void);
int superado_tiempo(tiempo);

// Función principal 
int    main(void)
{
	 pieza p;
	 p=inicializar_pieza();
	 char tecla;
	 
	 clock_t t_inicio,t_actual; //Medidas del tiempo
	 double segundos;
	 

	 t_inicio= clock ();
	 
	 dibujar_pieza(p);
	 while (p.fila<FILAS)
	 {
	 	t_actual = clock();  //Tiempo inicial
	 	
	 	segundos= (double)(t_actual-t_inicio)/CLOCKS_PER_SEC;
	 	
	 	if (segundos>0.2)
	 	{   //Movemos la pieza
	 		p =mover_pieza (p,'v');
	 	    t_inicio = clock(); //Restauramos el tiempo
	 		
		 }	
		 
		 if (kbhit()==1) //Si se ha pulsado una tecla
		 {
		 	tecla=getch(stdin); //Nos devuelve la tecla
		 	switch (tecla)
		 	{
		 		case 'm': p=mover_pieza(p,'>'); //Movemos  derecha y actualizamos columna
		 		          break;
		 		case 'n': p=mover_pieza(p,'<');//Movemos izquierda y actualizamos colimna
		 		          break;
			 }
		 }
	 	
	
	 }
	 
	 printf ("\n");
	 return 0;
}


// Funciones
pieza inicializar_pieza (void)
{
	pieza p;
	p.simbolo= '*';
	p.fila = 0;
	p.columna=60; //En la mitad de la pantalla;
	
	return p;
}


void dibujar_pieza (pieza p)
{
	gotoxy(p.columna,p.fila);
	printf("%c",p.simbolo);
}


void borrar_pieza (pieza p)
{
	gotoxy(p.columna,p.fila);
	printf(" ");	
}

 
void gotoxy (int x,int y )  //Intercambia el orden habitual, ya que la “x” identifica la columna, mientras la coordenada “y” representa la fila
{
	HANDLE hcon;      
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;     
	dwPos.X = x;
	dwPos.Y= y;      
	SetConsoleCursorPosition(hcon,dwPos);
}


pieza  mover_pieza (pieza p, int direccion) //Mover la pieza 
{
	borrar_pieza (p);
	
	switch (direccion)
	{
		case 'v': p.fila ++;
		          break;
		case '>': p.columna++;
		          break;
		case '<': p.columna--;
		          break;
	}
	dibujar_pieza(p);
	return p;
}


