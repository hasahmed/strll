#include <stdlib.h>
#include <stdio.h>
#include "strll.h"
int main(){
    strll *ll = strll_new();

    /*strll_entry *new_entry = strll_new_entry("ayee");*/

    /*printf("%s\n", new_entry->str);*/
    /*ll->next = new_entry;*/
    /*new_entry->prev = ll;*/
    /*new_entry->next = NULL;*/
    /*strll_free_entry(new_entry);*/

    char *c;


    strll_insert(ll, "tacos");
    strll_insert(ll, "tacos");
    strll_insert(ll, "tacos");
    strll_insert(ll, "tacos");
    strll_insert(ll, "tacos");
    strll_insert(ll, "tacos");
    printf("has acos %d\n", strll_has_entry(ll, "acos"));
    printf("has tacos %d\n", strll_has_entry(ll, "tacos"));
    printf("has " " %d\n", strll_has_entry(ll, " "));
    strll_print(ll);
    strll_free(ll);
}
