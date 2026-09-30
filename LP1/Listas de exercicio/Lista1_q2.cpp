// 2. Cadastro de produto
// Crie uma struct Produto com código, descrição, preço e quantidade em estoque.
// Mostre o valor total do estoque do produto

#include <iostream>
using namespace std;

struct Produto{
    char codigo[50];
    char descricao[500];
    float preco;
    int qnt_estoque;
};

int main(){
    cout << "Valor total em estoque: ";
    return 0;
}