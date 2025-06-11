#include <iostream>
#include <vector>
#include <string>
#include <chrono> // para medir tempo
using namespace std;
using namespace std::chrono;

struct Paciente {
    string nome;
    int prioridade;
};

void imprimirPacientes(const vector<Paciente>& pacientes) {
    for (const auto& p : pacientes) {
        cout << "Nome: " << p.nome << ", Prioridade: " << p.prioridade << endl;
    }
    cout << "-----------------------------" << endl;
}

void bubbleSort(vector<Paciente>& pacientes) {
    int n = pacientes.size();
    for (int i = 0; i < n - 1; i++) {
        bool trocou = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (pacientes[j].prioridade > pacientes[j + 1].prioridade) {
                swap(pacientes[j], pacientes[j + 1]);
                trocou = true;
            }
        }
        if (!trocou) break;
    }
}

void selectionSort(vector<Paciente>& pacientes) {
    int n = pacientes.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (pacientes[j].prioridade < pacientes[minIndex].prioridade) {
                minIndex = j;
            }
        }
        swap(pacientes[i], pacientes[minIndex]);
    }
}

int main() {
    vector<Paciente> base = {
        {"Ana", 5}, {"Pedro", 2}, {"Carla", 4}, {"Lucas", 1},
        {"Mariana", 3}, {"Fernanda", 5}, {"Rafael", 2},
        {"Beatriz", 4}, {"Guilherme", 1}, {"Sofia", 3}
    };

    string metodo;
    cout << "Escolha o metodo de ordenacao (bubble / selection): ";
    cin >> metodo;

    vector<Paciente> pacientes = base;  // cópia da lista original

    auto inicio = high_resolution_clock::now(); // início do tempo

    if (metodo == "bubble") {
        bubbleSort(pacientes);
    } else if (metodo == "selection") {
        selectionSort(pacientes);
    } else {
        cout << "Método inválido." << endl;
        return 1;
    }

    auto fim = high_resolution_clock::now(); // fim do tempo

    cout << "\nPacientes ordenados por prioridade (" << metodo << " sort):\n";
    imprimirPacientes(pacientes);

    auto duracao = duration_cast<nanoseconds>(fim - inicio).count();
    cout << "Tempo de execucao: " << duracao << " nanosegundos\n";

    return 0;
}
