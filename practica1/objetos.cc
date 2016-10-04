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
	glColor3f(r,g,b);
	glBegin(GL_LINES);
	
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
	glPolygonMode(GL_FRONT,GL_LINE);
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
	glPolygonMode(GL_FRONT,GL_LINE);
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

	//inicializacion de las caras de los triangulos


	_vertex3i c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12;
	

	c1.x=4;
	c1.y=8;
	c1.z=3;

	c2.x=4;
	c2.y=5;
	c2.z=8;

	c3.x=4;
	c3.y=3;
	c3.z=1;

	c4.x=1;
	c4.y=2;
	c4.z=3;

	c5.x=1;
	c5.y=2;
	c5.z=7;

	c6.x=1;
	c6.y=7;
	c6.z=6;
	
	c7.x=1;
	c7.y=5;
	c7.z=6;

	c8.x=1;
	c8.y=5;
	c8.z=4;

	c9.x=5;
	c9.y=6;
	c9.z=8;

	c10.x=6;
	c10.y=7;
	c10.z=8;
	
	c11.x=8;
	c11.y=7;
	c11.z=2;

	c12.x=8;
	c12.y=2;
	c12.z=3;


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

}
