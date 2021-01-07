#pragma once

// std::unordered_map
// --------------------------------------------
// --------------------------------------------

#ifdef UNORDERED_MAP_I

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map> 

int main()
{
	// Declaring umap to be of <string, int> type 
	// key value : string type
	// mapped value : int type 
	std::unordered_map<string, int> umap;

	// inserting values by using [] operator 
	umap["GeeksforGeeks"] = 10;
	umap["Practice"] = 20;
	umap["Contribute"] = 30;

	// Traversing an unordered map 
	for (auto x : umap)
		std::cout << x.first << " " << x.second << std::endl;
	return 0;

	/*
		GeeksforGeeks 10
		Practice 20
		Contribute 30
	*/

	
}

#endif // UNORDERED_MAP_I

// --------------------------------------------
// --------------------------------------------

#ifdef UNORDERED_MAP_II

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map> 

int main() {

	// Declaring umap to be of <string, double> type 
	// key value: string type 
	// mapped value : double type 
	std::unordered_map<string, double> umap;

	// inserting values by using [] operator 
	umap["PI"] = 3.14;
	umap["root2"] = 1.414;
	umap["root3"] = 1.732;
	umap["log10"] = 2.302;
	umap["loge"] = 1.0;

	// inserting value by insert function 
	umap.insert(make_pair("e", 2.718));

	string key = "PI";

	// If key not found in map iterator to end is returned 
	if (umap.find(key) == umap.end())
		std::cout << key << " not found\n\n";
	else
		std::cout << "Found " << key << "\n\n";
	key = "lambda";
	if (umap.find(key) == umap.end())
		std::cout << key << " not found\n";
	else
		std::cout << "Found " << key << std::endl;

	// iterating over all value of umap 
	// unordered_map<string, double>::iterator itr;
	std::cout << "\nAll Elements : \n";
	for (auto itr = umap.begin(); itr != umap.end(); itr++)	{
		// itr works as a pointer to pair<string, double>
		// type itr->first stores the key part and 
		// itr->second stroes the value part 
		std::cout << itr->first << " " << itr->second << std::endl;
	}

	return 0;

	/*
	 	Found PI

		lambda not found

		All Elements :
		root3 1.732
		PI 3.14
		root2 1.414
		e 2.718
		log10 2.302
		loge 1
	*/
}

#endif // UNORDERED_MAP_II

// TO BE CONTROLLED
// A practical problem based on unordered_map – given a string of words, find frequencies of individual words
// --------------------------------------------
// --------------------------------------------

#ifdef UNORDERED_MAP_III

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map> 

// Prints frequencies of individual words in str 
void printFrequencies(const string& str)
{
	// declaring map of <string, int> type, each word 
	// is mapped to its frequency 
	std::unordered_map<string, int> wordFreq;

	// breaking input into word using string stream 
	stringstream ss(str); // Used for breaking words 
	string word; // To store individual words 
	while (ss >> word)
		wordFreq[word]++;

	// now iterating over word, freq pair and printing 
	// them in <, > format 
	std::unordered_map<string, int>::iterator p;
	for (p = wordFreq.begin(); p != wordFreq.end(); p++)
		std::cout << "(" << p->first << ", " << p->second << ")\n";
}

int main(){

	std::string str = "geeks for geeks geeks quiz "
		"practice qa for";
	printFrequencies(str);
	return 0;
}

#endif // UNORDERED_MAP_III

// --------------------------------------------
// --------------------------------------------