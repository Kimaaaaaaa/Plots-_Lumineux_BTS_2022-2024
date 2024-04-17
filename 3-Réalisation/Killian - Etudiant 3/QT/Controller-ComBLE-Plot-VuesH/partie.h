#ifndef PARTIE_H
#define PARTIE_H

#include <QObject>
#include <plot.h>

class Partie : public QObject
{
    Q_OBJECT
public:
    explicit Partie(int tempsPourAppuyer = 5, int nbCoup = 10, QString couleurJ1 = "red", QString couleurJ2 = nullptr, QObject *parent = nullptr);

    int getTourCourant() const;
    void setTourCourant(int newTourCourant);

    bool getIsLaunched() const;
    void setIsLaunched(bool newIsLaunched);

    const QString &getCouleurJ1() const;
    const QString &getCouleurJ2() const;
    int getTempsPourAppuyer() const;
    int getNbCoup() const;
    const QList<Plot *> &getListePlotPartie() const;

    int getPlotTouche() const;
    void setPlotTouche(int newPlotTouche);

    bool getIsColorRandom() const;
    void setIsColorRandom(bool newIsColorRandom);

    void setCouleurJ1(const QString &newCouleurJ1);
    void setCouleurJ2(const QString &newCouleurJ2);

    int getRandomIndex() const;
    void setRandomIndex(int newRandomIndex);

    void addListeDeTempsDeReactionJ1(unsigned int newTempsDeReaction);

private:
    QString couleurJ1; // par défaut "red"
    QString couleurJ2;
    int tempsPourAppuyer; // en secondes
    int nbCoup;
    QList<Plot *> listePlotPartie;
    int tourCourant;
    bool isLaunched;
    bool isColorRandom;
    int plotTouche;
    int randomIndex;
    QList<unsigned int> listeDeTempsDeReactionJ1; // Utilisation de unsigned int au lieu de unsigned int*
    QList<unsigned int> listeDeTempsDeReactionJ2; // Utilisation de unsigned int au lieu de unsigned int*

signals:
    void isLaunchedChanged(bool);

public slots:

};

#endif // PARTIE_H
