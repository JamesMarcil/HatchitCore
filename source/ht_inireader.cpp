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

#include <ht_inireader.h>
#include <ht_debug.h>

namespace Hatchit {

    namespace Core {

        INIReader::INIReader(void)
        {

        }

        void INIReader::Load(File* file)
        {
            int error = ini_parse_file(file->Handle(), ValueHandler, this);
            if (error != 0)
                throw INIException(file->Name(), error);

#ifdef _DEBUG
            /*Print loaded values to output window*/
            DebugPrintF("[%s]:\n", file->Name().c_str());
            for (auto val : m_values)
            {
                DebugPrintF("%s : %s\n", val.first.c_str(), val.second.c_str());
            }
#endif
        }

        bool INIReader::Empty()
        {
            return m_values.empty();
        }

        std::string INIReader::Get(std::string section, std::string name)
        {
            std::string key = MakeKey(section, name);

            return m_values.count(key) ? m_values[key] : "";
        }

        std::string INIReader::MakeKey(std::string section, std::string name)
        {
            std::string key = section + "=" + name;

            //transform key to all lower-case for case-insensitivity
            std::transform(key.begin(), key.end(), key.begin(), ::tolower);

            return key;
        }

        int INIReader::ValueHandler(void* user, const char* section, const char* name, const char* value)
        {
            INIReader* reader = (INIReader*)user;
            std::string key = MakeKey(section, name);
            if (reader->m_values[key].size() > 0)
                reader->m_values[key] += "\n";
            reader->m_values[key] += value;

            return 1;
        }

    }
}