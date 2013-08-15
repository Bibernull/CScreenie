/**
 * Project: CScreenie: A screenshot managing utility
 * File name: RectangleWidget.cpp
 * Description:  A Selection Rectangle, also contains the uploading actions
 *
 * @author Biber Copyright (C) 2010.
 *
 * @see The GNU Public License (GPL)
 */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef UPLOADER_H
#define UPLOADER_H
#include <QString>
#include <curl/curl.h>
#include <QProgressDialog>
#include <string>
#include <fstream>

class Uploader
{
public:
    Uploader();
    ~Uploader();
    QString toCustomServer(const char *data,long size, std::string url, std::string imgpath,int status);
    QString toPublicServer(const char *data,long size, QString server,int status);

    QString toCustomServer(QString filename, std::string url, std::string imgpath,int status);
    QString toPublicServer(QString filename, QString server ,int status);

    static void getFile(std::string filename, std::string url);
    static std::string get(std::string url);

    static int writer(char *data, size_t size, size_t nmemb,std::string *writerData)
    {
              if (writerData == NULL)
        return 0;

      writerData->append(data, size*nmemb);

              return size * nmemb;
            }
    static int my_progress_func(QProgressDialog *bar,
                         double t, /* dltotal */
                         double d, /* dlnow */
                         double ultotal,
                         double ulnow){
        bar->setMaximum((int)ultotal);
        bar->setValue((int)ulnow);

        return 0;
    }
    static int write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
        int written = fwrite(ptr, size, nmemb, stream);
        return written;
    }
};

#endif // UPLOADER_H
