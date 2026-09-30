// 1. Cadastro de pessoa
// Crie uma struct Pessoa contendo nome, idade e altura. Leia os dados e apresenteos na tela.

#include <iostream>
using namespace std;

struct pessoa{
    char nome[25];
    int idade;
    float altura;
};

int main(){
    pessoa p1;

    cout << "Digite o nome: " << endl;
    cin >> p1.nome;

    cout << "Digite a idade: " << endl;
    cin >> p1.idade;

    cout << "Digite a altura: " << endl;
    cin >> p1.altura;

    cout << p1.nome << " " <<
            p1.idade << " " <<
            p1.altura << endl;

    return 0;
}