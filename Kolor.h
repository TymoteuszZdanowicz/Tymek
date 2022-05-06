#pragma once
class Kolor {
private:
	kolory jaki_kolor;

public:
	Kolor(kolory _jaki_kolor);
	~Kolor();

	void ustaw(kolory _jaki_kolor);
	kolory odczytaj();
};

enum class kolory{bialy, czarny, czerwony, zielony };