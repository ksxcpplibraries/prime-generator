
#include <iostream>
#include <vector>
#include <cstdlib>
#include "prime.hxx"

namespace __ {
	
	using namespace std;
	using namespace prime;
	
	int main(int argc, char **argv) {
		
		struct Condition {
			unsigned nmax;
			inline bool operator()(unsigned n) {
				return n <= nmax;
			}
		} condition;
		
		auto &nmax = condition.nmax;
		
		if (argc > 1) {
			nmax = atoi(argv[1]);
		} else {
			reask:
			cout << "Enter nmax: ";
			if (!(cin >> nmax)) {
				cout << "Invalid input!\n";
				goto reask;
			}
		}
		
		if (nmax > 1u) {
			cout << 2u << endl;
		} else {
			cout << "There's no prime less than 2.\n";
			return 0;
		}
		
		for (auto n : PrimeGen<vector, unsigned, Condition>(condition)) {
			cout << n << endl;
		}
		
		return 0;
		
	}
	
}

int main(int argc, char **argv) {
	return __::main(argc, argv);
}

