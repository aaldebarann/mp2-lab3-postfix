#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
    string str;
    setlocale(LC_ALL, "Russian");

    cout << "Введите арифметическое выражение: ";
    cin >> str;
    cout << "Вы ввели: " << str << endl;
    ArithmeticExpression expression(str);

    cout << "Обратная польская запись: "<< expression.getPostfix() << endl;
    double res = expression.Calculate();
    cout << "Результат: "<< res << endl;

    return 0;
}
