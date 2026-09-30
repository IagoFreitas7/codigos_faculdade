// 10 - Cadastre cinco alunos em alunos.dat utilizando ios::binary e write().
// 11 - Leia todos os registros de alunos.dat utilizando read() e apresente-os na tela.

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


int main(){
    Aluno a;

    for (int i = 0; i < 1; i++)
    {
        cout << "digite a matricula do aluno n."<< i << endl;
        cin >> a.matricula;
        cout << "digite o nome do aluno n."<< i << endl;
        cin >> a.nome;
        cout << "digite a nota do aluno n."<< i  << endl;
        cin >> a.nota;

        cadastro(a);
    }
    
    leitura();
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
        cout << a.matricula << endl;
        cout << a.nome << endl;
        cout << a.nota << endl;
    }

    file.close();
}