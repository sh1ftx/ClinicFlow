package patient

import "time"

type Patient struct {
	Name     string
	Priority int   // de 1 a 5
	TimeIn   int64 // timestamp de entrada
}

// Criar paciente

func NewPatient(name string, priority int) Patient {
	return Patient{
		Name:     name,
		Priority: priority,
		TimeIn:   time.Now().Unix(),
	}
}
