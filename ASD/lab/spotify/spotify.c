#include "spotify.h"

/* ---------------------------------------------
* funzioni da NON modificare
* --------------------------------------------*/
Song *acquireSong() {
    Song *new_s = (Song *) malloc(sizeof(Song));
    printf("\nInsert title -> ");
    scanf("%[^\n]s", new_s->title);
    getchar();

    printf("Insert genre -> ");
    scanf("%[^\n]s", new_s->genre);
    getchar();

    printf("Insert length -> ");
    scanf("%f", &(new_s->length));
    getchar();

    new_s->prev = NULL;
    new_s->next = NULL;

    return new_s;
}

void printSong(Song *t) {
    printf("\nTITLE    :\t %s \n", t->title);
    printf("GENRE    :\t %s \n", t->genre);
    printf("LENGTH   :\t %.2f \n", t->length);
}

/* ---------------------------------------------
* funzioni STUDENTE
* --------------------------------------------*/
void insertSong(PlayList *pl, Song *s) {
    Song *tmp_prev = NULL, *tmp_next = NULL;

    if (pl->top == NULL) {
        pl->top = s;
        pl->top->next = NULL;
        pl->top->prev = NULL;
    } else {
        //inizializzo i puntatori temporanei a prev e next
        tmp_prev = NULL;
        tmp_next = pl->top;


        while (tmp_next != NULL && strcmp(tmp_next->title, s->title) <= 0) //significa che la s.title è "maggiore"
        {
            tmp_prev = tmp_next;
            tmp_next = tmp_next->next;
        }

        //caso inserimento in coda
        if (tmp_next == NULL)
        {
            tmp_prev->next = s;
            s->next = NULL;
            s->prev = tmp_prev;
        }

            //inserimento in testa
        else if (tmp_next == pl->top)
        {
            pl->top = s;
            s->prev = NULL;
            s->next = tmp_next;
            tmp_next->prev = s;
        }

            //caso di inserimento tra due nodi
        else {
            tmp_prev->next = s;
            s->prev = tmp_prev;
            s->next = tmp_next;
            tmp_next->prev = s;
        }
    }
}

Song *findSong(PlayList *pl, char title[]) {
    Song *s = pl->top;

    while (s != NULL && strcmp(title, s->title) != 0) {
        s = s->next;
    }

    return s;
}

void deleteSong(PlayList *pl, Song *s) {
    if (s != NULL) {
        if (s->prev != NULL) //caso in cui ha un precedente
            s->prev->next = s->next;
        else //caso in cui non ha precedente, dunque è al top
            pl->top = s->next;

        if (s->next != NULL) //se non è l'ultimo in coda faccio il che il successivo abbia come
            // precedente il precedente del nodo eliminato
            s->next->prev = s->prev;
    }

    //libero la alloazione dinamica del nodo eliminato
    free(s);

}

/**
 * funzione clone della rimozione di una canzone ma senza la free finale
 * rende possibile utilizzare la rimozione nel merge delle playlist
 * @param pl
 * @param s
 */
void removeSong_no_free(PlayList *pl, Song *s) {

    if (s != NULL) {
        if (s->prev != NULL)
            s->prev->next = s->next;
        else
            pl->top = s->next;

        if (s->next != NULL)
            s->next->prev = s->prev;
    }

}


void modifySong(PlayList *pl, Song *s) {
    if (findSong(pl, s->title) != NULL) {
        deleteSong(pl, s);
        insertSong(pl, acquireSong());
    }
}

void printPlayList(PlayList *pl) {
    Song *s = pl->top;

    printf("\n\nNome Playlist: %s", pl->name);

    while (s != NULL) {
        printSong(s);
        s = s->next;
    }
}

Song *prevSong(Song *s) {
    return s->prev;
}

Song *nextSong(Song *s) {
    return s->next;
}

void scorriPlaylist(PlayList *p) {
    Song *s = p->top; //canzone di appoggio per scorrere la playlist
    char scelta;

    if (p->top == NULL) {
        printf("\nLa playlist è vuota!");
        return;
    }

    do {
        printf("\nCanzone corrente: ");
        printSong(s);

        do {
            printf("\nScegli un'azione"
                   "\n%c) Scorri la playlist avanti."
                   "\n%c) Scorri la playlist indietro."
                   "\n%c) Annulla."
                   "\n?) ", PROMPT_SCORRIMENTO_AVANTI, PROMPT_SCORRIMENTO_INDIETRO, PROMPT_SCORRIMENTO_ANNULLA);
            scanf(" %c", &scelta);
            if(scelta != PROMPT_SCORRIMENTO_AVANTI && scelta != PROMPT_SCORRIMENTO_INDIETRO && scelta != PROMPT_SCORRIMENTO_ANNULLA)
                printf("\nInserisci un'azione valida!");
        } while (scelta != PROMPT_SCORRIMENTO_AVANTI && scelta != PROMPT_SCORRIMENTO_INDIETRO && scelta != PROMPT_SCORRIMENTO_ANNULLA);

        switch (scelta) {
            case PROMPT_SCORRIMENTO_AVANTI:
                if(s->next != NULL) {
                    s = nextSong(s);
                } else {
                    printf("\nSei già alla fine della playlist.");
                }
                break;
            case PROMPT_SCORRIMENTO_INDIETRO:
                if(s->prev != NULL) {
                    s = prevSong(s);
                } else {
                    printf("\nSei già all'inizio della playlist.");
                }
            case PROMPT_SCORRIMENTO_ANNULLA:
                printf("\nScelta annullata.");
                break;
        }
    } while (scelta != PROMPT_SCORRIMENTO_ANNULLA);
}

void mergePlayList(PlayList *plA, PlayList *plB, PlayList *plC) {

    Song *s = plA->top;

    while (plA->top != NULL) //prima controllavo s
    {
        removeSong_no_free(plA, s);
        insertSong(plC, s);
        s = plA->top;
    }

    s = plB->top;

    while (plB->top != NULL) {
        removeSong_no_free(plB, s);
        insertSong(plC, s);


        s = plB->top;
    }
}