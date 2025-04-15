package queue

import (
	"clinicflow/patient"
	"sort"
)

type PriorityQueue struct {
	list []patient.Patient
}

// Adiciona um paciente à fila e ordena por prioridade
func (q *PriorityQueue) Add(p patient.Patient) {
	q.list = append(q.list, p)

	// Ordenar a lista por prioridade crescente (1 = mais urgente)
	sort.SliceStable(q.list, func(i, j int) bool {
		return q.list[i].Priority < q.list[j].Priority
	})
}

// Remove e retorna o próximo paciente (maior prioridade)
func (q *PriorityQueue) Remove() (patient.Patient, bool) {
	if len(q.list) == 0 {
		return patient.Patient{}, false
	}
	p := q.list[0]
	q.list = q.list[1:]
	return p, true
}

// Retorna todos os pacientes na fila
func (q *PriorityQueue) GetList() []patient.Patient {
	return q.list
}
