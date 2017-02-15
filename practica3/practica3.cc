//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <GL/glut.h>
#include <ctype.h>
#include <math.h>
#include <vector>
#include "objetos.h"
#include "file_ply_stl.h"
#include <stdlib.h>


using namespace std;



// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;
//Variables para controlar las teclas
int opcion=0;
int cupi=0;
int modificadorPra=3;
int betpeonbar=1;

//Objetos creacion
_cubo cubo1(1);
_piramide pi1(1,1.5);
modeloPly m;
modeloPlyRevolucion r;
modeloPlyBarrido b;
modeloJerarquico cubojer(1);

//Angulos
int angulo_base=0;
float movimiento = 0;

//variables velocidad
float girogrua=0;
float velocidadcarrito=0;
float velocidadcuerda=0;



// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Size_x,Size_y,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int Window_x=50,Window_y=50,Window_width=450,Window_high=450;

// objetos


//**************************************************************************
//
//***************************************************************************

void clean_window()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// formato(x_minimo,x_maximo, y_minimo, y_maximo,plano_delantero, plano_traser)
	//  plano_delantero>0  plano_trasero>PlanoDelantero)
	glFrustum(-Size_x,Size_x,-Size_y,Size_y,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{
	// posicion del observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-Observer_distance);
	glRotatef(Observer_angle_x,1,0,0);
	glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
	glDisable(GL_LIGHTING);
	glLineWidth(2);
	glBegin(GL_LINES);
	// eje X, color rojo
	glColor3f(1,0,0);
	glVertex3f(-AXIS_SIZE,0,0);
	glVertex3f(AXIS_SIZE,0,0);
	// eje Y, color verde
	glColor3f(0,1,0);
	glVertex3f(0,-AXIS_SIZE,0);
	glVertex3f(0,AXIS_SIZE,0);
	// eje Z, color azul
	glColor3f(0,0,1);
	glVertex3f(0,0,-AXIS_SIZE);
	glVertex3f(0,0,AXIS_SIZE);
	glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************



void draw_objects()
{
	//pi1.draw_aristas(1.0,0,0,1.2);

	if(modificadorPra == 1) //Practica 1
	{
		switch(opcion)
		{
			case 0:
				if(cupi==0)
					cubo1.draw_puntos(1.0,0,0,12);
				else
					pi1.draw_puntos(1.0,0,0,12);
				break;
			case 1:
				if(cupi==0)
					cubo1.draw_aristas(1.0,0,0,1.2);
				else
					pi1.draw_aristas(1.0,0,0,1.2);
				break;
			case 2:
				if(cupi==0)
					cubo1.draw_solido(1.0,0,0);
				else
					pi1.draw_solido(1.0,0,0);
				break;
			case 3:
				if(cupi==0)
					cubo1.draw_solido_ajedrez(1.0,0,0,0,1.0,0);
				else
					pi1.draw_solido_ajedrez(1.0,0,0,0,1.0,0);
				break;
			}
	}
	else if(modificadorPra == 2) //Practica 2
	{
		switch(opcion)
			{
				case 0:
					if(betpeonbar==1)
						m.draw_puntos(1.0,0,0,2);
					else if(betpeonbar==2)
						r.draw_puntos(1.0,0,0,2);
					else
						b.draw_puntos(1.0,0,0,10);
					break;
				case 1:
					if(betpeonbar==1)
						m.draw_aristas(1.0,0,0,1.2);
					else if(betpeonbar==2)
						r.draw_aristas(1.0,0,0,1.2);
					else
						b.draw_aristas(1.0,0,0,1.2);
					break;
				case 2:
					if(betpeonbar==1)
						m.draw_solido(1.0,0,0);
					else if(betpeonbar==2)
						r.draw_solido(1.0,0,0);
						else
						b.draw_solido(1.0,0,0);
					break;
				case 3:
					if(betpeonbar==1)
						m.draw_solido_ajedrez(1.0,0,0,0,1.0,0);
					else if(betpeonbar==2)
						r.draw_solido_ajedrez(1.0,0,0,0,1.0,0);
					else
						b.draw_solido_ajedrez(1.0,0,0,0,1.0,0);
					break;
			}
	}

	else if(modificadorPra == 3) //Practica 3
	{
		cubojer.pintarModelo();

		//
		// 	glPushMatrix();
		// 		glRotatef(giro,0,0,1);
		// 	 	glTranslatef(0,1,0);
		// 	 	glScalef(1,2,1);
		// 		cubo1.draw_solido_ajedrez(1,0,0,0,0,1);
		// 	glPopMatrix();
		//
		// 	glPushMatrix();
		// 		glRotatef(giro,0,0,1);
		// 		glTranslatef(0,2,0);
		// 		glRotatef(giro2,0,0,1);
		// 	 	glTranslatef(0,1,0);
		// 	 	glScalef(1,2,1);
		// 		cubo1.draw_solido_ajedrez(1,0,0,0,0,1);
		// 	glPopMatrix();
		//
		// 	glPushMatrix();
		//
		// //Trasladamos al primer rectangulo y luego al segundo
		//
		// 		glRotatef(giro,0,0,1);
		// 		glTranslatef(0,2.0,0);
		// 		glRotatef(giro2,0,0,1);
		// 		glTranslatef(-0.4,2.0,0);
		// 		glRotatef(pinzas,0,0,1);
		// 		glScalef(0.2,0.2,0.2);
		//
		// 		glTranslatef(0,1,0);
		// 	 	glScalef(1,2,1);
		// 		cubo1.draw_solido_ajedrez(1,0,0,0,0,1);
		// 	glPopMatrix();
		//
		// 	glPushMatrix();
		// //Trasladamos al primer rectangulo y luego al segundo
		//
		// 		glRotatef(giro,0,0,1);//le damos el giro del rectangulo primero
		// 		glTranslatef(0,2.0,0);//lo subimos al rectangulo de mas arriba
		// 		glRotatef(giro2,0,0,1);//le damos el angulo del rectangulo de arriba
		// 		glTranslatef(0.4,2.0,0);//lo subimos al primer rectangulo ya pintado
		// 		glRotatef(-pinzas,0,0,1);//Le damos el angulo de las pinzas
		// 		glScalef(0.2,0.2,0.2);//Lo ponemos chiquitito
		//
		// 		glTranslatef(0,1,0);//Ponemos por encima del eje de coordenadas
		// 	 	glScalef(1,2,1);//Escalamos como rectangulo
		// 		cubo1.draw_solido_ajedrez(1,0,0,0,0,1);//Pintamos el cuadrado
		// 	glPopMatrix();


	}
}

void idle()
{
	cubojer.setAngulo(cubojer.getAngulo()+girogrua);

	if(cubojer.getGancho()+velocidadcuerda < 2.7 && cubojer.getGancho()+velocidadcuerda>=-0.6)
	{
		cubojer.setGancho(cubojer.getGancho()+velocidadcuerda);
		//cout << velocidadcuerda << "cuerda" << cubojer.getGancho()<<  endl;
		if(cubojer.getGancho() > 2.5 || cubojer.getGancho()< -0.5)
		{
		//	cubojer.setGancho(0.00);
			velocidadcuerda=0.000;
		}
	}

	if(cubojer.getMovimiento()+velocidadcarrito < 3.4 && cubojer.getMovimiento()+velocidadcarrito>=-0.1)
	{
		cubojer.setMovimiento(cubojer.getMovimiento()+velocidadcarrito);
	//	cout << velocidadcarrito << "cuerda" << cubojer.getGancho()<<  endl;
		if(cubojer.getMovimiento() > 3.2 || cubojer.getMovimiento()< -0.05)
		{
		//	cubojer.setGancho(0.00);
			velocidadcarrito=0.000;
		//	cout << velocidadcarrito<< "DEntro" << endl;
		}
	}

		glutPostRedisplay();


}

//**************************************************************************
//
//***************************************************************************

void draw(void)
{
	clean_window();
	change_observer();
	draw_axis();
	draw_objects();
	glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
	float Aspect_ratio;

	Aspect_ratio=(float) Alto1/(float )Ancho1;
	Size_y=Size_x*Aspect_ratio;
	change_projection();
	glViewport(0,0,Ancho1,Alto1);
	glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_key(unsigned char Tecla1,int x,int y)
{
	switch (toupper(Tecla1))
	{
		case 'Q':
			exit(0);
			break;

		case 'P':
			opcion=0; //puntos
			break;

		case 'E':
			opcion=1; //Alambre
			break;

		case 'S':
			opcion=2; //Sólido
			break;
		case 'A':
			opcion=3; //Ajedrez
			break;

		case '8':
			betpeonbar=1;
			break;

		case '9': //cambiar entre piramide y cubo
			cupi=0;
			betpeonbar=2;
			break;
		case '0':
			cupi=1;
			betpeonbar=3;
			break;
		case '1':	//Práctica 1
			modificadorPra=1;
			break;

		case '2':	//Practica2
			modificadorPra=2;
			break;

		case '3': //Practica 3
			modificadorPra=3;
			break;

			case 'O':
				cubojer.setAngulo(cubojer.getAngulo()+15);
			//	giro=giro+15;
			//	angulo=angulo+15;
				break;

			case 'I':
				cubojer.setAngulo(cubojer.getAngulo()-15);
			//	giro=giro-15;
				//angulo=angulo-15;
				break;

			case 'Y':
		//	giro2=giro2+15;
				if(cubojer.getMovimiento() < 3.4)
					cubojer.setMovimiento(cubojer.getMovimiento()+0.2);
			//	angulo=angulo+15;
				break;

			case 'U':
			//giro2=giro2-15;
				if(cubojer.getMovimiento() >-0.1)
					cubojer.setMovimiento(cubojer.getMovimiento()-0.2);
				//angulo=angulo-15;
				break;

			case 'T':
				if(cubojer.getGancho() < 2.7)
					cubojer.setGancho(cubojer.getGancho()+0.1);
				cout << cubojer.getGancho() << endl;

			//	angulo=angulo+15;
				break;

			case 'R':
			if(cubojer.getGancho() > -0.6)
				cubojer.setGancho(cubojer.getGancho()-0.1);

			cout << cubojer.getGancho() << endl;


				//angulo=angulo-15;
				break;


			case 'Z'://aumentar velocidad giro
				girogrua=girogrua+1;
			break;


			case 'X'://disminuir velocidad giro
				girogrua=girogrua-1;
			break;


			case 'C'://disminuir velocidad cuerda
					velocidadcuerda=velocidadcuerda-0.007;
				break;

			case 'V'://aumentar velocidad cuerda
					velocidadcuerda=velocidadcuerda+0.007;
				break;
//velocidadcarrito

			case 'B'://disminuir velocidad cuerda
				velocidadcarrito=velocidadcarrito-0.007;
				break;

			case 'N'://aumentar velocidad cuerda
				velocidadcarrito=velocidadcarrito+0.007;
				break;



			case '-':
				Observer_distance*=1.2;
				break;

			case '+':
				Observer_distance/=1.2;
				break;



	}

	glutPostRedisplay();

}

//***************************************************************************
// Funcion llamada cuando se aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_key(int Tecla1,int x,int y)
{
	switch (Tecla1)
	{
		case GLUT_KEY_LEFT:Observer_angle_y--;break;
		case GLUT_KEY_RIGHT:Observer_angle_y++;break;
		case GLUT_KEY_UP:Observer_angle_x--;break;
		case GLUT_KEY_DOWN:Observer_angle_x++;break;
		case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
		case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}
	glutPostRedisplay();
}



//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
	// se inicalizan la ventana y los planos de corte
	Size_x=0.5;
	Size_y=0.5;
	Front_plane=1;
	Back_plane=1000;

	// se incia la posicion del observador, en el eje z
	Observer_distance=4*Front_plane;
	Observer_angle_x=0;
	Observer_angle_y=0;

	// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
	// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
	glClearColor(1,1,1,1);

	// se habilita el z-bufer
	glEnable(GL_DEPTH_TEST);
	change_projection();
	glViewport(0,0,Window_width,Window_high);

}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

char modo_ejecucion=0;
int main(int argc, char **argv)
{

	if(argc < 6)
	{
		cerr << "Tienes que introducir un archivo PLY: ./practica2 <ruta archivo ply> <ruta perfil ply> <etapas> <ruta barrido ply> <numero barrido>"<< endl;
		return -1;
	}

	// se llama a la inicialización de glut
	glutInit(&argc, argv);

	// se indica las caracteristicas que se desean para la visualización con OpenGL
	// Las posibilidades son:
	// GLUT_SIMPLE -> memoria de imagen simple
	// GLUT_DOUBLE -> memoria de imagen doble
	// GLUT_INDEX -> memoria de imagen con color indizado
	// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
	// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
	// GLUT_DEPTH -> memoria de profundidad o z-bufer
	// GLUT_STENCIL -> memoria de estarcido
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	// posicion de la esquina inferior izquierdad de la ventana
	glutInitWindowPosition(Window_x,Window_y);

	// tamaño de la ventana (ancho y alto)
	glutInitWindowSize(Window_width,Window_high);

	// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
	// al bucle de eventos)
	glutCreateWindow("PRACTICA 3");

	// asignación de la funcion llamada "dibujar" al evento de dibujo
	glutDisplayFunc(draw);
	// asignación de la funcion llamada "change_window_size" al evento correspondiente
	glutReshapeFunc(change_window_size);
	// asignación de la funcion llamada "normal_key" al evento correspondiente
	glutKeyboardFunc(normal_key);
	// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
	glutSpecialFunc(special_key);


	glutIdleFunc(idle);

	// funcion de inicialización
	initialize();

	//modo_ejecucion=*(argv[2]);
	//Cargamos el modelo Ply en nuetra Estructura de datos
	m.cargarModelo(argv[1]);
	r.cargarModelo(argv[2]);
	r.generarModelo(atoi(argv[3]),r.vertices);
	b.cargarModelo(argv[4]);



	///////////////////////////////////////////////////////////////
	//////////////    Creación del barrido  ///////////////////////
	///////////////////////////////////////////////////////////////

	_vertex3f v0,v1,v2,v3, v4,v5,barrer;
	vector<_vertex3f> poligono;

	barrer.x=0;
	barrer.y=0;
	barrer.z=atoi(argv[5]);

	b.generarBarrido(b.vertices, barrer);

	// inicio del bucle de eventos
	glutMainLoop();
	return 0;
}
