#include <iostream>

int main() {
    int* arr = new int[5]; // виділення пам’яті під масив з 5 цілих чисел
    arr[0] = 42;           // ініціалізуємо лише перший елемент

    std::cout << arr[3] << std::endl;  // Читання неініціалізованої пам’яті

    delete[] arr;
    return 0;
}
