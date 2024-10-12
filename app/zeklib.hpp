#pragma once

#include <cstddef>
#include <ostream>

namespace zeklib
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

  class string
  {
  public:
    static const size_t npos = -1;

    string();
    string(const char* string);
    string(const string& other);
    string(string&& other) noexcept;
    ~string();

    string& operator=(const string& other);
    string& operator=(string&& other) noexcept;

    friend std::ostream& operator<<(std::ostream& os, const string& other);

    size_t size() const;
    size_t length() const;

    void clear();
    bool empty() const;

    char& operator[](const size_t index);
    char& at(const size_t index);
    const char& operator[](const size_t index) const;
    const char& at(const size_t index) const;

    char& front();
    char& back();
    const char& front() const;
    const char& back() const;

    string& operator+=(const string& other);
    string& operator+=(const char* str);
    string& operator+=(char c);

    friend string operator+(const string& left, const string& right);
    friend string operator+(char left, const string& right);
    friend string operator+(const string& left, char right);

    string& append(const string& str);
    string& append(const string& str, size_t subpos, size_t sublen);
    string& append(const char* str);
    string& append(const char* str, size_t n);
    string& append(size_t n, char c);

    string& push_back(char c);
    string& assign(const string& str);
    string& assign(const string& str, size_t subpos, size_t sublen);
    string& assign(const char* str);
    string& assign(const char* s, size_t n);
    string& assign(size_t n, char c);

    string& insert(size_t pos, const string& str);
    string& insert(size_t pos, const char* str);
    string& erase(size_t pos, size_t len = npos);
    string& replace(size_t pos, size_t len, const string& str);
    string& replace(size_t pos, size_t len, const char* str);

    void swap(string& str);
    void pop_back();

    const char* c_str() const noexcept;
    const char* data() const noexcept;

    size_t copy(char* s, size_t len, size_t pos = 0);
    size_t find(const string& str, size_t pos = 0) const noexcept;
    size_t find(char c, size_t pos = 0) const noexcept;
    size_t find(const string& str, size_t pos, size_t n) const noexcept;
    size_t rfind(const string& str, size_t pos = npos) const noexcept;
    size_t rfind(char c, size_t pos = npos) const noexcept;

    size_t find_first_of(const string& str, size_t pos = 0) const;
    size_t find_first_of(char c, size_t pos = 0) const;
    size_t find_last_of(const string& str, size_t pos = npos) const;
    size_t find_last_of(char c, size_t pos = npos) const;
    size_t find_first_not_of(const string& str, size_t pos = 0) const;
    size_t find_first_not_of(char c, size_t pos = 0) const;
    size_t find_last_not_of(const string& str, size_t pos = npos) const;
    size_t find_last_not_of(char c, size_t pos = npos) const;

  private:
    char* _data;
    size_t _size;
  };

  string operator+(const string& left, const string& right);
  string operator+(char left, const string& right);
  string operator+(const string& left, char right);
} // namespace zeklib

#include "string.tpp"
#include "vector.tpp"
