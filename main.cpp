/**
 * @file main.cpp
 * @brief Esempio di utilizzo del vettore personalizzato della libreria zeklib.
 *
 * Questo programma dimostra l'utilizzo della classe `zeklib::vector` implementata come un vettore dinamico simile a `std::vector`.
 * Vengono aggiunti elementi, accessi, rimozioni e gestione delle eccezioni per mostrare le funzionalità principali del vettore personalizzato.
 */

#include "app/zeklib.hpp"
#include <iostream>

/**
 * @brief Funzione principale che dimostra l'utilizzo del vettore personalizzato.
 *
 * Il programma esegue le seguenti operazioni:
 * - Aggiunge elementi al vettore.
 * - Accede e stampa gli elementi.
 * - Rimuove l'ultimo elemento.
 * - Controlla e stampa la dimensione e la capacità.
 * - Utilizza la funzione `at()` con controllo dei limiti per accedere agli elementi, gestendo eventuali eccezioni.
 *
 * @return `0` se l'esecuzione avviene con successo.
 */
int main()
{
  // Creazione di un vettore di interi utilizzando la classe personalizzata
  zeklib::vector<int> vec;

  // Aggiunta di elementi al vettore
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);

  // Accesso e stampa degli elementi nel vettore
  std::cout << "Elements in vector:" << std::endl;
  for (size_t i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  // Rimozione dell'ultimo elemento dal vettore
  vec.pop_back();

  // Verifica e stampa della dimensione e della capacità del vettore dopo la rimozione
  std::cout << "Size after pop: " << vec.size() << std::endl;
  std::cout << "Capacity: " << vec.capacity() << std::endl;

  // Utilizzo della funzione `at()` con controllo dei limiti per accedere agli elementi
  try
  {
    std::cout << "Element at index 1: " << vec.at(1) << std::endl;
    std::cout << "Element at index 5: " << vec.at(5) << std::endl; // Questo lancerà un'eccezione
  }
  catch (const std::out_of_range &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
