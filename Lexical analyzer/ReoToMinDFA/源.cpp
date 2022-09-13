#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <stack>
#include <fstream>
#include <istream>
#include "NFA.h"
#include "Re.h"
/*
输入格式必须为为完整的正则表达式
a*.(a.b.b)*.b.(b|a)*
而不能为
a*(abb)*b(b|a)*

测试样例：
(a*|b*).b.(b.a)*
(a*|b*)*.a*.b*
a.(a|c).b|b.(a.b|b.c).(b.a|c)
((a*)*|(b|a)*).c.d*
*/
int Node::number = 0;
void input_by_file(string& pNotation, string filename) {
	ifstream fcin;
	fcin.open(filename);
	getline(fcin, pNotation);
	fcin.close();
}

int main() {
	string pNotation;						//波兰式子
	getline(cin, pNotation);				//命令行输入请打开此条注释
	//input_by_file(pNotation, "input.txt");	//文件输入
	Re* re = new Re(pNotation);
	re->setRPNotation();
	std::cout << re->getPostRe() << endl;

	NFA* nfa = re->getNFA();

	nfa->setNFAForm();
	nfa->printNFAForm();

	nfa->setDFAForm();
	nfa->printDFAForm();
	nfa->printDFAFormOrder();

	nfa->setMinDFAForm();
	nfa->printMinDFAForm();
	getchar();
	return 0;
}