//
//  KSLog.hpp
//  PhotoFX
//
//  Created by Shiva Shanker Pandiri on 10/18/23.
//

#ifndef KSLog_hpp
#define KSLog_hpp

#include <stdio.h>
#include <syslog.h>

#define KSLOGI(fmt,...) syslog(LOG_INFO,fmt,##__VA_ARGS__)
#define KSLOGD(fmt,...) syslog(LOG_DEBUG,fmt,##__VA_ARGS__)
#define KSLOGE(fmt,...) syslog(LOG_ERR,fmt,##__VA_ARGS__)
#define KSPrintF(fmt,...)    printf(fmt,##__VA_ARGS__)


#endif /* KSLog_hpp */
