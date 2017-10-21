// Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых
// чисел B[0..m-1]. Для каждого элемента массива B[i] найдите минимальный индекс
// элемента массива A[k], ближайшего по значению к B[i]. Время работы поиска для
// каждого элемента B[i]: O(log(k)).
// n ≤ 110000, m ≤ 1000.

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
    friend std::ostream& operator<<(std::ostream& os, const array& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            os << arr[i] << " ";
        }
        return os;
    }
};

void near(array& a, array& b, array& result) {
    for (int i = 0; i < b.size(); ++i) {
        int left = 1, mid = 0, right = a.size() - 1;

        while (left < right) {
            if (b[i] < left) {
                left /= 2;
                break;
            }
            left *= 2;
        }
        //двоичный поиск
        while (right - left > 0) {
            mid = left + (right - left) / 2;
            if (b[i] <= a[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        //двоичный поиск уедет или влево на один или вправо на один, или найдёт
        //равный элемент
        //надо пофиксить это
        //можно было бы как то изменить алгоритм двоичного поиска, но так проще
        if (right - 1 >= 0 &&
            abs(b[i] - a[right - 1]) <= abs(b[i] - a[right])) {
            result[i] = right - 1;
        } else if (right + 1 < a.size() &&
                   abs(b[i] - a[right + 1]) < abs(b[i] - a[right])) {
            result[i] = right + 1;
        } else {
            result[i] = right;
        }
    }
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
    array B(m), RES(m);

    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    near(A, B, RES);

    cout << result << endl;

    return 0;
}