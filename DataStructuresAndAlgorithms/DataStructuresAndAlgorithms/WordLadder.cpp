#include <iostream>
using namespace std;

#include <vector>

#include "RandomProblems.h"

//-------------------------------------------------------------------------
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(vector<int> dist, vector<bool> visited)
{
	// Initialize min value 
	int min = INT_MAX, min_index;

	for (int v = 0; v < dist.size(); v++)
		if (visited[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array 
void printSolution(vector<int> dist)
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < dist.size(); i++)
		cout << i << "\t\t" << dist[i] << "\n";
}

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
vector<int> dijkstra(vector<vector<int>> graph, int src)
{
	vector<int> dist; // The output array.  dist[i] will hold the shortest 
	// distance from src to i 
	dist.resize(graph.size());

	vector<bool> visited; // visited[i] will be true if vertex i is included in shortest 
	// path tree or shortest distance from src to i is finalized 
	visited.resize(graph.size());

	// Initialize all distances as INFINITE and stpSet[] as false 
	for (int i = 0; i < graph.size(); i++)
		dist[i] = INT_MAX, visited[i] = false;

	// Distance of source vertex from itself is always 0 
	dist[src] = 0;

	// Find shortest path for all vertices 
	for (int count = 0; count < graph.size() - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not 
		// yet processed. u is always equal to src in the first iteration. 
		int u = minDistance(dist, visited);

		// Mark the picked vertex as processed 
		visited[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex. 
		for (int v = 0; v < graph.size(); v++)

			// Update dist[v] only if is not in visited, there is an edge from 
			// u to v, and total weight of path from src to  v through u is 
			// smaller than current value of dist[v] 
			if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array 
	printSolution(dist);

	return dist;
}
//-------------------------------------------------------------------------


bool DifferByOneChar(string str1, string str2)
{
	int different = 0;

	for (int i = 0; i < str1.size(); i++)
	{
		if (str1.at(i) != str2.at(i))
			different++;
	}

	return (different == 1) ? true : false;
}

int WordLadder(string beginWord, string endWord, vector<string> wordList)
{
	int endWordIndex = 0;
	for (int i = 0; i < wordList.size(); i++)
	{
		if (wordList[i] == endWord)
		{
			endWordIndex = i;
			break;
		}

		if (i == wordList.size() - 1)
			return 0;
	}
	
	wordList.push_back(beginWord);

	vector<vector<int>> WithinOneChar;
	WithinOneChar.resize(wordList.size());

	for (int i = 0; i < wordList.size(); i++)
		WithinOneChar[i].resize(wordList.size());

	for (int i = 0; i < wordList.size(); i++)
		for (int j = 0; j < wordList.size(); j++)
			WithinOneChar[i][j] = -1;

	for (int i = 0; i < wordList.size(); i++)
		for (int j = 0; j < wordList.size(); j++)
		{
			if (i == j)
				WithinOneChar[i][j] = 0;

			if (WithinOneChar[i][j] == -1 && WithinOneChar[j][i] == -1)
				WithinOneChar[i][j] = DifferByOneChar(wordList[i], wordList[j]);
			else
				WithinOneChar[i][j] = WithinOneChar[j][i];
		}
	
	printMatrix(WithinOneChar);

	vector<int> dist = dijkstra(WithinOneChar, WithinOneChar.size() - 1);

	return (dist.at(endWordIndex)!= INT_MAX)? dist.at(endWordIndex):0;
}

void WordLadder_main()
{
	/*
	Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

	Only one letter can be changed at a time.
	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
	Note:

	Return 0 if there is no such transformation sequence.
	All words have the same length.
	All words contain only lowercase alphabetic characters.
	You may assume no duplicates in the word list.
	You may assume beginWord and endWord are non-empty and are not the same.
	Example 1:

	Input:
	beginWord = "hit",
	endWord = "cog",
	wordList = ["hot","dot","dog","lot","log","cog"]

	Output: 5

	Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
	return its length 5.
	Example 2:

	Input:
	beginWord = "hit"
	endWord = "cog"
	wordList = ["hot","dot","dog","lot","log"]

	Output: 0

	Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
	*/

#pragma region Preparation

	string beginWord = "hit", endWord = "cog";
	vector<string>wordList = { "hot", "bot", "dot", "dog", "rot", "lot", "log", "cog" };

#pragma endregion

#pragma region Execution

	cout << "Shortest ladder length = " << WordLadder(beginWord, endWord, wordList) << "\n";

#pragma endregion	

#pragma region Preparation

	beginWord = "hit"; endWord = "cog";
	wordList = { "bot", "dot", "dog", "rot", "lot", "log", "cog" };

#pragma endregion

#pragma region Execution

	cout << "Shortest ladder length = " << WordLadder(beginWord, endWord, wordList) << "\n";

#pragma endregion	
}