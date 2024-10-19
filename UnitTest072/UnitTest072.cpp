#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.2rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Декларація функції

namespace MyProjectTests
{
    TEST_CLASS(UnitTest072)
    {
    public:

        TEST_METHOD(TestFindMaxMinIndexes)
        {
            int row[] = { 5, 1, 9, 3, 7 };
            int n = sizeof(row) / sizeof(row[0]);
            int maxIndex = 0;
            int minIndex = 0;

            // Виклик функції для знаходження максимального та мінімального
            FindMaxMinInRow(row, n, maxIndex, minIndex, 1);

            // Перевірка результату
            Assert::AreEqual(2, maxIndex); // 9 - максимум, індекс 2
            Assert::AreEqual(1, minIndex); // 1 - мінімум, індекс 1
        }
    };
}
