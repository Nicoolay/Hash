#include <iostream>
#include <string>
#include <windows.h>
#include <cmath>

int string_hash(const std::string& str) {
    int p = 3;       // Константа для хэширования
    int n = 101;     // Модуль, чтобы избежать переполнения
    int hash_value = 0;

    for (size_t i = 0; i < str.size(); ++i) {
        hash_value += str[i] * static_cast<int>(std::pow(p, i));
    }
    return hash_value % n;
}

int find_substring_light_rabin_karp(const std::string& source, const std::string& substring) {
    int p = 3;
    int n = 101;

    int subs_hash = string_hash(substring);// вычисляем хэш от подстроки
    size_t k = substring.size();  // Длина подстроки
    int current_hash{};//текущий хэш

    for (size_t i = 0; i <= source.size() - k; ++i) {
        if (i == 0) {
            current_hash = string_hash(source.substr(0, k));  // Хэш начального окна

     }       
        
        else {
            // Удаляем символ, выходящий из окна
            current_hash -= source[i - 1];
          current_hash /= p;
            // Добавляем новый символ в окно
            current_hash += source[i + k - 1] * static_cast<int>(pow(p, k - 1));
           current_hash = current_hash % n;
          
         
        }
        bool match = true;
        if (current_hash != subs_hash) {
            continue;
        }
                  
      
         
            for (size_t j = 0; j < k; ++j) {
                if (source[i+j] != substring[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;  // Подстрока найдена на позиции i
            }
    }

    return -1;  
}

int main(int argc, char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    using namespace std;

    string source;
    string substring;
    cout << "Введите строку, в которой будет осуществляться поиск: ";
    cin >> source;

    do {
        cout << "Введите подстроку, которую нужно найти: ";
        cin >> substring;

        int match_index = find_substring_light_rabin_karp(source, substring);

        if (match_index != -1) {
            cout << "Подстрока " << substring << " найдена по индексу: " << match_index << endl;
        }
        else {
            cout << "Подстрока " << substring << " не найдена." << endl;
        }

    } while (substring != "exit");

    return 0;
}
