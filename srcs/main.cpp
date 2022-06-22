#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
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

void	legende() {
	std::cout << "*---+---+---*" << std::endl;
	std::cout << "| E | C | S |" << std::endl;
	std::cout << "| M | A | I |" << std::endl;
	std::cout << "| P | P | Z |		VECTOR		|" << std::endl;
	std::cout << "| T | A | E |" << std::endl;
	std::cout << "| Y | C |   |" << std::endl;
	std::cout << "*---+---+---*" << std::endl;
}
std::ostream&	operator<<(std::ostream& o, ft::vector<int>& v)
{
	o << "[ ";
	for (ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		o << *it << " ";
	o << "]" << std::endl;
	return o;
}
std::ostream&	operator<<(std::ostream& o, const ft::vector<int>& v)
{
	o << "[ ";
	for (ft::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		o << *it << " ";
	o << "]" << std::endl;
	return o;
}
void	prepost_incdec(ft::vector<int> &vct)
{
	ft::vector<int>::iterator it = vct.begin();
	ft::vector<int>::iterator it_tmp;

	std::cout << "Pre inc" << std::endl;
	it_tmp = ++it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Pre dec" << std::endl;
	it_tmp = --it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post inc" << std::endl;
	it_tmp = it++;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post dec" << std::endl;
	it_tmp = it--;
	std::cout << *it_tmp << " | " << *it << std::endl;
	std::cout << "###############################################" << std::endl;
}

// template <typename Ite_1, typename Ite_2>
// void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
// {
// 	std::cout << (first < second) << std::endl;
// 	std::cout << (first <= second) << std::endl;
// 	std::cout << (first > second) << std::endl;
// 	std::cout << (first >= second) << std::endl;
// 	if (redo)
// 		ft_eq_ope(second, first, 0);
// }

int main(void)
{
	
/*
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TEST ITERATOR VECTOR" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	legende();
	const int vsize = 5;

	ft::vector<int> iter_vct(vsize);
	ft::vector<int>::iterator itv = iter_vct.begin();
	ft::vector<int>::const_iterator ite = iter_vct.begin();

	std::cout << "| " << iter_vct.empty() << " | " << iter_vct.capacity() << " | " << iter_vct.size() << "|	" << iter_vct<< std::endl;
	for (int i = 0; i < vsize; ++i)
		itv[i] = (vsize - i) * 5;
	prepost_incdec(iter_vct);

	itv = itv + 5;
	itv = 1 + itv;
	itv = itv - 4;
	std::cout << *(itv += 2) << std::endl;
	std::cout << *(itv -= 1) << std::endl;

	*(itv -= 2) = 42;
	*(itv += 2) = 21;

	std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
	std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;
	std::cout << "(it == const_it): " << (ite == itv) << std::endl;
	std::cout << "(const_ite - it): " << (ite - itv) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == itv) << std::endl;

	std::cout << "| " << iter_vct.empty() << " | " << iter_vct.capacity() << " | " << iter_vct.size() << "|	" << iter_vct<< std::endl;

	std::cout << "----------------------------------" << std::endl;
	std::cout << "TEST ITERATOR VECTOR ARROW" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	const int size = 5;

	ft::vector<int> vctv2(size);
	ft::vector<int>::iterator itv2(vctv2.begin());
	ft::vector<int>::const_iterator itev2(vctv2.end());

	for (int i = 1; itv2 != itev2; ++i)
		*itv2++ = i;
	std::cout << "| " << vctv2.empty() << " | " << vctv2.capacity() << " | " << vctv2.size() << "|	" << vctv2 << std::endl;

	itv2 = vctv2.begin();
	itev2 = vctv2.begin();

	std::cout << *(++itev2) << std::endl;
	std::cout << *(itev2++) << std::endl;
	std::cout << *itev2++ << std::endl;
	std::cout << *++itev2 << std::endl;

	// itv2->m();
	// itev2->m();

	std::cout << *(++itv2) << std::endl;
	std::cout << *(itv2++) << std::endl;
	std::cout << *itv2++ << std::endl;
	std::cout << *++itv2 << std::endl;

	std::cout << *(--itev2) << std::endl;
	std::cout << *(itev2--) << std::endl;
	std::cout << *--itev2 << std::endl;
	std::cout << *itev2-- << std::endl;

	// (*itv2).m();
	// (*itev2).m();

	std::cout << *(--itv2) << std::endl;
	std::cout << *(itv2--) << std::endl;
	std::cout << *itv2-- << std::endl;
	std::cout << *--itv2 << std::endl;
*/
//	std::cout << "----------------------------------" << std::endl;
//	std::cout << "TEST ITERATOR EQ_OPE" << std::endl;
//	std::cout << "----------------------------------" << std::endl;
//	const int size_op = 5;
//
//	ft::vector<int> vectour(size_op);
//	ft::vector<int>::iterator it_0(vectour.begin());
//	ft::vector<int>::iterator it_1(vectour.end());
//	ft::vector<int>::iterator it_mid;
//
//	ft::vector<int>::const_iterator cit_0 = vectour.begin();
//	ft::vector<int>::const_iterator cit_1;
//	ft::vector<int>::const_iterator cit_mid;
//
//	for (int i = size_op; it_0 != it_1; --i)
//		*it_0++ = i;
//	std::cout << "| " << vectour.empty() << " | " << vectour.capacity() << " | " << vectour.size() << "|	" << vectour << std::endl;
//	it_0 = vectour.begin();
//	cit_1 = vectour.end();
//	it_mid = it_0 + 3;
//	cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;
//
//	// std::cout << std::boolalpha;
//	std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;
//
//	std::cout << "\t\tft_eq_ope:" << std::endl;
//	// regular it
//	ft_eq_ope(it_0 + 3, it_mid);
//	ft_eq_ope(it_0, it_1);
//	ft_eq_ope(it_1 - 3, it_mid);
//	// const it
//	ft_eq_ope(cit_0 + 3, cit_mid);
//	ft_eq_ope(cit_0, cit_1);
//	ft_eq_ope(cit_1 - 3, cit_mid);
//	// both it
//	ft_eq_ope(it_0 + 3, cit_mid);
//	ft_eq_ope(it_mid, cit_0 + 3);
//	ft_eq_ope(it_0, cit_1);
//	ft_eq_ope(it_1, cit_0);
//	ft_eq_ope(it_1 - 3, cit_mid);
//	ft_eq_ope(it_mid, cit_1 - 3);
	std::cout << "----------------------------------" << std::endl;
	std::cout << "BOUCLE DE REMPLISSAGE" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	const int start_size = 7;

	ft::vector<int> vct(start_size, 20);
	ft::vector<int> copy_test;
	ft::vector<int>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
	{
		std::cout << "| " << vct.empty() << " | " << vct.capacity() << " | " << vct.size() << "|	" << vct << std::endl;
		vct.insert(vct.begin(), (start_size - i) * 3);
		// it = (start_size - i) * 3;
		it++;
	}
	// std::cout << "----------------------------------" << std::endl;
	// ft::vector<int> vctest(12, 20);
	// std::cout << "| " << vctest.empty() << " | " << vctest.capacity() << " | " << vctest.size() << "|	" << vctest << std::endl;


	std::cout << "----------------------------------" << std::endl;
	std::cout << "TEST ==> COPY & SWAP" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TEST_COPY(with =)" << std::endl;
	copy_test = vct;
	std::cout << "| " << copy_test.empty() << " | " << copy_test.capacity() << " | " << copy_test.size() << "|	" << copy_test << std::endl;

	std::cout << "TEST_COPY(constructor)" << std::endl;
	ft::vector<int> copy_test2(vct);

	std::cout << "| " << copy_test2.empty() << " | " << copy_test2.capacity() << " | " << copy_test2.size() << "|	" << copy_test2 << std::endl;
	std::cout << "copy to" << std::endl;
	std::cout << "| " << vct.empty() << " | " << vct.capacity() << " | " << vct.size() << "|	" << vct << std::endl;
	copy_test2.swap(vct);
	std::cout << "copy.swap(vct)" << std::endl;
	std::cout << "| " << copy_test2.empty() << " | " << copy_test2.capacity() << " | " << copy_test2.size() << "|	" << copy_test2 << std::endl;
	std::cout << "----------------------------------" << std::endl;

	ft::vector < int >				vctouille(5);
	ft::vector < int >::iterator	itouille = vctouille.end();

	int i = 0;
	for (ft::vector<int>::iterator it = vctouille.begin(); it != vctouille.end(); ++it) {i++;}
	std::cout << "len: " << i << std::endl;
	for (ft::vector < int >::iterator itouill = vctouille.begin(); itouill != itouille; ++itouill)
		*itouill = (itouille - itouill);
// 
	ft::vector<int> vct_range(vctouille.begin(), --(--vctouille.end()));
	for (ft::vector < int >::iterator itouill = vctouille.begin(); itouill != itouille; ++itouill)
		*itouill = ++i * 5;

	i = 0;
	ft::vector<int> vct_cpy(vct);
	for (ft::vector < int >::iterator itouill = vctouille.begin(); itouill != itouille; ++itouill)
		*itouill = ++i * 7;
	// vct_cpy.push_back(42);
	// vct_cpy.push_back(21);

	std::cout << "\t-- PART ONE --" << std::endl;
	std::cout << "| " << vctouille.empty() << " | " << vctouille.capacity() << " | " << vctouille.size() << "|	" << vctouille << std::endl;
	std::cout << "| " << vct_range.empty() << " | " << vct_range.capacity() << " | " << vct_range.size() << "|	" << vct_range << std::endl;
	std::cout << "| " << vct_cpy.empty() << " | " << vct_cpy.capacity() << " | " << vct_cpy.size() << "|	" << vct_cpy << std::endl;

	// vctouille = vct_cpy;
	// vct_cpy = vct_range;
	// vct_range.clear();
// 
	// std::cout << "\t-- PART TWO --" << std::endl;
	// std::cout << "| " << vctouille.empty() << " | " << vctouille.capacity() << " | " << vctouille.size() << "|	" << vctouille << std::endl;
	// std::cout << "| " << vct_range.empty() << " | " << vct_range.capacity() << " | " << vct_range.size() << "|	" << vct_range << std::endl;
	// std::cout << "| " << vct_cpy.empty() << " | " << vct_cpy.capacity() << " | " << vct_cpy.size() << "|	" << vct_cpy << std::endl;
// 
	// ft::vector<int> foo(3, 15);
	// ft::vector<int> bar(5, 42);
	// ft::vector<int>::iterator it_foo = foo.begin();
	// ft::vector<int>::iterator it_bar = bar.begin();
// 
	// std::cout << "BEFORE SWAP" << std::endl;
	// std::cout << "foo contains:" << std::endl;
	// std::cout << "| " << foo.empty() << " | " << foo.capacity() << " | " << foo.size() << "|	" << foo << std::endl;
	// std::cout << "bar contains:" << std::endl;
	// std::cout << "| " << bar.empty() << " | " << bar.capacity() << " | " << bar.size() << "|	" << bar << std::endl;
// 
	// foo.swap(bar);
// 
	// std::cout << "AFTER SWAP" << std::endl;
	// std::cout << "foo contains:" << std::endl;
	// std::cout << "| " << foo.empty() << " | " << foo.capacity() << " | " << foo.size() << "|	" << foo << std::endl;
	// std::cout << "bar contains:" << std::endl;
	// std::cout << "| " << bar.empty() << " | " << bar.capacity() << " | " << bar.size() << "|	" << bar << std::endl;
// 
	// std::cout << "Iterator validity:" << std::endl;
	// std::cout << (it_foo == bar.begin()) << std::endl;
	// std::cout << (it_bar == foo.begin()) << std::endl;

	std::cout << "----------------------------------" << std::endl;
	std::cout << "TEST ==> ?" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	vct.resize(10, 42);
	std::cout << "| " << vct.empty() << " | " << vct.capacity() << " | " << vct.size() << "|	" << vct << std::endl;
	vct.resize(18, 43);
	std::cout << "| " << vct.empty() << " | " << vct.capacity() << " | " << vct.size() << "|	" << vct << std::endl;
	vct.resize(10);
	std::cout << "| " << vct.empty() << " | " << vct.capacity() << " | " << vct.size() << "|	" << vct << std::endl;
	vct.resize(23, 44);
	std::cout << "| " << vct.empty() << " | " << vct.capacity() << " | " << vct.size() << "|	" << vct << std::endl;
	vct.resize(5);
	std::cout << "| " << vct.empty() << " | " << vct.capacity() << " | " << vct.size() << "|	" << vct << std::endl;
	vct.reserve(5);
	std::cout << "| " << vct.empty() << " | " << vct.capacity() << " | " << vct.size() << "|	" << vct << std::endl;
	vct.reserve(3);
	std::cout << "| " << vct.empty() << " | " << vct.capacity() << " | " << vct.size() << "|	" << vct << std::endl;
	std::cout << "RESIZE(87)" << std::endl;
	vct.resize(87);
	std::cout << "| " << vct.empty() << " | " << vct.capacity() << " | " << vct.size() << "|	" << vct << std::endl;
	vct.resize(5);
	std::cout << "| " << vct.empty() << " | " << vct.capacity() << " | " << vct.size() << "|	" << vct << std::endl;

	// std::cout << "----------------------------------" << std::endl;
	// std::cout << "TEST ==> PUSH_POP" << std::endl;
	// std::cout << "----------------------------------" << std::endl;
// 
	// ft::vector<std::string> strs(8);
	// ft::vector<std::string> strs2;
	// ft::vector<std::string>::iterator it_strs = strs.begin();
// 
	// for (unsigned long int i = 0; i < strs.size(); ++i)
		// it_strs[i] = std::string((strs.size() - i), i + 65);
	// std::cout << "| " << strs.empty() << " | " << strs.capacity() << " | " << strs.size() << "|	" << std::endl;
	// 
// 
	// std::cout << "push_back():\n" << std::endl;
// 
	// strs.push_back("One long string");
	// strs2.push_back("Another long string");
// 
	// std::cout << "| " << strs.empty() << " | " << strs.capacity() << " | " << strs.size() << "|	" << std::endl;
	// for (ft::vector < char * >::size_type i = 0; i < strs.size(); ++i)
		// std::cout << strs[i] << std::endl;
	// std::cout << "| " << strs2.empty() << " | " << strs2.capacity() << " | " << strs2.size() << "|	" << std::endl;
	// for (ft::vector < char * >::size_type i = 0; i < strs2.size(); ++i)
		// std::cout << strs2[i] << std::endl;
// 
	// strs.pop_back();
	// strs2.pop_back();
// 
	// std::cout << "| " << strs.empty() << " | " << strs.capacity() << " | " << strs.size() << "|	" << std::endl;
	// for (ft::vector < char * >::size_type i = 0; i < strs.size(); ++i)
		// std::cout << strs[i] << std::endl;
	// std::cout << "| " << strs2.empty() << " | " << strs2.capacity() << " | " << strs2.size() << "|	" << std::endl;
	// for (ft::vector < char * >::size_type i = 0; i < strs2.size(); ++i)
		// std::cout << strs2[i] << std::endl;

	std::cout << "----------------------------------" << std::endl;
	std::cout << "TEST ==> AT" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	ft::vector<int> vct_at(7);

	for (unsigned long int i = 0; i < vct_at.size(); ++i)
	{
		vct_at.at(i) = (vct_at.size() - i) * 3;
		std::cout << "vct_at.at(): " << vct_at.at(i) << " | ";
		std::cout << "vct_at[]: " << vct_at[i] << std::endl;
	}
	std::cout << "| " << vct_at.empty() << " | " << vct_at.capacity() << " | " << vct_at.size() << "|	" << vct_at << std::endl;

	ft::vector<int> const vct_at_c(vct_at);

	std::cout << "front(): " << vct_at.front() << " " << vct_at_c.front() << std::endl;
	std::cout << "back(): " << vct_at.back() << " " <<  vct_at_c.back() << std::endl;

	try {
		vct_at.at(10) = 42;
	}
	catch (std::out_of_range &e) {
		std::cout << "Catch out_of_range exception!" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Catch exception: " << e.what() << std::endl;
	}

	ft::vector<int> vct_at2(7);

	for (unsigned long int i = 0; i < vct_at2.size(); ++i)
	{
		vct_at2.at(i) = (vct_at2.size() - i) * 3;
		std::cout << "vct_at2[]: " << vct_at2[i] << std::endl;
	}
	std::cout << "| " << vct_at2.empty() << " | " << vct_at2.capacity() << " | " << vct_at2.size() << "|	" << vct_at2 << std::endl;

	ft::vector<int> const vct_c(vct_at2);

	std::cout << "front(): " << vct_at2.front() << " " << vct_c.front() << std::endl;
	std::cout << "back(): " << vct_at2.back() << " " <<  vct_c.back() << std::endl;

	for (unsigned long int i = 0; i < vct_c.size(); ++i)
		std::cout << "vct_c.at(): " << vct_c.at(i) << std::endl;
	try {
		std::cout << vct_c.at(10) << std::endl;
	}
	catch (std::out_of_range &e) {
		std::cout << "Catch out_of_range exception!" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Catch exception: " << e.what() << std::endl;
	}
	std::cout << "| " << vct_c.empty() << " | " << vct_c.capacity() << " | " << vct_c.size() << "|	" << vct_c << std::endl;

	/*
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TEST ==> ERASE" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	// ft::vector<int>	vect;
	// ft::vector<int>	vect2;
	
	// vect2.insert(vect2.begin(), 1, 5);
	// std::cout << "| " << vect2.empty() << " | " << vect2.capacity() << " | " << vect2.size() << " |	" << vect2;
	// vect2.insert(vect2.begin(), 1, 4);
	// std::cout << "| " << vect2.empty() << " | " << vect2.capacity() << " | " << vect2.size() << " |	" << vect2;
	// vect2.insert(vect2.begin(), 1, 3);
	// std::cout << "| " << vect2.empty() << " | " << vect2.capacity() << " | " << vect2.size() << " |	" << vect2;
	// vect2.insert(vect2.begin(), 1, 2);
	// std::cout << "| " << vect2.empty() << " | " << vect2.capacity() << " | " << vect2.size() << " |	" << vect2;
	// vect2.insert(vect2.begin(), 1, 1);
	std::cout << "| " << vect2.empty() << " | " << vect2.capacity() << " | " << vect2.size() << " |	" << vect2;
	vect2.insert(vect2.begin(), 5);
	std::cout << "| " << vect2.empty() << " | " << vect2.capacity() << " | " << vect2.size() << " |	" << vect2;
	vect2.insert(vect2.begin(), 4);
	std::cout << "| " << vect2.empty() << " | " << vect2.capacity() << " | " << vect2.size() << " |	" << vect2;
	vect2.insert(vect2.begin(), 3);
	std::cout << "| " << vect2.empty() << " | " << vect2.capacity() << " | " << vect2.size() << " |	" << vect2;
	vect2.insert(vect2.begin(), 2);
	std::cout << "| " << vect2.empty() << " | " << vect2.capacity() << " | " << vect2.size() << " |	" << vect2;
	vect2.insert(vect2.begin(), 1);
	std::cout << "| " << vect2.empty() << " | " << vect2.capacity() << " | " << vect2.size() << " |	" << vect2;



	std::cout << "| " << vect.empty() << " | " << vect.capacity() << " | " << vect.size() << " |	" << vect;
	std::cout << "INSERT" << std::endl;
	vect.insert(vect.begin(), 1);
	std::cout << "| " << vect.empty() << " | " << vect.capacity() << " | " << vect.size() << " |	" << vect;
	std::cout << "PUSHBACK" << std::endl;
	vect.push_back(2);
	std::cout << "| " << vect.empty() << " | " << vect.capacity() << " | " << vect.size() << " |	" << vect;
	std::cout << "INSERT" << std::endl;
	vect.insert(vect.begin(), 2);
	std::cout << "| " << vect.empty() << " | " << vect.capacity() << " | " << vect.size() << " |	" << vect;
	std::cout << "SWAP" << std::endl;
	vect.swap(vect2);
	std::cout << "| " << vect.empty() << " | " << vect.capacity() << " | " << vect.size() << " |	" << vect;
	std::cout << "CLEAR" << std::endl;
	vect.clear();
	std::cout << "| " << vect.empty() << " | " << vect.capacity() << " | " << vect.size() << " |	" << vect;
	std::cout << "RESERVE" << std::endl;
	vect.reserve(10);
	std::cout << "| " << vect.empty() << " | " << vect.capacity() << " | " << vect.size() << " |	" << vect;
	std::cout << "RESIZE" << std::endl;
	ft::vector<int>	myvector;

	std::cout << "----------------------------------" << std::endl;
	for (int i=1; i<8; i++) {
		std::cout << "| " << myvector.empty() << " | " << myvector.capacity() << " | " << myvector.size() << " |	" << myvector << std::endl;
		myvector.push_back(i);
	}
	std::cout << "| " << myvector.empty() << " | " << myvector.capacity() << " | " << myvector.size() << " |	" << myvector << std::endl;
	std::cout << "REMPLI!" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "| " << myvector.empty() << " | " << myvector.capacity() << " | " << myvector.size() << " |	" << myvector << std::endl;
	myvector.resize(5);
	std::cout << "| " << myvector.empty() << " | " << myvector.capacity() << " | " << myvector.size() << " |	" << myvector << std::endl;
	myvector.resize(8,100);
	std::cout << "| " << myvector.empty() << " | " << myvector.capacity() << " | " << myvector.size() << " |	" << myvector << std::endl;
	myvector.resize(12);
	std::cout << "| " << myvector.empty() << " | " << myvector.capacity() << " | " << myvector.size() << " |	" << myvector << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "| " << vect.empty() << " | " << vect.capacity() << " | " << vect.size() << " |	" << vect << std::endl;
	vect.assign(13, 53);
	std::cout << "| " << vect.empty() << " | " << vect.capacity() << " | " << vect.size() << " |	" << vect << std::endl;

	// */
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