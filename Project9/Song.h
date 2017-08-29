/*
Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
Purpose: This program's purpose is to use pointers for songs and add them to a playlist,
	and then "play" the songs pointed to in a chosen playlist.
Purpose of File:
	To declare the class Song with its public member functions and private data members
Input:
	User menu choice
	Song name and first line of song
	Playlist name
	Index of chosen playlist and chosen song
	Chosen playlist to play
Output:
	Welcomes the user
	Prints menu choices and prompts for a choice
	Asks user for song name and first line until STOP is entered
	Prints song index, name, first line and number of times played
	Asks user for a playlist name
	Prints playlists and song names and prompts for a playlist and song to add to playlist
	Asks for a playlist to play and prints out first lines of songs in playlist
	Prints Goodbye at end of program
*/

#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
	public:
		Song();
		Song(string songName, string firstLine);
		string GetSongName() const;
		string GetFirstLine() const;
		int GetTimesPlayed() const;
		void PrintSongInfo() const;
		void IncrementPlayCount();
		void PlaySong();
	private:
		string songName;
		string firstLine;
		int numTimesPlayed;
};

#endif