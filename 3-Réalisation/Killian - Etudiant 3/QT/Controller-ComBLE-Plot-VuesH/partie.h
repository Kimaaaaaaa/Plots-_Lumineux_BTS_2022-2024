#ifndef PARTIE_H
#define PARTIE_H

#include <QObject>
#include <plot.h>


class Partie : public QObject
{
    Q_OBJECT
public:
    explicit Partie(int tempsPourAppuyer = 5, int nbCoup = 10, QString couleurJ1 = "red", QString couleurJ2 =nullptr, QObject *parent = nullptr);

    int getTourCourant() const;
    void setTourCourant(int newTourCourant);

private:
    QString couleurJ1; //par défaut 1
    QString couleurJ2;
    int  tempsPourAppuyer; //en secondes
    int nbCoup;
    QList<Plot*> listePlotPartie;
    int tourCourant;
signals:

};

#endif // PARTIE_H
