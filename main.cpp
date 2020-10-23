#include <iostream>
#include <time.h>
#include "dynarr.h"

using std::cout;
using std::endl;
using std::ostream;

struct data {
	int num;
	char c;
};

ostream& operator<<(ostream& out, const data& n) {
	out << "int: " << n.num << endl << "char: " << n.c << endl;
	return out;
}

ostream& operator<<(ostream& out, data* const& n) {
	out << "int: " << n->num << endl << "char: " << n->c << endl;
	return out;
}

data* generateData() {
	data* d = new data();
	d->num = rand() % 10001; // 0 - 10000
	d->c = rand() % ('z' - 'a' + 1) + 'a'; // a - z
	return d;
}

void testDyn() {
	// tablica
	DynArr<data>* a = new DynArr<data>();

	// struktury do dodania
	data d1;
	d1.num = 12;
	d1.c = 'd';

	data d2;
	d2.num = 999999;
	d2.c = 'k';

	data d3;
	d3.num = 123456789;
	d3.c = 'z';

	// poczatkowy stan
	a->showArray();

	// dodawanie
	a->add(d1);
	a->showArray();

	a->add(d2);
	a->showArray();

	a->add(d3);
	a->showArray();

	a->add(d2);
	a->showArray();

	a->add(d1);
	a->showArray();

	// usuwanie
	a->del();
	a->showArray();

	a->del();
	a->showArray();

	// ponownie dodawania
	a->add(d3);
	a->showArray();

	a->add(d2);
	a->showArray();

	a->add(d1);
	a->showArray();

	a->add(d3);
	a->showArray();

	// ponowne usuwanie
	a->del();
	a->showArray();

	// zwrocenie danych i-tego elementu
	a->getByIndex(20); // poza zakresem
	a->showArray();

	a->getByIndex(3); // w zakresie
	a->showArray();

	// ustawienie danych i-tego elementu
	data n1;
	n1.num = 90;
	n1.c = 'x';

	a->setByIndex(10, n1); // poza zakresem
	a->showArray();

	a->setByIndex(2, n1); // w zakresie
	a->showArray();

	// czyszczenie tablicy
	a->clearArray();
	a->showArray();
}

void testStat() {
	// tablica
	DynArr<data> a;

	// struktury do dodania
	data d1;
	d1.num = 12;
	d1.c = 'd';

	data d2;
	d2.num = 999999;
	d2.c = 'k';

	data d3;
	d3.num = 123456789;
	d3.c = 'z';

	// poczatkowy stan
	a.showArray();

	// dodawanie
	a.add(d1);
	a.showArray();

	a.add(d2);
	a.showArray();

	a.add(d3);
	a.showArray();

	a.add(d2);
	a.showArray();

	a.add(d1);
	a.showArray();

	// usuwanie
	a.del();
	a.showArray();

	a.del();
	a.showArray();

	// ponownie dodawania
	a.add(d3);
	a.showArray();

	a.add(d2);
	a.showArray();

	a.add(d1);
	a.showArray();

	a.add(d3);
	a.showArray();

	// ponowne usuwanie
	a.del();
	a.showArray();

	// zwrocenie danych i-tego elementu
	a.getByIndex(20); // poza zakresem
	a.showArray();

	a.getByIndex(3); // w zakresie
	a.showArray();

	// ustawienie danych i-tego elementu
	data n1;
	n1.num = 90;
	n1.c = 'x';

	a.setByIndex(10, n1); // poza zakresem
	a.showArray();

	a.setByIndex(2, n1); // w zakresie
	a.showArray();

	// czyszczenie tablicy
	a.clearArray();
	a.showArray();
}

void eksperymentDyn() {
	DynArr<data*>* a1 = new DynArr<data*>();

	const int numOfEl = 10000000;
	double worstTimePerEl = 0.0;

	clock_t start = clock();
	for (int i = 0; i < numOfEl; i++) {
		data* d = generateData();
		clock_t startEl = clock();
		a1->add(d);
		clock_t stopEl = clock();
		double timePerEl = double(stopEl - startEl) / (CLOCKS_PER_SEC);
		if (timePerEl > worstTimePerEl) {
			worstTimePerEl = timePerEl;
			printf("Najgorszy zaobserwowany czas operacji dodawania wynosi %.4fs (%.2fms), indeks: %d\n", worstTimePerEl, worstTimePerEl * 1000, i);
		}
	}
	clock_t stop = clock();

	double elapsedTime = double(stop - start) / (CLOCKS_PER_SEC);
	cout << endl;
	a1->showArray(12);
	printf("Calkowity czas dodawania %d elementow wynosi %.4fs\n", numOfEl, elapsedTime);
	printf("Czas zamortyzowany (dla pojedynczej operacji dodawania) wynosi %.8fs (%.6fms)\n", elapsedTime / numOfEl, (elapsedTime / numOfEl) * 1000);

	for (int i = 0; i < a1->getLength(); i++) {
		delete *a1->getByIndex(i);
	}

	a1->clearArray();
	delete a1;
}

void eksperymentStat() {
	DynArr<data*> a1;

	const int numOfEl = 10000000;
	double worstTimePerEl = 0.0;

	clock_t start = clock();
	for (int i = 0; i < numOfEl; i++) {
		data* d = generateData();
		clock_t startEl = clock();
		a1.add(d);
		clock_t stopEl = clock();
		double timePerEl = double(stopEl - startEl) / (CLOCKS_PER_SEC);
		if (timePerEl > worstTimePerEl) {
			worstTimePerEl = timePerEl;
			printf("Najgorszy zaobserwowany czas operacji dodawania wynosi %.4fs (%.2fms), indeks: %d\n", worstTimePerEl, worstTimePerEl * 1000, i);
		}
	}
	clock_t stop = clock();

	double elapsedTime = double(stop - start) / (CLOCKS_PER_SEC);
	cout << endl;
	a1.showArray(12);
	printf("Calkowity czas dodawania %d elementow wynosi %.4fs\n", numOfEl, elapsedTime);
	printf("Czas zamortyzowany (dla pojedynczej operacji dodawania) wynosi %.8fs (%.6fms)\n", elapsedTime / numOfEl, (elapsedTime / numOfEl) * 1000);

	for (int i = 0; i < a1.getLength(); i++) {
		delete *a1.getByIndex(i);
	}

	a1.clearArray();
}

int main() {
	//testDyn();
	//testStat();
	srand(time(NULL));

	eksperymentDyn();
	//eksperymentStat();

	cout << "Nacisnij dowolny klawisz, aby zakonczyc..." << endl;
	getchar();
	return 0;
}