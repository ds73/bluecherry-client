#ifndef LIVEFEEDWIDGET_H
#define LIVEFEEDWIDGET_H

#include <QWidget>
#include <QSharedPointer>

class DVRCamera;
class MJpegStream;
class QMimeData;

class LiveFeedWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(DVRCamera* camera READ camera WRITE setCamera NOTIFY cameraChanged)

public:
    explicit LiveFeedWidget(QWidget *parent = 0);

    DVRCamera *camera() const { return m_camera; }
    QString statusMessage() const { return m_statusMsg; }

    virtual QSize sizeHint() const;

public slots:
    void setCamera(DVRCamera *camera);

    void openWindow();

private slots:
    void updateFrame(const QPixmap &frame);
    void mjpegStateChanged(int state);

protected:
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dragLeaveEvent(QDragLeaveEvent *event);
    virtual void dropEvent(QDropEvent *event);
    virtual void paintEvent(QPaintEvent *event);
    virtual void contextMenuEvent(QContextMenuEvent *event);

private:
    DVRCamera *m_camera, *m_dragCamera;
    QSharedPointer<MJpegStream> m_stream;
    QPixmap m_currentFrame;
    QString m_statusMsg;

    DVRCamera *cameraFromMime(const QMimeData *mimeData);

    void setStatusMessage(const QString &message);
    void clearStatusMessage() { setStatusMessage(QString()); }

    void clone(LiveFeedWidget *other);
};

#endif // LIVEFEEDWIDGET_H