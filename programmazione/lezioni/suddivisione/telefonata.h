#ifndef TELEFONATA_H
#define TELEFONATA_H

class Telefonata(){
	Orario inizio, fine;
	unsigned numeroChiamato;
	public:
		Telefonata()=default;  
		Telefonata(const Orario &, const Orario & unsigned);
		unsigned durata() const;
};
