#ifndef PARTIE_H
#define PARTIE_H

#include <QObject>
#include <plot.h>


class Partie : public QObject
{
    Q_OBJECT
public:
    explicit Partie(int nbJoueur = 1, int tempsPourAppuyer = 5, QObject *parent = nullptr);

private:
    int nbJoueur; //par défaut 1
    int  tempsPourAppuyer; //en secondes
    QList<Plot*> listePlotPartie;
signals:

};

#endif // PARTIE_H
