#include "a_beer_r.h"


/* -------------------------------
 Funzioni gia' implementate (NON MODIFICARE):
 ------------------------------- */
Birra acquisisci_birra()
{
    Birra b;

    printf("\nnome: ");
    scanf("%[^\n]s", b.nome), getchar();

    printf("\ngradi: ");
    scanf("%f", &b.gradi), getchar();

    printf("\nbottiglie: ");
    scanf("%d", &b.bottiglie), getchar();

    return b;
}

void stampa_birra(Birra b)
{
    printf("--------------------- \n");
    printf("nome:  %s \n", b.nome);
    printf("gradi: %.1f \n", b.gradi);
    printf("bottiglie: %d \n", b.bottiglie);
    printf("--------------------- \n");
}

Nodo* crea_nodo(Birra b)
{
    Nodo* new_node = (Nodo*)malloc(sizeof(Nodo));
    if(new_node != NULL)
    {
        new_node->key = b;
        new_node->parent = NULL;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

Nodo* carica_test()
{
    Nodo *root = NULL;
    int i;
    Birra elenco[NUM_TEST] = {{"Ichnusa", 4.7, 3}, {"Founders", 5.7, 15}, {"Peroni", 4.7, 2},
                              {"San Miguel", 3.2, 4}, {"Miller", 4.7, 7}, {"Guinnes", 4.2, 1},
                              {"Best Brau", 4.7, 12}, {"Barley", 5.0, 7}, {"Chouffe", 8.0, 12},
                              {"Franziskaner", 5, 10}, {"Heineken", 5.0, 7}, {"Kwak", 8.0, 14},
                              {"Paulaner", 5.5, 10}, {"Rubiu", 4.5, 10}, {"Tuborg", 5.0, 3}};


    for(i = 0; i < NUM_TEST; i++)
    {
        Nodo *new_birra = crea_nodo(elenco[i]);
        root = insert_nodo(root, new_birra);
    }

    return root;
}


/* -------------------------------
 Funzioni da implementare:
 ------------------------------- */
Nodo* insert_nodo(Nodo* root, Nodo* new_node)
{
    Nodo *x, *y;
    y = NULL;
    x = root;
    while (x != NULL)
    {
        // L’algoritmo cerca un cammino discendente dalla radice
        y = x;   // fino ad una foglia; x segue il cammino, y punta al padre di x
        if (strcmp(new_node->key.nome, x->key.nome) < 0)
            x = x->left;
        else if(strcmp(new_node->key.nome, x->key.nome) == 0)
        {
            printf("\nEsiste già un elemento con questo nome!");
            return root;
        }

        else
            x = x->right;
    }

// usciti da questo ciclo y è il puntatore al padre del nuovo nodo
    new_node->parent =y;
    if (y == NULL)
        root = new_node;
    else if (strcmp(new_node->key.nome , y->key.nome)<0)
        y->left = new_node;
    else
        y->right=new_node;

    return root;
}

void inorder(Nodo* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        stampa_birra(root->key); // stampa contenuto di r
        inorder(root->right);
    }

}



void preorder(Nodo* root)
{
    if(root != NULL)
    {
        stampa_birra(root->key); // stampa contenuto di r
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Nodo* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        stampa_birra(root->key); // stampa contenuto di r
    }


}

int profondita(Nodo* root)
{
    if(root == NULL)
        return 0;

    int sx,dx;

    //else
    sx = profondita(root->left);
    dx = profondita(root->right);
    return 1 + max(sx, dx);
}

int max(int v1, int v2)
{
    return v1 >= v2 ? v1 : v2;
}

Nodo* ricerca(Nodo* root, char* nome_birra)
{
    if(root == NULL)
        return NULL;


    if(strcmp(nome_birra, root->key.nome)==0 )
        return root;

    if(strcmp(nome_birra, root->key.nome)<0)
        return ricerca(root->left, nome_birra);

    //else
    return ricerca(root->right, nome_birra);
}

Nodo* abr_min(Nodo* root)
{
    Nodo * nodo;
    nodo = root;
    while(nodo->left != NULL)
    {
        nodo = nodo->left;
    }

    return nodo;

}

Nodo* abr_max(Nodo* root)
{
    Nodo * nodo;
    nodo = root;
    while(nodo->right != NULL)
    {
        nodo = nodo->right;
    }

    return nodo;
}


Nodo* abr_pred(Nodo* x)
{

    Nodo * y;

    if(x->left != NULL)
        return abr_max(x->left);
    y = x->parent;
    while(y != NULL && x == y->left)
    {
        x = y;
        y = y->parent;
    }

    return y;
}

Nodo* abr_succ(Nodo* x)
{

    Nodo * y;

    if(x->right != NULL)
        return abr_min(x->right);
    y = x->parent;
    while(y != NULL && x == y->right)
    {
        x = y;
        y = y->parent;
    }

    return y;
}
/**
 * 3 casi:
 * cancellazione di un nodo di grado 0 (foglia): si imposta a NULL il campo
                                                figlio (sx o dx, a seconda del caso) del padre del nodo cancellato;

   cancellazione di un nodo di grado 1: si collega il sottoalbero del nodo da
                                        cancellare con il campo figlio del padre;

   cancellazione di un nodo di grado 2: si sostituisce il nodo da cancellare con
                                        l’elemento più piccolo del suo sottoalbero destro (oppure con il più grande
                                        del suo sottoalbero sinistro), infine si cancella anche tale nodo.
 * @param root
 * @param nodo
 * @return
 */
Nodo* delete_node(Nodo* root, Nodo* nodo)
{
    Nodo * y, *x;

    //controllo che abbia 1 o 0 figli
    if(nodo->left == NULL || nodo->right == NULL)
        y = nodo;
    else
        y = abr_succ(nodo); //salvo in y il successore

    //se ora y di appoggio ha come figlio sinistro qualcosa, lo salvo in x
    if(y->left != NULL)
        x = y->left;
    else
        x = y->right;//altrimenti metto il x la destra di y, che potrebbe anche essere null


    //controllo che non sia null e rendo x figlio del padre di y
    if(x != NULL)
        x->parent = y->parent;

    //se y era il primo elemento, dunque senza padre, e dunque la radice, rendo x la nuova radice
    if(y->parent == NULL)
        root=x;

        //nel caso in cui y sia il figlio sinistro, sostituisco x al suo posto
    else if(y->parent->left == y)
        y->parent->left = x;

    else //altrimenti è necessariamente il figlio destro e dunque metto x a destra
        y->parent->right = x;


    if(y != nodo)
    {
        nodo->key = y->key;
    }

    free(y);
    return root;
}

void free_postorder(Nodo* root)
{
    //uso la modalita postorder per fare le free di ogni nodo,
    //in modo cosi da partire dal basso per poi risalire senza fare free prima di aver pulito il suo sottoalbero
    if(root != NULL)
    {
        free_postorder(root->left);
        free_postorder(root->right);
        free(root);
    }
}