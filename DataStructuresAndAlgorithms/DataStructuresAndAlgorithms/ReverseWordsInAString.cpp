#include <iostream>
using namespace std;

#include <string>

string ReverseWord(string sentence, int start, int end)
{
	for (int i = 0; i <= (end - start) / 2; i++)
	{
		char temp = sentence[start + i];
		sentence[start + i] = sentence[end - i];
		sentence[end - i] = temp;
	}

	return sentence;
}

string ReverseWordsInAString(string sentence)
{
	int start = 0;
	int end = 0;

	while (end < sentence.length())
	{
		if (sentence[end] == ' ')
		{
			sentence = ReverseWord(sentence, start, end - 1);
			start = end + 1;
		}

		end++;
	}

	sentence = ReverseWord(sentence, start, end - 1);

	return sentence;
}

void ReverseWordsInAString_main()
{
#pragma region Preparation

	string sentence = "This is Dumpi solving the problem";

#pragma endregion

#pragma region Execution

	cout << ReverseWordsInAString(sentence);

#pragma endregion
}