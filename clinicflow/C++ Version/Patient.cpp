#include "Patient.h"
#include <ctime>  // Para manipulação de data/hora

// Construtor que inicializa um paciente
Patient::Patient(std::string name, int priority) {
    this->name = name;
    this->priority = priority;
    this->timeIn = std::time(nullptr);  // Marca o tempo de entrada do paciente
}

// Retorna a cor associada à prioridade do paciente
std::string Patient::getPriorityColor() const {
    switch (priority) {
        case 1: return "Vermelho";  // Emergência
        case 2: return "Laranja";   // Muito urgente
        case 3: return "Amarelo";   // Urgente
        case 4: return "Verde";     // Pouco urgente
        case 5: return "Azul";      // Não urgente
        default: return "Desconhecido";
    }
}

// Calcula o tempo de espera do paciente
int Patient::getWaitTime(std::time_t now) const {
    return static_cast<int>(now - timeIn);  // Retorna a diferença de tempo em segundos
}
