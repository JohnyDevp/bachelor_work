#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <string>
#include <iostream>
#include <QDebug>

using namespace std;

/// @brief variable for counting IDs of macros printed out
inline int debug_msg_num = 0;
/// @brief macro for printing debug info
#define Q_DEBUG_PRINTOUT(text)                 \
    cout << debug_msg_num << ". DEBUG MSG>> "; \
    cout << qPrintable(text);                  \
    cout << endl;                              \
    debug_msg_num++;

#define S_DEBUG_PRINTOUT(text)                 \
    cout << debug_msg_num << ". DEBUG MSG>> "; \
    cout << text;                              \
    cout << endl;                              \
    debug_msg_num++;

#endif