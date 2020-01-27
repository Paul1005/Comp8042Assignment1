#pragma once

#include <initializer_list>

template <class _T>
class Vector
{
private:
	size_t N;
	size_t C;
	_T* list;

public:
	Vector() {
		C = 10;
		N = 0;
		list = new _T[C];
	}

	Vector(_T thing1, _T thing2, _T thing3, _T thing4, _T thing5, _T thing6, _T thing7) {
		C = 7;
		N = 0;
		list = new _T[C];
		list[0] = thing1;
		list[1] = thing2;
		list[2] = thing3;
		list[3] = thing4;
		list[4] = thing5;
		list[5] = thing6;
		list[6] = thing7;
	}

	Vector(const _T& v) : list{ v } {}
	Vector(_T&& v) : list{ std::move(v) } {}

	void push_back(_T x) {
		if (N == C) {
			C *= 2;
			_T* temp = new _T[C];
			for (int i = 0; i < N; i++) {
				temp[i] = list[i];
			}
			delete[] list;

			list = temp;
		}
		list[N] = x;
		N = N + 1;
	}

	_T& operator[](int i) {
		return list[i];
	}

	const _T& operator[](int i) const {
		return list[i];
	}

	_T begin() {
		return list[0];
	}

	size_t size() {
		return N;
	}

	_T end() {
		return list[N - 1];
	}

	_T erase(int i) {
		for (int j = i; j < N; j++) {
			list[j] = list[j + 1];
		}
		N = N - 1;

		return i;
	}

	void resize(int newC) {
		C = newC;
		_T* temp = new _T[C];
		if (N >= C) {
			N = C - 1;
		}
		for (int i = 0; i < N; i++) {
			temp[i] = list[i];
		}
		delete[] list;

		list = temp;
	}
};