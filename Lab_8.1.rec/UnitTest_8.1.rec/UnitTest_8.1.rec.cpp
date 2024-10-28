#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8.1.rec/Lab_8.1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81rec
{
    TEST_CLASS(UnitTest81rec)
    {
    public:

 
        TEST_METHOD(ChangeTest)
        {
            char str1[] = "a+bc-de+fg-hi+";
            char expected1[] = "+bc-de+fg-hi+";
            char dest1[151] = { '\0' };
            Change(dest1, str1, 1, 0);
            Assert::AreEqual(expected1, dest1);

            char str2[] = "abc+-def";
            char expected2[] = "bc+-def";
            char dest2[151] = { '\0' };
            Change(dest2, str2, 1, 0);
            Assert::AreEqual(expected2, dest2);

            char str3[] = "g+hi-j+k-l+";
            char expected3[] = "+hi-j+****l+";
            char dest3[151] = { '\0' };
            Change(dest3, str3, 1, 0);
            Assert::AreEqual(expected3, dest3);
        }

     
    };
}
