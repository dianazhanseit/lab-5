
#include <fstream>
#include <iostream>
#include <random>
#include <unordered_map>
#include <algorithm>

#include "listtest.h"
#include "vectortest.h"
#include "case_insensitive_cmp.h"
#include "hash.h"
#include "timer.h"
#include "lab5-test.cpp"
//#include "lab6-test.cpp"

// LAB-6 ********************************************************************************

// Subtask 1: Frequency table using map
std::map<std::string, unsigned int, case_insensitive_cmp> 
frequencytable(const std::vector<std::string> & text)
{
	std::map<std::string, unsigned int, case_insensitive_cmp> result {};
	for (const auto & item : text)
		result[item]++;
	return result;	
}

// Subtask 6: Frequency table using unordered map and hash
std::unordered_map<std::string, unsigned int, 
	case_insensitive_hash, case_insensitive_equality>
hashed_frequencytable( const std::vector< std::string > & text )
{
	std::unordered_map<std::string, unsigned int,
		 case_insensitive_hash, case_insensitive_equality> result {};
	for (const auto & item : text)
		result[item]++;
	return result;
}

// Subtask 2: Print Frequency table
// 1. Map
std::ostream& 
operator << ( std::ostream& out, const std::map< std::string, unsigned int, case_insensitive_cmp> & map ) 
{
	for( auto & elem : map)
	{
		out<<elem.first<<": "<<elem.second<<"\n";
	}
	return out;
}

// 2. Unordered map
std::ostream& 
operator << ( std::ostream& out, const std::unordered_map< std::string, unsigned int, 			case_insensitive_hash, case_insensitive_equality> & umap ) 
{
	for( auto & elem : umap)
	{
		out<<elem.first<<": "<<elem.second<<"\n";
	}
	return out;
}

void mapTest()
{
	std::ifstream inp {"test.txt" };
	auto word_vector = vectortest::readfile(inp);
	inp.close();
	std::map<std::string, unsigned int, case_insensitive_cmp> 
	freq = frequencytable(word_vector);
	std::cout << "Frequency table (map) with a size of "<<freq.size()<<": \n"<<freq<<"\n";
}
void hashTest()
{
	case_insensitive_hash h;
	std::cout<<"h(\"xxx\") is "<<h( "xxx" )<<"\n"<<"h(\"XXX\") is "<<h("XXX")<<"\n";
	std::cout<<"h(\"Abc\") is "<<h("Abc")<<"\n"<<"h(\"abC\") is "<<h("abC")<<"\n";

	case_insensitive_equality e;
	std::cout<<"Comparing sss and SSS (1 if equal): "<<e("sss","SSS")<<"\n";

	std::ifstream inp2 {"test.txt" };
	auto word_vector2 = vectortest::readfile(inp2);
	inp2.close();
	std::unordered_map<std::string, unsigned int, 
		case_insensitive_hash, case_insensitive_equality> 
	hashFreq = hashed_frequencytable(word_vector2);
	std::cout << "Frequency table (unordered map) with a size of "<<hashFreq.size()<<": 				\n"<<hashFreq<<"\n";	
}

// Returns an iterator to the string with the highest frequency value in the map,
// returns map.end() for undefined value
std::map<std::string, unsigned int,
	case_insensitive_cmp>::const_iterator
mostFrequent(std::map<std::string, unsigned int, case_insensitive_cmp> map)
{
	unsigned int max = 0;
	std::string word;
	std::map<std::string, unsigned int,
		case_insensitive_cmp>::const_iterator maxp;
	// auto can also be used for simplicity
	for(std::map<std::string, unsigned int,
		case_insensitive_cmp>::const_iterator
		p = map.begin(); p != map.end(); ++p)
	{
		if (p->second>max) {
			max = p -> second;
			maxp = p;
		}
	} 
	if(max>0) return maxp;
	else return map.end();
}

void bookFreqMap()
{
	std::cout << "Testing maps on 'Confessiones' book...\n";
	std::ifstream inp3 { "book1.txt" }; 
	auto book = vectortest::readfile(inp3);
	inp3.close();
	
	std::map<std::string, unsigned int, case_insensitive_cmp> 
	bf = frequencytable(book);
	std::cout<<"Frequency table (map) with a size of "<<bf.size()<<".\n";
	// std::cout<<bf<<"\n";

	std::vector<std::string> words = {"magnus", "hominum", "memoria"};
	for (const auto& word : words)
		std::cout<<word<<": "<<bf.at(word)<<"\n";

	auto it = mostFrequent(bf);
	if( it != bf.end())
		std::cout<<"The most frequent word in the map is '"
			 <<it->first<<"' and it appears there "<<it->second<<" times.\n";
	else std::cout<<"Something went wrong :("<<"\n";
}

void bookFreqUnorderedMap()
{
	std::cout<<"Testing maps on 'Confessiones' book...\n";
	std::ifstream inp3 {"book1.txt"}; 
	auto book = vectortest::readfile(inp3);
	inp3.close();
	
	std::unordered_map<std::string, unsigned int,
		case_insensitive_hash, case_insensitive_equality> 
	bhf = hashed_frequencytable(book);
	std::cout<<"Frequency table ( unordered map) with a size of "<<bhf.size()<<".\n";
	// std::cout<<bhf<<"\n";

	std::vector<std::string> words = {"magnus", "hominum", "memoria"};
	for (const auto& word : words)
		std::cout<<word<<": "<<bhf.at(word)<<"\n";

	unsigned int max = 0;
	std::string word;
	// auto can also be used for simplicity
	for( std::unordered_map<std::string, unsigned int,
		case_insensitive_hash, case_insensitive_equality>::const_iterator
		p = bhf.begin(); p != bhf.end(); ++p)
	{
		if (p -> second > max) {
			max = p -> second;
			word = p -> first;
		}
	}
	std::cout<<"The most frequent word in the book is "<<word<<" and it appears "
		 <<max<<" times.\n";

}

int main( int argc, char* argv [] )
{
//************ Lab 5. Vectors and Lists, Sorting algorithms ************
 	
	// Subtask 1: Testing readfile
	// readfileTest();
	
	// Subtask 2: Testing Pretty Print for vector and list
	// pprintTest(); 
	
	// Subtask 5: Testing the vectToList() function
	// vectorToListTest();
	
	// Subtask 4 and 6: Testing Sorting Algorithms for vector and list
	// sortingAlgsTest();


//************ Lab 6. Map and Unordered Map, Hash *********************** 
	

      	mapTest();
	hashTest();
	bookFreqMap();
	bookFreqUnorderedMap();	
	
	return 0; 
}


