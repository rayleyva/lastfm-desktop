/***************************************************************************
 *   Copyright 2005-2008 Last.fm Ltd                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Steet, Fifth Floor, Boston, MA  02110-1301, USA.          *
 ***************************************************************************/

#ifndef LASTFM_NOW_PLAYING_H
#define LASTFM_NOW_PLAYING_H

#include "ScrobblerHttp.h"
#include <QTime>


class NowPlaying : public ScrobblerPostHttp
{
    class QTimer* m_timer;
    QTime m_delay;

public:
    NowPlaying( const QByteArray& );
    void submit( const class Track& );
    void reset();

    using ScrobblerPostHttp::request;
};

#endif
