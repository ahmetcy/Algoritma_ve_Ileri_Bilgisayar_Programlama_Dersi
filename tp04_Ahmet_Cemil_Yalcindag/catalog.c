#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalog.h"

struct node* new_Node (char* name, char* album, char* artist, int date, float duration)
{
    struct node *new = malloc(sizeof(struct node)) ;
    new->name = name;
    new->album = album;
    new->artist = artist;
    new->date = date;
    new->duration = duration;
    new->next = NULL;
    return new;
}

struct node* push(struct node* top, char* name, char* album, char* artist, int date, float duration)
{
    struct node* n = malloc(sizeof(struct node));
    n->name = malloc(strlen(name) + 1); 
    strcpy(n->name, name); 

    n->album = malloc(strlen(album) + 1); 
    strcpy(n->album, album); 

    n->artist = malloc(strlen(artist) + 1); 
    strcpy(n->artist, artist); 

    n->date = date;
    n->duration = duration;
    n->next = top;
    top=n;
    return top;

}
void print_list(struct node* top)
{
    struct node *temp = top;
    if(temp==NULL)
    {
        printf("Stack is empty!");
    }
    while(temp != NULL)
    {
        printf("\nSong: %s\nAlbum: %s\nArtist: %s\nRelease Date: %d\nDuration of the Song: %.2f\n",temp->name, temp->album, temp->artist, temp->date, temp->duration);
        temp = temp->next;
    }
}

struct node* pop (struct node* top) 
{
    if(top!=NULL) 
    {
        struct node* temp = top ;
        top = top->next;
        free (temp);
    } 
    else
    {
        printf ("The playlist is already empty!");
    }
    return top;
}

int search_node(struct node* top, char* name) 
{
    struct node* temp = top;
    while (temp) 
    {
        if (strcmp(temp->name, name)==0) 
        {
            printf("YES, there is a song called '%s' in the playlist!",name);
            return 1;
        }
        temp = temp->next;
    }
    printf("Unfortunately, there isn't a song called '%s' in the playlist :c",name);
    return 0;
}

struct node* pop_stack(struct node* top)
{
    struct node* temp = top ;
    if(temp!=NULL) 
    {
        while (temp)
        {
            temp=top;
            top=top->next;
            free(temp);
        }
    } 
    else
    {
        printf ("The playlist is already empty!");
    }
    return top;
}

struct node* s_seek_and_destroy(struct node* top, char* name)
{
    if (top == NULL) {
        printf("The playlist is already empty!\n");
        return NULL;
    }

    struct node* current = top;
    struct node* tempStack = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) 
        {
            while (top != current) 
            {
                tempStack = push(tempStack, top->name, top->album, top->artist, top->date, top->duration);
                top = top->next;
            }

            struct node* temp = top;
            top = top->next;
            free(temp);

            while (tempStack != NULL) {
                top = push(top, tempStack->name, tempStack->album, tempStack->artist, tempStack->date, tempStack->duration);
                tempStack = pop(tempStack);
            }
            
            return top; 
        }
        current = current->next;
    }

    printf("The song '%s' is not found in the playlist.\n", name);
    return top; 
}

struct node* enqueue (struct node* head , char* name, char* album, char* artist, int date, float duration) 
{
    struct node *temp = head;
    struct node *n = malloc(sizeof(struct node));
    n->name = malloc(strlen(name) + 1); 
    strcpy(n->name, name); 

    n->album = malloc(strlen(album) + 1); 
    strcpy(n->album, album); 

    n->artist = malloc(strlen(artist) + 1);
    strcpy(n->artist, artist); 

    n->date = date;
    n->duration = duration;
    n->next = NULL;

    if(temp == NULL) 
    {
        head = n; 
    } 
    else 
    {
        while(temp->next != NULL)
        {
            temp = temp->next; 
        }
        temp->next = n; 
    }
    return head;
}

struct node* dequeue (struct node * head) 
{
    struct node* temp = head;
    if(temp != NULL) 
    {
        temp = head;
        head = head->next;
        free (temp);
    } 
    else 
    {
        printf ( "The playlist is already empty!") ;
        exit (1);
    }
    return head;
}

int erase_queue(struct node* head)
{
    struct node* temp = head;
    if(temp != NULL) 
    {
        while(temp)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    } 
    else 
    {
        printf ( "The playlist is already empty!") ;
        return 1;
    }
    return 0;
}

struct node* q_seek_and_destroy(struct node* head, char* name)
{
    if (head == NULL) {
        printf("The playlist is already empty!\n");
        return NULL;
    }

    struct node* current = head;
    struct node* newQueue = NULL;
    struct node* deletedNode = NULL;

    // İlk elemanı silme durumu
    if (strcmp(current->name, name) == 0) {
        deletedNode = head;
        head = head->next;
        free(deletedNode);
    } 
    else 
    {
        newQueue = head;
    }

    while (current->next) {
        if (strcmp(current->next->name, name) == 0) 
        {
            deletedNode = current->next;
            current->next = current->next->next;
            free(deletedNode);
        } 
        else 
        {
            current = current->next;
            if (!newQueue) 
            {
                newQueue = current;
            }
        }
    }

    if (!newQueue) {
        printf("The song '%s' is not found in the playlist.\n", name);
    }

    return newQueue;
}
