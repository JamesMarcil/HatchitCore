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

#include <ht_platform.h>
#include <ht_string.h>
#include <exception>

namespace Hatchit {

    namespace Core {

        class HT_API INIException : public std::exception
        {
        public:
            INIException(std::string name, int error);

            const char* what() const NOEXCEPT override;

        private:
            std::string m_error;
        };

    }
}