#include <algorithm>
using std::find_if;
#include <iostream>
#include <vector>

/**
* @brief Functor que retorna se o numero é primo ou não
* @return booleano
*/
class Primo{
	int valor;
public:
	Primo(int valor_recebido):valor(valor_recebido){}
	bool operator()(int valor_recebido) const {
		if(valor_recebido == 1){
			return true;
		}
		for(int i = 2; i < valor; i++){
			if(valor_recebido%i==0)
				return false;
		}
		return true;
	}


};
/**
* @brief Functor inicial do projeto
* @return 0
*/
int main(int argc, char *argv[]){
	std::vector<int> valores;
	if(argv[1] != NULL){
		int valor_obtido = atoi(argv[1]);

		for(int i = 1; i <= valor_obtido; i++){
			valores.push_back(i);
		}

		std::cout << "Numeros primos [1-" << valor_obtido << "] ";
		auto it = valores.begin();
		while(it != valores.end()){
			it = find_if(it, valores.end(), Primo(*it));
			if(it != valores.end()){
				std::cout << *it << " ";
				it++;
			}

		}
		std::cout << std::endl;

	}else{
		std::cout << "ERRO. POR FAVOR, ENTRE COM UM NUMERO!" << std::endl;
	}


	return 0;
}
