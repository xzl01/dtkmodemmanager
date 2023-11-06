// SPDX-FileCopyrightText: 2022 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#pragma once

#include "dmodemtypes.h"
#include "dtkmodem_global.h"

#include <QObject>
#include <DExpected>

DMODEM_BEGIN_NAMESPACE

class DModemBearerPrivate;

using DCORE_NAMESPACE::DExpected;

class DModemBearer : public QObject
{
    Q_OBJECT
public:
    explicit DModemBearer(QObject *parent = nullptr);
    virtual ~DModemBearer();
    // properties:
    Q_PROPERTY(QString interface READ interface);
    Q_PROPERTY(bool connected READ connected);
    Q_PROPERTY(QString connectionError READ connectionError);
    Q_PROPERTY(bool suspended READ suspended);
    Q_PROPERTY(bool multiplexed READ multiplexed);
    Q_PROPERTY(QMap<QString, QVariant> ip4Config READ ip4Config);
    Q_PROPERTY(QMap<QString, QVariant> ip6Config READ ip6Config);
    Q_PROPERTY(QMap<QString, QVariant> stats READ stats);
    Q_PROPERTY(bool reloadStatsSupported READ reloadStatsSupported);
    Q_PROPERTY(quint32 ipTimeout READ ipTimeout);
    Q_PROPERTY(quint32 bearerType READ bearerType);
    Q_PROPERTY(int profileId READ profileId);
    Q_PROPERTY(QMap<QString, QVariant> properties READ properties);
    QString interface() const;
    bool connected() const;
    QString connectionError() const;
    bool suspended() const;
    bool multiplexed() const;
    QMap<QString, QVariant> ip4Config() const;
    QMap<QString, QVariant> ip6Config() const;
    QMap<QString, QVariant> stats() const;
    bool reloadStatsSupported() const;
    quint32 ipTimeout() const;
    quint32 bearerType() const;
    int profileId() const;
    QMap<QString, QVariant> properties() const;

    // methods:
public slots:

private:
    QScopedPointer<DModemBearerPrivate> d_ptr{nullptr};
};
DMODEM_END_NAMESPACE
