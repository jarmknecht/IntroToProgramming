/*
Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
Purpose: This program's purpose is to use pointers for songs and add them to a playlist,
	and then "play" the songs pointed to in a chosen playlist.
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
Test Cases:
	Case 1:
		Input: The following test case tests to see if the menu is printed again with incorrect choice,
			that typing STOP stops adding songs and that no songs were added and the program quits.
				7, 1, STOP, 2, 0
		Output: The menu was reprinted, and no songs were printed since none were added. Also,
			0 quit the program and printed out GOODBYE!
	Case 2:
		Input: The following test case tests to see if having only 1 playlist of 5 songs, but a total of 10 songs
			only updates songs played in the playlist.
			1
				Victorious, Tonight we are victorious
				House Of Memories, Woah, woah
				Miss Jackson, Climbing out the backdoor, didn't leave a mark
				Nicotine, Cross my heart and hope to die
				Golden Days, I found a pile of Polaroids
				Centuries, Some legends are told
				Immortals, They say we are what we are
				Uma Thurman, I can move mountains
				This Ain't A Scene, It's An Arms Race, I am an arms dealer
				Dance, Dance, She says she's no good
				STOP
			2, 3, Panic! At The Disco, 4, 0, 0, 4, 0, 1, 4, 0, 2, 4, 0, 3, 4, 0, 4, 5, 0, 2, 0
		Expected Outputs:
			Keeps asking for song name and song's first line till STOP is entered.
				Prints all of the songs' names, first lines, with play count zero
			Asks for a playlist name
			Prints playlist names, and asks for chosen playlist
			Prints out all songs, and asks for chosen song
			Plays songs in selected playlist by printing first line of songs
			Prints all songs with songs that were played updated by 1
		All outputs were as expected.
	Case 3:
		Input: The following test case tests to see if having 2 playlists of 5 songs each, but a total of 10 songs
			only updates songs played in the playlist.
			1
				Victorious, Tonight we are victorious
				House Of Memories, Woah, woah
				Miss Jackson, Climbing out the backdoor, didn't leave a mark
				Nicotine, Cross my heart and hope to die
				Golden Days, I found a pile of Polaroids
				Centuries, Some legends are told
				Immortals, They say we are what we are
				Uma Thurman, I can move mountains
				This Ain't A Scene, It's An Arms Race, I am an arms dealer
				Dance, Dance, She says she's no good
				STOP
			2, 3, Panic! At The Disco, 4, 0, 0, 4, 0, 1, 4, 0, 2, 4, 0, 3, 4, 0, 4, 5, 0, 2,
				3, Mixed Tape, 4, 1, 1, 4, 1, 3, 4, 1, 5, 4, 1, 7, 4, 1, 9, 5, 1, 2, 0
		Expected Outputs:
			Keeps asking for song name and song's first line till STOP is entered.
				Prints all of the songs' names, first lines, with play count zero
			Asks for a playlist name
			Prints playlist names, and asks for chosen playlist
			Prints out all songs, and asks for chosen song
			Plays songs in selected playlist by printing first line of songs
			Prints all songs with songs that were played updated by 1
			Asks for a playlist name
			Prints playlist names, and asks for chosen playlist
			Prints out all songs, and asks for chosen song
			Plays songs in selected playlist by printing first line of songs
			Prints all songs with songs that were played updated by 1 (Songs in both playlists will be 2 times played)
		All outputs were as expected.
*/

#include <iostream>
#include <vector>
using namespace std;

#include "Song.h"
#include "Playlist.h"

const int QUIT_PROGRAM = 0;
const int ADD_SONG = 1;
const int LIST_SONGS = 2;
const int ADD_PLAYLIST = 3;
const int ADD_SONG_TO_PLAYLIST = 4;
const int PLAY_PLAYLIST = 5;

void GetMenuChoice(int& menuChoice) {
	cout << "Please select one of the following options:" << endl << endl;
	cout << QUIT_PROGRAM << " - Quit the program" << endl;
	cout << ADD_SONG << " - Add songs" << endl;
	cout << LIST_SONGS << " - List all songs" << endl;
	cout << ADD_PLAYLIST << " - Add a playlist" << endl;
	cout << ADD_SONG_TO_PLAYLIST << " - Add a song to a playlist" << endl;
	cout << PLAY_PLAYLIST << " - Play a playlist" << endl << endl;
	cout << "Enter your selection now: ";
	cin >> menuChoice;
	cout << endl;
}

void AddSong(vector<Song*>& songs) {
	cin.ignore();
	string songName;
	string firstLine;

	cout << "Read in Song names and first lines:" << endl;
	do {
		cout << "Song Name (type \"STOP\" when done): ";
		getline(cin, songName);
		cout << endl << endl;
		if (songName != "STOP") {
			cout << "That song's first line: ";
			getline(cin, firstLine);
			cout << endl << endl;
			songs.push_back(new Song(songName, firstLine));
		}
	} while (songName != "STOP");
	cout << endl;
}

void AddPlaylist(vector<Playlist*>& playlists) {
	cin.ignore();
	string playlistName;

	cout << "Playlist name: ";
	getline(cin, playlistName);
	cout << endl << endl;

	playlists.push_back(new Playlist(playlistName));
}

void PrintAllSongsInfo(const vector<Song*>& songs) {
	for (int i = 0; i < songs.size(); ++i) {
		cout << i << ": ";
		songs.at(i)->PrintSongInfo();
	}
	cout << endl;
}

void PrintSongNames(const vector<Song*>& songs) {
	for (int i = 0; i < songs.size(); ++i) {
		cout << i << ": " << songs.at(i)->GetSongName() << endl;
	}
	cout << endl;
}

void PrintPlaylists(const vector<Playlist*>& playlists, string promptMessage) {
	cout << promptMessage << endl;

	for (int i = 0; i < playlists.size(); ++i) {
		cout << i << ": " << playlists.at(i)->GetPlaylistName() << endl;
	}
	cout << "Pick a playlist index number: ";
}

void DeleteSongPointers(vector<Song*>& songs) {
	const int STARTING_INDEX = 0;
	
	while (songs.size() != 0) {
		delete songs.at(STARTING_INDEX);
		songs.erase(songs.begin());
	}
}

void DeletePlaylistPointers(vector<Playlist*>& playlists) {
	const int STARTING_INDEX = 0;
	
	while (playlists.size() != 0) {
		delete playlists.at(STARTING_INDEX);
		playlists.erase(playlists.begin());
	}
}

Playlist* ChoosePlaylist(const vector<Playlist*>& playlists, string promptMessage) {
	int chosenPlaylist = 0;
	
	PrintPlaylists(playlists, promptMessage);

	cin >> chosenPlaylist;
	cout << endl;

	return playlists.at(chosenPlaylist);
}

Song* ChooseSong(vector<Song*>& songs) {
	int chosenSong = 0;

	cout << "Find a song to add:" << endl;
	PrintSongNames(songs);

	cout << "Pick a song index number: ";
	cin >> chosenSong;
	return songs.at(chosenSong);
}

void AddSongToPlaylist(vector<Playlist*>& playlists, vector<Song*>& songs) {
	Playlist* chosenPlaylist = ChoosePlaylist(playlists, "Add to a playlist:");
	Song* chosenSong = ChooseSong(songs);
	chosenPlaylist->AddSongToPlaylist(chosenSong);
	cout << endl << endl;
}

void PlayPlaylist(vector<Playlist*>& playlists) {
	Playlist* chosenPlaylist = ChoosePlaylist(playlists, "Pick a playlist to play:");
	cout << "Playing first lines:" << endl;

	vector<Song*> songsInPlaylist = chosenPlaylist->GetSongs();
	for (int i = 0; i < songsInPlaylist.size(); ++i) {
		songsInPlaylist.at(i)->PlaySong();
	}
}

void CleanupAllPointers(vector<Playlist*>& playlists, vector<Song*>& songs) {
	DeleteSongPointers(songs);
	DeletePlaylistPointers(playlists);
}

int main() {
	int menuChoice = 0;
	vector<Song*> songs;
	vector<Playlist*> playlists;

	cout << "Welcome to the Firstline Player!" << endl << endl;

	do {
		GetMenuChoice(menuChoice);
		if (menuChoice == ADD_SONG) {
			AddSong(songs);
		}
		else if (menuChoice == LIST_SONGS) {
			PrintAllSongsInfo(songs);
		}
		else if (menuChoice == ADD_PLAYLIST) {
			AddPlaylist(playlists);
		}
		else if (menuChoice == ADD_SONG_TO_PLAYLIST) {
			AddSongToPlaylist(playlists, songs);
		}
		else if (menuChoice == PLAY_PLAYLIST) {
			PlayPlaylist(playlists);
		}
	} while (menuChoice != QUIT_PROGRAM);

	CleanupAllPointers(playlists, songs);
	cout << "GOODBYE!";

	return 0;
}