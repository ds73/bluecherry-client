/*
 * Copyright 2010-2019 Bluecherry, LLC
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SERVERMENU_H
#define SERVERMENU_H

#include <QMenu>
#include <QObject>

class DVRServer;

class QAction;

class ServerMenu : public QMenu
{
	Q_OBJECT

public:
	explicit ServerMenu(DVRServer *server, const QString &title, QWidget *parent = 0);
    ~ServerMenu();

signals:
	void showEventsWindow();
	void openServerConfig();
	void openServerSettings();

protected:
	virtual void changeEvent(QEvent *event);

private:
	DVRServer *m_server;

	QAction *m_connectAction;
	QAction *m_browseEventsAction;
	QAction *m_configureServerAction;
	QAction *m_refreshDevicesAction;
	QAction *m_settingsAction;

	void createActions();
	void retranslateUI();

private slots:
	void updateMenuForServer();

};

Q_DECLARE_METATYPE(ServerMenu*)


#endif // SERVERMENU_H
