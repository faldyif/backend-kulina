#include <iostream>
#define ull unsigned long long
using namespace std;

ull dpFibo[100005];

void printFiboFromOneTo(int limit) {
	string fibos = "";
	for (int i = 1; i <= limit; i++) {
		fibos += to_string(dpFibo[i]) + " ";
	}

	// Remove last character from string if has result
	if (fibos.length() > 0) fibos = fibos.substr(0, fibos.size() - 1);
	cout << fibos << endl;
}

void initFibo(int limit) {
    dpFibo[1] = 1;
    dpFibo[2] = 1;

    for (int i = 3; i <= limit; i++) {
        dpFibo[i] = dpFibo[i-2] + dpFibo[i-1];
    }
}

int main() {
	int n;
	cin >> n;

	initFibo(n);
	printFiboFromOneTo(n);

}
