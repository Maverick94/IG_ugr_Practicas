//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos.h"


//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
    
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
	glColor3f(r,g,b);
	glPointSize(grosor);
	glBegin(GL_POINTS);
	for(int i=0; i < vertices.size(); i++)
		glVertex3f(vertices[i].x,vertices[i].y,vertices[i].z);

	glEnd();

}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glColor3f(r,g,b);
	glBegin(GL_TRIANGLES);
	
      /*glVertex3f(vertices[caras[0].x].x, vertices[caras[0].x].y, vertices[caras[0].x].z); // V0
      glVertex3f(1.0f, 1.0f, 0.0f); // V1
      glVertex3f(2.0f, 0.0f, 0.0f); // V2*/

	for(int i=0; i < caras.size(); i++)
	{
		glVertex3f(vertices[caras[i].x].x,vertices[caras[i].x].y,vertices[caras[i].x].z);
		glVertex3f(vertices[caras[i].y].x,vertices[caras[i].y].y,vertices[caras[i].y].z);
		glVertex3f(vertices[caras[i].z].x,vertices[caras[i].z].y,vertices[caras[i].z].z);
	}
	glEnd();
}

//*************************************************************************
// dibujar en modo sólido
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
	glPolygonMode(GL_FRONT,GL_FILL);
	glColor3f(r,g,b);
	glBegin(GL_TRIANGLES);
	
      /*glVertex3f(vertices[caras[0].x].x, vertices[caras[0].x].y, vertices[caras[0].x].z); // V0
      glVertex3f(1.0f, 1.0f, 0.0f); // V1
      glVertex3f(2.0f, 0.0f, 0.0f); // V2*/

	for(int i=0; i < caras.size(); i++)
	{
		glVertex3f(vertices[caras[i].x].x,vertices[caras[i].x].y,vertices[caras[i].x].z);
		glVertex3f(vertices[caras[i].y].x,vertices[caras[i].y].y,vertices[caras[i].y].z);
		glVertex3f(vertices[caras[i].z].x,vertices[caras[i].z].y,vertices[caras[i].z].z);
	}
	glEnd();
}

//*************************************************************************
// dibujar en modo sólido con apariencia de ajedrez
//*************************************************************************

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2)
{
	glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_TRIANGLES);
	
      /*glVertex3f(vertices[caras[0].x].x, vertices[caras[0].x].y, vertices[caras[0].x].z); // V0
      glVertex3f(1.0f, 1.0f, 0.0f); // V1
      glVertex3f(2.0f, 0.0f, 0.0f); // V2*/

	for(int i=0; i < caras.size(); i++)
	{
		if(i % 2 == 0)
			glColor3f(r1,g1,b1);
		else
			glColor3f(r2,g2,b2);

		glVertex3f(vertices[caras[i].x].x,vertices[caras[i].x].y,vertices[caras[i].x].z);
		glVertex3f(vertices[caras[i].y].x,vertices[caras[i].y].y,vertices[caras[i].y].z);
		glVertex3f(vertices[caras[i].z].x,vertices[caras[i].z].y,vertices[caras[i].z].z);
	}
	glEnd();
}



//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{


	//incializacion de los puntos en el eje de coordenadas x,y,z 
	_vertex3f v1,v2,v3,v4,v5,v6,v7,v8;

	v1.x = 0.0;
	v1.y = 0.0;
	v1.z = 0.0;

	v2.x = 0.0;
	v2.y = tam;
	v2.z = 0.0;

	v3.x = 0.0;
	v3.y = tam;
	v3.z = tam;

	v4.x = 0.0;
	v4.y = 0.0;
	v4.z = tam;

	v5.x = tam;
	v5.y = 0.0;
	v5.z = tam;

	v6.x = tam;
	v6.y = 0.0;
	v6.z = 0.0;

	v7.x = tam;
	v7.y = tam;
	v7.z = 0.0;

	v8.x = tam;
	v8.y = tam;
	v8.z = tam;

	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);
	vertices.push_back(v4);
	vertices.push_back(v5);
	vertices.push_back(v6);
	vertices.push_back(v7);
	vertices.push_back(v8);

	//inicializacion de las caras de los triangulos NOTA:  Hay que restar en 1 los vertices que se toman. Ya que nosotros estamos accediendo a los indices, no a los vertices en sí.


	_vertex3i c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12;
	

	c1.x=3;
	c1.y=7;
	c1.z=2;

	c2.x=3;
	c2.y=4;
	c2.z=7;

	c3.x=3;
	c3.y=2;
	c3.z=0;

	c4.x=0;
	c4.y=1;
	c4.z=2;

	c5.x=0;
	c5.y=1;
	c5.z=6;

	c6.x=0;
	c6.y=6;
	c6.z=5;
	
	c7.x=0;
	c7.y=4;
	c7.z=5;

	c8.x=0;
	c8.y=4;
	c8.z=3;

	c9.x=4;
	c9.y=5;
	c9.z=7;

	c10.x=5;
	c10.y=6;
	c10.z=7;
	
	c11.x=7;
	c11.y=6;
	c11.z=1;

	c12.x=7;
	c12.y=1;
	c12.z=2;

	caras.push_back(c1);
	caras.push_back(c2);
	caras.push_back(c3);
	caras.push_back(c4);
	caras.push_back(c5);
	caras.push_back(c6);
	caras.push_back(c7);
	caras.push_back(c8);
	caras.push_back(c9);
	caras.push_back(c10);
	caras.push_back(c11);
	caras.push_back(c12);
}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{
	//incializacion de los puntos en el eje de coordenadas x,y,z 
	_vertex3f v0,v1,v2,v3,v4;

	v0.x = 0.0;
	v0.y = 0.0;
	v0.z = 0.0;

	v1.x = tam;
	v1.y = 0.0;
	v1.z = 0.0;

	v2.x = tam/2;
	v2.y = al;
	v2.z = tam/2;

	v3.x = 0.0;
	v3.y = 0.0;
	v3.z = tam;

	v4.x = tam;
	v4.y = 0.0;
	v4.z = tam;

	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);
	vertices.push_back(v4);

	_vertex3i c1,c2,c3,c4,c5,c6;

	c1.x = 0;
	c1.y = 3;
	c1.z = 1;

	c2.x = 0;
	c2.y = 1;
	c2.z = 2;

	c3.x = 0;
	c3.y = 2;
	c3.z = 3;

	c4.x = 3;
	c4.y = 4;
	c4.z = 1;

	c5.x = 3;
	c5.y = 4;
	c5.z = 2;

	c6.x = 4;
	c6.y = 1;
	c6.z = 2;

	caras.push_back(c1);
	caras.push_back(c2);
	caras.push_back(c3);
	caras.push_back(c4);
	caras.push_back(c5);
	caras.push_back(c6);

}
