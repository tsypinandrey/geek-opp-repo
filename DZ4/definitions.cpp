/*файл: definitions.cpp
 *автор: Цыпин Андрей
 *дата: 011.03.2021
 *операционная система: ubuntu
 *задание: 4
 */

#include "prototype.h"

using std::cout;
using std::endl;
using std::cin;

ArrayInt::ArrayInt() : m_length(0), m_data(nullptr) {} // конструктор по умолчанию
ArrayInt::ArrayInt(int length) : m_length(length){ // конструктор с параметрами
    assert(length >= 0);
    if (length > 0)
        m_data = new int[length];
    else
        m_data = nullptr;
}
ArrayInt::~ArrayInt(){ // диструктор освобождения выделеной памяти
    delete [] m_data;
}
void ArrayInt::erase(){ // метод очистки массива и сброса длины
    delete [] m_data;
    m_data = nullptr;
    m_length = 0;
}
bool ArrayInt::isempty(){
    if (m_length == 0) return false;
    else return true;
}
int ArrayInt::getLength(){ // метод возращает длину массива
    return m_length;
}
int& ArrayInt::operator[] (int index){ // перегрука оператора [], чтобы иметь доступ к элементам массива
    assert(index >= 0 && index < m_length);
    return m_data[index];
}
void ArrayInt::resize(int newLength){ // метод resize изменяет размер массива, с сохранением данных
    if (newLength == m_length) return;
    if (newLength <= 0){
        erase();
        return;
    }
    int *data = new int[newLength];
    if (m_length > 0){
        int elementsToCopy = newLength > m_length ? m_length : newLength;
        for (int i = 0; i < elementsToCopy; i++) {
            data[i] = m_data[i];
        }
    }
    delete [] m_data;
    m_data = data;
    m_length = newLength;
}
void ArrayInt::insertBefore(int value, int index){ // метод добавления нового элемента в массив
    assert(index >= 0 && index <= m_length); // Проверка корректности передоваемого индекса
    int *data = new int[m_length + 1]; // Создаем новый массив на один элемент больше старого массива
    for (int before = 0; before < index; ++before) // копируем все элементы до index-a
        data[before] = m_data[before];
    data[index] = value; // вставляем новый элемент в новый массив
    for (int after = index; after < m_length; ++after) // копируем все значения после вставляемого элемента
        data[after + 1] = m_data[after];
    delete[] m_data; // удаляем старый массив и используем вместо него новый
    m_data = data;
    ++m_length;
}
void ArrayInt::push_back(int value){ // вставка нового элемента в конец массива
    insertBefore(value, m_length);
}
void ArrayInt::pop_back(){ // Удаление последнего элемента массива
    int newLength = m_length - 1;
    if (newLength == m_length) return;
    if (newLength <= 0){
        erase();
        return;
    }
    int *data = new int[newLength];
    if (m_length > 0){
        int elementsToCopy = newLength > m_length ? m_length : newLength;
        for (int i = 0; i < elementsToCopy; i++) {
            data[i] = m_data[i];
        }
    }
    delete [] m_data;
    m_data = data;
    m_length = newLength;
}

void ArrayInt::pop_front(){ // Удаление первого элемента массива
    int newLength = m_length - 1;
    if (newLength == m_length) return;
    if (newLength <= 0){
        erase();
        return;
    }
    int *data = new int[newLength];
    if (m_length > 0){
        int elementsToCopy = newLength > m_length ? m_length : newLength;
        for (int i = 0; i < elementsToCopy; i++) {
            data[i] = m_data[i + 1];
        }
    }
    delete [] m_data;
    m_data = data;
    m_length = newLength;
}

void ArrayInt::prinArray(){ // вывод на экран массива
    for (int i = 0; i < m_length; ++i){
          cout << m_data[i] << " ";
    }
    cout << endl;
}

void ArrayInt::sortArrayUp(){ // сортировка массива по возростанию
    int temp;
    for (int i = 0; i < m_length - 1; ++i){
        for (int j = 0; j < m_length - 1; ++j)
             if (m_data[j + 1] < m_data[j]){
                 temp = m_data[j + 1];
                 m_data[j + 1] = m_data[j];
                 m_data[j] = temp;
             }
    }
}
void ArrayInt::sortArrayDown(){ // сортировка массива по возростанию
    int temp;
    for (int i = 0; i < m_length - 1; ++i){
        for (int j = 0; j < m_length - 1; ++j)
             if (m_data[j + 1] > m_data[j]){
                 temp = m_data[j + 1];
                 m_data[j + 1] = m_data[j];
                 m_data[j] = temp;
             }
    }
}

int NumberLength(int k){ // проверка ввода числа
    while (!(cin >> k) || (cin.peek() != '\n') || k < 0){
        cin.clear();
        while (cin.get() != '\n') {};
            cout << "Это неверный ввод! Введите число: ";
    }
    return k;
}

int NumberNum(int k){ // проверка ввода числа
    while (!(cin >> k) || (cin.peek() != '\n')){
        cin.clear();
        while (cin.get() != '\n') {};
            cout << "Это неверный ввод! Введите число: ";
    }
    return k;
}

//***********************************

Hand::Hand(){
    m_Cards.reserve(7);
}
Hand::~Hand(){
    Clear();
}

void Hand::Add(Card* pCard){
    m_Cards.push_back(pCard);
}

void Hand::Clear(){
    std::vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter){
        delete *iter;
        *iter = 0;
    }
    m_Cards.clear();
}
