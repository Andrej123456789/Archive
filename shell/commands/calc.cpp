#include <iostream>

using namespace std;

int main()
{
    char op;
    float a, b;
    
    cout << "Enter operator: ";
    scanf("%c", &op);

    cout << "Enter first number: ";
    scanf("%f", &a);

    cout << "Enter second number: ";
    scanf("%f", &b);

    switch (op)
    {
        case '+':
            cout << "Result is: " << a + b << ".\n";
            break;

        case '-':
            cout << "Result is: " << a - b << ".\n";
            break;

        case '*':
            cout << "Result is: " << a * b << ".\n";
            break;

        case '/':
            cout << "Result is: " << a / b << ".\n";
            break;
        
        default:
            cout << "Wrong operator " << op << "!\n";
            return 1;
            break;
    }

    return 0;
}