// lab16_Петрушев.cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>

struct Bus {
    std::string destination;
    int busNumber;
    std::string departureTime;
    int seats;
};

void printBus(const Bus& bus) {
    std::cout << "Пункт призначення: " << bus.destination
        << ", Номер автобуса: " << bus.busNumber
        << ", Час відправлення: " << bus.departureTime
        << ", Число місць: " << bus.seats << std::endl;
}

void printBusesToDestination(Bus buses[], int size, const std::string& destination) {
    std::cout << "Список автобусів, що прямують до " << destination << ":" << std::endl;
    for (int i = 0; i < size; ++i) {
        if (buses[i].destination == destination) {
            printBus(buses[i]);
        }
    }
}

bool isTimeLater(const std::string& time1, const std::string& time2) {
    int hour1 = std::stoi(time1.substr(0, 2));
    int minute1 = std::stoi(time1.substr(3, 2));
    int hour2 = std::stoi(time2.substr(0, 2));
    int minute2 = std::stoi(time2.substr(3, 2));

    if (hour1 > hour2) return true;
    if (hour1 == hour2 && minute1 > minute2) return true;
    return false;
}

void printBusesToDestinationAfterTime(Bus buses[], int size, const std::string& destination, const std::string& time) {
    std::cout << "Список автобусів, що прямують до " << destination << " і відправляються після " << time << ":" << std::endl;
    for (int i = 0; i < size; ++i) {
        if (buses[i].destination == destination && isTimeLater(buses[i].departureTime, time)) {
            printBus(buses[i]);
        }
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 5;
    Bus buses[size];

    for (int i = 0; i < size; ++i) {
        std::cout << "Введіть інформацію про автобус " << i + 1 << ":" << std::endl;
        std::cout << "Пункт призначення: ";
        std::cin >> buses[i].destination;
        std::cout << "Номер автобуса: ";
        std::cin >> buses[i].busNumber;
        std::cout << "Час відправлення (HH:MM): ";
        std::cin >> buses[i].departureTime;
        std::cout << "Число місць: ";
        std::cin >> buses[i].seats;
    }

    std::string searchDestination;
    std::cout << "Введіть пункт призначення для пошуку: ";
    std::cin >> searchDestination;

    printBusesToDestination(buses, size, searchDestination);

    std::string searchTime;
    std::cout << "Введіть час для пошуку (HH:MM): ";
    std::cin >> searchTime;

    printBusesToDestinationAfterTime(buses, size, searchDestination, searchTime);

    return 0;
}