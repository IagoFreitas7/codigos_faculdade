#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#define TAM 10
using namespace std;


struct Voo{
  int num;
  string origem;
  string destino;
  int capacidade;
  int qnt;
  float preco;
};


void menu();
void cadastrarVoo(Voo LA[], int *i);
void consultarVoo(Voo LA[], int num);
void reservarPassagem(Voo LA[], int num);
void cancelarReserva(Voo LA[], int num);
void alterarPreco(Voo LA[], int num);
int consultarAssentos(Voo LA[], int num);
float calcularFaturamento(Voo LA[], int num); // faturamento = qnt de passageiros x preco da passagem
void limpar();
void validar(int &var);
void gravarVoo(string texto);


int main() {
  Voo LA[TAM];
  int id = 0;
  int entrada;
  int num;

  do{
    menu();
    cin >> entrada;

    switch (entrada){
      case 1:
        cadastrarVoo(LA, &id);
        if (id < TAM) 
          id++;
        else 
          cout << "Numero maximo de voos registrados" << endl;
        break;
      case 2:
        cout << "Informe o numero do voo:" << endl;
        cin >> num;
        consultarVoo(LA, num);
        limpar();
        break;
      case 3:
        cout << "Informe o numero do voo:" << endl;
        cin >> num;
        reservarPassagem(LA, num);
        limpar();
        break;
      case 4:
        cout << "Informe o numero do voo:" << endl;
        cin >> num;
        cancelarReserva(LA, num);
        limpar();
        break;
      case 5:
        cout << "Informe o numero do voo:" << endl;
        cin >> num;
        alterarPreco(LA, num);
        limpar();
        break;
      case 6:
        cout << "Informe o numero do voo:" << endl;
        cin >> num;
        consultarAssentos(LA, num);
        limpar();
        break;
      case 7:
        cout << "Informe o numero do voo:" << endl;
        cin >> num;
        calcularFaturamento(LA, num);
        limpar();
        break;
      case 0:
        break;
    }
  }
  while(entrada!=0);
  
  return 0;
}


void menu(){
  cout << "COMPANHIA AEREA" << endl;
  cout << "1 - Cadastrar voo" << endl;
  cout << "2 - Consultar voo" << endl;
  cout << "3 - Reservar passagem" << endl;
  cout << "4 - Cancelar reserva" << endl;
  cout << "5 - Alterar preco da passagem" << endl;
  cout << "6 - Consultar assentos disponiveis" << endl;
  cout << "7 - Consultar faturamento estimado" << endl;
  cout << "0 - Encerrar" << endl << endl;
  cout << "Escolha uma opcao:" << endl;
}


void cadastrarVoo (Voo LA[], int *i){
  string texto;
  string aspa = "\"", csv = ",";

  cout << "Digite o numero do voo" << endl;
  cin >> LA[*i].num;
  //validar(LA[*i].num);
  cin.ignore();

  cout << "Digite a origem do voo" << endl;
  getline(cin, LA[*i].origem);

  cout << "Digite o destino do voo" << endl;
  getline(cin, LA[*i].destino);

  cout << "Digite a capacidade maxima da aeronave" << endl;
  cin >> LA[*i].capacidade;

  //quantidade inicial de passageiros
  LA[*i].qnt = 0;

  cout << "Digite o preco da passagem" << endl;
  cin >> LA[*i].preco;

  texto = aspa + to_string(LA[*i].num) + aspa + csv + aspa + LA[*i].origem + aspa + csv +
  aspa + LA[*i].destino + aspa + csv + aspa + to_string(LA[*i].capacidade) + aspa + csv +
  aspa + to_string(LA[*i].qnt) + aspa + csv + aspa + to_string(LA[*i].preco) + aspa;

  gravarVoo(texto);
}


void consultarVoo(Voo LA[], int num){
  for (int i = 0; i < TAM; i++)
  {
    if (LA[i].num == num)
    {
      cout << "Numero do voo: " << LA[i].num << endl;
      cout << "Origem do voo: " <<  LA[i].origem << endl;
      cout << "Destino do voo: " <<  LA[i].destino << endl;
      cout << "Capacidade da aeronave: " << LA[i].capacidade << endl;
      cout << "Quantidade de passageiros: " <<  LA[i].qnt << endl;
      cout << "Preco da passagem: " <<  LA[i].preco << endl << endl;
      return;
    }
  }

  cout << "Voo nao encontrado." << endl;
}


void reservarPassagem(Voo LA[], int num){
  for (int i = 0; i < TAM; i++)
  {
    if (LA[i].num == num)
    {
      if(LA[i].qnt < LA[i].capacidade){
        LA[i].qnt++;
        cout << "Sua reserva foi realizada com sucesso" << endl;
      }
      else
        cout << "Nao ha vagas disponiveis no voo" << endl;
      return; 
    }
  }

  cout << "Voo nao encontrado." << endl;
}


void cancelarReserva(Voo LA[], int num){
  for (int i = 0; i < TAM; i++)
  {
    if (LA[i].num == num){
      if(LA[i].qnt > 0){
        LA[i].qnt--;
        cout << "Sua reserva foi cancelada com sucesso" << endl;
      }
      else
        cout << "Nao existe nenhuma reserva nesse voo" << endl;
      return;
    }
  }

  cout << "Voo nao encontrado." << endl;
}


void alterarPreco(Voo LA[], int num){
  for (int i = 0; i < TAM; i++)
  {
    if (LA[i].num == num){
      cout << "Digite o novo preco da passagem" << endl;
      cin >> LA[i].preco; 
      cout << "Preco da passagem alterado" << endl;
      return;
    }
  }

  cout << "Voo nao encontrado." << endl;
}


int consultarAssentos(Voo LA[], int num){
  int disponiveis;

  for (int i = 0; i < TAM; i++)
  {
    if (LA[i].num == num){
      disponiveis = LA[i].capacidade - LA[i].qnt;
      cout << "Quantidade de assentos disponiveis: " <<  disponiveis << endl;
      return disponiveis;
    }
  }

  cout << "Voo nao encontrado." << endl;
  return -1;
}


float calcularFaturamento(Voo LA[], int num){
  float faturamento;

  for (int i = 0; i < TAM; i++){
    if (LA[i].num == num){
      faturamento = LA[i].preco * LA[i].qnt;
      cout << "Faturamento estimado do voo: " <<  faturamento << endl;
      return faturamento;
    }
  }
  cout << "Voo nao encontrado." << endl;
  return -1;
}


// aguarda alguns segundos e limpa a tela
void limpar(){
  this_thread::sleep_for(chrono::seconds(4));
  system("clear||cls");
}


// testando funcao para validar entradas
void validar(int &var){
  while (!(cin >> var)) {  
  cout << "Entrada invalida. Digite novamente: ";
  cin.clear();
  cin.ignore(10000, '\n'); 
}
}


// file 
void gravarVoo(string texto){
  // cria ou abre o arquivo no modo append
  ofstream file("meusvoos.csv", ios::app);

  if (file.is_open()) {
      file << texto << endl;
      file.close();
  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }
}


// void lerArquivo(){
//   // cria ou abre o arquivo no modo de leitura
//     ofstream file("meusvoos.csv", ios::app);

//     if (file.is_open()) {
//         file << texto << endl;
//         file.close();
//     } else {
//         cout << "Erro ao abrir o arquivo." << endl;
//     }
// }


void numCadastro(int &num){
  do{
    cout << "Informe o numero do voo:" << endl;
    cin >> num;
  }
  while(num > TAM - 1 || num < 0);
}

