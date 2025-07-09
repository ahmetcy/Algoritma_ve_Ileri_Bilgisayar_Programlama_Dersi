#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalog.h"

int main()
{
    struct node* n;
    struct node* head = NULL;
    struct node* ns;
    struct node* top = NULL;
    char songname[50];
    char albumname[50];
    char artistname[50];
    int songdate;
    float songduration;
    int choice1 = 10;
    int choice2 = 10;

    

    
    
    printf("Welcome to the Playlist!!!\n\n");
    while (choice1)
    {
        printf("Press\n");
        printf("1) to use Stack System\n");
        printf("2) to use Queue System\n");
        printf("0) to exit\n");
        scanf("%d", &choice1);
        switch (choice1)
        {
        case 1:
            ns = new_Node("Les", "Camp", "Childish Gambino", 2011, 5.17); //Stack olusturma
            top = ns; 
            top = push(top, "Ivy", "Blonde", "Frank Ocean", 2016, 4.09);
            top = push(top, "Hallelujah", "Grace", "Jeff Buckley", 1994, 6.53);
            choice2 = 10;
            while (choice2)
            {
                printf("1) to add a new song\n");
                printf("2) to remove a song\n");
                printf("3) to see the playlist\n");
                printf("4) to check if a song is in the playlist\n");
                printf("5) to delete the playlist\n");
                printf("0) to go back\n");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                    printf("Name of the Song: ");
                    getchar(); 
                    fgets(songname, sizeof(songname), stdin);
                    printf("Name of the Album: ");
                    fgets(albumname, sizeof(albumname), stdin);
                    printf("Name of the Artist: ");
                    fgets(artistname, sizeof(artistname), stdin);
                    printf("Which year was it released: ");
                    scanf("%d", &songdate);
                    printf("Duration of the Song: ");
                    scanf("%f", &songduration);
                    top = push(top, songname, albumname, artistname, songdate, songduration);
                    printf("'%s' is added to the Stack Playlist successfully!\n", songname);
                    break;
                case 2:
                    printf("Which song would you like to erase: ");
                    getchar(); // Önceki scanf'ten gelen newline karakterini temizle
                    fgets(songname, sizeof(songname), stdin);
                    top = s_seek_and_destroy(top, songname);
                    printf("'%s' is removed from the Stack Playlist!\n", songname);
                    break;
                case 3:
                    print_list(top);
                    printf("\n");
                    break;
                case 4:
                    printf("Which song are you looking for: ");
                    getchar();
                    fgets(songname, sizeof(songname), stdin);
                    search_node(top, songname);
                    printf("\n");
                    break;
                case 5:
                    top = pop_stack(top);
                    printf("The Stack Playlist has been erased!\n");
                    break;
                case 0:
                    break;
                }
            }
            break;
        case 2:
            n = new_Node("Burger Queen", "Without You I'm Nothing", "Placebo", 1998, 4.18); //Queue olusturma
            head = n; 
            head = enqueue(head, "Glory Box", "Dummy", "Portishead", 1994, 5.08);
            head = enqueue(head, "So It Goes", "Swimming", "Mac Miller", 2018, 5.12);
            
            choice2 = 10;
            while (choice2)
            {
                printf("1) to add a new song\n");
                printf("2) to remove a song\n");
                printf("3) to see the playlist\n");
                printf("4) to check if a song is in the playlist\n");
                printf("5) to delete the playlist\n");
                printf("0) to go back\n");
                scanf("%d", &choice2);
                switch (choice2)
                {
                case 1:
                    printf("Name of the Song: ");
                    getchar(); 
                    fgets(songname, sizeof(songname), stdin);
                    printf("Name of the Album: ");
                    fgets(albumname, sizeof(albumname), stdin);
                    printf("Name of the Artist: ");
                    fgets(artistname, sizeof(artistname), stdin);
                    printf("Which year was it released: ");
                    scanf("%d", &songdate);
                    printf("Duration of the Song: ");
                    scanf("%f", &songduration);
                    head = enqueue(head, songname, albumname, artistname, songdate, songduration);
                    printf("'%s' is added to the Queue Playlist successfully!\n", songname);
                    break;
                case 2:
                    printf("Which song would you like to erase: ");
                    getchar(); 
                    fgets(songname, sizeof(songname), stdin);
                    head = q_seek_and_destroy(head, songname);
                    printf("'%s' is removed from the Queue Playlist!\n", songname);
                    break;
                case 3:
                    print_list(head);
                    printf("\n");
                    break;
                case 4:
                    printf("Which song are you looking for: ");
                    getchar();
                    fgets(songname, sizeof(songname), stdin);
                    search_node(head, songname);
                    printf("\n");
                    break;
                case 5:
                    erase_queue(head);
                    printf("The Queue Playlist has been erased!\n");
                    break;
                case 0:
                    break;
                }
            }
            break;
        case 0:
            return (0);
        }
    }
    return 0;
}
