Демонстрація читання неініціалізованої памʼяті з ASan

 Опис

У цьому прикладі демонструється **читання неініціалізованої пам’яті** в С++ та виявлення цієї помилки за допомогою **AddressSanitizer (ASan)**. Код виділяє динамічний масив з 5 цілих чисел, ініціалізує лише перший елемент, а потім читає третій — що є помилкою.

 Код

#include <iostream>

int* arr = new int[5]; // виділення пам’яті
arr[0] = 42;           // лише один елемент ініціалізований

std::cout << arr[3] << std::endl; // читання неініціалізованого значення

delete[] arr;
Компіляція з ASan
Використовуйте такі прапори компілятора:

g++ -fsanitize=address -g -O1 -o test_case1 test_case1.cpp
-fsanitize=address — увімкнення ASan

-g — додавання дебаг-інформації

-O1 — оптимізація, сумісна з ASan

Запуск
./test_case1

Приклад виводу ASan
==12345==ERROR: AddressSanitizer: use-of-uninitialized-value
    #0 0x7f4d893 in main test_case1.cpp:8
    ...
  Uninitialized value was created by a heap allocation
    #0 0x4b7f80 in operator new[](unsigned long) ...
    #1 0x7f4d893 in main test_case1.cpp:5
