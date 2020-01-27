#include <iostream>
#include "Vector.h"

using namespace std;
/*template <class _Ty, class _Alloc = allocator<_Ty>>
class vector { // varying size array of values
public:

	void push_back(const _Ty& _Val) { // insert element at end, provide strong guarantee
		emplace_back(_Val);
	}

	iterator begin() noexcept { // return iterator for beginning of mutable sequence
		auto& _My_data = _Mypair._Myval2;
		return iterator(_My_data._Myfirst, _STD addressof(_My_data));
	}

	size_t size() const noexcept { // return length of sequence
		auto& _My_data = _Mypair._Myval2;
		return static_cast<size_type>(_My_data._Mylast - _My_data._Myfirst);
	}

	iterator end() noexcept { // return iterator for end of mutable sequence
		auto& _My_data = _Mypair._Myval2;
		return iterator(_My_data._Mylast, _STD addressof(_My_data));
	}

	iterator erase(const_iterator _Where) { // erase element at _Where
		const pointer _Whereptr = _Where._Ptr;
		auto& _My_data          = _Mypair._Myval2;
		pointer& _Mylast        = _My_data._Mylast;

		#if _ITERATOR_DEBUG_LEVEL == 2
		_STL_VERIFY(
			_Where._Getcont() == _STD addressof(_My_data) && _Whereptr >= _My_data._Myfirst && _Mylast > _Whereptr,
			"vector erase iterator outside range");
		_Orphan_range(_Whereptr, _Mylast);
		#endif // _ITERATOR_DEBUG_LEVEL == 2

		_Move_unchecked(_Whereptr + 1, _Mylast, _Whereptr);
		_Alty_traits::destroy(_Getal(), _Unfancy(_Mylast - 1));
		--_Mylast;
		return iterator(_Whereptr, _STD addressof(_My_data));
	}

	_Ty& front() {
		auto& _My_data = _Mypair._Myval2;
		#if _CONTAINER_DEBUG_LEVEL > 0
		_STL_VERIFY(_My_data._Myfirst != _My_data._Mylast, "front() called on empty vector");
		#endif // _CONTAINER_DEBUG_LEVEL > 0

		return *_My_data._Myfirst;
	}
};
*/

// The Josephus problem is the following game:
//  N people, numbered 1 to N, are sitting in a circle.
//  Starting at person 1, a hot potato is passed.
//  After M passes, the person holding the hot potato is eliminated,
//      the circle closes ranks, and the game continues
//      with the person who was sitting after the eliminated person
//      picking up the hot potato.
//  The last remaining person wins.
//  Thus, if M = 0 and N = 5, players are eliminated in order, and player 5 wins.
//      If M = 1 and N = 5, the order of elimination is 2, 4, 1, 5.
// m is number of people
// n is number of passes before elimination
int Josephus(int m, int n)
{
	// Hint for making the algorithm efficient: think carefully how to determine next player to eliminate
	int winner = -1;
	Vector<int> people;
	for (int i = 1; i <= n; i++) {
		people.push_back(i);
	}

	auto currentPerson = 0;
	while (people.size() > 1) {
		for (int i = 0; i < m; i++) {
			currentPerson++;
			if (currentPerson == people.size() - 1) {
				currentPerson = 0;
			}
		}
		cout << people[currentPerson] << ", ";
		currentPerson = people.erase(currentPerson);
		if (currentPerson == people.size() - 1) {
			currentPerson = 0;
		}
	}
	cout << endl;
	winner = people.begin();
	// Be sure to use cout to print out each player as they are eliminated
	return winner;
}
