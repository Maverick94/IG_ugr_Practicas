#ifndef __iluminacion_h
#define __iluminacion_h

  #include <math.h>
  class Iluminacion
  {
  private:

    float x=1,y=0,z=0;
    float alpha=0, beta=0;

    float r=10;
    GLfloat luzdireccional[4]={x,y,z,0};
    GLfloat colordireccional[4]={0.5,0.5,0.5,1};

    GLfloat luzposicional[4]={-4,5,10,1};
    GLfloat colorposicional[4]={0.5,0.5,0.5};

  public:

    Iluminacion(){}

    float getAlpha()
    {
      return alpha;
    }

    float getBeta()
    {
      return beta;
    }

    void setAlpha(float a)
    {
      alpha=a;
    }
    void setBeta(float b)
    {
      beta=b;
    }

    void setPosicionDireccional()
    {
      deshabilitarLuces();
      std::cout << "antes" << '\n';
      std::cout << "x: "<< x << '\n';
      std::cout << "y: "<< y << '\n';
      std::cout << "z: "<< z << '\n';
      // cout << "alf: " << alpha<<endl;
      // cout << "bet: " << beta<<endl;
      x=r*(sin(alpha)*cos(beta));
      y=r*(sin(alpha)*sin(beta));
      z=r*cos(alpha);

std::cout << "despues" << '\n';
      std::cout << "x: "<< x << '\n';
      std::cout << "y: "<< y << '\n';
      std::cout << "z: "<< z << '\n';
      habilitarLuces();
    }
    void setColorDireccional(float r, float g,float b){colordireccional[0]=r,colordireccional[1]=g,colordireccional[2]=b;}
    void setColorPosicional(float r, float g,float b){colorposicional[0]=r,colorposicional[1]=g,colorposicional[2]=b;}
    void habilitarLuces(){glEnable(GL_LIGHTING);}
    void deshabilitarLuces(){glDisable(GL_LIGHTING);}
    void encederLuz0()
    {
      glLightfv(GL_LIGHT0,GL_POSITION,luzdireccional);
      setColorDireccional(0.9,0.9,.9);
      glLightfv(GL_LIGHT1,GL_AMBIENT, colordireccional);
      //
      // setColorDireccional(0.4,0.4,0.4);
      // glLightfv(GL_LIGHT0,GL_AMBIENT, colordireccional);
      setColorDireccional(1,1,1);
      glLightfv(GL_LIGHT0,GL_DIFFUSE, colordireccional);
      glLightfv(GL_LIGHT0,GL_SPECULAR, colordireccional);

      setColorDireccional(1,1,1);
      glLightfv(GL_LIGHT0,GL_DIFFUSE, colordireccional);
      glLightfv(GL_LIGHT0,GL_SPECULAR, colordireccional);
      // setColorDireccional(0.4,0.4,0.4);
      // glLightfv(GL_LIGHT0,GL_SPECULAR, colordireccional);


      glEnable(GL_LIGHT0);



    }

    void encenderLuz1()
    {
      glLightfv(GL_LIGHT1,GL_POSITION,luzposicional);

      setColorDireccional(0.6,0.6,.6);
      glLightfv(GL_LIGHT1,GL_AMBIENT, colordireccional);
      setColorDireccional(1,1,1);
      glLightfv(GL_LIGHT1,GL_DIFFUSE, colordireccional);
      glLightfv(GL_LIGHT1,GL_SPECULAR, colordireccional);

      setColorDireccional(1,1,1);
      glLightfv(GL_LIGHT1,GL_DIFFUSE, colordireccional);
      glLightfv(GL_LIGHT1,GL_SPECULAR, colordireccional);
      // setColorDireccional(0.4,0.4,0.4);
      // glLightfv(GL_LIGHT1,GL_SPECULAR, colordireccional);


      glEnable(GL_LIGHT1);
    }


    void apagarLuz1()
    {
      glDisable(GL_LIGHT1);
    }
    void apagarLuz0()
    {
      glDisable(GL_LIGHT0);
    }
  };

#endif
