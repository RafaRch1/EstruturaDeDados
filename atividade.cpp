#include <iostream>
#include <string>

using namespace std;

// Utilização de uma struct para representar o aluno [cite: 11]
struct Aluno {
    string nome;
    float nota1;
    float nota2;
};

// Vetor com 50 posições para armazenar os registros [cite: 11]
const int TAM = 50; [cite: 17]

// Inicializando o array de alunos com alguns alunos cadastrados [cite: 16]
Aluno alunos[TAM] = {
    {"Rafael", 8.0, 7.0},  // [cite: 17]
    {"Mariana", 5.5, 6.0}, // [cite: 17]
    {"Thiago", 4.0, 5.0},  // [cite: 17]
    {"Lorena", 9.0, 8.5},  // [cite: 17]
    {"Eduardo", 6.5, 7.0}  // [cite: 17]
};

// Variável para controlar quantos alunos já estão no vetor
int quantidadeAlunos = 5;

// Função que implementa a busca sequencial [cite: 11]
int buscaSequencial(string nomeBuscado) {
    for (int i = 0; i < quantidadeAlunos; i++) {
        if (alunos[i].nome == nomeBuscado) {
            return i; // Retorna o índice onde o aluno foi encontrado
        }
    }
    return -1; // Retorna -1 se não encontrar
}

int main() {
    int opcao;
    string nomeBusca;
    
    do {
        // Menu de opções [cite: 7]
        cout << "\nMenu\n"; // [cite: 15]
        cout << "1 = Inserir\n"; // [cite: 15]
        cout << "2 = Modificar\n"; // [cite: 15]
        cout << "3 = Consultar\n"; // [cite: 15]
        cout << "0 = Sair\n"; // [cite: 15]
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: { // Inserir aluno [cite: 8]
                if (quantidadeAlunos < TAM) {
                    cout << "Nome do aluno: ";
                    cin >> alunos[quantidadeAlunos].nome; // [cite: 8]
                    cout << "Nota 1: ";
                    cin >> alunos[quantidadeAlunos].nota1; // [cite: 8]
                    cout << "Nota 2: ";
                    cin >> alunos[quantidadeAlunos].nota2; // [cite: 8]
                    quantidadeAlunos++;
                } else {
                    cout << "Capacidade maxima atingida.\n";
                }
                break;
            }
            case 2: { // Modificar nota do aluno [cite: 9]
                cout << "Nome do aluno a modificar: ";
                cin >> nomeBusca;
                
                int indice = buscaSequencial(nomeBusca); // [cite: 11]
                
                if (indice != -1) {
                    cout << "Aluno encontrado\n"; // [cite: 23]
                    cout << "Nova Nota 1: ";
                    cin >> alunos[indice].nota1; // [cite: 9]
                    cout << "Nova Nota 2: ";
                    cin >> alunos[indice].nota2; // [cite: 9]
                } else {
                    cout << "Aluno nao encontrado\n"; // [cite: 21]
                }
                break;
            }
            case 3: { // Consultar nota do aluno [cite: 10]
                cout << "Nome do aluno a consultar: ";
                cin >> nomeBusca;
                
                int indice = buscaSequencial(nomeBusca); // [cite: 11]
                
                if (indice != -1) {
                    cout << "Aluno encontrado\n"; // [cite: 19]
                    float n1 = alunos[indice].nota1; // [cite: 10]
                    float n2 = alunos[indice].nota2; // [cite: 10]
                    float media = (n1 + n2) / 2.0; // [cite: 10]
                    
                    cout << "Nota1: " << n1 << "\n"; // [cite: 10, 19]
                    cout << "Nota2: " << n2 << "\n"; // [cite: 10, 19]
                    cout << "Media: " << media << "\n"; // [cite: 10, 19]
                    
                    // Situação, considerando 6,0 como média de corte [cite: 10]
                    if (media >= 6.0) {
                        cout << "Situacao: Aprovado\n"; // [cite: 10, 19]
                    } else {
                        cout << "Situacao: Reprovado\n"; // [cite: 10]
                    }
                } else {
                    cout << "Aluno nao encontrado\n"; // [cite: 21]
                }
                break;
            }
            case 0:
                // Sair do programa [cite: 15]
                break;
            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 0); // [cite: 15]

    return 0;
}