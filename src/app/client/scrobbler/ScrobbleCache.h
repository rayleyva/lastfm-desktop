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

#include "lib/moose/TrackInfo.h"
#include <QList>
#include <QString>


/** absolutely not thread-safe */
class ScrobbleCache
{
    QString m_path;
    QString m_username;
    QList<TrackInfo>& m_tracks;

    ScrobbleCache(); //used by tracksForPath()

    void read();  /// reads from m_path into m_tracks
    void write(); /// writes m_tracks to m_path

public:
    explicit ScrobbleCache( const QString& username );

    /** note this is unique for TrackInfo::sameAs() and equal timestamps 
    * obviously playcounts will not be increased for the same timestamp */
    void append( const TrackInfo& );
    void append( const QList<TrackInfo>& );

    /** returns the number of tracks left in the queue */
    int remove( const QList<TrackInfo>& );

    QList<TrackInfo> tracks() const { return m_tracks; }
    QString path() const { return m_path; }
    QString username() const { return m_username; }

    /** a track list from an XML file in the ScrobbleCache format at path */
    static QList<TrackInfo> tracksForPath( const QString& path )
    {
        ScrobbleCache cache;
        cache.m_path = path;
        cache.read();
        return cache.m_tracks;
    }

private:
    bool operator==( const ScrobbleCache& ); //undefined
};