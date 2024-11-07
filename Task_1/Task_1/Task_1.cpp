#include <iostream>
#include <string>
#include <windows.h>

int simple_string_hash(std::string s) {
    int sum = 0;

    for (char ch : s) {
        sum += ch;
    }
    return sum;
}



int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    using namespace std;
    string word;
    do {    
        
        cout << "Введите строку: ";
        cin >> word;
        int hash= simple_string_hash(word);
        cout << "Наивный хэш строки "<< word<< " = "<<hash<<endl;
       
    } while (word != "exit");
}
