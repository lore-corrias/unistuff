#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_TITLE 50
#define DIM_GENRE 50
#define DIM_NAME 50

#define PROMPT_AGGIUNGI_CANZONE 'A'
#define PROMPT_CERCA_CANZONE 'C'
#define PROMPT_MODIFICA_CANZONE 'M'
#define PROMPT_CANCELLA_CANZONE 'D'
#define PROMPT_STAMPA_PLAYLIST 'P'
#define PROMPT_SCORRI_PLAYLIST 'S'
#define PROMPT_UNISCI_PLAYLIST 'U'
#define PROMPT_ESCI 'E'

#define PROMPT_SCORRIMENTO_AVANTI 'A'
#define PROMPT_SCORRIMENTO_INDIETRO 'I'
#define PROMPT_SCORRIMENTO_ANNULLA 'C'

//struttura che rappresenta una CANZONE
struct song {
    char title[DIM_TITLE];
    char genre[DIM_GENRE];
    float length;
    struct song *prev;
    struct song *next;
};

typedef struct song Song;


//struttura che rappresenta una PLAYLIST
struct playlist {
    char name[DIM_NAME];
    Song *top;
};

typedef struct playlist PlayList;

//funzioni (gia' definite) per l'acquisizione e per la stampa di una canzone
Song *acquireSong(); //acquisisce i dati di UNA canzone chiedendoli all'utente
void printSong(Song *t); //stampa i dati relativi ad UNA canzone (passata tramite puntatore)

//prototipi funzioni STUDENTE

void insertSong(PlayList *pl, Song *s);

Song *findSong(PlayList *pl, char title[]);

void deleteSong(PlayList *pl, Song *s);

void removeSong_no_free(PlayList *pl, Song *s);

void modifySong(PlayList *pl, Song *s);

void printPlayList(PlayList *pl);

Song *prevSong(Song *s);

Song *nextSong(Song *s);

void scorriPlaylist(PlayList *p);

void mergePlayList(PlayList *plA, PlayList *plB, PlayList *plC);