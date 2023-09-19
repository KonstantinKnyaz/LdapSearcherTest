#ifndef LDAPSEARCHERLITE_H
#define LDAPSEARCHERLITE_H

#include <QObject>
#include <QString>

#include <ldap.h>
#include <lber.h>

class LdapSearcherLite : public QObject
{
    Q_OBJECT
public:
    LdapSearcherLite(QObject *parent = nullptr);

    int LDInit(QString url);

    int LDBind(QString dn, QString password);

    int LDMailSearch(QString mail);

    int LDClose();

signals:
    void searchFinish(QString searchResult);

private:
    LDAP *ld = Q_NULLPTR;
};

#endif // LDAPSEARCHERLITE_H
