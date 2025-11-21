
using namespace std;
class Data {
private:
    int giorno;
    int mese;
    int anno;

public:
    Data(int g = 1, int m = 1, int a = 1900)
        : giorno(g), mese(m), anno(a) {}

    int getGiorno() const { return giorno; }
    int getMese() const { return mese; }
    int getAnno() const { return anno; }

    void setGiorno(int g) { giorno = g; }
    void setMese(int m) { mese = m; }
    void setAnno(int a) { anno = a; }

    void setData(int g, int m, int a) {
        giorno = g;
        mese = m;
        anno = a;
    }
};
