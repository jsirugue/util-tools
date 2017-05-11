#ifndef _UTILTOOL_H_
#define _UTILTOOL_H_

#include <string>

#include "gradient.hpp"
#include "arrDeriv.hpp"
#include "secondDeriv.hpp"

int countLinesFile(char *fname);
int countLinesFile(std::string fname);
int countCharsLine(std::string fname);
int maxInt(int *tmax, int size);
int secondMaxInt(int *tmax, int size);
int countNbZeros(int *t, int size);
int countNbZeros_patch(int *t, int sizeX, int sizeY, int ideb, int jdeb, int sizep);
float maxFloat(float *tmax, int size);
float secondMaxFloat(float *tmax, int size);
float minFloat(float *tmin, int size);
float distMAD(float x, float y);
float distScoring(float x, float y);
void normalizeFloatArr(float *arrF, int size);
float meanPatch(int *X, int sizeX, int sizeY, int ideb, int jdeb, int sizeP);
void loadFiles_mapCvx(char **filenamesGrad, int **a, int *sizeX, int *sizeY, int sizei);
void loadFiles_mapCvx(char **filenamesGrad, float **ac, int *sizeX, int *sizeY, int sizei);
void readASCIIFile_courbElev(char *fname, float **courbElev, bool **maskCourbElev, int *sizeX,int *sizeY);
void loadFile_matrixScore(char *filenamesMatScore, float *matSc, int sizeX, int sizeY);
void saveImageAscii_grad(char *fnameout_gx, char *fnameout_gy, char *fnameout_gxgy, Gradient *gradImg, int sizeX, int sizeY);
void saveImageAscii_deriv(char *fnameout_deriv, Gradient *gradImg, SecondDeriv *sDeriv, int sizeX, int sizeY);
//void loadFile_grad(char *filenamesGrad, ArrGradient *ag);
void loadFile_deriv(char *filenamesDeriv, ArrDeriv *ad);
//void loadFiles_grad(char **filenamesGrad, ArrGradient *ag, int sizei);
void loadFiles_deriv(char **filenamesDeriv, ArrDeriv *ad, int sizei);
void saveMatrixScore(char *fnameout, float *matDist, int sizeMat);
void saveMatrixScore_transpose(char *fnameout, float *matDist, int sizeX, int sizeY);
void saveMatrixScore(char *fnameout, float *matDist, int sizeX, int sizeY);
void saveMatrixScore_append(char *fnameout, float *matDist, int sizeQueries, int j);
void saveMatrixScore(char *fnameout_gx, char *fnameout_gy, char *fnameout_norm, char *fnameout_arctan, float *matDistX, float *matDistY, float *matDistNorm, float *matDistArctan, int sizeMat);


#endif
