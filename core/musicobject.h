#ifndef MUSICOBJECT_H
#define MUSICOBJECT_H

/* =================================================
 * This file is part of the Music Player project
 * Copyright (c) 2014 - 2015 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include <QDir>
#include <QMap>
#include <QSet>
#include <QApplication>

#define LRC_DOWNLOAD   "MLrc/"
#define MUSIC_DOWNLOAD "Music/"
#define THEME_DOWNLOAD "MTheme/"
#define THEME_CACHED   "MCachedTheme/"
#define ART_DOWNLOAD   "MArt/"
#define TRANS_PLUGINS  "MPlugins/"
#define ART_BG         "MArt/background/"
#define TR_LANGUAGE    "MLanguage/"
#define TMP_DOWNLOAD   "temporary"

#define MUSIC_FILE     ".mp3"
#define SKN_FILE       ".skn"
#define JPG_FILE       ".jpg"
#define LRC_FILE       ".lrc"

#define MAKE_TRANSFORM "MPlugins/avconv.dll"
#define MAKE_RING      "MPlugins/avring.dll"
#define MAKE_RADIO     "MPlugins/avradio.dll"

#define COFIGPATH      "musicconfig.xml"
#define DATABASETYPE   "QSQLITE"
#define NETDADIOPATH   "musicradio.dll"
#define MUSICPATH      "music.dll"
#define DOWNLOADINFO   "music_1.dll"
#define MUSICSEARCH    "music_2.dll"
#define DARABASEPATH   "musicuser_1.dll"
#define USERPATH       "musicuser_2.dll"

#define USERID         20
#define PASSWD         100
#define EMAIL          20
#define USERNAME       20
#define LOGINTIME      20

typedef signed char MInt8;           /* 8 bit signed */
typedef unsigned char MUint8;        /* 8 bit unsigned */
typedef short MInt16;                /* 16 bit signed */
typedef unsigned short MUint16;      /* 16 bit unsigned */
typedef int MInt32;                  /* 32 bit signed */
typedef unsigned int MUint32;        /* 32 bit unsigned */
typedef long long MInt64;            /* 64 bit signed */
typedef unsigned long long MUint64;  /* 64 bit unsigned */

typedef double MDouble;              /* double */
typedef float MFloat;                /* float */
typedef bool MBool;                  /* bool */

typedef QList<QStringList> MStringLists;    /* stringlists */
typedef QList<int> MIntList;                /* intlist */
typedef QList<MIntList> MIntLists;          /* intlists */
typedef QSet<int> MIntSet;                  /* intset */
typedef QSet<MIntSet> MIntSets;             /* intsets */
typedef QMap<QString, QVariant> MStriantMap;    /* stringVariantMap */
typedef QMap<QString, QStringList> MStringsListMap; /* stringStrlistsMap */
typedef QMap<int, MIntList> MIntsListMap;        /* intIntlistMap */
typedef QMap<qint64, QString> MIntStringMap;      /* intStrMap */
typedef QMapIterator<QString, QVariant> MStriantMapIt;    /* stringVariantMapIt */
typedef QMapIterator<QString, QStringList> MStringsListMapIt; /* stringStrlistsMapIt */
typedef QMapIterator<int, MIntList> MIntsListMapIt;        /* intIntlistMapIt */
typedef QMapIterator<qint64, QString> MIntStringMapIt;      /* intStrMapIt */

typedef struct MusicSongs
{
    QStringList m_names;
    QStringList m_paths;
    MIntList m_playCount;
}MusicSongs;
typedef QList<MusicSongs> MMusicList;           /* musiclist */

namespace MusicObject
{
    enum DownLoadType{ DisConnection, DownLoading, Buffing, Waiting };

    enum SongPlayType{ MC_PlayOrder = 1, MC_PlayRandom,  MC_PlayListLoop,
                       MC_PlayOneLoop, MC_PlayOnce };

    enum SpecialEQ { EQ_NULL = -1, EQ_EchoEffect, EQ_MixChannelEffect, EQ_ReverseEffect,
                     EQ_SideCutEffect, EQ_CenterCutEffect, EQ_RateUpEffect, EQ_RateDownEffect,
                     EQ_PitchUpEffect, EQ_PitchDownEffect, EQ_TempoUpEffect, EQ_TempoDownEffect,
                     EQ_FadeOutEffect, EQ_FadeInEffect };

    static void dirIsExist(const QString& name)
    {
        QDir dir;
        if(!dir.exists(name))
        {
            dir.mkdir(name);
        }
    }

    static void fileIsExist(const QString& name)
    {
        QFile file(name);
        if(!file.exists())
        {
            file.open( QIODevice::WriteOnly );
            file.close();
        }
    }

    static QString getAppDir()
    {
        return QApplication::applicationDirPath() + "/";
    }

    static void checkTheDirectoryExist()
    {
        dirIsExist(getAppDir() + LRC_DOWNLOAD);
        dirIsExist(getAppDir() + MUSIC_DOWNLOAD);
        dirIsExist(getAppDir() + THEME_CACHED);
        dirIsExist(getAppDir() + THEME_DOWNLOAD);
        dirIsExist(getAppDir() + ART_DOWNLOAD);
        dirIsExist(getAppDir() + TRANS_PLUGINS);
        dirIsExist(getAppDir() + ART_BG);
        dirIsExist(getAppDir() + TR_LANGUAGE);

        fileIsExist(getAppDir() + DOWNLOADINFO);
        fileIsExist(getAppDir() + DARABASEPATH);
        fileIsExist(getAppDir() + USERPATH);
        fileIsExist(getAppDir() + COFIGPATH);
        fileIsExist(getAppDir() + MUSICPATH);
        fileIsExist(getAppDir() + MUSICSEARCH);
    }

    static QString getLanguageName(int index)
    {
        QString lan(getAppDir() + TR_LANGUAGE);
        switch(index)
        {
            case 0 : return lan.append(getAppDir() + "cn.ln");
            case 1 : return lan.append(getAppDir() + "cn_c.ln");
            case 2 : return lan.append(getAppDir() + "en.ln");
            default: return QString();
        }
    }

}

#endif // MUSICOBJECT_H
