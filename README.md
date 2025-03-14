# Árvores Binárias de Pesquisa (ABP)

## Descrição
Este projeto implementa Árvores Binárias de Pesquisa (ABP) em C, permitindo a criação, manipulação e consulta de árvores contendo números inteiros e informações de alunos.

## Funcionalidades
O projeto possui dois programas principais:

1. **ABP.c** - Implementa uma árvore binária de pesquisa para armazenar e manipular números inteiros.
2. **alunos.c** - Extensão do ABP para armazenar informações de alunos (nome, matrícula e nota).

### Operações disponíveis
Para ambos os programas, as seguintes operações estão disponíveis:

- Criar uma árvore binária de pesquisa.
- Inserir elementos na árvore.
- Buscar elementos.
- Remover elementos.
- Imprimir a árvore em ordem, pré-ordem e pós-ordem.
- Contar o total de nós na árvore.
- Destruir a árvore.
- Encontrar o aluno com maior e menor nota (somente em `alunos.c`).

## Estrutura do Código
O projeto contém os seguintes arquivos:

- **ABP.c**: Código principal para manipulação de ABP de números inteiros.
- **ABP.h**: Cabeçalho com as definições das funções e estrutura da árvore.
- **alunos.c**: Código principal para manipulação de ABP de alunos.
- **f_ABP.c**: Implementação das funções da árvore.
- **aluno.h**: Cabeçalho com a estrutura de dados para armazenar informações dos alunos.

## Compilação e Execução
Para compilar o projeto, utilize um compilador como `gcc`. Por exemplo:

```sh
# Compilar o programa ABP de números inteiros
gcc ABP.c f_ABP.c -o abp

# Compilar o programa de alunos
gcc alunos.c f_ABP.c -o alunos
```

Para executar:
```sh
./abp   # Executa o programa de números inteiros
./alunos # Executa o programa de alunos
```

## Exemplo de Uso
### ABP (Números Inteiros)
```
Escolha uma opção:
1 * Criar uma árvore (binária de pesquisa)
2 * Adicionar um elemento na árvore
3 * Buscar um elemento na árvore
4 * Remover um elemento na árvore
...
```

### Alunos
```
Escolha uma opção:
1 * Criar uma árvore (binária de pesquisa)
2 * Adicionar um aluno
3 * Buscar um aluno pelo nome
4 * Remover um aluno
...
```

## Observações
- O programa possui verificações para garantir que a árvore seja criada antes de operações como inserção e busca.
- O usuário pode sair do programa escolhendo a opção correspondente no menu.

## Autores
- Tony Hudson Candido Junior

