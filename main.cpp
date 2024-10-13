/**
 * @brief Applicazione interattiva per testare la classe zkl::string.
 *
 * Questo programma fornisce un'interfaccia utente interattiva che permette di
 * eseguire varie operazioni sulla classe `zkl::string`, una reimplementazione
 * personalizzata della classe `std::string` della Standard Template Library (STL).
 *
 * Le funzionalità offerte includono:
 * - Inserimento di una nuova stringa
 * - Visualizzazione della stringa corrente
 * - Aggiunta di un carattere alla fine della stringa
 * - Aggiunta di un'altra stringa alla fine
 * - Concatenazione di due stringhe senza modificare la stringa principale
 * - Confronto tra stringhe
 * - Ricerca di sottostringhe
 * - Inserimento di sottostringhe in posizioni specifiche
 * - Rimozione di porzioni della stringa
 * - Sostituzione di porzioni della stringa
 *
 * **Metodi Reimplementati da `std::string`:**
 *
 * **Costruttori e Distruttore:**
 * - `string()`
 * - `string(const char* string)`
 * - `string(const string& other)`
 * - `string(string&& other) noexcept`
 * - `~string()`
 *
 * **Operatori di Assegnazione:**
 * - `operator=(const string& other)`
 * - `operator=(string&& other) noexcept`
 *
 * **Operatori di Accesso:**
 * - `char& operator[](const size_t index)`
 * - `const char& operator[](const size_t index) const`
 * - `char& at(const size_t index)`
 * - `const char& at(const size_t index) const`
 * - `char& front()`
 * - `const char& front() const`
 * - `char& back()`
 * - `const char& back() const`
 *
 * **Operatori di Aggiunta e Concatenazione:**
 * - `string& operator+=(const string& other)`
 * - `string& operator+=(const char* str)`
 * - `string& operator+=(char c)`
 * - `friend string operator+(const string& left, const string& right)`
 * - `friend string operator+(char left, const string& right)`
 * - `friend string operator+(const string& left, char right)`
 *
 * **Metodi di Modifica:**
 * - `string& append(const string& str)`
 * - `string& append(const string& str, size_t subpos, size_t sublen)`
 * - `string& append(const char* str)`
 * - `string& append(const char* str, size_t n)`
 * - `string& append(size_t n, char c)`
 * - `string& push_back(char c)`
 * - `string& assign(const string& str)`
 * - `string& assign(const string& str, size_t subpos, size_t sublen)`
 * - `string& assign(const char* str)`
 * - `string& assign(const char* s, size_t n)`
 * - `string& assign(size_t n, char c)`
 * - `string& insert(size_t pos, const string& str)`
 * - `string& insert(size_t pos, const char* str)`
 * - `string& erase(size_t pos, size_t len = npos)`
 * - `string& replace(size_t pos, size_t len, const string& str)`
 * - `string& replace(size_t pos, size_t len, const char* str)`
 * - `void swap(string& str)`
 * - `void pop_back()`
 *
 * **Metodi di Ricerca:**
 * - `size_t find(const string& str, size_t pos = 0) const noexcept`
 * - `size_t find(char c, size_t pos = 0) const noexcept`
 * - `size_t find(const string& str, size_t pos, size_t n) const noexcept`
 * - `size_t rfind(const string& str, size_t pos = npos) const noexcept`
 * - `size_t rfind(char c, size_t pos = npos) const noexcept`
 * - `size_t find_first_of(const string& str, size_t pos = 0) const`
 * - `size_t find_first_of(char c, size_t pos = 0) const`
 * - `size_t find_last_of(const string& str, size_t pos = npos) const`
 * - `size_t find_last_of(char c, size_t pos = npos) const`
 * - `size_t find_first_not_of(const string& str, size_t pos = 0) const`
 * - `size_t find_first_not_of(char c, size_t pos = 0) const`
 * - `size_t find_last_not_of(const string& str, size_t pos = npos) const`
 * - `size_t find_last_not_of(char c, size_t pos = npos) const`
 * - `size_t copy(char* s, size_t len, size_t pos = 0)`
 * - `size_t substr(size_t pos = 0, size_t len = npos) const`
 *
 * **Metodi di Utilità:**
 * - `size_t size() const`
 * - `size_t length() const`
 * - `void clear()`
 * - `bool empty() const`
 * - `const char* c_str() const noexcept`
 * - `const char* data() const noexcept`
 * - `int compare(const string& str) const noexcept`
 * - `int compare(size_t pos, size_t len, const string& str) const noexcept`
 *
 * **Operatori di Confronto:**
 * - `bool operator==(const string& lhs, const string& rhs) noexcept`
 * - `bool operator!=(const string& lhs, const string& rhs) noexcept`
 * - `bool operator<(const string& lhs, const string& rhs) noexcept`
 * - `bool operator<=(const string& lhs, const string& rhs) noexcept`
 * - `bool operator>(const string& lhs, const string& rhs) noexcept`
 * - `bool operator>=(const string& lhs, const string& rhs) noexcept`
 *
 * **Operatori di Stream:**
 * - `friend std::istream& operator>>(std::istream& is, string& str)`
 * - `friend std::ostream& operator<<(std::ostream& os, const string& str)`
 * - `friend std::istream& getline(std::istream& is, string& str)`
 * - `friend std::istream& getline(std::istream& is, string& str, char delim)`
 *
 * Questo strumento è utile per verificare e dimostrare le funzionalità della
 * classe `zkl::string`, assicurandosi che si comporti in modo simile a `std::string`.
 */
#include "zkl/zkl.hpp"
#include <cstdlib>   // Per std::atoi
#include <iostream>  // Per funzioni io
#include <limits>    // Per std::numeric_limits
#include <stdexcept> // Per std::invalid_argument

/**
 * @brief Visualizza il menu delle opzioni disponibili all'utente.
 */
void displayMenu()
{
  std::cout << "--- Menu delle Operazioni sulla Stringa ---\n";
  std::cout << "1. Inserisci una nuova stringa\n";
  std::cout << "2. Visualizza la stringa corrente\n";
  std::cout << "3. Aggiungi un carattere alla fine\n";
  std::cout << "4. Aggiungi una stringa alla fine\n";
  std::cout << "5. Concatenazione di due stringhe (non modifica la stringa principale)\n";
  std::cout << "6. Confronta con un'altra stringa\n";
  std::cout << "7. Trova una sottostringa\n";
  std::cout << "8. Inserisci una sottostringa in una posizione specifica\n";
  std::cout << "9. Rimuovi una porzione della stringa\n";
  std::cout << "10. Sostituisci una porzione della stringa\n";
  std::cout << "11. Esci\n";
  std::cout << "Scegli un'opzione (1-11): ";
}

/**
 * @brief Cancella lo schermo.
 */
void clrscr()
{
  std::cout << "\033[2J\033[1;1H";
}

/**
 * @brief Svuota l'input buffer.
 */
void flushInput()
{
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Mette in pausa il programma fino l'invio.
 */
void pause()
{
  std::cout << std::endl;
  std::cout << "Premere 'invio' per continuare..." << std::endl;
  flushInput();
}

/**
 * @brief Prende dall'utente un input intero.
 * @return Il valore messo dall'utente. Se invalido, restituisce 0.
 */
int getInt()
{
  zkl::string line;
  zkl::getline(std::cin, line);
  return std::atoi(line.c_str());
}

int main()
{
  zkl::string mainStr;  // La stringa principale su cui operare
  zkl::string otherStr; // Una stringa ausiliaria per alcune operazioni
  int choice;
  bool exitFlag = false;

  std::cout << "Benvenuto nell'applicazione interattiva della classe zkl::string!\n";

  while (!exitFlag)
  {
    clrscr();
    displayMenu();
    choice = getInt();

    std::cout << std::endl;

    if (choice >= 2 && choice <= 10 && mainStr.c_str() == nullptr)
    {
      std::cout << "Devi impostare prima la stringa principale selezionando l'opzione 1!" << std::endl;
      pause();
      continue;
    }

    switch (choice)
    {
    case 1:
    {
      std::cout << "Inserisci la nuova stringa: ";
      zkl::string inputStr;
      zkl::getline(std::cin, inputStr);
      mainStr = inputStr;
      std::cout << "Stringa aggiornata: " << mainStr << std::endl;
      break;
    }
    case 2:
    {
      std::cout << "Stringa corrente: " << mainStr << std::endl;
      break;
    }
    case 3:
    {
      std::cout << "Inserisci il carattere da aggiungere: ";
      char c;
      std::cin >> c;
      flushInput();
      mainStr.push_back(c);
      std::cout << "Stringa aggiornata: " << mainStr << std::endl;
      break;
    }
    case 4:
    {
      std::cout << "Inserisci la stringa da aggiungere: ";
      zkl::string addStr;
      zkl::getline(std::cin, addStr);
      mainStr += addStr;
      std::cout << "Stringa aggiornata: " << mainStr << std::endl;
      break;
    }
    case 5:
    {
      std::cout << "Inserisci la seconda stringa per la concatenazione: ";
      zkl::getline(std::cin, otherStr);
      zkl::string concatenated = mainStr + otherStr;
      std::cout << "Risultato della concatenazione: " << concatenated << std::endl;
      break;
    }
    case 6:
    {
      std::cout << "Inserisci la stringa da confrontare: ";
      zkl::getline(std::cin, otherStr);
      int cmpResult = mainStr.compare(otherStr);
      if (cmpResult == 0)
      {
        std::cout << "Le stringhe sono uguali.\n";
      }
      else if (cmpResult < 0)
      {
        std::cout << "La stringa corrente è minore della stringa fornita.\n";
      }
      else
      {
        std::cout << "La stringa corrente è maggiore della stringa fornita.\n";
      }
      break;
    }
    case 7:
    {
      std::cout << "Inserisci la sottostringa da cercare: ";
      zkl::getline(std::cin, otherStr);
      size_t pos = mainStr.find(otherStr);
      if (pos != zkl::string::npos)
      {
        std::cout << "Sottostringa trovata alla posizione: " << pos << std::endl;
      }
      else
      {
        std::cout << "Sottostringa non trovata.\n";
      }
      break;
    }
    case 8:
    {
      std::cout << "Inserisci la sottostringa da inserire: ";
      zkl::getline(std::cin, otherStr);
      std::cout << "Inserisci la posizione in cui inserire: ";
      size_t insertPos = getInt();
      try
      {
        mainStr.insert(insertPos, otherStr);
        std::cout << "Stringa aggiornata: " << mainStr << std::endl;
      }
      catch (const std::out_of_range& e)
      {
        std::cout << "Errore: " << e.what() << std::endl;
      }
      break;
    }
    case 9:
    {
      std::cout << "Inserisci la posizione da cui iniziare a rimuovere: ";
      size_t erasePos = getInt();
      std::cout << "Inserisci la lunghezza della porzione da rimuovere (-1 per rimuovere fino alla fine): ";
      size_t eraseLen = getInt();
      mainStr.erase(erasePos, eraseLen);
      std::cout << "Stringa aggiornata: " << mainStr << std::endl;
      break;
    }
    case 10:
    {
      std::cout << "Inserisci la posizione da cui iniziare a sostituire: ";
      size_t replacePos = getInt();
      std::cout << "Inserisci la lunghezza della porzione da sostituire: ";
      size_t replaceLen = getInt();
      std::cout << "Inserisci la stringa sostitutiva: ";
      zkl::getline(std::cin, otherStr);
      mainStr.replace(replacePos, replaceLen, otherStr);
      std::cout << "Stringa aggiornata: " << mainStr << std::endl;
      break;
    }
    case 11:
    {
      exitFlag = true;
      std::cout << "Uscita dall'applicazione. Arrivederci!\n";
      break;
    }
    default:
    {
      std::cout << "Opzione non valida. Per favore, scegli un numero tra 1 e 11.\n";
      break;
    }
    }

    if (choice != 11)
    {
      pause();
    }
  }

  return 0;
}
