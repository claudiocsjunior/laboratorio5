#include <set>
#include <iostream>
using std::set;
using std::cout;
using std::endl;

template<typename TContainer>
void print_elementos(const TContainer& collection, const char* label="", const char separator=' '){
	//collection<TContainer>::iterator it;
	cout << label;
	for(auto i = collection.begin(); i != collection.end(); i++){
		cout << *i  << separator;
	}
	cout << endl;
}

int main() {
	set<int> numeros;
	numeros.insert(3);
	numeros.insert(1);
	numeros.insert(4);
	numeros.insert(1);
	numeros.insert(2);
	numeros.insert(5);
	print_elementos(numeros, "Set: ");
	print_elementos(numeros, "CSV Set: ", ';');
	return 0;
}
