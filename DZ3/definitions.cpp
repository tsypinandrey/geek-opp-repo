#include <iostream>
#include "prototype.h"

Paralelogram::Paralelogram(){ // конструктор по умолчанию
    hight = 0; width = 0;
}

Paralelogram::Paralelogram(float a, float b): // конструктор с переметрами для инициализации переменный
    hight(a), width(b){}

void Paralelogram::getParalelogram(float a, float b){ // изменение параметров Паралелограмма
    hight = a; width = b;
}

void Paralelogram::printfigure(){ // вывод на экран параметров Параллерограмма
    cout << "Параллерограмм -> высота - " << hight << ", " << "ширина - " << width << endl;
}

void Paralelogram::area(){ // вывод на экран площади Параллерограмма
    cout << "Площадь параллелограмма = " << hight * width << endl;
}

Circle::Circle(){ // конструктор по умолчанию
    radius = 0;
}

Circle::Circle(float a): radius(a){} // конструктор с переметрами для инициализации переменных

void Circle::printfigure(){ // вывод на экран параметров круга
    cout << "Круг -> радиус - " << radius << endl;
}

void Circle::area(){ // вывод на экран площади круга
    cout << "Площядь круга = " << 3.14 * radius * radius << endl;
}

void Circle::getCircle(float a){ // изменение радиуса круга
     radius = a;
}

Rectangle::Rectangle(){ // конструктор по умолчанию
    hight = 0; width = 0;
}

Rectangle::Rectangle(float a, float b): // конструктор с переметрами для инициализации переменных
    Paralelogram(a,b){}

void Rectangle::printfigure(){ // вывод на экран параметров Прямоугольник
    cout << "Прямоугольник -> длина - " << hight << ", " << "ширина - " << width << endl;
}
void Rectangle::area(){  // вывод на экран площади Прямоугольника
    cout << "Площадь прямоугольника = " << hight * width << endl;
}

Square::Square(){ // конструктор по умолчанию
    hight = 0; width = 0;
}

Square::Square(float a):  // конструктор с переметрами для инициализации переменных
    Paralelogram(a, a){}

void Square::printfigure() { // вывод на экран параметров Квадрата
    cout << "Квадрат -> cторона квадрата = " << hight << endl;
}

void Square::area(){ // вывод на экран площади Квадрат
    cout << "Площадь квадрата = " << hight * width << endl;
}

Rhombus::Rhombus(){ // конструктор по умолчанию
    hight = 0; width = 0;
}

Rhombus::Rhombus(float a, float b):  // конструктор с переметрами для инициализации переменных
    Paralelogram(a,b){}

void Rhombus::printfigure() { // вывод на экран параметров Ромба
    cout << "Ромб -> высота - " << hight << ", " << "ширина - " << width << endl;
}
void Rhombus::area(){ // вывод на экран площади Ромба
    cout << "Площадь ромба = " << hight * width / 2 << endl;
}

//*********************************************

Fraction::Fraction() { // конструктор по умолчанию
    this->numerator = 0;
    this->denominator = 0;
}

Fraction::Fraction(double Number) { // конструктор преобразования double
    this->convertDoubleToFraction(Number);
}

Fraction::Fraction(std::string FractionString) { // конструктор преобразования string
    this->convertStringToFraction(FractionString);
}

Fraction::~Fraction() {} // диструктор

long Fraction::euclidean(long a, long b){
    return b == 0 ? a : this->euclidean(b, a % b);
}

long Fraction::getNumerator() { // функция доступа для получения числителя
    return this->numerator;
}

long Fraction::getDenominator() { // функция доступа для получения делителя
    return this->denominator;
}

void Fraction::setNumerator(long Numerator) { // функция для присвоения значения числителя
    this->numerator = Numerator;
}

void Fraction::setDenominator(long Denominator) { // функция для присвоения значения делителя
    this->denominator = Denominator;
}

bool Fraction::reduce() { // сокращение дроби
    long gcd(this->euclidean(this->numerator, this->denominator));

    if (1 < gcd) {
        this->numerator /= gcd;
        this->denominator /= gcd;

        return true;
    } else {
        return false;
    }
}

void Fraction::convertDoubleToFraction(double Number) { // преобразование double в дробь
    this->denominator = 1;
    while(((double)(int)Number) != Number) {
        Number = Number * 10;
        this->denominator = this->denominator * 10;
    }
    this->numerator = (long)Number;
    this->reduce();
}

double Fraction::convertFractionToDouble() { // преобразование дробь в double
    return (double)this->numerator / (double)this->denominator;
}

bool Fraction::convertStringToFraction(std::string FractionString) { // преобразование string в дробь
    std::size_t pos = FractionString.find("/");
    if (pos != std::string::npos) {
        try {
            this->numerator = atol(FractionString.substr(0, pos).c_str());
            this->denominator = atol(FractionString.substr(pos + 1).c_str());
        } catch(...) {
            return false;
        }
        return (this->denominator == 0) ? false : true;
    }
    return false;
}

Fraction Fraction::operator+(Fraction fraction) { // Функции перегрузки оператора сложения
    Fraction resultFraction;
    if (this->denominator == fraction.getDenominator()) {
        resultFraction.setNumerator(this->numerator + fraction.getNumerator());
        resultFraction.setDenominator(this->denominator);
    } else {
        resultFraction.setNumerator((this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator));
        resultFraction.setDenominator(this->denominator * fraction.getDenominator());
    }
    return resultFraction;
}

Fraction Fraction::operator-(Fraction fraction) { // Функции перегрузки оператора вычитания
    Fraction resultFraction;
    if (this->denominator == fraction.getDenominator()) {
        resultFraction.setNumerator(this->numerator - fraction.getNumerator());
        resultFraction.setDenominator(this->denominator);
    } else {
        resultFraction.setNumerator((this->numerator * fraction.getDenominator()) - (fraction.getNumerator() * this->denominator));
        resultFraction.setDenominator(this->denominator * fraction.getDenominator());
    }
    return resultFraction;
}

Fraction Fraction::operator*(Fraction fraction) { // Функции перегрузки оператора умножения
    Fraction resultFraction;
    resultFraction.setNumerator(this->numerator * fraction.getNumerator());
    resultFraction.setDenominator(this->denominator * fraction.getDenominator());
    return resultFraction;
}

Fraction Fraction::operator/(Fraction fraction) { // Функции перегрузки оператора умножения
    Fraction resultFraction;
    resultFraction.setDenominator(this->denominator * fraction.getNumerator());
    resultFraction.setNumerator(this->numerator * fraction.getDenominator());
    return resultFraction;
}

ostream& operator<<(ostream &out, Fraction &Fraction) { // Функции перегрузки оператора <<
    out << Fraction.getNumerator() << "/" << Fraction.getDenominator();
    return out;
}

istream& operator>>(istream &in, Fraction &Fraction) { // Функции перегрузки оператора >>
    string input;
    in >> input;
    if (false == Fraction.convertStringToFraction(input)) {
        throw FractionInputFailException();
    }
    return in;
}

void addFractions() { // сложение дробей
    Fraction firstFraction;
    Fraction secondFraction;
    Fraction resultFraction;
    std::cout << "Введите первую дробь в формате (x/y): ";
    try {
        std::cin >> firstFraction;
    } catch (std::exception& e) {
        clrscr();
        std::cout << e.what();
        return;
    }
    std::cout << "Введите вторую дробь в формате (x/y): ";
    try {
        std::cin >> secondFraction;
    } catch (std::exception& e) {
        clrscr();
        std::cout << e.what();
        return;
    }
    resultFraction = firstFraction + secondFraction;
    std::cout << "\nСложение дробей: " << firstFraction << " + " << secondFraction << " = " << resultFraction;
    if (true == resultFraction.reduce()) {
        std::cout << " = " << resultFraction;
    }
}

void subtractFractions() { // вычитание дробей
    Fraction firstFraction;
    Fraction secondFraction;
    Fraction resultFraction;
    std::cout << "Введите первую дробь в формате (x/y): ";
    try {
        std::cin >> firstFraction;
    } catch (std::exception& e) {
        clrscr();
        std::cout << e.what();
        return;
    }
    std::cout << "Введите вторую дробь в формате (x/y): ";
    try {
        std::cin >> secondFraction;
    } catch (std::exception& e) {
        clrscr();
        std::cout << e.what();
        return;
    }
    resultFraction = firstFraction - secondFraction;
    std::cout << "\nВычитание дробей: " << firstFraction << " - " << secondFraction << " = " << resultFraction;
    if (true == resultFraction.reduce()) {
        std::cout << " = " << resultFraction;
    }
}

void multiplyFractions() { // умножение дробей
    Fraction firstFraction;
    Fraction secondFraction;
    Fraction resultFraction;
    std::cout << "Введите первую дробь в формате (x/y): ";
    try {
        std::cin >> firstFraction;
    } catch (std::exception& e) {
        clrscr();
        std::cout << e.what();
        return;
    }
    std::cout << "Введите вторую дробь в формате (x/y): ";
    try {
        std::cin >> secondFraction;
    } catch (std::exception& e) {
        clrscr();
        std::cout << e.what();
        return;
    }
    resultFraction = firstFraction * secondFraction;
    std::cout << "\nУмножение дробей: " << firstFraction << " * " << secondFraction << " = " << resultFraction;
    if (true == resultFraction.reduce()) {
        std::cout << " = " << resultFraction;
    }
}

void divideFractions() { // деление дробей
    Fraction firstFraction;
    Fraction secondFraction;
    Fraction resultFraction;
    std::cout << "Введите первую дробь в формате (x/y): ";
    try {
        std::cin >> firstFraction;
    } catch (std::exception& e) {
        clrscr();
        std::cout << e.what();
        return;
    }
    std::cout << "Введите вторую дробь в формате (x/y): ";
    try {
        std::cin >> secondFraction;
    } catch (std::exception& e) {
        clrscr();
        std::cout << e.what();
        return;
    }
    resultFraction = firstFraction / secondFraction;
    std::cout << "\nДеление дробей: " << firstFraction << " / " << secondFraction << " = " << resultFraction;
    if (true == resultFraction.reduce()) {
        std::cout << " = " << resultFraction;
    }
}

//*****************************************************

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu){} // конструктор

int Card::GetValue() const // метод возращает значение карты
{
    int value = 0;
    if (m_IsFaceUp)
    {
        value = m_Rank;
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}

void Card::Flip() // метод положение каты, рубашкой верх, лицом верх
{
    m_IsFaceUp = !(m_IsFaceUp);
}
