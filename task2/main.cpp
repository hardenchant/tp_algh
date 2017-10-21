// Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k.
// Найти количество таких пар индексов (i, j), что A[i] + B[j] = k. Время работы
// O(n + m).
// n, m ≤ 100000.

#include <cassert>
#include <iostream>

using namespace std;

class array {
    int* data;
    size_t array_size;

   public:
    array(const array& other) = delete;
    array(size_t size) : array_size(size) { data = new int[size]; }
    int& operator[](size_t i) {
        assert(i < array_size);
        return data[i];
    }
    size_t size() { return array_size; }
    ~array() { delete[] data; }
};

int pair_searcher(array& a, array& b, int k) {
    int pair_counter = 0;
    int i = 0;
    int j = b.size() - 1;

    while (i < a.size() && j >= 0) {
        if (a[i] + b[j] == k) {
            ++pair_counter;
            ++i;
            --j;
        } else if (a[i] + b[j] < k) {
            ++i;
        } else if (a[i] + b[j] > k) {
            --j;
        }
    }
    return pair_counter;
}

int main() {
    int n = 0;
    cin >> n;

    array A(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int m = 0;
    cin >> m;

    array B(m);

    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    int k = 0;
    cin >> k;

    cout << pair_searcher(A, B, k) << endl;

    return 0;
}