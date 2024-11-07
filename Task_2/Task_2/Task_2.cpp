#include <iostream>
#include <string>
#include <windows.h>
#include <cmath>

int real_string_hash(std::string s,int&p, int& n) {
    long long int sum = 0;
    long long int i = 0;
    for ( char ch : s) {
        sum += ch* static_cast<int>(pow(p, i));
        i++;
    }
    sum = sum % n;
    return sum;
}

bool is_prime(int p) {
    if (p <= 1) {
        return false; 
    }
    for (int i = 2; i <= std::sqrt(p); ++i) {
        if (p % i == 0) {
            return false; 
        }
    }
    return true; 
}

void check_p(int& p) {
    if (is_prime(p)==false) {
       std::cout << "Число должно быть простым, например: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97" << "\n" << "Попробуйте снова: ";
       std::cin >> p;
       check_p(p);

    }
}

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    using namespace std;
    string word;
    cout << "Введите p: ";
    int p{};
    cin >> p;
    check_p(p);
    cout << "Введите n: ";
    int n{};
    cin >> n;
    do {
        
        cout << "Введите строку: ";
        cin >> word;
        long long int hash = real_string_hash(word,p,n);
        cout << "Хэш строки " << word << " = " << hash << endl;

    } while (word != "exit");
}
