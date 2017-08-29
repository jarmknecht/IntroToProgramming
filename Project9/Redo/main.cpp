/*
Jonathan Armknecht, Section 7, jonathan.armknecht@gmail.com
Purpose: This program's purpose is to use pointers for songs and add them to a playlist,
and then "play" the songs pointed to in a chosen playlist. Also, to improve the Firstline Player made previously.
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

#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
using namespace std;

#include "Song.h"
#include "Playlist.h"

const int QUIT_PROGRAM = 0;
const int ADD_SONG = 1;
const int LIST_SONGS = 2;
const int ADD_PLAYLIST = 3;
const int ADD_SONG_TO_PLAYLIST = 4;
const int PLAY_PLAYLIST = 5;
const int SHUFFLE_SONGS = 6;
const int REMOVE_A_PLAYLIST = 7;
const int REMOVE_SONG_FROM_PLAYLIST = 8;
const int REMOVE_SONG_FROM_LIBRARY = 9;
const int  LIST_OPTIONS = 10;

void GetMenuChoice(int& menuChoice) {
	cout << "Enter your selection now (Enter 10 to list all options): ";
	cin >> menuChoice;
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	cout << endl;
	
	while (menuChoice == LIST_OPTIONS) {
		cout << endl << "Please select one of the following options:" << endl << endl;
		cout << QUIT_PROGRAM << " - Quit the program" << endl;
		cout << ADD_SONG << " - Add songs" << endl;
		cout << LIST_SONGS << " - List all songs" << endl;
		cout << ADD_PLAYLIST << " - Add a playlist" << endl;
		cout << ADD_SONG_TO_PLAYLIST << " - Add a song to a playlist" << endl;
		cout << PLAY_PLAYLIST << " - Play a playlist" << endl;
		cout << SHUFFLE_SONGS << " - Play random songs" << endl;
		cout << REMOVE_A_PLAYLIST << " - Delete a whole playlist" << endl;
		cout << REMOVE_SONG_FROM_PLAYLIST << " - Delete a song from a playlist" << endl;
		cout << REMOVE_SONG_FROM_LIBRARY << " - Delete a song from everywhere" << endl;
		cout << LIST_OPTIONS << " - List all options" << endl << endl;
		cout << "Enter your selection now (Enter 10 to list all options): ";
		cin >> menuChoice;
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << endl;
	}
}

void AddSong(vector<Song*>& songs) {
	string songName;
	string firstLine;
	int yearReleased;

	cout << "Read in Song names and first lines:" << endl;
	do {
		cout << "Song Name (type \"STOP\" when done): ";
		getline(cin, songName);
		cout << endl << endl;
		if (songName != "STOP") {
			cout << "That song's first line: ";
			getline(cin, firstLine);
			cout << endl << endl;
			cout << "The year that song was released: ";
			cin >> yearReleased;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << endl << endl;
			songs.push_back(new Song(songName, firstLine, yearReleased));
		}
	} while (songName != "STOP");
	cout << endl;
}

void AddPlaylist(vector<Playlist*>& playlists) {
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
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	cout << endl;

	return playlists.at(chosenPlaylist);
}

Song* ChooseSong(vector<Song*>& songs, string promptMessage) {
	int chosenSong = 0;

	cout << promptMessage << endl;
	PrintSongNames(songs);

	cout << "Pick a song index number: ";
	cin >> chosenSong;
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	return songs.at(chosenSong);
}

void AddSongToPlaylist(vector<Playlist*>& playlists, vector<Song*>& songs) {
	Playlist* chosenPlaylist = ChoosePlaylist(playlists, "Add to a playlist:");
	Song* chosenSong = ChooseSong(songs, "Find a song to add:");
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

void ShuffleSongs(vector <Song*> songs) {
	const int RAND_SEED = 42;
	int numSongsToShuffle = 0;
	int randomSongIndex = 0;
	
	srand(RAND_SEED);

	cout << "How many songs do you want played: ";
	cin >> numSongsToShuffle;
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	cout << endl;
	cout << "Playing random first lines:" << endl;

	for (int i = 0; i < numSongsToShuffle; ++i) {
		randomSongIndex = rand() % songs.size();
		songs.at(randomSongIndex)->PlaySong();
	}
}

void DeleteSongFromPlaylist(vector <Playlist*>& playlists) {
	Playlist* chosenPlaylist = ChoosePlaylist(playlists, "Delete a song from a playlist:");
	vector<Song*> songs = chosenPlaylist->GetSongs();
	Song* chosenSong = ChooseSong(songs, "Choose the song to delete:");
	chosenPlaylist->DeleteSongFromPlaylist(chosenSong);
}

Song* DeleteSongFromAllPlaylists(vector <Playlist*>& playlists, vector<Song*>& songs) {
	Playlist* chosenPlaylist = 0;
	Song* chosenSong = ChooseSong(songs, "Choose a song to delete:");

	for (int i = 0; i < playlists.size(); ++i) {
		chosenPlaylist = playlists.at(i);
		chosenPlaylist->DeleteSongFromPlaylist(chosenSong);
	}
	return chosenSong;
}

void DeleteSongFromLibrary(vector <Playlist*>& playlists, vector<Song*>& songs) {
	Song* songToDelete = DeleteSongFromAllPlaylists(playlists, songs);

	for (int i = 0; i < songs.size(); ++i) {
		if (songs.at(i) == songToDelete) {
			delete songs.at(i);
			songs.erase(songs.begin() + i);
		}
	}
}


void DeletePlaylist(vector <Playlist*>& playlists) {
	Playlist* chosenPlaylist = ChoosePlaylist(playlists, "Delete a whole playlist:");
	for (int i = 0; i < playlists.size(); ++i) {
		if (playlists.at(i) == chosenPlaylist) {
			delete playlists.at(i);
			playlists.erase(playlists.begin() + i);
		}
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
		else if (menuChoice == SHUFFLE_SONGS) {
			ShuffleSongs(songs);
		}
		else if (menuChoice == REMOVE_A_PLAYLIST) {
			DeletePlaylist(playlists);
		}
		else if (menuChoice == REMOVE_SONG_FROM_PLAYLIST) {
			DeleteSongFromPlaylist(playlists);
		}
		else if (menuChoice == REMOVE_SONG_FROM_LIBRARY) {
			DeleteSongFromLibrary(playlists, songs);
		}
	} while (menuChoice != QUIT_PROGRAM);

	CleanupAllPointers(playlists, songs);
	cout << "GOODBYE!";

	return 0;
}
