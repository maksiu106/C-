#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
    std::cout << "Wprowadz sciezke do katalogu, dla ktorego chcesz wypisac zwykla zawartosc" << std::endl;
    std::string lokalizacja;
    std::cin >> lokalizacja;
    int i=1;
    for (auto const& dir_entry : fs::directory_iterator(lokalizacja)) //iterator przechodzi po wszystkich plikach w lokalizacji
    {
        std::string plik = dir_entry.path(); //w stringu zapisujemy sciezke do kazdego pliku, na ktory wskazuje iterator
                                             //nastepnie: jesli plik jest zwyklym plikiem, wypisujemy jego nazwe i rozmiar
        if (fs::is_regular_file(plik) == true) {std::cout << i << ". NAZWA PLIKU: " << fs::path(plik).filename() << ", ROZMIAR PLIKU: " << fs::file_size(plik) << " bajtow" << std::endl; i++;}
    }
    if (i==1) std::cout << "W tej lokalizacji nie ma zadnych zwyklych plikow" << std::endl;
}