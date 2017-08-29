/*
Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
Purpose: This program's purpose is to use pointers for songs and add them to a playlist,
and then "play" the songs pointed to in a chosen playlist. Also, to improve the Firstline Player made previously.
Purpose of File:
To declare the class Song with its public member functions and private data members
Input:
	User menu choice
	Song name, first line of song, year it was released
	Playlist name
	Index of chosen playlist and chosen song
	Chosen playlist to play
	Chosen playlist to delete
	How many songs to play randomly
	Chosen song to delete from library or from just a playlist
Output:
	Welcomes the user
	Prompts for a choice, if 10 prints all options
	Asks user for song name, first line, and year released until STOP is entered
	Prints song index, name, first line, year released, and number of times played
	Asks user for a playlist name
	Prints playlists and song names and prompts for a playlist and song to add to playlist
	Asks for a playlist to play and prints out first lines of songs in playlist
	Asks for how many songs to play randomly and plays them
	Asks which playlist should be deleted
	Asks which song should be deleted from a certain playlist or the entire library
	Prints Goodbye at end of program
*/

#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
public:
	Song();
	Song(string songName, string firstLine, int yearOfSong);
	string GetSongName() const;
	string GetFirstLine() const;
	int GetTimesPlayed() const;
	int GetYear() const;
	void PrintSongInfo() const;
	void IncrementPlayCount();
	void PlaySong();
private:
	string songName;
	string firstLine;
	int yearOfSong;
	int numTimesPlayed;
};

#endif
