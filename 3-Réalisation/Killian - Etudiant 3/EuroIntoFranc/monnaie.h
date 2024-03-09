#ifndef MONNAIE_H
#define MONNAIE_H

#include <QObject>

class monnaie : public QObject
{
    Q_OBJECT
public:
    explicit monnaie(QObject *parent = nullptr, double valeur = 0, double tauxEuro=1);
    /*Getters*/
    double getValeur();
    double getTauxEuro();
    /*Setters*/
    void setValeur(double);
    void setTauxEuro(double);

private:
    double valeur;
    double tauxEuro;

signals:
};

#endif // MONNAIE_H
