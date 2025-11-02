#ifndef ORARIO_H
#define ORARIO_H
class Orario{
        private:
		unsigned ore, minuti, secondi;

	public:
		Orario(unsigned o=0, unsigned m=0, unsigned s=0) : ore(o), minuti(m), secondi(s){
		unsigned convertiInSecondi() const;
	}

	friend ostream& operator << (ostream&, const Orario&); // non è della classe, ma le do i privilegi di accesso alla classe

};


#endif 
