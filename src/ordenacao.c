#include "ordenacao.h"
#include "medicao.h"

/* ===================== TAREFA 1: ORDENAÇÃO =====================
   Ordene v em ordem CRESCENTE de matrícula.
   A cada comparação entre duas matrículas, faça comparacoes++.
   Dica: copie o Aluno inteiro (struct), não só a matrícula. */

void ordena_insercao(Aluno *v, int n) {
    int i, j;
    Aluno chave;

    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;

        while (j >= 0) {
            comparacoes++;
            if (v[j].matricula > chave.matricula) {
                v[j + 1] = v[j];
                j--;
            } else {
                break;
            }
        }
        v[j + 1] = chave;
    }
}

static void quick(Aluno *v, int ini, int fim) {
    int i = ini, j = fim;
    int pivo_matricula = v[(ini + fim) / 2].matricula;

    while (i <= j) {
        while (1) {
            comparacoes++;
            if (v[i].matricula < pivo_matricula) {
                i++;
            } else {
                break;
            }
        }

        while (1) {
            comparacoes++;
            if (v[j].matricula > pivo_matricula) {
                j--;
            } else {
                break;
            }
        }

        if (i <= j) {
            Aluno temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }

    if (ini < j) {
        quick(v, ini, j);
    }
    if (i < fim) {
        quick(v, i, fim);
    }
}

void ordena_quick(Aluno *v, int n) {
    if (n > 1) {
        quick(v, 0, n - 1);
    }

    /* TODO: Insertion Sort.
       Para cada i de 1 a n-1: guarde x = v[i]; ande para a esquerda
       deslocando os alunos com matrícula maior que x.matricula;
       coloque x no espaço que sobrou. */
    (void)v; (void)n;
}

void ordena_quick(Aluno *v, int n) {
    /* TODO: Quicksort.
       Use como pivô a matrícula do elemento do meio.
       Crie uma função auxiliar recursiva quick(v, ini, fim) e chame
       quick(v, 0, n - 1) aqui. */
    (void)v; (void)n;
}
