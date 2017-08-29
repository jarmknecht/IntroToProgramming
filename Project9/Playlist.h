/*
Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
Purpose: This program's purpose is to use pointers for songs and add them to a playlist,
	and then "play" the songs pointed to in a chosen playlist.
Purpose of File:
	To declare the class Playlist with its public member functions and private data members
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

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
using namespace std;

#include "Song.h"

class Playlist {
	public:
		Playlist();
		Playlist(string playlistName);
		void AddSongToPlaylist(Song* songPtr);
		string GetPlaylistName() const;
		vector<Song*> GetSongs() const;
	private:
		string playlistName;
		vector<Song*> songs;
};

#endif