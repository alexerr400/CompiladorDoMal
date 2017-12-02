#include "stdafx.h"
#include "AnalisadorLexico.h"

AnalisadorLexico::AnalisadorLexico(string nFile)
{
		arquivo.open(nFile);
}

AnalisadorLexico::~AnalisadorLexico() //tem que fechar o arquivo aqui
{
}


