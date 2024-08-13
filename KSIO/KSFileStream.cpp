//
// Created by shivaaz on 8/8/24.
//

#include <sys/file.h>
#include <unistd.h>
#include <err.h>
#include <cerrno>
#include <cstring>
#include "KSFileStream.h"
#include "../Logger/KSLog.hpp"

//no need fd check do check when opend;

int KSFileStream::open(const char *path, int flags){

    fd = ::open(path,flags);
    if( fd < 0)
    {
        KSPrintF("KSFileStream :%s %s %d%s "," error openFile",path, errno,strerror(errno));
    }
    return fd;
}

int KSFileStream::read(void *buf, size_t count) {

    if(fd >= 0)
    {
        int read = ::read(fd,buf,count);
        if(read == 0)
        {
            const char* error = strerror(errno);
            KSPrintF("KSFilestream Read : required %d , read %d error %d , %s", count, read,errno,error);
        }
        return read;
    }
    return fd;
}

off_t KSFileStream::seek(off_t offset, int whence) {

    if(fd >= 0)
    {
        off_t pos = ::lseek(fd,offset,whence);
        return pos;
    }
    return fd;
}

int KSFileStream::close() {
    if(fd >= 0)
        return ::close(fd);
    return fd;
}

void KSFileStream::setSource(void *dataSrc) {
    IKSStream::setSource(dataSrc);
}

long KSFileStream::getSize() {
    //TODO using stat
    if(fd >= 0)
    return lseek(fd, 0, SEEK_END);
    return 0;
}

int64_t KSFileStream::getCurrentPosition() {
    return 0;
}

int KSFileStream::eof() {
    return 0;
}
