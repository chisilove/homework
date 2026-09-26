#include <iostream>
using namespace std;

class Complex
{
private:
    double real;       
    double fake; 

public:
    Complex(double r = 0, double f = 0){
        real = r;
        fake = f;
    }

    Complex operator+(Complex number){
        Complex result;

        result.real = real + number.real;
        result.fake = fake + number.fake;

        return result;
    }

    Complex operator-(Complex number){
        Complex result;

        result.real = real - number.real;
        result.fake = fake - number.fake;

        return result;
    }

    Complex operator*(Complex number){
        Complex result;

        result.real = real * number.real - fake * number.fake;
        result.fake = real * number.fake + fake * number.real;

        return result;
    }

    Complex operator/(Complex number){
        Complex result;

        double denominator = number.real * number.real + number.fake * number.fake;

        if (denominator == 0){
            cout << "помилка ділення на 0" << endl;
            return Complex(0, 0);
        }

        result.real = (real * number.real + fake * number.fake) / denominator;
        result.fake = (fake * number.real - real * number.fake) / denominator;

        return result;
    }

    void print(){
        if (fake >= 0){
            cout << real << " + " << fake << "f";
        }
        else{
            cout << real << " - " << -fake << "f";
        }
    }
};

int main()
{
    Complex number1(4, 2);
    Complex number2(2, 1);

    Complex sum = number1 + number2;
    Complex difference = number1 - number2;
    Complex product = number1 * number2;
    Complex quotient = number1 / number2;

    cout << "перше число: ";
    number1.print();
    cout << endl << "друге число: ";
    number2.print();
    cout << endl;
    cout << "сума: ";
    sum.print();
    cout << endl << "різниця: ";
    difference.print();
    cout << endl << "лобуток: ";
    product.print();
    cout << endl << "частка: ";
    quotient.print();
    cout << endl;

    return 0;
}