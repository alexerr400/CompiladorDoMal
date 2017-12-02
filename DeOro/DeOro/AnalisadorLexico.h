#pragma once
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <cstring>

using namespace std;
class AnalisadorLexico
{
public:
	//NAO FACA ALTERACOES NO MEU ENUM NEM NO MEU VETOR!!!! 

	//Talvez precise adicionar mais coisas no enum e no vetor, mas deixa isso pro fim
	typedef enum {
		INICIO_DE_PROGRAMA,
		INICIO_DE_DECLARACAO_DE_VARIAVEL_OU_PARAMETRO_POR_REFERENCIA,
		INICIO_DE_DECLARACAO_DE_PROCEDIMENTO,
		INICIO_DE_DECLARACAO_DE_FUNCAO,
		SE,
		SENAO,
		FACA,
		ENQUANTO,
		ENTAO,
		ESCREVA,
		LEIA,
		INTEIRO,
		BOOLEAN,

		INICIO_DE_COMANDO_COMPOSTO,
		FIM_DE_COMANDO_COMPOSTO,
				
		VIRGULA,
		PONTO_E_VIRGULA,
		DOIS_PONTOS,
		PONTO,
		ABRE_PARENTESES,
		FECHA_PARENTESES,

		FIM_DE_ARQUIVO, //EOF
		ABRE_PARENTESES,
		FECHA_PARENTESES,
		ABRE_COLCHETES,
		FECHA_COLCHETES,

		MAIOR,
		MENOR,
		RECEBE,
		IGUAL,

		IDENTIFICADOR,
		NUMERO

	} TipoDePedaco;

	AnalisadorLexico(string nFile);
	~AnalisadorLexico();

	string getPalavra()
	{
		string palavra;

			//tive que mudar a logica, entao vai ficar o seguinte
			//nosso programa vai comecar a ler o arquivo
			//vai procurar palavra por palavra e comparar com o vetor de conhecidos para atribuir ao tipo de pedaço,
			//entao vou comecar percorrendo o arquivo e colocando as letras num vetor ate que se forme uma palavra
			//quando achar espaco ele quebra e compara
			
			while(arquivo.peek() == ' ')
				arquivo.get();

			while (arquivo.peek() != ' ' || arquivo.peek() != '\n')
			{
				palavra.append(1, arquivo.get());
			}
			

		return palavra;
	}

	TipoDePedaco getTipoPedaco()
	{
		string palavraPega = getPalavra();

		for (int i = 0; i <= sizeof(*conhecidos); i++)
		{
			if (palavraPega == conhecidos[i])
				return TipoDePedaco(i);
		}

		const char* p = palavraPega.c_str();
		strcpy(nomeDoIdenficador, p); //o getNome ou getValor vai pegar o que tem no nomeDoIdentificador
		for (int i = 0; i < strlen(p); i++)
			if (!isdigit(p[i]))
				return TipoDePedaco::IDENTIFICADOR;

		return TipoDePedaco::NUMERO; 
	}


	//UNICA COISA QUE VCS PODEM MEXER SÃO ESSES 3 MÉTODOS AQUI, NÃO TOCA NO RESTO

	// 1o grupo de gets
	TipoDePedaco getPedacoSemConsumir();

	TipoDePedaco getPedacoConsumindo();

	// 2o grupo de gets
	char* getNome(); // deve ser usado quando o ultimo retorno de um dos gets do 1o grupo tiver sido identificador; dar excecao caso contrario




private:
	TipoDePedaco novo, ultimoPedacoRetornado;
	int nTipos;
	char nomeDoIdenficador[256];
	int  valorDoNumero;
	ifstream arquivo;
	char * conhecidos[] = { "program", "var", "procedure", "function", "if", "else", "do", "while", 
							"then", "writeln", "readln", "integer", "boolean", "begin", "end", ",", ";", 
							":", ".", "(", ")", "{", "}", ">", "<", ":=", "="};
};

