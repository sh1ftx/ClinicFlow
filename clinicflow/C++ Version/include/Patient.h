#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <ctime>

// Classe que representa um paciente no hospital
class Patient {
public:
    std::string name;     // Nome do paciente
    int priority;         // Prioridade de atendimento (1 a 5)
    std::time_t timeIn;   // Tempo de entrada (timestamp)

    // Construtor da classe Patient
    Patient(std::string name, int priority);

    // Retorna a cor associada à prioridade do paciente
    std::string getPriorityColor() const;

    // Calcula o tempo de espera do paciente (em segundos)
    int getWaitTime(std::time_t now) const;
};

#endif
