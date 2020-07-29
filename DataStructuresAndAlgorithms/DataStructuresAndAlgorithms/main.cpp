#include <iostream>
using namespace std;

#pragma region Custom Headers

#include "DynamicProgramming.h"

#include "Heap.h"

#include "SLL.h"
#include "SLL_Problems.h"
#include "DLL.h"
#include "CLL.h"

#include "SAQueue.h"
#include "DAQueue.h"

#include "RandomProblems.h"

#include "RecursionAndBacktracking.h"

#include "Sorting.h"

#include "SAStack.h"
#include "DAStack.h"

#include "Strings.h"

#include "BinaryTrees_Problems.h"
#include "BinarySearchTrees_Problems.h"
#include "GenericT.h"
#include "TBT.h"

#pragma endregion

void main()
{
#pragma region Dynamic Programming
	
	//DP_Knapsack_0Or1_main();

	//DP_LongestIncreasingSubsequence_main();

	//DP_LongestSubsequence_main();

	//DP_Max_j_Minus_i_main();

	//DP_MaxActivities_main();

	//DP_MinCostToPaint_main();

#pragma endregion

#pragma region Heaps

	//Heap_InsertAndBuild_main();

#pragma endregion

#pragma region Linked Lists

#pragma region Single Linked Lists

	//SLL_BasicOperations_main();

	//SLL_AddingTwoLargeNumbers_main();

	//SLL_CloneWithRandomPointers_main();

	//SLL_FloydCFA_TortoiseAndHare_main();

	//SLL_MergingNode_main();

	//SLL_NthElementFromEnd_main();

	//SLL_ReverseList_main();

#pragma endregion

#pragma region Double Linked Lists

	//DLL_BasicOperations_main();

#pragma endregion

#pragma region Circular Linked Lists

	//CLL_BasicOperations_main();

#pragma endregion

#pragma endregion

#pragma region Queues

	//SAQ_BasicOperations_main();

	//DAQ_BasicOperations_main();

#pragma endregion

#pragma region Random Problems

	//Filter0sToTheLast_main();

	//KangarooOnXAxis_main();

	//kthSmallInTwoSortedArrays_main();

	//MaxConnectedRegion_main();

	//MaxContiguousOrNonContiguousSum_main();

	//MinJumpsToReachEnd_main();

	//ReverseWordsInAString_main();

	//Anagrams_main();

	//MedianOfTwoSortedArrays_main();

	//RegularExpression_main();

	//FilterDuplicatesToTheLastInSortedArray_main();

	//BinarySearch_main();

	//SearchInRotatedSortedArray_main();

	//FirstMissingPositive_main();

	//RotateMatrix_main();

	//LargestRectangleInHistogram_main();

	//WordLadder_main();

	//ProductOfArrayExceptItself_main();

	//MaxProductOf3Integers_main();

	//OverlappingAreaOf2Rectangles_main();

	ProductOfMinMax_main();

#pragma endregion

#pragma region Recursion & Backtracking

	//AllStringsGivenLength_main();

	//AllSubsetsOfASet_main();

	//BackTrack_AllStrings_main();

	//PrintNumbersBackwards_main();

	//R_CheckIfSorted_main();

	//R_Factorial_main();

#pragma endregion

#pragma region Sorting

	//BubbleSort_main();

	//InsertionSort_main();

	//QuickSort_main();

	//SelectionSort_main();

#pragma endregion

#pragma region Stacks

	//SAS_BasicOperations_main();
	
	//DAS_BasicOperations_main();

#pragma endregion

#pragma region Strings

	//KMP_main();

	//NaivePatternMatching_main();

#pragma endregion

#pragma region Trees

#pragma region Binary Trees

	//BT_DeepestNode_main();

	//BT_DiameterOrWidth_main();

	//BT_FullHalfAndLeafNodes_main();

	//BT_Height_OR_Depth_main();

	//BT_kSumPaths_main();

	//BT_LeftOrRight_main();

	//BT_LevelOrderTraversal_main();

	//BT_LevelOrderTraversalReverse_main();

	//BT_LowestCommonAncestor_main();

	//BT_Mirror_main();

	//BT_NodesAtDistanceK_main();

	//BT_NonRecursiveTraversals_main();

	//BT_RecursiveTraversals_main();

	//BT_RootLeafPaths_main();

	//BT_SearchElementRecursive_main();

	//BT_SizeRecursive_main();

	//BT_Sum_Max_Min_main();

	//BT_SumOfEachLevel_main();

	//BT_VerticalSum_main();

	//BTNQ_BasicOperations_main();

	//BTNS_BasicOperations_main();

#pragma endregion

#pragma region Binary Search Trees

	//BST_CheckIfBST_main();

	//BST_ClosestElementToKey_main();

	//BST_DeleteElement_main();

	//BST_FindElement_main();

	//BST_FindMaximum_main();

	//BST_FindMinimum_main();

	//BST_InsertElement_main();

	//BST_KthSmallestElement_main();

	//BST_LCA_ShortestPath_main();

	//BST_Swap2Bad_main();

#pragma endregion

#pragma region Generic Trees

	//GT_HeightOrDepth_main();

	//GT_NumOfChildren_main();

	//GT_NumOfSiblings_main();

	//GT_SumOfElements_main();

#pragma endregion

#pragma region Threaded Binary Trees

	//TBT_Creation_main();

#pragma endregion

#pragma endregion

	//Just to stop the console
	char blah;
	cout << "\nPress any key to exit:\n";
	cin >> blah;
}