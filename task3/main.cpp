// Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1]. Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k], ближайшего по значению к B[i]. Время работы поиска для каждого элемента B[i]: O(log(k)).
// n ≤ 110000, m ≤ 1000.

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
    friend std::ostream& operator <<(std::ostream &os, const wrapper &c){
        for(int i = 0; i < c.size; ++i){
            os << c.array[i] << " ";
        }
        return os;
    }
};

void near(wrapper& a, wrapper& b, wrapper& result){
    for(int i = 0; i < b.size; ++i){
        int left = 0, mid = 0, right = a.size - 1;
        //двоичный поиск
        while(right - left > 0) {
            mid = left + (right - left) / 2;
            if (b.array[i] <= a.array[mid]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        //двоичный поиск уедет или влево на один или вправо на один, или найдёт равный элемент
        //надо пофиксить это
        //можно было бы как то изменить алгоритм двоичного поиска, но так проще
        if (right - 1 >= 0 && abs(b.array[i] - a.array[right - 1]) <= abs(b.array[i] - a.array[right])) {
            result.array[i] = right - 1;
        }
        else if (right + 1 < a.size && abs(b.array[i] - a.array[right + 1]) < abs(b.array[i] - a.array[right])) {
            result.array[i] = right + 1;
        }
        else {
            result.array[i] = right;            
        }
    }
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
    int* RES = new int[m];
    *RES = {0};

    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    wrapper a(A, n), b(B, m), result(RES, m);
    near(a, b, result);

    cout << result << endl;

    delete[] A;
    delete[] B;
    delete[] RES;
    
    return 0;
}