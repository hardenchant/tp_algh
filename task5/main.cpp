// Пара слов называется стековой анаграммой, если одно слово можно получить из другого, проведя последовательность стековых операций с его буквами (взять очередную букву исходного слова и поместить ее в стек; взять букву из стека и добавить ее в конец выходного слова).
// Для заданной пары слов требуется определить, можно ли выполнить последовательность стековых операций, переводящую первое слово во второе. Все буквы в слове различные.

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class stack {
    char* buffer;
    int max_size;
    int cur_size;

    void increase_buffer()
    {
        char* new_buffer = new char[max_size * 2];
        for (int i = 0; i < max_size; ++i) {
            new_buffer[i] = buffer[i];
        }
        max_size = max_size * 2;
        char* temp_pointer = buffer;
        buffer = new_buffer;
        delete[] temp_pointer;
    }

public:
    stack()
    {
        buffer = new char[1];
        max_size = 1;
        cur_size = 0;
    }

    stack(const stack& obj) = delete;

    ~stack() { delete[] buffer; }

    void push(char el)
    {
        if (cur_size == max_size) {
            this->increase_buffer();
        }
        buffer[cur_size++] = el;
    }

    char pop()
    {
        assert(cur_size);
        return buffer[cur_size-- - 1];
    }

    char top()
    {
        assert(cur_size > 0);
        return buffer[cur_size - 1];
    }

    bool is_empty() const { return !(bool)cur_size; }
};

bool stack_anagramm(const char* word1, const char* word2, size_t size1, size_t size2)
{
    if (size1 < size2)
        return false;
    stack s;
    //пытаемся провести последовательность стековых операций)))
    for (int i = 0, j = 0; i < size1; ++i) {
        s.push(word1[i]);
        for (; j < size2 && !s.is_empty(); ++j) {
            if (word2[j] == s.top()) {
                s.pop();
            } else {
                break;
            }
        }
        if (j >= size2) {
            return true;
        }
    }

    return false;
}

int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    if (stack_anagramm(word1.data(), word2.data(), word1.size(), word2.size())) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}