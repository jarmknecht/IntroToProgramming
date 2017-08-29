/*
Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
Purpose: This program's purpose is to use pointers for songs and add them to a playlist,
and then "play" the songs pointed to in a chosen playlist. Also, to improve the Firstline Player made previously.
Purpose of File:
To declare the class Playlist with its public member functions and private data members
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
	void DeleteSongFromPlaylist(Song* songPtr);
	string GetPlaylistName() const;
	vector<Song*> GetSongs() const;
private:
	string playlistName;
	vector<Song*> songs;
};

#endif
