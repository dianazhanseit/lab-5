void readfileTest()
{
	std::ifstream inp { "test.txt" }; // open file to read from
	auto word_vector = vectortest::readfile(inp);
	std::cout << word_vector;
	inp.close(); // close file
}
void pprintTest()
{
	std::cout<<"Testing pretty print for vector:\n";
	for( size_t i; i != 5; i++)
	{
		std::vector< std::string > v1;
	        v1 = vectortest::randomstrings(i, 10);
		std::cout<<"Length = "<<i<<": "<<v1<<"\n";
	}
	
	std::cout<<"Testing pretty print for list:\n";
	for( size_t j; j != 5; j++)
	{
		std::list< std::string > l1;
	        l1 = listtest::randomstrings(j, 10);
		std::cout<<"Length = "<<j<<": "<<l1<<"\n";
	}
}
void vectorSortMove(size_t nr, size_t s)
{
	std::vector< std::string > vect;
	vect = vectortest::randomstrings(nr, s);
	vectortest::sort_move( vect );
}
void vectorSortAssign(size_t nr, size_t s)
{
	std::vector< std::string > vect;
	vect = vectortest::randomstrings(nr, s);
	vectortest::sort_assign( vect );
}
void vectorQuicksort(size_t nr, size_t s)
{
	std::vector< std::string > vect;
	vect = vectortest::randomstrings(nr, s);
	vectortest::sort_std( vect );
}
void listSortMove(size_t nr, size_t s)
{
	std::list< std::string > l1;
	l1 = listtest::randomstrings(nr, s);
	listtest::sort_move( l1 );
}
void listSortAssign(size_t nr, size_t s)
{
	std::list< std::string > l2;
	l2 = listtest::randomstrings(nr, s);
	listtest::sort_assign( l2 );
}

// Converts a vector of strings to a list of strings
std::list<std::string> 
vectorToList(std::vector<std::string> vect) 
{
	std::list<std::string> l;
	for(std::vector<std::string> :: const_iterator
		p = vect.begin();
		p != vect.end();
		++p )
		{
			l.push_back(*p);
		}
	return l;
}


void sortingAlgsTest()
{
	for(size_t nr = 5000; nr <=30000; nr+=5000){
		std::cout<<"\n************for nr = "<<nr<<"***************\n";
		listSortMove(nr, 50);
		listSortAssign(nr, 50);
		vectorSortMove(nr, 50);
	   	vectorSortAssign(nr, 50);
		vectorQuicksort(nr, 50);
	}
}


void vectorToListTest()
{
	std::vector<std::string> v1;
	v1 = vectortest::randomstrings(20, 10);
	std::cout<<"----------Unsorted Vector:\n"<<v1<<"\n";

        std::list< std::string > l1;
	l1 = vectorToList(v1);
	std::cout<<"----------Unsorted List:\n"<<l1<<"\n";	
	
	vectortest::sort_move( v1 );
	std::cout<<"----------Sorted Vector:\n"<<v1<<"\n";	
	
	listtest::sort_move( l1 );
	std::cout<<"----------Sorted List:\n"<<l1;
  	
}

