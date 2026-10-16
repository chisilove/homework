#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class String {
protected:
    char* str;
    size_t len;

public:
    String() : len(0) {
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* s) {
        if (s) {
            len = strlen(s);
            str = new char[len + 1];
            strcpy(str, s);
        } else {
            len = 0;
            str = new char[1];
            str[0] = '\0';
        }
    }

    String(const String& other) : len(other.len) {
        str = new char[len + 1];
        strcpy(str, other.str);
    }

    String& operator=(const String& other) {
        if (this != &other) { 
            delete[] str;
            len = other.len;
            str = new char[len + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    size_t getLength() const {
        return len;
    }

    void clear() {
        delete[] str;
        len = 0;
        str = new char[1];
        str[0] = '\0';
    }

    virtual ~String() {
        delete[] str;
    }

    String& operator+=(const String& other) {
        size_t newLen = len + other.len;
        char* newStr = new char[newLen + 1];
        
        strcpy(newStr, str);
        strcat(newStr, other.str);
        
        delete[] str;
        str = newStr;
        len = newLen;
        return *this;
    }

    String operator+(const String& other) const {
        String result(*this);
        result += other;
        return result;
    }

    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    const char* c_str() const {
        return str;
    }
};

class BitString : public String {
private:
    bool isValid(const char* s) const {
        if (!s || s[0] == '\0') return false;
        for (size_t i = 0; s[i] != '\0'; ++i) {
            if (s[i] != '0' && s[i] != '1') {
                return false;
            }
        }
        return true;
    }

    void padSignBit(size_t newLen) {
        if (len == 0 || len >= newLen) return;
        char signBit = str[0];
        char* newStr = new char[newLen + 1];
        size_t diff = newLen - len;

        for (size_t i = 0; i < diff; ++i) {
            newStr[i] = signBit;
        }
        strcpy(newStr + diff, str);

        delete[] str;
        str = newStr;
        len = newLen;
    }

public:
    BitString() : String() {}

    BitString(const char* s) : String(s) {
        if (!isValid(s)) {
            clear();
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        if (this != &other) {
            String::operator=(other); 
        }
        return *this;
    }

    ~BitString() override {}

    void changeSign() {
        if (len == 0) return;

        for (size_t i = 0; i < len; ++i) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }

        int carry = 1;
        for (int i = static_cast<int>(len) - 1; i >= 0 && carry > 0; --i) {
            int sum = (str[i] - '0') + carry;
            str[i] = (sum % 2) + '0';
            carry = sum / 2;
        }
    }

    BitString operator+(const BitString& other) const {
        if (len == 0) return other;
        if (other.len == 0) return *this;

        BitString a(*this);
        BitString b(other);

        size_t maxLen = max(a.len, b.len);
        a.padSignBit(maxLen);
        b.padSignBit(maxLen);

        char* resStr = new char[maxLen + 1];
        resStr[maxLen] = '\0';

        int carry = 0;
        for (int i = static_cast<int>(maxLen) - 1; i >= 0; --i) {
            int bitA = a.str[i] - '0';
            int bitB = b.str[i] - '0';
            int sum = bitA + bitB + carry;
            resStr[i] = (sum % 2) + '0';
            carry = sum / 2;
        }

        BitString result(resStr);
        delete[] resStr;
        return result;
    }

    BitString& operator+=(const BitString& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const BitString& other) const {
        if (len == 0 && other.len == 0) return true;
        if (len == 0 || other.len == 0) return false;

        BitString a(*this);
        BitString b(other);
        size_t maxLen = max(a.len, b.len);
        a.padSignBit(maxLen);
        b.padSignBit(maxLen);

        return strcmp(a.str, b.str) == 0;
    }

    bool operator!=(const BitString& other) const {
        return !(*this == other);
    }
};


int main() {

    cout << "тестування класу String\n";
    String s1("привіт, ");
    String s2("світ");
    String s3 = s1 + s2;
    cout << "результат конкатенації: " << s3.c_str() << " (довжина: " << s3.getLength() << ")\n\n";

    cout << "тестування класу BitString\n";
    BitString bad("010201");
    cout << "некооректний бітовий рядок ('010201') після створення має довжину: " << bad.getLength() << "\n";

    BitString num1("00000101");
    BitString num2("00000011");

    cout << "число 1 (+5): " << num1.c_str() << "\n";
    cout << "число 2 (+3): " << num2.c_str() << "\n";

    BitString sum1 = num1 + num2;
    cout << "сума (5 + 3 = 8): " << sum1.c_str() << "\n\n";

    num2.changeSign();
    cout << "число 2 після зміни знаку (-3 у додатковому коді): " << num2.c_str() << "\n";

    BitString sum2 = num1 + num2;
    cout << "сума (5 + (-3) = 2): " << sum2.c_str() << "\n";

    return 0;
}