#include <iostream>

using namespace std;

int n;
void print(int* s);
int* lastNode(int s, int *c);
int eval(int i, int k, int *c, int *t);

int main() {
	cin >> n;

	int *c = new int[2 * n]; // saving each node childs in two index like 1:{6,5}, 2:{0,0}...6:{4,0}
	fill_n(c, 2 * n, 0);

	int q = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> q;
		if (c[(q - 1) * 2 + 1]) {
			c[(q - 1) * 2] = i + 2;
		} else {
			c[(q - 1) * 2 + 1] = i + 2;
		}
	}

	int *t = new int[n];
	fill_n(t, n + 1, 0);

	t[0] = 1;
	eval(0, 0, c, t);

	print(t);

	int p;
	for (int i = 0; i < n; i++) {
		p = lastNode(i, c)[0] + 1;

		int start = 0, end = 0;
		for (int k = 0; k < n; k++) {
			if (t[k] == i + 1) {
				start = k + 1;
			} 
			if (t[k] == p) {
				end = k + 1;
				break;
			}
		}
		cout << i + 1 << ": " << start << " " << end << endl;
	}
	cin.get();
	cin.ignore();
	return 0;
}

int* lastNode(int s, int *c) {

	int ln[2] = { s,1 };
	if (!c[2 * s + 1]) return ln;

	int k = 0; // key
	int d = 1; // depth

	int rk, rd, lk, ld;

	int *w = lastNode(c[2 * s + 1] - 1, c);
	rk = w[0];
	rd = w[1];

	if (c[2 * s]) {
		w = lastNode(c[2 * s] - 1, c);
		lk = w[0];
		ld = w[1];
		k = rd >= ld ? rk : lk;
		d += rd + ld;
	} else {
		k = rk;
		d += rd;
	}

	ln[0] = k;
	ln[1] = d;

	return ln;
}

int eval(int i, int k, int *c, int *t) {

	if (i >= n) return 0;

	int lc = 0; // number of sub tree nodes

	if (c[2 * k]) {
		t[i + 1] = c[k];
		lc = eval(i + 1, c[2 * k] - 1, c, t);
	}

	if (c[2 * k + 1]) {
		i += lc;
		t[i + 1] = c[2 * k + 1];
		lc += eval(i + 1, c[2 * k + 1] - 1, c, t);
	} else {
		t[i] = k + 1;
	}

	return lc + 1;
}

void print(int* s) {
	for (int i = 0; s[i]; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}