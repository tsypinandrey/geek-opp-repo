/*файл: Gmenu.cpp
 *автор: Цыпин Андрей
 *дата: 11.03.2021
 *операционная система: ubuntu
 *задание: 4
 */

#include "prototype.h"

using std::cout;
using std::endl;
using std::cin;

void clrscr(void) { // Очистка экрана
    system("@cls||clear");
}

void Glmenu(){
    clrscr(); // очищаем экран
    cout << "Какое задание выполнить?" << endl;
    cout << "1. Создание 1." << endl;
    cout << "2. Создание 2." << endl;
    cout << "3. Реализация класс Hand." << endl;
    cout << "4. Выйти из программы" << endl;
    cout << "Ваш выбор: ";
}

void menuWorkArray(){
    cout << "Какую операцию с массивом выполнить?" << endl;
    cout << "1. - Добавить один элемент в конец массива." << endl;
    cout << "2. - Удалить последний элемент из массива." << endl;
    cout << "3. - Удалить первый элемент из массива." << endl;
    cout << "4. - Скортировка массива по возростанию." << endl;
    cout << "5. - Скортировка массива по убыванию." << endl;
    cout << "6. - Вывод на экран массива." << endl;
    cout << "7. - Завершить работу и выйти." << endl;
    cout << "Ваш выбор: ";
}

void menuWorkVector(){
    cout << "Какую операцию выполнить?" << endl;
    cout << "1. - Изменить параметры vector." << endl;
    cout << "2. - Завершить работу и выйти." << endl;
    cout << "Ваш выбор: ";
}

void Task1(){
    clrscr(); // очищаем экран
    cout << "Задние №1." << endl;
    cout << "Введите размер массива: ";
    int Size = 0, num = 0;
    Size = NumberLength(Size); // проверка на введеное значение (число Size <= 0)
    ArrayInt M(Size);
    if(M.isempty()){
        cout << "Заполните массив любыми числами." << endl;
        for (int i = 0; i < Size; i++){
            cout << i + 1 << ") ";
            cin >> M[i];
        }
        cout << "Ваш заполненый массив: ";
        M.prinArray();
    } else cout << "Вы создали пустой массив.";
    cout << endl;
    menuWorkArray();
    char ch;
    while (cin >> ch && ch != '7') {
        clrscr(); // очищаем экран
        cout << "Задние №1." << endl;
        cout << "Ваш выбор: " << ch << endl << endl;
        switch (ch) {
            case '1':
                    cout << "массив: ";
                    M.prinArray();
                    cout << "Для добовления в конец массива введите число : ";
                    num = NumberNum(num);
                    M.push_back(num);
                    cout << "чиcло -> " << num << " добавлено в конец массива" << endl;
                    cout << "массив: ";
                    M.prinArray();
                break;
            case '2':
                if(M.isempty()) {
                    cout << "массив: ";
                    M.prinArray();
                    cout << "чиcло -> " << M[M.getLength() - 1] << " удаленно из конца массива" << endl;
                    M.pop_back();
                    cout << "массив: ";
                    if (M.isempty())
                        M.prinArray();
                    else cout << "пуст." << endl;
               } else cout << "Операция не возможна так как массив пуст." << endl;
                break;
            case '3':
                if(M.isempty()) {
                    cout << "массив: ";
                    M.prinArray();
                    cout << "первое чиcло -> " << M[0] << " удаленно из массива" << endl;
                    cout << "массив: ";
                M.pop_front();
                M.prinArray();
                } else cout << "Операция не возможна так как массив пуст." << endl;
                break;
            case '4':
                if(M.isempty()) {
                    cout << "массив: ";
                    M.prinArray();
                    M.sortArrayUp();
                    cout << "Сортировка по возрастанию.";
                    cout << "массив: ";
                    M.prinArray();
                } else cout << "Операция не возможна так как массив пуст." << endl;
                break;
            case '5':
                if(M.isempty()) {
                    cout << "массив: ";
                    M.prinArray();
                    M.sortArrayDown();
                    cout << "Сортировка по убыванию.";
                    cout << "массив: ";
                    M.prinArray();
                } else cout << "Операция не возможна так как массив пуст." << endl;
                break;
            case'6':
                if(M.isempty()) {
                    cout << "массив: ";
                    M.prinArray();
                } else cout << "Операция не возможна так как массив пуст." << endl;
                break;
            case '7':
                cout << "Завершить работу и выйти: ";
                break;
            default: while (cin.get() != '\n'){} // если ввели строку, то всё отбросить
                cout << "Вы ввели неверное значение, введите от 1 до 7: ";
        }
        cout << endl;
        menuWorkArray();
        while (cin.get() != '\n') {}

    }
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task2(){
    clrscr(); // очищаем экран
    int Size = 30; // длина вектра
    int Randsize = 20; // диапазон случайных чисел
    std::vector<int> number; // создаем пустой вектор
    cout << "Создан вектор из " << Size << " случайных чисел," << endl;
    cout << "диапазон чисел от 0 до " << Randsize << " :" << endl;
    for (int i = 0; i < Size; ++i){
        number.push_back(rand() % Randsize); // присваеваем каждому элементу массива случайное число
        cout << number[i] << " "; // выводим на экран созданный массив
    }
    cout << endl << endl;
    cout << "Создан ассоциативный контейнер из данного вектора" << endl;
    cout << "отсортированный по возростанию:" << endl;
    std::set <int> col; // ассоциативный контейнер который автоматически сортирует добавляемые элементы в порядке возрастания
    for (int i = 0; i < Size; ++i)
        col.insert(number[i]); // при добавлении повторяющейся значений,set будет храниться только один экземпляр
    std::set <int> :: iterator itu = col.begin(); // создаем итератор и устанавливаем его на первый элемент
    for(; itu != col.end(); itu++)
        cout << *itu << " "; // выводим на экран значение итератора
    cout << endl;
    cout << "Создан ассоциативный контейнер из данного вектора" << endl;
    cout << "отсортированный по убыванию:" << endl;
    std::set <int, std::greater <int> > st; // ассоциативный контейнер который автоматически сортирует добавляемые элементы в порядке убывания
    for (int i = 0; i < Size; ++i)
        st.insert(number[i]); // при добавлении повторяющейся значений,set будет храниться только один экземпляр
    itu = st.begin(); // устанавливаем его на первый элемент
    for(; itu != st.end(); itu++)
        cout << *itu << " "; // выводим на экран значение итератора
    cout << endl << endl;
    menuWorkVector();
    char ch;
    while (cin >> ch && ch != '2') {
        clrscr(); // очищаем экран
        cout << "Задние №2." << endl;
        cout << "Ваш выбор: " << ch << endl << endl;
        switch (ch) {
            case '1':
                    cout << "Введите новую длину вектора: ";
                    number.clear();
                    Size = NumberLength(Size); // проверка на введеное значение (число Size <= 0)
                    cout << "Введите диапазон чисел(от 0 до 100): ";
                    Randsize = NumberLength(Randsize);
                    cout << "Size = " << Size << ", Randsize = " << Randsize << endl;
                    cout << "Дан вектор из " << Size << " случайных чисел," << endl;
                    cout << "диапазон чисел от 0 до " << Randsize << " :" << endl;
                    for (int i = 0; i < Size; ++i){
                        number.push_back(rand() % Randsize); // присваеваем каждому элементу массива случайное число
                        cout << number[i] << " "; // выводим на экран созданный массив
                    }
                    cout << endl << endl;
                    cout << "Создан ассоциативный контейнер из данного вектора" << endl;
                    cout << "отсортированный по возростанию:" << endl;
                    col.clear();
                    for (int i = 0; i < Size; ++i)
                        col.insert(number[i]); // при добавлении повторяющейся значений,set будет храниться только один экземпляр
                    itu = col.begin(); // устанавливаем его на первый элемент
                    for(; itu != col.end(); itu++)
                        cout << *itu << " "; // выводим на экран значение итератора
                    cout << endl;
                    cout << "Создан ассоциативный контейнер из данного вектора" << endl;
                    cout << "отсортированный по убыванию:" << endl;
                    st.clear();
                    for (int i = 0; i < Size; ++i)
                        st.insert(number[i]); // при добавлении повторяющейся значений,set будет храниться только один экземпляр
                    itu = st.begin(); // устанавливаем его на первый элемент
                    for(; itu != st.end(); itu++)
                        cout << *itu << " "; // выводим на экран значение итератора
                    cout << endl << endl;
                break;
            case '2':
                cout << "Завершить работу и выйти: ";
                break;
            default: while (cin.get() != '\n'){} // если ввели строку, то всё отбросить
                cout << "Вы ввели неверное значение, введите от 1 до 2: ";
        }
        menuWorkVector();
    }
    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}

void Task3(){
    clrscr(); // очищаем экран
    cout << " class Hand" << endl;
    cout << " {" << endl;
    cout << "   public:" << endl;
    cout << "       Hand(); // конструктор по умолчанию" << endl;
    cout << "       virtual ~Hand(); // виртуальный деструктор" << endl;
    cout << "       void Add(Card* pCard); // добавляет карту в руку" << endl;
    cout << "       void Clear(); // очищает руку от карт" << endl;
    cout << "       //получает сумму очков карт в руке, присваивая тузу" << endl;
    cout << "       // значение 1 или 11 в зависимости от ситуации" << endl;
    cout << "       int GetTotal() const;" << endl;
    cout <<  endl;
    cout << "   protected:" << endl;
    cout << "      std::vector <Card*> m_Cards;" << endl;
    cout << " };" << endl;

    cout << "Для продолжения нажмите <Enter>: ";
    cin.get();
    cin.get();
    clrscr(); // очищаем экран
    Glmenu();  // вывод меню на экран
}
