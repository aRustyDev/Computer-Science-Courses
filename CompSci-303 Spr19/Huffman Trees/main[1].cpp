// HuffTrees.cpp : Defines the entry point for the console application.
//

#include "Huffman_Tree.h"
#include <iostream>


int main()
{
	Huff_Data<char> space(186, ' ');
	Huff_Data<char> e(103, 'e');
	Huff_Data<char> t(80, 't');
	Huff_Data<char> a(64, 'a');
	Huff_Data<char> o(63, 'o');
	Huff_Data<char> i(57, 'i');
	Huff_Data<char> n(57, 'n');
	Huff_Data<char> s(51, 's');
	Huff_Data<char> r(48, 'r');
	Huff_Data<char> h(47, 'h');
	Huff_Data<char> d(32, 'd');
	Huff_Data<char> l(32, 'l');
	Huff_Data<char> u(23, 'u');
	Huff_Data<char> c(22, 'c');
	Huff_Data<char> f(21, 'f');
	Huff_Data<char> m(20, 'm');
	Huff_Data<char> w(18, 'w');
	Huff_Data<char> y(16, 'y');
	Huff_Data<char> g(15, 'g');
	Huff_Data<char> p(15, 'p');
	Huff_Data<char> b(13, 'b');
	Huff_Data<char> v(8, 'v');
	Huff_Data<char> k(5, 'k');
	Huff_Data<char> j(1, 'j');
	Huff_Data<char> q(1, 'q');
	Huff_Data<char> x(1, 'x');
	Huff_Data<char> z(1, 'z');
	
	
	std::ostringstream code;
	std::vector<Huff_Data<char>> huff_Data {space,e,t,a,o,i,n,s,r,h,d,l,u,c,f,m,w,y,g,p,b,v,k,j,q,x,z };
	Huffman_Tree<char> huff_tree;
	huff_tree.build_tree(huff_Data);
	huff_tree.print_code(code);
	std::string result = code.str();
	std::cout << result;

	result = huff_tree.decode("010");

	return 0;
}

