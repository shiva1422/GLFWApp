//
// Created by shivaaz on 8/8/24.
//

#ifndef GLFWAPP_KSFILESTREAM_H
#define GLFWAPP_KSFILESTREAM_H


#include "IKSStream.h"

//TODO read and write modes, restrictions, errors
class KSFileStream : public IKSStream{

public:

    ~KSFileStream(){}//TODO
    int open(const char *path, int flags) override;

    int read(void *buf, size_t count) override;

    off_t seek(off_t offset, int whence) override;

    int close() override;

    void setSource(void *dataSrc) override;

    long getSize() override;

    int64_t getCurrentPosition() override;

    int eof() override;


private:

    int fd = -1;

};


#endif //GLFWAPP_KSFILESTREAM_H
