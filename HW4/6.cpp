#include <iostream>

using namespace std;

int n;
int max(int *s); 
void print(int* s);
void maxHeap(int i, int *s, int *t);

int main() {
	cin >> n;
	int *s = new int[n];
	int *t = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	maxHeap(0, s, t);

	print(t);

	cin.get();
	cin.ignore();
	return 0;
}

void maxHeap(int i, int *s,int *t) { // O(logn)
	if (i >= n) return;

	t[i] = max(s); // O(n)

	maxHeap(2 * i + 1, s, t);
	maxHeap(2 * i + 2, s, t);
}// => O(n)

int max(int *s) {
	int max = -1;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 0) continue;
		if (s[i] > max) {
			max = s[i];
			k = i;
		}
	}
	s[k] = 0;
	return max;
}

void print(int* s) {
	for (int i = 0; i < n; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}