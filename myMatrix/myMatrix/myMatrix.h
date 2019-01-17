#pragma once
#define ORIDINARY_MATRIX 1
#define SPARSE_MATRIX 2
#include "mylist.h"
typedef int MatrixType;
template<class ElemType>
class MyMatrix
{
private:
	ElemType elem;
	int row, column;
	MyList< MyList<ElemType> > ptrMatrix;
public:
	MyMatrix(const int constRow, const int constColumn, MatrixType type = ORIDINARY_MATRIX)
	{
		if (type = ORIDINARY_MATRIX)
		{
			
		}
	}
};