// hidcomp/hidconfig, HID device interface for emc
// Copyright (C) 2008, Frank Tkalcevic, www.franksworkshop.com

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "stdafx.h"
#include "hidconfig.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("hidconfig");
    a.setOrganizationName( "FranksWorkshop" );
    a.setOrganizationDomain( "www.franksworkshop.com.au" );
    hidconfig w;
    w.show();
    w.ProcessCommandline();
    return a.exec();
}


