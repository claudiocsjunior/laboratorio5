#include <iostream>
using std::cout;
using std::endl;
#include <vector>
#include <numeric>
using std::vector;
#include <iterator>     // std::distance
#include <list>         // std::list

/**
* @brief Função que retorna o numero mais próximo da média
* @param[in] iterador inicial
* @param[in] iterador final
* @return iterador
*/
template<typename InputIterator>
InputIterator closest2mean(InputIterator first, InputIterator last){
	if(first == last){
		vector<int> erro = {0};
		vector<int>::iterator it;
		it = erro.begin();
		cout << "Erro. Lista vazia." << endl;
		return it;
	}

	InputIterator i;
	double soma = accumulate(first, last, 0);
	int quantidade_de_elementos = std::distance(first, last);
	double media = (double)soma/quantidade_de_elementos;

	double diferenca = 0;
	InputIterator retorno;
	for(i = first; i != last; i++){
		double diferencaInterna = 0;
		if(media > *i){
			diferencaInterna = media - *i;
		}else{
			diferencaInterna = *i - media;
		}

		if((diferenca == 0 && i == first) || (diferencaInterna) < diferenca){
			diferenca = diferencaInterna;
			retorno = i;
		}
	}
	return retorno;

}
/**
* @brief Função Inicial da aplicação
* @return 0
*/
int main() {
	vector<int> v {1, 2, 3, 30, 40, 50};
	auto result = closest2mean(v.begin(), v.end());
	cout << (*result) << endl;
	return 0;
}
