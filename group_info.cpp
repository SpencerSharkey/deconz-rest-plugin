/*
 * Copyright (C) 2013 dresden elektronik ingenieurtechnik gmbh.
 * All rights reserved.
 *
 * The software in this package is published under the terms of the BSD
 * style license a copy of which has been included with this distribution in
 * the LICENSE.txt file.
 *
 */

#include "group_info.h"

/*! Constructor.
 */
GroupInfo::GroupInfo() :
   state(StateInGroup),
   actions(ActionNone),
   id(0)
{
}
