#include "spotify.h"

int main() {
    //Creazione di una PLAYLIST. Utilizzare e riempire questa playlist
    PlayList p;
    strcpy(p.name, "Playlist N° 1");
    p.top = NULL;

    PlayList p1;
    strcpy(p1.name, "Playlist N° 2");
    p1.top = NULL;

    PlayList p2;
    strcpy(p2.name, "Playlist N° 3");
    p2.top = NULL;

    Song *s = NULL;
    char titolo[DIM_TITLE] = {};
    //altre chiamate e istruzioni per testare il funzionamento delle funzioni create

    char scelta;
    int sceltaPlaylist;

    printf("\nBenvenuto in Spotify!");
    do {
        printf("\nScegli un'azione:");
        printf("\n%c) Aggiungi canzone"
               "\n%c) Cerca canzone"
               "\n%c) Modifica canzone"
               "\n%c) Elimina canzone"
               "\n%c) Stampa playlist"
               "\n%c) Scorri playlist"
               "\n%c) Unisci la Playlist N° 1 e N° 2"
               "\n%c) Esci"
               "\n?) ", PROMPT_AGGIUNGI_CANZONE, PROMPT_CERCA_CANZONE, PROMPT_MODIFICA_CANZONE, PROMPT_CANCELLA_CANZONE, PROMPT_STAMPA_PLAYLIST, PROMPT_SCORRI_PLAYLIST, PROMPT_UNISCI_PLAYLIST, PROMPT_ESCI);
        scanf(" %c", &scelta);
        getchar();

        switch (scelta) {
            case PROMPT_AGGIUNGI_CANZONE:
                do {
                    printf("\nScegli tra la 1° e la 2° playlist.\n"
                           "?) ");
                    scanf(" %d", &sceltaPlaylist);
                    getchar();
                    if(sceltaPlaylist <= 0 || sceltaPlaylist > 2)
                        printf("\nInserisci un valore valido!");
                } while (sceltaPlaylist <= 0 || sceltaPlaylist > 2);

                if (sceltaPlaylist == 1)
                    insertSong(&p, acquireSong());
                else
                    insertSong(&p1, acquireSong());
                break;
            case PROMPT_CERCA_CANZONE:
                do {
                    printf("\nScegli tra la 1° e la 2° playlist.\n"
                           "?) ");
                    scanf(" %d", &sceltaPlaylist);
                    getchar();
                    if(sceltaPlaylist <= 0 || sceltaPlaylist > 2)
                        printf("\nInserisci un valore valido!");
                } while (sceltaPlaylist <= 0 || sceltaPlaylist > 2);

                printf("\nInserisci il titolo da cercare: ");
                scanf(" %49s", titolo);

                if (sceltaPlaylist == 1)
                    s = findSong(&p, titolo);
                else
                    s = findSong(&p1, titolo);

                if (s != NULL) {
                    printf("\nCanzone presente!");
                } else
                    printf("\nCanzone non presente.");
                break;
            case PROMPT_MODIFICA_CANZONE:
                do {
                    printf("\nScegli tra la 1° e la 2° playlist.\n"
                           "?) ");
                    scanf(" %d", &sceltaPlaylist);
                    getchar();
                    if(sceltaPlaylist <= 0 || sceltaPlaylist > 2)
                        printf("\nInserisci un valore valido!");
                } while (sceltaPlaylist <= 0 || sceltaPlaylist > 2);

                if (scelta == 1)
                    modifySong(&p, s);
                else
                    modifySong(&p1, s);
                break;
            case PROMPT_CANCELLA_CANZONE:
                do {
                    printf("\nScegli tra la 1° e la 2° playlist.\n"
                           "?) ");
                    scanf(" %d", &sceltaPlaylist);
                    getchar();
                    if(sceltaPlaylist <= 0 || sceltaPlaylist > 2)
                        printf("\nInserisci un valore valido!");
                } while (sceltaPlaylist <= 0 || sceltaPlaylist > 2);

                printf("\nInserisci il titolo da eliminare: ");
                scanf(" %49s", titolo);
                getchar();
                if (sceltaPlaylist == 1)
                    deleteSong(&p, findSong(&p, titolo));
                else
                    deleteSong(&p1, findSong(&p1, titolo));
                break;
            case PROMPT_STAMPA_PLAYLIST:
                do {
                    printf("\nScegli tra la 1°, e la 2° o la 3° playlist.\n"
                           "?) ");
                    scanf(" %d", &sceltaPlaylist);
                    getchar();
                    if(sceltaPlaylist <= 0 || sceltaPlaylist > 3)
                        printf("\nInserisci un valore valido!");
                } while (sceltaPlaylist <= 0 || sceltaPlaylist > 3);

                if (sceltaPlaylist == 1)
                    printPlayList(&p);
                else if (sceltaPlaylist == 2)
                    printPlayList(&p1);
                else
                    printPlayList(&p2);
                break;
            case PROMPT_SCORRI_PLAYLIST:
                do {
                    printf("\nScegli tra la 1°, la 2° o la 3° playlist.\n"
                           "?) ");
                    scanf(" %d", &sceltaPlaylist);
                    getchar();
                    if(sceltaPlaylist <= 0 || sceltaPlaylist > 3)
                        printf("\nInserisci un valore valido!");
                } while (sceltaPlaylist <= 0 || sceltaPlaylist > 3);

                if (sceltaPlaylist == 1)
                    scorriPlaylist(&p);
                else if (sceltaPlaylist == 2)
                    scorriPlaylist(&p1);
                else
                    scorriPlaylist(&p2);
                break;
            case PROMPT_UNISCI_PLAYLIST:
                mergePlayList(&p, &p1, &p2);
                printf("\nPlaylist unite!");
            default:
                printf("\nInserisci un valore valido!");
        }
    } while (scelta != PROMPT_ESCI);

    printf("\nA presto!");

    return 0;
}