#ifndef CATALOG_H_
#define CATALOG_H_

struct node
{
    char* name;
    char* album;
    char* artist;
    int date;
    float duration;;
    struct node* next;
};

struct node* new_Node(char* name, char* album, char* artist, int date, float duration); //Yeni node olusturur.

struct node* push(struct node* top, char* name, char* album, char* artist, int date, float duration); //Stack'e yeni node ekler.

struct node* pop(struct node* top); //Stack'in son elemanini cikarir.

void print_list(struct node* top); //Stack'i ekrana bastirir.

int search_node(struct node* top, char* name); //Bir node'u arar. (Sonradan ekledigimiz sarkilari bulabilse de ilk basta default olarak verdigimiz 3 sarkiyi bulamiyor)

struct node* pop_stack(struct node* top); //Tum stack'i siler.

struct node* s_seek_and_destroy (struct node* top, char* name); /*Stack'te bir elemanı arayarak siler. 
                                                                Bunu yaparken silinecek elemanin üstündeki 
                                                                elemanlari gecici süreliğine başka bir stack'e tasir.(search_node'daki gibi yine ilk bastkileri silemiyor)*/ 

struct node* enqueue (struct node* head , char* name, char* album, char* artist, int date, float duration); // Queue'ya yeni node ekler.

struct node* dequeue (struct node* head); //Queue'den son node'u cikarir.

int erase_queue(struct node* head); //Tum queue'yu siler.

struct node* q_seek_and_destroy(struct node* head, char* name); /*Queue'da bir elemanı arayarak siler. 
                                                                Bunu yaparken silinecek elemanin üstündeki 
                                                                elemanlari gecici süreliğine başka bir stack'e tasir.(search_node'daki gibi yine ilk bastkileri silemiyor)*/

#endif