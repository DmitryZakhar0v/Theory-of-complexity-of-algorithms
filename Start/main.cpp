#include <iostream>
#include <vector>
#include <random>

/**
* @brief Сортировка массива пузырьком
* @param vector Массив для сортировки
* @param count Счетчик сравнений
* @return Отсортированный массив
*/
std::vector<int> bubble_sort(std::vector<int> arr, size_t& count);

/**
* @brief Быстрая сортировка
* @param vector Массив для сортировки
* @param count Счетчик сравнений
* @return Отсортированный массив
*/
std::vector<int> quick_sort(std::vector<int> arr, size_t& count);

/**
* @brief Сортировка вставками
* @param vector Массив для сортировки
* @param count Счетчик сравнений
* @return Отсортированный массив
*/
std::vector<int> insertion_sort(std::vector<int> arr, size_t& count);

/**
* @brief Создание случайного числа в диапазоне
* @param min Минимальное значение
* @param max Максимальное значение
* @return Случайное число
*/
int generate_random(const int min, const int max);


int main() {

    try
    {
        std::cout << "Array size:";
        int arr_size;
        std::cin >> arr_size;
        int min_value = -9999;
        int max_value = 9999;

        std::vector<int> arr;
        for (size_t i = 0; i < arr_size; i++)
        {
            arr.push_back(generate_random(min_value, max_value));
        }

        size_t bubble_count = 0;
        std::vector<int> bubble_arr = bubble_sort(arr, bubble_count);

        size_t insertion_count = 0;
        std::vector<int> insertion_arr = insertion_sort(arr, insertion_count);

        size_t quick_counter = 0;
        std::vector<int> quick_arr = quick_sort(arr, quick_counter);

        for (size_t j = 0; j < quick_arr.size(); j++)
        {
            std::cout << quick_arr[j] << " ";
        }
        std::cout <<std::endl;
        std::cout << "Bubble count: " << bubble_count << std::endl;
        std::cout << "Insertion count: " << insertion_count << std::endl;
        std::cout << "quick count: " << quick_counter << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
    }
    return 0;
}

int generate_random(const int min, const int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uniformIntDistribution(min, max);
    return uniformIntDistribution(gen);
}

std::vector<int> bubble_sort(std::vector<int> arr, size_t& count) {
    int size = arr.size();
    for (size_t i = 0; i < size - 1; ++i) {
        bool flag = false;
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);

                flag = true;
            }
            count++;
        }
        if (!flag)
            break;
    }
    return arr;
}

std::vector<int> insertion_sort(std::vector<int> arr, size_t& count)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        int value = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j] > value)
        {
            arr[j + 1] = arr[j];
            count += 1;
            j--;
        }
        arr[j + 1] = value;
    }
    return arr;
}

std::vector<int> quick_sort(std::vector<int> arr, size_t& count)
{
    if (arr.size() < 2) return arr;
    int current = arr[0];
    std::vector<int> arr_1{};
    std::vector<int> arr_2{};

    for (size_t j = 1; j < arr.size(); j++) {
        {
            count++;
            if (arr[j] < current)
                arr_1.push_back(arr[j]);
            else
                arr_2.push_back(arr[j]);
        }
    }
    std::vector<int> temp_1 = quick_sort(arr_1, count);
    std::vector<int> temp_2 = quick_sort(arr_2, count);
    temp_1.push_back(current);
    temp_1.insert(temp_1.end(), temp_2.begin(), temp_2.end());
    return temp_1;
}