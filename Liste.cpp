//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIII
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @file Liste.cpp
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{


	ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        neuesElement->setPrev(back);
        back = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enthaelt nur ein Listenelement
    {
        delete front;                                        // Listenelement loeschen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student* Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
        cursor->getData()->ausgabe();

        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
	ListenElement* cursor = back;

	while (cursor != nullptr)
	{
		cursor->getData()->ausgabe();

		cursor = cursor->getPrev();
	}

}

/**
 * @brief Durchsuchen der Liste nach einem Element mit bestimmter Matrikelnummer und loeschen von diesem
 * Die Liste wird elementweise vom ersten bis zum letzten Element durchgegangen und die jeweilige Matrikelnummer mit der zu loeschenden Nummer verglichen.
 * Anschliessend wird dieses Element geloescht. Anschliessend wird ausgegeben wie viele Elemente mit der entsprechenden Matrikelnummer gefunden wurden
 * und dass diese geloescht wurden.
 *
 * @param pMatrikelnr Uebergebene Matrikelnummer des Elementes, welches geloescht werden soll
 * @return void
 */
void Liste::datenElementLoeschen(unsigned int pMatrikelnr)
{

	// Zeiger soll beim ersten Element starten. Counter zaehlt die gefundenen Elemente.
	ListenElement* cursor = front;
	int counter = 0;

	// Solange der Zeiger noch auf ein Element der Liste Zeigt.
	while (cursor != nullptr)
	{

		// Erfasse Liste mit nur einem Element
		if(front == back)
		{
			front = nullptr;
			back = nullptr;

			std::cout << "Geloeschtes Element: " << std::endl;
			cursor->getData()->ausgabe();

			delete cursor;
			counter++;
			break;
		}

		// Erfassen der Matrikelnummer des aktuellen Elementes.
		unsigned int currentNb = cursor->getData()->getMatNr();

		if(currentNb == pMatrikelnr)
		{

			// Ueberpruefung, ob das Element am Anfang der Liste ist.
			if(cursor->getPrev() == nullptr)
			{
				front = cursor->getNext();
				cursor->getNext()->setPrev(nullptr);
			}
			else
			{
				cursor->getPrev()->setNext(cursor->getNext());
			}

			// Ueberpruefung, ob das Element am Ende der Liste ist.
			if(cursor->getNext() == nullptr)
		    {
				back = cursor->getPrev();
				cursor->getPrev()->setNext(nullptr);
		    }
			else
			{
				cursor->getNext()->setPrev(cursor->getPrev());
			}


			std::cout << "Geloeschtes Element: " << std::endl;
			cursor->getData()->ausgabe();

			counter++;
		}


		cursor = cursor->getNext();
	}

	// Anzeogen ob, und wie viele Elemente geloescht wurden.
	if(counter == 0)
	{
		std::cout << "Kein Element in der Liste mit der Matrikelnummer: " << pMatrikelnr << " gefunden. Kein Element gelöscht." << std::endl;
	}
	else if(counter == 1)
	{
		std::cout << "Es wurde ein Element in der Liste mit der Matrikelnummer: " << pMatrikelnr << " gefunden und gelöscht." << std::endl;
	}
	else
	{
		std::cout << "Es wurden  " << counter << " Elemente in der Liste mit der Matrikelnummer: " << pMatrikelnr << " gefunden und gelöscht." << std::endl;
	}

}

/**
 * @brief Element am Anfang der Liste einfuegen.
 * Es wird ein neues Element mit den uebergebenen Daten erstellt und anschliessend der Next- und Prevzeiger neu zugewiesen.
 * Auch wird ueberprueft, ob die Liste leer ist ansonsten wird noch der Prevzeiger vom nachfolgendem Element neu zugewiesen.
 * @param pData
 */
void Liste::pushFront(Student pData)
{

	// Lege neues Element an.
	ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

	// Ueberpruefe, ob liste leer ist.
	if (back == nullptr)
	{
		back = neuesElement;
	}
	else
	{

		// Neues Verknuepfen der ersten beiden Elemente.
		neuesElement->setNext(front);
		front->setPrev(neuesElement);
	}

	// Zuweisen des Frontzeigers auf das neue erste Element.
	front = neuesElement;

}
