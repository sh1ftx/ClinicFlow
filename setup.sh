#!/bin/bash

# Função para verificar se o comando existe
command_exists() {
    command -v "$1" &> /dev/null
}

# Instalação do gcc e make no Linux
install_linux() {
    echo "Detectado sistema Linux."

    if ! command_exists g++ || ! command_exists make; then
        echo "g++ e/ou make não encontrados. Instalando..."
        sudo pacman -S --noconfirm gcc make
    else
        echo "g++ e make já estão instalados."
    fi
}

# Instalação do Xcode Command Line Tools no macOS
install_mac() {
    echo "Detectado sistema macOS."

    if ! command_exists g++ || ! command_exists make; then
        echo "g++ e make não encontrados. Instalando..."
        xcode-select --install
    else
        echo "g++ e make já estão instalados."
    fi
}

# Instalação do MinGW no Windows
install_windows() {
    echo "Detectado sistema Windows."

    # Instruções de instalação do MinGW
    echo "Para compilar no Windows, você precisa instalar o MinGW ou usar WSL (Windows Subsystem for Linux)."
    echo "Siga os passos abaixo para instalar o MinGW: https://www.msys2.org/"
}

# Função para rodar o make
run_make() {
    echo "Compilando o projeto..."
    make

    # Verifica se a compilação foi bem-sucedida
    if [ -f "build/hospital_simulator" ]; then
        echo "Compilação concluída com sucesso!"
        echo "Rodando o programa..."
        ./build/hospital_simulator
    else
        echo "Falha na compilação. Verifique o Makefile e os arquivos fonte."
    fi
}

# Verifica o sistema operacional
OS=$(uname)

case "$OS" in
    "Linux")
        # Verifica o tipo de distribuição para saber qual gerenciador de pacotes usar
        if [ -f "/etc/arch-release" ]; then
            install_linux
        else
            echo "Distribuição Linux não detectada como Arch. Adaptando para outro SO."
            sudo apt update && sudo apt install -y build-essential
        fi
        ;;
    "Darwin")
        install_mac
        ;;
    *)
        install_windows
        ;;
esac

# Verifica a existência do Makefile
if [ ! -f "Makefile" ]; then
    echo "Makefile não encontrado! Certifique-se de que o repositório foi clonado corretamente."
    exit 1
fi

# Cria diretório build se não existir
if [ ! -d "build" ]; then
    echo "Diretório 'build' não encontrado. Criando..."
    mkdir build
fi

# Executa a função de compilação
run_make
