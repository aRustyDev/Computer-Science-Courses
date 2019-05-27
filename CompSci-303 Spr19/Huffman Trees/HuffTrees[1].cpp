// HuffTrees.cpp : Defines the entry point for the console application.
//

#include "Huffman_Tree.h"
#include <iostream>


int main()
{
	Huff_Data space(186, ' ');
	Huff_Data e(103, 'e');
	Huff_Data t(80, 't');
	Huff_Data a(64, 'a');
	Huff_Data o(63, 'o');
	Huff_Data i(57, 'i');
	Huff_Data n(57, 'n');
	Huff_Data s(51, 's');
	Huff_Data r(48, 'r');
	Huff_Data h(47, 'h');
	Huff_Data d(32, 'd');
	Huff_Data l(32, 'l');
	Huff_Data u(23, 'u');
	Huff_Data c(22, 'c');
	Huff_Data f(21, 'f');
	Huff_Data m(20, 'm');
	Huff_Data w(18, 'w');
	Huff_Data y(16, 'y');
	Huff_Data g(15, 'g');
	Huff_Data p(15, 'p');
	Huff_Data b(13, 'b');
	Huff_Data v(8, 'v');
	Huff_Data k(5, 'k');
	Huff_Data j(1, 'j');
	Huff_Data q(1, 'q');
	Huff_Data x(1, 'x');
	Huff_Data z(1, 'z');
	
	
	std::ostringstream code;
	std::vector<Huff_Data> huff_Data {space,e,t,a,o,i,n,s,r,h,d,l,u,c,f,m,w,y,g,p,b,v,k,j,q,x,z };
	Huffman_Tree huff_tree;
	huff_tree.build_tree(huff_Data);
	huff_tree.print_code(code);
	std::string result = code.str();
	std::cout << result;

	result = huff_tree.decode("010");

	return 0;
}

