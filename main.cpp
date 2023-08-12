/** @mainpage
 *
 * Praktikum Informatik 2 MMXXIII <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>

#include "Liste.h"
#include "Student.h"
/**
 * @file main.cpp
 * @brief Mainfunktion zum erstellen einer Liste
 * 1) Abfrage, ob die Liste selber oder automatisch gefuellt werden soll.
 * -> Beim automatischen Fuellen werden bereits festgelegte Listenobjekte erstellt und der Liste hinten angefuegt.
 * 2) Anzeigen der verschiedenen Manipulationsmöglichkeiten der Liste.
 * -> Abfrage mittels Switch;Case der verschiedenen Punkte (1-6,8);
 * -> (Rueckwaerts- , Vorwaertsausgeben, beliebiges/erstes Datenelement loeschen, Element hinten/vorne hinzufuegen und Programm beenden)
 *
 * @return
 */
int main()
{

	// Erstellen der Liste.
    Liste studentenListe;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    // Automatisches fuellen der Liste, falls erwuenscht.
    if (abfrage != 'j')
    {
    	Student student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.pushBack(student);
        Student student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.pushBack(student);
        Student student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.pushBack(student);
        Student student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.pushBack(student);
        Student student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
        studentenListe.pushBack(student);
    }

    // Abfrage der verschiedenen Menupunkten.
    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
				  << "(5): Datenelement mit Matrikelnummer loeschen" << std::endl
				  << "(6): Datenelement vorne hinzufuegen" << std::endl
                  << "(8): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen.
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = new Student(matNr, name, geburtstag, adresse);

                    studentenListe.pushBack(student);
                }
                break;

            // Datenelement vorne entfernen.
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.dataFront();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                        studentenListe.popFront();
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben.
            case '3':
				{
					if(!studentenListe.empty())
					{
						std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
						studentenListe.ausgabeVorwaerts();
					}
					else
					{
						std::cout << "Die Liste ist leer!\n\n";
					}
				}
				break;

            // Datenbank rueckwaerts ausgeben.
            case '4':
				{
					if(!studentenListe.empty())
					{
						std::cout << "Inhalt der Liste in absteigender Reihenfolge:" << std::endl;
						studentenListe.ausgabeRueckwaerts();
					}
					else
					{
						std::cout << "Die Liste ist leer!\n\n";
					}
				}
				break;

            // Spezielle Matrikelnummer aus der Datenbank loeschen.
            case '5':
				{
					if(!studentenListe.empty())
					{
						unsigned int helper = 0;
						std::cout << "Inhalt der Liste: " << std::endl;
						studentenListe.ausgabeVorwaerts();
						std::cout << "Eingabe der zu löschenden Matrikelnummer: ";
						std::cin >> helper;
						std::cout << "Es wird die folgende Matrikelnummer gelöscht: " << helper << std::endl;
						studentenListe.datenElementLoeschen(helper);
						std::cout << "Vorgang beendet. Neue Liste ist: " << std::endl;
						studentenListe.ausgabeVorwaerts();
					}
					else
					{
						std::cout << "Die Liste ist leer!\n\n";
					}
				}
				break;

			// Datenelement vorne einfuegen.
            case '6':
            	{
					unsigned int matNr = 0;
					std::string name = "";
					std::string geburtstag = "";
					std::string adresse = "";

					std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
					getline(std::cin, name);    // ganze Zeile einselen inklusive aller Leerzeichen

					std::cout << "Geburtsdatum: ";
					getline(std::cin, geburtstag);

					std::cout << "Adresse: ";
					getline(std::cin, adresse);

					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;
					std::cin.ignore(10, '\n');

					Student student(matNr, name, geburtstag, adresse);
					studentenListe.pushFront(student);

            	}
				break;

			// Programm beenden
            case '8':
                std::cout << "Das Programm wird nun beendet";
                break;

            // Falsche Eingabe erfassen.
            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '8');

    return 0;
}
