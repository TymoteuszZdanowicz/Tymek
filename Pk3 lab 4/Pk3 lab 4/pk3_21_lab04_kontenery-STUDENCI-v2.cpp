// pk3_21_lab04_kontenery.cpp : 
// Autor: dr inż. Jolanta Kawulok
// ver 2

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>
#include <deque>
#include <forward_list>
#include <chrono>       // std::chrono::system_clock
#include <ctime>

#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>

////


using namespace std;

int main()
{
	/* Mierzenie czasu na podstawie
	https://bulldogjob.pl/news/1474-jak-mierzyc-czas-wykonania-programu-w-c-c  	*/

	int Uruchomzad = 4; // nr zad 1-4 do uruchomienia


		// OPIS DOSTEPNYCH KONTENEROW:
		// https://en.cppreference.com/w/cpp/container
		// https://www.cplusplus.com/reference/stl/
		
	if (Uruchomzad == 1) {
		/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		 ++++++++++++++++++++ zad 1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		++++++++	Porówywanie czasu wstawiania do kontenerów oraz dostepu do danych	++++++++++++++++++++++
		+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

		int poj = 1000;
		int a = 800, b = 900; // dane do spr zawartosci kontenerow
		//int a = 8, b = 9; // prosze spr dla dwoch zestawów



		/* W ćwiczeniu będziemy tworzyć tablicę wielkości poj x poj, zawierającą tabliczkę mnożenia.
		W tym celu należy wykorzystać 4 rodzaje kontnerów:
		a) wektor wektorow typu int
		b) deque deque typu int
		c) liste list typu int
		d) forward_list  forward_list   typu int    */


		/* 1.1 Proszę zmierzyc czas tworzenia wyzej wymienionych obiektow.
		a) Czy jest roznica w czasie tworzenia kontenra,
		jesli dla vector i deque bedziemy wykorzystywac push_back,
		a jesli z góry ustaloną wartość ? */




		/* ===============================================================================================
		===========================  vector =============================================================
		=================================================================================================== */
		auto begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie wektora\n";

		vector<vector<int>> wektor(poj, vector<int>(poj));

		for (int i = 0; i < poj; i++) {
			for (int j = 0; j < 1000; j++) {
				wektor[i][j] = i * j;
			}
		}


		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do wektora: %.3f s.\n", elapsed.count() * 1e-9);



		/* ================================================================================================
		===========================  DEQUE ================================================================
		=================================================================================================== */
		begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie deque\n";

		deque<deque<int>> kolejka(poj, deque<int>(poj));

		for (int i = 0; i < poj; i++) {
			for (int j = 0; j < poj; j++) {
				kolejka[i][j] = i * j;
			}
		}


		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do deque: %.3f s.\n", elapsed.count() * 1e-9);


		/*   ================================================================================================
			===========================  list ================================================================
			================================================================================================= */
		begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie LIST\n";

		list<list<int>> lista;
		list<int> tempLista(poj);

		for (int i = 0; i < poj; i++) {
			for (int j = 0; j < poj; j++) {
				tempLista.push_back(i * j);
			}
			lista.push_back(tempLista);
			tempLista.clear();
		}


		// Stop measuring time and calculate the elapsed time
		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do list: %.3f s.\n", elapsed.count() * 1e-9);






		/*   ==============================================================================================
		===========================  forward_list =========================================================
		==================================================================================================== */
		begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie forward_list\n";
		
		forward_list<forward_list<int>> forwardLista(poj, forward_list<int>(poj));

		for (int i = poj - 1; i >= 0; i--) {
			forward_list<int> forwardListaTemp;
			for (int j = poj - 1; j >= 0; j--) {
				forwardListaTemp.push_front(i * j);
			}
			forwardLista.push_front(forwardListaTemp);
			forwardListaTemp.clear();
		}

		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do forward_list: %.3f s.\n", elapsed.count() * 1e-9);



		/*   =============================================================================================
		1.2 Proszę odczytac wartosci z tabeli dla par a i b (czyli wynikiem jest a*b)
		Dla list i forward_list prosze dodatkowo zmierzyc czas.
		Proszę zwrócić uwagę na różnice czasowe przy wykorzystaniu innych wartości a i b
		(zdefiniowanych na początku zad 1).
		 ================================================================================================= */
		cout << "\n\n\tOdczyt z kontenerow: \n";
		cout << "\nVEC: " << wektor[a][b];
		cout << "\nDEQ: " << kolejka[a][b];


		/*   ============================================================================================
		===========================  list ===============================================================
		==============================================================================================*/
		begin = std::chrono::high_resolution_clock::now();

		//int wartość;
		//for (int i = 0; i <= a; i++) {
		//	if (i == a) {
		//		list<int> temp = lista.front();
		//		for (int j = 0; j <= b; j++) {
		//			if (j == b) {
		//				wartość = temp.front();
		//			}
		//			temp.pop_front(); // usuwanie pierwszej wartości
		//		}
		//	}
		//	lista.pop_back();
		//}

		auto tempA = lista.begin();
		advance(tempA, a);
		auto tempB = *tempA;
		auto wartość = tempB.begin();
		advance(wartość, b);

		cout << "\nlist: " << *wartość;

		// Stop measuring time and calculate the elapsed time
		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("\nCzas odczytu z list: %.3f s.\n", elapsed.count() * 1e-9);


		/*   ============================================================================================
		===========================  forward_list =======================================================
		=============================================================================================== */
		begin = std::chrono::high_resolution_clock::now();

		auto tempA_F = forwardLista.begin();
		advance(tempA_F, a);
		auto tempB_F = *tempA_F;
		auto wartość_F = tempB_F.begin();
		advance(wartość_F, b);

		cout << "\nforward: " << *wartość_F;
		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("\nCzas odczytu z forward_list: %.3f s.\n", elapsed.count() * 1e-9);


	}




	if (Uruchomzad == 2) {
		/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			++++++++++++++++++++ zad 2 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			++++++++++++++++++++++++++++++++ ADAPTORY ++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

			/* Prosze stworzyc 3 rodzaje adaptorów typu int:
			stack, queue, priority_queue
			do których prosze dodawac pokolei dane z myvec
			(dla priority_queue definicja prorytetu nie ma znaczenia).
			A następnie prosze wyswietlic zawartosci tych obiektów      */


		vector<int> myvec = { 1 ,10 ,2 ,20, 3, 30 };
		stack<int> stos;
		for (int i = myvec.size()-1; i >= 0; i--) {
			stos.push(myvec[i]);
		}
		/*for (int i : myvec) {
			stos.push(i);
		}*/

		queue<int> kolejka1;
		for (int i = 0; i < myvec.size(); i++) {
			kolejka1.push(myvec[i]);
		}

		priority_queue<int> kolejka2;
		for (int i = 0; i < myvec.size(); i++) {
			kolejka2.push(myvec[i]);
		}

		cout << "Wyswietlanie stosu \n";

		for (int i = 0; i < myvec.size(); i++) {
			cout << stos.top() << " ";
			stos.pop();
		}

		cout << "\n Wyswietlanie kolejki \n";

		for (int i = 0; i < myvec.size(); i++) {
			cout << kolejka1.front() << " ";
			kolejka1.pop();
		}

		cout << "\n Wyswietlanie kolejki priorytetowej \n";

		for (int i = 0; i < myvec.size(); i++) {
			cout << kolejka2.top() << " ";
			kolejka2.pop();
		}
	}






	if (Uruchomzad == 3) {
		/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		 ++++++++++++++++++++ zad 3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++++++ Kontenery asocjacyjne  ++++++++++++++++++++++++++++++++++++++++ */

		vector<int> vec3 = { 1,2,3,4,5,5,4,3,2,1,0,10,11,12,13,14,15,-1,-2,-3,-4,-5,15,14,13,12,11,10 };

		/* zad 3.1 Proszę stworzyc obiekt typu set, multiset, map oraz multimap typu int,
		a następnie (dla dwóch pierwszych) dodać do nich zawartość wektora vec3.
		Dla map proszę wstawiać rowniez zawartość wektora, przy czym kluczem niech będzie wartość
		bewzględna danego elmentu (mozna wykorzystać abs i pair).
		Dodawanie do 4 kontenetow można wykonac w 1 pętli.		*/

		set<int> Set;
		multiset<int> multiSet;
		map<int, int> Map;
		multimap<int, int> multiMap;

		for (int i = 0; i < vec3.size(); i++) {
			Set.insert(vec3[i]);
			multiSet.insert(vec3[i]);
			/*pair<int, int> para;
			para.first = abs(vec3[i]);
			para.second = vec3[i];*/
			Map.insert({ abs(vec3[i]), vec3[i] });
			multiMap.insert({ abs(vec3[i]), vec3[i] });
		}



		/* Nastepnie proszę wyswietlic zawartosc tych 4 obiektow.*/

		cout << "\nZAWARTOSC set\n";
		for (int i : Set) {
			cout << i << " ";
		}

		cout << "\n\nZAWARTOSC multiset\n";
		for (int i : multiSet) {
			cout << i << " ";
		}

		cout << "\n\nZAWARTOSC map\n";
		for (auto i : Map) {
			cout << i.first << ": " << i.second << ", ";
		}

		cout << "\n\nZAWARTOSC multimap\n";
		for (auto i : multiMap) {
			cout << i.first << ": " << i.second << ", ";
		}




		/* =====================================================================
		===================== zad 3.1 ==========================================
		Dla MULTIMAP proszę usunąć WSZYSTKIE elementy gdzie klucz wynosi 2     */

		multiMap.erase(2);

		cout << "\n\nZAD 3.1 multimap po usunieciu 2\n";
		for (auto i : multiMap) {
			cout << i.first << ": " << i.second << ", ";
		}



		/* =====================================================================
		===================== zad 3.2 ==========================================
			 Proszę swtorzyć inną zwykłą mapę (nie multi),
			 a następnie przepisać z wyzej stworzonej multimapy zawartość tak, aby:
			 klucze były niemniejsze niż 10 oraz
			 klucze byly mniejsze od 14.
			 Wykorzystaj do samego przepisania TYLKO 1 linię kodu
			 (BEZ PETLI).
			 
			 Natępnie prosze wyswietlic tę nową mapę. */

		map<int, int> Map2;
		map<int, int>::iterator początek, koniec;
		początek = multiMap.lower_bound(10);
		koniec = multiMap.upper_bound(13);

		Map2.insert(początek, koniec);

		cout << "\n\nZAD 3.2 Nowa mapa na podstawie multimapy \n";
		for (auto i : Map2) {
			cout << i.first << ": " << i.second << ", ";
		}
	}


	if (Uruchomzad == 4) {
		/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		 ++++++++++++++++++++ zad 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++++++ unordered_map  +++++++++++++++++++++++++++++++++++++++++++++++ */

		/* Stworz unordered_map<string, string>, a nastepnie wstaw do niego dowolne pary wyrazow.
		Nastepnie sprawdz, co pod dwoma wybranymi kluczami sie znajduje.
		Niech jeden z kluczy rzeczywiscie znajduje sie w bazie
		(wtedy prosze wyswietlic ten element),
		a niech drugiego klucza nie ma
		(wtedy prosze wyswietlic informacje, ze nie znaleziono danego klucza w mapie). */

		unordered_map<string, string> mapaSłów;

		pair<string, string> para1 = { "Polska", "Francja" };
		pair<string, string> para2 = { "Japonia", "Chorwacja" };
		pair<string, string> para3 = { "Korea", "Brazylia" };

		mapaSłów.insert(para1);
		mapaSłów.insert(para2);
		mapaSłów.insert(para3);

		try {
			cout << mapaSłów.at("Polska") << endl;
			cout << mapaSłów.at("Japonia") << endl;
			cout << mapaSłów.at("Belgia") << endl;
		}
		catch (exception) {
			cout << "Nie ma klucza" << endl;
		}
	}

}


