#include <iostream>
using namespace std;

#include <string>
#include <vector>

class Anagram
{
	string hash;
	vector<string> inputs;

public:
	Anagram(string hashComputed, string input)
	{
		hash = hashComputed;
		inputs.push_back(input);
	}

	string GetHash()
	{
		return hash;
	}

	vector<string> GetInputs()
	{
		return inputs;
	}

	void AddInput(string input)
	{
		inputs.push_back(input);
	}
};

vector<Anagram *> Anagrams;

string GetHash(string input)
{
	string hash = "00000000000000000000000000";
	for (int i = 0; i < input.size(); i++)
	{
		hash.at((int)input[i] - 97) = (int)(hash.at((int)input[i] - 97))++;
	}

	return hash;
}

void Anagrams_main()
{
#pragma region Preparation

	vector<string> inputs = { "abab", "aabb", "ababa", "cinema", "iceman", "", "zoom", "omoz", "aaabb" };

#pragma endregion

#pragma region Execution

	//determining anagrams
	for (int i = 0; i < inputs.size(); i++)
	{
		string hash = GetHash(inputs[i]);

		if (Anagrams.size() == 0)
		{
			Anagrams.push_back(new Anagram(hash, inputs[i]));
		}
		else
		{
			for (int j = 0; j < Anagrams.size(); j++)
			{
				if (hash._Equal(Anagrams[j]->GetHash()))//hash found
				{
					Anagrams[j]->AddInput(inputs[i]);
					break;
				}

				if (j == Anagrams.size() - 1)//hash not found
				{
					Anagrams.push_back(new Anagram(hash, inputs[i]));
					break;
				}
			}
		}
	}

	//printing anagrams
	for (int i = 0; i < Anagrams.size(); i++)
	{
		cout << "hash: " << Anagrams[i]->GetHash() << "\n";

		cout << "inputs: ";
		for (int j = 0; j < Anagrams[i]->GetInputs().size(); j++)
			cout << Anagrams[i]->GetInputs()[j] << "\t";

		cout << "\n\n";
	}

#pragma endregion	
}