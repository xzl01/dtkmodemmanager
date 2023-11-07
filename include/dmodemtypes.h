// SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef DMODEMTYPES_H
#define DMODEMTYPES_H

#include "dtkmodem_global.h"
#include <QDBusArgument>
#include <QList>

DMODEM_BEGIN_NAMESPACE

struct UserPath_p;

struct UserPath
{
    uint user_id;
    qint64 path;
    bool operator==(const UserPath &up) const { return up.user_id == user_id && up.path == path; }
};

using UserPathList = QList<UserPath>;

DMODEM_END_NAMESPACE

#endif
