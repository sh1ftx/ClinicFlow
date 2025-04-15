#include "PriorityQueue.h"
#include <iostream>
#include <algorithm>
#include <fstream>  // Para escrita de arquivos

// Adiciona um paciente à fila, mantendo a ordem de prioridade
void PriorityQueue::addPatient(const Patient& p) {
    queue.push_back(p);
    std::sort(queue.begin(), queue.end(), [](const Patient& a, const Patient& b) {
        return a.priority < b.priority;  // Menor prioridade vem primeiro
    });
}

// Atende o paciente com a maior prioridade e o remove da fila
Patient PriorityQueue::attendPatient() {
    if (!queue.empty()) {
        Patient p = queue.front();  // O paciente com maior prioridade (menor número)
        queue.erase(queue.begin()); // Remove da fila
        attended.push_back(p);      // Adiciona à lista de atendidos
        return p;
    }
    throw std::out_of_range("Fila vazia");
}

// Lista todos os pacientes na fila, incluindo suas prioridades e cores
void PriorityQueue::listPatients() const {
    for (const auto& p : queue) {
        std::cout << p.name << " - Prioridade: " << p.getPriorityColor() << std::endl;
    }
}

// Lista todos os pacientes atendidos
void PriorityQueue::listAttended() const {
    for (const auto& p : attended) {
        std::cout << p.name << " - Atendido" << std::endl;
    }
}

// Busca um paciente pelo nome
Patient* PriorityQueue::searchPatient(const std::string& name) {
    for (auto& p : queue) {
        if (p.name == name) {
            return &p;
        }
    }
    return nullptr;
}

// Calcula o tempo médio de espera
double PriorityQueue::getAverageWaitTime() const {
    if (attended.empty()) return 0.0;

    double totalWaitTime = 0.0;
    std::time_t now = std::time(nullptr);
    for (const auto& p : attended) {
        totalWaitTime += p.getWaitTime(now);
    }

    return totalWaitTime / attended.size();
}

// Exporta o relatório dos pacientes atendidos para um arquivo
void PriorityQueue::exportReport(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& p : attended) {
            file << p.name << " - Prioridade: " << p.getPriorityColor() << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Não foi possível abrir o arquivo para escrita." << std::endl;
    }
}
