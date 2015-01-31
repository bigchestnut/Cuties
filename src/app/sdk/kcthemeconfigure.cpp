#include <QJsonDocument>
#include <QFile>
#include <QApplication>

#include "kcthemeconfigure.h"

KCThemeConfigure *KCThemeConfigure::m_instance=nullptr;

KCThemeConfigure *KCThemeConfigure::instance()
{
    return m_instance==nullptr?m_instance=new KCThemeConfigure:m_instance;
}

KCThemeConfigure::~KCThemeConfigure()
{

}

QPalette KCThemeConfigure::getPalette(const QString &identityName)
{
    return m_paletteMap.contains(identityName)?
                m_paletteMap.value(identityName):
                m_paletteMap.value("Base");
}

void KCThemeConfigure::loadConfigure()
{
    //Open the palette configure file.
    QFile configureFile(m_filePath);
    if(!configureFile.open(QIODevice::ReadOnly))
    {
        return;
    }
    //Get the map object.
    QJsonObject dataObject=
            QJsonDocument::fromJson(configureFile.readAll()).object(),
            mapObject=dataObject.value("map").toObject();
    //Close the file.
    configureFile.close();

    QPalette basePalette;
    parseObject(dataObject.value("Base").toObject(), basePalette);
    //Parse the base palette.
    m_paletteMap.insert("Base", basePalette);

    //Parse all the other palettes contains in the map.
    QStringList keys=mapObject.keys();
    for(QStringList::iterator i=keys.begin();
        i!=keys.end();
        ++i)
    {
        //Insert the palette to hash list.
        QJsonObject currentObject=mapObject.value(*i);
        //Build the palette.
        //Check if the palette is based on a parent palette.
        QPalette currentPalette=
                currentObject.value("Parent").isNull()?
                    basePalette:
                    m_paletteMap.value(currentObject.value("Parent").toString());
        //Parse the current object.
        parseObject(currentObject, currentPalette);
        m_paletteMap.insert(*i, currentPalette);
    }
}

void KCThemeConfigure::saveConfigure()
{
    ;
}

void KCThemeConfigure::setConfigureFile(const QString &filePath)
{
    m_filePath=filePath;
}

void KCThemeConfigure::parseObject(const QJsonObject &object, QPalette &palette)
{
    //Parse all the roles.
    QStringList colorRoleList=object.keys();
    for(QStringList::iterator i=colorRoleList.begin();
        i!=colorRoleList.end();
        ++i)
    {
        //Get the palette of the string.
        QPalette::ColorRole role=m_textRole.value(*i, QPalette::NoRole);
        //Check the role result.
        if(role!=QPalette::NoRole)
        {
            palette.setColor(role, stringToColor(object.value(*i).toString()));
        }
    }

}

QColor KCThemeConfigure::stringToColor(const QString &colorString)
{
    QColor currentColor=QColor(0,0,0);
    if(colorString.startsWith('#'))
    {
        if(colorString.length()==7)
        {
            //Format like: #RRGGBB hex(16)
            currentColor.setRgb(qRgb(colorString.mid(1, 2).toInt(0, 16),
                                     colorString.mid(3, 2).toInt(0, 16),
                                     colorString.mid(5, 2).toInt(0, 16)));
            return currentColor;
        }
        if(colorString.length()==9)
        {
            //Format like: #RRGGBBAA hex(16)
            currentColor.setRgba(qRgba(colorString.mid(1, 2).toInt(0, 16),
                                       colorString.mid(3, 2).toInt(0, 16),
                                       colorString.mid(5, 2).toInt(0, 16),
                                       colorString.mid(7,2).toInt(0, 16)));
            return currentColor;
        }
    }
    return currentColor;
}

KCThemeConfigure::KCThemeConfigure(QObject *parent) :
    KCConfigure(parent)
{
    //Initial the text-role translate map.
    m_textRole.insert("Window",QPalette::Window);
    m_textRole.insert("WindowText",QPalette::WindowText);
    m_textRole.insert("Base",QPalette::Base);
    m_textRole.insert("AlternateBase",QPalette::AlternateBase);
    m_textRole.insert("ToolTipBase",QPalette::ToolTipBase);
    m_textRole.insert("ToolTipText",QPalette::ToolTipText);
    m_textRole.insert("Texts",QPalette::Texts);
    m_textRole.insert("Button",QPalette::Button);
    m_textRole.insert("ButtonText",QPalette::ButtonText);
    m_textRole.insert("BrightText",QPalette::BrightText);
    m_textRole.insert("Light",QPalette::Light);
    m_textRole.insert("Midlight",QPalette::Midlight);
    m_textRole.insert("Dark",QPalette::Dark);
    m_textRole.insert("Mid",QPalette::Mid);
    m_textRole.insert("Shadow",QPalette::Shadow);
    m_textRole.insert("Highlight",QPalette::Highlight);
    m_textRole.insert("HighlightedText",QPalette::HighlightedText);
    m_textRole.insert("Link",QPalette::Link);
    m_textRole.insert("LinkVisited",QPalette::LinkVisited);

    m_roleText.insert(QPalette::Window,"Window");
    m_roleText.insert(QPalette::WindowText,"WindowText");
    m_roleText.insert(QPalette::Base,"Base");
    m_roleText.insert(QPalette::AlternateBase,"AlternateBase");
    m_roleText.insert(QPalette::ToolTipBase,"ToolTipBase");
    m_roleText.insert(QPalette::ToolTipText,"ToolTipText");
    m_roleText.insert(QPalette::Texts,"Texts");
    m_roleText.insert(QPalette::Button,"Button");
    m_roleText.insert(QPalette::ButtonText,"ButtonText");
    m_roleText.insert(QPalette::BrightText,"BrightText");
    m_roleText.insert(QPalette::Light,"Light");
    m_roleText.insert(QPalette::Midlight,"Midlight");
    m_roleText.insert(QPalette::Dark,"Dark");
    m_roleText.insert(QPalette::Mid,"Mid");
    m_roleText.insert(QPalette::Shadow,"Shadow");
    m_roleText.insert(QPalette::Highlight,"Highlight");
    m_roleText.insert(QPalette::HighlightedText,"HighlightedText");
    m_roleText.insert(QPalette::Link,"Link");
    m_roleText.insert(QPalette::LinkVisited,"LinkVisited");
}
