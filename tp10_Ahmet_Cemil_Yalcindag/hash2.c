#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include"hash.h"
#define MULTIPLIER 256 

/* La fonction de hachage dont le pseudocode est
 * donne sur l'enonce de TP */
unsigned long hash_compute(const char *str, int m){
	// TODO
	int sum=0,mul=1;
	for (int i = 0; i <= sizeof(str)/sizeof(char); i++)
	{
		if (i%4==0) mul=1;
		else 		mul*=MULTIPLIER;
		sum+=(str[i]*mul);
	}
	return sum % m;
}

/* La table represente la structure de hach.
 * Si la chaine de caractere existe deja dans la liste
 * alors on retourne son adresse, sinon et si create == 1
 * alors on ajoute cette chaine à la table de hachage */
Key* hash_lookup(Key **table, const char *str, int create){
	// TODO
	
	// appel à la fonction hash_compute pour str
	unsigned long computed_key = hash_compute(str,MAXBUCKETS);
	Key* current = table[computed_key];
	// controlez si cette valeur de hachage existe deja
	// si elle existe alors retournez l'adresse de cette case
	while (current!=NULL)
	{
	
		if(strcmp(current->word,str)==0){
			return current;
		}
		current= current->next;
	}	
	
	// si elle n'existe pas et si on va l'ajouter:
	if(create){
		// allouez la place necessaire dans la memoire
		Key * new_key = (Key*)malloc(sizeof(Key));
		// si la place correspondante est allouee sans probleme
		if(new_key==NULL){
			printf("Memmory coudln't be allocated...");
			return NULL;
		}
		// alors pour le nouvel element faites l'initalisation 
		// de word, count et next
		new_key->word = strdup(str);
		new_key->count=0;
		new_key->next = table[computed_key];
		table[computed_key]=new_key;
		// retournez l'adresse de cet element
		return table[computed_key];
   }
  return NULL;
}

/* Une fonction pour effacer la table entiere.
 * Vous devez liberer (free) chaque noeud et chaque 
 * word qui se toruvent dans la liste chainee. */
void hash_free(Key **table){
  // TODO
	for (int i = 0; i < MAXBUCKETS; i++)
	{
		Key* current = table[i];
		while (current!=NULL)
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
	// TODO 
	for (int i = 0; i < MAXBUCKETS; i++)
	{
		Key* current  = table[i];
		while (current!=NULL)
		{
			if(current->count >=n){
				printf("%30s-->%5ld\n",current->word,current->count);
			}
			current= current -> next;
		}
		
	}

}