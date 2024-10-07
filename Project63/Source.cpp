#include <iostream>  
#include <cstring>  
using namespace std;

class MyString {
private:
    char* str;
    size_t length;

public:
    
    MyString() : str(nullptr), length(0) {}

   
    MyString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    
    ~MyString() {
        delete[] str;
    }

    
    void initFromInput() {
        char buffer[256];
        cout << "Введите строку: ";
        cin.getline(buffer, 256);
        delete[] str;
        length = strlen(buffer);
        str = new char[length + 1];
        strcpy(str, buffer);
    }

      
    char& operator[](size_t index) {
        if (index >= length) {
            throw std::out_of_range("Индекс вне допустимого диапазона");
        }
        return str[index];
    }

    
    MyString operator+(char ch) const {
        MyString newStr;
        newStr.length = length + 1;
        newStr.str = new char[newStr.length + 1];
        strcpy(newStr.str, str);
        newStr.str[length] = ch;
        newStr.str[newStr.length] = '\0';
        return newStr;
    }

  
    friend MyString operator+(char ch, const MyString& obj) {
        MyString newStr;
        newStr.length = obj.length + 1;
        newStr.str = new char[newStr.length + 1];
        newStr.str[0] = ch;
        strcpy(&newStr.str[1], obj.str);
        newStr.str[newStr.length] = '\0';
        return newStr;
    }

  
    MyString operator+(int count) const {
        MyString newStr;
        newStr.length = length + count;
        newStr.str = new char[newStr.length + 1];
        strcpy(newStr.str, str);
        for (int i = length; i < newStr.length; ++i) {
            newStr.str[i] = '*'; 
        }
        newStr.str[newStr.length] = '\0';
        return newStr;
    }

   
    friend MyString operator+(int count, const MyString& obj) {
        return obj + count;
    }

   
    MyString operator++(int) {
        MyString temp = *this;
        *this = *this + '*'; 
        return temp;
    }

 
    MyString operator++() {
        MyString temp = *this;
        *this = '*' + *this;  
        return temp;
    }

  
    void print() const {
        if (str != nullptr) {
            cout << str << endl;
        }
    }
};

int main() {
    MyString myStr("Hello");
    myStr.print();

    myStr = myStr + '!';
    myStr.print();

    myStr = 'A' + myStr;
    myStr.print();

    myStr = myStr + 10;
    myStr.print();

    myStr = 10 + myStr;
    myStr.print();

    myStr++;
    myStr.print();

    ++myStr;
    myStr.print();

    return 0;
}