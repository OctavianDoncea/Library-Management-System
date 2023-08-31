#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <list>
#include <set>
#include <map>
#include <iterator>
#include <fstream>
#include <iomanip>

using namespace std;

class Taxe
{
public:
    virtual float Impozit() = 0;
    virtual int ani() = 0;
};

class Firma
{
protected:
    string numeFirma;
public:
    void afisareFirma()
    {
        cout << "Bine ai venit la firma ";
        cin >> numeFirma;
        cout << endl;
    }

    virtual int aniDefunctionare() = 0;

    friend ostream& operator<<(ostream& out, const Firma& f)
    {
        out << f.numeFirma;
        return out;
    }
};

class Angajat {
protected:
    const int id;
    bool concediu;
    char* nume;
    char dataAngajarii[100];
    float salariuNet;
    int* ore;
    double salariuBrut;
    static int TVA;
    static int nrAngajati;

public:
    Angajat(const int id):id(id)
    {
        this->nume = new char[strlen("Anonim") + 1];
        strcpy(this->nume, "Anonim");
        this->concediu = 0;
        strcpy(this->dataAngajarii, "1.01.2018");
        this->salariuNet = 0;
        this->salariuBrut = salariuNet * Angajat::TVA;
        this->ore = new int[8];
        for(int i = 0; i < 8; i++)
        {
            ore[i] = 0;
        }
    }

    Angajat(const int ID, char* Nume):id(ID), nume(Nume)
    {
        this->concediu = 0;
        strcpy(this->dataAngajarii, "1.01.2018");
        this->salariuNet = 0;
        this->salariuBrut = salariuNet * Angajat::TVA;
        this->ore = new int[8];
        for(int i = 0; i < 8; i++)
        {
            ore[i] = 0;
        }
    }

    Angajat():id(Angajat::nrAngajati++)
    {
        this->concediu = 0;
        this->nume = new char[strlen("Anonim") + 1];
        strcpy(this->nume, "Anonim");
        strcpy(this->dataAngajarii, "1.01.2018");
        this->salariuNet = 0;
        this->salariuBrut = salariuNet * Angajat::TVA;
        this->ore = new int[8];
        for(int i = 0; i < 8; i++)
        {
            ore[i] = 0;
        }
    }

    Angajat(const Angajat& ang):id(ang.id)
    {
        this->concediu = ang.concediu;
        this->nume = new char[strlen(ang.nume) + 1];
        strcpy(this->nume, ang.nume);
        strcpy(this->dataAngajarii, ang.dataAngajarii);
        this->salariuNet = ang.salariuNet;
        this->salariuBrut = ang.salariuBrut;
        this->ore = new int[8];
        for(int i = 0; i< 8; i++)
        {
            this->ore[i] = ang.ore[i];
        }
    }

    ~Angajat()
    {
        if(this->nume != nullptr)
        {
            delete[] this->nume;
        }

        if(this->ore != nullptr)
        {
            delete[] this->ore;
        }
    }


    friend istream& operator>>(istream& in, Angajat& ang) {
        char* nume = new char(30);
        float salariuNet;
        if (&in == &cin)
        {
            // de la tastatura
            cout << "Nume: ";
            in >> nume;
            cout << "Salariu net: ";
            in >> salariuNet;

            ang.setNume(nume);
            ang.setSalariuNet(salariuNet);
        }
        else
        {
            // de la fisier
            in >> nume;
            in >> salariuNet;

            ang.setNume(nume);
            ang.setSalariuNet(salariuNet);
        }

        return in;
    }

    friend ostream& operator<<(ostream& out, const Angajat& ang)
    {
        out << "Angajat ->\t";
        out << "ID: " << ang.id << "\t";
        out << "Nume: " << ang.nume << endl;

        return out;
    }

    const int getId()
    {
        return this->id;
    }

    bool getConcediu()
    {
        return this->concediu;
    }

    char* getNume() const
    {
        return this->nume;
    }

    char* getDataAngajarii()
    {
        return this->dataAngajarii;
    }

    float getSalariuNet()
    {
        return this->salariuNet;
    }

    int* getOre()
    {
        return this->ore;
    }

    double getSalariuBrut()
    {
        return this->salariuBrut;
    }

    int getTVA()
    {
        return Angajat::TVA;
    }

    int getNrAngajati()
    {
        return Angajat::nrAngajati;
    }


    void setConcediu(bool concediu)
    {
        this->concediu = concediu;
    }

    void setNume(char* nume)
    {
        this->nume = nume;
    }

    void setDataAngajarii(char dataAngajarii[100])
    {
        strcpy(this->dataAngajarii, dataAngajarii);
    }

    void setSalariuNet(float salariuNet)
    {
        this->salariuNet = salariuNet;
    }

    void setOre(int* ore)
    {
        this->ore = ore;
    }

    void setSalariuBrut(double salariuBrut)
    {
        this->salariuBrut = salariuBrut;
    }

    void setTVA(int TVA)
    {
        Angajat::TVA = TVA;
    }

    void setNrAngajati(int nrAngajati)
    {
        this->nrAngajati = nrAngajati;
    }

    Angajat& operator =(const Angajat& ang)
    {
        if(this != &ang)
        {
            this->concediu = ang.concediu;

            if(this->nume != 0)
                delete[] this->nume;

            this->nume = new char[strlen(ang.nume) + 1];
            strcpy(this->nume, ang.nume);

            strcpy(this->dataAngajarii, ang.dataAngajarii);
            this->salariuNet = ang.salariuNet;
            this->salariuBrut = ang.salariuBrut;

            if(this->ore != NULL)
                delete[] this->ore;

            for(int i = 0; i < 8; i++)
            {
                this->ore[i] = ang.ore[i];
            }

        }
        return *this;
    }

    float operator [](int index)
    {
        if(index < 8 && index > 0)
            return this->ore[index];
        else {cout << "Index invalid\n";
                return -1;}
    }

    Angajat operator *(int TVA)
    {
        Angajat::TVA = TVA;
        this->salariuBrut = this->salariuNet * Angajat::TVA;
        return *this;
    }

    Angajat operator /(int TVA)
    {
        Angajat::TVA = TVA;
        this->salariuNet = this->salariuBrut / Angajat::TVA;
        return *this;
    }


};

class Curier:public Angajat
{
protected:
    float km;

public:
    Curier():Angajat()
    {
        this->km = km;
    }

    Curier(int km):Angajat()
    {
        this->km = km;
    }

    Curier(Angajat ang, int km):Angajat(ang)
    {
        this->km = km;
    }

    Curier(const Curier& l):Angajat(l)
    {
        this->km = l.km;
    }

    Curier& operator=(const Curier& l)
    {
        if(this!=&l)
        {
            Angajat::operator=(l);
            this->km = l.km;
        }
        return *this;
    }

    virtual ostream& operator<<(ostream& out) const
    {
        out << " ";
        return out;
    }

    friend istream& operator>>(istream& in, Curier& l)
    {
        in >> (Angajat&)l;
        cout << "Introduceti numarul de km fata de adresa: ";
        in >> l.km;
        if(l.km < 1)
        {
            cout << endl << "Curierul se va deplasa fara masina." << endl;
        }
        else
            cout << endl << "Curierul se va deplasa cu masina." << endl;
        }
};

class Carte
{
    bool inStoc;
    char litera;
    char* gen;
    char nume[100];
    float reducere;
    double pret;
    char numeAutor[100];
    int* nrExemplare;
    int nrExmp;
    const int Id;
    static int nrCarti;

public:

    Carte(const int Id):Id(Id)
    {
        this->inStoc = 0;
        this->litera = 'O';

        this->gen = new char[strlen(gen) + 1];
        strcpy(this->gen, "Anonim");

        strcpy(this->nume, "Anonim");
        this->reducere = 0;
        this->pret = 0;
        strcpy(this->numeAutor, "Anonim");
        this->nrExemplare = new int[50];
        for(int i = 0; i < 50; i++)
        {
            nrExemplare[i] = 0;
        }
    }

    Carte(const int ID, bool inStoc, char litera, char* gen, char nume[100], float reducere, double pret, char numeAutor[100]):Id(ID)
    {
        this->inStoc = inStoc;
        this->litera = litera;

        this->gen = new char[strlen(gen) + 1];
        strcpy(this->gen, gen);

        strcpy(this->nume, nume);
        this->reducere = reducere;
        this->pret = pret;
        strcpy(this->numeAutor, numeAutor);
        this->nrExemplare = new int[50];
        for(int i = 0; i < 50; i++)
        {
            nrExemplare[i] = 0;
        }
    }

    Carte():Id(Carte::nrCarti++)
    {
        this->inStoc = 0;
        this->litera = 'A';

        this->gen = new char[strlen("Anonim") + 1];
        strcpy(this->gen, "Anonim");

        strcpy(this->nume, "Anonim");
        this->reducere = 0;
        this->pret = 0.00;

        strcpy(this->numeAutor, "Anonim");
        this->nrExemplare = new int[50];
        for(int i = 0; i < 50; i++)
        {
            nrExemplare[i] = 0;
        }
    }

    ~Carte()
    {
        if(this->gen != NULL)
        {
            delete[] gen;
        }

        if(this->nrExemplare != NULL)
        {
            delete[] nrExemplare;
        }
    }

    Carte(const Carte& crt):Id(crt.Id)
    {
        this->inStoc = crt.inStoc;
        this->litera = crt.litera;

        this->gen = new char[strlen(crt.gen) + 1];
        strcpy(this->gen, crt.gen);

        strcpy(this->nume, crt.nume);
        this->reducere = crt.reducere;
        this->pret = crt.pret;
        strcpy(this->numeAutor, crt.numeAutor);
        this->nrExemplare = new int[50];
        this->nrExmp = crt.nrExmp;
        for(int i = 0; i < 50; i++)
        {
            this->nrExemplare[i] = crt.nrExemplare[i];
        }
    }

    friend istream& operator>>(istream& in, Carte& crt)
    {
        char* nume = new char(30);
        char litera;
        char* gen = new char(20);
        float reducere;
        double pret;
        char numeAutor[100];
        int nrExmp;
        int* nrExemplare = new int(sizeof(int));
        if (&in == &cin)
        {
            // de la tastatura
            cout << "Nume: ";
            in >> nume;
            cout << "Gen: ";
            in >> gen;
            cout << "Pret: ";
            in >> pret;
            cout << "Reducere: ";
            in >> reducere;
            cout << "Autor: ";
            in >> numeAutor;
            cout << "Exemplare: ";
            in >> nrExmp;

            crt.setNume(nume);
            crt.setLitera(nume[0]);
            crt.setGen(gen);
            crt.setPret(pret);
            crt.setReducere(reducere);
            crt.setNumeAutor(numeAutor);
            crt.setNrExmp(nrExmp);
        } else
        {
            // de la fisier
            in >> nume;
            in >> gen;
            in >> pret;
            in >> reducere;
            in >> numeAutor;
            in >> nrExmp;

            crt.setNume(nume);
            crt.setLitera(nume[0]);
            crt.setGen(gen);
            crt.setPret(pret);
            crt.setReducere(reducere);
            crt.setNumeAutor(numeAutor);
            crt.setNrExmp(nrExmp);
        }

        return in;
    }

    friend ostream& operator<<(ostream& out, const Carte& crt)
    {
        out << "Carte ->\t";
        out << "ID: " << crt.Id << "\t";
        out << "Nume: " << crt.nume << "\t";
        out << "Numar exemplare: " << crt.nrExmp << endl;

        return out;
    }

    void setInStoc(bool inStoc)
    {
        this->inStoc = inStoc;
    }

    void setLitera(char litera)
    {
        this->litera = litera;
    }

    void setGen(char* gen)
    {
        this->gen = gen;
    }

    void setNume(char nume[100])
    {
        strcpy(this->nume, nume);
    }

    void setReducere(float reducere)
    {
        this->reducere = reducere;
    }

    void setPret(double pret)
    {
        this->pret = pret;
    }

    void setNumeAutor(char numeAutor[100])
    {
        strcpy(this->numeAutor, numeAutor);
    }

    void setNrCarti(int nrCarti)
    {
        this->nrCarti = nrCarti;
    }

    void setNrExemplare(int* nrExemplare)
    {
        this->nrExemplare = nrExemplare;
        if (*this->nrExemplare <= 0) {
            *this->nrExemplare = 0;
            this->inStoc = false;
        } else {
            this->inStoc = true;
        }
    }

    void setNrExmp(int value)
    {
        this->nrExmp = value;
        if (value <= 0)
            this->inStoc = false;
        else
            this->inStoc = true;
    }

    bool getInStoc()
    {
        return this->inStoc;
    }

    char getLitera()
    {
        return this->litera;
    }

    char* getGen()
    {
        return this->gen;
    }

    char* getNume()
    {
        return this->nume;
    }

    float getReducere()
    {
        return this->reducere;
    }

    double getPret()
    {
        return this->pret;
    }

    char* getNumeAutor()
    {
        return this->numeAutor;
    }

    const int getId()
    {
        return this->Id;
    }

    int getNrCarti()
    {
        return Carte::nrCarti;
    }

    int getNrExmp() {
        return nrExmp;
    }

    int* getNrExemplare()
    {
        return this->nrExemplare;
    }

    /*friend ifstream& operator>>(ifstream&, Carte&);
    friend ofstream& operator<<(ofstream&, Carte);

    ifstream& operator>>(ifstream& f, Carte& crt)
    {
        f.open("carti.txt", ios:in|ios::_Nocreate);
        if(f)
        {
            char n[40];
            f >> n;
            crt.setNume(n);
        }
        f.close;
        return f;
    }*/

    Carte& operator =(const Carte& crt)
    {
        if(this != &crt)
        {
            this->inStoc = crt.inStoc;
            this->litera = crt.litera;

            if(this->gen != 0)
                delete[] this->gen;

            this->gen = new char[strlen(crt.gen) + 1];
            strcpy(this->gen, crt.gen);

            strcpy(this->nume, crt.nume);
            this->reducere = crt.reducere;
            this->pret = crt.pret;
            strcpy(this->numeAutor, crt.numeAutor);
            this->nrExmp = crt.nrExmp;
            if(this->nrExemplare != NULL)
                delete[] this->nrExemplare;

            for(int i = 0; i < 50; i++)
            {
                this->nrExemplare[i] = crt.nrExemplare[i];
            }
        }
        return *this;
    }

    float operator [](int index)
    {
        if(index < 50 && index > 0)
            return this->nrExemplare[index];
        else {cout << "Index invalid";
                return -1;}
    }

    const Carte operator ++()
    {
        this->nrCarti++;
        return *this;
    }

    const Carte operator ++(int)
    {
        Carte aux(*this);
        this->nrCarti++;
        return aux;
    }

    Carte operator *(float pretRedus)
    {
        pretRedus = this->pret - (this->pret * this->reducere);
        return *this;
    }

    Carte operator -(float pretRedus)
    {
        pretRedus = this->pret - (this->pret * this->reducere);
        return *this;
    }
};


class Autor
{
    const int id;
    char* nume;
    int nrCarti;
    Carte listaCarti;
    static int nrAutori;

public:

    Autor(const int ID):id(ID)
    {
        this->nume = new char(100);
        strcpy(this->nume, "Anonim");
        this->nrCarti = 0;
    }

    Autor(const int ID, char nume[100], int nrCarti):id(ID)
    {
        this->nume = new char(100);
        strcpy(this->nume, nume);
        this->nrCarti = nrCarti;
    }

    Autor():id(Autor::nrAutori++)
    {
        this->nume = new char(100);
        strcpy(this->nume, "Anonim");
        this->nrCarti = 0;
    }

    ~Autor()
    {
        if(this->nume != NULL)
            delete this->nume;
    }

    Autor(const Autor& aut):id(aut.id)
    {
        strcpy(this->nume, aut.nume);
        this->nrCarti = aut.nrCarti;
    }

    friend istream& operator>>(istream& in, Autor& aut)
    {
        char * nume = new char(30);
        int nrCarti;
        if (&in == &cin)
        {
            // de la tastatura
            cout << "Nume: ";
            in >> nume;
            cout << "Numar carti scrise: ";
            in >> nrCarti;

            aut.setNume(nume);
            aut.setNrCarti(nrCarti);
        } else
        {
            // de la fisier
            in >> nume;
            in >> nrCarti;

            aut.setNume(nume);
            aut.setNrCarti(nrCarti);
        }

        return in;
    }

    friend ostream& operator<<(ostream& out, const Autor& aut)
    {
        out << "Autor ->\t";
        out << "ID: " << aut.id << "\t";
        out << "Nume: " << aut.nume << endl;

        return out;
    }

    void setNume(char nume[100])
    {
        strcpy(this->nume, nume);
    }

    void setNrCarti(int nrCarti)
    {
        this->nrCarti = nrCarti;
    }

    void setListaCarti(Carte listaCarti)
    {
        this->listaCarti = listaCarti;
    }


    const int getId()
    {
        return this->id;
    }

    char* getNume()
    {
        return this->nume;
    }

    int getNrCarti()
    {
        return this->nrCarti;
    }

    Carte getListaCarti()
    {
        return this->listaCarti;
    }


    Autor& operator =(const Autor& aut)
    {
        if(this != &aut)
        {
            strcpy(this->nume, aut.nume);
            this->nrCarti = aut.nrCarti;
        }
        return *this;
    }
};


class Tranzactie
{
protected:
    int nrCartiCurente;
    Carte* cartiCurente;
    char listaCarti[100];
    char* data;
    const int nrComanda;
    static int comenzi;

public:

    Tranzactie(const int NrComanda):nrComanda(NrComanda)
    {
        this->data = new char[strlen(data) + 1];
        strcpy(this->data, data);

        strcpy(this->listaCarti, listaCarti);
    }

    Tranzactie(char listaCarti[100], char* data, const int NrComanda):nrComanda(NrComanda)
    {
        strcpy(this->listaCarti, listaCarti);

        this->data = new char[strlen(data) + 1];
        strcpy(this->data, data);
    }

    Tranzactie():nrComanda(Tranzactie::comenzi++)
    {
        strcpy(this->listaCarti, "");

        this->data = new char[strlen("1.01.2018") + 1];
        strcpy(this->data, "1.01.2018");

    }

    ~Tranzactie()
    {
        if(this->data != NULL)
        {
            delete[] this->data;
        }
    }

    Tranzactie(const Tranzactie& tr):nrComanda(tr.nrComanda)
    {
        strcpy(this->listaCarti, tr.listaCarti);

        this->data = new char[strlen(tr.data) + 1];
        strcpy(this->data, tr.data);
    }

    friend istream& operator>>(istream& in, Tranzactie& tr)
    {
        char* numeCarte = new char(30);
        char* data = new char(100);
        if (&in == &cin)
        {
            // de la tastatura

            cout << "Lista carti:\n" << tr.nrCartiCurente;
            for (int i = 0; i < tr.nrCartiCurente; i++) {
                cout << tr.cartiCurente[i].getNume()<< endl;
        }
            cout << endl;
            cout << "Carte de cumparat: ";
            in >> numeCarte;

            bool ok = false;
            for (int i = 0; i < tr.nrCartiCurente; i++) {
                if (strcmp(tr.cartiCurente[i].getNume(), numeCarte) == 0) {
                    ok = true;
                    if (tr.cartiCurente[i].getInStoc() == true) {
                        tr.cartiCurente[i].setNrExmp(tr.cartiCurente[i].getNrExmp() - 1);
                    }
                }
            }

            if (ok == false)
            {
                cout << "Cartea nu este in stoc";
                char* tmp = new char[200];
                strcpy(tmp, "Tranzactie esuata (cartea nu a fost in stoc)");
                tr.setListaCarti(tmp);
                return in;
            }

            cout << "Data de astazi: ";
            in >> data;

            tr.setListaCarti(numeCarte);
            tr.setData(data);
        } else
        {
            // de la fisier
            in >> numeCarte;
            in >> data;

            tr.setListaCarti(numeCarte);
            tr.setData(data);
        }

        return in;
    }

    friend ostream& operator<<(ostream& out, Tranzactie& tr)
    {
        out << "Tranzactie ->\t";
        out << "ID: " << tr.nrComanda << "\t";
        out << "Nume carte: " << tr.getListaCarti() << endl;

        return out;
    }

    void setListaCarti(char listaCarti[100])
    {
        strcpy(this->listaCarti, listaCarti);
    }

    void setNrCartiCurente(int nr) {
        this->nrCartiCurente = nr;
    }

    void setData(char* data)
    {
        this->data = data;
    }

    void setCartiCurente(Carte * listaCarti) {
        this->cartiCurente = listaCarti;
    }

    char* getListaCarti()
    {
        return this->listaCarti;
    }

    char* getData()
    {
        return this->data;
    }

    const int getNrComanda()
    {
        return this->nrComanda;
    }

    Tranzactie& operator =(const Tranzactie& tr)
    {
        if(this != &tr)
        {
            strcpy(this->listaCarti, tr.listaCarti);

            this->data = new char[strlen(tr.data) + 1];
            strcpy(this->data, tr.data);
        }
        return *this;
    }
};

class ProgramLivrare:public Tranzactie
{
    int oraDeschidere, oraInchidere;
    bool deschis;
public:
    ProgramLivrare():Tranzactie()
    {
        this->oraDeschidere = 8;
        this->oraInchidere = 20;
        this->deschis = 1;
    }

    ProgramLivrare(int oraDeschidere, int oraInchidere, bool deschis):Tranzactie()
    {
        this->oraDeschidere = oraDeschidere;
        this->oraInchidere = oraInchidere;
        this->deschis = deschis;
    }

    ProgramLivrare(Tranzactie tr, int oraDeschidere, int oraInchidere, bool deschis):Tranzactie(tr)
    {
        this->oraDeschidere = oraDeschidere;
        this->oraInchidere = oraInchidere;
        this->deschis = deschis;
    }

    ProgramLivrare(const ProgramLivrare& p):Tranzactie(p)
    {
        this->oraDeschidere = p.oraDeschidere;
        this->oraInchidere = p.oraInchidere;
        this->deschis = p.deschis;
    }

    ProgramLivrare& operator=(const ProgramLivrare& p)
    {
        if(this!=&p)
        {
            Tranzactie::operator=(p);
            this->oraDeschidere = p.oraDeschidere;
            this->oraInchidere = p.oraInchidere;
            this->deschis = p.deschis;
        }
        return *this;
    }

    void afisare()
    {
        cout << "Depozitul este deschis? (Apasati 1-Da, 0-Nu)";
        cin >> deschis;

        if(deschis == 1)
        {
            cout << endl << "Depozitul este deschis pana la ora " << oraDeschidere << endl;
        }
        else
        {
            cout << endl << "Depozitul este inchis, iar livrarile se vor efectua maine dupa ora " << oraInchidere << endl;
        }
    }
};

int Angajat::nrAngajati = 0;
int Tranzactie::comenzi = 0;
int Autor::nrAutori = 0;

int Carte::nrCarti = 0;
int Angajat::TVA = 19;

int main()
{
    int n;
    int nrTranzactii = 0, nrAutori = 0, nrCarti = 0, nrAngajati = 0;
    Tranzactie* listaTranzactii = new Tranzactie[50 * sizeof(Tranzactie)];
    Angajat* listaAngajati = new Angajat[50 * sizeof(Angajat)];
    Carte* listaCarti = new Carte[50 * sizeof(Carte)];
    Autor* listaAutori = new Autor[50 * sizeof(Autor)];
    Curier* listaCurieri = new Curier[50 * sizeof(Curier)];

    bool ignoreNewLine;
    while (1) {
        cout << "*****************************\n";
        cout << "1) Afiseaza toate datele\n";
        cout << "2) Adauga o tranzactie\n";
        cout << "3) Adauga un angajat\n";
        cout << "4) Adauga o carte\n";
        cout << "5) Adauga un autor\n";
        cout << "6) Adauga un curier\n";
        cout << "*****************************\n";
        ignoreNewLine = false;
        cin >> n;

        if (n == 1) {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "Sunt " << nrAngajati << " angajati" << endl;
            for (int i = 0; i < nrAngajati; i++) {
                cout << listaAngajati[i];
            }

            cout << "\nSunt " << nrTranzactii << " tranzactii facute" << endl;
            for (int i = 0; i < nrTranzactii; i++) {
                cout << listaTranzactii[i];
            }

            cout << "\nSunt " << nrAutori << " autori" << endl;
            for (int i = 0; i < nrAutori; i++) {
                cout << listaAutori[i];
            }

            cout << "\nSunt " << nrCarti << " carti" << endl;
            for (int i = 0; i < nrCarti; i++) {
                cout << listaCarti[i];
            }
            ignoreNewLine = true;
        } else if (n == 2) {
            ProgramLivrare p1;
            p1.afisare();
            Tranzactie tmp;
            tmp.setNrCartiCurente(nrCarti);
            tmp.setCartiCurente(listaCarti);
            cin >> tmp;
            listaTranzactii[nrTranzactii++] = tmp;
        } else if (n == 3) {
            Angajat tmp;
            cin >> tmp;
            listaAngajati[nrAngajati++] = tmp;
        } else if (n == 4) {
            Carte tmp;
            cin >> tmp;
            listaCarti[nrCarti++] = tmp;
        } else if (n == 5) {
            Autor tmp;
            cin >> tmp;
            listaAutori[nrAutori++] = tmp;
        } else if (n == 6)
        {
            Curier tmp;
            cin >> tmp;
            listaAngajati[nrAngajati++] = tmp;
        }


        if (!ignoreNewLine)
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }

    return 0;
}
