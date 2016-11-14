//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>

using namespace std;

const float AXIS_SIZE=5000;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
	public:
		vector<_vertex3f> vertices;
		_puntos3D();
		void draw_puntos(float r, float g, float b, int grosor);


};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
	public:
		vector<_vertex3i> caras;

		_triangulos3D();
		void draw_aristas(float r, float g, float b, int grosor);
		void draw_solido(float r, float g, float b);
		void draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);

};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
	public:
		_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
	public:
		_piramide(float tam=0.5, float al=0.75);
};


//*************************************************************************
// Clase PLY
//*************************************************************************
class modeloPly: public _triangulos3D
{

	public:

		modeloPly();
		void cargarModelo (char* filename);
};

class modeloPlyRevolucion: public modeloPly
{
	private:
		_vertex3f rotarPunto(_vertex3f p, float ang);
		_vertex3f generarPuntoTapa(vector <_vertex3f> &p,int var);

	public:
		modeloPlyRevolucion();
		void generarModelo(int etapas,vector <_vertex3f> perfil);


};



class modeloPlyBarrido: public modeloPly
{
	private:
		//_vertex3f generarPuntoTapa(vector <_vertex3f> &p,int var);



	public:
		modeloPlyBarrido();
		void generarBarrido (vector <_vertex3f> perfil, _vertex3f verti);


};


class modeloJerarquico
{
	private:
		_cubo *cubo;
		_piramide *pira;
		int angulo;

		void init(int tam);


	public:
		modeloJerarquico();
		modeloJerarquico(int tam=1);
		void pintarModelo();
		void setAngulo(int angulo);
		int getAngulo();




};
