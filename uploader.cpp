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

#ifdef WIN32
#define CURL_STATICLIB
#endif

#include "uploader.h"

using namespace std;


/*
*
*     xLink's sexy InBetween function <3
*/
std::string InBetween(std::string content, std::string begin, std::string end) {

    if(content.empty() || begin.empty() || end.empty()) return "";

       unsigned int pos1 = content.find(begin);
       unsigned int pos2 = 0;

        if(pos1 != string::npos){

            pos1 += begin.length();
            pos2 = content.find(end,pos1);

            if(pos2 != string::npos){
                return content.substr(pos1, pos2 - pos1);
            }
        }

        return "";
    }


Uploader::Uploader()
{
}

Uploader::~Uploader()
{

}

QString Uploader::toCustomServer(const char *imgdata,long size, std::string url, std::string imgpath,int status){


    CURL *curl;
    CURLcode success;
    struct curl_httppost *formpost=NULL;
    struct curl_httppost *lastptr=NULL;
    struct curl_slist *headerlist=NULL;
    static const char buf[] = "Expect:";
    std::string buffer;
    buffer.clear();

    curl_formadd(&formpost,
              &lastptr,
              CURLFORM_COPYNAME, "file",
              CURLFORM_BUFFER, "cscreenie_image.png",
              CURLFORM_BUFFERPTR, imgdata,
              CURLFORM_BUFFERLENGTH, size,
              CURLFORM_END);

   headerlist = curl_slist_append(headerlist, buf);

    curl = curl_easy_init();

    QProgressDialog progress("Uploading",0,0,100,0);
    if(status == 1){
      curl_easy_setopt(curl, CURLOPT_NOPROGRESS, FALSE);
      curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, &my_progress_func);
      curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &progress);
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); //Set url
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);  //Headers to send
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);  //Post data
    curl_easy_setopt(curl, CURLOPT_WRITEDATA,&buffer ) ;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);

    success = curl_easy_perform(curl); //Execute
    curl_easy_cleanup(curl);  //Always cleanup


    QString result;

    if(buffer != ""){
        result = QString::fromStdString(imgpath);
        result.append(QString::fromStdString(buffer));
        return result;
    }else{
        return "Fail";
       }
}

QString Uploader::toPublicServer(const char *imgdata,long size, QString server,int status){

    CURL *curl;
    CURLcode success;
    struct curl_httppost *formpost=NULL;
    struct curl_httppost *lastptr=NULL;
    struct curl_slist *headerlist=NULL;
    static const char buf[] = "Authorization: Client-ID 3c1a6553ba0bbe4";
    std::string url = "";
    std::string buffer;

    buffer.clear();
    url.clear();

    QString result;
    result.clear();
    std::string link;
    link.clear();

    if(server == "imgshack"){

    url = "http://www.imageshack.us/index.php";

    curl_formadd(&formpost,
              &lastptr,
              CURLFORM_COPYNAME, "image",
              CURLFORM_BUFFER, "image",
              CURLFORM_BUFFERPTR, imgdata,
              CURLFORM_BUFFERLENGTH,size,
              CURLFORM_END);
              curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "xml", CURLFORM_COPYCONTENTS, "yes", CURLFORM_END);

      }else{

    url = "https://api.imgur.com/3/image.xml";


    curl_formadd(&formpost,
              &lastptr,
              CURLFORM_COPYNAME, "image",
              CURLFORM_BUFFER, "image",
              CURLFORM_BUFFERPTR, imgdata,
              CURLFORM_BUFFERLENGTH,size,
              CURLFORM_END);
    curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "xml", CURLFORM_COPYCONTENTS, "yes", CURLFORM_END);
    //curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "client_id", CURLFORM_COPYCONTENTS, "3c1a6553ba0bbe4", CURLFORM_END);

          }

    headerlist = curl_slist_append(headerlist, buf);

    curl = curl_easy_init();

    QProgressDialog progress("Uploading",0,0,100,0);

    if(status == 1){

    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, FALSE);
    curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, &my_progress_func);
    curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &progress);
}
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); //Set url
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);  //Headers to send
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);  //Post data
    curl_easy_setopt(curl, CURLOPT_WRITEDATA,&buffer ) ;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);

    success = curl_easy_perform(curl); //Execute
    curl_easy_cleanup(curl);  //Always cleanup

    if(!buffer.empty()){


        if(server == "imgshack"){
             link.append(InBetween(buffer,"<image_link>","</image_link>"));
        }else{
             link.append(InBetween(buffer,"<link>","</link>"));

             }
    }

    result = "";
    result.append(QString::fromStdString(link));

    ofstream log( "public_server_log.txt" );
    if(log){
        log << buffer;
        log << curl_easy_strerror(success);
        log.flush();
        log.close();
    }

    if(!result.isEmpty()){
             return result;
    }else{

        return "Fail";
    }

}







QString Uploader::toCustomServer(QString filename, std::string url, std::string imgpath,int status){


      CURL *curl;
      CURLcode success;
      struct curl_httppost *formpost=NULL;
      struct curl_httppost *lastptr=NULL;
      struct curl_slist *headerlist=NULL;
      static const char buf[] = "Expect:";
      std::string buffer;
      buffer.clear();

      curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "file", CURLFORM_FILE, filename.toStdString().c_str(), CURLFORM_END);
      headerlist = curl_slist_append(headerlist, buf);

      curl = curl_easy_init();

      QProgressDialog progress("Uploading",0,0,100,0);
      if(status == 1){
      curl_easy_setopt(curl, CURLOPT_NOPROGRESS, FALSE);
      curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, &my_progress_func);
      curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &progress);
  }

      curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); //Set url
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);  //Headers to send
      curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);  //Post data
      curl_easy_setopt(curl, CURLOPT_WRITEDATA,&buffer ) ;
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);

      success = curl_easy_perform(curl); //Execute
      curl_easy_cleanup(curl);  //Always cleanup

      QString result;

      if(buffer != ""){
          result = QString::fromStdString(imgpath);
          result.append(QString::fromStdString(buffer));
          return result;
      }else{
          return "Fail";
      }
  }



  QString Uploader::toPublicServer(QString filename, QString server,int status){

      CURL *curl;
      CURLcode success;
      struct curl_httppost *formpost=NULL;
      struct curl_httppost *lastptr=NULL;
      struct curl_slist *headerlist=NULL;
      static const char buf[] = "Expect:";
      std::string url;
      std::string buffer;
      buffer.clear();

      if(server == "imgshack"){

      url = "http://www.imageshack.us/index.php";

      curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "fileupload", CURLFORM_FILE, filename.toStdString().c_str(), CURLFORM_END);
      curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "xml", CURLFORM_COPYCONTENTS, "yes", CURLFORM_END);

        }else{

      url = "http://imgur.com/api/upload.xml";

      curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "image", CURLFORM_FILE, filename.toStdString().c_str(), CURLFORM_END);
      curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "key", CURLFORM_COPYCONTENTS, "fd86c828ac1f4d85eafae07dd8efc51a", CURLFORM_END);

            }


      headerlist = curl_slist_append(headerlist, buf);

      curl = curl_easy_init();

      QProgressDialog progress("Uploading",0,0,100,0);
      if(status == 1){

      curl_easy_setopt(curl, CURLOPT_NOPROGRESS, FALSE);
      curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, &my_progress_func);
      curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &progress);
  }
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); //Set url
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);  //Headers to send
      curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);  //Post data
      curl_easy_setopt(curl, CURLOPT_WRITEDATA,&buffer ) ;
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);

      success = curl_easy_perform(curl); //Execute
      curl_easy_cleanup(curl);  //Always cleanup

      QString link;

  if(buffer.empty() > 0)  return "Fail";


      if(server == "imgshack"){
           link = QString::fromStdString(InBetween(buffer,"<image_link>","</image_link>"));
      }else{
           link = QString::fromStdString(InBetween(buffer,"<original_image>","</original_image>"));
           }


      QString result = "";
      result.append(link);

      if(result != ""){
          return result;
      }else{
          return "Fail";
      }

  }


  void Uploader::getFile(std::string filename, std::string url){

      if(filename.empty() || url.empty()) return;


      CURL *curl;
      FILE *fp;
      CURLcode res;
      curl = curl_easy_init();

      if (curl) {
          fp = fopen(filename.c_str(),"wb");
          curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
          curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
          curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
          res = curl_easy_perform(curl);
          /* always cleanup */
          curl_easy_cleanup(curl);
          fclose(fp);
      }

  }

  std::string Uploader::get(std::string url){

      CURL *curl;
      CURLcode success;
      struct curl_httppost *formpost=NULL;

      struct curl_slist *headerlist=NULL;
      static const char buf[] = "Expect:";
      std::string buffer;
      buffer.clear();

      headerlist = curl_slist_append(headerlist, buf);

      curl = curl_easy_init();


      curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); //Set url
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);  //Headers to send
      curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);  //Post data
      curl_easy_setopt(curl, CURLOPT_WRITEDATA,&buffer ) ;
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);

      success = curl_easy_perform(curl); //Execute
      curl_easy_cleanup(curl);  //Always cleanup


      if(buffer.empty())  return "Fail";

      return buffer;

  }
