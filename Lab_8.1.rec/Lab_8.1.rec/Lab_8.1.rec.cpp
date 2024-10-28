#include <iostream>
#include <cstring>

using namespace std;
/*
g+hi-j+k-l+
abc+-def
*/
bool findStr(char* str, int i) {
    if (str[i + 1] == '\0')
        return false;
    if (i > 0 && str[i - 1] == '+' && str[i + 1] == '-')
        return true;
    return findStr(str, i + 1);
}

char* Change(char* dest, const char* str, int i, int destIndex) {
    if (str[i] == '\0') {
        dest[destIndex] = '\0';
        return dest;
    }

    if (i > 0 && str[i - 1] == '+' && str[i + 1] == '-') {
        strcat_s(dest, 150 - destIndex, "****");
        return Change(dest, str, i + 2, destIndex + 4);
    }
    else {
        dest[destIndex] = str[i];
        dest[destIndex + 1] = '\0';
        return Change(dest, str, i + 1, destIndex + 1);
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    char* dest1 = new char[151];
    dest1[0] = '\0';

    char* dest2 = Change(dest1, str, 1, 0);

    findStr(str, 1)
        ? cout << "'+<char>-' pattern found and will be changed" << endl
        : cout << "'+<char>-' pattern not found" << endl;

    cout << "Original string (param): " << str << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}
