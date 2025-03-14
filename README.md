# Árvore Binária de Pesquisa (ABP)

## Descrição
Este projeto implementa uma Árvore Binária de Pesquisa (ABP) em C, permitindo a manipulação de dados de forma estruturada. Há duas versões da implementação:
1. Manipulação de números inteiros.
2. Gerenciame

to de alunos, incluindo nome, matrícula e nota.

O usuário pode criar a árvore, inserir elementos, buscar valores, remover nós e imprimir a árvore em diferentes ordens.

---



## Funcionalidades

### Para a versão com números inteiros:
- Criar uma árvore binária de pesquisa.
- Inserir elementos.
- Buscar elementos.
- Remover elementos.
- Imprimir a árvore em ordem, pré-ordem e pós-ordem.
- Contar o total de nós.
- Destruir a árvore.

### Para a versão com alunos:
- Criar uma árvore binária de pesquisa.
- Inserir um aluno (nome, matrícula e nota).
- Buscar um aluno pelo nome.
- Remover um aluno.
- Imprimir a árvore em ordem.
- Encontrar e imprimir o aluno com a maior nota.
- Encontrar e imprimir o aluno com a menor nota.
- Destruir a árvore.

---

## Compilação e Execução

### Compilar o código:
```sh
gcc main.c ABP.c -o abp
```

Para a versão com alunos:
```sh
gcc main_aluno.c ABP.c -o abp_aluno
```

### Executar:
```sh
./abp
```

Ou, para a versão de alunos:
```sh
./abp_aluno
```

---

## Estrutura do Código

- `main.c` - Programa principal para manipulação de números inteiros.
- `main_aluno.c` - Programa principal para manipulação de alunos.
- `ABP.c` - Implementação das funções de manipulação da árvore.
- `ABP.h` - Cabeçalho contendo as declarações das funções.
- `aluno.h` - Definição da estrutura do aluno (usada na versão com alunos).

---

## Autor
Desenvolvido por [Seu Nome].

