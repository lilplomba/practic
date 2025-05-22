#include "CppUnitTest.h"
#include <vector>
#include "C:\Users\Егор\source\repos\ConsoleApplication19\ConsoleApplication19\largest_divisible_subset.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LargestDivisibleSubsetTests
{
    TEST_CLASS(LargestDivisibleSubsetTests)
    {
    public:

        TEST_METHOD(BasicCases)
        {
            std::vector<int> nums1 = { 1, 2, 3 };
            std::vector<int> expected1a = { 1, 2 };
            std::vector<int> expected1b = { 1, 3 };
            std::vector<int> result1 = largestDivisibleSubset(nums1);
            Assert::IsTrue(result1 == expected1a || result1 == expected1b);

            std::vector<int> nums2 = { 1, 2, 4, 8 };
            std::vector<int> expected2 = { 1, 2, 4, 8 };
            std::vector<int> result2 = largestDivisibleSubset(nums2);
            Assert::AreEqual(expected2.size(), result2.size());
            for (size_t i = 0; i < expected2.size(); ++i) {
                Assert::AreEqual(expected2[i], result2[i]);
            }
        }

        TEST_METHOD(SingleElement)
        {
            std::vector<int> nums = { 5 };
            std::vector<int> expected = { 5 };
            std::vector<int> result = largestDivisibleSubset(nums);
            Assert::AreEqual(expected.size(), result.size());
            Assert::AreEqual(expected[0], result[0]);
        }

        TEST_METHOD(EmptyInput)
        {
            std::vector<int> nums = {};
            std::vector<int> expected = {};
            std::vector<int> result = largestDivisibleSubset(nums);
            Assert::AreEqual(expected.size(), result.size());
        }

        TEST_METHOD(NoDivisiblePairs)
        {
            std::vector<int> nums = { 2, 3, 5, 7, 11 };
            std::vector<int> result = largestDivisibleSubset(nums);
            Assert::AreEqual(1, (int)result.size());
            bool found = false;
            for (int num : nums) {
                if (num == result[0]) {
                    found = true;
                    break;
                }
            }
            Assert::IsTrue(found);
        }

        TEST_METHOD(LargeNumbers)
        {
            std::vector<int> nums = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };
            std::vector<int> expected = nums;
            std::vector<int> result = largestDivisibleSubset(nums);
            Assert::AreEqual(expected.size(), result.size());
            for (size_t i = 0; i < expected.size(); ++i) {
                Assert::AreEqual(expected[i], result[i]);
            }
        }

        TEST_METHOD(MixedNumbers)
        {
            std::vector<int> nums = { 3, 4, 6, 8, 12, 16, 24 };
            std::vector<int> expected1 = { 4, 8, 16, 24 };
            std::vector<int> expected2 = { 3, 6, 12, 24 };
            std::vector<int> result = largestDivisibleSubset(nums);
            bool matches = (result == expected1) || (result == expected2);
            Assert::IsTrue(matches);
        }
    };
}