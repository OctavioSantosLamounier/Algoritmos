#include <bits/stdc++.h>

using namespace std;
using Producao = vector<string>; 


/*  ========================= Struct's =========================== */

struct No {
    string simbolo;
    vector<unique_ptr<No>> filhos;
};

struct Gramatica {
    set<string> variaveis;
    set<string> terminais;
    map<string, vector<Producao>> producoes;
    string simboloInicial;
};

/*  ========================= Entrada ============================ */

bool ehEpsilon(const string& simbolo) {
    if(simbolo == "ε" || simbolo == "eps")
        return true;
    return false;
}

vector<string> separarPalavras(const string& linha) {
    istringstream fluxo(linha);
    vector<string> palavras;
    string palavra;

    while (fluxo >> palavra)
        palavras.push_back(palavra);

    return palavras;
}

// Repete até haver ao menos uma palavra
vector<string> lerPalavras(const string& mensagem) {
    string linha;
    vector<string> palavras;

    while (palavras.empty()) {
        cout << mensagem;
        getline(cin, linha);
        palavras = separarPalavras(linha);
    }

    return palavras;
}

void lerVariaveis(Gramatica& g) {
    vector<string> palavras = lerPalavras("Variaveis (separadas por espaco): ");
    g.variaveis.insert(palavras.begin(), palavras.end());
}

void lerTerminais(Gramatica& g) {
    while (true) {
        vector<string> palavras = lerPalavras("Terminais (separados por espaco): ");
        bool valido = true;

        for (const auto& t : palavras) {
            if (g.variaveis.count(t) || ehEpsilon(t)) {
                cout << "  '" << t << "' nao pode ser terminal.\n";
                valido = false;
            }
        }

        if (valido) {
            g.terminais.insert(palavras.begin(), palavras.end());
            return;
        }
    }
}

void lerSimboloInicial(Gramatica& g) {
    while (true) {
        vector<string> palavras = lerPalavras("Simbolo inicial: ");
        
        if (g.variaveis.count(palavras[0])) {
            g.simboloInicial = palavras[0];
            return;
        }

        cout << "  O simbolo inicial deve ser uma variavel.\n";
    }
}

// Formato: A -> x y | z | ε
bool adicionarProducao(Gramatica& g, const string& linha) {
    auto palavras = separarPalavras(linha);
    if (palavras.size() < 3 || palavras[1] != "->" || !g.variaveis.count(palavras[0])) {
        cout << "  Formato invalido. Use: Variavel -> simbolos | outros simbolos\n";
        return false;
    }

    vector<Producao> alternativas;
    Producao atual;
    
    for (size_t i = 2; i < palavras.size(); i++) {
        const string& simbolo = palavras[i];
        if (simbolo == "|") {
            alternativas.push_back(atual);
            atual.clear();
            
        } else if (!ehEpsilon(simbolo)) {
            if (!g.variaveis.count(simbolo) && !g.terminais.count(simbolo)) {
                cout << "  Simbolo desconhecido: " << simbolo << "\n";
                return false;
            }
            atual.push_back(simbolo);
        }
    }
    alternativas.push_back(atual);

    auto& destino = g.producoes[palavras[0]];
    destino.insert(destino.end(), alternativas.begin(), alternativas.end());

    return true;
}

void lerProducoes(Gramatica& g) {
    cout << "Producoes, uma por linha (linha vazia para terminar). Ex: EXPR -> EXPR + TERMO | TERMO\n";
    string linha;

    while (true) {
        cout << "> ";
        getline(cin, linha);

        if (separarPalavras(linha).empty()) {
            if (!g.producoes.empty()) return;
            cout << "  Informe ao menos uma producao.\n";
            continue;
        }

        adicionarProducao(g, linha);
    }
}

/*  ========================= Análise ============================ */

// Constrói a árvore por backtracking, testando todas as divisões da cadeia
class Analisador {
public:
    Analisador(const Gramatica& gramatica, const vector<string>& cadeia)
        : g(gramatica), cadeia(cadeia) {}

    unique_ptr<No> construirArvore() {
        return derivar(g.simboloInicial, 0, cadeia.size());
    }

private:
    const Gramatica& g;
    const vector<string>& cadeia;
    // Evita recursão infinita em ciclos como A -> A
    set<tuple<string, size_t, size_t>> emAndamento;

    // Tenta derivar cadeia[ini, fim) a partir de 'simbolo'
    unique_ptr<No> derivar(const string& simbolo, size_t ini, size_t fim) {
        if (g.terminais.count(simbolo)) {

            if (fim - ini != 1 || cadeia[ini] != simbolo) return nullptr;
            auto folha = make_unique<No>();
            folha->simbolo = simbolo;

            return folha;
        }

        auto it = g.producoes.find(simbolo);
        if (it == g.producoes.end()) return nullptr;

        auto chave = make_tuple(simbolo, ini, fim);
        if (!emAndamento.insert(chave).second) return nullptr;

        unique_ptr<No> resultado;
        for (const auto& producao : it->second) {
            auto no = make_unique<No>();
            no->simbolo = simbolo;
            if (!distribuir(producao, 0, ini, fim, no->filhos)) continue;

            if (no->filhos.empty()) {  // produção ε
                auto vazio = make_unique<No>();
                vazio->simbolo = "ε";
                no->filhos.push_back(move(vazio));
            }

            resultado = move(no);
            break;
        }

        emAndamento.erase(chave);
        return resultado;
    }

    // Divide cadeia[ini, fim) entre os símbolos da produção, a partir de 'indice'
    bool distribuir(const Producao& producao, size_t indice, size_t ini, size_t fim, vector<unique_ptr<No>>& filhos) {
        if (indice == producao.size())  
            return ini == fim;

        for (size_t meio = ini; meio <= fim; meio++) {
            auto filho = derivar(producao[indice], ini, meio);
            if (!filho) continue;

            filhos.push_back(move(filho));
            if (distribuir(producao, indice + 1, meio, fim, filhos)) return true;
            filhos.pop_back();
        }
        
        return false;
    }
};

/*  =========================== Saída ============================ */

using Tela = vector<string>;

size_t largura(const No& n) {
    size_t m = n.simbolo.size();
    for (auto& f : n.filhos)
        m = max(m, largura(*f));
    return m;
}

void escrever(Tela& t, size_t l, size_t c, const string& s) {
    if (t.size() <= l) t.resize(l + 1);
    if (t[l].size() < c + s.size()) t[l].resize(c + s.size(), ' ');
    t[l].replace(c, s.size(), s);
}

// desenha a arvore
int desenhar(const No& n, int l, int w, int& x, Tela& t) {
    vector<int> cs;
    for (auto& f : n.filhos)
        cs.push_back(desenhar(*f, l + (n.filhos.size() > 1 ? 3 : 2), w, x, t));

    int c;
    if (cs.empty()) { c = x + w / 2; x += w; }
    else c = (cs[0] + cs.back()) / 2;
    if (!cs.empty()) escrever(t, l + 1, c, "|");

    if (cs.size() > 1) {
        escrever(t, l + 1, cs[0] + 1, string(cs.back() - cs[0] - 1, '_'));
        escrever(t, l + 1, c, "|");
        for (int k : cs)
            escrever(t, l + 2, k, "|");
        escrever(t, l + 2, cs[0], "/");
        escrever(t, l + 2, cs.back(), "\\");
    }

    string s = n.simbolo == "ε" ? "\1" : n.simbolo;
    escrever(t, l, c - s.size() / 2, s);

    return c;
}

void exibirArvore(const No& raiz) {
    Tela t; int x=0;

    desenhar(raiz, 0, largura(raiz) + 2, x, t);

    for (auto& l : t) {
        for (char c : l)
            if (c == 1) cout << "e";
            else cout << c;
        cout << "\n";
    }
}


/*  ============================================================== */

int main() {
    // barra horizontal (estetica)
    const string separador = string(70, '=');
    cout << separador << '\n' << endl;
    

    Gramatica gramatica;

    lerVariaveis       (gramatica);
    lerTerminais       (gramatica);
    lerSimboloInicial  (gramatica);
    lerProducoes       (gramatica);

    vector<string> cadeia = lerPalavras("Cadeia de entrada (simbolos separados por espaco): ");


    for (const auto& simbolo : cadeia) {
        if (!gramatica.terminais.count(simbolo)) {
            cout << "A cadeia contem simbolo que nao e terminal: " << simbolo << endl;
            cout << separador << endl;
            return 0;
        }
    }

    Analisador analisador(gramatica, cadeia);
    auto arvore = analisador.construirArvore();


    if (!arvore)
        cout << '\n' << separador << "\nA cadeia nao pode ser gerada por esta gramatica." << endl;
    else {
        cout << '\n' << separador << "\nArvore de derivacao:\n" << endl;
        exibirArvore(*arvore);
        cout << '\n' << separador << endl;
    }
    
    return 0;
}


/* ==================================================================
EXEMPLOS DE ENTRADA:
=====================================================================

EXPR TERMO FATOR
a x + ( )
EXPR
EXPR -> EXPR + TERMO | TERMO
TERMO -> TERMO x FATOR | FATOR
FATOR -> ( EXPR ) | a

a + ( a x a )

=====================================================================

S SN SV D N V
o a menino menina ve gosta
S
S -> SN SV
SN -> D N
SV -> V SN
D -> o | a
N -> menino | menina
V -> ve | gosta

o menino ve a menina

=====================================================================

S A
a b
S
S -> a A b
A -> eps

a b

=====================================================================

N B
0 1
N
N -> N B | B
B -> 0 | 1

1 0 1 1

================================================================== */