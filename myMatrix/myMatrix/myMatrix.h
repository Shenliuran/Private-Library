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
	ElemType **ptrMatrix;
public:
	MyMatrix(const int constRow, const int constColumn, MatrixType type = ORIDINARY_MATRIX)
	{
		ptrMatrix = nullptr;
		row = constRow;
		column = constColumn;
		if (type == ORIDINARY_MATRIX)
		{
			ptrMatrix = (ElemType**) new (ElemType*)[row];
			for (int i = 0; i < column; i++)
				ptrMatrix[i] = (ElemType*) new (ElemType)[column];
		}
		else
		{
			MyList<
		}
	}
};