#include <iostream>
#include <stack>
#define ull unsigned long long
using namespace std;

void printZeros(int total) {
    for (int i = 0; i < total; i++) {
        cout << 0;
    }
}

void printPattern(ull n) {
	stack<int> digits;

	while (n > 0) {
        int digit = n % 10;
        n /= 10;
        digits.push(digit);
    }

    while (!digits.empty()) {
        cout << digits.top();
        digits.pop();
        printZeros(digits.size());
        cout << endl;
    }
}

int main() {
	ull n;
	cin >> n;

	printPattern(n);
}
