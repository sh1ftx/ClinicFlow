#include <iostream>
#include <string>
#include "PriorityQueue.h"
#include "utils.h"

// Função para mostrar o menu de opções
void showMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Adicionar paciente\n";
    std::cout << "2. Atender paciente\n";
    std::cout << "3. Listar pacientes na fila\n";
    std::cout << "4. Listar pacientes atendidos\n";
    std::cout << "5. Calcular tempo médio de espera\n";
    std::cout << "6. Exportar relatório\n";
    std::cout << "7. Sair\n";
    std::cout << "Escolha uma opção: ";
}

int main() {
    PriorityQueue queue;  // Fila de pacientes
    int choice;  // Opção escolhida pelo usuário

    while (true) {
        showMenu();  // Exibe o menu
        std::cin >> choice;  // Recebe a escolha

        if (choice == 1) {
            std::string name;
            int priority;

            // Entrada de dados do paciente
            std::cout << "Digite o nome do paciente: ";
            std::cin.ignore();  // Limpa o buffer de entrada
            std::getline(std::cin, name);  // Lê o nome completo do paciente

            std::cout << "Digite a prioridade do paciente (1 a 5): ";
            std::cin >> priority;

            // Valida a prioridade
            if (!isValidPriority(priority)) {
                std::cout << "Prioridade inválida! Deve ser entre 1 e 5.\n";
                continue;
            }

            // Adiciona o paciente à fila
            Patient p(name, priority);
            queue.addPatient(p);
            std::cout << "Paciente " << name << " adicionado à fila.\n";

        } else if (choice == 2) {
            try {
                // Atende o paciente com maior prioridade
                Patient attended = queue.attendPatient();
                std::cout << "Paciente " << attended.name << " atendido! Prioridade: " 
                          << attended.getPriorityColor() << "\n";
            } catch (const std::out_of_range& e) {
                std::cout << "Erro: " << e.what() << "\n";
            }

        } else if (choice == 3) {
            std::cout << "\nPacientes na fila:\n";
            queue.listPatients();  // Lista todos os pacientes na fila

        } else if (choice == 4) {
            std::cout << "\nPacientes atendidos:\n";
            queue.listAttended();  // Lista os pacientes atendidos

        } else if (choice == 5) {
            // Calcula o tempo médio de espera
            double avgWaitTime = queue.getAverageWaitTime();
            std::cout << "Tempo médio de espera: " << avgWaitTime << " segundos\n";

        } else if (choice == 6) {
            std::string filename;
            std::cout << "Digite o nome do arquivo para exportar o relatório: ";
            std::cin >> filename;
            queue.exportReport(filename);  // Exporta os dados para um arquivo
            std::cout << "Relatório exportado para " << filename << ".\n";

        } else if (choice == 7) {
            std::cout << "Saindo...\n";
            break;  // Encerra o programa

        } else {
            std::cout << "Opção inválida! Tente novamente.\n";
        }
    }

    return 0;
}
