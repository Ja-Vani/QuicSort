//
// Created by Ja_Vani on 2.12.2024.
//
#include <random>

#include "gtest/gtest.h"
#include "my_sort.h"

TEST(Sort_tests, insert_test) {
    int arr[100];
    for(int t = 0; t < 100; t++) {
        arr[t] = 100-t;
    }
    insert_sort(arr, arr+100, [](int a, int b) { return a < b; });
    for (int i = 0; i < 100; ++i)
        ASSERT_TRUE(i + 1 == arr[i]);
}

TEST(Sort_tests, quick_test) {
    int arr[100];
    for(int t = 0; t < 100; t++) {
        arr[t] = 100-t;
    }
    quick_sort(arr, arr+100, [](int a, int b) { return a < b; });
    for (int i = 0; i < 100; ++i)
        ASSERT_TRUE(i + 1 == arr[i]);
}

TEST(Sort_tests, quick_test_random) {
    int arr[100];
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> uniform_dist(-10000, 10000);
    for(int t = 0; t < 100; t++) {
        arr[t] = uniform_dist(generator);
    }
    quick_sort(arr, arr+100, [](int a, int b) { return a < b; });
    for (int i = 0; i < 99; ++i)
        ASSERT_TRUE(arr[i] <= arr[i+1]);
}

TEST(Sort_tests, quick_test_not_trivial) {
    std::string arr[100];
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> uniform_dist(-10000, 10000);
    for(int t = 0; t < 100; t++) {
        arr[t] = std::to_string(uniform_dist(generator));
    }
    quick_sort(arr, arr+100, [](std::string a, std::string b) { return a < b; });
    for (int i = 0; i < 99; ++i)
        ASSERT_TRUE(arr[i] <= arr[i+1]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
