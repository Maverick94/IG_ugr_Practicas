#ifndef __material_h
#define __material_h

class Material
{
  private:
    GLfloat comp_difusa[4]={0.5,0.5,0.5,1};
    GLfloat comp_ambiental[4]={0.5,0.5,0.5,1};
    GLfloat comp_especular[4]={0.5,0.5,0.5,1};
    float brillo=25;

  public:

    GLfloat* getDifusa(){return comp_difusa;}
    GLfloat* getAmbiental(){return comp_ambiental;}
    GLfloat* getEspecular(){return comp_especular;}
    float getBrillo(){return brillo;}

    void setComponenteDifusa(float r, float g, float b, float s)
    {
      comp_difusa[0]=r, comp_difusa[1]=g, comp_difusa[2]=b, comp_difusa[3]=s;
    }

    void setComponenteAmbiental(float r, float g, float b, float s)
    {
      comp_ambiental[0]=r, comp_ambiental[1]=g, comp_ambiental[2]=b, comp_ambiental[3]=s;
    }

    void setComponenteEspecular(float r, float g, float b, float s)
    {
      comp_especular[0]=r, comp_especular[1]=g, comp_especular[2]=b, comp_especular[3]=s;
    }

    void setComponenteBrillo(float brillo)
    {
      this->brillo=brillo;
    }


};


#endif
