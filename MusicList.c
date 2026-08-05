#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Song {
    char title[100];
    struct Song *next;
    struct Song *prev;
} Song;

typedef struct Playlist {
    char title[100];
    Song *head;
    Song *tail;
} Playlist;

//Constructors Functions
Song *createSong(char *title) {
    Song *newSong = (Song *)malloc(sizeof(Song));
    // Check if memory allocation was successful
    if (newSong == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newSong->title, title);
    newSong->next = NULL;
    newSong->prev = NULL;
    return newSong;
}

void addSong(Playlist *playlist, char *title) {
    Song *newSong = createSong(title);
    newSong->prev = playlist->tail;

    if (playlist->tail != NULL) {
        playlist->tail->next = newSong;
    } else {
        playlist->head = newSong;
    }
    playlist->tail = newSong;
}

bool removeSong(Playlist *playlist, char *title) {
    Song *current = playlist->head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                playlist->head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                playlist->tail = current->prev;
            }
            free(current);
            return true;
        }
        current = current->next;
    }
    return false;
}

void printPlaylist(Playlist *playlist) {
    Song *current = playlist->head;
    while (current != NULL) {
        printf("%s\n", current->title);
        current = current->next;
    }
}

void freePlaylist(Playlist *playlist) {
    Song *current = playlist->head;
    while (current != NULL) {
        Song *next = current->next;
        free(current);
        current = next;
    }
    free(playlist);
}

int main() {
    Playlist *playlist = (Playlist *)malloc(sizeof(Playlist));
    if (playlist == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    playlist->head = NULL;
    playlist->tail = NULL;

    addSong(playlist, "Hachimi");
    addSong(playlist, "heart");
    addSong(playlist, "Stellar");

    removeSong(playlist, "heart");

    printPlaylist(playlist);

    freePlaylist(playlist);
    return 0;
}

