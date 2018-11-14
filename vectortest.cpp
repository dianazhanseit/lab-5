
#include "vectortest.h"
#include "timer.h"
#include <random>
#include <chrono> 
#include <algorithm>
#include <cctype>

std::vector< std::string >
vectortest::randomstrings( size_t nr, size_t s )
{
   static std::default_random_engine gen( 
      std::chrono::system_clock::now( ). time_since_epoch( ). count( ) );
         // Narrowing long int into int, but that is no problem.

   static std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345689";
   static std::uniform_int_distribution<int> distr( 0, alphabet. size( ) - 1 );
      // More narrowing.

   std::vector< std::string > res;
   for( size_t i = 0; i < nr; ++ i )
   {
      std::string rand;
      for( size_t j = 0; j < s; ++ j )
      {
         rand. push_back( alphabet[ distr( gen ) ] );  
      }

      res. push_back( std::move( rand ));
   }
   return res;
}
// Subtask 1: readfile 
// Reads from input and creates vector of all words in input   
std::vector<std::string> 
vectortest::readfile( std::istream& input ) 
{
	std::vector<std::string> vect;
	std::string str;
	char c;
	while ((input.get(c)).good()) {
		if(isalpha(c)){
			str.push_back(c);
		} 
		else if(str.size()) {
			vect.push_back(str);
			str = "";
		}
	}

        return vect;

}
// Subtask 2: pretty printing for vector
std::ostream& 
operator << ( std::ostream& out, const std::vector< std::string > & vect ) 
{ 
	out<< "{ ";
	for(std::vector<std::string> :: const_iterator
		p = vect.begin();
		p != vect.end();
		++p )
	{
		if( p != vect.begin())
			out<<", ";
		out<<"\""<< *p <<"\"";	
	}
	return out<<" }\n";
}

// Subtask 3: Sorting algorithms
// Exchanges strings by usual assignment
void vectortest::sort_assign( std::vector< std::string > & v )
{
	timer t("vector sort_assign", std::cout);
	for (size_t j = 0; j<v.size(); ++j) {
		for (size_t i = 0; i<j; ++i) {
			if (v[j] < v[i]) {
				std::string s = v[i];
				v[i] = v[j];
				v[j] = s;
			}
		}
	}
}
// Uses std::swap: exchanges pointers
void vectortest::sort_move( std::vector< std::string > & v )
{	
	timer t("vector sort_move", std::cout);
	for (size_t j = 0; j<v.size(); ++j) {
		for (size_t i = 0; i<j; ++i) {
			if (v[j] < v[i])
				std::swap(v[i], v[j]);
		}
	}
	// does timer destuct here???
}
// Quicksort algorithm
void vectortest::sort_std( std::vector< std::string > & v )
{
	timer t("vector quicksort", std::cout);
	std::sort(v.begin(), v.end());
}







