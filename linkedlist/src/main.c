#include <stdio.h>
#include "linkedlist.h"

int main() {
    printf("=== LinkedList Demo ===\n\n");
    
    // 1. Criar lista
    linkedlist* list = list_create();
    if(!list) {
        printf("Erro ao criar lista!\n");
        return 1;
    }
    printf("✓ Lista criada\n");
    
    // 2. Verificar se está vazia
    printf("Lista vazia? %s\n", list_is_empty(list) ? "Sim" : "Não");
    printf("Tamanho inicial: %d\n\n", list_size(list));
    
    // 3. Adicionar elementos no final
    printf("Adicionando elementos no final: 10, 20, 30\n");
    list_append(list, 10);
    list_append(list, 20);
    list_append(list, 30);
    list_print(list);
    printf("Tamanho: %d\n\n", list_size(list));
    
    // 4. Adicionar elementos no início
    printf("Adicionando elementos no início: 5, 1\n");
    list_prepend(list, 5);
    list_prepend(list, 1);
    list_print(list);
    printf("Tamanho: %d\n\n", list_size(list));
    
    // 5. Buscar elementos
    printf("Procurando elementos:\n");
    int* found = list_find(list, 20);
    printf("Buscar 20: %s\n", found ? "Encontrado" : "Não encontrado");
    found = list_find(list, 99);
    printf("Buscar 99: %s\n\n", found ? "Encontrado" : "Não encontrado");
    
    // 6. Remover do início
    printf("Removendo do início:\n");
    list_remove_head(list);
    list_print(list);
    printf("Tamanho: %d\n\n", list_size(list));
    
    // 7. Remover do fim
    printf("Removendo do fim:\n");
    list_remove_tail(list);
    list_print(list);
    printf("Tamanho: %d\n\n", list_size(list));
    
    // 8. Remover elemento específico
    printf("Removendo elemento 20:\n");
    list_remove(list, 20);
    list_print(list);
    printf("Tamanho: %d\n\n", list_size(list));
    
    // 9. Adicionar mais elementos para testar
    printf("Adicionando mais elementos: 100, 200\n");
    list_append(list, 100);
    list_prepend(list, 200);
    list_print(list);
    
    // 10. Testar remoção até ficar vazio
    printf("\nEsvaziando a lista:\n");
    while(!list_is_empty(list)) {
        printf("Removendo head... ");
        list_remove_head(list);
        list_print(list);
        printf("Tamanho: %d\n", list_size(list));
    }
    
    printf("\nLista vazia? %s\n", list_is_empty(list) ? "Sim" : "Não");
    
    // 11. Destruir lista
    list_destroy(list);
    printf("\n✓ Lista destruída\n");
    
    printf("\n=== Teste Concluído ===\n");
    return 0;
}