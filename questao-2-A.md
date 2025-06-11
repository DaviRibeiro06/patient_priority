
## ❓ Qual algoritmo seria mais eficiente se a lista estiver quase ordenada? Por quê?

Se a lista estiver **quase ordenada**, o algoritmo **Bubble Sort** é mais eficiente do que o **Selection Sort**.

### ✅ Justificativa:

O **Bubble Sort** percorre a lista comparando **pares consecutivos** e, com uma pequena otimização (uso de uma flag de troca), ele pode **encerrar a ordenação antes do fim** se perceber que a lista já está ordenada. Isso faz com que, em cenários onde os dados estão quase na ordem correta, seu desempenho seja **quase linear** (melhor caso: `O(n)`).

Já o **Selection Sort** **não se beneficia de listas quase ordenadas**. Ele percorre toda a lista em cada iteração para encontrar o menor elemento, realizando sempre o mesmo número de comparações e trocas, **independente da ordem inicial** da lista.

---

### 📊 Comparativo: Bubble Sort vs Selection Sort em listas quase ordenadas

| Critério                            | Bubble Sort            | Selection Sort          |
|-------------------------------------|-------------------------|--------------------------|
| Detecta ordenação antecipada        | ✅ Sim                  | ❌ Não                   |
| Reduz número de iterações           | ✅ Sim                  | ❌ Não                   |
| Complexidade no melhor caso         | **O(n)**                | **O(n²)**                |
| Eficiência em lista quase ordenada  | **Alta**                | **Baixa**                |

---

### ✅ Conclusão:

> Em listas quase ordenadas, o **Bubble Sort** é preferível por conseguir interromper o processo mais cedo, economizando tempo de execução.  
> O **Selection Sort** tem comportamento constante e não otimiza com base na ordenação prévia dos dados.
