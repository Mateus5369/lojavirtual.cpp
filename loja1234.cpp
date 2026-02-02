#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#define RESET "\x1b[0m"
#define VERMELHO "\x1b[91m"
#define VERDE "\x1b[92m"
#define AMARELO "\x1b[93m"
#define AZUL "\x1b[94m"
#define ROXO "\x1b[95m"
#define CIANO "\x1b[96m"

// ==================== CLASSE BASE ====================
class Produto {
protected:  // PROTECTED: classe PAI + FILHAS acedem (private = só o pai)
    string nome;
    double preco;

public:
    Produto(string nome = "", double preco = 0.0) {
        this->nome = nome;  // THIS: atributo = parâmetro (diferencia os dois)
        setPreco(preco);
    }

    void setPreco(double valor) {
        if (valor < 0) {  // VALIDAÇÃO: rejeita negativos
            cout << "Nao existe produtos com preco negativo irmao ! Definir como 0" << endl;
            preco = 0.0;
        } else {
            preco = valor;
        }   
    }

    virtual void exibirDetalhes() {  // VIRTUAL: filhas podem REESCREVER este método
        cout << "Nome: " << nome << endl;
        cout << fixed << setprecision(2);
        cout << "Preco:  " << preco << endl;
    }

    virtual ~Produto() {}  // DESTRUTOR (~): destrói objeto | VIRTUAL: chama destrutores das filhas
};

// ==================== CLASSE DERIVADA 1: LIVRO ====================
class Livro : public Produto {  // DERIVADA/FILHA: HERDA nome e preco de Produto
private:
    string autor;

public:
    Livro(string nome = "", double preco = 0.0, string autor = "") 
        : Produto(nome, preco) {  // chama construtor PAI
        this->autor = autor;
    }

    void exibirDetalhes() override {  // OVERRIDE: reescreve método do pai (POLIMORFISMO)
        cout << "Nome: " << nome << endl;
        cout << "Autor: " << autor << endl;
        cout << fixed << setprecision(2);
        cout << "Preco:  " << preco << endl;
    }
};

// ==================== CLASSE DERIVADA 2: SMARTPHONE ====================
class Smartphone : public Produto {  // DERIVADA/FILHA: HERDA de Produto
private:
    string marca;

public:
    Smartphone(string nome = "", double preco = 0.0, string marca = "") 
        : Produto(nome, preco) {
        this->marca = marca;
    }

    void exibirDetalhes() override {  
        cout << "Nome: " << nome << endl;
        cout << "Marca: " << marca << endl;
        cout << fixed << setprecision(2);
        cout << "Preco: " << preco << endl;
    }
};

// ==================== MAIN ====================
int main() {
    cout << VERDE << endl;
    cout << "--------------------------------" << endl;
    cout << "||||||| CADASTRO DA LOJA ||||||" << endl; 
    cout << "--------------------------------" << endl;
   
    Livro livro("O Executor", 45.50, "Senhor Nao sei que");
    Smartphone smartphone("iPhone 16 PM", 999.99, "Apple");
    Produto produtoGenerico("Caderno", 5.00);
    
    cout << ROXO << endl;
    cout << "-------------" << endl;
    cout << "||| LIVRO |||" << endl;
    cout << "-------------" << endl;
    livro.exibirDetalhes();
    
    cout << AMARELO << endl;
    cout << "-------------------" << endl;
    cout << "||| TELEMOVEL |||" << endl;
    cout << "-------------------" << endl;
    smartphone.exibirDetalhes();
    
    cout << AZUL << endl;
    cout << "------------------------" << endl;
    cout << "||| PRODUTO GENERICO |||" << endl;
    cout << "------------------------" << endl;
    produtoGenerico.exibirDetalhes();
   
    cout << VERMELHO << endl;
    cout << "--------------------------------" << endl;
    cout << "||||| TESTE PRECO NEGATIVO |||||" << endl;
    cout << "--------------------------------" << endl;
    cout << RESET << endl;
    
    livro.setPreco(-46.50); 
    cout << "Novo preco do livro:" << endl;
    livro.exibirDetalhes();
    cout << endl;

    smartphone.setPreco(-1000.00);
    cout << "Novo preco do smartphone:" << endl;
    smartphone.exibirDetalhes();

    return 0;
}
