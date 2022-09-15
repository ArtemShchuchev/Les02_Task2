#include <iostream>

struct Bill
{
    unsigned int account = 0;
    std::string userName;
    float money = 0.0;
};

void changeBalance(Bill&, float);
bool inputClean();
Bill userInput();
float newBalanceInput();
void printBill(const Bill&);

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");   // задаём русский текст
    system("chcp 1251");            // настраиваем кодировку консоли
    std::system("cls");

    std::cout << "Задача 2. Счета\n";
    std::cout << "---------------\n" << std::endl;

    Bill user = userInput();
    changeBalance(user, newBalanceInput());
    printBill(user);
    
    std::cout << std::endl;

    return 0;
}


void changeBalance(Bill& bill, float newBalance)
{
    bill.money = newBalance;
}
bool inputClean()
{
    bool err = std::cin.fail();
    if (err) std::cin.clear(); // ошибка ввода
    int ch; // поиск и очистка лишних введенных символов
    while ((ch = std::cin.get()) != '\n' && ch != EOF);
    
    return err;
}
Bill userInput()
{
    using namespace std;
    
    Bill bill;
    int temp = 0;
    do
    {
        // оказалось cin не верно принимает unsigned переменные
        // или не так как я ожидал, поэтому сделал ввод данных
        // счета через временную переменную с последующим
        // приведением (
        cout << "Введите номер счёта: "; cin >> temp;
    } while (inputClean());
    if (temp < 0) bill.account = static_cast<unsigned int>(temp) * -1;
    else bill.account = static_cast<unsigned int>(temp);

    cout << "Введите имя владельца: "; cin >> bill.userName;

    do
    {
        cout << "Введите баланс: "; cin >> bill.money;
    } while (inputClean());

    return bill;
}
float newBalanceInput()
{
    float balance;
    do
    {
        std::cout << "Введите новый баланс: "; std::cin >> balance;
    } while (inputClean());
    return balance;
}
void printBill(const Bill& bill)
{
    std::cout << "Ваш счёт: " << bill.userName
        << ", " << bill.account
        << ", " << bill.money;
}
/*
Описание
Создайте структуру для хранения информации о банковском счёте. Она должна хранить номер счёта (целое число),
имя владельца (строка) и количество денег на счету (дробное число)

Создайте функцию для изменения баланса счёта - функция должна принимать экземпляр структуры банковского счёта и новую сумму

Попросите пользователя заполнить поля экземпляра структуры, попросите его сообщить новый баланс счёта и выведите
обновлённый экземпляр структуры на консоль

Пример работы программы
Введите номер счёта: 123456789
Введите имя владельца: Андрей
Введите баланс: 5000
Введите новый баланс: 6000
Ваш счёт: Андрей, 123456789, 6000
*/