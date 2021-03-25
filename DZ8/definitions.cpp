/*файл: definitions.cpp
 *автор: Цыпин Андрей
 *дата: 25.03.2021
 *операционная система: ubuntu
 *задание: 8
 */

#include "prototype.h"

using std::cout;
using std::endl;
using std::cin;

const int ROW = 11;
const int COL = 11;
char arr[ROW][COL];

void Robot::GetRoute(){
    int x1 = 0, y1 = 0;
    cout << "Введите направление движения робота строго только\n"
            "вверх <U>, вниз <D>, влево <L>, вправо <R>: ";
    route = ValueChar(route);
    cout << "Введите координаты назначения <x>: ";
    x1 = Number(x1);
    cout << "Введите координаты назначения <y>: ";
    y1 = Number(y1);
    if(x1 >= 0 && x1 <= DX && y1 >= 0 && y1 <= DY) {
        if (route == 'R' && x <= x1 && y == y1) {
           GetXY(x1, y1);
           arr[COL - y1 - 1][x1] = '+';
           arr[COL - y - 1][x] = 'X';
           printArr();
           printRobot(x1, y1, route);
        }else if (route == 'L' && x >= x1 && y == y1){
            GetXY(x1, y1);
            arr[COL - y1 - 1][x1] = '+';
            arr[COL - y - 1][x] = 'X';
            printArr();
            printRobot(x1, y1, route);
        }
        else if (route == 'U' && x1 == x && y <= y1){
            GetXY(x1, y1);
            arr[COL - y1 - 1][x1] = '+';
            arr[COL - y - 1][x] = 'X';
            printArr();
            printRobot(x1, y1, route);
        }
        else if (route == 'D' && x1 == x && y >= y1){
            GetXY(x1, y1);
            arr[COL - y1 - 1][x1] = '+';
            arr[COL - y - 1][x] = 'X';
            printArr();
            printRobot(x1, y1, route);
        }
        else{
            std::cerr << "Вы задали не верные координаты для движения робота." << endl;
            throw "IIIegalCommand";
        }
    } else {
        std::cerr << "Вы вышли за границы поля." << endl;
        throw "OffTheField";
    }
}
void Robot::GetXY(int &x_x, int &y_y){
    int temp = x_x;
    x_x = x;
    x = temp;
    temp = y_y;
    y_y = y;
    y = temp;
}
void Robot::printRobot(int x_x, int y_y, char r){
    std::string str;
    if (r == 'R') str = "право: ";
    if (r == 'L') str = "лево: ";
    if (r == 'U') str = "вверх: ";
    if (r == 'D') str = "вниз: ";
    if(x == x_x && y == y_y) cout << "Робот остался на месте." << endl;
    else cout << "Робот переместился в " << str << endl;
    cout << "с x:->" << x_x << " на x->" << x << endl;
    cout << "с y:->" << y_y << " на y->" << y << endl;
}

char ValueChar(char c) // проверка ввода символа направления движения робота
{
    while(std::cin >> c)
    {
        c = toupper(c);
        switch(c){
            case ('R'): return c;
            case ('L'): return c;
            case ('U'): return c;
            case ('D'): return c;
            default: cout << "Вы ввели не верное значение." << endl;
                     cout << "Введите направление движения робота строго только\n"
                             "вверх <U>, вниз <D>, влево <L>, вправо <R>: ";
        }
    }
    return c;
}

void initArr(){
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            arr[i][j] = '+';
    arr[10][0] = 'X';
}
void printArr (){
    cout << " \x1b[32mY\x1b[0m" << endl;
    cout << " ^" << endl;
    cout << " |" << endl;
    for (int i = 0; i < ROW; ++i){
        cout << "\x1b[32m";
        cout.width(2);
        cout << (ROW - 1) - i << "\x1b[0m ";
        for (int j = 0; j < COL; ++j){
            if (arr[i][j] == 'X')
                cout << "\x1b[31m" << arr[i][j] << "\x1b[0m ";
            else cout << arr[i][j] << " ";
        }
    cout << endl;
    }
    cout << "   ";
    for (int i = 0; i < COL; ++i)
        cout << "\x1b[32m" << i << "\x1b[0m ";
    cout << "-> \x1b[32mX\x1b[0m" << endl;
}
