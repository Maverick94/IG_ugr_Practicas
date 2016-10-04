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

}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

}
