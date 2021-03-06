#ifndef _GRADIENT_H_
#define _GRADIENT_H_

class Gradient {
  float gx,gy;
  float z;
  float normGrad;
  float arctan;
  float arctangx;
  float arctangy;
  bool init_val;


  
public:
  Gradient ();
  Gradient(float gx, float gy, float z);
  
  static void getArrayGx (Gradient *arrG, float *arrF, int size);
  static void getArrayGy (Gradient *arrG, float *arrF, int size);
  static void getArrayZ (Gradient *arrG, float *arrF, int size);
  static void getArrayNorm (Gradient *arrG, float *arrF, int size);
  static void getArrayArctan (Gradient *arrG, float *arrF, int size);
  static void getArrayArctangx (Gradient *arrG, float *arrF, int size);
  static void getArrayArctangy (Gradient *arrG, float *arrF, int size);
  
  float getgx () { return this->gx; }
  float getgy () { return this->gy; }
  float getz () {return this->z;}
  float getnorm () { return this->normGrad; }
  float getarctan () {return this->arctan;}
  float getarctangx () {return this->arctangx;}
  float getarctangy () {return this->arctangy;}
  bool getinitval() {return this->init_val;}
  
  void setGradient (float gx,float gy, float z);
  void setgx(float gx);
  void setgy(float gy);


  
};

#endif
