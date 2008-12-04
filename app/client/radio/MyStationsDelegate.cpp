/***************************************************************************
 *   Copyright 2005-2008 Last.fm Ltd.                                      *
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

#include "MyStationsDelegate.h"
#include <QStylePainter>
#include <QApplication>
#include <QFontMetrics>

void 
MyStationsDelegate::paint(QPainter* painter, 
									   const QStyleOptionViewItem& option, 
									   const QModelIndex& index) const
{
	if( option.state & QStyle::State_Selected )
	{
		QRect rect = option.rect;
		rect.setHeight( rect.height() - 1 );
		rect.setWidth( rect.width() - 1 );
		painter->save();
		painter->setBrush( QPalette().highlight() );
		painter->setPen( QPalette().mid().color() );
		painter->drawRect( rect );
		painter->restore();
	}
	
	QRect pixmapRect = option.rect;

	pixmapRect.setX( pixmapRect.x() + 10 );
	pixmapRect.setY( pixmapRect.y() + ( pixmapRect.height() / 2 ) - 7 );
	pixmapRect.setWidth( 18 );
	pixmapRect.setHeight( 14 );
	
	painter->setRenderHint( QPainter::SmoothPixmapTransform );
	painter->drawPixmap( pixmapRect, QPixmap( ":/station.png" ));
	
	QRect textRect = option.rect;
	textRect.setTop( textRect.top() + 9 );
	textRect.setLeft( textRect.left() + 35 );
	painter->drawText( textRect, index.data( Qt::DisplayRole ).toString() );
}

QSize
MyStationsDelegate::sizeHint( const QStyleOptionViewItem&, const QModelIndex& index ) const
{
	QFontMetrics fm = qApp->fontMetrics();
	QSize size = fm.size( Qt::TextSingleLine, index.data( Qt::DisplayRole ).toString() );
	
	size.setWidth( size.width() + 35 );
	size = size.expandedTo( QSize( 0, 30 ) ).expandedTo( QApplication::globalStrut() );
	
	
	return size;
}