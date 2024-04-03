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
    scanf('Song title: %s',title);
    char interpret[20];
    scanf('Song interpret: %s',interpret);
    char language[20];
    scanf('Song language: %s',language);
    char type[20];
    scanf('Song type: %s',type);
    char chorus[100];
    scanf('Song chorus: %s',chorus);
    int identifier;
    scanf('Song identifier: %d', identifier);
    int year;
    scanf('Song year: %d', year);
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

}

void removeSong(int identifier, struct songList* songList) {

}

void listSongsByYear(struct songList* songList) {

}

void listSongsByYearAndLanguage(struct songList* songList, int year, char* language) {

}

void listSongsByType(struct songList* songList, char* type) {

}

void listSong(struct songList* songList, int identifier) {

    struct song song = searchSong(identifier, songList);

    printf("Song identifier: %d", song.identifier);
    printf("Song title: %s", song.title);
    printf("Song interpret: %s", song.interpret);
    printf("Song language: %s", song.language);
    printf("Song type: %s", song.type);
    printf("Song chorus: %s", song.chorus);
    printf("Song year: %d", song.year);
}

void listAllSongs(struct songList* songList) {

    struct songList* songListCopy = songList;
    while (songListCopy != NULL) {
        listSong(songListCopy, songListCopy->song.identifier);
        songListCopy = songListCopy->next;
    }
}

void downloadSong(struct songList* songList, int identifier) {
    // WIll only be implemented in project 2.
}

int main() {
    struct songList* songList = NULL;
    registerSong(songList);
    listSong(songList, 1);
    registerSong(songList);

    return 0;
}