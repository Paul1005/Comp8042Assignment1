#include <iostream>
//#include <vector>
#include <string>
#include <queue>
//#include <strings.h>
#include "Rectangle.h"
#include "Matrix.h"
#include "Josephus.h"

ostream& operator << (ostream& s, Rectangle r)
{
	s << "Rectangle: " << r.GetLength() << "x" << r.GetWidth();
	return s;
}

template <typename T>
ostream& operator << (ostream& s, matrix<T>m)
{
	int rows = m.numrows();
	int cols = m.numcols();
	for (int i = 0; i < rows; i++)
	{
		Vector<int> row = m[i];
		for (int j = 0; j < cols; j++)
			s << row[j] << " ";
		s << endl;
	}
	return s;
}

int main()
{
	Vector<Rectangle> recVec
	{
		Rectangle(1, 3),
		Rectangle(4, 4),
		Rectangle(4, 2),
		Rectangle(7, 2),
		Rectangle(1, 2),
		Rectangle(2, 2),
		Rectangle(6, 2)
	};


	cout << "***** Q1: Rectangle class" << endl;
	//for (Rectangle r : recVec)
	for (int i = 0; i < recVec.size(); i++)
		//cout << r << endl;
		cout << recVec[i] << endl;
	cout << endl;

	cout << "Highest Area: " << FindMaxByArea(recVec) << endl;
	cout << "Highest Perimeter: " << FindMaxByPerim(recVec) << endl << endl;


	cout << endl << endl << "***** Q2: matrix class" << endl;
	matrix<int> mat = matrix<int>();
	cout << "Zero-parameter matrix (rows,cols) = (" << mat.numrows() << "," << mat.numcols() << ")" << endl;

	mat.resize(4, 3);
	cout << "Resized matrix to 4x3" << endl;
	cout << mat << endl;
	mat[2][1] = 12;
	cout << "Modified (2,1)" << endl;
	cout << mat << endl;

	cout << endl << endl << "***** Q3: Josephus problem" << endl;
	cout << "Elimination order (0, 5): ";
	int winner = Josephus(0, 5);
	cout << "+++WINNER: " << winner << endl;
	cout << "Elimination order (1, 5): ";
	winner = Josephus(1, 5);
	cout << "+++WINNER: " << winner << endl;
	cout << "Elimination order (3, 7): ";
	winner = Josephus(3, 7);
	cout << "+++WINNER: " << winner << endl;

	return 0;
}
