#include <iostream>// trabalhar com std::count
#include <string>

int main(int argc, char **argv)
{
	std::string result; // declaro uma um string vazia chamada result
	for (int i = 1; i < argc; i++)//iterar sobre todos os argumentos da linha de comando , 1 pk o 0 'e o programa
	{
		std::string currentArgument(argv[i]);//inicializo outra variavel  para guardar o argumento onde estou
		for(int len = 0; currentArgument[len]; len++)//iterar sobre todos os caracteres do argumento
			currentArgument[len] = toupper(currentArgument[len]);//converte tudo para maiusculas
		result += currentArgument;//junta tudo
	}
	if(result.empty())//caso nao haja argumentos imprime
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << result << std::endl;//imprime na tela
	return(0);
}
