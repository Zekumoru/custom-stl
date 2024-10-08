/**
 * @brief Esempio interattivo di utilizzo del vettore personalizzato della libreria zeklib.
 *
 * Questo programma permette all'utente di inserire numeri interi in un vettore dinamico personalizzato (`zeklib::vector<int>`).
 * L'utente può continuare ad aggiungere numeri fino a quando decide di terminare l'inserimento inserendo 'e' o 'E'.
 * Alla fine, il programma stampa tutti i numeri inseriti in formato [n1, n2, n3, ...] e mostra la dimensione e la capacità del vettore.
 */

#include "app/zeklib.hpp"
#include <iostream>
#include <string>
#include <stdexcept> // Per std::out_of_range e std::stoi

/**
 * @brief Funzione principale che gestisce l'interazione con l'utente e dimostra l'utilizzo del vettore personalizzato.
 *
 * Il programma esegue le seguenti operazioni:
 * - Richiede all'utente di inserire numeri interi.
 * - Aggiunge i numeri inseriti al vettore `zeklib::vector<int>`.
 * - Permette all'utente di terminare l'inserimento digitando 'e' o 'E'.
 * - Gestisce eventuali errori di conversione dell'input.
 * - Stampa tutti gli elementi inseriti nel vettore nel formato [n1, n2, n3, ...].
 *
 * @return `0` se l'esecuzione avviene con successo.
 */
int main()
{
  // Creazione di un vettore di interi utilizzando la classe personalizzata
  zeklib::vector<int> integers;
  std::string input;

  std::cout << "Programma di inserimento numeri interi nel vettore personalizzato (digita 'e' o 'E' per terminare)." << std::endl;

  do
  {
    std::cout << "Inserire un numero intero (o 'e' per terminare): ";
    std::getline(std::cin, input);

    // Verifica se l'utente ha deciso di terminare l'inserimento
    if (input == "e" || input == "E")
    {
      break;
    }

    try
    {
      // Tenta di convertire l'input in un intero
      int numero = std::stoi(input);
      integers.push_back(numero);
      std::cout << "Numero " << numero << " aggiunto al vettore." << std::endl;
      std::cout << std::endl;
    }
    catch (const std::invalid_argument &)
    {
      std::cerr << "Errore: Input non valido. Per favore, inserisci un numero intero o 'e' per terminare." << std::endl;
    }
    catch (const std::out_of_range &)
    {
      std::cerr << "Errore: Numero troppo grande. Per favore, inserisci un numero intero valido." << std::endl;
    }

  } while (true);

  // Stampa degli elementi inseriti nel vettore nel formato [n1, n2, n3, ...]
  std::cout << "\nElementi inseriti nel vettore: ";
  std::cout << "[";

  for (size_t i = 0; i < integers.size(); ++i)
  {
    std::cout << integers[i];
    if (i != integers.size() - 1)
    {
      std::cout << ", ";
    }
  }

  std::cout << "]" << std::endl;

  // Verifica e stampa della dimensione e della capacità del vettore
  std::cout << "\nDimensione del vettore: " << integers.size() << std::endl;
  std::cout << "Capacità del vettore: " << integers.capacity() << std::endl;

  return 0;
}
