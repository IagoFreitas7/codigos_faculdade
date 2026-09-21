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
void cadastrarVoo(Voo LA[]);
void consultarVoo(Voo LA[], int num);
void reservarPassagem(Voo LA[], int num);
void cancelarReserva(Voo LA[], int num);
void alterarPreco(Voo LA[], int num);
int consultarAssentos(Voo LA[], int num);
float calcularFaturamento(Voo LA[], int num); // faturamento = qnt de passageiros x preco da passagem
void limpar();
void validar(int &var);
void gravarVoo(string texto);
void lerArquivo();
void carregaVetor(Voo LA[]);
string limparTexto(string texto);
int contarVoos(Voo LA[]);
void atualizaArquivo(Voo LA[]);
void deletarVoo(Voo LA[], int num);


int main() {
  Voo LA[TAM] = {};
  int id = 0;
  int entrada;
  int num;
  carregaVetor(LA);

  do{
    menu();
    id = contarVoos(LA);
    cin >> entrada;

    switch (entrada){
      case 1:
        if (id < TAM){
          cadastrarVoo(LA);
          id++;
        } 
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
      case 8:
        lerArquivo();
        limpar();
        break;
      case 9:
        cout << "Informe o numero do voo:" << endl;
        cin >> num;
        deletarVoo(LA, num);
        limpar();
        break;
    }
  }
  while(entrada!=0);
  
  return 0;
}


//printa opcoes para o usuario
void menu(){
  cout << "COMPANHIA AEREA" << endl;
  cout << "1 - Cadastrar voo" << endl;
  cout << "2 - Consultar voo" << endl;
  cout << "3 - Reservar passagem" << endl;
  cout << "4 - Cancelar reserva" << endl;
  cout << "5 - Alterar preco da passagem" << endl;
  cout << "6 - Consultar assentos disponiveis" << endl;
  cout << "7 - Consultar faturamento estimado" << endl;
  cout << "8 - Exibir todos os voos" << endl;
  cout << "9 - Exclui um voo" << endl;
  cout << "0 - Encerrar" << endl << endl;
  cout << "Escolha uma opcao:" << endl;
}


//falta: validar tipos das entradas
//colocar regra para numero do voo
void cadastrarVoo(Voo L[]){
  Voo LA;
  string texto;
  //caracteres
  string aspa = "\"", csv = ",";

  cout << "Digite o numero do voo" << endl;
  cin >> LA.num;
  //validar(LA.num);
  cin.ignore();

  cout << "Digite a origem do voo" << endl;
  getline(cin, LA.origem);

  cout << "Digite o destino do voo" << endl;
  getline(cin, LA.destino);

  cout << "Digite a capacidade maxima da aeronave" << endl;
  cin >> LA.capacidade;

  //quantidade inicial de passageiros
  LA.qnt = 0;

  cout << "Digite o preco da passagem" << endl;
  cin >> LA.preco;

  texto = aspa + to_string(LA.num) + aspa + csv + aspa + LA.origem + aspa + csv +
  aspa + LA.destino + aspa + csv + aspa + to_string(LA.capacidade) + aspa + csv +
  aspa + to_string(LA.qnt) + aspa + csv + aspa + to_string(LA.preco) + aspa;

  gravarVoo(texto);
  carregaVetor(L);
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
        atualizaArquivo(LA);
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
        atualizaArquivo(LA);
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
      atualizaArquivo(LA);
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


// Guarda o voo cadastrado em um arquivo csv
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


//le todos os voos do arquivo e printa
void lerArquivo(){
    // cria ou abre o arquivo no modo de leitura
    ifstream file("meusvoos.csv");
    string texto;
    int i = 0;

    if (file.is_open()) {
        while (!file.eof()){
          if (i < 5) {
            getline(file, texto, ',');
          }
          else {
            getline(file, texto);
          }

          switch (i){
          case 0:
            cout << "Numero do voo: " << limparTexto(texto) << endl;
            break;
          case 1:
            cout << "Origem do voo: " << limparTexto(texto) << endl;
            break;
          case 2:
            cout << "Destino do voo: " << limparTexto(texto) << endl;
            break;
          case 3:
            cout << "Capacidade da aeronave: " << limparTexto(texto) << endl;
            break;
          case 4:
            cout << "Quantidade de passageiros: " << limparTexto(texto) << endl;
            break;
          case 5:
            cout << "Preco da passagem: " << limparTexto(texto) << endl;
            break;  
        }
        i++;
        if(i==6){
          cout << endl;
          i = 0;
        }
      }
        file.close();        
    }
    else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
}


//preenche o vetor com dados do arquivo
void carregaVetor(Voo LA[]){
    for (int k = 0; k < TAM; k++) {
      LA[k] = Voo{};
    }

    ifstream file("meusvoos.csv");

    if (!file.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    string texto, textoLimpo = "";
    int i = 0, j = 0;

    while (!file.eof()){
        if (i < 5) {
            getline(file, texto, ',');
        }
        else {
            getline(file, texto);
        }

        if (file.fail()) {
            break;
        }
      
        textoLimpo = limparTexto(texto);
        switch (i){
          case 0:
            LA[j].num = stoi(textoLimpo);       
            break;
          case 1:
            LA[j].origem = textoLimpo;
            break;
          case 2:
            LA[j].destino = textoLimpo;
            break;
          case 3:
            LA[j].capacidade = stoi(textoLimpo);
            break;
          case 4:
            LA[j].qnt = stoi(textoLimpo);
            break;
          case 5:
            LA[j].preco = stof(textoLimpo);
            j++;
            break;  
        }
        i++;

        if(i == 6)
          i = 0;
        if(j >= TAM)
          break;
      }

    file.close();        
}
    

//funcao pra capturar texto do csv com aspas e devolve apenas o conteudo
string limparTexto(string texto){
  string textoLimpo;

    for (int i = 0; i < texto.length(); i++) {
        if (texto[i] != '\"'&& (texto[i] != '\n' && texto[i] != '\r')) {
            textoLimpo += texto[i];
        }
    }
  return textoLimpo;
}


// informar o numero do voo para outras funcoes
void numCadastro(int &num){
  do{
    cout << "Informe o numero do voo:" << endl;
    cin >> num;
  }
  while(num > TAM - 1 || num < 0);
}


//conta quantos voos tem preenchidos do vetor
int contarVoos(Voo LA[]) {
    int quantidade = 0;

    for (int i = 0; i < TAM; i++) {
        if (LA[i].num != 0) {
            quantidade++;
        }
    }

    return quantidade;
}


//escreve novamente o csv apos alguma alteracao em algum voo
void atualizaArquivo(Voo LA[]){
  string texto;
  //caracteres
  string aspa = "\"", csv = ",";
  ofstream file("meusvoos.csv");

  int id = contarVoos(LA);
  if (file.is_open()) {
        for (int i = 0; i < id; i++){
          if(LA[i].num!= -1){
            texto = aspa + to_string(LA[i].num) + aspa + csv + aspa + LA[i].origem + aspa + csv +
            aspa + LA[i].destino + aspa + csv + aspa + to_string(LA[i].capacidade) + aspa + csv +
            aspa + to_string(LA[i].qnt) + aspa + csv + aspa + to_string(LA[i].preco) + aspa;
            file << texto << endl;
          }         
        }
      file.close();
  } else {
      cout << "Erro ao abrir o arquivo." << endl;
  }
}


// exclui um voo e atualiza no csv
void deletarVoo(Voo LA[], int num){
  char resposta;
  for (int i = 0; i < TAM; i++) {
    if (LA[i].num == num){
      cout << "Tem certeza em deletar o voo n:"<< num << " ? [s/n]" << endl;
      cin >> resposta;
      if(resposta == 's'){
        cout << "Voo deletado" << endl;
        LA[i].num = -1;
        // LA[i].origem = "";
        // LA[i].destino = "";
        // LA[i].capacidade = 0;
        // LA[i].qnt = 0;
        // LA[i].preco = 0;
      }
      else
        cout << "Operacao abortada" << endl;
      atualizaArquivo(LA);
      carregaVetor(LA);
      return;
    }
  }
}


// LA[i].num
// LA[i].origem
// LA[i].destino
// LA[i].capacidade
// LA[i].qnt
// LA[i].preco