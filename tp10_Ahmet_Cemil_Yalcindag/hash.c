#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include"hash.h"
#define MULTIPLIER 256 

/* La fonction de hachage dont le pseudocode est
 * donne sur l'enonce de TP */
unsigned long hash_compute(const char *str, int m){
	int sum=0;
	int mul=1;
	for(int i=0; i<=strlen(str); i++)
	{
		if(i%4) mul = 1;
		else mul = mul*MULTIPLIER;
		sum = sum + str[i]*mul;	
	}
	return sum % m;
}

/* La table represente la structure de hach.
 * Si la chaine de caractere existe deja dans la liste
 * alors on retourne son adresse, sinon et si create == 1
 * alors on ajoute cette chaine à la table de hachage */
Key* hash_lookup(Key **table, const char *str, int create){

	// appel à la fonction hash_compute pour str
	unsigned long hash_value = hash_compute(str, MAXBUCKETS);
	Key* current = table[hash_value];
	
	while (current != NULL)
	{

	// controlez si cette valeur de hachage existe deja
		if (strcmp(current->word, str) == 0)
		{

		// si elle existe alors retournez l'adresse de cette case
		return current;
		}
		current = current->next;
	}

	// si elle n'existe pas et si on va l'ajouter:
	if(create){
		// allouez la place necessaire dans la memoire
		Key* newkey = (Key*)malloc(sizeof(Key));

		// si la place correspondante est allouee sans probleme
		if(newkey == NULL)
		{
			printf("Pas d'espace!");
			return NULL;
		}

		// alors pour le nouvel element faites l'initalisation 
		// de word, count et next
		newkey->word = strdup(str);
		newkey->count = 0;
		newkey->next = table[hash_value];
		table[hash_value] = newkey;
		
		// retournez l'adresse de cet element
		return newkey;
   }
  return NULL;
}

/* Une fonction pour effacer la table entiere.
 * Vous devez liberer (free) chaque noeud et chaque 
 * word qui se toruvent dans la liste chainee. */
void hash_free(Key **table){
	for (int i = 0; i < MAXBUCKETS; i++)
	{
		Key* current = table[i];
		while (current != NULL)
		{
			Key* temp = current;
			current = current->next;
			free(temp->word);
			free(temp);
		}
  	}
}

/* Une fonction pour afficher les mots dont 
 * la frequence >= n. Pour l'affichage utiliser
 * le format "%30s-->%5ld\n" 
 * (ld pour unsigned long) */
void hash_dump(Key **table,int n){
	for(int i=0; i < MAXBUCKETS; i++)
	{
		Key* current = table[i];
		while (current != NULL)
		{
			if(current->count >= n)
			{
				printf("Le mot est ecrit %30s  --> %5ld dans ce texte\n", current->word, current->count);
			}
			current = current->next;
		}
	}
  
}
