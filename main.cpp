#include <iostream>
#include <vector>
#include <string>
#include "pointT.hpp"
#include "rectangle.hpp"

// fonction max avec template
template<typename T>
T max(const T& a, const T& b);

template<> std::string max(const std::string& a, const std::string& b);

template<typename T>
T moy(const std::vector<T>& vect);

int main() {
    int a(1), b(2);
    std::cout << "max : " << max<int>(a, b) << std::endl;
    return 0;
}

template<typename T>
T max(const T& a, const T& b) {
    if(a > b) {
        return a;
    }
    else {
        return b;
    }
}

template<typename T>
T moy(const std::vector<T>& vect) {
    T somme = 0;
    for(T v : vect) {
        somme += v;
    }
    return somme / vect.size();
}

// on spécialise la fonction max de tout à l'heure
template<> std::string max(const std::string& a, const std::string& b) {
    if(a.size() > b.size()) {
        return a;
    }
    else {
        return b;
    }
}