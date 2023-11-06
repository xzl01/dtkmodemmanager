// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#pragma once

#include "dmodemtypes.h"
#include "dtkmodem_global.h"

#include <QObject>
#include <DExpected>

DMODEM_BEGIN_NAMESPACE

class DModemSimPrivate;

using DCORE_NAMESPACE::DExpected;

class DModemSim : public QObject
{
    Q_OBJECT
public:
    explicit DModemSim(QObject *parent = nullptr);
    virtual ~DModemSim() ;
    //properties:
    Q_PROPERTY(QByteArray gid1 READ gid1);
    Q_PROPERTY(QByteArray gid2 READ gid2);
    Q_PROPERTY(QList<QString> emergencyNumbers READ emergencyNumbers);
    Q_PROPERTY(QList<QMap<QString, quint32>> perferredNetworks READ perferredNetworks);
    Q_PROPERTY(bool active READ isActive);
    Q_PROPERTY(QString eid READ eid);
    Q_PROPERTY(QString imsi READ imsi);
    Q_PROPERTY(QString operatorIdentifier READ operatorIdentifier);
    Q_PROPERTY(QString operatorName READ operatorName);
    Q_PROPERTY(QString simIdentifier READ simIdentifier);
    Q_PROPERTY(QString esimStatus READ esimStatus);
    Q_PROPERTY(QString removability READ removability);
    Q_PROPERTY(QString simType READ simType);

    QByteArray gid1() const;
    QByteArray gid2() const;
    QList<QString> emergencyNumbers() const;
    QList<QMap<QString, quint32>> perferredNetworks() const;
    bool isActive() const;
    QString eid() const;
    QString imsi() const;
    QString operatorIdentifier() const;
    QString operatorName() const;
    QString simIdentifier() const;
    QString esimStatus() const;
    QString removability() const;
    QString simType() const;

// Methods:
public slots:
    DExpected<void> changePin(const QString &old_pin, const QString &new_pin);
    DExpected<void> enablePin(const QString &pin);
    DExpected<void> sendPin(const QString &pin);
    DExpected<void> sendPuk(const QString &puk, const QString &pin);
    DExpected<void> setPreferredNetworks(QList<QMap<QString, quint32>> preferred_networks);

    QString version() const;

private:
    QScopedPointer<DModemSimPrivate> d_ptr{nullptr};

};
DMODEM_END_NAMESPACE
