#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

void menu();
void cadastrarVoo();
void consultarVoo();
void reservarPassagem();
void cancelarReserva();
void alterarPreco();
int consultarAssentos();
float calcularFaturamento(); // faturamento = qnt de passageiros x preco da passagem
void limpar();
void validar(int &var);


struct Voo{
  int num;
  string origem;
  string destino;
  int capacidade;
  int qnt;
  float preco;
};


Voo LA1;


int main() {
  int entrada;

  do{
    menu();
    cin >> entrada;

    switch (entrada){
      case 1:
        cadastrarVoo();
        break;
      case 2:
        consultarVoo();
        limpar();
        break;
      case 3:
        reservarPassagem();
        limpar();
        break;
      case 4:
        cancelarReserva();
        limpar();
        break;
      case 5:
        alterarPreco();
        limpar();
        break;
      case 6:
        consultarAssentos();
        limpar();
        break;
      case 7:
        calcularFaturamento();
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


void cadastrarVoo (){
  //LA[0].num = 123;
  //LA[1].num = 400;

  cout << "Digite o numero do voo" << endl;
  //cin >> LA1.num;
  validar(LA1.num);
  cin.ignore();

  cout << "Digite a origem do voo" << endl;
  getline(cin, LA1.origem);

  cout << "Digite o destino do voo" << endl;
  getline(cin, LA1.destino);

  cout << "Digite a capacidade maxima da aeronave" << endl;
  cin >> LA1.capacidade;

  //quantidade inicial de passageiros
  LA1.qnt = 0;

  cout << "Digite o preco da passagem" << endl;
  cin >> LA1.preco;
}


void consultarVoo(){
  cout << "Numero do voo: " << LA1.num << endl;
  cout << "Origem do voo: " <<  LA1.origem << endl;
  cout << "Destino do voo: " <<  LA1.destino << endl;
  cout << "Capacidade da aeronave: " << LA1.capacidade << endl;
  cout << "Quantidade de passageiros: " <<  LA1.qnt << endl;
  cout << "Preco da passagem: " <<  LA1.preco << endl << endl;
}


void reservarPassagem(){
  if(LA1.qnt < LA1.capacidade){
    LA1.qnt++;
    cout << "Sua reserva foi realizada com sucesso" << endl;
  }
  else 
    cout << "Nao ha vagas disponiveis no voo" << endl;
}


void cancelarReserva(){
  if(LA1.qnt > 0){
    LA1.qnt--;
    cout << "Sua reserva foi cancelada com sucesso" << endl;
  }
}


void alterarPreco(){
  cout << "Digite o novo preco da passagem" << endl;
  cin >> LA1.preco; 
  cout << "Preco da passagem alterado" << endl;
}


int consultarAssentos(){
  int disponiveis;

  disponiveis = LA1.capacidade - LA1.qnt;
  cout << "Quantidade de assentos disponiveis: " <<  disponiveis << endl;

  return disponiveis;
}


float calcularFaturamento(){
  float faturamento;

  faturamento = LA1.preco * LA1.qnt;
  cout << "Faturamento estimado do voo: " <<  faturamento << endl;

  return faturamento;
}


void limpar(){
  this_thread::sleep_for(chrono::seconds(4));
  system("clear||cls");
}


void validar(int &var){
  while (!(cin >> var)) {  
  cout << "Entrada invalida. Digite novamente: ";
  cin.clear();
  cin.ignore(10000, '\n'); 
}
}