#include <stdio.h>
#include <sys/time.h>
#include "../include/tmp.hpp"
#include "../include/arvexp.hpp"

int main(int argc, char *argv[])
{
    Tmp t;
    Registro x;
    Pagina *D;
    stat_t st;
    exp_t exp;

    struct rusage start, end; // Structs para medir o tempo de execução

    srand(time(NULL));

    int i, j, op;

    exp.print = 0;
    exp.seed = 1;
    exp.numops = 10000;
    exp.maxch = 100;
    exp.op[PESQUISA] = 0.4;
    exp.op[INSERE] = 0.7;
    exp.op[RETIRA] = 1.0;

    srand48((unsigned int)exp.seed);

    Inicializa(&D);

    for (i = 0; i < exp.numops; i++)
    {
        // define op
        double opaux = drand48();
        for (op = 0; op < 3; op++)
        {
            if (opaux < exp.op[op])
            {
                break;
            }
        }

        // define chave
        x.Chave = (long)(exp.maxch * drand48());

        if (exp.print)
        {
            printf("i %d opaux %f op %d x %ld\n", i, opaux, op, x.Chave);
        }

        switch (op)
        {
        case PESQUISA:
            getrusage(RUSAGE_SELF, &start);
            Pesquisa(&x, D);
            getrusage(RUSAGE_SELF, &end);
            printf("Pesquisa -> %.6fs", t.diffUserTime(&start, &end));
            break;
        case INSERE:
            getrusage(RUSAGE_SELF, &start);
            Insere(x, &D);
            getrusage(RUSAGE_SELF, &end);
            printf("Insere -> %.6fs", t.diffUserTime(&start, &end));
            break;
        case RETIRA:
            getrusage(RUSAGE_SELF, &start);
            Retira(x.Chave, &D);
            getrusage(RUSAGE_SELF, &end);
            printf("Retira -> %.6fs", t.diffUserTime(&start, &end));
            break;
        }
        if (exp.print)
            Imprime(D, stdout, &st, "");
    }

    return 0;
}