#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string.h>


#include "utilTool.hpp"

/**********************************
 *
 * countLinesFiles count the number of lines of a file
 * 
********************************/
int countLinesFile(char *fname)
{

  int ch;
  int lines = 0;
  FILE *f;

  if ( (f = fopen(fname, "r")) == NULL)
    printf("(readASCIIFile) Can't open file named '%s' for reading\n", fname);

  while (EOF != (ch=fgetc(f)))
    if (ch=='\n')
      ++lines;

  fclose(f);

  return lines;

}

/**********************************
 *
 * countLinesFiles count the number of lines of a file
 * 
********************************/
int countLinesFile(std::string fname)
{

  int lines = 0;
  std::string l;
  std::ifstream f;

  f.open(fname.c_str(),std::ios::in);

  if(f.is_open())
    {
      while (std::getline(f,l))
	  ++lines;

      f.close();
    }
  else
    std::cout << "unable open file (countLinesFiles) " << fname << "\n";

  return lines;

}

/**********************************
 *
 * countCharsLine count the number of character of a line
 * 
********************************/
int countCharsLine(char *fname)
{

  int ch;
  int size = 1;
  FILE *f;

  if ( (f = fopen(fname, "r")) == NULL)
    printf("(countCharsLine) Can't open file named '%s' for reading\n", fname);

  while ('\n' != (ch=fgetc(f)))
    {
      if (ch==' ')
	size++;
    }
  fclose(f);

  return size;

}

/**********************************
 *
 * countCharsLine count the number of character of a line
 * 
********************************/
int countCharsLine(std::string fname)
{
  int i;
  int size = 1;
  std::string l;
  std::ifstream f;

  f.open(fname.c_str(),std::ios::in);

  if(f.is_open())
    {
      std::getline(f,l);

      for(i = 0; i < l.size(); i++)
	{
	  if(l[i] == ' ')
	    size++;
	}
      f.close();
    }
  else
    std::cout << "unable open file (countCharLine) " << fname << "\n";

  return size;

}

/**********************************
 *
 * countNbZeros count how many zeros there is in the array t
 * 
********************************/

int countNbZeros(int *t, int size)
{
  int i;
  int nbZeros = 0;
  
  for(i = 0; i < size; i++)
    {
      if(t[i] == 0)
	nbZeros ++;
    }
  return nbZeros;
}

/**********************************
 *
 * countNbZeros_patch count how many zeros there is in the patch
 * 
********************************/

int countNbZeros_patch(int *t, int sizeX, int sizeY, int ideb, int jdeb, int sizep)
{
  int i,j;
  int nbZeros = 0;

  for(j = jdeb; j < sizep+jdeb; j++)
    {
      for(i = ideb; i < sizep+ideb; i++)
	{
	  if(t[j*sizeX + i] == 0)
	    nbZeros ++;
	}
    }
  return nbZeros;
}



/**********************************
 *
 * maxInt find the maximun of a array of int
 * 
********************************/

int maxInt(int *tmax, int size)
{
  int i;
  int max =  tmax[0];

  for (i =1; i < size; i++)
    {
      if ( max < tmax[i])
	max = tmax[i];
    }
  return max;
}

/**********************************
 *
 * secMaxInt find the maximun of a array of int
 * 
********************************/

int secondMaxInt(int *tmax, int size)
{
  int i;
  int max =  tmax[0];
  int secMax;

  for (i =1; i < size; i++)
    {
      if ( max < tmax[i])
	{
	  secMax = max;
	  max = tmax[i];
	}
    }
  return secMax;
}

/**********************************
 *
 * maxFloat find the maximun of a array of float
 * 
********************************/
float maxFloat(float *tmax, int size)
{
  int i;
  float max =  tmax[0];

  for (i =1; i < size; i++)
    {
      if ( max < tmax[i])
	max = tmax[i];
    }
  return max;
}

/**********************************
 *
 * secondMaxFloat find the maximun of a array of float
 * 
********************************/
float secondMaxFloat(float *tmax, int size)
{
  int i;
  float max =  tmax[0];
  float secMax;
  for (i =1; i < size; i++)
    {
      if ( max < tmax[i])
	{
	  secMax = max;
	  max = tmax[i];
	}
    }
  return secMax;
}

/**********************************
 *
 * minFloat find the minimum of a array of float
 * 
********************************/
float minFloat(float *tmin, int size)
{
  int i;
  float min =  tmin[0];

  for (i =1; i < size; i++)
    {
      if ( min > tmin[i])
	min = tmin[i];
    }
  return min;
}


float distMAD(float x, float y)
{
    return fabs(x - y);
}

float distScoring(float x, float y)
{
  if(x == y)
    return 0;
  if(x == 0.0 || y == 0.0)
    return 1;
  return 1;
}


/**********************************
 *
 * normalizeFloatArr normalize sur 256 un tableau de float
 * 
********************************/
void normalizeFloatArr(float *arrF, int size)
{
  int i;
  float aMax = maxFloat(arrF,size);
  float aMin = minFloat(arrF,size);

  if(aMax != aMin)
    {
      for(i = 0; i < size; i++)
	{
	  arrF[i] = (arrF[i]-aMin)*(255/(aMax-aMin));
	}
    }
}

/**********************************
 *
 * meanPatch calculate the mean of a patch of size sizeP 
 * in X of size sizeX*sizeY
 * the index of the upper left corner of the patch is ideb, jdeb
 * 
********************************/
float meanPatch(int *X, int sizeX, int sizeY, int ideb, int jdeb, int sizeP)
{
  int i,j;
  float mean = 0.0;
  
  j = jdeb;
  while(j < jdeb+sizeP)
    {
      i = ideb;
      while(i < ideb+sizeP)
	{
	  mean += X[j*sizeX+i];
	  i++;
	  i = i % sizeX;
	}
      j++;
      j = j % sizeY;
    }

  return mean/(sizeP*sizeP);
}


/**********************************
 *
 * loadFiles_grad prends une liste de fichier sous le format : "x y gx gy norm arctan \n"
 * et créer une liste de tableau de gradien correspondent a une liste de chaque image des gradients
 * 
********************************/

void loadFiles_mapCvx(char **filenamesGrad, int **ac, int *sizeX, int *sizeY, int sizei)
{
  int i,j,k,l;
  int nbLine, nbChar;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  
  for (i = 0; i < sizei; i++)
    {
    
      fileGrad.open(filenamesGrad[i],std::ios::in);

      if(fileGrad.is_open())
	{
	  nbLine = countLinesFile(filenamesGrad[i]);
	  nbChar = countCharsLine(filenamesGrad[i]);
	  //  printf("%d \n", nbChar);
	  ac[i] = new int[nbLine*nbChar];
	  sizeX[i] = nbChar;
	  sizeY[i] = nbLine;

	  j = 0;
	  while (std::getline(fileGrad,line))
	    {
	      // printf("%s \n", line.c_str());
	      ideb=0;
	      l = 0;
	      for(k = 0; k < line.size(); k++)
		{
		  // printf("%d %d \n", i, line.size());
		  if(line[k] == ' ')
		    {
		      ac[i][j*sizeX[i]+l] = std::stoi(line.substr(ideb));
		      ideb = k+1;
		     
		      l++;
		    }
		}
	      j++;
	    }
	  
	  fileGrad.close();
	  

	}
      else
	{
	  std::cout << "(loadFiles_matrixCvx) doesn't open files " <<  filenamesGrad[i] << " \n";
	}
    } 
}  

/**********************************
 *
 * loadFiles_grad prends une liste de fichier sous le format : "x y gx gy norm arctan \n"
 * et créer une liste de tableau de gradien correspondent a une liste de chaque image des gradients
 * 
********************************/

void loadFiles_mapCvx(char **filenamesGrad, float **ac, int *sizeX, int *sizeY, int sizei)
{
  int i,j,k,l;
  int nbLine, nbChar;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream fileGrad;

  
  for (i = 0; i < sizei; i++)
    {
    
      fileGrad.open(filenamesGrad[i],std::ios::in);

      if(fileGrad.is_open())
	{
	  nbLine = countLinesFile(filenamesGrad[i]);
	  nbChar = countCharsLine(filenamesGrad[i]);
	  //  printf("%d \n", nbChar);
	  ac[i] = new float[nbLine*nbChar];
	  sizeX[i] = nbChar;
	  sizeY[i] = nbLine;

	  j = 0;
	  while (std::getline(fileGrad,line))
	    {
	      // printf("%s \n", line.c_str());
	      ideb=0;
	      l = 0;
	      for(k = 0; k < line.size(); k++)
		{
		  // printf("%d %d \n", i, line.size());
		  if(line[k] == ' ')
		    {
		      ac[i][j*sizeX[i]+l] = std::stof(line.substr(ideb));
		      ideb = k+1;
		     
		      l++;
		    }
		}
	      j++;
	    }
	  
	  fileGrad.close();
	  

	}
      else
	{
	  std::cout << "(loadFiles_matrixCvx) doesn't open files " <<  filenamesGrad[i] << " \n";
	}
    } 
}  


/**********************************
 *
 * readASCIIFile open an ASCII file with the coord (x,y) of the panorama 
 * and the elevation of the 3D object z
 * and initialize the array courbElev who represent the panorama in an array
 * 
********************************/

void readASCIIFile_courbElev(char *fname, float **courbElev, bool **maskCourbElev, int *sizeX,int *sizeY)
{
  FILE *fAsc; 
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  int nbLine;
  char *tok;
  int *x,*y;
  float *z;
  int i = 0;

  nbLine = countLinesFile(fname);
  x = (int*)malloc(nbLine*sizeof(int));
  y = (int*)malloc(nbLine*sizeof(int));
  z = (float*)malloc(nbLine*sizeof(float));

  if ( (fAsc = fopen(fname, "r")) == NULL )
    printf("(readASCIIFile_courbElev) Can't open file named '%s' for reading\n", fname);
  else
    {
      while ((read = getline(&line, &len, fAsc)) != -1) {


	tok = strtok(line, " ");
	x[i] = atoi(tok);
 
	tok = strtok(NULL, " ");
	y[i] = atoi(tok);

	tok = strtok(NULL, " ");
	z[i] = atof(tok);

	i++;

      }

      *sizeX = maxInt(x, nbLine)+1;
      *sizeY = maxInt(y,nbLine)+1;

      *courbElev = (float*)calloc((*sizeX ) * (*sizeY), sizeof(float));
      *maskCourbElev = (bool*)calloc((*sizeX ) * (*sizeY), sizeof(bool));

  
      for (i = 0; i < nbLine; i++)
	{
	  (*courbElev)[y[i]* (*sizeX) + x[i]] = z[i];
	  (*maskCourbElev)[y[i]* (*sizeX) + x[i]] = true;
	}

      fclose(fAsc);

      free(line);
      free(x);
      free(y);
      free(z);
    }
}

/**********************************
 *
 * loadFiles_grad prends une liste de fichier sous le format : "x y gx gy norm arctan \n"
 * et créer une liste de tableau de gradien correspondent a une liste de chaque image des gradients
 * 
********************************/

void loadFile_matrixScore(char *filenamesMatScore, float *matSc, int sizeX, int sizeY)
{
  int i,j,k,l;
  int nbLine, nbChar;
  std::string line;  
  std::string::size_type ideb;

  std::ifstream file;

  

  file.open(filenamesMatScore,std::ios::in);

  if(file.is_open())
    {
      nbLine = countLinesFile(filenamesMatScore);
      nbChar = countCharsLine(filenamesMatScore);
      //  printf("%d \n", nbChar);
      sizeX = nbChar-1;
      sizeY = nbLine;

      j = 0;
      while (std::getline(file,line))
	{
	  ideb=0;
	  l = 0;

	  for(k = 0; k < line.size(); k++)
	    {
	      // printf("%d %d \n", i, line.size());
	      if(line[k] == ' ')
		{ 
		  matSc[j*sizeX+l] = std::stof(line.substr(ideb));
		  ideb = k+1;
		  l++;
		}
	    }

	  j++;
	}
	  
      file.close();
	  

    }
  else
    {
      std::cout << "(loadFiles_matrixScore) doesn't open files " <<  filenamesMatScore << " \n";
    }
    
}  


/**********************************
 *
 * saveImageAscii_grad save 3 image, one for gx and one for gy
 * with the value gx(gy) for the coord (x,y)
 * The last one is ASCII style file with gx gy <gx,gy> (euclidian norm) and arctan.
 *
********************************/

void saveImageAscii_grad(char *fnameout_gx, char *fnameout_gy, char *fnameout_gxgy, Gradient *gradImg, int sizeX, int sizeY)
{
  int i,j;
  std::ofstream fileASC_gx (fnameout_gx, std::ios::out);
  std::ofstream fileASC_gy (fnameout_gy, std::ios::out);
  std::ofstream fileASC_gxgy (fnameout_gxgy, std::ios::out);
  
  if(fileASC_gx.is_open() && fileASC_gy.is_open() && fileASC_gxgy.is_open())
    {
      for(j = 0; j < sizeY; j++)
	{
	  for(i =0; i < sizeX; i++)
	    {
	      fileASC_gx << i << " " << j << " " << gradImg[j*sizeX+i].getgx() << "\n";
	      fileASC_gy << i << " " << j << " " << gradImg[j*sizeX+i].getgy() << "\n";
	      fileASC_gxgy << i << " " << j << " " << gradImg[j*sizeX+i].getgx() << " " << gradImg[j*sizeX+i].getgy() << " " << gradImg[j*sizeX+i].getnorm() << " " << gradImg[j*sizeX+i].getarctangx() << " " << gradImg[j*sizeX+i].getarctangx() << "\n";
	    }
	}
      fileASC_gx.close();
      fileASC_gy.close();
      fileASC_gxgy.close();
    }
  else
    {
      std::cout << "(saveImageAscii_courbElev) Unable to open file";
    }
}

/**********************************
 *
 * saveImageAscii_deriv save 1 image in
 * ASCII style file with gx gy dx dy <gx,gy> (euclidian norm) and arctan.
 *
********************************/

void saveImageAscii_deriv(char *fnameout_deriv, Gradient *gradImg, SecondDeriv *sDeriv, int sizeX, int sizeY)
{
  int i,j;
  std::ofstream fileASC_deriv (fnameout_deriv, std::ios::out);
  
  if(fileASC_deriv.is_open())
    {
      for(j = 0; j < sizeY; j++)
	{
	  for(i =0; i < sizeX; i++)
	    {

	      fileASC_deriv << i << " " << j << " " << gradImg[j*sizeX+i].getgx() << " " << gradImg[j*sizeX+i].getgy() << " " << sDeriv[j*sizeX+i].getdx() << " " << sDeriv[j*sizeX+i].getdy() << " " << gradImg[j*sizeX+i].getnorm() << " " << gradImg[j*sizeX+i].getarctangx() << " " << gradImg[j*sizeX+i].getarctangx() << "\n";
	    }
	}
      fileASC_deriv.close();
    }
  else
    {
      std::cout << "(saveImageAscii_deriv) Unable to open file";
    }
}

/**********************************
 *
 * loadFile_grad prends un fichier sous le format : "x y gx gy norm arctan \n"
 * et créer un tableau de gradients correspondent aux gradients d'une image
 * 
********************************/

/*void loadFile_grad(char *filenamesGrad, ArrGradient *ag)
{
  int  j, sizeX, sizeY;
  int nbLine;
  std::string line;  
  std::string tok;
  std::stringstream ss;
  int *x, *y;
  float *gx, *gy;

  std::ifstream fileGrad;


    
  fileGrad.open(filenamesGrad,std::ios::in);

  if(fileGrad.is_open())
    {
      nbLine = countLinesFile(filenamesGrad);
      x = (int*)malloc(nbLine*sizeof(int));
      y = (int*)malloc(nbLine*sizeof(int));
      gx = (float*)malloc(nbLine*sizeof(float));
      gy = (float*)malloc(nbLine*sizeof(float));

      j = 0;
      while (std::getline(fileGrad,line))
	{

	  ss.str( line + "\n");
	      
	  ss >> x[j];
	  ss >> y[j];
	  ss >> gx[j];
	  ss >> gy[j];
	      
	  j++;
	}

      sizeX = maxInt(x, nbLine)+1;
      sizeY = maxInt(y, nbLine)+1;

      ag->initGradientArr(sizeX,sizeY);
	  
  
      for (j = 0; j < nbLine; j++)
	{
	  ag->setGradient(gx[j], gy[j], x[j], y[j]);
	}
	  
      fileGrad.close();
	  
      free(x);
      free(y);
      free(gx);	  
      free(gy);
    }
  else
    {
      std::cout << "(loadFile_grad) doesn't open files " <<  filenamesGrad << " \n";
    }
    
	

  
}  */


/**********************************
 *
 * loadFile_deriv prends un fichier sous le format : "x y gx gy dx dy norm arctan \n"
 * et créer un tableau de deriv correspondent aux derivee premiere et seconde d'une image
 * 
********************************/

void loadFile_deriv(char *filenamesDeriv, ArrDeriv *ad)
{
  int  j, sizeX, sizeY;
  int nbLine;
  std::string line;  
  std::string tok;
  std::stringstream ss;
  int *x, *y;
  float *gx, *gy;
  float *dx, *dy;

  std::ifstream fileDeriv;


    
  fileDeriv.open(filenamesDeriv,std::ios::in);

  if(fileDeriv.is_open())
    {
      nbLine = countLinesFile(filenamesDeriv);
      x = (int*)malloc(nbLine*sizeof(int));
      y = (int*)malloc(nbLine*sizeof(int));
      gx = (float*)malloc(nbLine*sizeof(float));
      gy = (float*)malloc(nbLine*sizeof(float));
      dx = (float*)malloc(nbLine*sizeof(float));
      dy = (float*)malloc(nbLine*sizeof(float));

      j = 0;
      while (std::getline(fileDeriv,line))
	{

	  ss.str( line + "\n");
	      
	  ss >> x[j];
	  ss >> y[j];
	  ss >> gx[j];
	  ss >> gy[j];
	  ss >> dx[j];
	  ss >> dy[j];
	  
	  j++;
	}

      sizeX = maxInt(x, nbLine)+1;
      sizeY = maxInt(y, nbLine)+1;

      ad->initDerivArr(sizeX,sizeY);
	  
  
      for (j = 0; j < nbLine; j++)
	{
	  ad->setDeriv(gx[j], gy[j], dx[j], dy[j], x[j], y[j]);
	}
	  
      fileDeriv.close();
	  
      free(x);
      free(y);
      free(gx);	  
      free(gy);
      free(dx);	  
      free(dy);
    }
  else
    {
      std::cout << "(loadFile_deriv) doesn't open files " <<  filenamesDeriv << " \n";
    }
    
	

  
}  

/**********************************
 *
 * loadFiles_grad prends une liste de fichier sous le format : "x y gx gy norm arctan \n"
 * et créer une liste de tableau de gradien correspondent a une liste de chaque image des gradients
 * 
********************************/

/*void loadFiles_grad(char **filenamesGrad, ArrGradient *ag, int sizei)
{
  int i, j, sizeX, sizeY;
  int nbLine;
  std::string line;  
  std::string tok;
  std::stringstream ss;
  int *x, *y;
  float *gx, *gy;

  std::ifstream fileGrad;


  
  for (i = 0; i < sizei; i++)
    {
    
      fileGrad.open(filenamesGrad[i],std::ios::in);

      if(fileGrad.is_open())
	{
	  nbLine = countLinesFile(filenamesGrad[i]);
	  x = (int*)malloc(nbLine*sizeof(int));
	  y = (int*)malloc(nbLine*sizeof(int));
	  gx = (float*)malloc(nbLine*sizeof(float));
	  gy = (float*)malloc(nbLine*sizeof(float));

	  j = 0;
	  while (std::getline(fileGrad,line))
	    {

	      ss.str( line + "\n");
	      
	      ss >> x[j];
	      ss >> y[j];
	      ss >> gx[j];
	      ss >> gy[j];
	      
	      j++;
	    }

	  sizeX = maxInt(x, nbLine)+1;
	  sizeY = maxInt(y, nbLine)+1;

	  (ag[i]).initGradientArr(sizeX,sizeY);
	  

	  for (j = 0; j < nbLine; j++)
	    {
	      (ag[i]).setGradient(gx[j], gy[j], x[j], y[j]);
	    }
	  
	  fileGrad.close();
	  
	  free(x);
	  free(y);
	  free(gx);	  
	  free(gy);
	}
      else
	{
	  std::cout << "(loadFilesGrad) doesn't open files " <<  filenamesGrad[i] << " \n";
	}
    } 
    }  */

/**********************************
 *
 * loadFiles_deriv prends une liste de fichier sous le format : "x y gx gy dx dy norm arctan \n"
 * et créer une liste de tableau de derive correspondent a une liste de chaque image des derivees premiere et seconde
 * 
********************************/

void loadFiles_deriv(char **filenamesDeriv, ArrDeriv *ad, int sizei)
{
  int i, j, sizeX, sizeY;
  int nbLine;
  std::string line;  
  std::string tok;
  std::stringstream ss;
  int *x, *y;
  float *gx, *gy;
  float *dx, *dy;

  std::ifstream fileDeriv;


  
  for (i = 0; i < sizei; i++)
    {
    
      fileDeriv.open(filenamesDeriv[i],std::ios::in);

      if(fileDeriv.is_open())
	{
	  nbLine = countLinesFile(filenamesDeriv[i]);
	  x = (int*)malloc(nbLine*sizeof(int));
	  y = (int*)malloc(nbLine*sizeof(int));
	  gx = (float*)malloc(nbLine*sizeof(float));
	  gy = (float*)malloc(nbLine*sizeof(float));

	  j = 0;
	  while (std::getline(fileDeriv,line))
	    {

	      ss.str( line + "\n");
	      
	      ss >> x[j];
	      ss >> y[j];
	      ss >> gx[j];
	      ss >> gy[j];
	      ss >> dx[j];
	      ss >> dy[j];
	      
	      j++;
	    }

	  sizeX = maxInt(x, nbLine)+1;
	  sizeY = maxInt(y, nbLine)+1;

	  (ad[i]).initDerivArr(sizeX,sizeY);
	  

	  for (j = 0; j < nbLine; j++)
	    {
	      (ad[i]).setDeriv(gx[j], gy[j], dx[j], dy[j], x[j], y[j]);
	    }
	  
	  fileDeriv.close();
	  
	  free(x);
	  free(y);
	  free(gx);	  
	  free(gy);
	  free(dx);	  
	  free(dy);
	}
      else
	{
	  std::cout << "(loadFilesDeriv) doesn't open files " <<  filenamesDeriv[i] << " \n";
	}
    } 
}  

/**********************************
 *
 * saveMatrixScore save 1 image, matrix of the score
 * of float array
 * 
********************************/

void saveMatrixScore(char *fnameout, float *matDist, int sizeMat)
{
  int i,j;
  std::ofstream fileMat (fnameout, std::ios::out);

  
  if(fileMat.is_open()  )
    {
      for(j = 0; j < sizeMat; j++)
	{
	  for(i =0; i < sizeMat; i++)
	    {
	      fileMat << matDist[j*sizeMat + i] << " ";
	    }
	  fileMat << "\n";
	}
      fileMat.close();
    }
  else
    {
      std::cout << "(saveMatrixScore char* flaot* int) Unable to open file";
    } 
}


/**********************************
 *
 * saveMatrixScore_transpose save 1 image, matrix transposition of the score
 * of float array
 * 
********************************/

void saveMatrixScore_transpose(char *fnameout, float *matDist, int sizeX, int sizeY)
{
  int i,j;
  std::ofstream fileMat (fnameout, std::ios::out);

  
  if(fileMat.is_open()  )
    {
      for(i =0; i < sizeX; i++)
	{
	  for(j = 0; j < sizeY; j++)
	    {
	      fileMat << matDist[j*sizeX + i] << " ";
	    }

	  fileMat << "\n";
	}
      fileMat.close();
    }
  else
    {
      std::cout << "(saveMatrixScore char* float* int int ) Unable to open file";
    }
}

/**********************************
 *
 * saveMatrixScore save 1 image, matrix of the score
 * of float array
 * 
********************************/

void saveMatrixScore(char *fnameout, float *matDist, int sizeX, int sizeY)
{
  int i,j;
  std::ofstream fileMat (fnameout, std::ios::out);

  
  if(fileMat.is_open()  )
    {

      for(j = 0; j < sizeY; j++)
	{
	  for(i =0; i < sizeX; i++)
	    {
	      fileMat << matDist[j*sizeX + i] << " ";
	    }
	  fileMat << "\n";
	}
      fileMat.close();
    }
  else
    {
      std::cout << "(saveMatrixScore char* float* int int ) Unable to open file";
    }
}


/**********************************
 *
 * saveMatrixScore save 1 image, 1 column of a matrix
 * of float 
 * 
********************************/

void saveMatrixScore_append(char *fnameout, float *matDist, int sizeQueries, int j)
{
  int i;
  std::ofstream fileMat (fnameout, std::ios::out | std::ofstream::app);

  
  if(fileMat.is_open()  )
    {
   
      for(i = 0; i < sizeQueries; i++)
	{
	  fileMat << matDist[j*sizeQueries + i] << " ";
	}
      fileMat << "\n";
	
      fileMat.close();
    }
  else
    {
      std::cout << "saveMatrixScore_append(char, float, int, int), with file : " << fnameout << ", unable to open file";
    }
}


/**********************************
 *
 * saveMatrixScore save 4 image, matrix of the score
 * of gx, gy, norm, arctan
 * 
********************************/

void saveMatrixScore(char *fnameout_gx, char *fnameout_gy, char *fnameout_norm, char *fnameout_arctan, float *matDistX, float *matDistY, float *matDistNorm, float *matDistArctan, int sizeMat)
{
  int i,j;
  std::ofstream fileMat_gx (fnameout_gx, std::ios::out);
  std::ofstream fileMat_gy (fnameout_gy, std::ios::out);
  std::ofstream fileMat_norm (fnameout_norm, std::ios::out);
  std::ofstream fileMat_arctan (fnameout_arctan, std::ios::out);
  
  if(fileMat_gx.is_open() && fileMat_gy.is_open() && fileMat_norm.is_open() && fileMat_arctan.is_open() )
    {
      for(j = 0; j < sizeMat; j++)
	{
	  for(i =0; i < sizeMat; i++)
	    {
	      fileMat_gx << matDistX[j*sizeMat + i] << " ";
	      fileMat_gy << matDistY[j*sizeMat + i] << " ";
	      fileMat_norm << matDistNorm[j*sizeMat + i] << " ";
	      fileMat_arctan << matDistArctan[j*sizeMat + i] << " ";
	    }
	  fileMat_gx << "\n";
	  fileMat_gy << "\n";
	  fileMat_norm << "\n";
	  fileMat_arctan << "\n";
	}
      fileMat_gx.close();
      fileMat_gy.close();
      fileMat_norm.close();
      fileMat_arctan.close();
    }
  else
    {
      std::cout << "(saveImageAsciiScore) Unable to open file";
    }
}



