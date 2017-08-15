#include "webengineviewplus.h"

WebEngineViewPlus::WebEngineViewPlus(QWebEngineView *parent) : QWebEngineView(parent)
{

}

void WebEngineViewPlus::setAdminURL(QUrl url)
{
    this->adminURL = url;
}

void WebEngineViewPlus::adminPage()
{
    //qInfo("Key pressed!!!");
    if(this->adminActive){
        //reload active page:
        this->load(this->activeURL);
        adminActive = false;
    }else{
        //load admin pages
        this->activeURL = this->url();
        this->load(this->adminURL);
        adminActive = true;
    }
}

