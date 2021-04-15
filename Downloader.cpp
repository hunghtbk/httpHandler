#include <QtWidgets>
#include <QtNetwork>

#include "Downloader.h"

Downloader::Downloader(QObject *parent) :
    QObject(parent)
{
}

void Downloader::doDownload()
{
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl("https://qt-project-org.herokuapp.com")));
}

void Downloader::replyFinished (QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        qDebug() << "Content Type" << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << "Last modify" << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();
        qDebug() << "Header length" << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << "Code Attribute" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << "Pharese attribute" << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();

        QFile *file = new QFile("./downloaded.txt");//this file will be created in build image folder
        if(file->open(QFile::Append))
        {
            file->write(reply->readAll());
            file->flush();
            file->close();
        }
        delete file;
    }

    reply->deleteLater();
}
