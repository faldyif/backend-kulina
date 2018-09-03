#include <iostream>
#include <cmath>
using namespace std;

bool dpPrime[100005];

void printPrimesFromOneTo(int limit) {
	string primes = "";
	for (int i = 1; i <= limit; i++) {
		if (!dpPrime[i]) primes += to_string(i) + " ";
	}

	// Remove last character from string if has result
	if (primes.length() > 0) primes = primes.substr(0, primes.size() - 1);
	cout << primes << endl;
}

void initPrime(int limit) {
	int lastPrime = 2;

	// 1 is not prime
	dpPrime[1] = true;

	while (lastPrime <= limit) {
		for (int multipler = 2; lastPrime * multipler <= limit; multipler++) {
			dpPrime[lastPrime * multipler] = true;
		}

		for (int i = lastPrime + 1; i <= limit + 1; i++) {
			if (!dpPrime[i]) {
				lastPrime = i;
				break;
			} else if (i == limit + 1) {
				lastPrime = i;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	initPrime(n);
	printPrimesFromOneTo(n);
}
