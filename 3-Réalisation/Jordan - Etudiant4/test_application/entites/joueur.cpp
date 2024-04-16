#include "joueur.h"

Joueur:: Joueur(const QString &identifiant,const int id, const QString email, const QString &password):
    m_identifiant(identifiant),
    m_id(id),
    m_email(email),
  m_password(password)
{
}

QString Joueur::getIdentifiant() const
{
    return m_identifiant;
}

QString Joueur::getPassword() const
{
    return m_password;
}
