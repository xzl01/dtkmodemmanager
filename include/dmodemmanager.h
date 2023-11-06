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
    virtual ~DModemManager() ;
    //properties:
    Q_PROPERTY(QString version READ version);
    bool inhibitDevices(const QString uid, bool inhibit);
    void reportKernelEvent(const QString &event, const QString &message);//字典
    void scanDevices();
    void setLogging(const QString &level);

    QString version() const;

private:
    QScopedPointer<DModemManagerPrivate> d_ptr{nullptr};

};
DMODEM_END_NAMESPACE
