#ifndef __TEXTURA
#define __TEXTURA

class Textura {
private:
  GLuint id;
  GLbyte * texels;
  unsigned long tamx;
  unsigned long tamy;

public:
  Textura(): id(0) {
    texels = 0;
  }

  Textura(const Textura& orig): texels(0) {
    id = orig.id;
    tamx = orig.tamx;

    if(orig.texels)
    {
      texels = new GLbyte[tamx*tamy];
      memcpy(texels, orig.texels, tamx*tamy*3*sizeof(GLbyte));
    }
  }

  ~Textura() {
    delete[] texels;
  }

  void cargar(std::string ruta) {
    jpg::Imagen * pimg = new jpg::Imagen(ruta);

    tamx = pimg->tamX();
    tamy = pimg->tamY();

    cout << "Componente x: " << tamx << endl;
    cout << "Componente y: " << tamy << endl;

    texels = new GLbyte[tamx*tamy];
    memcpy(texels, pimg->leerPixels(), tamx*tamy*3*sizeof(GLbyte));

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    // glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    // glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,tamx,tamy,0,GL_RGB,GL_UNSIGNED_BYTE,texels);
    // glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  }

  void activar() {
    if(texels) {
      glBindTexture(GL_TEXTURE_2D, id);
      glEnable(GL_TEXTURE_2D);
    }
  }

  void desactivar() {
    glDisable(GL_TEXTURE_2D);
  }
};

#endif
