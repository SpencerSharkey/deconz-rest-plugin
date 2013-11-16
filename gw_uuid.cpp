/*
 * Copyright (C) 2013 dresden elektronik ingenieurtechnik gmbh.
 * All rights reserved.
 *
 * The software in this package is published under the terms of the BSD
 * style license a copy of which has been included with this distribution in
 * the LICENSE.txt file.
 *
 */

#include <QUuid>
#include <QSettings>
#include "de_web_plugin_private.h"

void DeRestPluginPrivate::generateGatewayUuid()
{
#ifdef Q_OS_WIN
    QSettings settings("HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Cryptography", QSettings::NativeFormat);
    gwUuid = settings.value("MachineGuid", "").toString();

    if (gwUuid.isEmpty())
    {
        QUuid uuid = QUuid::createUuid();
        gwUuid = uuid.toString();
    }
#endif

#ifdef Q_OS_LINUX
   QUuid uuid = QUuid::createUuid();
   gwUuid = uuid.toString();
#endif

   DBG_Assert(!gwUuid.isEmpty());

   if (!gwUuid.isEmpty())
   {
       needSaveDatabase = true;
   }
}