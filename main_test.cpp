#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <stack>

std::ostream&	operator<<(std::ostream& o, std::vector<int> const& v)
{
	o << "[ ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		o << *it << " ";
	o << "]" << std::endl;
	return o;
}

int main(void)
{
	std::vector<int>	vect;
	std::vector<int>	vect2;
	
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


	std::cout << "|" << vect2.empty() << "|" << vect2.capacity() << "|" << vect2.size() << "|	" << vect2;
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
	std::cout << "RESERVE" << std::endl;
	vect.reserve(10);
	std::cout << "|" << vect.empty() << "|" << vect.capacity() << "|" << vect.size() << "|	" << vect;
	std::cout << "RESIZE" << std::endl;
	std::vector<int>	myvector;
	for (int i=1;i<8;i++)
		myvector.push_back(i);
	myvector.resize(5);
	std::cout << "|" << myvector.empty() << "|" << myvector.capacity() << "|" << myvector.size() << "|	" << myvector;
	myvector.resize(8,100);
	std::cout << "|" << myvector.empty() << "|" << myvector.capacity() << "|" << myvector.size() << "|	" << myvector;
	myvector.resize(12);
	std::cout << "|" << myvector.empty() << "|" << myvector.capacity() << "|" << myvector.size() << "|	" << myvector;
/*
*/	

	return 0;
}
