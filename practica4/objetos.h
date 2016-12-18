//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include "material.h"
#include "iluminacion.h"
#include "jpg_imagen.hpp"
#include "jpg_jinclude.h"
#include "textura.h"


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
		vector<_vertex3f> caras_normalizadas;
		vector<_vertex3f> vertices_normalizados;
		Material material;
		Textura textura;
		vector<_vertex2f> coordendastex;

		_triangulos3D();
		/// Formas de representación ///
		void draw_aristas(float r, float g, float b, int grosor);
		void draw_solido(float r, float g, float b);
		void draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
		void draw_normales_vertices(float r, float g, float b);
		void draw_normales_caras(float r, float g, float b);
		void draw_suavizado_plano(float r, float g, float b);
		void draw_suavizado_gouraud(float r, float g, float b);

		/// Normalizacion de Vectores ///
		void normalizarVectorCaras();
		void normalizarVectorVertices();
		void normalizarVectores();



	private:
		float productoEscalar(const _vertex3f &a, const _vertex3f &b);
		_vertex3f productoVectorial(const _vertex3f &a, const _vertex3f &b);
		void normalizar(_vertex3f &v);

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
		 //Perfil sin revolionar

		void perfilModelo();
	public:
		bool generarTapas;
vector<_vertex3f> p;
	int et;//numero de etapas
		modeloPlyRevolucion();
		void generarModelo(int etapas,vector <_vertex3f> perfil);

		///Aplicaciones para texturas ///
		void calculoCordenadasTexturas();

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
		float mov_caja;
		float gancho;

		void init(int tam);


	public:
		modeloJerarquico();
		modeloJerarquico(int tam=1);
		void pintarModelo();
		void setAngulo(int angulo);
		int getAngulo();
		void setMovimiento(float mov_caja);
		float getMovimiento();
		void setGancho(float gancho);
		float getGancho();





};
