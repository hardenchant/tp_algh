// Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с
// помощью динамического буфера.
#include <iostream>

using namespace std;

class stack {
    int* buffer;
    int max_size;
    int cur_size;

    void increase_buffer() {
        int* new_buffer = new int[max_size * 2];
        for (int i = 0; i < max_size; ++i) {
            new_buffer[i] = buffer[i];
        }
        max_size = max_size * 2;
        delete[] buffer;
        buffer = new_buffer;
    }

   public:
    stack() {
        buffer = new int[1];
        max_size = 1;
        cur_size = 0;
    }

    stack(const stack& obj) = delete;

    ~stack() { delete[] buffer; }

    void push(int el) {
        if (cur_size == max_size) {
            increase_buffer();
        }
        buffer[cur_size++] = el;
    }

    int pop() {
        if (cur_size > 0) {
            return buffer[--cur_size];
        } else {
            return -1;
        }
    }

    bool is_empty() const { return cur_size == 0; }
};

class queue {
    stack s1;  //сюда будем делать push
    stack s2;  // cюда pop, если пустые то перекидываем в другой
   public:
    queue() = default;
    queue(const queue& obj) = delete;
    void push(int el) { s1.push(el); }
    int pop() {
        if (s2.is_empty()) {
            while (!s1.is_empty()) {
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }
};

int main() {
    queue a;
    int n;
    cin >> n;
    bool error = false;
    for (int i = 0; i < n; ++i) {
        int command, value;
        cin >> command;
        cin >> value;
        if (command == 3) {
            a.push(value);
        } else {
            int temp = a.pop();
            if (temp != value) {
                error = true;
                break;
            }
        }
    }
    if (error) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}