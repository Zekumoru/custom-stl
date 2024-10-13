#pragma once

#include <cstddef>
#include <istream>
#include <ostream>

namespace zkl
{
  /**
   * @brief Classe che implementa un vettore dinamico simile a std::vector.
   *
   * @tparam T Il tipo di elementi memorizzati nel vettore.
   */
  template <typename T>
  class vector
  {
  private:
    T* _array;        /**< Puntatore all'array dinamico che contiene gli elementi. */
    size_t _size;     /**< Numero corrente di elementi nel vettore. */
    size_t _capacity; /**< Capacità corrente del vettore (numero massimo di elementi prima del riallocamento). */

    /**
     * @brief Rialloca l'array interno a una nuova capacità.
     *
     * @param newCapacity La nuova capacità desiderata.
     */
    void reallocate(size_t newCapacity);

  public:
    /**
     * @brief Costruttore di default. Inizializza un vettore vuoto.
     */
    vector();

    /**
     * @brief Costruttore che inizializza il vettore con una capacità iniziale specificata.
     *
     * @param initialCapacity La capacità iniziale del vettore.
     */
    vector(size_t initialCapacity);

    /**
     * @brief Distruttore. Libera la memoria allocata per l'array.
     */
    ~vector();

    /**
     * @brief Aggiunge un elemento alla fine del vettore.
     *
     * @param value Riferimento all'elemento da aggiungere.
     */
    void push_back(const T& value);

    /**
     * @brief Rimuove l'ultimo elemento dal vettore.
     *
     * @throws std::out_of_range se il vettore è vuoto.
     */
    void pop_back();

    /**
     * @brief Accede all'elemento al indice specificato con controllo dei limiti.
     *
     * @param index L'indice dell'elemento da accedere.
     * @return Riferimento all'elemento al indice specificato.
     *
     * @throws std::out_of_range se l'indice è fuori dai limiti.
     */
    T& at(size_t index);

    /**
     * @brief Accede all'elemento al indice specificato con controllo dei limiti (versione const).
     *
     * @param index L'indice dell'elemento da accedere.
     * @return Riferimento costante all'elemento al indice specificato.
     *
     * @throws std::out_of_range se l'indice è fuori dai limiti.
     */
    const T& at(size_t index) const;

    /**
     * @brief Sovraccarica l'operatore di indicizzazione per l'accesso agli elementi senza controllo dei limiti.
     *
     * @param index L'indice dell'elemento da accedere.
     * @return Riferimento all'elemento al indice specificato.
     */
    T& operator[](size_t index);

    /**
     * @brief Sovraccarica l'operatore di indicizzazione per l'accesso agli elementi senza controllo dei limiti (versione const).
     *
     * @param index L'indice dell'elemento da accedere.
     * @return Riferimento costante all'elemento al indice specificato.
     */
    const T& operator[](size_t index) const;

    /**
     * @brief Restituisce il numero corrente di elementi nel vettore.
     *
     * @return Numero di elementi.
     */
    size_t size() const;

    /**
     * @brief Restituisce la capacità corrente del vettore.
     *
     * @return Capacità del vettore.
     */
    size_t capacity() const;

    /**
     * @brief Verifica se il vettore è vuoto.
     *
     * @return `true` se il vettore è vuoto, `false` altrimenti.
     */
    bool empty() const;

    /**
     * @brief Rimuove tutti gli elementi dal vettore senza modificare la capacità.
     */
    void clear() const;

    /**
     * @brief Riserva una capacità minima per il vettore.
     *
     * Se la nuova capacità specificata è maggiore della capacità attuale, il vettore viene riallocato con la nuova capacità.
     *
     * @param newCapacity La nuova capacità desiderata.
     */
    void reserve(size_t newCapacity);
  };

  /**
   * @brief Classe che implementa una stringa dinamica simile a std::string.
   */
  class string
  {
  public:
    /** Valore costante che rappresenta la posizione non valida. */
    static const size_t npos = -1;

    /**
     * @brief Costruttore di default. Inizializza una stringa vuota.
     */
    string();

    /**
     * @brief Costruttore che inizializza la stringa con una stringa C.
     *
     * @param string Puntatore a una stringa C (null-terminated).
     */
    string(const char* string);

    /**
     * @brief Costruttore di copia. Crea una nuova stringa come copia di un'altra.
     *
     * @param other Riferimento costante all'altra stringa da copiare.
     */
    string(const string& other);

    /**
     * @brief Costruttore di spostamento. Inizializza la stringa trasferendo le risorse da un'altra stringa.
     *
     * @param other Riferimento a rvalue di un'altra stringa.
     */
    string(string&& other) noexcept;

    /**
     * @brief Distruttore. Libera la memoria allocata per i dati della stringa.
     */
    ~string();

    /**
     * @brief Operatore di assegnazione di copia. Assegna il contenuto di un'altra stringa.
     *
     * @param other Riferimento costante all'altra stringa da assegnare.
     * @return Riferimento alla stringa assegnata.
     */
    string& operator=(const string& other);

    /**
     * @brief Operatore di assegnazione di spostamento. Assegna il contenuto di una stringa rvalue trasferendo le risorse.
     *
     * @param other Riferimento a rvalue di un'altra stringa.
     * @return Riferimento alla stringa assegnata.
     */
    string& operator=(string&& other) noexcept;

    /**
     * @brief Operatore di estrazione da flusso di input.
     *
     * @param is Riferimento al flusso di input.
     * @param str Riferimento alla stringa da riempire.
     * @return Riferimento al flusso di input.
     */
    friend std::istream& operator>>(std::istream& is, string& str);

    /**
     * @brief Operatore di inserimento in flusso di output.
     *
     * @param os Riferimento al flusso di output.
     * @param str Riferimento costante alla stringa da inserire.
     * @return Riferimento al flusso di output.
     */
    friend std::ostream& operator<<(std::ostream& os, const string& str);

    /**
     * @brief Restituisce la dimensione della stringa.
     *
     * @return Numero di caratteri nella stringa.
     */
    size_t size() const;

    /**
     * @brief Restituisce la lunghezza della stringa.
     *
     * @return Numero di caratteri nella stringa.
     */
    size_t length() const;

    /**
     * @brief Cancella il contenuto della stringa, rendendola vuota.
     */
    void clear();

    /**
     * @brief Verifica se la stringa è vuota.
     *
     * @return `true` se la stringa è vuota, `false` altrimenti.
     */
    bool empty() const;

    /**
     * @brief Operatore di indicizzazione per l'accesso ai caratteri senza controllo dei limiti.
     *
     * @param index L'indice del carattere da accedere.
     * @return Riferimento al carattere all'indice specificato.
     */
    char& operator[](const size_t index);

    /**
     * @brief Operatore di indicizzazione per l'accesso ai caratteri senza controllo dei limiti (versione const).
     *
     * @param index L'indice del carattere da accedere.
     * @return Riferimento costante al carattere all'indice specificato.
     */
    const char& operator[](const size_t index) const;

    /**
     * @brief Accede al carattere al indice specificato con controllo dei limiti.
     *
     * @param index L'indice del carattere da accedere.
     * @return Riferimento al carattere all'indice specificato.
     *
     * @throws std::out_of_range se l'indice è fuori dai limiti.
     */
    char& at(const size_t index);

    /**
     * @brief Accede al carattere al indice specificato con controllo dei limiti (versione const).
     *
     * @param index L'indice del carattere da accedere.
     * @return Riferimento costante al carattere all'indice specificato.
     *
     * @throws std::out_of_range se l'indice è fuori dai limiti.
     */
    const char& at(const size_t index) const;

    /**
     * @brief Restituisce una referenza al primo carattere della stringa.
     *
     * @return Riferimento al primo carattere.
     */
    char& front();

    /**
     * @brief Restituisce una referenza all'ultimo carattere della stringa.
     *
     * @return Riferimento all'ultimo carattere.
     */
    char& back();

    /**
     * @brief Restituisce una referenza costante al primo carattere della stringa.
     *
     * @return Riferimento costante al primo carattere.
     */
    const char& front() const;

    /**
     * @brief Restituisce una referenza costante all'ultimo carattere della stringa.
     *
     * @return Riferimento costante all'ultimo carattere.
     */
    const char& back() const;

    /**
     * @brief Aggiunge una stringa alla fine di questa stringa.
     *
     * @param other La stringa da aggiungere.
     * @return Riferimento alla stringa modificata.
     */
    string& operator+=(const string& other);

    /**
     * @brief Aggiunge una stringa C alla fine di questa stringa.
     *
     * @param str La stringa C da aggiungere.
     * @return Riferimento alla stringa modificata.
     */
    string& operator+=(const char* str);

    /**
     * @brief Aggiunge un carattere alla fine di questa stringa.
     *
     * @param c Il carattere da aggiungere.
     * @return Riferimento alla stringa modificata.
     */
    string& operator+=(char c);

    /**
     * @brief Concatenazione di due stringhe.
     *
     * @param left La stringa di sinistra.
     * @param right La stringa di destra.
     * @return Nuova stringa risultante dalla concatenazione.
     */
    friend string operator+(const string& left, const string& right);

    /**
     * @brief Concatenazione di un carattere e una stringa.
     *
     * @param left Il carattere di sinistra.
     * @param right La stringa di destra.
     * @return Nuova stringa risultante dalla concatenazione.
     */
    friend string operator+(char left, const string& right);

    /**
     * @brief Concatenazione di una stringa e un carattere.
     *
     * @param left La stringa di sinistra.
     * @param right Il carattere di destra.
     * @return Nuova stringa risultante dalla concatenazione.
     */
    friend string operator+(const string& left, char right);

    /**
     * @brief Aggiunge una stringa alla fine di questa stringa.
     *
     * @param str La stringa da aggiungere.
     * @return Riferimento alla stringa modificata.
     */
    string& append(const string& str);

    /**
     * @brief Aggiunge una sottostringa di un'altra stringa alla fine di questa stringa.
     *
     * @param str La stringa da cui prendere la sottostringa.
     * @param subpos La posizione di inizio nella stringa `str`.
     * @param sublen La lunghezza della sottostringa da aggiungere.
     * @return Riferimento alla stringa modificata.
     */
    string& append(const string& str, size_t subpos, size_t sublen);

    /**
     * @brief Aggiunge una stringa C alla fine di questa stringa.
     *
     * @param str La stringa C da aggiungere.
     * @return Riferimento alla stringa modificata.
     */
    string& append(const char* str);

    /**
     * @brief Aggiunge i primi `n` caratteri di una stringa C alla fine di questa stringa.
     *
     * @param str La stringa C da aggiungere.
     * @param n Il numero massimo di caratteri da aggiungere.
     * @return Riferimento alla stringa modificata.
     */
    string& append(const char* str, size_t n);

    /**
     * @brief Aggiunge `n` copie di un carattere alla fine di questa stringa.
     *
     * @param n Il numero di copie del carattere da aggiungere.
     * @param c Il carattere da aggiungere.
     * @return Riferimento alla stringa modificata.
     */
    string& append(size_t n, char c);

    /**
     * @brief Aggiunge un carattere alla fine della stringa.
     *
     * @param c Il carattere da aggiungere.
     * @return Riferimento alla stringa modificata.
     */
    string& push_back(char c);

    /**
     * @brief Assegna il contenuto di un'altra stringa a questa stringa.
     *
     * @param str La stringa da assegnare.
     * @return Riferimento alla stringa assegnata.
     */
    string& assign(const string& str);

    /**
     * @brief Assegna una sottostringa di un'altra stringa a questa stringa.
     *
     * @param str La stringa da cui prendere la sottostringa.
     * @param subpos La posizione di inizio nella stringa `str`.
     * @param sublen La lunghezza della sottostringa da assegnare.
     * @return Riferimento alla stringa assegnata.
     */
    string& assign(const string& str, size_t subpos, size_t sublen);

    /**
     * @brief Assegna una stringa C a questa stringa.
     *
     * @param str La stringa C da assegnare.
     * @return Riferimento alla stringa assegnata.
     */
    string& assign(const char* str);

    /**
     * @brief Assegna i primi `n` caratteri di una stringa C a questa stringa.
     *
     * @param s La stringa C da assegnare.
     * @param n Il numero massimo di caratteri da assegnare.
     * @return Riferimento alla stringa assegnata.
     */
    string& assign(const char* s, size_t n);

    /**
     * @brief Assegna `n` copie di un carattere a questa stringa.
     *
     * @param n Il numero di copie del carattere da assegnare.
     * @param c Il carattere da assegnare.
     * @return Riferimento alla stringa assegnata.
     */
    string& assign(size_t n, char c);

    /**
     * @brief Inserisce una stringa in una posizione specifica.
     *
     * @param pos La posizione in cui inserire la stringa.
     * @param str La stringa da inserire.
     * @return Riferimento alla stringa modificata.
     */
    string& insert(size_t pos, const string& str);

    /**
     * @brief Inserisce una stringa C in una posizione specifica.
     *
     * @param pos La posizione in cui inserire la stringa C.
     * @param str La stringa C da inserire.
     * @return Riferimento alla stringa modificata.
     */
    string& insert(size_t pos, const char* str);

    /**
     * @brief Rimuove una porzione della stringa a partire da una posizione specifica.
     *
     * @param pos La posizione di inizio della porzione da rimuovere.
     * @param len La lunghezza della porzione da rimuovere. Se omesso, rimuove fino alla fine.
     * @return Riferimento alla stringa modificata.
     */
    string& erase(size_t pos, size_t len = npos);

    /**
     * @brief Sostituisce una porzione della stringa con un'altra stringa.
     *
     * @param pos La posizione di inizio della porzione da sostituire.
     * @param len La lunghezza della porzione da sostituire.
     * @param str La stringa con cui sostituire.
     * @return Riferimento alla stringa modificata.
     */
    string& replace(size_t pos, size_t len, const string& str);

    /**
     * @brief Sostituisce una porzione della stringa con una stringa C.
     *
     * @param pos La posizione di inizio della porzione da sostituire.
     * @param len La lunghezza della porzione da sostituire.
     * @param str La stringa C con cui sostituire.
     * @return Riferimento alla stringa modificata.
     */
    string& replace(size_t pos, size_t len, const char* str);

    /**
     * @brief Scambia il contenuto di questa stringa con un'altra.
     *
     * @param str La stringa con cui scambiare.
     */
    void swap(string& str);

    /**
     * @brief Rimuove l'ultimo carattere della stringa.
     */
    void pop_back();

    /**
     * @brief Restituisce un puntatore alla stringa C interna.
     *
     * @return Puntatore costante alla stringa C.
     */
    const char* c_str() const noexcept;

    /**
     * @brief Restituisce un puntatore ai dati interni della stringa.
     *
     * @return Puntatore costante ai dati della stringa.
     */
    const char* data() const noexcept;

    /**
     * @brief Copia una porzione della stringa in un buffer.
     *
     * @param s Puntatore al buffer di destinazione.
     * @param len Numero massimo di caratteri da copiare.
     * @param pos Posizione di inizio nella stringa da cui iniziare la copia.
     * @return Numero di caratteri effettivamente copiati.
     */
    size_t copy(char* s, size_t len, size_t pos = 0);

    /**
     * @brief Cerca la prima occorrenza di una stringa all'interno di questa stringa.
     *
     * @param str La stringa da cercare.
     * @param pos La posizione di inizio della ricerca.
     * @return La posizione della prima occorrenza trovata, o `npos` se non trovata.
     */
    size_t find(const string& str, size_t pos = 0) const noexcept;

    /**
     * @brief Cerca la prima occorrenza di un carattere all'interno di questa stringa.
     *
     * @param c Il carattere da cercare.
     * @param pos La posizione di inizio della ricerca.
     * @return La posizione della prima occorrenza trovata, o `npos` se non trovata.
     */
    size_t find(char c, size_t pos = 0) const noexcept;

    /**
     * @brief Cerca la prima occorrenza di una sottostringa all'interno di questa stringa.
     *
     * @param str La stringa da cercare.
     * @param pos La posizione di inizio della ricerca.
     * @param n Numero massimo di caratteri da considerare nella stringa da cercare.
     * @return La posizione della prima occorrenza trovata, o `npos` se non trovata.
     */
    size_t find(const string& str, size_t pos, size_t n) const noexcept;

    /**
     * @brief Cerca l'ultima occorrenza di una stringa all'interno di questa stringa.
     *
     * @param str La stringa da cercare.
     * @param pos La posizione massima da cui iniziare la ricerca.
     * @return La posizione dell'ultima occorrenza trovata, o `npos` se non trovata.
     */
    size_t rfind(const string& str, size_t pos = npos) const noexcept;

    /**
     * @brief Cerca l'ultima occorrenza di un carattere all'interno di questa stringa.
     *
     * @param c Il carattere da cercare.
     * @param pos La posizione massima da cui iniziare la ricerca.
     * @return La posizione dell'ultima occorrenza trovata, o `npos` se non trovata.
     */
    size_t rfind(char c, size_t pos = npos) const noexcept;

    /**
     * @brief Cerca la prima occorrenza di qualsiasi carattere presente in una stringa all'interno di questa stringa.
     *
     * @param str La stringa contenente i caratteri da cercare.
     * @param pos La posizione di inizio della ricerca.
     * @return La posizione della prima occorrenza trovata, o `npos` se non trovata.
     */
    size_t find_first_of(const string& str, size_t pos = 0) const;

    /**
     * @brief Cerca la prima occorrenza di un carattere specifico all'interno di questa stringa.
     *
     * @param c Il carattere da cercare.
     * @param pos La posizione di inizio della ricerca.
     * @return La posizione della prima occorrenza trovata, o `npos` se non trovata.
     */
    size_t find_first_of(char c, size_t pos = 0) const;

    /**
     * @brief Cerca l'ultima occorrenza di qualsiasi carattere presente in una stringa all'interno di questa stringa.
     *
     * @param str La stringa contenente i caratteri da cercare.
     * @param pos La posizione massima da cui iniziare la ricerca.
     * @return La posizione dell'ultima occorrenza trovata, o `npos` se non trovata.
     */
    size_t find_last_of(const string& str, size_t pos = npos) const;

    /**
     * @brief Cerca l'ultima occorrenza di un carattere specifico all'interno di questa stringa.
     *
     * @param c Il carattere da cercare.
     * @param pos La posizione massima da cui iniziare la ricerca.
     * @return La posizione dell'ultima occorrenza trovata, o `npos` se non trovata.
     */
    size_t find_last_of(char c, size_t pos = npos) const;

    /**
     * @brief Cerca la prima posizione in cui nessuno dei caratteri presenti in una stringa si trova all'interno di questa stringa.
     *
     * @param str La stringa contenente i caratteri da escludere.
     * @param pos La posizione di inizio della ricerca.
     * @return La posizione della prima occorrenza trovata, o `npos` se non trovata.
     */
    size_t find_first_not_of(const string& str, size_t pos = 0) const;

    /**
     * @brief Cerca la prima posizione in cui un carattere specifico non si trova all'interno di questa stringa.
     *
     * @param c Il carattere da escludere.
     * @param pos La posizione di inizio della ricerca.
     * @return La posizione della prima occorrenza trovata, o `npos` se non trovata.
     */
    size_t find_first_not_of(char c, size_t pos = 0) const;

    /**
     * @brief Cerca l'ultima posizione in cui nessuno dei caratteri presenti in una stringa si trova all'interno di questa stringa.
     *
     * @param str La stringa contenente i caratteri da escludere.
     * @param pos La posizione massima da cui iniziare la ricerca.
     * @return La posizione dell'ultima occorrenza trovata, o `npos` se non trovata.
     */
    size_t find_last_not_of(const string& str, size_t pos = npos) const;

    /**
     * @brief Cerca l'ultima posizione in cui un carattere specifico non si trova all'interno di questa stringa.
     *
     * @param c Il carattere da escludere.
     * @param pos La posizione massima da cui iniziare la ricerca.
     * @return La posizione dell'ultima occorrenza trovata, o `npos` se non trovata.
     */
    size_t find_last_not_of(char c, size_t pos = npos) const;

    /**
     * @brief Restituisce una sottostringa a partire da una posizione specifica e di una lunghezza specificata.
     *
     * @param pos La posizione di inizio della sottostringa.
     * @param len La lunghezza della sottostringa. Se omesso, restituisce fino alla fine della stringa.
     * @return La sottostringa risultante.
     */
    string substr(size_t pos = 0, size_t len = npos) const;

    /**
     * @brief Confronta questa stringa con un'altra stringa.
     *
     * @param str La stringa da confrontare.
     * @return Un valore negativo se questa stringa è minore, zero se sono uguali, positivo se è maggiore.
     */
    int compare(const string& str) const noexcept;

    /**
     * @brief Confronta una porzione di questa stringa con una porzione di un'altra stringa.
     *
     * @param pos La posizione di inizio nella stringa corrente.
     * @param len La lunghezza della porzione nella stringa corrente.
     * @param str La stringa da confrontare.
     * @return Un valore negativo se questa stringa è minore, zero se sono uguali, positivo se è maggiore.
     *
     * @throws std::out_of_range se la posizione è maggiore della lunghezza della stringa.
     */
    int compare(size_t pos, size_t len, const string& str) const noexcept;

    /**
     * @brief Estrae una linea da un flusso di input e la memorizza nella stringa.
     *
     * @param is Riferimento al flusso di input.
     * @param str Riferimento alla stringa in cui memorizzare la linea.
     * @return Riferimento al flusso di input.
     */
    friend std::istream& getline(std::istream& is, string& str);

    /**
     * @brief Estrae una linea da un flusso di input fino a un delimitatore specificato e la memorizza nella stringa.
     *
     * @param is Riferimento al flusso di input.
     * @param str Riferimento alla stringa in cui memorizzare la linea.
     * @param delim Il carattere delimitatore.
     * @return Riferimento al flusso di input.
     */
    friend std::istream& getline(std::istream& is, string& str, char delim);

  private:
    char* _data;  /**< Puntatore ai dati della stringa. */
    size_t _size; /**< Numero di caratteri nella stringa. */
  };

  /**
   * @brief Operatore di uguaglianza tra due stringhe.
   *
   * @param lhs La stringa di sinistra.
   * @param rhs La stringa di destra.
   * @return `true` se le stringhe sono uguali, `false` altrimenti.
   */
  bool operator==(const string& lhs, const string& rhs) noexcept;

  /**
   * @brief Operatore di disuguaglianza tra due stringhe.
   *
   * @param lhs La stringa di sinistra.
   * @param rhs La stringa di destra.
   * @return `true` se le stringhe sono diverse, `false` altrimenti.
   */
  bool operator!=(const string& lhs, const string& rhs) noexcept;

  /**
   * @brief Operatore di minore tra due stringhe.
   *
   * @param lhs La stringa di sinistra.
   * @param rhs La stringa di destra.
   * @return `true` se `lhs` è minore di `rhs`, `false` altrimenti.
   */
  bool operator<(const string& lhs, const string& rhs) noexcept;

  /**
   * @brief Operatore di minore o uguale tra due stringhe.
   *
   * @param lhs La stringa di sinistra.
   * @param rhs La stringa di destra.
   * @return `true` se `lhs` è minore o uguale a `rhs`, `false` altrimenti.
   */
  bool operator<=(const string& lhs, const string& rhs) noexcept;

  /**
   * @brief Operatore di maggiore tra due stringhe.
   *
   * @param lhs La stringa di sinistra.
   * @param rhs La stringa di destra.
   * @return `true` se `lhs` è maggiore di `rhs`, `false` altrimenti.
   */
  bool operator>(const string& lhs, const string& rhs) noexcept;

  /**
   * @brief Operatore di maggiore o uguale tra due stringhe.
   *
   * @param lhs La stringa di sinistra.
   * @param rhs La stringa di destra.
   * @return `true` se `lhs` è maggiore o uguale a `rhs`, `false` altrimenti.
   */
  bool operator>=(const string& lhs, const string& rhs) noexcept;

  /**
   * @brief Scambia il contenuto di due stringhe.
   *
   * @param x La prima stringa.
   * @param y La seconda stringa.
   */
  void swap(string& x, string& y);
} // namespace zkl

#include "string.tpp"
#include "vector.tpp"
