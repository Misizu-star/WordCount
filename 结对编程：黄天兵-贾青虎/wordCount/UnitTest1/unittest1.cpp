#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\wordCount\wordCount.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(CharNum)
		{
			wordsCount test1("1.txt");
			wordsCount test2("2.txt");
			wordsCount test3("3.txt");
			wordsCount test4("4.txt");
			wordsCount test5("5.txt");
			Assert::AreEqual(556, test1.Char_num());
			Assert::AreEqual(533, test2.Char_num());
			Assert::AreEqual(379, test3.Char_num());
			Assert::AreEqual(481, test4.Char_num());
			Assert::AreEqual(529, test5.Char_num());
		}
		TEST_METHOD(WordsNum)
		{
			wordsCount test1("1.txt");
			wordsCount test2("2.txt");
			wordsCount test3("3.txt");
			wordsCount test4("4.txt");
			wordsCount test5("5.txt");
			Assert::AreEqual(41, test1.Words_num());
			Assert::AreEqual(44, test2.Words_num());
			Assert::AreEqual(39, test3.Words_num());
			Assert::AreEqual(48, test4.Words_num());
			Assert::AreEqual(49, test5.Words_num());
		}
		TEST_METHOD(LinesNum)
		{
			wordsCount test1("1.txt");
			wordsCount test2("2.txt");
			wordsCount test3("3.txt");
			wordsCount test4("4.txt");
			wordsCount test5("5.txt");
			Assert::AreEqual(2, test1.Lines_num());
			Assert::AreEqual(3, test2.Lines_num());
			Assert::AreEqual(3, test3.Lines_num());
			Assert::AreEqual(3, test4.Lines_num());
			Assert::AreEqual(3, test5.Lines_num());
		}

	};
}