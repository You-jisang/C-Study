
#pragma once
#define SPARSEMATRIX_H

#include <iostream>

using namespace std;

class MatrixTerm;

class SparseMatrix
{
// objects: 3원소쌍<행, 열, 값>의집합이다. 여기서, 행과열은정수이고 이조합은유일하며, 값또한
//정수이다.
public:
   SparseMatrix();
   ~SparseMatrix();
   SparseMatrix(int r, int c, int t); //희소행렬표현
   void NewTerm(int r, int c, int v);
   SparseMatrix Transpose(); //전치

   int GetRow(int i);
   int GetCol(int i);
   int GetValue(int i);
   friend ostream& operator << (ostream& os, SparseMatrix& s);
private:
   int Rows, Cols, Terms, Capacity;
   MatrixTerm* smArray;
};


class MatrixTerm
{
   friend class SparseMatrix;
public:
   MatrixTerm();
   MatrixTerm(int r, int c , int t);
   ~MatrixTerm();


private:
   int row, col, value; // <행, 열, 값> 3원소 쌍
};
