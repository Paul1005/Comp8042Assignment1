#pragma once

#include <initializer_list>

template <class _T>
class Vector
{
private:
	size_t N;
	size_t C;
	_T* list;
	typedef _T* iterator;

public:
	Vector() {
		C = 10;
		N = 0;
		list = new _T[C];
	}

	Vector(std::initializer_list<_T> initializer) {
		C = initializer.size();
		N = C;
		list = new _T[C];
		int count = 0;
		for (auto& element : initializer) {
			list[count] = element;
			++count;
		}
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

	iterator begin() {
		return &list[0];
	}

	iterator end() { 
		return &list[N-1];
	}

	size_t size() {
		return N;
	}

	_T erase(int i) {
		for (int j = i; j < N; j++) {
			list[j] = list[j + 1];
		}
		N = N - 1;

		return i;
	}

	void resize(int newN) {
		N = newN;
		if (N == C) {
			C *= 2;
		}
		_T* temp = new _T[C];
		for (int i = 0; i < N; i++) {
			temp[i] = list[i];
		}
		delete[] list;

		list = temp;
	}
};