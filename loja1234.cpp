#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ==================== CLASSE BASE ====================
class Produto {
protected:
    string nome;
    double preco;

public:
    Produto(string nome = "", double preco = 0.0) {
        this->nome = nome;
        setPreco(preco);
    }

    void setPreco(double valor) {
        if (valor < 0) {
            cout << "Nao existe produtos com preco negativo irmao ! Definir como 0" << endl;
            preco = 0.0;
        } else {
            preco = valor;
        }   
    }

    virtual void exibirDetalhes() {
        cout << "Nome: " << nome << endl;
        cout << fixed << setprecision(2);
        cout << "Preco:  " << preco << endl;
    }

    virtual ~Produto() {} // Destrutor virtual para boa prática
};

// ==================== CLASSE DERIVADA 1: LIVRO ====================
class Livro : public Produto {
private:
    string autor;

public:
    Livro(string nome = "", double preco = 0.0, string autor = "") 
        : Produto(nome, preco) {
        this->autor = autor;
    }

    void exibirDetalhes() override {
        cout << "Nome: " << nome << endl;
        cout << "Autor: " << autor << endl;
        cout << fixed << setprecision(2);
        cout << "Preco:  " << preco << endl;
    }
};

// ==================== CLASSE DERIVADA 2: SMARTPHONE ====================
class Smartphone : public Produto {
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
    cout << "===== CADASTRO DA LOJA =====" << endl << endl;

    // Criar objetos
    Livro livro("O Executor", 45.50, "Senhor Nao sei que");
    Smartphone smartphone("iPhone 16 PM", 999.99, "Apple");
    Produto produtoGenerico("Caderno", 5.00);

    // Exibir detalhes iniciais
    cout << "--- LIVRO ---" << endl;
    livro.exibirDetalhes();
    cout << endl;

    cout << "--- SMARTPHONE ---" << endl;
    smartphone.exibirDetalhes();
    cout << endl;

    cout << "--- PRODUTO GENERICO ---" << endl;
    produtoGenerico.exibirDetalhes();
    cout << endl;

    // Testar preço negativo
    cout << "===== TESTE PRECO NEGATIVO =====" << endl;
    livro.setPreco(-10.50);
    cout << "Novo preco do livro:" << endl;
    livro.exibirDetalhes();
    cout << endl;

    smartphone.setPreco(-500.00);
    cout << "Novo preco do smartphone:" << endl;
    smartphone.exibirDetalhes();

    return 0;
}

