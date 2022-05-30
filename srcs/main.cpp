#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map/map.hpp>
	#include <stack/stack.hpp>
	#include <vector/vector.hpp>
#endif

#include <stdlib.h>

std::ostream&	operator<<(std::ostream& o, ft::vector<int> const& v)
{
	o << "[ ";
	for (ft::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		o << *it << " ";
	o << "]" << std::endl;
	return o;
}

int main(void)
{
	ft::vector<int>	vect;
	ft::vector<int>	vect2;
	
	vect2.insert(vect2.begin(), 5);
	vect2.insert(vect2.begin(), 4);
	vect2.insert(vect2.begin(), 3);
	vect2.insert(vect2.begin(), 2);
	vect2.insert(vect2.begin(), 1);

	std::cout << "*-+-+-*" << std::endl;
	std::cout << "|E|C|S|" << std::endl;
	std::cout << "|M|A|I|" << std::endl;
	std::cout << "|P|P|Z|		VECTOR		|" << std::endl;
	std::cout << "|T|A|E|" << std::endl;
	std::cout << "|Y|C| |" << std::endl;
	std::cout << "*-+-+-*" << std::endl;


	std::cout << "|" << vect.empty() << "|" << vect.capacity() << "|" << vect.size() << "|	" << vect;
	std::cout << "INSERT" << std::endl;
	vect.insert(vect.begin(), 1);
	std::cout << "|" << vect.empty() << "|" << vect.capacity() << "|" << vect.size() << "|	" << vect;
	std::cout << "PUSHBACK" << std::endl;
	vect.push_back(2);
	std::cout << "|" << vect.empty() << "|" << vect.capacity() << "|" << vect.size() << "|	" << vect;
	std::cout << "INSERT" << std::endl;
	vect.insert(vect.begin(), 2);
	std::cout << "|" << vect.empty() << "|" << vect.capacity() << "|" << vect.size() << "|	" << vect;
	std::cout << "SWAP" << std::endl;
	vect.swap(vect2);
	std::cout << "|" << vect.empty() << "|" << vect.capacity() << "|" << vect.size() << "|	" << vect;
	std::cout << "EMPLACE_BACK" << std::endl;
	// vect.emplace_back(5);
	std::cout << "|" << vect.empty() << "|" << vect.capacity() << "|" << vect.size() << "|	" << vect;
	std::cout << "CLEAR" << std::endl;
	vect.clear();
	std::cout << "|" << vect.empty() << "|" << vect.capacity() << "|" << vect.size() << "|	" << vect;
	

	return 0;
}
/*
#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}
*/