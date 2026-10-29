#include <iostream>
#include <Windows.h>
bool LeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int DaysMonth(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    if (month == 2) {
        if (LeapYear(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    return 31;
}

int DaysDiff(int d1, int m1, int y1, int d2, int m2, int y2) {
    long long date1 = y1 * 10000 + m1 * 100 + d1;
    long long date2 = y2 * 10000 + m2 * 100 + d2;

    if (date1 > date2) {
        int tempD = d1; d1 = d2; d2 = tempD;
        int tempM = m1; m1 = m2; m2 = tempM;
        int tempY = y1; y1 = y2; y2 = tempY;
    }

    int daysCount = 0;

    while (d1 != d2 || m1 != m2 || y1 != y2) {
        daysCount++;
        d1++;

        if (d1 > DaysMonth(m1, y1)) {
            d1 = 1;
            m1++;

            if (m1 > 12) {
                m1 = 1;
                y1++;
            }
        }
    }

    return daysCount;
}


// ЗАДАНИЕ 2:


double getAverage(int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    return sum / size;
}


// ЗАДАНИЕ 3:


int Positive(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }
    return count;
}

int Negative(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}

int Zeros(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            count++;
        }
    }
    return count;
}
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Задания 1
    int day1, month1, year1;
    int day2, month2, year2;

    std::cout << "Задание 1 \n";
    std::cout << "Введите первую дату (день месяц год): ";
    std::cin >> day1 >> month1 >> year1;

    std::cout << "\nВведите вторую дату (день месяц год): ";
    std::cin >> day2 >> month2 >> year2;

    int resultDays = DaysDiff(day1, month1, year1, day2, month2, year2);
    std::cout << "\nРезультат: " << resultDays << " дней.";

    //Заданий 2 и 3
    std::cout << "\nЗадания 2 и 3";

    int myArray[5];
    std::cout << "\nВведите 5 целых чисел для массива через пробел: ";
    for (int i = 0; i < 5; i++) {
        std::cin >> myArray[i];
    }

    double Value = getAverage(myArray, 5);
    int positiveTotal = Positive(myArray, 5);
    int negativeTotal = Negative(myArray, 5);
    int zeroTotal = Zeros(myArray, 5);

    std::cout << "\nСреднее арифметическое: " << Value;
    std::cout << "\nПоложительных чисел: " << positiveTotal;
    std::cout << "\nОтрицательных чисел: " << negativeTotal;
    std::cout << "\nЧисел равных нулю: " << zeroTotal;
    return 0;
}
