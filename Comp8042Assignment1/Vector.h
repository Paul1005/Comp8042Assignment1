#pragma once

#include <initializer_list>

template <class _T, class _Alloc = allocator<_T>>
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

	Vector(std::initializer_list<_T> initializer) {
		list = initializer;
	}

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