#ifndef DYNARR_H
#define DYNARR_H

using std::cout;
using std::endl;

// implementacja tablicy i interfejsu
template <typename T>
class DynArr {
	int length;
	int capacity;
	float rRatio;
	T* arr;
public:
	DynArr() {
		length = 0;
		capacity = 1;
		rRatio = 2.0;
		arr = new T[capacity];
	}

	~DynArr() {
		delete[] arr;
	}

	int getLength() {
		return length;
	}

	void add(const T&);
	void del();
	T* getByIndex(int);
	bool setByIndex(int, const T&);
	void clearArray();
	void showArray();
	void showArray(int);
};

template <typename T>
void DynArr<T>::add(const T& data) {
	if (length >= capacity) {
		T* tmp = new T[int(capacity * rRatio)]; // alokacja 200%

		for (int i = 0; i < length; i++) { // przepisanie
			tmp[i] = arr[i];
		}

		delete[] arr; // uwolnienie pamieci
		arr = tmp;
		tmp = nullptr;
		capacity *= rRatio;
	}

	arr[length] = data; // dodanie elementu
	length++;
	//cout << "Pomyslnie dodano element" << endl; // TODO: usunac na koniec
};

// dodac metode ktora usuwa ostatni element i zmniejsza rozmiar
template <typename T>
void DynArr<T>::del() {
	if (length > 0) {
		length--; 
	}
	else {
		cout << "Brak elementow w tablicy!" << endl;
	}
};

template <typename T>
T* DynArr<T>::getByIndex(int i) {
	if (i < 0) {
		cout << "Indeks nie moze byc ujemny!" << endl;
		return nullptr;
	}

	if (length > 0) {
		if (i < length) {
			//cout << "Zwracany element o indeksie " << i << ":" << endl << arr[i] << endl;
			return &arr[i];
		}
		else {
			cout << "Indeks #" << i << " jest spoza zakresu!" << endl;
			return nullptr;
		}
		
	}
	else {
		cout << "Brak elementow w tablicy!" << endl;
		return nullptr;
	}
};

template <typename T>
bool DynArr<T>::setByIndex(int i, const T& newData) {
	if (i < 0) {
		cout << "Indeks nie moze byc ujemny!" << endl;
		return nullptr;
	}

	if (length > 0) {
		if (i < length) {
			arr[i] = newData;
			return true;
		}
		else {
			cout << "Indeks #" << i << " jest spoza zakresu!" << endl;
			return false;
		}
	}
	else {
		cout << "Brak elementow w tablicy!" << endl;
		return false;
	}
};

template <typename T>
void DynArr<T>::clearArray() {
	if (length > 0) {
		length = 0;
		cout << "Pomyslnie wyczyszczono tablice!" << endl << endl;
	}
	else {
		cout << "Brak elementow w tablicy!" << endl;
	}
}

template <typename T>
void DynArr<T>::showArray() {
	if (length > 0) {
		cout << "Rozmiar tablicy: " << length << endl;
		cout << "Maksymalny rozmiar tablicy: " << capacity << endl;
		cout << "Adres tablicy: " << this << endl << endl;
		cout << "Zawartosc tablicy:" << endl;

		for (int i = 0; i < length; i++) {
			cout << "Element #" << i << ":" << endl;
			cout << arr[i] << endl;
		}
	}
	else {
		cout << "Brak elementow w tablicy!" << endl;
		cout << "Maksymalny rozmiar tablicy: " << capacity << endl;
		cout << "Adres tablicy: " << this << endl << endl;
	}
};

template <typename T>
void DynArr<T>::showArray(int numEl) {
	if (length > 0) {
		cout << "Rozmiar tablicy: " << length << endl;
		cout << "Maksymalny rozmiar tablicy: " << capacity << endl;
		cout << "Adres tablicy: " << this << endl << endl;
		cout << "Zawartosc tablicy:" << endl;

		int k = 0;
		if (numEl < length) {
			k = numEl;
		}
		else {
			k = length;
		}

		for (int i = 0; i < k; i++) {
			cout << "Element #" << i << ":" << endl;
			cout << arr[i] << endl;
		}
	}
	else {
		cout << "Brak elementow w tablicy!" << endl;
		cout << "Maksymalny rozmiar tablicy: " << capacity << endl;
		cout << "Adres tablicy: " << this << endl << endl;
	}
};

#endif
