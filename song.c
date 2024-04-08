#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    int identifier;
    char title[50];
    char interpret[20];
    char language[20];
    char type[20];
    char chorus[100];
    int year;
};

typedef struct songList {
    struct song song;
    struct songList* next;
};


struct song createSong() {

    struct song newSong;

    char title[50];
    scanf("Song title: %s",title);
    char interpret[20];
    scanf("Song interpret: %s",interpret);
    char language[20];
    scanf("Song language: %s",language);
    char type[20];
    scanf("Song type: %s",type);
    char chorus[100];
    scanf("Song chorus: %s",chorus);
    int identifier;
    scanf("Song identifier: %d", identifier);
    int year;
    scanf("Song year: %d", year);
    newSong.identifier = identifier;
    newSong.year = year;
    strncpy(newSong.title, title, 50);
    strncpy(newSong.interpret, interpret, 20);
    strncpy(newSong.language, language, 20);
    strncpy(newSong.type, title, 20);
    strncpy(newSong.chorus, title, 100);

    return newSong;
}

struct song searchSong(int identifier, struct songList* songList) {
    
    struct songList* searcher = songList;
    while (searcher != NULL) {
        if (searcher->song.identifier == identifier) {
            return searcher->song;
        }
        searcher = searcher->next;
    }

    printf("Song not found. Defaulting to first song.");
    return songList->song;

}


void registerSong(struct songList* songList) {

    struct song newSong = createSong();
    struct songList* node = (struct songList*)malloc(sizeof(struct songList));
    node->song = newSong;
    node->next = songList;
    songList = node;

    return;

}

void removeSong(int identifier, struct songList* songList) {

    struct songList* searcher = songList;
    struct songList* previous;
    while (searcher != NULL) {
        if (searcher->song.identifier == identifier) {
            previous->next = searcher->next;
            free(searcher);
            return;
        }
        previous = searcher;
        searcher = searcher->next;
    }

    printf("Song not found. No songs were removed.");
    return songList->song;
}

void listSongsByYear(struct songList* songList, int year) {
    
    struct songList* searcher = songList;
    while (searcher != NULL) {
        if (searcher->song.year == year) {
            listSong(searcher->song);
        }
        searcher = searcher->next;
    }

    printf("All registered songs from the year %d have been listed.", year);
    return songList->song;
}

void listSongsByYearAndLanguage(struct songList* songList, int year, char* language) {
    struct songList* searcher = songList;
    while (searcher != NULL) {
        if (searcher->song.year == year && strcmp(searcher->song.language, language) == 0) {
            listSong(searcher->song);
        }
        searcher = searcher->next;
    }

    printf("All registered %s songs from the year %d have been listed.", language, year);
    return songList->song;
}

void listSongsByType(struct songList* songList, char* type) {
    struct songList* searcher = songList;
    while (searcher != NULL) {
        if (strcmp(searcher->song.type, type) == 0) {
            listSong(searcher->song);
        }
        searcher = searcher->next;
    }

    printf("All registered songs of type %s have been listed.", type);
    return songList->song;
}

void listSong(struct song song) {

    printf("Song identifier: %d", song.identifier);
    printf("Song title: %s", song.title);
    printf("Song interpret: %s", song.interpret);
    printf("Song language: %s", song.language);
    printf("Song type: %s", song.type);
    printf("Song chorus: %s", song.chorus);
    printf("Song year: %d", song.year);

    return;
}

void listAllSongs(struct songList* songList) {

    struct songList* songListCopy = songList;
    while (songListCopy != NULL) {
        listSong(songListCopy->song);
        songListCopy = songListCopy->next;
    }
    return;
}

void downloadSong(struct songList* songList, int identifier) {
    // WIll only be implemented in project 2.
}

int main() {
    struct songList* songList = NULL;
    registerSong(songList);
    listSong(searchSong(1, songList));
    registerSong(songList);

    return 0;
}