/*
   Copyright 2005-2009 Last.fm Ltd. 
      - Primarily authored by Max Howell, Jono Cole, Erik Jaelevik, 
        Christian Muehlhaeuser

   This file is part of the Last.fm Desktop Application Suite.

   lastfm-desktop is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   lastfm-desktop is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with lastfm-desktop.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef CORE_APPLE_SCRIPT_H
#define CORE_APPLE_SCRIPT_H
#ifdef __APPLE__

#include <QString>
#include <Carbon/Carbon.h> // is there a less huge header option?


/** @author Max Howell <max@last.fm> 
  */
class AppleScript
{
public:
    AppleScript( const QString& code = "" );
    ~AppleScript();

    /** add a whole line, newlines are added after every call to this function!
      * escapes ' to \" for convenience 
      * NOTE calling exec() and then using this function is unsupported 
      */
    AppleScript&
    operator<<( QString line )
    {
        m_code += line.replace( '\'', '"' );
        m_code += '\n';
        return *this;
    }
        
    /** execs script set with setScript() 
      * @returns script output */
    QString exec();
    
    /** AppleScript hates unicode, encode unicode strings with this */
    static QString asUnicodeText( const QString& );
    
    /** if false, you're screwed, we've never yet seen that though */
    static bool isAppleScriptAvailable();
    
    bool isEmpty() const { return m_code.isEmpty(); }
    QString code() const { return m_code; }
	
private:    
    bool compile();
    void logError();

private:
    OSAID m_compiled_script;
    QString m_code;

    static ComponentInstance s_component;
};

#endif
#endif
