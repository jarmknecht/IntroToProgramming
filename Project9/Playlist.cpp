/*
Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
Purpose: This program's purpose is to use pointers for songs and add them to a playlist,
	and then "play" the songs pointed to in a chosen playlist.
Purpose of File:
   To define the public member functions found in the Playlist header file
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

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Song.h"
#include "Playlist.h"

Playlist::Playlist() {
	this->playlistName = "none";
}

Playlist::Playlist(string playlistName) {
	this->playlistName = playlistName;
}

void Playlist::AddSongToPlaylist(Song* songPtr) {
	this->songs.push_back(songPtr);
}

string Playlist::GetPlaylistName() const {
	return this->playlistName;
}

vector<Song*> Playlist::GetSongs() const {
	return this->songs;
}