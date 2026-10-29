#include <iostream>
#include <Windows.h>
//Урок №7 Практика массивов
int main() {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int tank[2][2] = { { 300, 0 },{ 1000, 100 } };

    int Limits[2][3] = { { 750, 1500, 2000 },{ 1000, 2000, 3000 } };
    int full[2][3] = { { 1, 4, 7 },{ 2, 4, 6 } };

    int plane;
    double distAB, distBC, cargo;

    std::cout << "Номер самолета (1 или 2), расстояния АВ, ВС и вес груза: ";
    std::cin >> plane >> distAB >> distBC >> cargo;

    if (plane != 1 && plane != 2) return 0;
    int idx = plane - 1;

    double sum = -1;
    for (int i = 0; i < 3; i++)
    {
        if (cargo <= Limits[idx][i])
        {
            sum = full[idx][i];
            break;
        }
    }

    if (sum == -1)
    {
        std::cout << "\nПолет невозможен: самолет не подмет такой вес!\n";
        return 0;
    }

    double fullA = tank[idx][0] + tank[idx][1];
    double needAB = distAB * sum;

    if (needAB > fullA)
    {
        std::cout << "Полет невозможен: не хватит топлива до В!\n";
        return 0;
    }

    double fullAtB = fullA - needAB;
    if (fullAtB > tank[idx][0])
    {
        fullAtB = tank[idx][0];
    }

    double needBC = distBC * sum;
    if (needBC > tank[idx][0])
    {
        std::cout << "Полет невозможен: расстояние ВС слишком велико для основного бака!\n";
        return 0;
    }

    double refull = 0;
    if (fullAtB < needBC)
    {
        refull = needBC - fullAtB;
    }

    std::cout << "Успешно! Нужно дозаправить в пункте В: " << refull << " литров.";
    return 0;
}