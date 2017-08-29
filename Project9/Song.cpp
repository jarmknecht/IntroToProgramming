/*
Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
Purpose: This program's purpose is to use pointers for songs and add them to a playlist,
	and then "play" the songs pointed to in a chosen playlist.
Purpose of File:
   To define the public member functions found in the Song header file
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
using namespace std;

#include "Song.h"

Song::Song() {
	this->songName = "none";
	this->firstLine = "none";
	this->numTimesPlayed = 0;
}

Song::Song(string songName, string firstLine) {
	this->songName = songName;
	this->firstLine = firstLine;
	this->numTimesPlayed = 0;
}

string Song::GetSongName() const {
	return this->songName;
}

string Song::GetFirstLine() const {
	return this->firstLine;
}

int Song::GetTimesPlayed() const {
	return this->numTimesPlayed;
}

void Song::PrintSongInfo() const {
	cout << "Name: \"" << GetSongName() << "\" FirstLine: \"" << GetFirstLine() << "\"" << endl;
	cout << "Played " << GetTimesPlayed() << " times." << endl;
}

void Song::IncrementPlayCount() {
	this->numTimesPlayed++;
}

void Song::PlaySong() {
	cout << this->GetFirstLine() << endl;
	IncrementPlayCount();
}