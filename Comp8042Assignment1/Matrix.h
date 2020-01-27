#pragma once

//#include <vector>
#include "Vector.h"

using namespace std;

template <typename Object>
class matrix
{

public:
	matrix(int rows, int cols) : array{ rows } {
		for (auto& thisRow : array)
			thisRow.resize(cols);
	}

	matrix(initializer_list<Vector<Object>> lst) : array(lst.size())
	{
		int i = 0;
		for (auto& v : lst)
			array[i++] = std::move(v);
	}

	matrix(const Vector<Vector<Object>>& v) : array{ v } {}
	matrix(Vector<Vector<Object>>&& v) : array{ std::move(v) } {}

	// *** Provide zero-parameter constructor here
	matrix() {

	}

	const Vector<Object>& operator[](int row) const
	{
		return array[row];
	}

	Vector<Object>& operator[](int row)
	{
		return array[row];
	}

	int numrows() const
	{
		Vector<Vector<Object>> temp = array;
		return temp.size();
	}

	int numcols() const
	{
		Vector<Object> temp = array[0];
		return numrows() ? temp.size() : 0;
	}

	// *** Provide resize method here
	void resize(int rows, int cols) {
		array.resize(rows);
		for (int i = 0; i < array.size(); i++)
			//for (auto& thisRow : array)
				//thisRow.resize(cols);
			array[i].resize(cols);
	}

private:
	Vector<Vector<Object>> array;

};
