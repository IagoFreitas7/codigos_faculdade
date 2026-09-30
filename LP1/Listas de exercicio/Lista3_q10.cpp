// A questao 10 vai sendo elaborada nas questoes seguintes
// 10 - Cadastre cinco alunos em alunos.dat utilizando ios::binary e write().
// 11 - Leia todos os registros de alunos.dat utilizando read() e apresente-os na tela.
// 12 - Determine quantos registros existem em alunos.dat utilizando o tamanho do
// arquivo e sizeof(Aluno), sem percorrer todos os registros.

#include <iostream>
#include <fstream> 
using namespace std;


struct Aluno{
    int matricula;
    char nome[50];
    float nota;
};


void cadastro(Aluno a);
void leitura();
void qtd_registros();


int main(){
    Aluno a;
    int qnt;

    cout << "Digite a quantidade de alunos para fazer o registro: "<< endl;
    cin >> qnt;

    for (int i = 0; i < qnt; i++)
    {
        cout << "digite a matricula do aluno"<< endl;
        cin >> a.matricula;
        cin.ignore();
        cout << "digite o nome do aluno" << endl;
        cin.getline(a.nome, 50);
        cout << "digite a nota do aluno" << endl;
        cin >> a.nota;

        cadastro(a);
    }
    
    leitura();
    qtd_registros();
    return 0;
}


void cadastro(Aluno a){
    ofstream file("alunos.dat", ios::binary | ios::app);

    if(!file){
        cout << "erro ao abrir arquivo";
        return;
    }

    file.write(reinterpret_cast<char*>(&a), sizeof(Aluno));
    
    file.close();
}


void leitura(){
    Aluno a;
    ifstream file("alunos.dat", ios::binary);

    if(!file){
        cout << "erro ao abrir o arquivo";
        return;
    }

    while(file.read(reinterpret_cast<char*>(&a),sizeof(Aluno))){
        cout << "Matricula: "<< a.matricula << endl;
        cout << "Nome: " << a.nome << endl;
        cout << "Nota: " << a.nota << endl;
    }

    file.close();
}


void qtd_registros(){
    ifstream file("alunos.dat", ios::binary);

    if(!file){
        cout << "erro ao abrir arquivo";
        return;
    }

    file.seekg(0, ios::end);
    streampos tamanho = file.tellg();
    int quantidade = tamanho / sizeof(Aluno);
    cout << "Bytes: " << tamanho << endl;
    cout << "Registros: " << quantidade;

    file.close();
}