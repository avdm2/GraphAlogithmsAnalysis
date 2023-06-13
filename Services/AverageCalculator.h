#include <vector>
#include <functional>

#include "../Models/Edge.h"
#include "Generator.h"

// Если прогонять каждый метод по 50 раз, то за 44 минуты программа напишет ровно 100 строк из 189. С учетом того,
// что чем дальше, тем больше вершин у графа, количество тестов я решил снизить до 10
// При TEST_AMOUNTS = 10 тесты так и не завершились за ~полтора часа работы, поэтому усредненное значение будет для 5 тестов
// (i5-9300h, 16gb)

#define TESTS_AMOUNT 5

using Graph = std::vector<std::vector<Edge>>;

uint64_t average_time(const Graph& g, const std::function<std::pair<int64_t, std::vector<int>>(const Graph&)>& func) {
    uint64_t sum = 0;
    for (int i = 0; i < TESTS_AMOUNT; ++i) {
        sum += func(g).first;
    }
    return sum / TESTS_AMOUNT;
}