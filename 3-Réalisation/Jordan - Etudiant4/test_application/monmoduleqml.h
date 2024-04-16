// monmoduleqml.h
#ifndef MONMODULEQML_H
#define MONMODULEQML_H

#include <QObject>

class MonModuleQML : public QObject
{
    Q_OBJECT

public:
    explicit MonModuleQML(QObject *parent = nullptr);

public:
    void ajouterJoueurCpp(const QString &password, const QString &email, const QString &identifiant);
    void recupererDonneesJoueurs(const QString &password, const QString &identifiant);
};

#endif
