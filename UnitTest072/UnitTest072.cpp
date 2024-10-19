#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.2rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// ���������� �������

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

            // ������ ������� ��� ����������� ������������� �� ����������
            FindMaxMinInRow(row, n, maxIndex, minIndex, 1);

            // �������� ����������
            Assert::AreEqual(2, maxIndex); // 9 - ��������, ������ 2
            Assert::AreEqual(1, minIndex); // 1 - �����, ������ 1
        }
    };
}
