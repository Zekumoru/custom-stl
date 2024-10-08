#pragma once

#include <cstddef>

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
    T *_array;        /**< Puntatore all'array dinamico che contiene gli elementi. */
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
    void push_back(const T &value);

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
    T &at(size_t index);

    /**
     * @brief Accede all'elemento al indice specificato con controllo dei limiti (versione const).
     *
     * @param index L'indice dell'elemento da accedere.
     * @return Riferimento costante all'elemento al indice specificato.
     *
     * @throws std::out_of_range se l'indice è fuori dai limiti.
     */
    const T &at(size_t index) const;

    /**
     * @brief Sovraccarica l'operatore di indicizzazione per l'accesso agli elementi senza controllo dei limiti.
     *
     * @param index L'indice dell'elemento da accedere.
     * @return Riferimento all'elemento al indice specificato.
     */
    T &operator[](size_t index);

    /**
     * @brief Sovraccarica l'operatore di indicizzazione per l'accesso agli elementi senza controllo dei limiti (versione const).
     *
     * @param index L'indice dell'elemento da accedere.
     * @return Riferimento costante all'elemento al indice specificato.
     */
    const T &operator[](size_t index) const;

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
}

#include "vector.tpp"
