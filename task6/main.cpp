// Дано N кубиков. Требуется определить каким количеством способов можно
// выстроить из этих кубиков пирамиду.
// Каждый вышележащий слой пирамиды должен быть строго меньше нижележащего.
#include <iostream>
#include <vector>

using namespace std;

bool check_combination(vector<unsigned> combination)
{
    if (combination.size() == 1)
        return true;
    for (int i = 1; i < combination.size(); ++i) {
        if (combination[i] >= combination[i - 1]) {
            return false;
        }
    }
    return true;
}

int pyramid_count(int n)
{
    int pyr_count = 1;
    vector<vector<unsigned>> combinations;
    combinations.push_back({1});
    for(int i = 1; i < n; ++i){
        for(auto &el:combinations){
            el[0]++;
        }
        vector<unsigned> comb;
        
        comb.push_back((n / 2) + 1);

    }    
    return pyr_count;
}

int main() { 
    pyramid_count(2);
    return 0;
}