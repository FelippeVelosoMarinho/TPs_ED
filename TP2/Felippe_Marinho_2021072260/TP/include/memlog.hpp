//---------------------------------------------------------------------
// Arquivo      : memlog.hpp
// Conteudo     : Classe memlog
// Autor        : Felippe Veloso Marinho. (felippe.veloso15@gmail.com)
// Historico    : 10/06/2023 - arquivo criado
//---------------------------------------------------------------------

#include <iostream>
#include <time.h>

// defines do msgasserts
#define avisoAssert(e, m) ((void)((e) ? 0 : __avisoassert(#e, __FILE__, __LINE__, m)))
#define __avisoassert(e, file, line, m) ((void)fprintf(stderr, "%s:%u: Aviso: '%s' - %s\n", file, line, e, m), 0)
#define erroAssert(e, m) ((void)((e) ? 0 : __erroassert(#e, __FILE__, __LINE__, m)))
#define __erroassert(e, file, line, m) ((void)fprintf(stderr, "%s:%u: Erro '%s' - %s\n", file, line, e, m), abort(), 0)

// constantes definindo os estados de registro
#define MLATIVO 1
#define MLINATIVO 0

#define LEMEMLOG(pos, tam, id) \
    ((void)((ml.ativo == MLATIVO) ? leMemLog(pos, tam, id) : 0));

#define ESCREVEMEMLOG(pos, tam, id) \
    ((void)((ml.ativo == MLATIVO) ? escreveMemLog(pos, tam, id) : 0));

typedef struct memlog
{
    FILE *log;
    clockid_t clk_id;
    struct timespec inittime;
    long count;
    int fase;
    int ativo;
} memlog_tipo;
extern memlog_tipo ml;

// funcoes da memlog
int iniciaMemLog(char *nome);
int ativaMemLog();
int desativaMemLog();
int defineFaseMemLog(int f);
int leMemLog(long int pos, long int tam, int id);
int escreveMemLog(long int pos, long int tam, int id);
int finalizaMemLog();
