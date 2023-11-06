

// SPDX-FileCopyrightText: 2022 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#pragma once

#include "dmodemtypes.h"
#include "dtkmodem_global.h"

#include <QObject>
#include <DExpected>

DMODEM_BEGIN_NAMESPACE

class DModemManagerPrivate;

using DCORE_NAMESPACE::DExpected;

class DModemManager : public QObject
{
    Q_OBJECT
public:
    explicit DModemManager(QObject *parent = nullptr);
    virtual ~DModemManager();
    // properties:
    Q_PROPERTY(quint32 state READ state);
    Q_PROPERTY(quint32 pduType READ pduType);
    Q_PROPERTY(QString number READ number);
    Q_PROPERTY(QString text READ text);
    Q_PROPERTY(QByteArray data READ data);
    Q_PROPERTY(QString smsc READ smsc);
    Q_PROPERTY(QString validity READ validity);
    Q_PROPERTY(int class READ class);
    Q_PROPERTY(QString teleserviceId READ teleserviceId);
    Q_PROPERTY(QString serviceCategory READ serviceCategory);
    Q_PROPERTY(bool deliveryReportRequest READ deliveryReportRequest);
    Q_PROPERTY(QString messageReference READ messageReference);
    Q_PROPERTY(QString timestamp READ timestamp);
    Q_PROPERTY(QString dischargeTimestamp READ dischargeTimestamp);
    Q_PROPERTY(QString deliveryState READ deliveryState);
    Q_PROPERTY(QString storage READ storage);

    quint32 state() const;
    quint32 pduType() const;
    QString number() const;
    QString text() const;
    QByteArray data() const;
    QString smsc() const;
    QString validity() const;


private:
    QScopedPointer<DModemManagerPrivate> d_ptr{nullptr};
};
DMODEM_END_NAMESPACE
