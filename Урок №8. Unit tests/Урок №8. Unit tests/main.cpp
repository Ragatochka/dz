#include <iostream>
#include <stdexcept>
#include <Windows.h>

// 1. Получение цены товара по ID
double getItemPrice(int id) {
    switch (id) {
    case 1: return 100.0;  // Яблочный
    case 2: return 152.0;  // Апельсиновый
    case 3: return 130.0;  // Абрикосовый
    case 4: return 167.0;  // Грушевый
    case 5: return 125.0;  // Томатный
    case 6: return 105.0;  // Луковый
    case 7: return 130.0;  // Огуречный
    case 8: return 97.0;   // Чесночный чай
    case 9: return 99.0;   // Петрушевый чай
    case 10: return 467.0; // Боярышник
    default: throw std::invalid_argument("Неверный ID товара");
    }
}

// 2. Расчёт стоимости позиции с учётом скидки 5% на Петрушевый чай от 3 шт.
double calcItemCost(int id, int count) {
    if (count < 0) {
        throw std::invalid_argument("Количество не может быть отрицательным");
    }
    double price = getItemPrice(id);
    double cost = price * count;
    if (id == 9 && count >= 3) {
        cost *= 0.95;
    }
    return cost;
}

// 3. Расчёт количества подарочных единиц (каждый 4-й Луковый сок в подарок)
int calcBonusCount(int id, int count) {
    if (count < 0) {
        throw std::invalid_argument("Количество не может быть отрицательным");
    }
    if (id == 6 && count >= 4) {
        return count / 4;
    }
    return 0;
}

// 4. Проверка совместимости товаров (Боярышник нельзя с фруктовыми соками)
bool canAddItem(int id, bool hasFruitJuice) {
    if (id == 10 && hasFruitJuice) {
        return false;
    }
    return true;
}

// 5. Применение общей скидки 13%, если сумма корзины >= 666 рублей
double applyTotalDiscount(double totalSum) {
    if (totalSum < 0) {
        throw std::invalid_argument("Сумма не может быть отрицательной");
    }
    if (totalSum >= 666.0) {
        return totalSum * 0.87;
    }
    return totalSum;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int num = 1;
    int col = 0;
    const int mass = 100;
    int basket[mass]{};
    int basketcol[mass]{};
    int loh = 0;
    bool drop = false;

    while (true) {
        std::cout << "\t\t\t\tМагазин Соки Александра\n";
        std::cout << "Фруктовые: Яблочный(1), Апельсиновый(2), Абрикосовый(3), Грушевый(4).\n";
        std::cout << "             100р           152р             130р           167р\n";
        std::cout << "Овощные: Томатный(5), Луковый(6), Огуречный(7).\n";
        std::cout << "            125р         105р        130р\n";
        std::cout << "Чаи: Чесночный(8), Петрушевый(9).\n";
        std::cout << "         97р           99р\n";
        std::cout << "Настойки: Боярышник(10).\n";
        std::cout << "            467р\n";
        std::cout << "Все напитки по 1л\n";
        std::cout << "Если корзина будет равна или больше 666 рублей то скидка 13%\n";
        std::cout << "Для завершения покупок напишите \"0\"\n\n";

        while (true) {
            std::cout << "Выберите товар: ";
            std::cin >> num;

            if (num == 0) break;

            if (num > 10 || num < 0) {
                std::cout << "Такого товара нет в ассортименте!\n";
                Sleep(1500);
                break;
            }

            if (num >= 1 && num <= 4) {
                drop = true;
                for (int i = 0; i < loh; i++) {
                    if (basket[i] == 10) {
                        basket[i] = 0;
                        basketcol[i] = 0;
                    }
                }
            }
            else if (!canAddItem(num, drop)) {
                std::cout << "Вы не можете брать Боярышник, если выбрали сок!\n";
                Sleep(1500);
                system("cls");
                break;
            }

            std::cout << "\nВведите кол-во товара: ";
            std::cin >> col;
            if (col <= 0) break;

            basket[loh] = num;
            basketcol[loh] = col;
            loh++;
        }

        if (num == 0) break;
    }

    system("cls");
    std::cout << "Корзина\n";
    double total = 0.0;

    for (int i = 0; i < loh; i++) {
        if (basket[i] == 0) continue;

        double itemCost = calcItemCost(basket[i], basketcol[i]);
        int bonus = calcBonusCount(basket[i], basketcol[i]);
        total += itemCost;

        std::cout << "Товар #" << basket[i] << " (" << basketcol[i] << " шт.)";
        if (bonus > 0) std::cout << " + " << bonus << " в подарок";
        std::cout << " - " << itemCost << "р\n";
    }

    double finalTotal = applyTotalDiscount(total);
    std::cout << "Итого: " << finalTotal << "р\n";

    return 0;
}
