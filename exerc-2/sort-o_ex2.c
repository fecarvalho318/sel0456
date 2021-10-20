#include <stdlib.h>
#include <stdio.h>
#include <glib.h>
#include <string.h>

#define ERRO (-32000)

typedef struct ITEM ITEM;
struct ITEM {
    char *data;
    int key;
};

ITEM *item_init(char *data, int key);
int item_apagar(ITEM **item);
char *item_get_data(ITEM *item);
int item_get_key(ITEM *item);

gint compare_item(gconstpointer a, gconstpointer b);
void print_item(gpointer data, gpointer user_data);
ITEM * item_init(char * data, int key);
void item_destroy(gpointer _self, gpointer unused_data);


void sort(ITEM **a, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++)
            if(item_get_key(a[j]) > item_get_key(a[j+1])) {
                ITEM *t;
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
    }
}

char s1[40];

int main(void) {
    char *s = "bill";
    GList *list = g_list_append(NULL, item_init(s, 3));
    s = "neil";
    list = g_list_insert_sorted(list, item_init(s, 4), compare_item);
    strcpy(s1, "john");
    list = g_list_insert_sorted(list, item_init(s1, 2), compare_item);
    strcpy(s1, "sara");
    list = g_list_insert_sorted(list, item_init(s1, 7), compare_item);
    list = g_list_insert_sorted(list, item_init("rick", 5), compare_item);
    list = g_list_insert_sorted(list, item_init("alex", 1), compare_item);

    list = g_list_first(list);

    int i = 0;
    g_list_foreach(list, print_item, &i);

    /* limpando toda a lista e suas estruturas */
    list = g_list_first(list);
    g_list_foreach(list, item_destroy, NULL);
    g_list_free(list);

    return 0;
}


//Funções auxiliares usadas para programação com orientação a objetos
int item_apagar(ITEM **item) {
    if((*item) != NULL) {
        free((*item)->data);
        free((*item));
        (*item) = NULL;
        return 1;
    }
    return 0;
}

char *item_get_data(ITEM *item) {
    if(item != NULL) {
        return item->data;
    }
    return NULL;
}
int item_get_key(ITEM *item) {
    if(item != NULL) {
        return item->key;
    }
    return ERRO;
}

//Funcoes exercicio 2 usando biblioteca glib
gint compare_item(gconstpointer a, gconstpointer b) {
    if (((ITEM *)a)->key < ((ITEM *)b)->key)
        return -1;
    else if (((ITEM *)a)->key > ((ITEM *)b)->key)
        return 1;
    else
        return 0;
}

void print_item(gpointer data, gpointer user_data) {
    int *i = (int *) user_data;
    printf("No. %d -> key=%d: %s\n", *i + 1, ((ITEM *)data)->key, ((ITEM *)data)->data);
    (*i)++;
}
ITEM *item_init(char * data, int key) {
    ITEM * self = malloc(sizeof(ITEM));
    self->key = key;
    self->data = strdup(data);
    return self;
}

void item_destroy(gpointer _self, gpointer unused_data) {
    ITEM *self = (ITEM *) _self;
    free(self->data);
    free(self);
}
