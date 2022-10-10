#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
insertion_sort_list - sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm

@list: double pointer to the list head to be sorted
*/

void insertion_sort_list(listint_t **list)
{
  listint_t *head, *temp, *curr;

  if(list == NULL || *list == NULL || (*list)->next == NULL)
    return;

  head = *list;
  curr = head->next;

  while(curr)
    {
      while(curr->prev && curr->n < (curr->prev)->n)
        {
          temp = curr; // hold current node

          //link the nodes immediately before and after our current node
          if(curr->next != NULL) //if not the last node
            (curr->next)->prev = temp->prev;
          (curr->prev)->next = temp->next;
          //prev node and next nodes linked
          
          curr = curr->prev;//substitute the current node with the previous node

          //hanging node
          temp->prev = curr->prev; //previous node
          temp->next = curr; //

          if(curr->prev)//not the first node
            (curr->prev)->next = temp;
          curr->prev = temp;

          if(temp->prev == NULL)
            *list = temp;
          print_list(*list);
          curr = curr->prev;
        }
      curr = curr->next;
    }
}