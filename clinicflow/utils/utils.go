package utils

func GetPriorityColor(priority int) string {
	switch priority {
	case 1:
		return "Vermelho"
	case 2:
		return "Laranja"
	case 3:
		return "Amarelo"
	case 4:
		return "Verde"
	case 5:
		return "Azul"
	default:
		return "Desconhecido"
	}
}
