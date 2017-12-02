// DeOro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include "AnalisadorLexico.h"

using namespace std;
int main()
{

	string nomeArq;
	cin >> nomeArq;
	AnalisadorLexico analisador(nomeArq);
	analisador.analisar();

	

    return 0;
}

