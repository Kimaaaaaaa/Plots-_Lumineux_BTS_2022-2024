#ifndef JOUEUR_H
#define JOUEUR_H

#include <QObject>
#include <QString>

class Joueur : public QObject
{
    Q_OBJECT
public:

    Joueur(const QString &identifiant="",const int id=0, const QString email="", const QString &password="");

    QString getIdentifiant()const;
    QString getPassword()const;

    QString identifiant() const;

    int score() const;
    void setScore(int score);

    int getId() const;

private:
    QString m_identifiant;
    int m_id;
    QString m_email;
     QString m_password;

};

#endif // JOUEUR_H
