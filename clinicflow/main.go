package main

import (
	"bufio"
	"clinicflow/patient"
	"clinicflow/queue"
	"clinicflow/utils"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	q := queue.PriorityQueue{}

	for {
		fmt.Println("\n------------------------------")
		fmt.Println("🏥  ClinicFlow - Menu Principal")
		fmt.Println("------------------------------")
		fmt.Println("1. Adicionar paciente")
		fmt.Println("2. Chamar próximo paciente")
		fmt.Println("3. Listar fila de espera")
		fmt.Println("4. Sair")
		fmt.Print("Escolha: ")

		scanner.Scan()
		input := scanner.Text()
		choice, err := strconv.Atoi(input)
		if err != nil {
			fmt.Println("⚠️  Entrada inválida.")
			continue
		}

		switch choice {
		case 1:
			fmt.Print("Nome do paciente: ")
			scanner.Scan()
			name := scanner.Text()

			fmt.Print("Prioridade (1 a 5): ")
			scanner.Scan()
			priStr := scanner.Text()
			priority, err := strconv.Atoi(priStr)
			if err != nil || priority < 1 || priority > 5 {
				fmt.Println("⚠️  Prioridade inválida.")
				continue
			}

			newPatient := patient.NewPatient(name, priority)
			q.Add(newPatient)
			fmt.Printf("✅ Paciente %s adicionado com prioridade %s.\n", newPatient.Name, utils.GetPriorityColor(priority))

		case 2:
			p, ok := q.Remove()
			if !ok {
				fmt.Println("🕓 Nenhum paciente na fila.")
			} else {
				fmt.Printf("🎙️ Chamando %s (Prioridade: %s)\n", p.Name, utils.GetPriorityColor(p.Priority))
			}

		case 3:
			fmt.Println("\n📋 Fila de espera:")
			for i, p := range q.GetList() {
				fmt.Printf("%d. %s - Prioridade: %s\n", i+1, p.Name, utils.GetPriorityColor(p.Priority))
			}

		case 4:
			fmt.Println("👋 Encerrando o sistema.")
			return

		default:
			fmt.Println("❌ Opção inválida.")
		}
	}
}
