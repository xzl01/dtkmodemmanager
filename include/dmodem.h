// SPDX-FileCopyrightText: 2022 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#pragma once

#include "dmodemtypes.h"
#include "dtkmodem_global.h"

#include <QObject>
#include <DExpected>

DMODEM_BEGIN_NAMESPACE

class DModemPrivate;

using DCORE_NAMESPACE::DExpected;

class DModem : public QObject
{
    Q_OBJECT
public:
    explicit DModem(QObject *parent = nullptr);
    virtual ~DModem();
    // properties:
    Q_PROPERTY(QList<QByteArray> bearers READ bearers);
    Q_PROPERTY(QList<QByteArray> simSlots READ simSlots);
    Q_PROPERTY(QList<QString> drivers READ drivers);
    Q_PROPERTY(QList<QString> ownNumbers READ ownNumbers);
    Q_PROPERTY(QList<QMap<QString, quint32>> ports READ ports);
    Q_PROPERTY(QList<QMap<quint32, quint32>> supportModems READ supportModems);
    Q_PROPERTY(QList<quint32> currentBands READ currentBands);
    Q_PROPERTY(QList<quint32> supportedBands READ supportedBands);
    Q_PROPERTY(QList<quint32> supportedCapabilities READ supportedCapabilities);
    Q_PROPERTY(QMap<quint32, quint32> unlockRetries READ unlockRetries);  // TODO:
    Q_PROPERTY(qint32 state READ state);
    Q_PROPERTY(QObjectPath *sim READ sim);  // TODO: 这里应该是 sim 对象的指针
    Q_PROPERTY(QString carrierConfiguration READ carrierConfiguration);
    Q_PROPERTY(QString carrierConfigurationRevision READ carrierConfigurationRevision);
    Q_PROPERTY(QString device READ device);
    Q_PROPERTY(QString deviceIdentifier READ deviceIdentifier);
    Q_PROPERTY(QString equipmentIdentifier READ equipmentIdentifier);
    Q_PROPERTY(QString hardwareRevision READ hardwareRevision);
    Q_PROPERTY(QString manufacturer READ manufacturer);
    Q_PROPERTY(QString model READ model);
    Q_PROPERTY(QString physdev READ physdev);
    Q_PROPERTY(QString plugin READ plugin);
    Q_PROPERTY(QString primaryPort READ primaryPort);
    Q_PROPERTY(QString revision READ revision);
    Q_PROPERTY(QMap<quint32, bool> signalQuality READ signalQuality);
    Q_PROPERTY(QMap<quint32, quint32> currentModes READ currentModes);
    Q_PROPERTY(quint32 accessTechnologies READ accessTechnologies);
    Q_PROPERTY(quint32 currentCapabilities READ currentCapabilities);
    Q_PROPERTY(quint32 maxActiveBearers READ maxActiveBearers);
    Q_PROPERTY(quint32 maxActiveMultiplexedBearers READ maxActiveMultiplexedBearers);
    Q_PROPERTY(quint32 maxBearers READ maxBearers);
    Q_PROPERTY(quint32 powerState READ powerState);
    Q_PROPERTY(quint32 primarySimSlot READ primarySimSlot);
    Q_PROPERTY(quint32 supportedIpFamilies READ supportedIpFamilies);
    Q_PROPERTY(quint32 unlockRequired READ unlockRequired);

    QList<QByteArray> bearers() const;
    QList<QByteArray> simSlots() const;
    QList<QString> drivers() const;
    QList<QString> ownNumbers() const;
    QList<QMap<QString, quint32>> ports() const;
    QList<QMap<quint32, quint32>> supportModems() const;
    QList<quint32> currentBands() const;
    QList<quint32> supportedBands() const;
    QList<quint32> supportedCapabilities() const;
    QMap<quint32, quint32> unlockRetries() const;
    qint32 state() const;
    // QObjectPath *sim() const;
    QString carrierConfiguration() const;
    QString carrierConfigurationRevision() const;
    QString device() const;
    QString deviceIdentifier() const;
    QString equipmentIdentifier() const;
    QString hardwareRevision() const;
    QString manufacturer() const;
    QString model() const;
    QString physdev() const;
    QString plugin() const;
    QString primaryPort() const;
    QString revision() const;
    QMap<quint32, bool> signalQuality() const;
    QMap<quint32, quint32> currentModes() const;
    quint32 accessTechnologies() const;
    quint32 currentCapabilities() const;
    quint32 maxActiveBearers() const;
    quint32 maxActiveMultiplexedBearers() const;
    quint32 maxBearers() const;
    quint32 powerState() const;
    quint32 primarySimSlot() const;
    quint32 supportedIpFamilies() const;
    quint32 unlockRequired() const;

    // methods:
public slots:
    DExpected<QString> command(const QString &command, const quint32 timeout = 1000);
    DExpected<QString> createBearer(const QString &bearer);
    DExpected<void> deleteBearer(const QString &bearer);
    DExpected<void> enable(const bool &enable);
    DExpected<void> factoryReset(const QString &code);
    DExpected<QList<QMap<QString, QVariant>>> getCallInfo();
    DExpected<void> reset();
    DExpected<void> setCurrentBands(const QList<quint32> &bands);
    DExpected<void> setCurrentCapabilities(const quint32 &capabilities);
    DExpected<void> setCurrentModes(const QMap<quint32, quint32> &modes);
    DExpected<void> setPowerState(const quint32 &state);
    DExpected<void> setPrimarySimSlot(const quint32 &slot);

private:
    QScopedPointer<DModemPrivate> d_ptr{nullptr};
};
DMODEM_END_NAMESPACE
