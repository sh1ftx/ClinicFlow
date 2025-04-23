#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include "Patient.h"

// Classe que representa uma fila de prioridade
class PriorityQueue {
private:
    std::vector<Patient> queue;    // Fila de pacientes
    std::vector<Patient> attended; // Lista de pacientes atendidos

public:
    // Adiciona um paciente à fila
    void addPatient(const Patient& p);

    // Atende o paciente com a maior prioridade e o remove da fila
    Patient attendPatient();

    // Lista todos os pacientes na fila (ordenada)
    void listPatients() const;

    // Lista todos os pacientes atendidos
    void listAttended() const;

    // Busca um paciente pelo nome
    Patient* searchPatient(const std::string& name);

    // Calcula o tempo médio de espera de todos os pacientes
    double getAverageWaitTime() const;

    // Exporta os dados dos pacientes atendidos para um arquivo de texto
    void exportReport(const std::string& filename) const;
};

#endif
