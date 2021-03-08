#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <iostream>

void clrscr(void);
void Glmenu();
void Task1();
void Task2();
void Task3();
void Task4();
void addFractions(void);
void subtractFractions(void);
void multiplyFractions(void);
void divideFractions(void);


using namespace std;

class Figure{ // абстрактный класс
public:
    virtual void printfigure() = 0; // виртуальная функция вывода параметров фигуры
    virtual void area() = 0; // виртуальная функция для расчета площади фигуры

};

class Paralelogram: public Figure {
protected:
    float hight; // высота, радиус
    float width; // ширина основания
public:
    Paralelogram(); // конструктор по умолчанию
    Paralelogram(float a, float b); // конструктор с переметрами для инициализации переменных
    void getParalelogram(float a, float b); // изменение параметров Паралелограмма
    void printfigure(); // вывод на экран параметры Параллерограмма
    void area(); // вывод на экран площади Параллерограмма
};

class Circle: public Figure {
protected:
    float radius; // радиус круга
public:
    Circle(); // конструктор по умолчанию
    Circle(float a); // конструктор с переметрами для инициализации переменных
    void getCircle(float a); // изменение радиуса круга
    void printfigure(); // вывод на экран параметров круга
    void area(); // вывод на экран площади круга
};

class Rectangle: public Paralelogram{
public:
    Rectangle(); // конструктор по умолчанию
    Rectangle(float a, float b); // конструктор с переметрами для инициализации переменных
    void printfigure(); // вывод на экран параметров Прямоугольник
    void area(); // вывод на экран площади Прямоугольника
};

class Square: public Paralelogram{
public:
    Square(); // конструктор по умолчанию
    Square(float a); // конструктор с переметрами для инициализации переменных
    void printfigure(); // вывод на экран параметров Квадрата
    void area(); // вывод на экран площади Квадрат
};

class Rhombus: public Paralelogram{
public:
    Rhombus(); // конструктор по умолчанию
    Rhombus(float a, float b); // конструктор с переметрами для инициализации переменных
    void printfigure(); // вывод на экран параметров Ромба
    void area(); // вывод на экран площади Ромба
};

template <typename N> // определение проверка ввода числа
N Number(N k){
    while (!(cin >> k) || (cin.peek() != '\n') || k <=0){
        cin.clear();
        while (cin.get() != '\n') {};
            cout << "Это неверный ввод! Введите число: ";
    }
    return k;
}

//**********************************************************************

class Car{
protected:
    string company;
    string model;
public:
    Car(string c, string m) : company(c), model(m){
        cout << "Company: " << company<< endl;
        cout << "Model: " << model << endl;
    }
};

class PassengerCar : virtual public Car{
protected:
    string color;
public:
    PassengerCar(string c, string m, string s) : Car(c, m), color(s){
        cout << "Color Car: " << color << endl;
    }
};

class Bus : virtual public Car {
protected:
    int places;
public:
    Bus(string c, string m, int p) : Car(c, m), places(p){
        cout << "number of seats: " << places << endl;
    }
};

class Miniven : public PassengerCar, public Bus{
private:
    int n;
public:
    Miniven(string c, string m, string s, int p, int a) :
        Car(c, m), PassengerCar(company, model, s), Bus(company, model, p), n(a){
        cout << "number of divers: " << n << endl;
    }
};

//*******************************************************************************

class Fraction { // класс дробь
private:
    long numerator; // числитель
    long denominator; // делитель
    long euclidean(long a, long b); // Евклидов алгоритм для наибольшего общего делителя
public:
    Fraction(void); // конструктор по умолчанию
    Fraction(double Number); // конструктор преобразования double
    Fraction(std::string FractionString); // конструктор преобразования string
    ~Fraction(void); // диструктор

    long getNumerator(void); // функция доступа для получения числителя
    long getDenominator(void); // функция доступа для получения делителя
    void setNumerator(long Numerator); // функция для присвоения значения числителя
    void setDenominator(long Denominator); // функция для присвоения значения делителя

    bool reduce(void); // сокращение дроби
    void convertDoubleToFraction(double Number); // преобразование double в дробь
    double convertFractionToDouble(void); // преобразование дробь в double
    bool convertStringToFraction(std::string FractionString); // преобразование string в дробь

    // Функции перегрузки операторов
    bool operator<(Fraction fraction);
    bool operator<=(Fraction fraction);
    bool operator>(Fraction fraction);
    bool operator>=(Fraction fraction);
    bool operator==(Fraction fraction);
    bool operator!=(Fraction fraction);
    long operator%(Fraction fraction);

    operator double();
    operator float();
    operator long();
    operator std::string();

    Fraction operator+(Fraction fraction);
    Fraction operator+=(Fraction fraction);
    Fraction operator-=(Fraction fraction);
    Fraction operator-(Fraction fraction);
    Fraction operator*(Fraction fraction);
    Fraction operator*=(Fraction fraction);
    Fraction operator/(Fraction fraction);
    Fraction operator/=(Fraction fraction);
    Fraction operator~(void);
    Fraction operator++(void);
    Fraction operator--(void);
};

class FractionInputFailException: public std::exception { // вертуальный класс исключений
    public: virtual const char* what() const throw() { return "Неправильный ввод"; }
};

std::ostream& operator<<(std::ostream &out, Fraction &Fraction); // Функции перегрузки оператора <<

std::istream& operator>>(std::istream &in, Fraction &Fraction); // Функции перегрузки оператора >>

//***************************************************************

class Card {
public:
    enum rank { // перечисление значений карт
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES }; // перечисление масти карт

    Card(rank r = ACE, suit s = SPADES, bool ifu = true); // конструктор
    int GetValue() const; // метод возращает значение карты
    void Flip(); // метод положение каты, рубашкой верх, лицом верх

private:
    rank m_Rank; // значение карты
    suit m_Suit; // масть карты
    bool m_IsFaceUp; // положение карты
};


#endif // PROTOTYPE_H
