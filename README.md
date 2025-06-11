# 🏥 Questão 2 — Ordenação de Pacientes por Prioridade

## 📌 Enunciado

Um hospital precisa ordenar uma lista de pacientes por prioridade (1 = urgente a 5 = não urgente). Os dados chegam em ordem aleatória.

**Dica:** Para representar cada paciente, utilize uma `struct` com nome (string) e prioridade (int).  
A lista de pacientes será um vetor dessas structs:

```cpp
{ {"Ana", 5}, {"Pedro", 2}, {"Carla", 4}, {"Lucas", 1},
  {"Mariana", 3}, {"Fernanda", 5}, {"Rafael", 2},
  {"Beatriz", 4}, {"Guilherme", 1}, {"Sofia", 3} }
```

---

## ✅ Estrutura de Dados

```cpp
struct Paciente {
    string nome;
    int prioridade;
};
```

---

## 🔁 Algoritmo 1 — Bubble Sort

```cpp
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
```

---

## 🔁 Algoritmo 2 — Selection Sort

```cpp
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
```

---

## ✅ Conclusão

Em listas quase ordenadas, o **Bubble Sort** é mais eficiente, pois consegue detectar que a lista já está ordenada e **interromper a ordenação antecipadamente**, economizando processamento.

Já o **Selection Sort sempre percorre todo o restante da lista para encontrar o menor elemento, mesmo que a lista já esteja quase em ordem**. Isso significa que ele **executa o mesmo número de comparações e trocas** independentemente da disposição inicial dos dados, tornando-se menos eficiente nesse tipo de situação.
