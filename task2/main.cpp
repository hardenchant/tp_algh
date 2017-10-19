// Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k. Найти количество таких пар индексов (i, j), что A[i] + B[j] = k. Время работы O(n + m).
// n, m ≤ 100000.

#include <iostream>

using namespace std;

struct wrapper {
    int* array;
    int size;

    wrapper(const wrapper& other) = delete;
    wrapper(int* array, int size) : array(array), size(size) {}
    int operator[](size_t i){
        if (i >= size) {
            return 0;
        }
        return array[i];
    }
    ~wrapper(){
        array = nullptr;
        size = 0;
    }
};

int pair_searcher(wrapper& a, wrapper& b, int k){
    int pair_counter = 0;
    int i = 0;
    int j = b.size - 1;

    while (i < a.size && j >= 0) {
        if (a[i] + b[j] == k) {
            ++pair_counter;
            ++i;
            --j;
        }
        else if (a[i] + b[j] < k) {
            ++i;
        }
        else if (a[i] + b[j] > k) {
            --j;
        }
    }
    return pair_counter;
}

int main(){
    int n = 0;
    cin >> n;
    int* A = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    int m = 0;
    cin >> m;
    int* B = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    wrapper a(A, n), b(B, m);

    int k = 0;
    cin >> k;

    cout << pair_searcher(a, b, k) << endl;

    delete[] A;
    delete[] B;
    
    return 0;
}