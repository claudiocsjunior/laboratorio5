#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

template<typename InputIterator>
InputIterator closest2mean(InputIterator first, InputIterator last){
	InputIterator i;
	InputIterator soma = first;
	int count = 1;
	//Realiza a soma dos iteradores
	for(i = soma+1; i != last; i++){
	
		 *soma += *i;
		 count++;
	}
	//usar acumulate
	double media = ((double)*soma / (double)count);

	//busca o iterador mais proximo
	double diferenca = 0;
	InputIterator retorno;
	for(i = first; i != last; i++){
		double diferencaInterna = 0;
		if(media > *i){
			cout << media << " - " << *i << " = " ;
			diferencaInterna = media - *i;
		}else{
			cout << *i << " - " << media << " = ";
			diferencaInterna = *i - media;
		}

		if((diferenca == 0 && i == first) || (diferencaInterna) < diferenca){
			diferenca = diferencaInterna;
			retorno = i;
		}
		cout <<  diferenca << endl;
		cout << "retorno: " << *retorno << endl;


	}
	return retorno;

}

int main() {
	vector<int> v { 1, 2, 3, 30, 40, 50};
	auto result = closest2mean(v.begin(), v.end());
	cout << (*result) << endl;
	return 0;
}