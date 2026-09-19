#include <iostream>
#include <string>
#include <vector>

class Playlist {
private:
    std::vector<std::string> songs;
    int maxSize;

public:
    Playlist(int max_size) : maxSize(max_size) {}

    void addSong(const std::string& song) {
        if (songs.size() < maxSize) {
            songs.push_back(song);
        }
    }

    // Returning by value naturally creates a safe copy in C++
    std::vector<std::string> getSongs() const {
        return songs;
    }

    int getSongCount() const {
        return songs.size();
    }
};

// Usage Example
void testPlaylist() {
    Playlist p(10);
    p.addSong("Song A");
    p.addSong("Song B");
    
    std::vector<std::string> copy = p.getSongs();
    copy[0] = "Hacked"; 
    
    std::cout << "Original first song: " << p.getSongs()[0] << "\n"; // "Song A"
    std::cout << "Song count: " << p.getSongCount() << "\n"; // 2
}