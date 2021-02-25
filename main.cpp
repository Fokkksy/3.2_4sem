#include <iostream>
#include <random>
#include <vector>
#include <set>

std::size_t hash_func(double n){
    int a = static_cast<int>(n) + 1;
    n = static_cast<double>(a) - n;

    auto hash_code = std::size_t(static_cast<int>((n * n - n) * 2008033) % 100);
    return hash_code;
}


int main(){
    std::default_random_engine dre;
    std::uniform_real_distribution<double> myrandom(0, 100);

    std::vector<std::size_t> v(100);
    std::vector<double> v1(100);

    for (auto i = 0; i < 100; ++i){
        v1[i] = myrandom(dre);
    }

    for (auto i = 0; i < 100; ++i){
        v[i] = hash_func(v1[i]);
    }

    std::set<std::size_t> set;
    int collisions;

    for (auto N = 10; N <= 100; N += 10){
        for (auto i = 0; i < N; ++i){
            set.insert(v[i]);
        }
        collisions = N - std::size(set);
        std::cout << "If there  are " << N << " elements in vector, then there are " << collisions << " collisions " << std::endl;
        set.clear();

    }

    return 0;
}