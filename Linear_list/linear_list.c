//
// Created by marco on 13/09/2024.
//
/*Management Functions

Implement functions to:

Initialize the structure
Return the quantity of valid elements
Display the elements of the structure
Search for an element in the structure
Insert elements into the structure
Remove elements from the structure
Reinitialize the structure*/

#include <stdbool.h>
#include <stdio.h>

#define Max 20

typedef int KEYTYPE;

typedef struct
{
    KEYTYPE key;
}Registry;

typedef struct
{
    Registry A[Max];
    int Elem_Num;
}List;

//Initialize the structure
void init_struc(List *l)
{
    l->Elem_Num = 0;
}

//Return the quantity of valid elements
int size_list(const List* l)
{
    return l->Elem_Num;
}

//Display the elements of the structure
void display_list(const List* l)
{
    printf("Lista: \"");
    for (int i = 0;i < l->Elem_Num; i++)
    {
        printf("%d", l->A[i].key);
        if (i < l->Elem_Num - 1)
            printf(",");
    }
    printf("\"\n");
}

//Search for an element in the structure
int search_element(const List *l, const KEYTYPE k )
{
    for (int i = 0;i < l->Elem_Num;i++)
    {
        if (l->A[i].key == k)
            return i;
    }
    return -1;
}

//Insert elements into the structure
bool insert_element(List *l, const Registry reg, const KEYTYPE i)
{
    if ((l->Elem_Num == Max) || (i < 0) || (i > l->Elem_Num))
        return false;
    for (int j = l->Elem_Num; j > i; j--) {l->A[j] = l->A[j-1];}
    l->A[i] = reg;
    l->Elem_Num++;
    return true;
}

//Remove elements from the structure
bool delete_element(List *l,KEYTYPE k)
{
    int i = search_element(l,k);
    if (i != -1)
    {
        for (int j = i; j < l->Elem_Num;j++)
        {
            l->A[j] = l->A[j + 1];
        }
        l->Elem_Num--;
        return true;
    }
        return false;
}



int main(void)
{
    List Elements_names = {7,2,3,4,5};
    init_struc(&Elements_names);
    Elements_names.Elem_Num = 5;
    //printf("%d\n", Elements_names.Elem_Num);
    size_list(&Elements_names);
    display_list(&Elements_names);
    Registry b = {8};
    insert_element(&Elements_names,b,0);
    display_list(&Elements_names);
    //search_element(&Elements_names,(0));
    delete_element(&Elements_names,(2));
    display_list(&Elements_names);


    return 0;
}


