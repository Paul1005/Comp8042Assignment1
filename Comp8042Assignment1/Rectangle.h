#pragma once

#include "Vector.h"

using namespace std;

// Define the Rectangle class here
class Rectangle {
private:
	int length;
	int width;
public:
	Rectangle(int l, int w) {
		length = l;
		width = w;
	}
	int GetLength() {
		return length;
	}

	int GetWidth() {
		return width;
	}

	Rectangle() {

	}
};

// Define the AreaCompare and PerimeterCompare functions here
bool AreaCompare(Rectangle rectangle1, Rectangle rectangle2) {
	if (rectangle1.GetLength() * rectangle1.GetWidth() < rectangle2.GetLength() * rectangle2.GetWidth()) {
		return true;
	}
	else  {
		return false;
	}
}

bool PerimeterCompare(Rectangle rectangle1, Rectangle rectangle2) {
	if (rectangle1.GetLength() * 2 + rectangle1.GetWidth() * 2 < rectangle2.GetLength() * 2 + rectangle2.GetWidth() * 2) {
		return true;
	}
	else {
		return false;
	}
}

template <typename Object, typename Comparator>
const Object& findMax(const Vector<Object>& arr, Comparator isLessThan)
{
	int maxIndex = 0;
	Vector<Object>& temp = arr;
	for (int i = 1; i < temp.size(); ++i)
		if (isLessThan(arr[maxIndex], arr[i]))
			maxIndex = i;

	return arr[maxIndex];
}

// Define the FindMaxByArea() and FindMaxByPerim() functions here

const Rectangle FindMaxByArea(Vector<Rectangle> recVec) {
	return findMax(recVec, AreaCompare);
}

const Rectangle FindMaxByPerim(Vector<Rectangle> recVec) {
	return findMax(recVec, PerimeterCompare);
}