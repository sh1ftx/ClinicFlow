#include "Utils.h"
#include <iostream>

// Função para validar a prioridade (de 1 a 5)
bool isValidPriority(int p) {
    return p >= 1 && p <= 5;
}

// Função para exibir a cor correspondente à prioridade
std::string getColorFromPriority(int p) {
    switch (p) {
        case 1: return "Vermelho";
        case 2: return "Laranja";
        case 3: return "Amarelo";
        case 4: return "Verde";
        case 5: return "Azul";
        default: return "Desconhecido";
    }
}
