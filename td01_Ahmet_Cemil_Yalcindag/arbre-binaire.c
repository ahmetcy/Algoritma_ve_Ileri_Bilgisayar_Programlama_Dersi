#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// La structure de noeud
struct node {
	int data;
	struct node* left;
	struct node* right;	
};

// Pour creer un nouveau noeud
struct node* newNode(int data) {
    struct node* new = malloc(sizeof(struct node));
	assert(new);
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

// Calcul de la hauteur de l'arbre (recursive)
int findHeight(struct node *root) {
	if (root == NULL)
	{
		return -1;
	}
	int h_left = findHeight(root->left);
	int h_right = findHeight(root->right);

	if (h_left > h_right) 
	{
		return (1+h_left);
	}
	else
	{
		return (1+h_right);
	} 
}

/***** Parcours des Arbres *****/

// Parcours infixe recursive
void printTreeInOrder(struct node* root) {
	if(root != NULL ) 
	{
		printTreeInOrder(root->left);
		printf("%d ",root->data);
		printTreeInOrder(root->right);
	}
}

// Parcours prefixe recursive
void printTreePreOrder(struct node* root) {
	if(root != NULL)
	{
		printf("%d ",root->data);
		printTreePreOrder(root->left);
		printTreePreOrder(root->right);
	}
	
}

// Parcours postfixe recursive
void printTreePostOrder(struct node* root) {
	if (root != NULL)
	{
		printTreePostOrder(root->left);
		printTreePostOrder(root->right);
		printf("%d ",root->data);
	}
	
}

// Affichage des noeuds sur le meme niveau (recursive)
void printLevel(struct node *root, int level) {

}

// Parcours par niveau (recursive)
void printTreeLevelOrder(struct node* root) {

}


int main(void) {
	
	// creez l'arbre que l'on va utiliser 
	// (le meme arbre que sur le slide no 24)
	struct node* r = newNode(23);
	r->left = newNode(18);
	r->right = newNode(44);

	r->left->left = newNode(12);
	r->left->right = newNode(20);
	r->right->left = newNode(35);
	r->right->right = newNode(52);

	r->right->right->left = newNode(47);
	r->right->right->right = newNode(53);
	
	// Affichez la hauteur de l'arbre
	printf("Hauteur    : %d", findHeight(r));
	
	// Parcours de l'arbre en utilisant le parcours
	// prefixe, infixe, postfixe et par niveau
	printf("\nPrefixe    : ");
	printTreePreOrder(r);
	
	printf("\nInfixe     : ");
	printTreeInOrder(r);
	
	printf("\nPostfixe   : ");
	printTreePostOrder(r);
	
	printf("\nPar Niveau : ");
	
	
	return 0;
}