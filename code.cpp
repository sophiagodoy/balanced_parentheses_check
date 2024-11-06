// VERIFICAÇÃO DE PARÊNTESES BALANCEADOS 
// DEFININDO BIBLIOTECAS 
#include <iostream>
#include <string>

// ESTRUTURA DE NÓ 
// representa um elemento na pilha 
struct No {
    char var; // armazena o valor do nó da pilha 
    No* next; // aponta para o próximo
};

// ESTRUTURA DA PILHA 
// representa a pilha em si 
struct Pilha {
    No* top; // contém um ponteiro que aponta para o topo da pilha 
};

// FUNÇÃO PARA CRIAR A PILHA 
Pilha* createPilha() {
    Pilha* p = new Pilha;
    p->top = nullptr;
    return p;
}

// FUNÇÃO PARA INSERIR UM ELEMENTO NA PILHA
void insert(Pilha* p, char v) {
    No* newnode = new No;
    newnode->var = v;
    newnode->next = p->top;
    p->top = newnode;
}

// FUNÇÃO PARA REMOVER UM ELEMENTO DA PILHA
char remove(Pilha* p) {
    if (p->top == nullptr) {
        return '\0';  // retorna um caractere nulo se a pilha estiver vazia
    }
    No* temp = p->top;
    char value = temp->var;
    p->top = p->top->next;
    delete temp;
    return value;
}

// FUNÇÃO PARA LIBERAR A PILHA
void freePilha(Pilha* p) {
    while (p->top != nullptr) {
        remove(p);
    }
    delete p;
}

// FUNÇÃO PARA VERIFICAR O BALANCEAMENTO DA EXPRESSÃO
bool CheckConsistency(const std::string& expr) {
    Pilha* pi = createPilha();
    for (char charact : expr) {
        switch (charact) {
            case '(': insert(pi, '('); break;
            case '[': insert(pi, '['); break;
            case '{': insert(pi, '{'); break;
            case ')':
                if (remove(pi) != '(') { // verifica se há um '(' correspondente
                    freePilha(pi);
                    return false;
                }
                break;
            case ']':
                if (remove(pi) != '[') { // verifica se há um '[' correspondente
                    freePilha(pi);
                    return false;
                }
                break;
            case '}':
                if (remove(pi) != '{') { // verifica se há um '{' correspondente
                    freePilha(pi);
                    return false;
                }
                break;
        }
    }
    // verifica se a pilha está vazia no final
    bool ok = (pi->top == nullptr);
    freePilha(pi);
    return ok;
}

int main() {
    // DEFININDO EXPRESSÃO
    std::string expr = "{[(3+4)/2] + (5*2)}"; // exemplo de expressão - colocar aqui a expressão que deseja verificar 
    
    // CHAMANDO A FUNÇÃO 
    bool ok = CheckConsistency(expr);

    // DEFININDO CONDIÇÕES 
    if (ok) {
        std::cout << "Expressao valida" << std::endl;
    } else {
        std::cout << "Expressao invalida" << std::endl;
    }

    return 0;
}
