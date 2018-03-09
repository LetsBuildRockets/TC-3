#ifndef _DO_H
#define _DO_H

void turnOffAllOutputs();
void initDO();
void releaseDO();
bool readOutput();
bool setOutput(int, bool);
void loopTest();

#endif
