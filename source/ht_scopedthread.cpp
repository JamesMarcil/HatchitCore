/**
**    Hatchit Engine
**    Copyright(c) 2015 Third-Degree
**
**    GNU Lesser General Public License
**    This file may be used under the terms of the GNU Lesser
**    General Public License version 3 as published by the Free
**    Software Foundation and appearing in the file LICENSE.LGPLv3 included
**    in the packaging of this file. Please review the following information
**    to ensure the GNU Lesser General Public License requirements
**    will be met: https://www.gnu.org/licenses/lgpl.html
**
**/

#include <ht_scopedthread.h>
#include <exception>
#include <stdexcept>

namespace Hatchit {

    namespace Core {
        
        ScopedThread::ScopedThread(std::thread _t)
        {
            t = std::thread(std::move(_t));
            
            if(!t.joinable())
                throw std::logic_error("No thread");
        }

        ScopedThread::~ScopedThread()
        {
            t.join();
        }
    }
}
